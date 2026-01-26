# Mainboard - Schaltplan Beschreibung

**ESP32 + 2× ADS1115 + GY-521 + Flowsensor**

---

## 📐 KOMPONENTEN:

```
U1: ESP32 WROOM-32 DevKit
U2: ADS1115 #1 (I2C Adresse 0x48)
U3: ADS1115 #2 (I2C Adresse 0x49)
U4: GY-521 (MPU6050, I2C Adresse 0x68)
J1: Power Input (3.3V + GND vom Powerboard)
J2: Sensor Input (8-pol vom Sensorboard)
J3: Flowsensor Input (2-pol, GPIO4)
R1, R2: Pull-up 4.7kΩ (I2C Bus)
```

---

## 🔌 I2C BUS:

**Zentrale I2C-Verbindung:**

```
ESP32 GPIO21 (SDA) ─┬─ R1 (4.7k Pull-up) ─ 3.3V
                    │
                    ├─ ADS1115 #1 SDA
                    ├─ ADS1115 #2 SDA
                    └─ GY-521 SDA

ESP32 GPIO22 (SCL) ─┬─ R2 (4.7k Pull-up) ─ 3.3V
                    │
                    ├─ ADS1115 #1 SCL
                    ├─ ADS1115 #2 SCL
                    └─ GY-521 SCL
```

**I2C Adressen:**
- ADS1115 #1: 0x48 (ADDR → GND)
- ADS1115 #2: 0x49 (ADDR → VDD)
- GY-521 (MPU6050): 0x68

---

## 📊 SENSOR INPUTS (J2 vom Sensorboard):

```
J2 Pin 1 → ADS1115 #1 A0 (Starterbatterie)
J2 Pin 2 → ADS1115 #1 A1 (Verbraucherbatterie)
J2 Pin 3 → ADS1115 #1 A2 (Tank)
J2 Pin 4 → ADS1115 #1 A3 (Öldruck)
J2 Pin 5 → ADS1115 #2 A0 (Motor-Temp)
J2 Pin 6 → ESP32 GPIO25 (Drehzahl, digital)
J2 Pin 7 → 5V (für Optokoppler)
J2 Pin 8 → GND
```

---

## 🌊 FLOWSENSOR INPUT (J3):

**Diesel-Durchflusssensor:**

```
J3 Pin 1: Signal (Impulse) → ESP32 GPIO4
J3 Pin 2: GND

ESP32 GPIO4 (Flowsensor):
├─ Pull-up 10kΩ → 3.3V (intern oder extern)
└─ Signal vom Flowsensor (Open-Collector)

Funktionsweise:
- Flowsensor gibt Impulse (Hall-Sensor)
- Jeder Impuls = X ml Diesel
- ESP32 zählt Impulse → Durchfluss berechnen
```

---

## 🎯 GPIO MAPPING:

### **ESP32 Pinout:**

```
GPIO21: I2C SDA (zu allen I2C-Devices)
GPIO22: I2C SCL (zu allen I2C-Devices)
GPIO25: Drehzahl Input (digital, von Sensorboard)
GPIO4:  Flowsensor Input (digital, Impulszähler)

3.3V:   Power für alle Module
GND:    Common Ground
```

---

## 🔧 POWER DISTRIBUTION:

```
Powerboard 3.3V (J1) ─┬─ ESP32 3.3V
                      ├─ ADS1115 #1 VDD
                      ├─ ADS1115 #2 VDD
                      ├─ GY-521 VCC
                      └─ Pull-up Widerstände

GND (J1) ─────────────┴─ Alle GND-Pins (Common Ground)
```

---

## 📐 SCHALTPLAN DETAILLIERT:

### **ADS1115 #1 Verdrahtung:**
```
VDD  → 3.3V
GND  → GND
SCL  → ESP32 GPIO22 (I2C Bus)
SDA  → ESP32 GPIO21 (I2C Bus)
ADDR → GND (I2C Adresse 0x48)
A0   → Sensorboard Out1 (Starterbatterie)
A1   → Sensorboard Out2 (Verbraucherbatterie)
A2   → Sensorboard Out3 (Tank)
A3   → Sensorboard Out4 (Öldruck)
```

### **ADS1115 #2 Verdrahtung:**
```
VDD  → 3.3V
GND  → GND
SCL  → ESP32 GPIO22 (I2C Bus)
SDA  → ESP32 GPIO21 (I2C Bus)
ADDR → VDD (I2C Adresse 0x49)
A0   → Sensorboard Out5 (Motor-Temp)
A1   → (Reserve)
A2   → (Reserve)
A3   → (Reserve)
```

### **GY-521 (MPU6050) Verdrahtung:**
```
VCC  → 3.3V
GND  → GND
SCL  → ESP32 GPIO22 (I2C Bus)
SDA  → ESP32 GPIO21 (I2C Bus)
INT  → (nicht verbunden, optional GPIO)
AD0  → GND (I2C Adresse 0x68)
```

---

## 🔧 BOM:

