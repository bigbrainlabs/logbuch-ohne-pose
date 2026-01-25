# Installation Guide - Boot-Monitoring System

**Schritt-für-Schritt Anleitung vom Löten bis zum laufenden System**

---

## 📋 Vorbereitung

### **Was du brauchst:**
- [ ] Alle Bauteile (siehe [BOM](../hardware/bom.md))
- [ ] Lötkolben (25-40W) + Lötzinn
- [ ] Multimeter (zur Fehlersuche)
- [ ] Computer mit Arduino IDE
- [ ] USB-Kabel (Micro-USB für ESP32)
- [ ] Raspberry Pi mit Mosquitto (MQTT Broker)

### **Optional aber hilfreich:**
- [ ] I2C-Scanner Sketch (zum Testen)
- [ ] Dritte Hand (Löthelfer)
- [ ] Entlötlitze (für Fehler)
- [ ] Lupe (für SMD-Pads)

---

## 🔨 Phase 1: Power Board bauen

**Ziel:** 12V → 5V → 3.3V Stromversorgung

### **Schritt 1.1: Platine vorbereiten**
```
Lochraster 50×46mm
- Mit Cutter auf Größe brechen
- Kanten entgraten (Feile)
- Mit Alkohol reinigen
```

### **Schritt 1.2: Layout planen**
```
┌─────────────────────┐
│  IN+ IN- (12V)      │
│  ┌──────────┐       │
│  │ AMS1117  │       │
│  └──────────┘       │
│  OUT+ OUT- (3.3V)   │
│  5V+ 5V- (Pass)     │
└─────────────────────┘
```

### **Schritt 1.3: Komponenten löten**
**Reihenfolge:**
1. ✅ AMS1117-3.3V (flach aufliegend, Kühlkörper nach oben)
2. ✅ 100µF Elko Input (Polung beachten! Minus = Streifen)
3. ✅ 100nF Keramik Input (Polung egal)
4. ✅ 100µF Elko Output (Polung!)
5. ✅ 100nF Keramik Output
6. ✅ Schraubklemmen (Input 12V, Output 3.3V, Pass 5V)

**Kritische Punkte:**
- ⚠️ Elko-Polung: Minus-Streifen zur GND-Seite!
- ⚠️ AMS1117 Pinout: IN - GND - OUT (von links)
- ⚠️ Kühlkörper nicht auf GND (isolieren!)

### **Schritt 1.4: Verkabelung**
```
IN+  → AMS1117 Pin 1 (IN)
IN-  → AMS1117 Pin 2 (GND) + alle Kondensator Minus
OUT+ → AMS1117 Pin 3 (OUT)
5V+  → Pass-through von Buck Input
GND  → Gemeinsame Masse
```

### **Schritt 1.5: Test (WICHTIG!)**
**Ohne Last:**
```
Buck 5V anlegen
Multimeter:
- Input:  sollte ~5V sein
- Output: sollte 3.25-3.35V sein
- GND:    0V Differenz zu Input GND
```

**Mit Last (LED + 1kΩ):**
```
3.3V → 1kΩ → LED → GND
Spannung sollte stabil bei 3.3V bleiben
LED leuchtet
```

✅ **Power Board fertig!**

---

## 🔨 Phase 2: Sensor Board bauen

**Ziel:** Spannungsteiler + Pull-ups für VDO Sensoren

### **Schritt 2.1: Platine vorbereiten**
```
Lochraster 36×46mm
Sauber brechen + entgraten
```

### **Schritt 2.2: Widerstände löten**

**Spannungsteiler (2×):**
```
Batterie → 10kΩ → [Abgriff] → 4.7kΩ → GND
              ↓
           zum ADC
```
- Starter-Batterie: Kanal 1
- Verbraucher-Batterie: Kanal 2

**Pull-ups (4×):**
```
+5V → 1kΩ → [Abgriff] → VDO Sensor → GND
              ↓
           100nF parallel!
              ↓
           zum ADC
```
- Tank: Kanal 3
- Temperatur: Kanal 4
- Öldruck: Kanal 5
- Reserve: Kanal 6

**RPM (W-Klemme):**
```
W → 1N4007 → 10kΩ → [Abgriff] → 4.7kΩ → GND
  (Anode)              ↓
                    10µF Elko
                       ↓
                    zum ADC
```

