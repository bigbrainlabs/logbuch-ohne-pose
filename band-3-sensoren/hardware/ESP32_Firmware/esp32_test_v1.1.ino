/*
 * ESP32 Boot Monitoring System - TEST VERSION v1.1
 * =================================================
 * 
 * NEU: MQTT Konfiguration im Captive Portal!
 * 
 * Features:
 * - WiFi UND MQTT im Captive Portal konfigurierbar
 * - Einstellungen werden im Flash gespeichert
 * - Fake-Daten für Tests ohne echte Sensoren
 * - Motor-Start-Simulation
 * 
 * Beim ersten Start:
 * 1. ESP32 erstellt Access Point "BootMonitor-Setup"
 * 2. Mit Handy/Laptop verbinden
 * 3. Captive Portal öffnet sich
 * 4. WiFi SSID + Passwort eingeben
 * 5. MQTT Server + Port eingeben
 * 6. Speichern → ESP32 startet neu
 * 
 * Version: 1.1-TEST
 */

// ============================================================================
// TEST MODE - AUF TRUE SETZEN FÜR FAKE-DATEN!
// ============================================================================
#define TEST_MODE true  // ← true = Fake-Daten, false = echte Sensoren

// ============================================================================
// LIBRARIES
// ============================================================================
#include <WiFi.h>
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager
#include <PubSubClient.h>        // MQTT Client
#include <ArduinoOTA.h>          // OTA Updates
#include <esp_task_wdt.h>        // Watchdog
#include <Preferences.h>         // Settings speichern (EEPROM Ersatz)
#include <Wire.h>                // I2C (für MPU6050)
#include <Adafruit_MPU6050.h>    // MPU6050 IMU (auch im TEST_MODE!)
#include <Adafruit_Sensor.h>

#if !TEST_MODE
  #include <Adafruit_ADS1X15.h>  // ADS1115 nur bei echten Sensoren
#endif

// ============================================================================
// CONFIGURATION
// ============================================================================

// --- MQTT Settings (werden aus Flash geladen, falls vorhanden) ---
char mqtt_server[40] = "192.168.1.100";   // Default Wert
char mqtt_port[6] = "1883";                // Default Port
char mqtt_user[40] = "";                   // Optional
char mqtt_pass[40] = "";                   // Optional
const char* MQTT_CLIENT_ID = "ESP32_BootMonitor";

// --- GPIO Pins ---
#define STATUS_LED_PIN  2       // Onboard LED
#define RESET_BUTTON_PIN 0      // GPIO0 - Boot Button (optional für Factory Reset)

// --- Update Intervals (Millisekunden) ---
#define UPDATE_FAST     200     // RPM, Flow (5 Hz)
#define UPDATE_MEDIUM   1000    // Temp, Öl, Tank (1 Hz)
#define UPDATE_SLOW     5000    // Batterien, IMU (0.2 Hz)
#define UPDATE_STATUS   10000   // Heartbeat/Status (0.1 Hz)

// --- Watchdog Timeout ---
#define WDT_TIMEOUT     10      // Sekunden

// ============================================================================
// GLOBAL OBJECTS
// ============================================================================
WiFiClient espClient;
PubSubClient mqtt(espClient);
WiFiManager wifiManager;
Preferences preferences;  // Flash Storage
Adafruit_MPU6050 mpu;     // MPU6050 auch im TEST_MODE nutzen!

#if !TEST_MODE
  Adafruit_ADS1115 ads1;
  Adafruit_ADS1115 ads2;
#endif

// ============================================================================
// GLOBAL VARIABLES
// ============================================================================

// Timing
unsigned long lastUpdateFast = 0;
unsigned long lastUpdateMedium = 0;
unsigned long lastUpdateSlow = 0;
unsigned long lastUpdateStatus = 0;

// Sensor values
float batteryStarter = 12.5;
float batteryHouse = 12.8;
float tankLevel = 0.65;
float tankLiters = 0.0;
float engineTemp = 75.0;
float oilPressure = 3.2;
float engineRPM = 0.0;
float pitch = 0.0;
float roll = 0.0;
float flowRate = 0.0;

// Status
unsigned long uptime = 0;
int wifiRSSI = 0;
bool sensorsOK = TEST_MODE;

