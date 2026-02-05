# Band 3 – Kapitel 3: Die drei Boards

Drei Boards.
Drei Funktionen.
Ein Wochenende.

So der Plan.

Der Plan hat sogar funktioniert.
Meistens.

---

## Das Powerboard

Das kleinste der drei.
7 mal 5 Zentimeter.
Mehr braucht es nicht.

Die Aufgabe: Strom verteilen.
5V rein, 3.3V raus.
Fertig.

---

Moment, 5V rein?
Nicht 12V?

Richtig.
Das Boot hat 12V.
Aber das 12V-auf-5V-Netzteil existiert schon.
10 Ampere, hängt eh im System.
Versorgt den Raspberry Pi, den Touchscreen, alles was 5V will.

Warum also nochmal wandeln?
Das Powerboard hängt einfach mit dran.
Ein Abnehmer mehr.
Bei 10 Ampere ist das ein Rundungsfehler.

---

Der ESP32 will aber 3.3V.
Nicht 5V.
5V auf einen ESP32 ist wie Kaffee auf eine Tastatur.
Geht einmal.
Danach nie wieder.

Also: Stepdown.
Von 5V auf 3.3V.
Ein kleiner Spannungsregler.
Kostet Centbeträge.
Kann aber wichtig sein.

---

**Der erste Versuch**

Regler auflöten.
Kabel dran.
Einschalten.
Funktioniert.

Zwanzig Minuten später.
Regler anfassen.
Heiß.
Sehr heiß.
Dann: Rauch.
Dann: nichts mehr.

Was war passiert?

Der Lötkolben.
Zu lange dran.
Der kleine Regler hat die Wärme gespeichert wie ein Elefant einen Groll.
Und dann aufgegeben.

Erkenntnis Nummer eins: Kleine Bauteile mögen keine Wellness-Behandlung mit dem Lötkolben.
Schnell rein, schnell raus, nicht kuscheln.

---

**Der zweite Versuch**

Neuer Regler.
Gleiche Stelle.
Andere Technik.

Lötkolben an.
Drei Sekunden.
Lötkolben weg.
Nächstes Bein.
Drei Sekunden.
Fertig.

Funktioniert.
Bis heute.

Manchmal ist die Lösung nicht besser planen.
Sondern schneller handeln.

---

Das Powerboard ist das langweiligste der drei.
Aber ohne Powerboard: kein Strom.
Ohne Strom: keine Sensoren.
Ohne Sensoren: kein Projekt.

Das Langweilige ist oft das Wichtigste.
Wie Socken.
Keiner redet drüber.
Aber ohne wird's ungemütlich.

---

## Das Sensorboard

Das Herzstück.
Hier wird's interessant.

7 mal 5 Zentimeter.
Vollgestopft mit Schraubklemmen, Widerständen und der Hoffnung, dass alles funktioniert.

---

**Die Aufgabe:**

Acht Sensoren einsammeln.
Signale übersetzen.
Weiterleiten ans Mainboard.

Bootsprache rein.
ESP32-Sprache raus.

---

**Die acht Sensoren:**

