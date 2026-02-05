# Band 3 – Kapitel 1: Die Idee

Die VDO-Instrumente sind alt.
Manche ungenau.
Der Drehzahlmesser funktioniert gar nicht mehr.

Das ist nicht tragisch.
Das Boot fährt auch ohne Drehzahlmesser.
Der Motor macht Geräusche, man hört ob er läuft.
Mehr braucht man eigentlich nicht.

Eigentlich.

---

Aber es nervt.

Es nervt, auf eine Nadel zu schauen, die sich nicht bewegt.
Es nervt, nicht zu wissen, ob der Motor jetzt 1.500 oder 2.500 Umdrehungen macht.
Es nervt, bei der Tankfüllung zu raten, weil die Tankanzeige irgendwas zwischen "voll" und "leer" zeigt, aber nie das Richtige.

Man gewöhnt sich dran.
An vieles gewöhnt man sich.
An quietschende Türen, an tropfende Wasserhähne, an Instrumente die lügen.

Bis man es nicht mehr tut.

---

Der Moment kam an einem Samstagnachmittag.
Nichts Besonderes.
Kein Drama, kein Notfall.

Nur der Blick aufs Armaturenbrett.
Tanknadel: irgendwo in der Mitte.
Temperaturnadel: irgendwo in der Mitte.
Drehzahlnadel: tot.

Und der Gedanke: Das muss doch besser gehen.

---

Natürlich gibt es bessere Lösungen.
Marine-Elektronik.
Raymarine, Garmin, Simrad.
Schöne Displays, bunte Grafiken, touchscreen-optimiert.

Man öffnet die Website.
Man schaut die Produkte an.
Man sieht die Preise.
Man schließt die Website.

Ein einzelner Multifunktions-Display: 800 Euro.
Ein Tankgeber mit NMEA2000: 200 Euro.
Ein Drehzahlsensor: 150 Euro.
Kabel, Stecker, Adapter: nochmal 100 Euro.

Für ein komplettes System landet man schnell bei 2.000 Euro.
Oder mehr.
Meistens mehr.

Das Boot ist kein Neubau.
Das Boot ist ein Projekt.
Projekte haben Budgets.
Budgets haben Grenzen.
Und die Grenze war deutlich unter 2.000 Euro.

---

Also: selber machen.

Nicht aus Geiz.
Aus Prinzip.
Und ein bisschen aus Geiz.

Das Mantra lautet: **Selbstgemacht ist wissen was drin ist und bezahlbar.**

Das gilt für Marmelade.
Das gilt für Möbel.
Das gilt erst recht für Elektronik.

---

ESP32 ist kein Fremdwort.
Die kleinen Dinger liegen zu Hause rum.
Immer ein paar auf Vorrat.
Für Smart Home, für Bastelprojekte, für "ich probier mal kurz was".

Wer einmal angefangen hat mit Mikrocontrollern, hört nicht mehr auf.
Das ist wie Gitarre spielen.
Man kauft eine, dann zwei, dann fünf.
Nur dass ESP32s weniger Platz brauchen.
Und seltener verstimmt sind.

---

Die Idee kam nicht über Nacht.
Sie wuchs.
Langsam, aber stetig.

Erst war es nur: "Der Drehzahlmesser muss ersetzt werden."
Dann: "Wenn schon, dann auch die Tankuhr."
Dann: "Und die Temperaturanzeige ist auch nicht mehr genau."
Dann: "Warum eigentlich nicht alles?"

So fangen Projekte an.
Klein und harmlos.
Und dann wachsen sie.
Wie Unkraut, nur teurer.

---

Ein A/D-Wandler für Marine-Instrumente: 150 Euro.
Ein ADS1115 bei AliExpress: 2 Euro.

Gleiche Funktion.
Anderer Preis.

Der Unterschied ist das Gehäuse, die Zertifizierung und der Markenname.
Und vielleicht ein bisschen Support.
Den man eh nie anruft.

Der ADS1115 kann 16-bit Auflösung.
Der kann vier Kanäle.
Der kann I2C.
Der kann alles, was man braucht.
Für 2 Euro.

Die Rechnung war einfach.

---

Das Armaturenbrett muss eh neu.
Irgendwann.
Das Boot hab ich erst ein Jahr, aber "irgendwann" steht schon seit Tag eins auf der Liste.
Direkt unter "Kaffeehalter montieren" und "Polster reinigen".

Der Touchscreen für BoatOS ist schon da.
Ein 10-Zoll-Display, das am Raspberry Pi hängt.
Zeigt Karten, zeigt GPS, zeigt Geschwindigkeit.
Könnte auch Motordaten zeigen.
Wenn man welche hätte.

BoatOS ist übrigens auch selbstgemacht.
Ein komplettes Bordcomputer-System.
Navigation, Dashboard, Steuerung.
Zusammen mit Claude entwickelt, weil KI-Unterstützung beim Coden Gold wert ist.
Aber das ist eine andere Geschichte.
Die steht in Band 4 und 5.

Warum also nicht alles kombinieren?

Ein System, das nicht nur anzeigt.
Das archiviert.
Das vergleicht.
Das auswertet.