| Ref | Komponente | Wert | Gehäuse | Anzahl | Preis |
|-----|------------|------|---------|--------|-------|
| U1 | ESP32 DevKit | - | DevKit | 1 | 8€ |
| U2 | ADS1115 #1 | 0x48 | Modul | 1 | 3€ |
| U3 | ADS1115 #2 | 0x49 | Modul | 1 | 3€ |
| U4 | GY-521 (MPU6050) | 0x68 | Modul | 1 | 3€ |
| J1 | Schraubklemme | 2-pol | 5mm | 1 | 0.30€ |
| J2 | Buchsenleiste | 8-pol | 2.54mm | 1 | 0.50€ |
| J3 | Schraubklemme | 2-pol | 5mm | 1 | 0.30€ |
| R1, R2 | Widerstand | 4.7kΩ | 0805 | 2 | 0.10€ |
| | | | | **Total** | **~18€** |

---

## 📐 PCB LAYOUT:

**Größe:** 100×80 mm

```
┌────────────────────────────────────────┐
│ [J1] Power In (3.3V)                   │
│                                        │
│                    [U4 GY-521]         │  ← GY-521 (oben rechts)
│                    Pitch/Roll          │
│                                        │
│  [U1 ESP32 DevKit]                    │  ← ESP32 (links mitte)
│   │││││││││││││││                     │
│                                        │
│  [U2 ADS1115]  [U3 ADS1115]           │  ← ADS1115 (unten)
│   0x48          0x49                   │
│                                        │
│  [J2 8-pol]         [J3 Flow]         │  ← Inputs (unten)
│  Sensorboard        Flowsensor        │
│                                        │
└────────────────────────────────────────┘
```

---

## 💡 DESIGN NOTES:

**Wichtig:**
- I2C Bus kurz halten (<30cm Gesamt!)
- Pull-ups NAH am ESP32
- ADS1115 Module nah am ESP32
- GY-521 kann weiter weg (weniger kritisch)
- GND-Plane großflächig!
- 3.3V Traces: 0.8mm
- Signal Traces: 0.3mm

**I2C Bus Stabilität:**
- Pull-ups 4.7kΩ sind Standard
- Bei langen Leitungen: 2.2kΩ verwenden
- Twisted Pair für SDA/SCL bei >20cm
- 100nF Kondensatoren an jedem VDD-Pin

---

## 🎯 VERWENDUNG:

```
1. Power vom Powerboard (J1: 3.3V + GND)
2. Sensoren vom Sensorboard (J2: 8-pol Stecker)
3. Flowsensor anschließen (J3: Signal + GND)
4. USB-Kabel für Programmierung (ESP32 USB-Port)
```

**Fertig! ✅**

---

## 📊 MQTT TOPICS (zur Erinnerung):

```
boat/sensors/battery/starter/voltage      (ADS1115 #1 A0)
boat/sensors/battery/house/voltage        (ADS1115 #1 A1)
boat/sensors/tank/diesel/level            (ADS1115 #1 A2)
boat/sensors/engine/oil_pressure          (ADS1115 #1 A3)
boat/sensors/engine/temperature           (ADS1115 #2 A0)
boat/sensors/engine/rpm                   (GPIO25)
boat/sensors/engine/fuel_flow             (GPIO4)
boat/sensors/motion/pitch                 (GY-521)
boat/sensors/motion/roll                  (GY-521)
boat/sensors/motion/yaw                   (GY-521, optional)
```

---

## 🔧 SOFTWARE NOTES:

### **ADS1115 Konfiguration:**
```cpp
// ADS1115 #1 (0x48)
Adafruit_ADS1115 ads1(0x48);
ads1.begin();
ads1.setGain(GAIN_ONE);  // ±4.096V range

// ADS1115 #2 (0x49)
Adafruit_ADS1115 ads2(0x49);
ads2.begin();
ads2.setGain(GAIN_ONE);
```

### **MPU6050 Konfiguration:**
```cpp
// GY-521 (0x68)
MPU6050 mpu;
mpu.initialize();
mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);
mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_250);
```

### **Flowsensor (GPIO4):**
```cpp
// Interrupt-basiert
volatile uint32_t flowPulses = 0;
void IRAM_ATTR flowISR() {
  flowPulses++;
}

void setup() {
  pinMode(4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(4), flowISR, RISING);
}

// Flow berechnen
float flow_ml_per_pulse = 2.25;  // Sensor-spezifisch!
float flow_rate = (flowPulses * flow_ml_per_pulse) / time_seconds;
```

---

## 🎊 ZUSAMMENFASSUNG:

**Mainboard kann:**
✅ 5× analoge Sensoren auslesen (2× ADS1115)  
✅ 1× digitale Drehzahl messen (GPIO25)  
✅ 1× Flowsensor zählen (GPIO4)  
✅ Pitch/Roll/Yaw messen (GY-521)  
✅ WiFi/MQTT kommunizieren (ESP32)  
✅ Alles über I2C Bus koordinieren  

**Das ist das Herzstück! 🔥**
