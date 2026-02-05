# Band 2: Strom ist nie einfach

**Solar, Batterien und die Realität der Autarkie**

> *280 Ah Akku. 260 Wp Solar. Das sollte reichen.*  
> *Spoiler: Kommt drauf an.*

---

**📖 Hinweis:** Alle Kapitel sind hier **vollständig und kostenlos lesbar**. Das Buch (Februar 2026) bietet editierte Version, Fotos und bequemes Format. [Mehr dazu](#-das-vollständige-buch)

---

## 📖 Über dieses Buch

Dies ist kein technisches Handbuch.  
Keine Tabellen mit Idealwerten.  
Keine Versprechen, dass "mit diesem einen Trick" alles perfekt wird.

Das ist ein ehrliches Logbuch über Strom auf einem Boot.  
Mit echten Zahlen vom echten Boot.  
Mit Erwartungen, die korrigiert wurden.  
Mit Lösungen, die manchmal improvisiert sind.

**Kurz:** Realität statt Prospekt.

---

## 📚 Kapitel-Übersicht

### ✅ Kapitel 1: Erwartungen vs. Realität
*In dem ich lerne, dass 280 Ah nicht bedeuten "nie wieder Landstrom"*

- 3.580 Wh theoretisch vs. praktisch
- Die Halbwertszeit von Optimismus
- Warum "sollte reichen" oft nicht reicht
- Display-Starren als neue Gewohnheit

### ✅ Kapitel 2: Die Verbraucher-Inventur
*In dem ich feststelle, dass "nur 2 Ampere" keine Kleinigkeit ist*

- Der Kühlschrank: 300 Wh/Tag für kaltes Bier
- Licht, Radio, TV – die "kleinen" Sünden
- Standby-Vampire und der Dauerstrom (1,5-2 A)
- Die Rechnung: 1.000 Wh/Tag kommen schneller zusammen als gedacht
- Bewusster verbrauchen statt verzichten

### ✅ Kapitel 3: Solar – Hoffnung & Grenzen
*In dem die Sonne sich nicht an Datenblätter hält*

- 1.200 Wh im Juli vs. 200 Wh im Dezember
- Warum flache Paneele im Winter Urlaub haben
- Solar ist kein Stromvertrag
- Wettervorhersagen als neue Religion

### ✅ Kapitel 4: Laden ohne Sonne
*In dem Fahren zur Ladestation wird*

- Landstrom: Der einfache Weg (20A Ladegerät, 6 Stunden bis voll)
- Die Lichtmaschine: Der Fahr-Weg (2-8 Stunden, Akku voller als vorher)
- Das Zusammenspiel: Solar + Fahren + Landstrom
- Man fährt nicht zum Laden – man lädt beim Fahren

### ✅ Kapitel 5: Fehlannahmen & kleine Katastrophen
*In dem ich lerne, dass Excel die Physik nicht überzeugt*

- Großer Akku ≠ Autarkie (nur Puffer)
- Solar deckt den Verbrauch (manchmal)
- Kleinigkeiten fallen nicht ins Gewicht (tun sie doch)
- Man merkt wenn der Akku leer wird (merkt man nicht)

### ✅ Kapitel 6: Improvisieren, ohne zu planen
*In dem ich aufhöre perfekt zu sein und anfange praktisch zu sein*

- Zweiter Akku? (Idee für später)
- Wasserkocher bei 12V? (Gas ist schneller)
- Faltbares Panel (200 Wp Raumfahrt-Gefühl) – geplant!
- Weniger Verbrauch (bewusster, nicht Verzicht)
- Fahren als Ladestation (mobiles Kraftwerk)

### ✅ Kapitel 7: Messen statt Raten
*In dem ich aufhöre zu schätzen und anfange zu wissen*

- Display zeigt 12,4 V (hilft nicht wirklich)
- ESP32 + Sensoren (echte Zahlen statt Bauchgefühl)
- Verbrauch in Wh statt "gefühlt zu viel"
- Aha-Momente beim Ablesen
- I2C-Scanner rettet den Tag

### ✅ Kapitel 8: Das System lernt mit
*In dem alles zusammenkommt und ich endlich durchblicke*

- MQTT + BoatOS Dashboard
- Solar-Ertrag live (nicht geschätzt)
- Verbrauch live (jeder Verbraucher einzeln)
- Batterie-SOC mit Prognose
- Autarkie – jetzt mit Daten

---

## 🎯 Was du lernst

**Praktisches Wissen:**
- Realistische Verbrauchsanalyse (nicht Datenblatt-Theorie)
- Solar-Dimensionierung (mit Wetter-Faktor)
- Batterie-Management (LiFePO₄ Alltag)
- Improvisation & Anpassung
- Monitoring mit ESP32

**Ehrliche Einsichten:**
- Warum Werbeprospekte optimistisch sind
- Dass Winter und Solar keine Freunde sind
- Wie man mit weniger auskommt (ohne zu leiden)
- Dass Messen besser ist als Raten
- Warum "autark" nicht "perfekt" bedeutet

**Keine Lösungen für:**
- Unbegrenzte Energie aus dem Nichts
- Solar-Anlagen die im Winter wie im Sommer funktionieren
- Akkus die sich selbst aufladen
- Physik-Tricks die die Realität überlisten

---

## 📊 Die harten Fakten

**Das Boot:**
- Motorboot, Liegeplatz mit Landstrom
- Regelmäßige Nutzung (Wochenenden + Urlaub)
- Deutschland (= viel Grau, wenig Sonne)

**Das System:**
- 280 Ah LiFePO₄ (3.580 Wh nutzbar)
- 260 Wp Solar (fest)
- DC-DC-Lader (von Lichtmaschine)
- 20A Ladegerät (für Landstrom)
- ESP32 Monitoring mit MQTT

**Geplant:**
- Faltbares Panel 200 Wp (für Winter-Boost)

**Der Verbrauch:**
- Kühlschrank: ~300 Wh/Tag
- Kleinverbraucher: ~700 Wh/Tag
- Gesamt: ~1.000 Wh/Tag

**Die Realität:**
- Sommer: Solar deckt alles + lädt Akku
- Winter: Solar hilft, reicht nicht
- Lösung: Fahren + weniger Verbrauch (+ faltbares Panel geplant)

---

## 📁 Repository-Inhalte

```
band-2-strom/
├── kapitel/                    # Buch-Inhalte (Markdown)
│   ├── 01-erwartungen-vs-realitaet.md
│   ├── 02-die-verbraucher-inventur.md
│   ├── 03-solar-hoffnung-grenzen.md
│   ├── 04-laden-ohne-sonne.md
│   ├── 05-fehlannahmen-katastrophen.md
│   ├── 06-improvisieren.md
│   ├── 07-messen-statt-raten.md
│   └── 08-system-lernt-mit.md
│
├── berechnungen/              # Tools & Scripts
│   ├── verbrauch-rechner.xlsx
│   ├── solar-dimensionierung.py
│   └── beispiele/
│       ├── wochenende-trip.md
│       ├── sommer-liegeplatz.md
│       └── winter-dauerlader.md
│
├── messungen/                 # Echte Daten vom Boot
│   ├── verbrauch-oktober-2024.csv
│   ├── solar-ertrag-sommer.csv
│   ├── solar-ertrag-winter.csv
│   └── akku-kurven/
│
└── fotos/
    ├── setup/
    ├── display-screenshots/
    └── weather-correlation/
```

---

## 🔗 Verbindung zu Band 3 (Sensoren & Monitoring)

**Kapitel 7 & 8 dieses Bands** dokumentieren den Übergang von "ich schätze mal" zu "ich weiß es genau".

Das Monitoring-System aus **Band 3** ist die technische Umsetzung davon:
- ESP32 mit Sensoren
- MQTT Datenfluss
- BoatOS Dashboard
- Live-Messung statt Schätzung

**Die Projekte bauen aufeinander auf:**

```
Band 2 (Strom):           Band 3 (Monitoring):
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem beschrieben   →   Lösung gebaut
Verbrauch geschätzt   →   Verbrauch gemessen
Solar geraten        →   Solar erfasst
Akku beobachtet      →   Akku überwacht
```

---

## 📖 Das vollständige Buch

**Hier auf GitHub: Alles lesbar. Kostenlos.**

Die **Kapitel sind vollständig** im Rohformat (Markdown) zum Lesen und Lernen.

**Das Buch bietet zusätzlich:**
- Vollständig editiert & lektoriert (keine Tippfehler, schöner Fluss)
- Hochwertige Fotos & Diagramme (Farbig!)
- Zusätzliche Berechnungsbeispiele
- Troubleshooting-Tipps & Anhänge
- Leserfreundliches Layout (Kindle/Print)
- **Offline am Boot lesbar** (kein Internet nötig!)

→ **Amazon KDP:** *(~7€ Kindle, ~12€ Print)* – Februar 2026

**Warum kaufen wenn's hier kostenlos ist?**

Weil:
1. Du das Projekt gut findest
2. Weitere Bände unterstützen willst
3. Lieber bequem auf Kindle/Papier liest
4. "Danke" sagen möchtest

**Aber:** Wenn GitHub reicht → alles gut! Hauptsache du lernst was! 😊

---

## 🤝 Beitragen

**Du hast ähnliche Erfahrungen?**  
→ Teile deine Daten! (anonymisiert als CSV)

**Du hast andere Lösungen gefunden?**  
→ Pull Request mit deinem Ansatz!

**Du hast Fehler gefunden?**  
→ Issues sind willkommen!

---

## 📄 Lizenz

**Buch-Inhalte (Kapitel):** © Copyright  
→ Nur zur Vorschau, nicht zur kommerziellen Nutzung

**Berechnungs-Scripts:** MIT License  
→ Frei verwendbar

**Daten & Messungen:** CC0 (Public Domain)  
→ Nutze sie wie du willst

---

**Status:** ✅ 8/8 Kapitel fertig | Veröffentlichung: Februar 2026

*"Autarkie ist kein Ziel. Autarkie ist ein Kompromiss zwischen Wunsch und Wetter."*
