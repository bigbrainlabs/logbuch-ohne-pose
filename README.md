# Logbuch ohne Pose

**Authentische DIY-Projekte rund ums Boot – ohne Schönfärberei**

> *"Keine perfekten Tutorials, sondern echte Lernreisen mit allen Höhen, Tiefen, Fehlern und Aha-Momenten."*

Diese Repository-Serie dokumentiert praktische Boot-Projekte mit der ehrlichen Perspektive eines Bootseigentümers, der selbst Hand anlegt – inklusive aller Umwege, Fehleinschätzungen und improvisierten Lösungen.

---

## 📚 Die Buchreihe

### Band 2: Strom ist nie einfach
**Solar, Batterien und die Realität der Autarkie**

*Status: 📝 In Arbeit (6/8 Kapitel fertig)*

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

**Themen:**
- Verbrauchsanalyse (mit echten Daten, nicht mit Prospekten)
- Solar-Dimensionierung (Hoffnung vs. Realität)
- Batterie-Management (LiFePO₄ im Alltag)
- Praktische Lösungen (faltbare Panels, Gas, Routine)
- Monitoring mit ESP32 (weil Raten nicht reicht)

---

### Band X: Boot-Digitalisierung
**Von analogen VDO-Instrumenten zu MQTT & BoatOS**

*Status: ⚙️ Hardware läuft, Software stabil, Buch in Planung*

Drei handgelötete Platinen. Ein ESP32. Acht Sensoren.  
Und die Frage: Warum zeigt der I2C-Scanner nur ein Gerät statt drei?

**Was entsteht:**
- 8-Kanal Sensor-System (Batterien, Tank, Temp, Öl, RPM, Pitch, Roll)
- MQTT-basierte Datenübertragung zum Raspberry Pi
- BoatOS Dashboard mit Live-Widgets
- SignalK Kompatibilität
- VDO Instrumente bleiben als mechanisches Backup

[→ Zum Projekt](band-x-monitoring/)

**Themen:**
- ESP32 + ADS1115 + MPU6050 (I2C Debugging inklusive)
- MQTT ohne Hardcoding (Captive Portal für WiFi + MQTT Config)
- Mixed Mode Testing (Fake-Daten + echter MPU6050)
- VDO Sensor-Kennlinien (von Widerstand zu Litern)
- Marine-Elektronik Basics (Spannungsteiler, Pull-ups, Bootsmasse)
- Silikon-Verguss & 3D-Druck Gehäuse

---

## 🎯 Philosophie

**"Logbuch ohne Pose" bedeutet:**

✅ **Fehler werden gezeigt** – nicht versteckt  
✅ **Trial & Error** dokumentiert – mit allen Rückschlägen  
✅ **Authentische Zeitangaben** – "drei Tage gebastelt" statt "kurze Einrichtung"  
✅ **Realistische Kosten** – keine versteckten Ausgaben  
✅ **Improvisationen** – weil nicht alles nach Plan läuft  
✅ **Lernkurven** – vom "sollte funktionieren" zum "funktioniert tatsächlich"

**Was du NICHT findest:**
❌ Perfekte Lösungen beim ersten Versuch  
❌ "Einfach und schnell" wenn es kompliziert war  
❌ Werbeprospekt-Optimismus  
❌ Verschweigen von Problemen

---

## 🛠️ Technologie-Stack (Band X - Monitoring)

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
- BoatOS Dashboard (Node-RED / React)
- SignalK Server (optional)

**Prinzipien:**
- Open Source (MIT License)
- Dokumentiert (Schaltpläne + Code)
- Nachbaubar (Stückliste + Anleitung)
- Erweiterbar (modular aufgebaut)

---

## 📖 Für wen ist das?

**Bootsbesitzer die:**
- Selbst Hand anlegen wollen (statt Werft-Preise zu zahlen)
- Technik-interessiert sind (aber keine Ingenieure sein müssen)
- Authentische Erfahrungen schätzen (statt Marketing-Texte)
- Mit Trial & Error klarkommen (und draus lernen wollen)
- Realistische Zeit- und Kosteneinschätzungen suchen

**Du bist hier richtig wenn:**
- "Sollte reichen" dir nicht reicht
- Du wissen willst WAS auf deinem Boot passiert
- Dich NMEA2000 Preise abschrecken
- Du gerne bastelst (und auch mal fluchst)
- "Open Source" keine Fremdsprache ist

---

## 🤝 Community & Beitragen

**Eigene Erfahrungen? Verbesserungen? Fehler gefunden?**

→ **Issues** für Bugs, Fragen, Diskussionen  
→ **Pull Requests** für Code-Verbesserungen, Korrekturen  
→ **Discussions** für Projekt-Vorstellungen, Ideen

**Du hast das Projekt nachgebaut?**  
→ Zeig's uns! Fotos, Anpassungen, Learnings  
→ Issues mit "Show & Tell" Label

**Du hast eine Erweiterung gebaut?**  
→ Heizungssteuerung? Bilgepumpen-Monitoring? Ankerwacht?  
→ Pull Request mit deinem Projekt!

---

## 📦 Repository-Struktur

