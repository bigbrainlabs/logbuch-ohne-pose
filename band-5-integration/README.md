# Band 5: BoatOS – Das System

**Navigation, Dashboard und das automatische Logbuch**

> *"Das Logbuch ist das Highlight. Alles automatisch. Kein Papier. Keine Ausreden."*

---

## 📖 Übersicht

Band 5 beschreibt die Entwicklung von BoatOS – von der ersten Karte bis zum fertigen System mit Navigation, Dashboard, Sensoren und dem automatischen Logbuch.

**Status:** 📋 Outline fertig  
**Geplant:** Q3 2026  
**Umfang:** ~15.000-20.000 Wörter (8 Kapitel)

---

## 🎯 Die Story

```
Navigation → Frontend → Dashboard → Logbuch → Backend → Sensoren → Praxistest → Zukunft
```

- Kapitel 1-3: Die Oberfläche (Navigation, Frontend, Dashboard)
- Kapitel 4: **Das Logbuch – DAS HIGHLIGHT!**
- Kapitel 5-6: Das Innenleben (Backend, MQTT, Sensoren)
- Kapitel 7-8: Praxis & Zukunft

---

## 📑 Kapitelstruktur

### Kapitel 1: Die Navigation
*Von Online zu Offline*

- Erste Version: Online-Karten (OpenSeaMap)
- Das Problem: Funklöcher
- Viele Funklöcher
- Die Navigation stottert, hängt, stirbt
- Die Lösung: Offline-Karten
- Tile-Server selbst hosten
- Karten vorher runterladen
- Routing auch offline
- Ergebnis: Läuft. Immer. Überall.

**Ton:** Problem → Lösung

---

### Kapitel 2: Das Frontend
*React, TypeScript und warum*

- Warum React? (Komponenten, State, Community)
- Warum TypeScript? (Fehler früh finden)
- Warum Tailwind? (Schnelles Styling)
- Die Architektur:
  - Navigation als Komponente
  - Dashboard als Komponente
  - Widgets als Komponenten
  - **Logbuch als Komponente**
- Mobile-First: Tablet ist das Hauptgerät
- Dark Mode: Nachts am Steuerstand
- Code-Beispiele (vereinfacht)

**Ton:** Technisch, aber verständlich

---

### Kapitel 3: Das Dashboard
*Eigene Widgets statt starrer Layouts*

- Warum nicht Home Assistant?
  - Zu starr
  - Zu zickig beim Einbetten
  - Nicht das was ich brauche
- Eigene Widgets entwickeln:
  - Batterie-Gauge
  - Tank-Balken
  - RPM-Anzeige
  - Temperatur
  - GPS-Info (Speed, Course)
- Layout: Flexibel, anpassbar
- Drag & Drop? Vielleicht später
- Screenshots vom echten System

**Ton:** Design-Entscheidungen, Stolz

---

### Kapitel 4: Das Logbuch – Das Highlight
*Alles automatisch mitloggen*

- Das Feature worauf alles hinarbeitet
- Was geloggt wird:
  - Position (GPS)
  - Geschwindigkeit, Kurs
  - Batterien (beide!)
  - Tank
  - Motor (Temp, Öl, RPM)
  - Neigung (Pitch, Roll)
  - Wetter? (optional, später)
- Wann geloggt wird:
  - Automatisch bei Fahrt
  - Intervall einstellbar
  - Bei Events (Motor an/aus, Tank unter X%)
- Was rauskommt:
  - Tagesübersicht
  - Fahrtstatistiken
  - Verbrauchsberechnung
  - Track auf Karte
  - Export (CSV, GPX)
- Das papierlose Logbuch
- "Logbuch ohne Pose" – endlich wirklich digital!

**Ton:** Begeisterung, Das Highlight!

---

### Kapitel 5: Das Backend
*Python, FastAPI und die API*

- Warum Python? (Kann ich, mag ich)
- FastAPI: Modern, schnell, dokumentiert
- Die API-Endpunkte:
  - /api/gps – Position, Speed, Course
  - /api/sensors – Alle Sensordaten
  - /api/logbook – Logbuch-Einträge
  - /api/status – Systemstatus
- WebSocket für Live-Updates
- GPSd-Integration
- MQTT-Bridge für ESP32-Sensoren
- Datenbank: SQLite reicht (erstmal)
- Deployment: Systemd Service

**Ton:** Architektur, Entscheidungen

---

### Kapitel 6: MQTT & Sensoren
*Die Daten fließen – ins Dashboard UND ins Logbuch*

