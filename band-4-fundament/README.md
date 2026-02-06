# Band 4: Die Reise zum Bordcomputer

**Von der Stromzicke Pi 5 zur eigenen Vision**

> *"Der Pi 5 ist eine Diva. Auf dem Schreibtisch perfekt. Auf dem Boot? Zickenalarm."*

---

## 📖 Übersicht

Band 4 erzählt die Geschichte vom Wunsch nach einem Bordcomputer bis zur Entscheidung, BoatOS selbst zu entwickeln. Mit allen Umwegen, Fails und der Erkenntnis: Manchmal ist selbst machen einfacher.

**Status:** 📋 Outline fertig  
**Geplant:** Q2 2026  
**Umfang:** ~15.000-20.000 Wörter (8 Kapitel)

---

## 🎯 Die Story

```
Motivation → Pi 5 Fail → Software-Fails → Umwege → Durchbruch → Start
```

- Kapitel 1-2: Was ich will & erster Hardware-Fail
- Kapitel 3-5: Software-Versuche (alle gescheitert)
- Kapitel 6: Home Assistant (Umweg)
- Kapitel 7-8: BoatOS wird geboren

---

## 📑 Kapitelstruktur

### Kapitel 1: Der Wunsch
*Was ein Bordcomputer können sollte*

- Das Boot hat kein modernes Display
- Raymarine, Garmin, Simrad: Die Preise
  - 7-Zoll-Axiom: 800€
  - 9-Zoll: 1.400€
  - MFD: 2.300€+
- Die Wunschliste:
  - Navigation mit Karten
  - Geschwindigkeit, Position, Kurs
  - Sensordaten (Batterien, Tank, Motor)
  - Steuerung (Licht, Pumpen, später Heizung)
  - **Das Logbuch:** Alles automatisch mitloggen!
- Der Gedanke: "Raspberry Pi kann das doch auch?"

**Ton:** Motivation, Naivität, Optimismus

---

### Kapitel 2: Die Stromzicke
*Raspberry Pi 5 – zu eitel fürs Boot*

- 2024/2025: Pi 5 ist neu, Pi 5 ist schnell, Pi 5 muss her
- Die Bestellung: Voller Vorfreude
- Die Installation: Läuft... erstmal
- Dann die Probleme:
  - Stromversorgung: 5V/5A? Auf dem Boot?
  - USB-C Power Delivery: Zickig
  - Spannungsschwankungen: Pi 5 mag das nicht
  - Unterspannungs-Warnung: Dauergast
  - Abstürze: Regelmäßig
- Der Pi 5 ist eine Diva
- Auf dem Schreibtisch: Perfekt
- Auf dem Boot mit 12V-Wandler: Zickenalarm
- Die bittere Erkenntnis: Zurück zum Pi 4
- Pi 4: Robust, genügsam, bootstauglich

**Ton:** Vorfreude → Frust → Pragmatismus

---

### Kapitel 3: OpenCPN – Der Software-Versuch
*Kostenlos ist nicht immer günstig*

- OpenCPN: Die Open-Source-Hoffnung
- Installation auf dem Pi 4: Geht... irgendwie
- Die ersten Probleme:
  - UI wie aus den 90ern
  - Touch? Vergiss es
  - Plugins? Versionschaos
  - Karten? Kompliziert zu installieren
- "Das muss doch besser gehen"
- Trotzdem: Wochenlang probiert
- Am Ende: Aufgegeben

**Ton:** Hoffnung → Ernüchterung

---

### Kapitel 4: AvNav – Noch ein Versuch
*Speziell für Pi, speziell buggy*

- AvNav: "Speziell für Raspberry Pi!"
- Klingt perfekt. Ist es nicht.
- Die Probleme:
  - Installation: Okay
  - Konfiguration: Hölle
  - Bugs: Überall
  - Dokumentation: Deutsch, aber kryptisch
  - Community: Klein, wenig Support
- Wochenlang debugging
- Am Ende: Wieder aufgegeben

**Ton:** Déjà-vu, Frustration

---

### Kapitel 5: Die anderen Kandidaten
*Alle mit Dealbreaker*

- SignalK: Interessant, aber nur Backend
- Freeboard-SK: Schick, aber limitiert
- WilhelmSK: Nur iOS
- Navionics auf Tablet: Proprietär, keine Integration
- Die Erkenntnis: Jede Lösung hat einen Dealbreaker
- Die Frage: Warum ist das so schwer?

