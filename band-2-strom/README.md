# Band 2: Strom ist nie einfach

**Solar, Batterien und die Realität der Autarkie**

> *280 Ah Akku. 260 Wp Solar. Das sollte reichen.*  
> *Spoiler: Kommt drauf an.*

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

### 🔄 Kapitel 2: Der Verbrauch im Detail
*In dem ich feststelle, dass "nur 2 Ampere" keine Kleinigkeit ist*

*(in Arbeit)*

### ✅ Kapitel 3: Solar – Hoffnung & Grenzen
*In dem die Sonne sich nicht an Datenblätter hält*

- 1.200 Wh im Juli vs. 200 Wh im Dezember
- Warum flache Paneele im Winter Urlaub haben
- Solar ist kein Stromvertrag
- Wettervorhersagen als neue Religion

### 🔄 Kapitel 4: Lichtmaschine & DC-DC
*In dem Fahren zur Ladestation wird*

*(in Arbeit)*

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
- Faltbares Panel (200 Wp Raumfahrt-Gefühl)
- Weniger Verbrauch (bewusster, nicht Verzicht)
- Fahren als Ladestation (mobile Kraftwerk)

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
- 260 Wp Solar (fest + faltbar)
- 60A DC-DC-Lader (von Lichtmaschine)
- ESP32 Monitoring mit MQTT

**Der Verbrauch:**
- Kühlschrank: ~600 Wh/Tag
- Kleinverbraucher: ~400 Wh/Tag
- Gesamt: 1.000-1.200 Wh/Tag

**Die Realität:**
- Sommer: Solar deckt alles + lädt Akku
- Winter: Solar hilft, reicht nicht
- Lösung: Fahren + faltbares Panel + weniger Verbrauch

---

## 📁 Repository-Inhalte

```
band-2-strom/
├── kapitel/                    # Buch-Inhalte (Markdown)
│   ├── 01-erwartungen-vs-realitaet.md
│   ├── 03-solar-hoffnung-grenzen.md
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

## 🔗 Verbindung zu Band X (Monitoring)

**Kapitel 7 & 8 dieses Bands** dokumentieren den Übergang von "ich schätze mal" zu "ich weiß es genau".

Das Monitoring-System aus **Band X** ist die technische Umsetzung davon:
- ESP32 mit Sensoren
- MQTT Datenfluss
- BoatOS Dashboard
- Live-Messung statt Schätzung

**Die Projekte bauen aufeinander auf:**

```
Band 2 (Strom):           Band X (Monitoring):
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Problem beschrieben   →   Lösung gebaut
Verbrauch geschätzt   →   Verbrauch gemessen
Solar geraten        →   Solar erfasst
Akku beobachtet      →   Akku überwacht
```

---

## 📖 Das vollständige Buch

Die GitHub-Version enthält die **Kapitel im Rohformat** (Markdown) zum Nachvollziehen und Lernen.

**Das fertige Buch bietet:**
- Vollständig editiert & lektoriert
- Hochwertige Fotos & Diagramme
- Zusätzliche Berechnungsbeispiele
- Troubleshooting-Tipps
- Leserfreundliches Layout

→ **Amazon KDP:** *(folgt bei Veröffentlichung)*

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

**Status:** 📝 6/8 Kapitel fertig | Veröffentlichung: 2025 (geplant)

*"Autarkie ist kein Ziel. Autarkie ist ein Kompromiss zwischen Wunsch und Wetter."*