### **Schritt 2.3: Kondensatoren**
**KRITISCH:** 100nF sind PARALLEL (Signal zu GND), NICHT in Serie!

```
RICHTIG:                FALSCH:
Signal ─┬─ ADC          Signal ── 100nF ── ADC
        │                         
      100nF              
        │                         
       GND              
```

### **Schritt 2.4: Schraubklemmen**
```
6× Eingänge (VDO Sensoren)
6× Ausgänge (zu Main Board ADCs)
1× +5V
1× GND
```

### **Schritt 2.5: Test**
**Ohne Sensoren (Pull-ups):**
```
+5V anlegen
Multimeter an Abgriffpunkten:
- Tank:  sollte ~5V sein (kein Sensor = unendlich Ω)
- Temp:  sollte ~5V sein
- Öl:    sollte ~5V sein
```

**Mit Widerstand simulieren:**
```
120Ω zwischen Sensor-Ausgang und GND
Spannung sollte sinken auf ~4.5V
```

✅ **Sensor Board fertig!**

---

## 🔨 Phase 3: Main Board bauen

**Ziel:** ESP32 + 2× ADS1115 + MPU6050

### **Schritt 3.1: I2C-Adressen planen**

**KRITISCH:**
```
ADS1115 #1: ADDR → GND     = Adresse 0x48
ADS1115 #2: ADDR → VDD     = Adresse 0x49 ⚠️ WICHTIG!
MPU6050:    AD0  → GND     = Adresse 0x68
```

### **Schritt 3.2: Buchsenleisten für ESP32**
```
ESP32 DevKit 38-Pin:
- 2× 19-polige Buchsenleisten
- ESP32 ist ABNEHMBAR (wichtig für Verguss!)
- Erst Buchsen löten, dann ESP32 reinstecken
```

### **Schritt 3.3: Module platzieren**
```
Layout-Tipp:
┌────────────────────────┐
│  [ESP32 WROOM-32]      │
│                        │
│  [ADS1] [ADS2] [MPU]   │
└────────────────────────┘

Oder vertikal:
┌──────┐
│ ESP  │
├──────┤
│ ADS1 │
├──────┤
│ ADS2 │
├──────┤
│ MPU  │
└──────┘
```

**Empfehlung:** MPU6050 in der Mitte (mechanisch stabiler bei Vibrationen!)

### **Schritt 3.4: I2C Bus verdrahten**
```
ESP32 GPIO21 (SDA) ──┬── ADS1 SDA
                     ├── ADS2 SDA
                     └── MPU SDA

ESP32 GPIO22 (SCL) ──┬── ADS1 SCL
                     ├── ADS2 SCL
                     └── MPU SCL

3.3V ────────────────┬── ADS1 VDD
                     ├── ADS2 VDD
                     └── MPU VCC

GND ─────────────────┴── alle GND
```

**Mit Kupferlackdraht:**
- SDA/SCL: direkt durchverbinden (Bus!)
- VDD: Stern-Topologie von Power Board
- GND: gemeinsame Fläche (großzügig)

### **Schritt 3.5: ADDR Pins setzen**
```
ADS1115 #1:
  ADDR Pin → GND löten

ADS1115 #2:
  ADDR Pin → VDD löten ⚠️ KRITISCH!
```

### **Schritt 3.6: Entkopplung**
**4× 100nF Keramik:**
- Jeweils direkt an VDD/GND Pins!
- ESP32: zwischen 3V3 und GND
- ADS1 #1: zwischen VDD und GND
- ADS1 #2: zwischen VDD und GND
- MPU6050: zwischen VCC und GND

**So nah wie möglich an den Modulen!**

### **Schritt 3.7: Test (ohne Sensor Board)**

**ESP32 Strom-Test:**
```
USB-Kabel anstecken
ESP32 sollte booten (interne LED blinkt kurz)
```

**I2C-Scanner hochladen:**
```arduino
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  Serial.println("I2C Scanner");
}

void loop() {
  for(byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if(Wire.endTransmission() == 0) {
      Serial.print("Device at 0x");
      Serial.println(addr, HEX);
    }
  }
  delay(5000);
}
```

**Erwartete Ausgabe:**
```
I2C Scanner
Device at 0x48    ← ADS1115 #1
Device at 0x49    ← ADS1115 #2
Device at 0x68    ← MPU6050
```