Sensordaten während der Fahrt.
Automatisch ins Logbuch.
Mit Zeitstempel, mit Position, mit allem.

Nicht mehr raten.
Sondern wissen.

---

Die Vision wuchs weiter.

Wartungsplan mit Erinnerung.
Nicht "ich glaube, der Ölwechsel war letztes Jahr".
Sondern: "Ölwechsel fällig in 12 Betriebsstunden."
Das System zählt mit.
Das System erinnert.
Das System vergisst nicht.

Anders als ich.

---

Helm-Modus auf dem Tablet.
Alle Instrumente am Außensteuerstand sichtbar.
Ohne Kabel zum Außensteuerstand ziehen.
Ohne zweites Display kaufen.
Ohne Löcher bohren.

Einfach: Tablet mitnehmen, WLAN verbinden, fertig.
Die Daten sind eh im Netzwerk.
Man muss sie nur anzeigen.

Das spart nicht nur Geld.
Das spart Arbeit.
Und Nerven.
Und Diskussionen mit sich selbst, wo das Kabel lang soll.

---

Und dann der Durchfluss.

In der Bastelkiste lag ein Durchflusssensor.
Eigentlich für ein anderes Projekt gekauft.
Das andere Projekt wurde nie fertig.
Wie so viele Projekte.

Aber auf dem Boot?
In der Dieselleitung?

Echter Verbrauch.
Nicht "ungefähr 3 Liter pro Stunde".
Sondern: "3,27 Liter pro Stunde bei 2.100 Umdrehungen."

Echte Daten.
Zum Loggen.
Zum Auswerten.
Zum Optimieren.
Zum Angeben am Steg.

"Wie viel verbraucht deiner?"
"3,27 Liter bei Marschfahrt. Gemessen, nicht geraten."

Das ist unbezahlbar.
Also quasi kostenlos, weil der Sensor eh schon da lag.

---

In der Bastelkiste lag auch noch ein MPU6050.
Gyroskop und Beschleunigungssensor in einem.
Eigentlich für eine Drohne gedacht.
Die Drohne wurde nie gebaut.
Wie so vieles.

Aber auf dem Boot?
Neigung.
Schlagseite.
Bewegung in allen Achsen.

Nice to have, das plötzlich must-have wird.

Man stelle sich vor:
Das Logbuch zeigt nicht nur Position und Geschwindigkeit.
Sondern auch: "Maximale Schlagseite: 15 Grad bei der Schleusendurchfahrt."

Braucht man das?
Nein.
Will man das?
Unbedingt.

---

Der Plan war einfach:
ESP32 liest die Sensoren.
Schickt alles per MQTT an den Raspberry Pi.
BoatOS zeigt es an.
Fertig.

MQTT ist wie WhatsApp für Maschinen.
Einer schickt, einer empfängt.
Einfach, zuverlässig, bewährt.

Der ESP32 macht die Drecksarbeit.
Liest Spannungen, zählt Impulse, fragt Sensoren ab.
Und schickt alles ins Netzwerk.

Der Raspberry Pi sammelt.
Speichert.
Zeigt an.

Arbeitsteilung.
Wie in einer guten Ehe.
Nur ohne Diskussionen.

---

So einfach ist es nie.
Aber das wusste ich da noch nicht.

---

Die Bestellung ging an AliExpress.
Nicht Amazon, nicht Conrad, nicht der lokale Elektronikladen.
AliExpress.

Weil man da alles bekommt.
Weil es günstiger ist.
Und weil man eh drei Wochen Zeit hat, bis es ankommt.

Zeit zum Planen.
Zeit zum Zweifeln.
Zeit zum Umplanen.
Zeit zum Vergessen, was man bestellt hat.
Zeit zur Überraschung, wenn das Paket kommt.

"Ah ja, die ADS1115. Wofür waren die nochmal?"

Das gehört dazu.

---

Was ich bestellte:
- ADS1115 (16-bit ADC, I2C) – 2 Stück, weil 4 Kanäle nicht reichen
- Schraubklemmen – viele, weil man nie genug hat

Was ich schon hatte:
- ESP32 (liegen immer rum, wie Kugelschreiber, nur mit mehr Pins)
- MPU6050 (Bastelkisten-Fund)
- Durchflusssensor (Glücksfund vom gescheiterten Drohnen-Projekt)
- Widerstände, Kondensatoren, Dioden (Hobby-Mikroelektroniker halt)
- Lochrasterplatinen (sowieso immer da)
- Lötkolben, Lötzinn, Flussmittel (Grundausstattung)
- Kaffee (wichtigstes Werkzeug)

Gesamtkosten neue Teile: unter 10 Euro.
Für ein komplettes Monitoring-System.

Marine-Elektronik: 2.000 Euro.
DIY: 10 Euro.

Faktor 200.

Selbstgemacht ist wissen was drin ist und bezahlbar.
Das Mantra stimmt.

---

Die Idee war geboren.
Der Plan stand.
Die Teile waren unterwegs.
Die meisten lagen eh schon rum.

Jetzt musste es nur noch funktionieren.

Spoiler: Es hat gedauert.
Aber es hat funktioniert.

Am Ende zumindest.
Der Weg dahin war... lehrreich.

Aber davon später.

---
