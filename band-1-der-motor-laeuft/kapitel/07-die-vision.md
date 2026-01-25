# Band 1 – Kapitel 7: Die Vision

*Oder: "Ich bau das komplett neu"*

---

Mai.

Boot liegt am Steg.

LED leuchtet.

Voltmeter zeigt 12.4V.

Zwei erfolgreiche Projekte.

Klein.

Aber erfolgreich.

---

Ich sitze im Cockpit.

Notizblock auf dem Schoß.

Stift in der Hand.

Denke nach.

"Was als nächstes?"

---

Liste:

```
✅ LED-Beleuchtung
✅ Voltmeter (digital)
☐ Tankanzeige
☐ Motor-Temperatur
☐ Öldruck
☐ Drehzahl (genau)
☐ Durchflussmesser Diesel
☐ ...
```

Die Liste wächst.

Schnell.

---

Jedes "☐" ist ein Projekt.

Jedes Projekt ist:
- ESP32 (8€)
- Sensor (5-20€)
- Zeit (Stunden)
- Code
- Einbau

Machbar.

Alles machbar.

---

Aber:

8 Projekte.

8 ESP32.

8× programmieren.

8× einbauen.

Einzeln.

---

Ich schaue aufs Dashboard.

Voltmeter: neu, digital.

Daneben: altes Voltmeter.

Daneben: Drehzahlmesser (analog).

Daneben: Tankuhr (lügt).

Daneben: Tiefenmesser (okay).

Daneben: 12 Schalter (halb bekannt).

---

Alles einzeln.

Alles für sich.

Keine Verbindung.

Keine Integration.

Kein System.

---

Die Idee entsteht.

Langsam.

Schleichend.

---

"Was wenn..."

"Was wenn ich das ALLES..."

"...zusammenbringe?"

---

Ein System.

Ein Dashboard.

Ein Display.

Alle Daten.

Zentral.

Modern.

---

Ich skizziere:

```
┌─────────────────────────┐
│    BOOT DASHBOARD       │
├─────────────────────────┤
│  Batterie:  12.4V  85% │
│  Tank:      156 L      │
│  Motor:     82°C       │
│  Drehzahl:  1.850 U/m  │
│  Öldruck:   3.2 bar    │
├─────────────────────────┤
│  Alles auf einem        │
│  Display!               │
└─────────────────────────┘
```

Das wäre...

Das wäre perfekt.

---

Ich Google.

"Boot Dashboard DIY"

"Marine Display custom"

"ESP32 Dashboard"

---

Treffer:

- SignalK Server
- Node-RED Dashboard
- Grafana
- Raspberry Pi als Zentrale

Begriffe.

Viele Begriffe.

---

Ein Video:

"Komplettes Boot-Monitoring mit Raspberry Pi"

45 Minuten.

Ich schaue.

---

Der Typ zeigt:

- Raspberry Pi (50€)
- Mehrere ESP32 (je 8€)
- MQTT Broker
- Node-RED
- Dashboard auf Tablet
- WiFi im ganzen Boot

---

Alles vernetzt.

Alle Daten zentral.

Von überall abrufbar.

Handy.

Tablet.

Laptop.

---

Das ist...

Das ist genau was ich will!

Nicht 8 einzelne Projekte.

Sondern:

EIN System.

Für alles.

---

Ich pause das Video.

Mache Screenshots.

Notizen.

---

Komponenten:

```
Hardware:
- Raspberry Pi 4 (4GB): 60€
- 5× ESP32: 40€
- Sensoren: ~100€
- Kabel, Gehäuse: 30€
- Display (7" Touch): 80€

Software:
- Raspbian OS: kostenlos
- Mosquitto MQTT: kostenlos
- Node-RED: kostenlos
- Alles Open Source!

Gesamt: ~310€
```

---

Ich schaue auf die Zahl.

310€.

Für ein komplettes System.

Nicht einzelne Projekte.

Sondern:

Alles integriert.

Zentral gesteuert.

Professionell.

---

Raymarine vergleichbar:

Multifunction Display: 1.500€

Plus Sensoren: +800€

Plus Installation: +500€

Gesamt: 2.800€

---

Mein System: 310€.

Differenz: 2.490€.

Und: Ich verstehe es.

Kann es anpassen.

Erweitern.

Reparieren.

---

Die Entscheidung ist klar.

Ich baue es.

Komplett.

Von Grund auf.

---

Aber:

Das ist groß.

Sehr groß.

Nicht mehr "kleines Projekt".

Sondern:

Komplett-Digitalisierung.

---

Ich mache eine neue Liste.

Nicht "Projekte".

Sondern "Phasen".

---