// Test-Mode Animation
#if TEST_MODE
  float testMotorState = 0.0;
  unsigned long testStartTime = 0;
#endif

// ============================================================================
// SETUP
// ============================================================================
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n\n========================================");
  #if TEST_MODE
    Serial.println("ESP32 Boot Monitor - TEST MODE v1.1");
    Serial.println("*** USING FAKE SENSOR DATA ***");
  #else
    Serial.println("ESP32 Boot Monitor v1.1");
  #endif
  Serial.println("========================================\n");
  
  // --- Status LED ---
  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(STATUS_LED_PIN, LOW);
  
  // --- Factory Reset Check (GPIO0 Button gedrückt beim Start) ---
  pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);
  if (digitalRead(RESET_BUTTON_PIN) == LOW) {
    Serial.println("⚠️  FACTORY RESET - Boot button held during startup!");
    Serial.println("Erasing all settings in 3 seconds...");
    delay(3000);
    if (digitalRead(RESET_BUTTON_PIN) == LOW) {
      preferences.begin("mqtt-config", false);
      preferences.clear();
      preferences.end();
      wifiManager.resetSettings();
      Serial.println("✓ Settings erased! Rebooting...");
      delay(1000);
      ESP.restart();
    }
  }
  
  // --- MQTT Settings aus Flash laden ---
  loadMQTTConfig();
  
  // --- I2C initialisieren (für MPU6050) ---
  Wire.begin(21, 22);
  Serial.println("I2C initialized (SDA=21, SCL=22)");
  
  #if TEST_MODE
    Serial.println("\nTEST MODE ACTIVE - Generating fake data");
    Serial.println("BUT: MPU6050 will provide REAL pitch/roll data!\n");
    
    // MPU6050 initialisieren (für echte Neigungsdaten)
    if (mpu.begin(0x68)) {
      Serial.println("✓ MPU6050 found @ 0x68 - providing REAL data!");
      mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
      mpu.setGyroRange(MPU6050_RANGE_250_DEG);
      mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
      sensorsOK = true;
    } else {
      Serial.println("✗ MPU6050 NOT found - will use fake data");
      sensorsOK = false;
    }
    
    testStartTime = millis();
  #else
    // Alle Sensoren initialisieren
    sensorsOK = initSensors();
    if (!sensorsOK) {
      Serial.println("ERROR: Sensor initialization failed!");
    }
  #endif
  
  // --- WiFi & MQTT Setup über Captive Portal ---
  setupWiFiAndMQTT();
  
  // --- Watchdog initialisieren (NACH WiFi Setup!) ---
  Serial.println("Starting watchdog...");
  #if ESP_ARDUINO_VERSION >= ESP_ARDUINO_VERSION_VAL(3, 0, 0)
    // Neue API (ESP-IDF v5.x)
    esp_task_wdt_config_t wdt_config = {
      .timeout_ms = WDT_TIMEOUT * 1000,
      .idle_core_mask = (1 << portNUM_PROCESSORS) - 1,
      .trigger_panic = true
    };
    esp_task_wdt_init(&wdt_config);
    esp_task_wdt_add(NULL);
  #else
    // Alte API (ESP-IDF v4.x)
    esp_task_wdt_init(WDT_TIMEOUT, true);
    esp_task_wdt_add(NULL);
  #endif
  
  // --- MQTT Client konfigurieren ---
  int port = atoi(mqtt_port);
  mqtt.setServer(mqtt_server, port);
  mqtt.setCallback(mqttCallback);
  mqtt.setBufferSize(512);
  
  Serial.print("\nMQTT Broker: ");
  Serial.print(mqtt_server);
  Serial.print(":");
  Serial.println(mqtt_port);
  if (strlen(mqtt_user) > 0) {
    Serial.print("MQTT User: ");
    Serial.println(mqtt_user);
  }
  
  // --- OTA initialisieren ---
  setupOTA();
  
  Serial.println("\n========================================");
  Serial.println("Setup complete! Starting main loop...");
  #if TEST_MODE
    Serial.println("\nWatch the fake data on MQTT!");
    Serial.println("Motor simulation: OFF → Idle → Running");
  #endif
  Serial.println("========================================\n");
  
  // Kurzes Blinken = Ready
  for (int i = 0; i < 3; i++) {
    digitalWrite(STATUS_LED_PIN, HIGH);
    delay(100);
    digitalWrite(STATUS_LED_PIN, LOW);
    delay(100);
  }
}

