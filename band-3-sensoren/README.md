# Band 3: Boot-Digitalisierung

**Von analogen VDO-Instrumenten zu MQTT & BoatOS**

> *Drei handgelötete Platinen. Ein ESP32. Acht Sensoren.*  
> *Und die Frage: Warum zeigt der I2C-Scanner nur ein Gerät statt drei?*

---

## 📖 Über dieses Projekt

Dies ist kein Plug-and-Play System.  
Keine fertige Lösung für 500 Euro.  
Kein "funktioniert sofort aus der Box".

Das ist ein DIY-Projekt für Bootsbesitzer, die:
- Selbst Hand anlegen wollen
- Verstehen wollen wie ihr System funktioniert
- Mit Lochraster und Lötkolben klarkommen
- Trial & Error nicht scheuen

**Was entsteht:**
- 8-Kanal Monitoring (Batterien, Tank, Motor, Lage)
- MQTT-basiert (Standard-Protokoll, keine Proprietary-Software)
- BoatOS Dashboard Integration (Live-Daten, Grafiken, Alarme)
- SignalK kompatibel (Standard für Marine-Daten)
- VDO Instrumente bleiben als Backup (Redundanz!)

**Status:** 🔧 Hardware & Firmware getestet, Boot-Installation ausstehend

---

## 🎯 Features

**Messwerte:**
- ⚡ 2× Batteriespannungen (Starter + Verbraucher)
- ⛽ Tank-Füllstand (VDO Widerstandssensor)
- 🌡️ Motor-Temperatur (VDO Sender)
- 🛢️ Öldruck (VDO Sender)
- 🔄 Motor-Drehzahl (W-Klemme Lichtmaschine)
- 🧭 Pitch & Roll (MPU6050 IMU)
- 💧 Durchfluss (optional)

**System:**
- 📡 MQTT über WiFi (Raspberry Pi als Broker)
- 🌐 WiFiManager (Captive Portal für einfaches Setup)
- 🔄 OTA Updates (kein USB-Kabel nötig nach Installation)
- 🔋 12V Bordnetz → 5V → 3.3V (saubere Stromversorgung)
- 🧪 TEST_MODE (Fake-Daten für Entwicklung)
- 🛡️ Watchdog (automatischer Neustart bei Problemen)

**MQTT Topics:**
```
boot/sensoren/batterie1      (V)
boot/sensoren/batterie2      (V)
boot/sensoren/tank           (%)
boot/sensoren/oeldruck       (bar)
boot/sensoren/temperatur     (°C)
boot/sensoren/drehzahl       (RPM)
boot/sensoren/durchfluss     (l/h)
boot/sensoren/pitch          (°)
boot/sensoren/roll           (°)
boot/status/esp32/online     (true/false)
boot/status/esp32/uptime     (s)

signalk/vessels/self/*       (Standard-konform)
```

---

## 🛠️ Hardware-Übersicht

### **Drei Platinen (handgelötet auf Lochraster):**

```
┌─────────────────────┐
│  POWERBOARD         │  5V rein → 3.3V raus
├─────────────────────┤
│  SENSORBOARD        │  VDO Sensoren → Spannungsteiler
├─────────────────────┤
│  MAINBOARD          │  ESP32 + 2×ADS1115 + MPU6050
└─────────────────────┘
```

---

### **1. Powerboard**

- **Input:** 5V (vom vorhandenen 12V→5V Netzteil)
- **Output:** 3.3V (AMS1117) für ESP32
- **Funktion:** Saubere Stromversorgung

**Komponenten:**
- AMS1117-3.3V Linear Regler
- 2× 100µF + 2× 100nF Kondensatoren
- Schraubklemmen für Ein-/Ausgänge

---

### **2. Sensorboard**

- **Input:** 8× Sensorsignale (12V Bereich)
- **Output:** 8× Analog-Signale (0-3.8V für ADS1115)
- **Funktion:** Spannungsteiler, Signal-Aufbereitung

