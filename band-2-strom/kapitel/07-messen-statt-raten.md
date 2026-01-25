# Band 2 – Kapitel 7: Messen statt Raten

Display zeigt 12,4 V.

Das ist irgendwo zwischen "alles gut" und "wird knapp".
Hilft nicht wirklich.

Man starrt auf die Zahl und versucht, aus zwei Ziffern nach dem Komma die Zukunft abzulesen.
Wie Kaffeesatzlesen, nur mit Volt.

---

12,4 V bei LiFePO₄.
Das können 80 % sein.
Oder 40 %.
Oder irgendwas dazwischen.

Die Kurve ist flach.
Sehr flach.
So flach, dass der Unterschied zwischen "noch drei Tage" und "heute Abend leer" ungefähr 0,2 V beträgt.

Das Display lügt nicht.
Es sagt nur nicht genug.

---

Man entwickelt ein Gefühl.

12,8 V: alles entspannt.
12,4 V: läuft noch.
12,2 V: wird Zeit.
12,0 V: zu spät.

Das funktioniert.
Meistens.

Bis es nicht mehr funktioniert, weil man vergessen hat, dass gestern bewölkt war und heute auch.
Oder weil der Kühlschrank nachts doch mehr zieht als gedacht.
Oder weil "nur kurz TV" drei Folgen wurden.

Dann steht man morgens da, starrt auf 12,1 V und denkt: Wie konnte das passieren?

---

Es gibt eine Lösung.
Keine perfekte.
Aber eine bessere.

Nicht Volt messen.
Wattstunden messen.

Nicht schätzen, wie viel noch da ist.
Wissen, wie viel noch da ist.

Nicht hoffen, dass Solar was bringt.
Sehen, wie viel Solar bringt.

Das Werkzeug dafür: ein ESP32, ein paar Sensoren und die Bereitschaft, ein paar Drähte zu löten.

---

**Die Idee**

Man baut ein System, das echte Zahlen liefert.

Solar: wie viel Wh kamen heute rein?
Verbrauch: wie viel Wh gingen heute raus?
Akku: wie viel Wh sind noch drin?

Nicht gefühlt.
Gemessen.

Klingt kompliziert.
Ist es auch.
Aber nur beim ersten Mal.

---

**Das Setup**

Ein ESP32.
Klein, günstig, hat WLAN.
Das Gehirn.

Ein Shunt.
Misst Strom, der durch ihn fließt.
Nicht perfekt genau, aber genau genug.

Ein paar Spannungsteiler.
Für Batterien, Solar, Verbraucher.
Damit der ESP32 nicht bei 12 V stirbt.

Ein MQTT-Broker.
Raspberry Pi, der im Schrank steht und Daten sammelt.
Wie ein Buchhalter, nur mit weniger Fragen.

---

Die Idee ist nicht neu.
Victron macht das seit Jahren.
Nur teuer.
Und proprietär.

ESP32 macht es billiger.
Und man weiß, was passiert, weil man es selbst gebaut hat.

Der Nachteil: man muss es selbst bauen.
Der Vorteil: man weiß, was passiert.

---

**Der Aufbau**

Drei Platinen.
Handgelötet, weil PCB zu aufwendig ist und Lochraster reicht.

Power Board: macht aus 12 V saubere 3,3 V für den ESP32.
Sensor Board: liest die Spannungen und Ströme.
Main Board: ESP32 und I2C-Module, die die Daten verarbeiten.

Klingt nach viel Arbeit.
Ist es auch.
Aber wenn man einmal angefangen hat, ist es nicht mehr aufzuhalten.

Man lötet.
Man testet.
Man flucht, weil der I2C-Scanner nur ein Gerät findet statt drei.
Man entdeckt, dass der ADDR-Pin vom zweiten ADS1115 nicht auf VDD liegt. *Natürlich.*

Man lötet nach.
Man testet wieder.
Alle drei Geräte gefunden.

Erfolg schmeckt nach Lötzinn und Kaffee.

---