// ============================================================================
// MAIN LOOP
// ============================================================================
void loop() {
  // Watchdog nur resetten wenn initialisiert
  static bool wdt_active = true;
  if (wdt_active) {
    esp_task_wdt_reset();
  }
  
  if (!mqtt.connected()) {
    reconnectMQTT();
  }
  mqtt.loop();
  
  ArduinoOTA.handle();
  
  // Status LED blinken
  static unsigned long lastBlink = 0;
  if (millis() - lastBlink > 1000) {
    digitalWrite(STATUS_LED_PIN, !digitalRead(STATUS_LED_PIN));
    lastBlink = millis();
  }
  
  unsigned long now = millis();
  
  #if TEST_MODE
    updateFakeData();
  #endif
  
  // --- FAST Updates (200ms) ---
  if (now - lastUpdateFast >= UPDATE_FAST) {
    lastUpdateFast = now;
    if (sensorsOK) {
      #if !TEST_MODE
        engineRPM = readRPM();
        calculateFlowRate();
      #endif
      publishFloat("boot/sensoren/motor/drehzahl", engineRPM);
      publishFloat("signalk/vessels/self/propulsion/main/revolutions", engineRPM / 60.0);
      publishFloat("boot/sensoren/durchfluss/rate", flowRate);
    }
  }
  
  // --- MEDIUM Updates (1s) ---
  if (now - lastUpdateMedium >= UPDATE_MEDIUM) {
    lastUpdateMedium = now;
    if (sensorsOK) {
      #if !TEST_MODE
        tankLevel = readTankLevel();
        engineTemp = readTemperature();
        oilPressure = readOilPressure();
      #endif
      tankLiters = tankLevel * 200.0;
      publishFloat("boot/sensoren/tank/diesel/prozent", tankLevel * 100.0);
      publishFloat("boot/sensoren/tank/diesel/liter", tankLiters);
      publishFloat("signalk/vessels/self/tanks/fuel/0/currentLevel", tankLevel);
      publishFloat("boot/sensoren/motor/temperatur", engineTemp);
      publishFloat("signalk/vessels/self/propulsion/main/temperature", engineTemp + 273.15);
      publishFloat("boot/sensoren/motor/oeldruck", oilPressure);
      publishFloat("signalk/vessels/self/propulsion/main/oilPressure", oilPressure * 100000.0);
    }
  }
  
  // --- SLOW Updates (5s) ---
  if (now - lastUpdateSlow >= UPDATE_SLOW) {
    lastUpdateSlow = now;
    if (sensorsOK) {
      #if TEST_MODE
        // Im TEST_MODE: Batterien fake, aber IMU echt!
        // (batteryStarter und batteryHouse werden in updateFakeData() gesetzt)
      #else
        batteryStarter = readBatteryStarter();
        batteryHouse = readBatteryHouse();
      #endif
      
      // IMU IMMER echt auslesen (auch im TEST_MODE!)
      readIMU();
      
      publishFloat("boot/sensoren/batterie/starter", batteryStarter);
      publishFloat("boot/sensoren/batterie/verbraucher", batteryHouse);
      publishFloat("signalk/vessels/self/electrical/batteries/starter/voltage", batteryStarter);
      publishFloat("signalk/vessels/self/electrical/batteries/house/voltage", batteryHouse);
      publishFloat("boot/sensoren/lage/neigung", pitch);
      publishFloat("boot/sensoren/lage/schlagseite", roll);
      publishFloat("signalk/vessels/self/navigation/attitude/pitch", pitch * PI / 180.0);
      publishFloat("signalk/vessels/self/navigation/attitude/roll", roll * PI / 180.0);
    }
  }
  
  // --- STATUS Updates (10s) ---
  if (now - lastUpdateStatus >= UPDATE_STATUS) {
    lastUpdateStatus = now;
    uptime = millis() / 1000;
    wifiRSSI = WiFi.RSSI();
    
    mqtt.publish("boot/status/esp32/online", "true", true);
    publishInt("boot/status/esp32/uptime", uptime);
    publishInt("boot/status/esp32/wifi_rssi", wifiRSSI);
    publishBool("boot/status/esp32/sensors_ok", sensorsOK);
    #if TEST_MODE
      mqtt.publish("boot/status/esp32/mode", "TEST_MODE");
    #endif
    
    // Debug Info
    Serial.println("\n--- Status Update ---");
    #if TEST_MODE
      Serial.println("MODE: TEST (Fake Data)");
      Serial.printf("Motor State: %.1f (0=Off, 1=Idle, 2=Running)\n", testMotorState);
    #endif
    Serial.printf("Uptime: %lu s\n", uptime);
    Serial.printf("WiFi RSSI: %d dBm\n", wifiRSSI);
    Serial.printf("Free Heap: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("MQTT: %s\n", mqtt.connected() ? "Connected" : "Disconnected");
    
    Serial.println("\n--- Sensor Values ---");
    Serial.printf("Batterie Starter: %.2f V\n", batteryStarter);
    Serial.printf("Batterie Verbraucher: %.2f V\n", batteryHouse);
    Serial.printf("Tank: %.1f%% (%.1f L)\n", tankLevel * 100, tankLiters);
    Serial.printf("Motor Temp: %.1f °C\n", engineTemp);
    Serial.printf("Öldruck: %.2f bar\n", oilPressure);
    Serial.printf("Drehzahl: %.0f RPM\n", engineRPM);
    Serial.printf("Durchfluss: %.1f L/h\n", flowRate);
    Serial.printf("Neigung: %.1f°  Schlagseite: %.1f°\n", pitch, roll);
  }
  
  delay(10);
}

// ============================================================================
// WIFI & MQTT SETUP (Captive Portal)
// ============================================================================
void setupWiFiAndMQTT() {
  Serial.println("\n--- WiFi & MQTT Setup ---");
  
  // Custom Parameter für MQTT im Captive Portal
  WiFiManagerParameter custom_mqtt_server("server", "MQTT Server IP", mqtt_server, 40);
  WiFiManagerParameter custom_mqtt_port("port", "MQTT Port", mqtt_port, 6);
  WiFiManagerParameter custom_mqtt_user("user", "MQTT User (optional)", mqtt_user, 40);
  WiFiManagerParameter custom_mqtt_pass("pass", "MQTT Password (optional)", mqtt_pass, 40);
  
  // Hilfe-Text im Portal
  WiFiManagerParameter custom_text("<p><b>MQTT Broker Einstellungen:</b></p><p>Gib die IP-Adresse deines Raspberry Pi ein (z.B. 192.168.1.100)</p>");
  
  // Parameter zum WiFiManager hinzufügen
  wifiManager.addParameter(&custom_text);
  wifiManager.addParameter(&custom_mqtt_server);
  wifiManager.addParameter(&custom_mqtt_port);
  wifiManager.addParameter(&custom_mqtt_user);
  wifiManager.addParameter(&custom_mqtt_pass);
  
  // Callback wenn Einstellungen gespeichert wurden
  wifiManager.setSaveConfigCallback(saveConfigCallback);
  
  // Portal Timeout
  wifiManager.setConfigPortalTimeout(300);  // 5 Minuten
  
  // WiFi verbinden (oder Portal starten)
  if (!wifiManager.autoConnect("BootMonitor-Setup", "boot2025")) {
    Serial.println("Failed to connect - restarting...");
    delay(3000);
    ESP.restart();
  }
  
  // WiFi verbunden!
  Serial.println("WiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("RSSI: ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
  
  // MQTT Parameter aus Portal übernehmen
  strcpy(mqtt_server, custom_mqtt_server.getValue());
  strcpy(mqtt_port, custom_mqtt_port.getValue());
  strcpy(mqtt_user, custom_mqtt_user.getValue());
  strcpy(mqtt_pass, custom_mqtt_pass.getValue());
  
  // In Flash speichern
  saveMQTTConfig();
}

void saveConfigCallback() {
  Serial.println("Saving config...");
}

// ============================================================================
// MQTT CONFIG STORAGE (Flash / Preferences)
// ============================================================================
void loadMQTTConfig() {
  preferences.begin("mqtt-config", true);  // Read-only
  
  String server = preferences.getString("server", "");
  String port = preferences.getString("port", "");
  String user = preferences.getString("user", "");
  String pass = preferences.getString("pass", "");
  
  if (server.length() > 0) {
    strcpy(mqtt_server, server.c_str());
    Serial.print("Loaded MQTT Server: ");
    Serial.println(mqtt_server);
  }
  
  if (port.length() > 0) {
    strcpy(mqtt_port, port.c_str());
  }
  
  if (user.length() > 0) {
    strcpy(mqtt_user, user.c_str());
  }
  
  if (pass.length() > 0) {
    strcpy(mqtt_pass, pass.c_str());
  }
  
  preferences.end();
}

void saveMQTTConfig() {
  preferences.begin("mqtt-config", false);  // Read-write
  
  preferences.putString("server", mqtt_server);
  preferences.putString("port", mqtt_port);
  preferences.putString("user", mqtt_user);
  preferences.putString("pass", mqtt_pass);
  
  preferences.end();
  
  Serial.println("✓ MQTT config saved to flash!");
}

// ============================================================================
// FAKE DATA GENERATOR (Test-Mode)
// ============================================================================
#if TEST_MODE
void updateFakeData() {
  unsigned long elapsed = (millis() - testStartTime) / 1000;
  
  if (elapsed < 30) {
    testMotorState = 0.0;
    engineRPM = 0;
    engineTemp = 20.0 + random(-5, 5);
    oilPressure = 0.0;
    flowRate = 0.0;
  } else if (elapsed < 60) {
    testMotorState = 1.0;
    engineRPM = 800 + random(-50, 50);
    engineTemp = 20.0 + (elapsed - 30) * 2.0 + random(-2, 2);
    oilPressure = 2.5 + random(-10, 10) / 100.0;
    flowRate = 2.0 + random(-5, 5) / 10.0;
    batteryStarter += 0.01;
    batteryHouse += 0.01;
  } else {
    testMotorState = 2.0;
    static float targetRPM = 1800;
    if (random(0, 100) < 5) {
      targetRPM = random(1500, 2500);
    }
    engineRPM += (targetRPM - engineRPM) * 0.1;
    engineRPM += random(-20, 20);
    
    float targetTemp = 82.0;
    engineTemp += (targetTemp - engineTemp) * 0.05;
    engineTemp += random(-5, 5) / 10.0;
    
    oilPressure = 2.0 + (engineRPM / 1000.0) + random(-10, 10) / 100.0;
    flowRate = (engineRPM / 150.0) + random(-10, 10) / 10.0;
    
    if (batteryStarter < 14.4) batteryStarter += 0.005;
    if (batteryHouse < 14.2) batteryHouse += 0.003;
    
    tankLevel -= 0.0001;
    if (tankLevel < 0.1) tankLevel = 0.65;
  }
  
  // Begrenzen (nur für Fake-Werte)
  batteryStarter = constrain(batteryStarter, 11.0, 14.8);
  batteryHouse = constrain(batteryHouse, 11.5, 14.5);
  tankLevel = constrain(tankLevel, 0.0, 1.0);
  engineTemp = constrain(engineTemp, 15.0, 100.0);
  oilPressure = constrain(oilPressure, 0.0, 6.0);
  engineRPM = constrain(engineRPM, 0.0, 3500.0);
  flowRate = constrain(flowRate, 0.0, 25.0);
  
  // Pitch/Roll kommen jetzt ECHT vom MPU6050!
  // Keine Simulation mehr!
}
#endif

// ============================================================================
// SENSOR FUNCTIONS (nur wenn nicht Test-Mode)
// ============================================================================
#if !TEST_MODE

bool initSensors() {
  Serial.println("\n--- Initializing Sensors ---");
  bool success = true;
  
  if (ads1.begin(0x48)) {
    Serial.println("✓ ADS1115 #1 found @ 0x48");
    ads1.setGain(GAIN_TWOTHIRDS);
  } else {
    Serial.println("✗ ADS1115 #1 NOT found!");
    success = false;
  }
  
  if (ads2.begin(0x49)) {
    Serial.println("✓ ADS1115 #2 found @ 0x49");
    ads2.setGain(GAIN_TWOTHIRDS);
  } else {
    Serial.println("✗ ADS1115 #2 NOT found!");
    success = false;
  }
  
  if (mpu.begin(0x68)) {
    Serial.println("✓ MPU6050 found @ 0x68");
    mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  } else {
    Serial.println("✗ MPU6050 NOT found!");
    success = false;
  }
  
  return success;
}

float readBatteryStarter() {
  int16_t adc = ads1.readADC_SingleEnded(0);
  float voltage = ads1.computeVolts(adc);
  return voltage * 3.127;
}

float readBatteryHouse() {
  int16_t adc = ads1.readADC_SingleEnded(1);
  float voltage = ads1.computeVolts(adc);
  return voltage * 3.127;
}

float readTankLevel() {
  int16_t adc = ads1.readADC_SingleEnded(2);
  float voltage = ads1.computeVolts(adc);
  float resistance = (voltage * 1000.0) / (5.0 - voltage);
  float level = (240.0 - resistance) / (240.0 - 33.0);
  return constrain(level, 0.0, 1.0);
}

float readTemperature() {
  int16_t adc = ads1.readADC_SingleEnded(3);
  float voltage = ads1.computeVolts(adc);
  return 75.0;  // TODO: VDO Lookup
}

float readOilPressure() {
  int16_t adc = ads2.readADC_SingleEnded(0);
  float voltage = ads2.computeVolts(adc);
  return 3.2;  // TODO: VDO Lookup
}

float readRPM() {
  return 1800.0;  // TODO: Frequency measurement
}

void calculateFlowRate() {
  flowRate = 0.0;  // TODO: Pulse counting
}

#endif

// ============================================================================
// IMU READING (immer verfügbar - auch im TEST_MODE!)
// ============================================================================
void readIMU() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  // Pitch & Roll aus Accelerometer berechnen  
  pitch = atan2(a.acceleration.x, sqrt(a.acceleration.y * a.acceleration.y + 
                                       a.acceleration.z * a.acceleration.z)) * 180.0 / PI;
  
  roll = atan2(a.acceleration.y, sqrt(a.acceleration.x * a.acceleration.x + 
                                      a.acceleration.z * a.acceleration.z)) * 180.0 / PI;
}

// ============================================================================
// MQTT FUNCTIONS
// ============================================================================
void reconnectMQTT() {
  static unsigned long lastAttempt = 0;
  unsigned long now = millis();
  
  if (now - lastAttempt < 5000) return;
  lastAttempt = now;
  
  Serial.print("Connecting to MQTT... ");
  
  // Mit oder ohne Auth verbinden
  bool connected = false;
  if (strlen(mqtt_user) > 0) {
    connected = mqtt.connect(MQTT_CLIENT_ID, mqtt_user, mqtt_pass,
                            "boot/status/esp32/online", 1, true, "false");
  } else {
    connected = mqtt.connect(MQTT_CLIENT_ID, 
                            "boot/status/esp32/online", 1, true, "false");
  }
  
  if (connected) {
    Serial.println("connected!");
    mqtt.publish("boot/status/esp32/online", "true", true);
    mqtt.subscribe("boot/command/#");
  } else {
    Serial.print("failed, rc=");
    Serial.println(mqtt.state());
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("MQTT received: ");
  Serial.println(topic);
}

void publishFloat(const char* topic, float value) {
  char msg[16];
  dtostrf(value, 6, 2, msg);
  mqtt.publish(topic, msg);
}

void publishInt(const char* topic, long value) {
  char msg[16];
  sprintf(msg, "%ld", value);
  mqtt.publish(topic, msg);
}

void publishBool(const char* topic, bool value) {
  mqtt.publish(topic, value ? "true" : "false");
}

// ============================================================================
// OTA SETUP
// ============================================================================
void setupOTA() {
  ArduinoOTA.setHostname("ESP32-BootMonitor");
  ArduinoOTA.setPassword("boot2025");
  
  ArduinoOTA.onStart([]() {
    Serial.println("OTA Update started");
  });
  
  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA finished!");
  });
  
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("OTA: %u%%\r", (progress / (total / 100)));
  });
  
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("OTA Error[%u]: ", error);
  });
  
  ArduinoOTA.begin();
  Serial.println("OTA Ready");
}
