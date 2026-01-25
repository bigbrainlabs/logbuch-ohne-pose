# Logbuch ohne Pose - Repository Struktur

**Komplette Übersicht aller Dateien und Ordner**

---

## 📁 Root-Level

```
logbuch-ohne-pose/
├── README.md              ← Haupt-Übersicht (Serie, Philosophie, Links)
├── LICENSE                ← Multi-Lizenz (MIT, CC BY-SA, Copyright)
├── .gitignore             ← Git Ignore-Regeln
│
├── band-2-strom/          ← Band 2: Strom ist nie einfach
├── band-x-monitoring/     ← Band X: Boot-Digitalisierung
└── ressourcen/            ← Gemeinsame Ressourcen
```

---

## 📖 Band 2: Strom ist nie einfach

```
band-2-strom/
├── README.md                           ← Band-Übersicht
│
├── kapitel/                            ← Buch-Kapitel (Markdown)
│   ├── 01-erwartungen-vs-realitaet.md  ✅
│   ├── 02-verbrauch-im-detail.md       🔄 (in Arbeit)
│   ├── 03-solar-hoffnung-grenzen.md    ✅
│   ├── 04-lichtmaschine-dc-dc.md       🔄 (in Arbeit)
│   ├── 05-fehlannahmen-katastrophen.md ✅
│   ├── 06-improvisieren.md             ✅
│   ├── 07-messen-statt-raten.md        ✅ NEU!
│   └── 08-system-lernt-mit.md          ✅ NEU!
│
├── berechnungen/                       ← Tools & Scripts
│   ├── verbrauch-rechner.xlsx          📊 (folgt)
│   ├── solar-dimensionierung.py        🐍 (folgt)
│   └── beispiele/                      📝 (folgt)
│       ├── wochenende-trip.md
│       ├── sommer-liegeplatz.md
│       └── winter-dauerlader.md
│
├── messungen/                          ← Echte Daten
│   ├── README.md                       📋 (folgt)
│   ├── verbrauch-oktober-2024.csv      📊 (folgt)
│   ├── solar-ertrag-sommer.csv         📊 (folgt)
│   ├── solar-ertrag-winter.csv         📊 (folgt)
│   └── akku-kurven/                    📈 (folgt)
│
└── fotos/                              ← Bilder
    ├── setup/                          📸 (folgt)
    ├── display-screenshots/            📸 (folgt)
    └── weather-correlation/            📸 (folgt)
```

---

## 🔧 Band X: Boot-Digitalisierung

```
band-x-monitoring/
├── README.md                           ← Projekt-Übersicht
│
├── hardware/                           ← Hardware-Design
│   ├── bom.md                          ✅ Stückliste mit Preisen
│   ├── schaltplaene/                   📐
│   │   ├── power_board.html            ✅ (vorhanden)
│   │   ├── sensor_board.html           ✅ (vorhanden)
│   │   └── main_board.html             ✅ (vorhanden)
│   └── stl-files/                      🖨️
│       ├── gehaeuse-3-faecher.stl      🔄 (in Arbeit)
│       └── README.md                   📋 (folgt)
│
├── firmware/                           ← Arduino Code
│   ├── ESP32_BootMonitor.ino           ✅ (vorhanden)
│   ├── ESP32_BootMonitor_TEST.ino      ✅ (vorhanden)
│   ├── libraries.txt                   📋 (folgt)
│   └── README.md                       ✅ (folgt)
│
├── mqtt/                               ← MQTT Konfiguration
│   ├── topic-structure.md              ✅ Vollständige Topic-Doku
│   └── mosquitto-config/               ⚙️ (folgt)
│       └── mosquitto.conf
│
├── dashboard/                          ← BoatOS/Node-RED
│   ├── screenshots/                    📸 (folgt)
│   ├── widgets/                        🎨 (folgt)
│   └── node-red-flows.json             🔄 (folgt)
│
├── kalibrierung/                       ← VDO Kennlinien
│   └── vdo-kennlinien.md               📊 (folgt)
│
└── docs/                               ← Dokumentation
    ├── installation.md                 ✅ Kompletter Install-Guide
    ├── troubleshooting.md              ✅ Problem-Lösungen
    └── erweiterungen.md                🔄 (folgt)
```

---

## 🛠️ Ressourcen (gemeinsam genutzt)

```
ressourcen/
├── templates/                          📝 (folgt)
│   ├── kapitel-vorlage.md
│   └── doku-vorlage.md
│
├── tools/                              🔧 (folgt)
│   ├── mqtt-test.sh
│   └── csv-konverter.py
│
└── links.md                            🔗 (folgt)
    ├── Bootsbesitzer-Communities
    ├── Marine-Elektronik Shops
    └── Hilfreiche Blogs
```