**Ton:** Systematische Suche, wachsende Verzweiflung

---

### Kapitel 6: Home Assistant – Der Umweg
*Eigentlich für die Heizung*

- Die Idee: Webasto-Heizung smart steuern
- Home Assistant: Das Smart-Home-System
- Installation: Endlich mal einfach!
- Erste Erfolge:
  - Sensoren einbinden: Check
  - Dashboard: Check
  - Automationen: Check
- Aber dann:
  - Layout: Starr, unflexibel
  - Einbetten: Zickig
  - Navigation: Fehlanzeige
- HA ist gut für Smart Home
- HA ist nicht gut als Bordcomputer
- Aber: Bleibt im Hinterkopf für Heizung später

**Ton:** Hoffnung → Teilerfolg → Limitation

---

### Kapitel 7: Die Geburt von BoatOS
*"Dann mach ich's halt selbst"*

- Der Moment der Erkenntnis
- Was ich brauche:
  - Karten (Leaflet + OpenSeaMap)
  - GPS-Anbindung (GPSd)
  - Dashboard (eigene Widgets)
  - MQTT (Sensoren)
  - **Logbuch!** (Das Highlight!)
  - Flexibilität (alles anpassbar)
- Was ich kann:
  - Bisschen Python
  - Bisschen JavaScript
  - Bisschen HTML/CSS
  - Viel Sturheit
- Was ich habe:
  - Claude als Entwicklungspartner
  - Einen Raspberry Pi 4 (die Stromzicke ist raus)
  - Zu viel Zeit
- Die Entscheidung: BoatOS wird geboren

**Ton:** Durchbruch, Entschlossenheit

---

### Kapitel 8: Der Startschuss
*Hardware, 10 Zoll und los*

- Die Hardware-Entscheidung:
  - Pi 4 (4GB) – robust, genügsam
  - 10" Display – die optimale Größe
  - Touch – muss sein
  - GPS USB – externe Antenne
- Die Einkaufsliste: ~200€
- Entwicklungsumgebung einrichten
- "Hallo Welt" auf dem Pi
- Erste Karte im Browser
- GPS-Position als Punkt
- Es funktioniert!
- Die Euphorie
- Ausblick auf Band 5

**Ton:** Anfang, Hoffnung, Vorfreude

---

## 🛠️ Hardware (am Ende von Band 4)

| Komponente | Entscheidung | Preis |
|------------|--------------|-------|
| Raspberry Pi 4 (4GB) | Robust, genügsam | 60€ |
| 10" Touch-Display | Optimale Größe | 80€ |
| USB GPS-Modul | Externe Antenne | 25€ |
| SD-Karte 32GB | Schnell, zuverlässig | 15€ |
| Kabel, Kleinkram | Diverses | 20€ |
| **Gesamt** | | **~200€** |

---

## 📊 Die Fail-Liste

| Versuch | Problem | Ergebnis |
|---------|---------|----------|
| Pi 5 | Stromzicke, Spannungsschwankungen | ❌ Zurück zu Pi 4 |
| OpenCPN | 90er-UX, Touch-Probleme, Plugins | ❌ Aufgegeben |
| AvNav | Buggy, schlechte Doku | ❌ Aufgegeben |
| SignalK | Nur Backend | ❌ Nicht ausreichend |
| Freeboard-SK | Limitiert | ❌ Nicht ausreichend |
| Home Assistant | Starr, zickig beim Einbetten | ⚠️ Nur für Heizung später |

---

## 🔗 Verbindungen

**Vorher:** Band 3 (Sensoren & Monitoring) – Die ESP32-Hardware steht

**Nachher:** Band 5 (BoatOS – Das System) – Die Entwicklung beginnt

---

## 📝 Notizen

- Pi 5 Fail = Erster echter Rückschlag, guter Story-Einstieg
- Home Assistant bleibt im Spiel für Heizungssteuerung später
- Das Logbuch wird schon in Kapitel 1 & 7 als Vision erwähnt
- Claude als Entwicklungspartner erwähnen (USP!)
- 10" Display war eine bewusste Entscheidung (nicht 7")

---

## 📜 Lizenz

- **Buch-Inhalte:** Copyright
- **Code-Snippets:** MIT License

---

*"Der direkte Weg wäre langweilig gewesen. Die Umwege haben BoatOS erst möglich gemacht."*