**Spannungsteiler (für alle 12V Signale):**
```
12V Signal → 100kΩ → [Abgriff] → 47kΩ → GND
                         ↓
                    zum ADS1115 (max 3.84V)
```

**Formel:** Vout = 12V × 47k / (100k + 47k) = 3.84V ✓

**Kanalbelegung:**

| Klemme | Signal | ADS1115 | Beschreibung |
|--------|--------|---------|--------------|
| K1 | BAT1+ | #1 CH0 | Starterbatterie |
| K2 | BAT2+ | #1 CH1 | Versorgerbatterie |
| K3 | TANK | #1 CH2 | VDO Tankgeber |
| K4 | OELDRUCK | #1 CH3 | VDO Öldruckgeber |
| K5 | TEMP | #2 CH0 | VDO Temperaturgeber |
| K6 | RPM | #2 CH1 | W-Klemme Lichtmaschine |
| K7 | FLOW | #2 CH2 | Durchflusssensor |
| K8 | RESERVE | #2 CH3 | (frei) |

---

### **3. Mainboard**

- **Zentrale:** ESP32 WROOM-32 DevKit
- **ADCs:** 2× ADS1115 (16-bit, I2C)
- **IMU:** MPU6050 (6-DOF, I2C)
- **Funktion:** Daten sammeln, verarbeiten, via MQTT senden

**I2C Bus:**
```
ESP32 GPIO21 (SDA) ────┬─── ADS1115 #1 (0x48)
                       ├─── ADS1115 #2 (0x49)
                       └─── MPU6050   (0x68)

ESP32 GPIO22 (SCL) ────┴─── (alle parallel)
```

**⚠️ KRITISCH – I2C Adressen:**

| Gerät | Adresse | ADDR-Pin |
|-------|---------|----------|
| ADS1115 #1 | 0x48 | → GND |
| ADS1115 #2 | 0x49 | → VDD (3.3V) |
| MPU6050 | 0x68 | (fest) |

**Beide ADS1115 auf GND = Adresskollision = Fehler!**

---

## 💻 Firmware

### **Dateien:**

| Datei | Zweck |
|-------|-------|
| `ESP32_BootMonitor.ino` | Produktiv-Firmware |
| `ESP32_BootMonitor_TEST.ino` | Test-Firmware mit Fake-Daten |

### **Features:**

- WiFiManager Captive Portal (SSID + Passwort)
- MQTT Server/Port konfigurierbar
- Settings im Flash gespeichert
- Factory Reset: Boot-Button 3s gedrückt halten

### **Update-Raten:**

| Intervall | Sensoren |
|-----------|----------|
| 200ms (5 Hz) | RPM, Durchfluss |
| 1s (1 Hz) | Tank, Temp, Öldruck |
| 5s (0.2 Hz) | Batterien, Pitch/Roll |
| 10s (0.1 Hz) | Status/Heartbeat |

### **Benötigte Libraries:**

```
- WiFiManager by tzapu
- PubSubClient by Nick O'Leary
- Adafruit ADS1X15
- Adafruit MPU6050
- Adafruit Unified Sensor
```

---

## 📦 Stückliste (BOM)

### **Hauptkomponenten:**

| Teil | Anzahl | Preis (ca.) |
|------|--------|-------------|
| ESP32 DevKit WROOM-32 | 1 | 8€ |
| ADS1115 Breakout | 2 | 12€ |
| MPU6050 GY-521 | 1 | 4€ |
| AMS1117-3.3V | 1 | 1€ |
| Lochraster (div. Größen) | 3 | 5€ |
| Widerstände 100kΩ | 8 | 1€ |
| Widerstände 47kΩ | 8 | 1€ |
| Kondensatoren 100nF | 6 | 1€ |
| Kondensatoren 100µF | 2 | 1€ |
| Schraubklemmen | 10 | 5€ |
| Stiftleisten | div. | 3€ |
| Draht 0.6mm | 5m | 3€ |

**Gesamt Hardware: ~45€**

### **Optional:**