**Falls NICHT alle 3 gefunden:**
- 0x48 fehlt? → ADS #1 VDD/GND prüfen
- 0x49 fehlt? → ADS #2 ADDR Pin nicht auf VDD! ⚠️
- 0x68 fehlt? → MPU6050 VCC/GND prüfen

✅ **Main Board fertig!**

---

## 🔨 Phase 4: Boards zusammenschalten

### **Schritt 4.1: Stromversorgung**
```
Buck 5V → Power Board IN
Power Board 3.3V → Main Board VDD
Power Board 5V → Sensor Board +5V
Power Board GND → alle GND zusammen
```

### **Schritt 4.2: Sensor → ADC Verbindungen**
```
Sensor Board Kanal 1 → ADS1 A0 (Starter-Batterie)
Sensor Board Kanal 2 → ADS1 A1 (Verbraucher-Batterie)
Sensor Board Kanal 3 → ADS1 A2 (Tank)
Sensor Board Kanal 4 → ADS1 A3 (Temperatur)
Sensor Board Kanal 5 → ADS2 A0 (Öldruck)
Sensor Board Kanal 6 → ADS2 A1 (RPM)
```

### **Schritt 4.3: Test (Gesamt-System)**
```
Buck 5V anlegen (12V vom Bordnetz)
ESP32 bootet
I2C-Scanner findet alle 3 Geräte
```

✅ **Hardware komplett!**

---

## 💻 Phase 5: Firmware hochladen

### **Schritt 5.1: Arduino IDE vorbereiten**

**ESP32 Board installieren:**
```
File → Preferences → Additional Boards Manager URLs:
https://dl.espressif.com/dl/package_esp32_index.json

Tools → Board → Boards Manager
Suche: "esp32" → Install "ESP32 by Espressif"
```

**Libraries installieren:**
```
Sketch → Include Library → Manage Libraries

Installieren:
- WiFiManager by tzapu (v2.0.16-rc.2 oder neuer)
- PubSubClient by Nick O'Leary
- Adafruit ADS1X15
- Adafruit MPU6050
- Adafruit Unified Sensor
- Adafruit BusIO
```

### **Schritt 5.2: Code anpassen**
```arduino
// In ESP32_BootMonitor_TEST.ino:

#define TEST_MODE true    // Für erste Tests!
#define WDT_TIMEOUT 10    // Watchdog 10s

// MQTT Config passiert über Captive Portal!
```

### **Schritt 5.3: Upload**
```
Tools → Board → "ESP32 Dev Module"
Tools → Upload Speed → "115200"
Tools → Flash Frequency → "80MHz"
Tools → Partition Scheme → "Default"

Upload klicken
```

**Bei Problemen:**
- Boot-Button gedrückt halten beim Upload
- USB-Kabel wechseln (manche sind nur zum Laden!)
- Treiber installieren (CH340/CP2102)

### **Schritt 5.4: Serial Monitor checken**
```
Tools → Serial Monitor → 115200 baud

Erwartete Ausgabe:
========================================
ESP32 Boot Monitor - TEST MODE v1.1
*** USING FAKE SENSOR DATA ***
========================================

I2C initialized (SDA=21, SCL=22)
✓ MPU6050 found @ 0x68 - providing REAL data!

*wm:AutoConnect
*wm:Starting Web Portal
*wm:AP IP address: 192.168.4.1
```

✅ **Firmware läuft!**

---

## 🌐 Phase 6: WiFi & MQTT konfigurieren

### **Schritt 6.1: Captive Portal öffnen**
```
1. Mit Handy/Laptop WLAN suchen
2. Netzwerk "BootMonitor-Setup" verbinden
3. Passwort: boot2025
4. Browser sollte automatisch Portal öffnen
   Falls nicht: http://192.168.4.1 eingeben
```

### **Schritt 6.2: Konfigurieren**
```
WiFi SSID:       [Dein Boot-WLAN]
WiFi Password:   [Passwort]

MQTT Server IP:  [Raspberry Pi IP, z.B. 192.168.1.100]
MQTT Port:       1883
MQTT User:       [leer lassen wenn keine Auth]
MQTT Password:   [leer lassen]
```

**Save klicken!**

### **Schritt 6.3: Verbindung prüfen**
```
Serial Monitor sollte zeigen:
WiFi connected!
IP Address: 192.168.1.XXX
Connecting to MQTT... connected!
```