- MQTT: Publish/Subscribe erklärt
- Mosquitto als Broker
- Die ESP32s aus Band 3:
  - 8 Sensoren liefern Daten
  - Topics: boot/sensoren/*
- Im Dashboard anzeigen:
  - MQTT → WebSocket → React State → Widget
- **Ins Logbuch schreiben:**
  - MQTT → Backend → Datenbank → Logbuch
- Live-Updates ohne Polling
- Alarme bei kritischen Werten
- SignalK-Kompatibilität (für später)

**Ton:** Integration, Zusammenführung

---

### Kapitel 7: Praxistest Saisonstart 2026
*Endlich auf dem Wasser – funktioniert es?*

- Installation am Steuerstand
- Stromversorgung: 12V → 5V, 3A (Pi 4 ist genügsam!)
- Erste Fahrt mit BoatOS
- Die Checkliste:
  - Navigation: ✅ ?
  - GPS: ✅ ?
  - Offline-Karten: ✅ ?
  - Dashboard: ✅ ?
  - Sensoren: ✅ ?
  - **Logbuch: ✅ ?** (Die Hoffnung!)
- Echte Erfahrungen vom Wasser
- Was funktioniert, was nicht
- Die Hoffnung: Dass Navi und Logbuch endlich richtig laufen

**Ton:** Ehrlich, Spannung, Praxis

---

### Kapitel 8: v1 Final & Zukunft
*Was kommt noch*

- Was v1 kann:
  - ✅ Navigation (offline!)
  - ✅ Dashboard (eigene Widgets)
  - ✅ Sensoren (8× ESP32)
  - ✅ GPS (Position, Speed, Course)
  - ✅ Logbuch (automatisch!)
- Was noch geplant ist:
  - Heizungssteuerung (Webasto – die ursprüngliche HA-Idee!)
  - AIS-Integration
  - Mehr Widgets
  - Mobile-App
- Open Source: Die Entscheidung
- GitHub: Der Code ist da
- Einladung: Mach mit!
- Epilog: Ein Jahr später... (v2.4?)

**Ton:** Abschluss, Stolz, Einladung

---

## 🛠️ Technologie-Stack

### Frontend
```
- React 18
- TypeScript
- Tailwind CSS
- Leaflet (Karten)
- WebSocket (Live-Updates)
```

### Backend
```
- Python 3.11
- FastAPI
- SQLite (Datenbank)
- GPSd (GPS)
- Mosquitto (MQTT)
```

### Hardware
```
- Raspberry Pi 4 (4GB)
- 10" Touch-Display
- USB GPS-Modul
- 8× ESP32 (aus Band 3)
```

---

## 📊 Das Logbuch – Details

### Was wird geloggt?

| Datenquelle | Werte | Intervall |
|-------------|-------|-----------|
| GPS | Position, Speed, Course | 1s |
| Batterie 1 | Spannung | 5s |
| Batterie 2 | Spannung | 5s |
| Tank | Füllstand % | 10s |
| Motor Temp | °C | 5s |
| Motor RPM | U/min | 1s |
| Öldruck | bar | 5s |
| Pitch/Roll | ° | 5s |

### Was kommt raus?

- 📊 Tagesübersicht
- 📈 Fahrtstatistiken
- ⛽ Verbrauchsberechnung
- 🗺️ Track auf Karte
- 📁 Export (CSV, GPX)

---

## 🔗 Verbindungen

**Vorher:** Band 4 (Die Reise zum Bordcomputer) – Die Entscheidung für BoatOS

**Danach:** Band 6 (Die Ventil-Heizung) – Spezial-Projekt

**Verbunden mit:** Band 3 (Sensoren & Monitoring) – Die ESP32-Daten fließen hierher

---

## 📝 Notizen

- Das Logbuch ist DAS Feature – zentral in Kapitel 4
- Offline-Karten wegen Funklöcher = echter Pain Point
- Praxistest Saisonstart 2026 = Spannungsbogen
- "Funktioniert es endlich?" als roter Faden
- v2.4 nur im Epilog erwähnen (Zukunft)
- Heizungssteuerung als "kommt noch" (aus Band 4 HA-Umweg)

---

## 📜 Lizenz

- **Buch-Inhalte:** Copyright
- **Code-Snippets:** MIT License

---

## 🔗 Links

- **BoatOS Code:** [github.com/bigbrainlabs/BoatOS](https://github.com/bigbrainlabs/BoatOS)
- **Band 3 (Sensoren):** Prerequisite für ESP32-Integration
- **Band 4 (Fundament):** Die Vorgeschichte

---

*"Das Logbuch ohne Pose – jetzt wirklich ohne Papier."*
