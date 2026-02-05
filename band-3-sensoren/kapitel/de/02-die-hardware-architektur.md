# Band 3 – Kapitel 2: Die Hardware-Architektur

Am Anfang war ein Board.
Ein einziges.
Alles drauf, alles dran, alles kompakt.

So der Plan.

---

Der Plan hielt ungefähr eine Stunde.

Dann wurde aus einem Board ein Chaos aus Linien, Kreuzungen und der Frage: "Wo soll das jetzt hin?"

ESP32 hier.
ADS1115 da.
Spannungsteiler dazwischen.
Schraubklemmen am Rand.
Stromversorgung irgendwo.
Und der MPU6050 schwebt noch im Raum.

Das wird nichts.

---

Claude hatte die Idee.

"Warum nicht aufteilen? Nach Funktion. Drei Boards statt einem."

Klingt nach mehr Arbeit.
Ist es auch.
Aber es macht Sinn.

Ein Board für Strom.
Ein Board für Sensoren.
Ein Board für Logik.

Jedes Board hat eine Aufgabe.
Jedes Board ist austauschbar.
Jedes Board ist überschaubar.

Plötzlich war der Plan kein Chaos mehr.
Plötzlich war der Plan ein Plan.

---

**Das Konzept:**

```
┌─────────────────────────────────────────────┐
│                                             │
│  POWERBOARD                                 │
│  ├─ 12V rein (vom Boot-Netzteil)           │
│  ├─ 5V raus (für Sensorboard)              │
│  └─ 3.3V raus (für ESP32)                  │
│                                             │
│  SENSORBOARD                                │
│  ├─ Schraubklemmen für alle Sensoren       │
│  ├─ Spannungsteiler (12V → messbar)        │
│  └─ Signal-Aufbereitung                    │
│                                             │
│  MAINBOARD                                  │
│  ├─ ESP32 (das Gehirn)                     │
│  ├─ 2× ADS1115 (die Ohren)                 │
│  └─ MPU6050 (das Gleichgewicht)            │
│                                             │
└─────────────────────────────────────────────┘
```

Drei Boards.
Drei Aufgaben.
Eine Mission.

---

Das Schöne an der Aufteilung: Wenn was kaputtgeht, tauscht man ein Board.
Nicht das ganze System.

Wenn der ESP32 stirbt: neues Mainboard.
Wenn ein Spannungsteiler abraucht: neues Sensorboard.
Wenn die Stromversorgung Probleme macht: neues Powerboard.

Modular.
Wie LEGO.
Nur mit mehr Lötzinn.

---

Und wenn man später erweitern will?
Neues Sensorboard mit mehr Kanälen.
Oder neues Mainboard mit besserem Chip.
Der Rest bleibt.

Zukunftssicher.
So weit man bei Bastelprojekten von "Zukunft" sprechen kann.

---

**Das Powerboard**

Die Stromversorgung klingt einfach.
12V rein, 5V und 3.3V raus.
Was soll da schief gehen?

Einiges.

---

Das Boot hat ein 12V-System.
Wie jedes Boot.
Wie jedes Auto.
Wie alles, was Batterien hat und nicht aus der Steckdose kommt.

Der Raspberry Pi braucht 5V.
Hab ich schon.
Ein Netzteil, 12V auf 5V, 10 Ampere.
Hängt eh schon im System.
Versorgt den Pi, versorgt den Touchscreen, versorgt alles was 5V will.

Da kann das Powerboard auch mit dran.
Ein Abnehmer mehr, kein Problem bei 10 Ampere.

---

Der ESP32 braucht 3.3V.
Nicht 5V, nicht 12V.
3.3V.

Also: Stepdown.
Von 5V auf 3.3V.

Einfach.
Theoretisch.

---

Der erste Versuch: ein kleiner Spannungsregler.
Aufgelötet.
Angeschlossen.
Funktioniert.

Zwanzig Minuten später: funktioniert nicht mehr.
Riecht komisch.
Kleiner Regler, große Hitze, kurzes Leben.

Was war passiert?
Lötkolben zu lange dran.
Der kleine Regler hat's persönlich genommen.

Erkenntnis: Kleine Bauteile mögen keine langen Lötorgien.
Schnell rein, schnell fertig, nicht trödeln.

---

Zweiter Versuch.
Neuer Regler.
Diesmal schneller löten.

Funktioniert.
Bis heute.

Manchmal ist die Lösung einfach: weniger denken, schneller löten.

---

**Das Sensorboard**

Das Herzstück.
Hier kommen die Signale vom Boot rein.
Hier werden sie übersetzt.

Bootsprache → ESP32-Sprache.

---

Das Problem: Das Boot spricht 12V.
Der ESP32 versteht nur 3.3V.

12V auf einen GPIO-Pin vom ESP32?
Einmal.
Danach spricht der ESP32 gar nichts mehr.

Also: Spannungsteiler.

---

**Spannungsteiler für Dummies:**

Zwei Widerstände.
In Reihe.
Die Spannung teilt sich auf.

100kΩ und 47kΩ ergibt:
12V rein → 3.8V raus.

Perfekt für den ADS1115.
Der kann bis 4V.
Passt.