```
logbuch-ohne-pose/
├── band-2-strom/              # Solar, Batterien, Energie
│   ├── kapitel/              # Buch-Inhalte (Markdown)
│   ├── berechnungen/         # Excel, Python Scripts
│   ├── messungen/            # Echte Daten vom Boot
│   └── fotos/
│
├── band-x-monitoring/         # ESP32 Sensor-System
│   ├── hardware/             # Schaltpläne, STL-Files, BOM
│   ├── firmware/             # Arduino Code
│   ├── mqtt/                 # Topic-Struktur, Config
│   ├── dashboard/            # BoatOS Integration
│   └── docs/                 # Installation, Troubleshooting
│
└── ressourcen/               # Gemeinsam genutzte Tools
```

---

## 📄 Lizenz

**Hardware & Schematics:** CC BY-SA 4.0  
→ Frei nutzbar, veränderbar, teilbar (mit Namensnennung)

**Software:** MIT License  
→ Sehr permissive, auch kommerzielle Nutzung OK

**Dokumentation & Texte:** CC BY-SA 4.0  
→ Teilen und anpassen erlaubt

**Buch-Inhalte:** © Copyright (nur zur Vorschau im Repo)

---

## 📚 Bücher kaufen

Die vollständigen Bücher mit allen Kapiteln, Fotos, Diagrammen und Hintergrund-Infos:

→ **Band 2: Strom ist nie einfach** – [Amazon KDP](#) *(folgt)*  
→ **Band X: Boot-Digitalisierung** – [Amazon KDP](#) *(in Planung)*

**Warum kaufen wenn's auf GitHub ist?**
- Vollständig editiert & lektoriert
- Hochwertige Fotos & Diagramme
- Zusätzliche Hintergrund-Infos
- Unterstützt weitere Projekte
- Schön formatiert zum Lesen (nicht nur Code)

---

## 🔗 Links & Ressourcen

**Bootsspezifisch:**
- [SignalK](https://signalk.org/) – Open Source Marine Data Standard
- [BoatOS](https://github.com/your-boatos-link) – Dashboard für Bootsdaten
- [OpenCPN](https://opencpn.org/) – Navigation Software

**Hardware:**
- [ADS1115 Datasheet](https://www.ti.com/product/ADS1115)
- [MPU6050 Datasheet](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/)
- [ESP32 Documentation](https://docs.espressif.com/)

**Community:**
- [Cruisers Forum](https://www.cruisersforum.com/) – DIY Marine Electronics
- [Reddit r/boatbuilding](https://reddit.com/r/boatbuilding)

---

## ⚓ Status & Roadmap

**Aktuell:**
- ✅ Band 2 (Strom): 6/8 Kapitel geschrieben
- ✅ Monitoring Hardware: Funktioniert, im Einsatz
- ✅ Monitoring Software: Stabil, OTA-Updates laufen
- 🔄 3D-Gehäuse: In Planung
- 🔄 Boot-Installation: Vorbereitung läuft

**Nächste Schritte:**
- Band 2 Kapitel 7 & 8 fertigstellen
- Monitoring auf Boot installieren (mit echten VDO Sensoren)
- Kalibrierung & Feintuning
- Fotos & Dokumentation vervollständigen
- Buch-Veröffentlichung vorbereiten

**Geplant:**
- Band 3: Weitere Boot-Projekte
- Erweiterungs-Module (Heizung, Bilgepumpen, etc.)
- Community-Beiträge integrieren

---

## 💬 Kontakt & Feedback

**Fragen? Anregungen? Probleme?**

→ [GitHub Issues](../../issues) – Für technische Fragen  
→ [GitHub Discussions](../../discussions) – Für allgemeine Diskussionen  
→ Email: *[deine-email@example.com]* – Für direkten Kontakt

**Folgen & Updates:**
- GitHub: Star & Watch dieses Repo
- *[Optional: Blog, YouTube, etc.]*

---

## ⭐ Support / Buch kaufen

**Hier ist alles. Wenn's dir hilft, kauf das Buch. Wenn nicht, auch OK.** 🤷‍♂️

Alle Inhalte sind frei verfügbar auf GitHub. Die Bücher gibt's für die, die:
- ✅ Das Projekt gut finden und danke sagen wollen
- ✅ Lieber auf Kindle/gedruckt lesen (am Boot kein Internet!)
- ✅ Schön editiert & lektoriert haben wollen
- ✅ Weitere Projekte unterstützen möchten

**Die Bücher:**
→ **Band 2: Strom ist nie einfach** – [Amazon KDP](#) *(~7€ Kindle, ~12€ Print)* – folgt 2025  
→ **Band X: Boot-Digitalisierung** – [Amazon KDP](#) *(~7€ Kindle, ~12€ Print)* – in Planung

**Andere Wege zu helfen:**
→ ⭐ **Star** auf GitHub – Hilft anderen es zu finden  
→ 🔀 **Fork & Erweitern** – Bau deine eigene Version  
→ 💬 **Teilen** – Erzähl anderen davon  
→ 🐛 **Issues melden** – Fehler gefunden? Sag Bescheid!

---

**Made with ⚓ and many ☕**

*"Hier ist alles. Open Source heißt: Du darfst damit machen was du willst. Auch nichts kaufen. Auch das ist OK."*