✅ **WiFi & MQTT läuft!**

---

## 🖥️ Phase 7: MQTT Broker (Raspberry Pi)

### **Schritt 7.1: Mosquitto installieren**
```bash
sudo apt update
sudo apt install mosquitto mosquitto-clients
sudo systemctl enable mosquitto
sudo systemctl start mosquitto
```

### **Schritt 7.2: Test**
```bash
# In Terminal 1:
mosquitto_sub -h localhost -t 'boot/#' -v

# Sollte zeigen:
boot/status/esp32/online true
boot/sensoren/batterie/starter 12.50
boot/sensoren/motor/drehzahl 0.00
...
```

✅ **MQTT Daten fließen!**

---

## 📊 Phase 8: Dashboard (BoatOS)

### **Schritt 8.1: Node-RED installieren**
```bash
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
sudo systemctl enable nodered
sudo systemctl start nodered
```

### **Schritt 8.2: MQTT Nodes**
```
http://[raspberry-ip]:1880

Palette → Install → "node-red-dashboard"
```

### **Schritt 8.3: Flow erstellen**
```
mqtt in → "boot/sensoren/batterie/starter"
  ↓
gauge → "Starter-Batterie" (9-15V)

mqtt in → "boot/sensoren/motor/drehzahl"
  ↓
gauge → "Motor RPM" (0-3500)
```

**Dashboard:** `http://[raspberry-ip]:1880/ui`

✅ **Dashboard zeigt Live-Daten!**

---

## 🚤 Phase 9: Boot-Installation

### **Schritt 9.1: Gehäuse vorbereiten**
```
- 3D-gedrucktes Gehäuse (PETG!)
- Oder IP65 Kunststoff-Gehäuse
- Kabelverschraubungen PG7/PG9
- Belüftungsmembran M12
```

### **Schritt 9.2: Verguss (optional)**
```
NUR Platinen-Unterseite vergießen!
- ESP32 rausnehmen (Buchsenleisten!)
- Boards auf Fach legen (Unterseite oben)
- Neutrales Silikon auftragen (2-3mm)
- 24h aushärten lassen
- ESP32 wieder reinstecken
```

### **Schritt 9.3: VDO Sensoren anschließen**
```
Sensor Board Klemmen:
┌────────┬──────────────────┐
│ Kanal  │ VDO Sensor       │
├────────┼──────────────────┤
│ 1 (A0) │ Starter-Batt +   │
│ 2 (A1) │ Verbraucher +    │
│ 3 (A2) │ Tank Sender      │
│ 4 (A3) │ Temp Sender      │
│ 5 (A4) │ Öl Sender        │
│ 6 (A5) │ W-Klemme         │
└────────┴──────────────────┘

Alle Sensor-Minus → Bootsmasse
```

### **Schritt 9.4: TEST_MODE deaktivieren**
```arduino
#define TEST_MODE false   // Echte Sensoren!
```

**Neu hochladen (OTA oder USB)**

✅ **System auf Boot läuft!**

---

## ✅ Abschluss-Checkliste

- [ ] Alle 3 Boards funktionieren einzeln
- [ ] I2C-Scanner findet 0x48, 0x49, 0x68
- [ ] WiFi verbindet sich
- [ ] MQTT Daten kommen an
- [ ] Dashboard zeigt Werte
- [ ] VDO Sensoren liefern plausible Werte
- [ ] Gehäuse ist dicht (IP65)
- [ ] Belüftung vorhanden (Kondenswasser!)
- [ ] Kabel ordentlich verlegt
- [ ] System läuft stabil über 24h

---

## 🆘 Bei Problemen

→ Siehe [Troubleshooting Guide](troubleshooting.md)

**Häufigste Fehler:**
1. ADDR Pin vergessen (0x49 fehlt)
2. 100nF in Serie statt parallel
3. Elko-Polung falsch
4. GND nicht durchverbunden
5. Boot-Button beim Upload nicht gedrückt

---

**Geschätzte Bauzeit:**
- Power Board: 1h
- Sensor Board: 2h
- Main Board: 3h
- Software: 1h
- Test & Debug: 2-4h
- **Gesamt: 9-11h** (über 2-3 Tage verteilt)

**Viel Erfolg! ⚓🔧**