| Teil | Preis |
|------|-------|
| 3D-Druck Gehäuse (ASA) | 5€ |
| Silikon-Verguss | 8€ |
| Kabelverschraubungen | 5€ |

---

## 🔗 BoatOS Integration

Das BoatOS Dashboard empfängt die MQTT-Daten direkt und zeigt sie in Widgets an:

- **Gauges** für Batterien, Temperatur, Öldruck
- **Balken** für Tankfüllstand
- **Zahlen** für RPM, Durchfluss
- **Graphen** für Verlauf (historisch)
- **Alarme** bei kritischen Werten

Die Integration erfolgt über MQTT → keine zusätzliche Software nötig.

Zusätzlich werden die Daten auch als SignalK Topics publiziert für Kompatibilität mit anderen Marine-Systemen.

---

## 📊 VDO Kalibrierung

VDO Sensoren haben spezifische Kennlinien (Widerstand → Messwert).

**Standard VDO Kennlinien:**

**Tank:**
| Füllstand | Widerstand |
|-----------|------------|
| Leer | 240Ω |
| Voll | 33Ω |

**Temperatur:**
| Temp | Widerstand |
|------|------------|
| 40°C | 560Ω |
| 60°C | 240Ω |
| 80°C | 110Ω |
| 100°C | 52Ω |
| 120°C | 18Ω |

**Öldruck:**
| Druck | Widerstand |
|-------|------------|
| 0 bar | 184Ω |
| 1 bar | 120Ω |
| 3 bar | 43Ω |
| 5 bar | 10Ω |

**Hinweis:** Wenn VDO Instrumente parallel laufen, verschieben sich die Kennlinien leicht (5-10%). Nach Installation neu kalibrieren!

---

## 🐛 Troubleshooting

| Problem | Ursache | Lösung |
|---------|---------|--------|
| I2C-Scanner findet nur 1 Gerät | ADDR Pin ADS1115 #2 falsch | ADDR auf VDD (3.3V) löten |
| Bootloop beim Start | Watchdog zu früh | Code-Update verwenden |
| MQTT zeigt 0.00 | Startphase | 1-2 Min warten |
| MPU6050 nicht gefunden | I2C Verkabelung | SDA/SCL prüfen |
| VDO Werte falsch | Kalibrierung | Kennlinien anpassen |

---

## 📁 Repository-Struktur

```
band-3-sensoren/
├── README.md                 ← Diese Datei
├── firmware/
│   ├── ESP32_BootMonitor.ino
│   └── ESP32_BootMonitor_TEST.ino
├── hardware/
│   ├── powerboard.md
│   ├── sensorboard.md
│   └── mainboard.md
├── kalibrierung/
│   └── vdo-kennlinien.md
└── docs/
    ├── installation.md
    └── troubleshooting.md
```

---

## 📚 Verbindung zum Buch

Dieses Projekt ist die **technische Umsetzung** von **Band 3: Sensoren & Monitoring**.

**Hier auf GitHub (kostenlos):**
- ✅ Kompletter Code
- ✅ Hardware-Dokumentation
- ✅ Stückliste
- ✅ Troubleshooting

**Im Buch (erscheint Q2 2026):**
- Die Story vom Bauen (Trial & Error)
- Alle Fehler & Learnings im Detail
- Warum Messen besser ist als Raten
- Kalibrierung mit echten Beispielen

---

## 📜 Lizenz

- **Software:** MIT License
- **Hardware:** CC BY-SA 4.0
- **Dokumentation:** CC BY-SA 4.0

---

## ⚓ Status

```
Hardware:           ✅ Getestet
Firmware:           ✅ Stabil
MQTT:               ✅ Funktioniert
BoatOS Integration: ✅ Widgets laufen
Boot-Installation:  🔄 Ausstehend
Buch:               🔄 In Arbeit
```

---

**Made with ⚓ and ☕**

*"Man braucht kein NMEA2000 für 2000€. Man braucht nur ESP32 für 8€ und die Bereitschaft zu löten."*
