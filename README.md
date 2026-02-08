# Logbuch ohne Pose

**Authentische DIY-Projekte rund ums Boot – ohne Schönfärberei**

> *„Keine perfekten Tutorials, sondern echte Lernreisen mit allen Höhen, Tiefen, Fehlern und Aha-Momenten."*

> *„Selbstgemacht ist wissen was drin ist und bezahlbar."*

Diese Repository-Serie dokumentiert praktische Boot-Projekte mit der ehrlichen Perspektive eines Bootseigentümers, der selbst Hand anlegt – inklusive aller Umwege, Fehleinschätzungen und improvisierten Lösungen.

---

## 📚 Die Buchreihe

### Band 1: Der Motor läuft
**Schrauben, Fluchen und der erste Start**

*Status: ✅ Veröffentlicht (DE + EN auf Amazon)*

Das Boot funktioniert. Motor läuft. Alles schwimmt.  
Aber: Voltmeter zeigt immer 12.0V. Tankuhr zeigt immer 3/4.  
Spoiler: Das nervt.

**Was drin ist:**
- Der Kauf (frisch lackiert, Motor läuft, Elektrik „gewachsen")
- Die Erstinspektion (Kabel-Archäologie, 4 Jahrzehnte, 5 Schichten)
- Der erste Sommer (funktioniert! Aber: Wackelkontakt-Heizung...)
- Der erste Winter (Frustration, YouTube, Bastelkiste durchgewühlt)
- Die Idee (Arduino IDE, „Hallo Welt!", ESP32, Elektronik-Vorwissen hilft)
- Das erste Projekt (LED-Beleuchtung... mit Rauch)
- Die Vision (von „2 Projekte" zu „ALLES digitalisieren")
- Epilog: 3 Jahre später (BoatOS, der Motor läuft immer noch)

**Auch auf Englisch:** *Logbook Without Posing – Volume 1: The Engine Runs*

[→ Zum Band](band-1-der-motor-laeuft/)

**Running Gag:** *"Der Motor läuft. Seit 1989. Immer."*

---

### Band 2: Strom ist nie einfach
**Kabel, Chaos und die Erleuchtung**

*Status: ✅ Veröffentlicht (DE + EN auf Amazon)*

280 Ah Akku. 260 Wp Solar. Das sollte reichen.  
Spoiler: Kommt drauf an.

**Was drin ist:**
- Erwartungen vs. Realität (warum 280 Ah nicht immer genug sind)
- Die Verbraucher-Inventur (was zieht eigentlich wie viel?)
- Solar im Sommer vs. Solar im Winter (Physik ist gemein)
- Laden ohne Sonne (Landstrom, Lichtmaschine, Alternativen)
- Fehlannahmen & kleine Katastrophen (der Akku verzeiht, aber merkt sich)
- Improvisieren statt Planen (wie man mit Gas, faltbaren Panels und Routine klarkommt)
- Messen statt Raten (ESP32 + Sensoren = echte Zahlen statt Bauchgefühl)
- Das System lernt mit (MQTT, Dashboard, Prognosen)

**Auch auf Englisch:** *Logbook Without Posing – Volume 2: Power Is Never Simple*

[→ Zum Band](band-2-strom/)

---

### Band 3: Sensoren & Monitoring
**ESP32, MQTT und die Digitalisierung der VDO-Geber**

*Status: 🔧 Kapitel 1-4 fertig, Hardware & Doku komplett*

Drei handgelötete Platinen. Ein ESP32. Acht Kanäle.  
Und die Frage: Warum zeigt der I2C-Scanner nur ein Gerät statt drei?

**Das System (3-Board-Architektur):**
- **Powerboard:** 12V→5V Buck Converter + AMS1117 3.3V Regler
- **Sensorboard:** Anschlüsse für VDO-Sensoren, Spannungsteiler, Pull-ups
- **Mainboard:** ESP32 + 2× ADS1115 (16-bit ADC) + MPU6050 (6-DOF IMU)

**Gemessene Werte:**
- 3× Batteriespannung (Starter, Verbraucher, Bow-Thruster)
- Tankfüllstand (über VDO-Geber)
- Öldruck & Öltemperatur
- Motortemperatur
- Drehzahl (RPM)
- Durchfluss Diesel (Fuel Flow)
- Neigung (Pitch/Roll über MPU6050)

[→ Zum Projekt](band-3-sensoren/)

**Themen:**
- ESP32 + ADS1115 + MPU6050 (I2C Debugging inklusive)
- MQTT ohne Hardcoding (Captive Portal für WiFi + MQTT Config)
- Mixed Mode Testing (Fake-Daten + echter MPU6050)
- VDO Sensor-Kennlinien (von Widerstand zu Litern)
- Marine-Elektronik Basics (Spannungsteiler, Pull-ups, Bootsmasse)
- Silikon-Verguss & 3D-Druck Gehäuse

---

### Band 4-5: BoatOS
**Das komplette Boot-Betriebssystem**

*Status: 💻 System läuft, Buch-Arbeit 2026*

Nicht nur ein Dashboard. Ein komplettes Betriebssystem.  
Mit eigener Navigation. Moderner UX. Voller Integration.

**Das System:**
- 🗺️ **Navigation** (eigene Offline-Navigation, OSM/OpenSeaMap als Vektor-Tiles)
- 📊 **Dashboard** (eigenes Dashboard mit Editor, alle Sensoren live via MQTT)
- 🎮 **Steuerung** (Heizung, Licht, Pumpen, Alarme)
- 📱 **Mobile-First** (Tablet, Handy, Touch-optimiert)
- 🌐 **WiFi Remote** (von überall auf dem Boot)
- ⛵ **SignalK** (Brücke für Sensordaten zu anderen Geräten)

**Technologie:**
- Raspberry Pi 4 (Pi 5 zu stromhungrig für Marine-Einsatz)
- Eigene Offline-Navigation (OSM Vektor-Tiles)
- Eigenes Dashboard mit integriertem Editor
- Python Backend (FastAPI, MQTT, GPSd)
- ESP32 Sensor-System (siehe Band 3)
- Mosquitto MQTT Broker
- SignalK Integration

**➡️ Zum Projekt: [github.com/bigbrainlabs/BoatOS](https://github.com/bigbrainlabs/BoatOS)**

**Kosten:**
- Minimal: ~110€ (Raspberry Pi 4, GPS, SD-Karte)
- Empfohlen: ~280€ (+ Display, Gehäuse)
- Komplett: ~450€ (+ Sensor-System, Gehäuse)
- **vs. Raymarine Axiom 7: 2.300€** → Ersparnis: ~1.850€!

**Warum eigene Navigation?**
- ❌ OpenCPN: zu komplex, nicht mobile-freundlich, veraltete UX
- ✅ Eigene Lösung: modern, integriert, mobile-first, 100% offline

---

### Band 6: Die Ventil-Heizung
**Von Kabelgewirr zu smarten Heizringen**

*Status: 🔧 Prototyp V3 in Entwicklung*

3 Stunden mit Föhn am gefrorenen Ventil?  
Oder 15 Minuten mit selbstgebauten Heizringen?  
Klick, Klett, frostfrei.

**Die Innovation:**
- Aufklappbare Heizringe (Clamshell-Design)
- Klettband-Fixierung, verschiedene Größen
- Controller-Einheit + Klemmleiste
- ASA-Filament + Armaflex-Isolierung
- Temperatur-geregelt
- 3D-druckbar

**Die Story:**
- Von Problem (gefroren!) zu Prototyp (schmilzt!) zu Lösung (funktioniert!)
- Trial & Error dokumentiert (mit geschmolzenem Plastik)
- Von Manschette (V1) über Heizringe (V2) zu Controller-System (V3)

[→ Zum Band](band-6-ventilheizung/)

---

### Band 7: Die Auto-Sat
**Weil automatisch cooler ist**

*Status: 📋 Outline fertig, Prototyp in Arbeit*

2 Minuten manuell ausrichten?  
Oder 6 Monate eine Automatik bauen?  
"WEIL ICH'S KANN!"

**Die Innovation:**
- Automatische Sat-Schüssel-Ausrichtung
- ESP32 + GPS + 2× Schrittmotoren
- Schneckengetriebe 1:40 (selbsthemmend!)
- Knopfdruck → Signal → TV läuft

**Die Kosten:**
- DIY: <150€
- Fertig kaufen: 900€ - 3.500€
- Ersparnis: 750€ - 3.350€!

**Die Story:**
- Von "Wie schwer kann das sein?" zu "ES FUNKTIONIERT!"
- Mechanik-Albtraum (Schneckengetriebe!)
- Trigonometrie schmerzt (GPS → Azimut/Elevation)
- **"WEIL ICH'S KANN. WEIL'S JEDER KANN!"**

[→ Zum Band](band-7-autosat/)

---

## 🎯 Philosophie

**„Logbuch ohne Pose" bedeutet:**

✅ **Fehler werden gezeigt** – nicht versteckt  
✅ **Trial & Error** dokumentiert – mit allen Rückschlägen  
✅ **Authentische Zeitangaben** – „drei Tage gebastelt" statt „kurze Einrichtung"  
✅ **Realistische Kosten** – keine versteckten Ausgaben  
✅ **Improvisationen** – weil nicht alles nach Plan läuft  
✅ **Lernkurven** – vom „sollte funktionieren" zum „funktioniert tatsächlich"

**Was du NICHT findest:**

❌ Perfekte Lösungen beim ersten Versuch  
❌ „Einfach und schnell" wenn es kompliziert war  
❌ Werbeprospekt-Optimismus  
❌ Verschweigen von Problemen

---

## 🛠️ Technologie-Stack

### **Band 1 - Die Basics:**

**Erste Schritte (mit Elektronik-Vorwissen):**
- Arduino IDE
- ESP32 DevKit (8€)
- Bastelkiste (Breadboard, Jumper, Widerstände)
- Spannungsteiler (100kΩ + 47kΩ)
- LED-Strips (12V, mit Vorwiderstand!)
- OLED Display 0.96" (I2C)

### **Band 3 - Sensor-System (3-Board-Architektur):**

**Hardware:**
```
┌─────────────┐
│ POWERBOARD  │  12V → 5V Buck → AMS1117 → 3.3V
└──────┬──────┘
       │
┌──────┴──────┐
│ SENSORBOARD │  VDO-Anschlüsse, Spannungsteiler, Pull-ups
└──────┬──────┘
       │
┌──────┴──────┐
│  MAINBOARD  │  ESP32 + 2× ADS1115 + MPU6050
└─────────────┘
```

- 1× ESP32 WROOM-32 DevKit
- 2× ADS1115 (16-bit ADC, I2C, 8 Kanäle gesamt)
- 1× MPU6050 (6-DOF IMU für Pitch/Roll)
- VDO Marine-Sensoren (Tank, Temp, Öl, RPM)
- Handgelötete Lochraster-Platinen (3 Stück)

**Software:**
- Arduino IDE (C++)
- WiFiManager (Captive Portal)
- PubSubClient (MQTT)

### **Band 4-5 - BoatOS:**

**Hardware:**
- Raspberry Pi 4 (4GB, Pi 5 zu stromhungrig)
- 7" Touch Display (optional)
- USB GPS-Modul
- ESP32 Sensor-System (siehe Band 3)

**Software:**
- Eigene Offline-Navigation (OSM/OpenSeaMap als Vektor-Tiles)
- Eigenes Dashboard mit integriertem Editor
- Python 3.11 + FastAPI (Backend)
- Mosquitto MQTT Broker
- SignalK (Brücke für Sensordaten)

**➡️ Komplette Doku: [github.com/bigbrainlabs/BoatOS](https://github.com/bigbrainlabs/BoatOS)**

### **Band 6 - Ventil-Heizung:**

**Hardware:**
- PTC-Heizelement (60W, 12V)
- DS18B20 Temperatur-Sensor
- ESP32 Controller-Einheit + Klemmleiste
- 3D-gedrucktes Gehäuse (ASA-Filament)
- Armaflex-Isolierung

**Software:**
- Temperatur-Regelung
- Optional: MQTT-Integration (→ BoatOS)

### **Band 7 - Auto-Sat:**

**Hardware:**
- ESP32 DevKit
- GPS-Modul (mit ext. Antenne)
- 2× NEMA17 Schrittmotor
- 2× A4988 Stepper-Driver
- Schneckengetriebe 1:40
- Rillenkugellager 6000-2RS
- D-Shaft Wellen
- Schleifring
- 2× Endschalter

**Software:**
- Arduino IDE (C++)
- AccelStepper Library
- TinyGPS++ (GPS)
- Trigonometrie (Satellitenwinkel)
- MQTT Integration

---

## 💸 Business-Modell

### 100% Open Source. Alles. Für immer.

```
✅ Alle Schaltpläne
✅ Aller Code
✅ Alle STL-Dateien
✅ Alle Anleitungen
✅ Für JEDEN – auch kommerziell
✅ Kein Gebrauchsmuster
✅ Kein Papierkram
```

### „Lizenzgebühren" 😄

> *„Du findest das nützlich? Kauf die Buchreihe. Dann sind wir quitt."*
>
> *„Du willst das kommerziell nutzen? Kauf die Buchreihe. Zweimal."*

**~50€ für 7 Bände. Das ist der Deal.**

Kein Anwalt. Kein Patent. Kein Drama.  
Nur ein Typ der sein Zeug teilt und hofft, dass die Leute fair sind.

### **Für Leser:**
```
📚 Bücher = Die Story + Kontext
📚 GitHub = Die Technik + Details
📚 Beides zusammen = Vollständiges Bild

"Verstehen UND Umsetzen!"
```

---

## 📊 Status

```
═══════════════════════════════════════════════
BÜCHER:
───────────────────────────────────────────────
Band 1:  ✅ LIVE auf Amazon (DE + EN)
Band 2:  ✅ LIVE auf Amazon (DE + EN)
Band 3:  🔧 Kapitel 1-4 fertig
Band 4:  📋 Outline
Band 5:  📋 Outline
Band 6:  🔧 Prototyp V3
Band 7:  📋 Outline

PROJEKTE:
───────────────────────────────────────────────
Sensor-System:    ✅ Hardware läuft (3-Board-Architektur)
BoatOS:           ✅ Stabil
Ventil-Heizung:   🔧 Prototyp V3
Auto-Sat:         🔄 Prototyp in Arbeit
```

---

## 📂 Repository-Struktur

```
logbuch-ohne-pose/
├── README.md                    ← Diese Datei
├── LICENSE
│
├── band-1-der-motor-laeuft/     ✅ LIVE
│   ├── README.md
│   ├── kapitel/
│   │   ├── de/
│   │   └── en/
│   └── ...
│
├── band-2-strom/                ✅ LIVE
│   ├── README.md
│   └── kapitel/
│       ├── de/
│       └── en/
│
├── band-3-sensoren/             🔧 In Arbeit
│   ├── README.md
│   ├── hardware/
│   │   ├── pcb-designs/
│   │   ├── ESP32_Firmware/
│   │   └── Images/
│   ├── 3D-Print/
│   ├── kapitel/
│   └── docs/
│
├── band-4-fundament/            📋 Outline
│   └── README.md
│
├── band-5-integration/          📋 Outline
│   └── README.md
│
├── band-6-ventilheizung/        🔧 In Arbeit
│   ├── README.md
│   └── OUTLINE.md
│
├── band-7-autosat/              📋 Outline
│   ├── README.md
│   └── OUTLINE.md
│
└── Externes Repository:
    └── BoatOS/  ➡️ github.com/bigbrainlabs/BoatOS
```

---

## 🔗 Links

**GitHub:**
- **Hauptprojekt:** [github.com/bigbrainlabs/logbuch-ohne-pose](https://github.com/bigbrainlabs/logbuch-ohne-pose)
- **BoatOS:** [github.com/bigbrainlabs/BoatOS](https://github.com/bigbrainlabs/BoatOS)

**Bücher:**
- Amazon KDP – Band 1 + 2 live (DE + EN)

**Community:**
- GitHub Discussions (bevorzugt!)
- GitHub Issues (für Bugs/Features)

---

## 🤝 Mitmachen

**Community Contributions willkommen!**

- 🐛 **Bug Reports** (GitHub Issues)
- 💡 **Feature Ideas** (GitHub Discussions)
- 📝 **Dokumentation** (PRs willkommen!)
- 🔧 **Code** (Frontend, Backend, Firmware)
- 📚 **Beta-Reading** (Bücher Korrektur lesen)

---

## 📜 Lizenz

**Code & Hardware:** MIT License (frei nutzbar, modifizierbar, verteilbar)  
**Bücher:** Copyright (GitHub-Inhalte bleiben open)

---

## 🙏 Credits

**Inspiriert von:**
- Der DIY-Marine-Community
- Allen die teilen statt verkaufen

**Technologie:**
- OpenSeaMap
- SignalK
- ESP32/Arduino Community

---

## ⚓ Warum das Ganze?

**Nicht reich werden – unsterblich werden.**

In 20 Jahren googelt jemand „DIY Boot ESP32", findet dieses Repo, baut es nach, und denkt: *„Wer war dieser Maik?"*

Das ist der Plan.

---

*„Logbuch ohne Pose – Weil Hochglanz-Tutorials lügen."*