---

## ✅ Status-Übersicht

### **Band 2: Strom ist nie einfach**
- Kapitel: **6/8 fertig** (75%)
- Berechnungen: **0% fertig**
- Messungen: **0% fertig**
- Fotos: **0% fertig**
- **Gesamt: ~40% fertig**

### **Band X: Boot-Digitalisierung**
- Hardware: **100% fertig** ✅
- Firmware: **100% fertig** ✅
- Dokumentation: **80% fertig** ✅
- Installation: **100% fertig** ✅
- 3D-Gehäuse: **20% fertig** 🔄
- Boot-Test: **Läuft!** ✅
- **Gesamt: ~85% fertig**

---

## 📝 Nächste Schritte

### **Kurzfristig (diese Woche):**
- [ ] 3D-Gehäuse fertig drucken
- [ ] Gehäuse-Fotos machen
- [ ] Silikon-Verguss dokumentieren
- [ ] Node-RED Flow exportieren

### **Mittelfristig (nächste Wochen):**
- [ ] Boot-Installation Fotos
- [ ] Kalibrierung VDO Sensoren
- [ ] Band 2 Kapitel 2 & 4 schreiben
- [ ] Verbrauchs-Messdaten sammeln

### **Langfristig (nächste Monate):**
- [ ] Band 2 fertigstellen
- [ ] Band X Buch schreiben
- [ ] Erweiterungs-Module (Heizung, Bilge)
- [ ] Video-Tutorials (optional)

---

## 🔄 Git Workflow

### **Branches:**
```
main                # Stabile Version
├── dev-band-2      # Band 2 Entwicklung
└── dev-monitoring  # Monitoring Entwicklung
```

### **Commits:**
```
Konvention: [TYPE] Kurzbeschreibung

Typen:
- [DOC]  Dokumentation
- [CODE] Software
- [HW]   Hardware
- [FIX]  Bugfix
- [ADD]  Neue Datei

Beispiele:
[DOC] Kapitel 7 hinzugefügt
[CODE] Watchdog-Fix für Bootloop
[HW] 3D-Gehäuse STL hinzugefügt
```

---

## 📊 Dateigrößen (geschätzt)

```
Total Repository:
├── Dokumentation (MD):    ~5 MB
├── Code (INO):            ~0.5 MB
├── Schaltpläne (HTML):    ~2 MB
├── 3D-Modelle (STL):      ~5 MB
├── Fotos (JPG):           ~50 MB (optional)
├── Messdaten (CSV):       ~10 MB (optional)
└── Gesamt:                ~20-75 MB
```

**Tipp:** Große Binärdateien (Videos, RAW-Fotos) nicht ins Repo!

---

## 🔗 Externe Links

**GitHub Pages (optional):**
```
https://[username].github.io/logbuch-ohne-pose/

Automatisch generierte Website aus dem Repo
Mit schöner Darstellung der Markdown-Dateien
```

**Amazon KDP (bei Veröffentlichung):**
```
Band 2: amazon.de/... (folgt)
Band X: amazon.de/... (folgt)
```

---

## 🤝 Contribution Guidelines

**Mitmachen erwünscht!**

1. Fork das Repo
2. Branch erstellen: `git checkout -b feature/meine-erweiterung`
3. Änderungen committen: `git commit -m '[ADD] Meine Änderung'`
4. Push zum Fork: `git push origin feature/meine-erweiterung`
5. Pull Request öffnen

**Was wir suchen:**
- Verbesserungen an Schaltplänen
- Zusätzliche Berechnungs-Scripts
- Übersetzungen (EN)
- Eigene Mess-Daten
- Erweiterungs-Module

---

## 📄 Lizenz-Zusammenfassung

| Inhalt | Lizenz | Verwendung |
|--------|--------|------------|
| Code (INO, PY) | MIT | Frei verwendbar |
| Hardware (Schaltpläne) | CC BY-SA 4.0 | Mit Namensnennung |
| Dokumentation | CC BY-SA 4.0 | Mit Namensnennung |
| Kapitel (Buch) | Copyright | Nur Vorschau |
| Messdaten (CSV) | CC0 | Public Domain |

---

**Letzte Aktualisierung:** Januar 2025  
**Maintainer:** [Dein Name]  
**Kontakt:** [Deine Email]

*"Open Source bedeutet: Teilen was funktioniert, dokumentieren was schief ging."*