Die Formel steht im Internet.
Claude hat sie mir trotzdem nochmal erklärt.
Dreimal.
Jetzt sitzt sie.

---

Für die Batterieüberwachung: Spannungsteiler.
Für die Tankuhr: Spannungsteiler.
Für die Temperatur: Spannungsteiler.
Für den Öldruck: Spannungsteiler.

Spannungsteiler überall.
Wie Salz in der Suppe.
Zu wenig: schmeckt nicht.
Zu viel: auch nicht.

---

**Die Drehzahl**

Die Drehzahl ist anders.

Kein analoges Signal.
Kein Widerstand.
Keine Spannung zum Messen.

Die Lichtmaschine hat eine W-Klemme.
Die gibt Impulse aus.
Je schneller der Motor, desto mehr Impulse.

Der Plan: W-Klemme anzapfen, Impulse zählen, Drehzahl berechnen.

---

Claude und ich haben das durchgesprochen.

"Brauchst du einen Optokoppler?"
"Warum?"
"Galvanische Trennung. Sicherheit."
"Braucht man das?"
"Kommt drauf an."
"Worauf?"
"Ob du Risiko magst."

Ich mag Risiko.
Und weniger Bauteile.

Also: W-Klemme direkt auf einen ADS1115-Kanal.
Mit Spannungsteiler davor, natürlich.
Sonst: siehe oben, toter ESP32.

Funktioniert.
Ohne Optokoppler.
Manchmal ist weniger mehr.

---

**Das Mainboard**

Das Gehirn.

ESP32 in der Mitte.
Zwei ADS1115 drumherum.
MPU6050 in der Ecke.
Alles über I2C verbunden.

---

I2C ist praktisch.
Zwei Leitungen für alles.
SDA und SCL.
Daten und Takt.

Man kann mehrere Geräte anschließen.
Jedes hat eine Adresse.
Wie Hausnummern in einer Straße.

ADS1115 Nummer 1: Adresse 0x48.
ADS1115 Nummer 2: Adresse 0x49.
MPU6050: Adresse 0x68.

Drei Geräte, zwei Leitungen, null Probleme.

Theoretisch.

---

Praktisch war da dieses eine Mal, wo der I2C-Scanner nur ein Gerät fand.
Statt drei.

Panik.
Kabel prüfen.
Alles sitzt.
Spannung prüfen.
Alles da.
Nochmal scannen.
Ein Gerät.

Claude meinte: "Vielleicht der ADDR-Pin?"

Der ADDR-Pin bestimmt die Adresse.
GND = 0x48.
VDD = 0x49.

Bei mir: beide auf GND.
Beide mit Adresse 0x48.
Kollision.

Anfängerfehler.

Einen ADDR-Pin auf VDD gelegt.
Nochmal gescannt.
Drei Geräte.

Manchmal sind es die einfachen Dinge.

---

**Die Zusammenarbeit**

Das Projekt wäre ohne Claude nicht so schnell fertig geworden.
Vermutlich gar nicht.

Die Architektur: zusammen entwickelt.
Die Spannungsteiler: zusammen berechnet.
Die Firmware: Claude hat geschrieben, ich hab getestet.

Arbeitsteilung.
Claude ist schneller im Coden.
Ich bin schneller im Löten.
Zusammen sind wir ein Team.

---

Wobei "Team" manchmal auch heißt: einer macht Fehler, der andere nickt.

Die Geschichte mit dem ESP8266-Simulator zum Beispiel.

---

**Der ESP8266-Fail**

Die Sensoren waren noch nicht am Boot.
Aber testen wollte ich trotzdem.

Die Idee: Ein ESP8266 simuliert die Sensoren.
Gibt Spannungen aus.
Das Sensorboard liest sie.
Der ESP32 verarbeitet sie.

Claude fand die Idee gut.
"Ja, das funktioniert."

Ich auch.
"Klar, warum nicht."

---

Warum nicht?

Weil das Sensorboard für 12V ausgelegt ist.
Spannungsteiler, erinnerst du dich?

Der ESP8266 gibt 3.3V aus.
Maximal.

3.3V durch einen Spannungsteiler, der für 12V designed ist?
Da kommt hinten ungefähr nichts raus.

Der ESP32 sah: fast null.
Ich sah: verwirrende Werte.
Claude sah: sein Fehler.

"Oh. Stimmt. Das kann nicht funktionieren. Sorry."

Passiert.
KI ist auch nur menschlich.
Irgendwie.

---

Die Lösung war einfacher: Einfach am Boot testen.
Mit echten 12V.
Von einer echten Batterie.

Funktionierte sofort.

Manchmal ist der direkte Weg der beste.

---

**Das Ergebnis**

Drei Boards.
Alle funktionieren.
Alle reden miteinander.

Powerboard liefert Strom.
Sensorboard übersetzt Signale.
Mainboard denkt und sendet.

Ein System.
Aus der Bastelkiste.
Für unter 10 Euro.

Selbstgemacht ist wissen was drin ist und bezahlbar.

---

Die Hardware steht.
Jetzt fehlt nur noch die Software.

Und ein Gehäuse.
Aber eins nach dem anderen.

---