```
PHASE 1: Foundation
☐ Raspberry Pi Setup
☐ MQTT Broker
☐ Node-RED installieren
☐ Basis-Dashboard

PHASE 2: Sensoren
☐ Batterie-Monitoring (3× Akkus)
☐ Tank-Füllstand
☐ Motor-Daten (Temp, Öl, RPM)
☐ Durchfluss Diesel

PHASE 3: Integration
☐ Alle ESP32 anbinden
☐ Dashboard finalisieren
☐ WiFi-Access-Point
☐ Mobile Zugriff

PHASE 4: Erweiterungen
☐ Heizungs-Steuerung
☐ Bilgepumpen-Monitor
☐ GPS/Navigation
☐ Alarme & Benachrichtigungen
```

Vier Phasen.

Viele Monate.

Aber: machbar.

---

Ich schaue auf die alte Liste.

8 einzelne Projekte.

Dann auf die neue Liste.

1 großes System.

---

Die neue Liste ist besser.

Durchdachter.

Kompletter.

Richtiger.

---

Aber auch:

Größer.

Zeitaufwändiger.

Teurer.

---

Ich rechne:

```
Zeit (geschätzt):
- Phase 1: 20h
- Phase 2: 40h
- Phase 3: 30h
- Phase 4: 50h

Gesamt: 140h

Bei 5h/Woche: 28 Wochen
= 7 Monate
```

7 Monate.

Fast ein Jahr.

Bis alles fertig ist.

---

Kosten:

```
Hardware: 310€
Reserve (Fehler, Ersatz): 100€
Werkzeug (noch zu kaufen): 50€

Gesamt: 460€
```

Nicht billig.

Aber machbar.

Über 7 Monate verteilt.

~65€/Monat.

---

Ich schaue aufs Boot.

Dann auf die Liste.

Zurück aufs Boot.

---

Das ist es.

Das ist DIE Idee.

Nicht "bisschen verbessern".

Sondern:

"Komplett neu machen."

---

Partner kommt an Bord.

Sieht den Notizblock.

Skizzen.

Listen.

Zahlen.

---

"Was planst du?"

Ich zeige.

Dashboard-Skizze.

Phasen-Plan.

Kosten-Übersicht.

---

Sie liest.

Schweigt.

Denkt nach.

---

"Das ist... groß."

"Ja."

"Und teuer."

"Geht. 460€."

"Über wie lange?"

"7 Monate."

---

Pause.

"Und das alles... für Daten?"

"Ja."

"Brauchst du das?"

Ich überlege.

"Nein."

"Aber?"

"Aber ich will es."

---

Sie lächelt.

"Du bist verrückt."

"Ja."

"Aber es ist dein Boot."

"Unser Boot."

"Dein Projekt."

---

Sie schaut auf die Skizze.

Dashboard.

Alle Daten.

Zentral.

Modern.

---

"Das sieht... professionell aus."

"Wird es auch."

"Kannst du das wirklich?"

"Weiß nicht. Aber ich probier's."

---

Sie nickt.

"Okay. Aber:"

"Was?"

"Budget einhalten."

"Versprochen."

"Und keine neuen Projekte parallel."

"Versprochen."

"Erst fertig machen, dann erweitern."

"Versprochen."

---

Sie geht.

Ich bleibe.

Mit der Liste.

Der Vision.

Dem Plan.

---

Abends.

Zu Hause.

Excel auf.

---

Tabelle 1: Budget

```
┌──────────────────────┬────────┬────────┐
│ Komponente           │ Preis  │ Status │
├──────────────────────┼────────┼────────┤
│ Raspberry Pi 4       │  60€   │   ☐    │
│ ESP32 (5×)           │  40€   │   ☐    │
│ Sensoren Set         │ 100€   │   ☐    │
│ 7" Touch Display     │  80€   │   ☐    │
│ Kabel & Gehäuse      │  30€   │   ☐    │
│ Werkzeug             │  50€   │   ☐    │
│ Reserve              │ 100€   │   ☐    │
├──────────────────────┼────────┼────────┤
│ GESAMT               │ 460€   │        │
└──────────────────────┴────────┴────────┘
```

Sieht machbar aus.

---

Tabelle 2: Timeline

```
┌───────┬──────────────────┬──────────┐
│ Monat │ Phase            │ Kosten   │
├───────┼──────────────────┼──────────┤
│ Jun   │ Phase 1: Setup   │   90€    │
│ Jul   │ Phase 2a: Akku   │   50€    │
│ Aug   │ Phase 2b: Tank   │   40€    │
│ Sep   │ Phase 2c: Motor  │   80€    │
│ Okt   │ Phase 3: WiFi    │   50€    │
│ Nov   │ Phase 4a: Heiz.  │   60€    │
│ Dez   │ Phase 4b: Rest   │   90€    │
├───────┼──────────────────┼──────────┤
│       │ GESAMT           │  460€    │
└───────┴──────────────────┴──────────┘
```

7 Monate.

Jeden Monat was bestellen.