1. Batterie 1 (Starterbatterie)
2. Batterie 2 (Versorgerbatterie)
3. Tank (wie viel Diesel noch?)
4. Öldruck (läuft der Motor rund?)
5. Temperatur (wird's zu heiß?)
6. Drehzahl (W-Klemme der Lichtmaschine)
7. Durchfluss (wie viel Diesel pro Stunde?)
8. MPU6050 (Neigung, Schlagseite, Bewegung)

Acht Sensoren.
Ein Board.
Viele Kabel.

---

**Das Problem mit 12V**

Das Boot denkt in 12V.
Der ESP32 denkt in 3.3V.
Der ADS1115 kann maximal 4V.

12V auf einen ADS1115-Eingang?
Einmal.
Dann ist der ADS1115 ein sehr teurer Briefbeschwerer.

Also: Spannungsteiler.

---

**Spannungsteiler – die Kurzversion:**

Zwei Widerstände.
In Reihe.
Die Spannung teilt sich auf.

100kΩ oben, 47kΩ unten.
12V rein, 3.8V raus.

Warum diese Werte?
Weil die Formel das sagt.
Und weil Claude sie mir dreimal erklärt hat.
Beim vierten Mal hab ich's kapiert.

---

Für jede Batterie: ein Spannungsteiler.
Für jeden analogen Sensor: ein Spannungsteiler.

Das Sensorboard ist im Grunde eine Sammlung von Spannungsteilern mit Schraubklemmen dran.

Klingt simpel.
Ist es auch.
Wenn man's einmal verstanden hat.

---

**Die VDO-Geber**

Tank, Öldruck, Temperatur – alles VDO.
Alte Schule.
Bewährte Technik.
Widerstandsgeber.

Je nach Messwert ändert sich der Widerstand.
Tank voll: anderer Widerstand als Tank leer.
Motor heiß: anderer Widerstand als Motor kalt.

Das Problem: Der ADS1115 misst Spannung, nicht Widerstand.

Die Lösung: Spannung anlegen, durch den VDO-Geber schicken, Spannungsabfall messen.
Mit einem festen Widerstand in Reihe wird aus dem variablen Widerstand eine variable Spannung.

Physik.
Manchmal ist sie auf unserer Seite.

---

**Die Drehzahl**

Die Drehzahl ist anders.

Kein Widerstand.
Keine Gleichspannung.
Impulse.

Die Lichtmaschine hat eine W-Klemme.
Die gibt Rechteckimpulse aus.
Je schneller der Motor, desto mehr Impulse pro Sekunde.

Der Plan: Impulse zählen, Frequenz berechnen, Drehzahl ausgeben.

---

Natürlich nicht direkt.
Die W-Klemme liefert auch irgendwas um die 12V.
Also: Spannungsteiler.

Ja, schon wieder.
Spannungsteiler sind die Butter auf dem Brot des Elektronikers.
Ohne geht fast nichts.

---

**Die Schraubklemmen**

Acht Sensoren brauchen Anschlüsse.
Schraubklemmen.
Viele.

Jeder Sensor: eine Klemme für Signal, eine für Masse.
Plus Stromversorgung.
Plus Reserve, weil man nie weiß.

Am Ende hat das Sensorboard mehr Schraubklemmen als ein Sicherungskasten.
Aber jede hat ihren Platz.
Jede hat ihre Aufgabe.

Und ja, ich hab sie beschriftet.
Nach dem dritten Mal "welches Kabel war nochmal Tank?" lernt man dazu.

---

## Das Mainboard

Das Gehirn.
Hier passiert die Magie.
Oder zumindest das, was nach Magie aussieht.

Etwas größer als die anderen.
Weil mehr drauf muss.

---

**Die Besetzung:**

- ESP32 WROOM-32 (der Chef)
- ADS1115 Nummer 1 (Adresse 0x48)
- ADS1115 Nummer 2 (Adresse 0x49)
- MPU6050 (Adresse 0x68)

Vier Bauteile.
Ein Bus.
I2C.

---

**I2C – der Datenbus**

I2C ist praktisch.
Zwei Leitungen für alles.
SDA für Daten.
SCL für Takt.

Man kann Dutzende Geräte anschließen.
Alle an die gleichen zwei Leitungen.
Jedes Gerät hat eine Adresse.
Wie Hausnummern in einer Straße.

Der ESP32 ruft: "Hey, 0x48, was liegt an?"
Der ADS1115 mit Adresse 0x48 antwortet.
Die anderen halten die Klappe.

Elegant.
Effizient.
Meistens problemlos.

---

**Das I2C-Drama**

Meistens.

Der I2C-Scanner ist ein kleines Programm.
Fragt alle möglichen Adressen ab.
Meldet, wer antwortet.

Erster Scan.
Ein Gerät gefunden.
0x68.
Der MPU6050.

Und die beiden ADS1115?
Stille.

---

Panik.

Kabel prüfen.
Sitzen.
Spannung prüfen.
3.3V, passt.
Lötstellen prüfen.
Sehen gut aus.

Nochmal scannen.
Ein Gerät.

Claude meinte: "Hast du die ADDR-Pins richtig gesetzt?"

ADDR-Pin?

---

Der ADS1115 hat einen ADDR-Pin.
Der bestimmt die I2C-Adresse.

ADDR an GND: Adresse 0x48.
ADDR an VDD: Adresse 0x49.
ADDR an SDA: Adresse 0x4A.
ADDR an SCL: Adresse 0x4B.

Bei mir: beide ADDR-Pins auf GND.
Beide ADS1115 mit Adresse 0x48.
Beide wollten gleichzeitig antworten.
Keiner konnte.

Adresskollision.
Klassiker.
Anfängerfehler.

---

Einen ADDR-Pin auf VDD gelötet.
Nochmal gescannt.

Drei Geräte gefunden.
0x48, 0x49, 0x68.

Manchmal ist die Lösung ein einziger Draht.
An der richtigen Stelle.

---

**Der ESP32 – fest verlötet**

Und dann der Fail.

Der ESP32 sitzt auf dem Mainboard.
Fest.
Sehr fest.
Direkt auf die Platine gelötet.

Warum?

Weil ich dachte: stabiler.
Weil ich dachte: kompakter.
Weil ich nicht dachte: was wenn er kaputtgeht?

---

Jetzt sitzt er da.
Für immer.
Oder bis ich das ganze Board wegwerfe.

Wenn der ESP32 stirbt, stirbt das Mainboard mit.
Keine Sockel, keine Stiftleisten, kein Austausch.

Ärgerlich?
Ja.
Lehrreich?
Auch ja.

Die nächste Version bekommt Stiftleisten.
Der ESP32 wird steckbar.
Austauschbar.
Professioneller.

Vielleicht sogar ein richtiges PCB.
Nicht Lochraster.
Sondern designed.
Mit Software.
Wie die Großen.

Aber das ist Zukunftsmusik.
Erstmal muss das hier funktionieren.

---

## Ein Wochenende

Freitag Abend: Bauteile sortieren.
Samstag: Löten.
Sonntag: Testen.

So der Plan.

---

**Freitag**

Alle Bauteile auf den Tisch.
Widerstände sortieren.
Schraubklemmen zählen.
ESP32 suchen.
ADS1115 finden.
MPU6050 aus der Bastelkiste graben.

Kaffee kochen.
Zweite Tasse kochen.
Schaltplan nochmal anschauen.
Dritte Tasse kochen.

Freitag war ein guter Tag.

---

**Samstag**

Lötkolben an.
Erste Platine: Powerboard.
Klein, überschaubar, Einstieg.

Spannungsregler drauf.
Kabel dran.
Erster Test.
Funktioniert.

Zweite Platine: Sensorboard.
Größer, mehr Teile, mehr Geduld.

Schraubklemmen auflöten.
Widerstände einsetzen.
Spannungsteiler aufbauen.
Messen, ob die Werte stimmen.
Stimmen meistens.
Nachbessern wo nicht.

Dritte Platine: Mainboard.
Die größte.
ESP32 drauf.
Direkt.
Ohne Sockel.
Der Fehler, von dem ich erzählt hab.

ADS1115 drauf.
MPU6050 drauf.
Alles verbinden.
I2C-Leitungen.
Stromversorgung.
Viele kleine Drähte.

Samstag war lang.
Aber produktiv.

---

**Sonntag**

Der Tag der Wahrheit.

Alles zusammenstecken.
Powerboard an 5V.
Sensorboard an Powerboard.
Mainboard an Sensorboard.

ESP32 flashen.
Test-Firmware drauf.
Seriellen Monitor öffnen.
Warten.

---

Erste Lebenszeichen.
ESP32 bootet.
Verbindet sich mit WLAN.
Sucht nach I2C-Geräten.

Ein Gerät gefunden.

Das war der Moment mit dem ADDR-Pin.
Siehe oben.
Drama, Lösung, Erleichterung.

---

Drei Geräte gefunden.
ADS1115 Nummer eins liefert Werte.
ADS1115 Nummer zwei liefert Werte.
MPU6050 liefert Neigung und Beschleunigung.

Es lebt.

---

Sensoren anschließen?
Noch nicht.
Erstmal nur das System.
Die Sensoren kommen später.
Am Boot.

Wo die echten Probleme warten.

---

**Der Ausblick**

Die drei Boards liegen auf dem Schreibtisch.
Fertig gelötet.
Getestet.
Funktionieren.

Als System.
Ohne echte Sensoren.
Aber immerhin.

Der nächste Schritt: Gehäuse drucken.
ASA-Filament.
UV-beständig.
Bootsfest.

Dann: Einbau.
Kabel ziehen.
Sensoren anschließen.
Testen unter Realbedingungen.

Dann kommen die echten Probleme.
Die "warum zeigt der Tank 120%"-Probleme.
Die "welches Kabel ist lose"-Probleme.
Die "wieso funktioniert das am Schreibtisch aber nicht am Boot"-Probleme.

Darauf freue ich mich.
Irgendwie.

---

Drei Boards.
Ein Wochenende.
Unter 10 Euro.

Selbstgemacht ist wissen was drin ist und bezahlbar.

Bisher jedenfalls.
Die Nerven beim Einbau sind noch nicht eingepreist.

---
