# Logbuch ohne Pose

**Authentische DIY-Projekte rund ums Boot – ohne Schönfärberei**

> *„Keine perfekten Tutorials, sondern echte Lernreisen mit allen Höhen, Tiefen, Fehlern und Aha-Momenten."*

Diese Repository-Serie dokumentiert praktische Boot-Projekte mit der ehrlichen Perspektive eines Bootseigentümers, der selbst Hand anlegt – inklusive aller Umwege, Fehleinschätzungen und improvisierten Lösungen.

---

## 📚 Die Buchreihe

### Band 1: Der Motor läuft
**Vom guten Boot zum Smart-Boat – eine Lernreise**

*Status: ✅ Fertig geschrieben! (8/8 Kapitel, 19.000 Wörter)*

Das Boot funktioniert. Motor läuft. Alles schwimmt.  
Aber: Voltmeter zeigt immer 12.0V. Tankuhr zeigt immer 3/4.  
Spoiler: Das nervt.

**Was drin ist:**
- Der Kauf (frisch lackiert, Motor läuft, Elektrik „gewachsen")
- Die Erstinspektion (Kabel-Archäologie, 4 Jahrzehnte, 5 Schichten)
- Der erste Sommer (funktioniert! Aber: Wackelkontakt-Heizung...)
- Der erste Winter (Frustration, YouTube, 12 Tabs, 134€ Warenkorb)
- Die Idee (Arduino IDE, „Hallo Welt!", ESP32, 8€ Hardware)
- Das erste Projekt (LED-Beleuchtung... mit Rauch)
- Die Vision (von „2 Projekte" zu „ALLES digitalisieren")
- Der Motor läuft (Epilog: 3 Jahre später, BoatOS v2.4, Motor läuft immer noch)

[→ Zum Band](band-1-der-motor-laeuft/)

**Running Gag:** *"Der Motor läuft. Seit 1985. Immer."*

**Launch:** Februar 2026

---

### Band 2: Strom ist nie einfach
**Solar, Batterien und die Realität der Autarkie**

*Status: 🔄 In Arbeit (6/8 Kapitel fertig)*

280 Ah Akku. 260 Wp Solar. Das sollte reichen.  
Spoiler: Kommt drauf an.

**Was drin ist:**
- Erwartungen vs. Realität (warum 280 Ah nicht immer genug sind)
- Solar im Sommer vs. Solar im Winter (Physik ist gemein)
- Fehlannahmen & kleine Katastrophen (der Akku verzeiht, aber merkt sich)
- Improvisieren statt Planen (wie man mit Gas, faltbaren Panels und Routine klarkommt)
- Messen statt Raten (ESP32 + Sensoren = echte Zahlen statt Bauchgefühl)
- Das System lernt mit (MQTT, Dashboard, Prognosen)

[→ Zum Band](band-2-strom/)

**Launch:** Februar 2026

---

### Band 3: Sensoren & Monitoring
**ESP32, MQTT und die Digitalisierung der VDO-Geber**

*Status: ✅ Dokumentation komplett, Buch in Planung*

Drei handgelötete Platinen. Ein ESP32. Acht Sensoren.  
Und die Frage: Warum zeigt der I2C-Scanner nur ein Gerät statt drei?

**Was entsteht:**
- 8-Kanal Sensor-System (Batterien, Tank, Temp, Öl, RPM, Pitch, Roll)
- MQTT-basierte Datenübertragung zum Raspberry Pi
- Live-Dashboard mit allen Bootsdaten
- VDO Instrumente bleiben als mechanisches Backup

[→ Zum Projekt](band-3-sensoren/)

**Themen:**
- ESP32 + ADS1115 + MPU6050 (I2C Debugging inklusive)
- MQTT ohne Hardcoding (Captive Portal für WiFi + MQTT Config)
- Mixed Mode Testing (Fake-Daten + echter MPU6050)
- VDO Sensor-Kennlinien (von Widerstand zu Litern)
- Marine-Elektronik Basics (Spannungsteiler, Pull-ups, Bootsmasse)
- Silikon-Verguss & 3D-Druck Gehäuse

**Launch:** Q2 2026

---

### Band 4-5: BoatOS
**Das komplette Boot-Betriebssystem**

*Status: 💻 System läuft (v2.4), Buch-Arbeit 2026*

Nicht nur ein Dashboard. Ein komplettes Betriebssystem.  
Mit eigener Navigation. Moderner UX. Voller Integration.

**Das System:**
- 🗺️ **Navigation** (eigene Implementierung, OpenSeaMap, GPS-Tracking)
- 📊 **Dashboard** (alle Sensoren live: 8× ESP32, MQTT)
- 🎮 **Steuerung** (Heizung, Licht, Pumpen, Alarme)
- 🏠 **Home Assistant** (Smart Home fürs Boot)
- 📱 **Mobile-First** (Tablet, Handy, Touch-optimiert)
- 🌐 **WiFi Remote** (von überall auf dem Boot)

**Technologie:**
- Raspberry Pi 4 + Home Assistant OS
- React Frontend (TypeScript, Leaflet, Tailwind)
- Python Backend (FastAPI, MQTT, GPSd)
- 8× ESP32 (Sensoren via MQTT)

**➡️ Zum Projekt: [github.com/bigbrainlabs/BoatOS](https://github.com/bigbrainlabs/BoatOS)**

**Kosten:**
- Minimal: 110€ (Raspberry Pi, GPS, SD-Karte)
- Empfohlen: 230€ (+ Display, Gehäuse)
- Komplett: 524€ (+ 8× ESP32, Sensoren)
- **vs. Raymarine Axiom 7: 2.300€** → Ersparnis: 1.776€!

**Warum eigene Navigation?**
- ❌ OpenCPN: zu komplex, nicht mobile-freundlich, veraltete UX
- ✅ Eigene Lösung: modern, integriert, mobile-first

**Launch Bücher:** Q3 2026 (Band 4), Q4 2026 (Band 5)

---

### Band 6: Die Ventil-Heizung
**Wie ein Winterproblem zur Innovation wurde**

*Status: 📋 Outline fertig, Prototyp läuft*

3 Stunden mit Föhn am gefrorenen Ventil?  
Oder 15 Minuten mit selbstgebauter Heizung?  
Die Wahl ist klar.

**Die Innovation:**
- Clamshell-Heizmanschette (aufklappbar!)
- ESP32 Temperatur-Regelung
- 3D-druckbar (PETG)
- 15 Minuten statt 3+ Stunden

**Das Business-Modell:**
- ✅ DIY: Kostenlos (STL, Code, Anleitung auf GitHub)
- 💼 Firmen: Lizenz (500€/Jahr oder 5€/Stück)
- 📜 Gebrauchsmuster (10 Jahre Schutz)

**Die Story:**
- Von Problem (gefroren!) zu Prototyp (schmilzt!) zu Lösung (funktioniert!)
- Trial & Error dokumentiert (mit geschmolzenem Plastik)
- Patent-Strategie (Gebrauchsmuster)
- Open Source + Fair Licensing

**Launch:** Q2 2026

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
- Epic Fail (5° daneben!)
- Endschalter retten alles
- BoatOS Integration
- **"WEIL ICH'S KANN. WEIL'S JEDER KANN!"**

**Launch:** Q3 2026

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

**Erste Schritte:**
- Arduino IDE
- ESP32 DevKit (8€)
- Breadboard & Jumper Wires
- Spannungsteiler (100kΩ + 47kΩ)
- LED-Strips (12V)
- OLED Display 0.96" (I2C)

### **Band 3 - Monitoring System:**

**Hardware:**
- ESP32 WROOM-32 DevKit
- 2× ADS1115 (16-bit ADC, I2C)
- MPU6050 (6-DOF IMU)
- VDO Marine-Sensoren (Tank, Temp, Öl, RPM)
- 12V→5V Buck Converter + AMS1117 Linear Regler
- Handgelötete Lochraster-Platinen (3 Stück)

**Software:**
- Arduino IDE (C++)
- WiFiManager (Captive Portal)
- PubSubClient (MQTT)
- MQTT Broker (Mosquitto auf Raspberry Pi)

### **Band 4-5 - BoatOS:**

**Hardware:**
- Raspberry Pi 4 (4GB)
- 7" Touch Display
- USB GPS-Modul
- 8× ESP32 (Sensoren)

**Software:**
- Home Assistant OS
- React 18 + TypeScript (Frontend)
- Python 3.11 + FastAPI (Backend)
- Leaflet (Karten)
- Mosquitto MQTT Broker
- InfluxDB (optional, historische Daten)

**➡️ Komplette Doku: [github.com/bigbrainlabs/BoatOS](https://github.com/bigbrainlabs/BoatOS)**

### **Band 6 - Ventil-Heizung:**

**Hardware:**
- ESP32 DevKit
- PTC-Heizelement (60W, 12V)
- DS18B20 Temperatur-Sensor
- OLED Display 0.96"
- 3D-gedrucktes Gehäuse (PETG)

**Software:**
- Arduino IDE (C++)
- Temperatur-Regelung (50-60°C)
- Display-Anzeige (Live-Temperatur)

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

## 📖 Konzept

**Open Source + Fair Licensing:**

### **Für DIYer:**
```
✅ Alle Infos kostenlos (GitHub)
✅ Hardware-Designs (STL, Schaltpläne)
✅ Software (Code, Firmware)
✅ Dokumentation (Anleitungen, BOMs)

"Hier ist alles. Bau's nach!"
```

### **Für Firmen (Band 6 - Ventil-Heizung):**
```
💼 Kommerzielle Nutzung: Lizenz erforderlich
💼 Option A: Jahres-Lizenz (500€)
💼 Option B: Per-Unit (5€/Stück)
📜 Geschützt durch Gebrauchsmuster

"Willst du's verkaufen? Zahl fair!"
```

### **Für Leser:**
```
📚 Bücher = Die Story + Kontext
📚 GitHub = Die Technik + Details
📚 Beides zusammen = Vollständiges Bild

"Verstehen UND Umsetzen!"
```

---

## 🚀 Roadmap

**2026:**
- Q1: Band 1 + 2 Launch ✨
- Q2: Band 3 + 6 Launch
- Q3: Band 4 + 7 Launch
- Q4: Band 5 Launch

**2027:**
- Q1+: Weitere Projekte (Community-driven)

**Langfristig:**
- Band 8+: Weitere Innovationen
- BoatOS Weiterentwicklung (AIS, Offline-Karten, Mobile App)
- Community-Projekte
- Hardware-Produkte (Ventil-Heizung, Auto-Sat, etc.)

---

## 📊 Status Overview

```
═══════════════════════════════════════════════
BAND-ÜBERSICHT:
───────────────────────────────────────────────
Band 1:  ✅ Fertig (19.000 Wörter, alle 8 Kapitel)
Band 2:  🔄 75% (6/8 Kapitel)
Band 3:  ✅ Doku komplett
Band 4:  💻 System läuft (v2.4)
Band 5:  💻 System läuft (v2.4)
Band 6:  📋 Outline fertig
Band 7:  📋 Outline fertig

PROJEKTE:
───────────────────────────────────────────────
Monitoring:       ✅ Hardware läuft
BoatOS:           ✅ v2.4 stabil
Ventil-Heizung:   🔄 Prototyp V2 funktioniert
Auto-Sat:         🔄 Prototyp in Arbeit

LAUNCH-TIMELINE:
───────────────────────────────────────────────
Februar 2026:   Band 1 + 2 📚
Q2 2026:        Band 3 + 6 📚
Q3 2026:        Band 4 + 7 📚
Q4 2026:        Band 5 📚
```

---

## 📂 Repository-Struktur

```
logbuch-ohne-pose/
├── README.md                    ← Diese Datei
├── LICENSE
│
├── band-1-der-motor-laeuft/     ✅ KOMPLETT
│   ├── README.md
│   ├── OUTLINE.md
│   ├── MARKETING.md
│   └── kapitel/
│       ├── 01-der-kauf.md
│       ├── 02-erstinspektion.md
│       ├── 03-erster-sommer.md
│       ├── 04-erster-winter.md
│       ├── 05-die-idee.md
│       ├── 06-erstes-projekt.md
│       ├── 07-die-vision.md
│       └── 08-der-motor-laeuft.md
│
├── band-2-strom/                🔄 In Arbeit
│   ├── README.md
│   └── kapitel/
│       ├── 01-erwartungen-vs-realitaet.md
│       ├── 03-solar-hoffnung-grenzen.md
│       ├── 05-fehlannahmen-katastrophen.md
│       ├── 06-improvisieren.md
│       ├── 07-messen-statt-raten.md
│       └── 08-system-lernt-mit.md
│
├── band-3-sensoren/             ✅ Doku komplett
│   ├── README.md
│   ├── hardware/
│   ├── firmware/
│   └── docs/
│
└── Externe Repositories:
    ├── BoatOS/                  ➡️ github.com/bigbrainlabs/BoatOS
    ├── Band 6 (geplant)         ➡️ Eigenes Repo für Hardware
    └── Band 7 (geplant)         ➡️ Eigenes Repo für Hardware
```

---

## 🔗 Links

**GitHub:**
- **Hauptprojekt:** [github.com/bigbrainlabs/logbuch-ohne-pose](https://github.com/bigbrainlabs/logbuch-ohne-pose)
- **BoatOS:** [github.com/bigbrainlabs/BoatOS](https://github.com/bigbrainlabs/BoatOS)

**Bücher:**
- Amazon KDP (ab Februar 2026)
- Band 1-7 geplant

**Community:**
- GitHub Discussions (bevorzugt!)
- GitHub Issues (für Bugs/Features)

---

## 🤝 Mitmachen

**Community Contributions willkommen!**

**Du kannst helfen mit:**
- 🐛 **Bug Reports** (GitHub Issues)
- 💡 **Feature Ideas** (GitHub Discussions)
- 📝 **Dokumentation** (PRs willkommen!)
- 🔧 **Code** (Frontend, Backend, Firmware)
- 📚 **Beta-Reading** (Bücher Korrektur lesen)
- 🎨 **Design** (UI/UX für BoatOS)

---

## 📜 Lizenz

**Code & Hardware:**
- MIT License (frei nutzbar, modifizierbar, verteilbar)

**Bücher:**
- Copyright (aber GitHub-Inhalte bleiben open!)

**Ventil-Heizung (Band 6):**
- DIY: CC BY-NC-SA (kostenlos für non-commercial)
- Commercial: Lizenz erforderlich
- Gebrauchsmuster: 10 Jahre Schutz

---

## 🙏 Credits

**Inspiriert von:**
- Der DIY-Marine-Community
- YouTube-Tutorial-Erstellern
- Allen die teilen statt verkaufen

**Technologie:**
- Home Assistant
- OpenSeaMap
- SignalK
- ESP32/Arduino Community

---

## 📧 Kontakt

**Fragen? Ideen? Feedback?**

- 💬 GitHub Discussions (bevorzugt!)
- 🐛 GitHub Issues (für Bugs)
- 📧 Email: [deine email hier]

---

## ⚓ Über das Projekt

**„Logbuch ohne Pose" entstand aus Frustration.**

Frustration über:
- Tutorial-Videos die Probleme verschweigen
- „Einfache" Anleitungen die kompliziert sind
- Projekte die „in 2 Stunden" doch 2 Tage dauern
- Versteckte Kosten
- Fehlende Ehrlichkeit

**„Logbuch ohne Pose" ist anders:**

✅ Ehrlich über Fehler  
✅ Realistisch über Zeit  
✅ Transparent über Kosten  
✅ Authentisch über Probleme  

**Keine Pose. Nur Wahrheit.**

---

**Letzte Aktualisierung:** 25. Januar 2026

*„Der Motor läuft. Die Projekte auch. Die Bücher entstehen. Die Community wächst."*

**Los geht's! 🚀**
