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

**Status:** ⚙️ Hardware läuft stabil, Software getestet, auf Boot im Einsatz

---

## 🎯 Features

**Messwerte:**
- ⚡ 2× Batteriespannungen (Starter + Verbraucher)
- ⛽ Tank-Füllstand (VDO Widerstandssensor)
- 🌡️ Motor-Temperatur (VDO Sender)
- 🛢️ Öldruck (VDO Sender)
- 🔄 Motor-Drehzahl (W-Klemme Lichtmaschine)
- 🧭 Pitch & Roll (MPU6050 IMU) - **ECHT, nicht simuliert!**
- 💧 Durchfluss (optional, FM-HL3012)

**System:**
- 📡 MQTT über WiFi (Raspberry Pi als Broker)
- 🌐 WiFiManager (Captive Portal für einfaches Setup)
- 🔄 OTA Updates (kein USB-Kabel nötig nach Installation)
- 🔋 12V Bordnetz → 5V → 3.3V (saubere Stromversorgung)
- 🧪 TEST_MODE (Fake-Daten für Entwicklung, Mixed-Mode für Tests)
- 🛡️ Watchdog (automatischer Neustart bei Problemen)

**Topics:**
- Eigene Topics: `boot/sensoren/*` (V, bar, RPM, °C, %)
- SignalK Topics: `signalk/vessels/self/*` (Standard-konform)
- Status Topics: `boot/status/esp32/*` (online, uptime, WiFi)

---

## 🛠️ Hardware-Übersicht

### **Drei Platinen (handgelötet auf Lochraster):**

```
┌─────────────────────┐
│  Power Board        │  12V → 5V → 3.3V
├─────────────────────┤
│  Sensor Board       │  VDO Sensoren auslesen
├─────────────────────┤
│  Main Board         │  ESP32 + I2C Module
└─────────────────────┘
```

### **1. Power Board (50×46mm)**
- **Input:** 12V Bordnetz (via Buck Converter 5V)
- **Output:** 3.3V (AMS1117) + 5V (Pass-through)
- **Funktion:** Saubere Stromversorgung für digitale + analoge Teile

**Komponenten:**
- AMS1117-3.3V Linear Regler
- 2× 100µF + 2× 100nF Kondensatoren
- Schraubklemmen für Ein-/Ausgänge

[→ Schaltplan](hardware/schaltplaene/power_board.html)

---

### **2. Sensor Board (36×46mm)**
- **Input:** 6× VDO Sensoren (Widerstandswerte 0-240Ω)
- **Output:** 6× Analog-Signale (0-5V)
- **Funktion:** Spannungsteiler, Pull-ups, Filterung

**Schaltungstopologie:**

**Batterie-Spannungsteiler (2×):**
```
12V Batterie → 10kΩ → [Abgriff] → 4.7kΩ → GND
                        ↓
                    zum ADC (0-3.3V)
```

**Pull-up Widerstände (4×):**
```
+5V → 1kΩ → [Abgriff] → VDO Sensor (0-240Ω) → GND
              ↓
           100nF parallel (Filter)
              ↓
           zum ADC
```

**RPM (W-Klemme):**
```
W-Terminal → 1N4007 → 10kΩ → [Abgriff] → 4.7kΩ → GND
                                ↓
                             10µF (Glättung)
                                ↓
                             zum ADC
```

**Wichtig:** 
- 100nF Kondensatoren sind PARALLEL (Signal zu GND), nicht in Serie!
- Common GND über Bootsmasse (von Power Board)

[→ Schaltplan](hardware/schaltplaene/sensor_board.html)

---

### **3. Main Board (Größe variabel)**
- **Zentrale:** ESP32 WROOM-32 DevKit (38-pin)
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

**KRITISCH:**
- ADS1115 #1: ADDR → GND (Adresse 0x48)
- ADS1115 #2: ADDR → VDD (Adresse 0x49) ⚠️ **NICHT vergessen!**
- MPU6050: AD0 → GND oder offen (Adresse 0x68)

**Entkopplung:**
- 4× 100nF Keramik-Kondensatoren (direkt an VDD/GND Pins!)
- Je einer für: ESP32, ADS#1, ADS#2, MPU6050

[→ Schaltplan](hardware/schaltplaene/main_board.html)

---

## 💻 Software

### **Firmware Features:**

**Konfiguration:**
- WiFiManager Captive Portal (SSID + Passwort)
- MQTT Server/Port/User/Pass konfigurierbar (kein Hardcoding!)
- Settings im Flash gespeichert (überleben Neustart)
- Factory Reset: Boot-Button 3s beim Start gedrückt halten

**Modi:**
- **TEST_MODE = true:** Fake-Daten (außer MPU6050 = echt!)
- **TEST_MODE = false:** Alle echten Sensoren
- Mixed-Mode perfekt für Entwicklung

**Update-Raten:**
- **5 Hz** (200ms): RPM, Durchfluss
- **1 Hz** (1s): Tank, Temp, Öldruck
- **0.2 Hz** (5s): Batterien, Pitch/Roll
- **0.1 Hz** (10s): Status/Heartbeat