**Die ersten Messungen**

ESP32 läuft.
Sensoren laufen.
MQTT läuft.

Man öffnet das Terminal und schaut, was ankommt.

```
boot/energie/solar/leistung 45.2
boot/energie/verbrauch/gesamt 12.8
boot/energie/batterie/soc 67
```

Echte Zahlen.
Live.
Nicht geschätzt, nicht geraten.
Gemessen.

Man starrt auf die Zahlen wie auf ein Wunder.
Und dann fängt man an zu verstehen.

---

**Die Aha-Momente**

Solar bringt 45 W.
Verbrauch liegt bei 13 W.

Das heißt: Akku lädt.
Langsam, aber er lädt.

Man wusste das vorher schon.
Theoretisch.

Aber *sehen*, wie die Zahlen sich ändern, ist anders.
Man sieht, wie die Sonne arbeitet.
Man sieht, wie der Kühlschrank zieht.
Man sieht, wie der Fernseher mehr nimmt als gedacht.

Plötzlich wird aus "sollte reichen" ein klares "reicht" oder "reicht nicht".

Kein Raten mehr.
Keine Hoffnung.
Nur Physik, in Echtzeit.

---

**Was man lernt**

Der Kühlschrank zieht nicht "ungefähr 600 Wh am Tag".
Er zieht manchmal 620, manchmal 580, manchmal 650.
Je nachdem, wie warm es ist.
Wie oft man die Tür öffnet.
Wie viel Bier drin ist.

Das Licht ist nicht "vernachlässigbar".
Vier LED-Leuchten, sechs Stunden am Abend: 120 Wh.
Das ist ein Zehntel vom Tagesverbrauch.

Solar bringt nicht "260 Wp".
Solar bringt 1.200 Wh im Juli.
500 Wh im Oktober.
200 Wh im Dezember.
Und an manchen Tagen fragt man sich, ob die Paneele noch da sind oder schon in den Winterschlaf gegangen sind.

Man hört auf, auf Datenblätter zu vertrauen.
Man fängt an, den eigenen Messungen zu vertrauen.

---

**Das Display**

12,4 V ist immer noch da.
Aber jetzt steht daneben: 67 %.

Und darunter: "Noch 2.200 Wh".

Das ist nicht perfekt.
LiFePO₄ SOC aus Spannung zu schätzen ist schwierig.
Aber es ist besser als vorher.

Viel besser.

Man weiß jetzt, wie lange es noch reicht.
Nicht gefühlt.
Berechnet.

Und wenn die Prognose sagt "morgen Nachmittag leer", dann ist man nicht überrascht.
Man ist vorbereitet.

---

**Die Grenze**

Das System ist nicht perfekt.

Der Shunt hat eine Genauigkeit von ±1 %.
Das klingt gut.
Aber nach einer Woche summiert sich das.

Die Spannung schwankt, je nachdem, ob gerade etwas zieht.
Die Temperatur beeinflusst die Messung.
Der Wind auch, irgendwie.

Man lernt, dass "messen" nicht "absolute Wahrheit" bedeutet.
Sondern nur: besser als raten.

Aber das reicht.

---

**Was bleibt**

Ein System, das Daten liefert.
Nicht perfekt.
Aber nützlich.

Man schaut nicht mehr aufs Display und hofft.
Man schaut aufs Dashboard und weiß.

Solar heute: 850 Wh.
Verbrauch heute: 1.100 Wh.
Differenz: -250 Wh.

Morgen wird Solar nicht reichen.
Aber man weiß es.
Und man kann reagieren.

Landstrom ran.
Oder eine Runde fahren.
Oder den Kühlschrank nachts ausschalten.

Keine Überraschungen mehr.
Nur noch Entscheidungen.

Und das ist der Unterschied zwischen "ich hoffe" und "ich weiß".

---

Nach ein paar Wochen schaut man nicht mehr auf Volt.
Man schaut auf Wattstunden.

Und man fragt sich, wie man je ohne leben konnte.

---