Jeden Monat ein Schritt weiter.

Bis Dezember: Fertig.

---

Ich lehne mich zurück.

Das ist es.

Der Plan.

Die Vision.

Das Projekt.

---

Nicht mehr:

"Ich bau ein Voltmeter."

Sondern:

"Ich digitalisiere das komplette Boot."

---

Das ist...

Das ist wahnsinnig.

Ambitioniert.

Groß.

Vielleicht zu groß.

---

Aber:

Ich habe LED gebaut.

Ich habe Voltmeter gebaut.

Ich habe Code geschrieben.

Ich habe gelötet.

Ich habe gelernt.

---

Wenn ich das kann...

Kann ich auch den Rest.

Einen Schritt nach dem anderen.

Ein Projekt nach dem anderen.

Eine Phase nach der anderen.

---

Ich speichere die Excel-Tabelle.

"Boot_Digitalisierung_Master_Plan.xlsx"

Klingt offiziell.

Ist es auch.

---

Ich öffne Amazon.

Warenkorb:

- Raspberry Pi 4 (4GB)
- Offizielles Netzteil
- 32GB MicroSD
- Gehäuse mit Lüfter

Gesamt: 89€.

Phase 1.

---

Finger über dem "Bestellen"-Button.

Zögere.

---

Das ist der Point of no Return.

Wenn ich jetzt bestelle:

Gibt's kein Zurück mehr.

Projekt läuft.

7 Monate.

460€.

140 Stunden.

---

Aber:

Das will ich.

Wirklich.

Nicht weil's nötig ist.

Sondern weil's möglich ist.

---

Klick.

"Bestellen."

---

Bestellung aufgegeben.

Ankunft: Morgen.

---

Es hat begonnen.

Die Digitalisierung.

Die Transformation.

Von "altem Boot" zu "Smart-Boot".

---

Der Motor läuft.

Wie immer.

Kümmert sich nicht um Pläne.

Kümmert sich nicht um Raspberry Pi.

Läuft einfach.

Seit 1985.

Unverändert.

Zuverlässig.

---

Aber drumherum:

Ändert sich alles.

Analog wird digital.

Alt wird neu.

Raten wird wissen.

---

Ich schaue auf die Bestellbestätigung.

Raspberry Pi 4.

Morgen da.

Dann geht's los.

---

Partner kommt rein.

"Hast du bestellt?"

"Ja."

"Wie viel?"

"89€. Erste Rate."

Sie seufzt.

"Du ziehst das echt durch."

"Ja."

"Wahnsinn."

"Ja."

---

Sie lächelt.

"Viel Erfolg."

"Danke."

"Und vergiss nicht:"

"Was?"

"Dokumentieren. Für andere."

"Warum?"

"Weil du das zeigen musst."

---

Dokumentieren.

Gute Idee.

Fotos machen.

Code speichern.

Notizen schreiben.

---

Vielleicht.

Irgendwann.

Wenn's fertig ist.

Ein Blog?

Eine Anleitung?

Ein... Buch?

---

Aber das kommt später.

Viel später.

Erstmal: Bauen.

Lernen.

Machen.

---

Die Vision ist klar:

Komplettes Boot-Digitalisierungs-System.

Zentral.

Integriert.

Modern.

---

Der Weg ist lang:

7 Monate.

4 Phasen.

Unzählige Stunden.

Viele Fehler.

Noch mehr Lernen.

---

Aber:

Ich bin bereit.

Habe LED gebaut.

Habe Voltmeter gebaut.

Habe bewiesen: Ich kann das.

---

Jetzt:

Wird's groß.

Richtig groß.

---

Das Boot weiß es noch nicht.

Liegt ruhig am Steg.

LED leuchtet.

Voltmeter zeigt 12.4V.

Motor schläft.

---

Aber bald:

Raspberry Pi.

Sensoren überall.

Dashboard.

Daten.

Wissen.

---

Von "funktioniert irgendwie"

Zu "ich weiß genau was passiert".

---

Das ist die Vision.

Das ist der Plan.

Das ist das Projekt.

---

Der Motor läuft.

Wird immer laufen.

Unverändert.

Zuverlässig.

Seit 1985.

---

Aber alles andere?

Wird neu.

Digital.

Modern.

Smart.

---

Nächster Sommer:

Boot mit System.

Mit Daten.

Mit Wissen.

---

Nicht mehr raten.

Sondern wissen.

---

Das ist es wert.

460€.

140 Stunden.

7 Monate.

---

Für die Gewissheit.

Für das Wissen.

Für die Kontrolle.

---

Und für den Spaß.

Den Spaß am Bauen.

Am Lernen.

Am Verstehen.

---

Das Boot funktioniert.

Hat immer funktioniert.

Wird immer funktionieren.

---

Aber jetzt:

Wird es smart.

---