**Sicherheit:**
- Watchdog Timer (10s, automatischer Neustart)
- MQTT Last Will (offline-Status bei Ausfall)
- Retained Messages (letzter Wert bleibt)

[→ Code](firmware/ESP32_BootMonitor_TEST.ino)  
[→ Installation](docs/installation.md)

---

## 📦 Stückliste (BOM)

### **Hauptkomponenten:**

| Teil | Anzahl | Typ | Preis (ca.) | Link |
|------|--------|-----|-------------|------|
| ESP32 DevKit | 1 | WROOM-32, 38-pin | 8€ | [AZ-Delivery](https://www.az-delivery.de) |
| ADS1115 | 2 | 16-bit ADC Breakout | 2× 6€ | Amazon/eBay |
| MPU6050 | 1 | GY-521 Breakout | 4€ | Amazon/eBay |
| AMS1117-3.3V | 1 | Linear Regler | 1€ | Reichelt/Conrad |
| Buck 12V→5V | 1 | 10A Step-Down | 10€ | Amazon |
| Lochraster | 3 | Verschiedene Größen | 5€ | Conrad |
| Widerstände | ~20 | 1kΩ, 4.7kΩ, 10kΩ | 2€ | Sortiment |
| Kondensatoren | ~10 | 100nF, 100µF, 10µF | 3€ | Sortiment |
| Diode 1N4007 | 1 | Gleichrichter | 0.50€ | Conrad |
| Draht | 5m | 0.6mm Kupferlackdraht | 3€ | Conrad |
| Schraubklemmen | 10 | 2/3-polig | 5€ | Conrad |
| Stiftleisten | Div. | 2.54mm männlich/weiblich | 3€ | Sortiment |

**Gesamt: ~60€** (ohne Gehäuse, Kabel, VDO Sensoren)

**Optional:**
- 3D-Druck Gehäuse (PETG, ~50g) → 3€
- Silikon-Verguss (50ml) → 8€
- Kabelverschraubungen PG7/PG9 → 5€
- Belüftungsmembran M12 → 2€

[→ Detaillierte BOM](hardware/bom.md)

---

## 🚀 Quick Start

### **1. Hardware bauen**
1. Power Board löten & testen (5V + 3.3V Check)
2. Sensor Board löten & testen (Spannungen mit Multimeter prüfen)
3. Main Board löten (ESP32 auf Buchsenleiste!)
4. I2C-Scanner Test (muss 0x48, 0x49, 0x68 finden)

[→ Detaillierte Anleitung](docs/installation.md)

### **2. Firmware hochladen**
```bash
# Arduino IDE Libraries installieren:
- WiFiManager by tzapu
- PubSubClient by Nick O'Leary
- Adafruit ADS1X15
- Adafruit MPU6050
- Adafruit Unified Sensor

# Code öffnen & hochladen
ESP32_BootMonitor_TEST.ino
```

### **3. WiFi & MQTT konfigurieren**
1. ESP32 startet Access Point "BootMonitor-Setup"
2. Mit Handy/Laptop verbinden (Passwort: boot2025)
3. Captive Portal öffnet automatisch
4. WiFi SSID + Passwort eingeben
5. MQTT Server IP + Port eingeben (z.B. 192.168.1.100:1883)
6. Speichern → ESP32 verbindet sich

### **4. MQTT Broker einrichten (Raspberry Pi)**
```bash
sudo apt install mosquitto mosquitto-clients
sudo systemctl enable mosquitto

# Test ob's läuft:
mosquitto_sub -h localhost -t 'boot/#' -v
```

### **5. BoatOS Dashboard verbinden**
- MQTT Topics abonnieren
- Widgets erstellen (Gauges, Graphen, Balken)
- Live-Daten fließen!

[→ Dashboard Setup](docs/dashboard-integration.md)

---

## 🐛 Troubleshooting

### **Problem: I2C-Scanner findet nur 1 Gerät**
**Ursache:** ADDR Pin vom ADS1115 #2 nicht verbunden  
**Lösung:** ADDR Pin von ADS#2 auf VDD (3.3V) löten

### **Problem: Bootloop beim Start**
**Ursache:** Watchdog startet bevor WiFi fertig ist  
**Lösung:** Code v1.1 verwenden (Watchdog nach WiFi-Setup)

### **Problem: MQTT zeigt 0.00 für alle Werte**
**Ursache:** Meist temporär beim Start  
**Lösung:** 1-2 Minuten warten, dann kommen Daten

### **Problem: MPU6050 nicht gefunden**
**Ursache:** I2C Verkabelung, ADDR Pin falsch  
**Lösung:** SDA/SCL Pins prüfen, AD0 auf GND

### **Problem: VDO Sensoren zeigen falsche Werte**
**Ursache:** Kalibrierung fehlt oder falsch  
**Lösung:** Kennlinien in Code anpassen (siehe Kalibrierung)

[→ Komplettes Troubleshooting](docs/troubleshooting.md)

---

## 📊 Kalibrierung

VDO Sensoren haben spezifische Kennlinien (Widerstand → Messwert).

**Standard VDO Kennlinien (bereits im Code):**

**Tank:**
- Leer: 240Ω
- Voll: 33Ω

**Temperatur:**
- 120°C = 18Ω
- 100°C = 52Ω
- 80°C = 110Ω
- 60°C = 240Ω
- 40°C = 560Ω

**Öldruck:**
- 5 bar = 10Ω
- 3 bar = 43Ω
- 1 bar = 120Ω
- 0 bar = 184Ω

**Wenn VDO Instrumente parallel laufen:**
- Kennlinien verschieben sich leicht (5-10%)
- Nach Installation neu kalibrieren!

[→ Kalibrierungs-Anleitung](kalibrierung/vdo-kennlinien.md)

---

## 🔧 Installation auf dem Boot

### **Montageort:**
- ✅ Trocken (nicht Motorraum!)
- ✅ Zugänglich (für Updates/Reset)
- ✅ Belüftet (Kondenswasser!)
- ✅ Fern von Kompass (WiFi stört)
- ❌ Nicht in Bilge
- ❌ Nicht im direkten Spritzwasser

**Ideal:** Schalttafel-Rückseite, unter Steuerkonsole

### **Gehäuse:**
- IP65 oder besser
- 3D-Druck: PETG oder ASA (nicht PLA!)
- Kabelverschraubungen PG7/PG9
- Belüftungsmembran (gegen Kondensation!)

### **Verguss:**
- Nur Unterseite vergießen (ESP32 Oberseite frei!)
- Neutrales Silikon (nicht Bau-Silikon!)
- Lötstellen & Drahtbrücken schützen
- USB-Port freilassen für Updates

[→ Installations-Guide](docs/installation.md)

---

## 🔗 Integration mit SignalK

```bash
# SignalK MQTT Gateway Plugin
cd ~/.signalk
npm install @signalk/signalk-mqtt-gw

# In SignalK WebUI konfigurieren:
# Plugin → MQTT Gateway → Enable
# Host: localhost, Port: 1883
# Subscribe: signalk/vessels/self/#
```

**Fertig!** SignalK wandelt MQTT Topics automatisch in SignalK Deltas um.

---

## 📈 Erweiterungen

**Mögliche Module:**
- 🔥 Heizungssteuerung (Webasto/Eberspächer)
- 💧 Bilgepumpen-Monitoring
- ⚓ Ankerwacht (GPS + Alarm)
- 💡 Licht-Steuerung
- 🌡️ Innenraum-Klima
- 🔋 Power-Monitoring (Shunt für Ströme)

**Alles über MQTT = einfach erweiterbar!**

---

## 🤝 Community

**Du hast das Projekt nachgebaut?**  
→ Zeig's uns! [Discussions](https://github.com/...)

**Fehler gefunden?**  
→ [Issue](https://github.com/.../issues) öffnen

**Verbesserung gebaut?**  
→ [Pull Request](https://github.com/.../pulls) willkommen!

---

## 📚 Verbindung zum Buch

Dieses Projekt ist die **technische Umsetzung** von **Band 2 (Kapitel 7 & 8)**.

**Was wo zu finden ist:**

**Hier auf GitHub (kostenlos):**
- ✅ Kompletter Code (funktionsfähig)
- ✅ Schaltpläne (nachbaubar)
- ✅ Stückliste (mit Links)
- ✅ Installation (Step-by-Step)
- ✅ Troubleshooting (alle Probleme)

**Im Buch (folgt 2025, ~7€ Kindle):**
- Die **Story** vom Bauen (Trial & Error)
- Alle **Fehler & Learnings** im Detail
- Warum Messen besser ist als Raten
- Dashboard-Integration Schritt-für-Schritt
- Kalibrierung mit echten Beispielen

**Strategie:** Hardware muss frei sein (sonst baut's keiner nach!). Die Story gibt's im Buch für die, die "Danke" sagen wollen.

**Hier ist alles. Wenn's dir hilft, kauf das Buch. Wenn nicht, auch OK.** 😊

---

## 📄 Lizenz

- **Software:** MIT License (frei verwendbar)
- **Hardware:** CC BY-SA 4.0 (mit Namensnennung)
- **Dokumentation:** CC BY-SA 4.0

---

## ⚓ Status

- ✅ Hardware: Funktioniert, getestet
- ✅ Software: Stabil, OTA läuft
- ✅ MQTT: Live-Daten fließen
- ✅ Dashboard: Widgets laufen
- 🔄 Gehäuse: 3D-Druck läuft
- 🔄 Boot-Installation: Vorbereitung
- 📝 Buch: In Arbeit

---

**Made with ⚓ and many ☕**

*"Man braucht kein NMEA2000 für 2000€. Man braucht nur ESP32 für 8€ und die Bereitschaft zu löten."*
