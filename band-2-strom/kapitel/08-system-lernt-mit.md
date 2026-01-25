# Band 2 – Kapitel 8: Das System lernt mit

Das ESP32-System läuft.
Die Daten fließen.
MQTT summt im Hintergrund wie ein zufriedener Kühlschrank.

Aber Daten im Terminal zu sehen ist das eine.
Sie zu nutzen ist das andere.

Man braucht ein Dashboard.
Etwas, das man anschaut, ohne nachzudenken.
Etwas, das auf einen Blick zeigt: läuft oder läuft nicht.

---

**Die Anforderung**

Keine Excel-Tabelle.
Keine Log-Dateien.
Keine Kommandozeile.

Einfach: Zahlen, Grafiken, Farben.
Rot wenn's schlecht ist.
Grün wenn's gut ist.
Gelb wenn man aufpassen sollte.

Wie ein Cockpit.
Nur für Strom.

---

**Das Dashboard**

BoatOS auf dem Raspberry Pi.
Node-RED dahinter, um MQTT-Daten zu verarbeiten.
Ein paar Widgets, die man zusammenklickt.

Klingt kompliziert.
Ist es am Anfang auch.
Aber nach dem dritten Versuch weiß man, wie es geht.

Man abonniert die MQTT-Topics:
```
boot/energie/solar/leistung
boot/energie/verbrauch/gesamt
boot/energie/batterie/soc
```

Und dann baut man Widgets.

Ein Gauge für Solar.
Ein Balken für den Akku.
Ein Graph für den Verbrauch über die letzten 24 Stunden.

Nach ein paar Stunden hat man etwas, das funktioniert.
Nach ein paar Tagen hat man etwas, das gut aussieht.
Nach ein paar Wochen hat man etwas, auf das man stolz ist.

---

**Was man sieht**

Solar-Leistung: live.
Nicht "sollte 260 Wp bringen".
Sondern: bringt gerade 83 W.

Das ändert sich.
Jede Sekunde.
Wolke zieht vorbei: 83 W → 12 W.
Wolke weg: 12 W → 91 W.

Man sieht, wie empfindlich Solar ist.
Man sieht, dass eine einzige Wolke reicht, um aus "lädt gut" ein "lädt kaum" zu machen.

Man lernt, Wolken zu hassen.
Aber man versteht sie auch.

---

Verbrauch: live.
Nicht "ungefähr 1.200 Wh am Tag".
Sondern: gerade 14,2 W.

Kühlschrank schaltet ein: 14,2 W → 58 W.
Zwei Minuten später: 58 W → 18 W.
Licht an: 18 W → 28 W.

Man sieht jeden Verbraucher.
Man sieht, was wie viel zieht.
Man sieht, dass "nur kurz Licht" über den Tag verteilt 150 Wh sind.

Plötzlich ist Strom nicht mehr abstrakt.
Strom ist sichtbar.
Und man fängt an, bewusster zu schalten.

---

Batterie-SOC: live.
Nicht "irgendwo zwischen voll und leer".
Sondern: 68 %.

Mit Prognose:
"Bei aktuellem Verbrauch: noch 32 Stunden."

Das ist nicht perfekt.
Die Prognose ändert sich, wenn sich der Verbrauch ändert.
Aber es ist eine Zahl.
Eine Richtung.
Ein Gefühl von Kontrolle.

Man schaut morgens aufs Dashboard wie andere Leute aufs Wetter schauen.
Und man plant den Tag danach.

---

**Die Überraschungen**

Man denkt, man weiß, wie das Boot läuft.
Dann schaut man aufs Dashboard und lernt.

Der Kühlschrank zieht nachts mehr als gedacht.
Nicht viel mehr.
Aber genug, dass es auffällt.
150 Wh statt 100 Wh.

Warum?
Weil nachts kälter ist?
Weil der Kompressor länger läuft?
Keine Ahnung.

Aber man sieht es.
Und man kann entscheiden: ausschalten oder nicht.

---

Das Licht ist nicht das Problem.
Das Radio ist das Problem.

Läuft den ganzen Tag.
Zieht nur 8 W.
Klingt nach nichts.

Aber 8 W × 12 Stunden = 96 Wh.
Das ist fast ein Zehntel vom Tagesverbrauch.

Man schaltet das Radio aus, wenn man es nicht hört.
Plötzlich sind 100 Wh mehr im Akku.

Kleine Änderung.
Großer Effekt.

---

Solar im Winter ist noch deprimierender, wenn man es live sieht.

Ganzer Tag bewölkt: 180 Wh.
Das ist nicht mal ein Viertel vom Verbrauch.

Man schaut aufs Dashboard und denkt: Warum hab ich Solar überhaupt?

Dann kommt ein sonniger Tag.
Drei Stunden Sonne im Dezember: 420 Wh.

Ah. Darum.

Man lernt, dass Solar nicht konstant ist.
Aber man lernt auch, wann es sich lohnt, aufs Wetter zu hoffen.

---

**Die Prognose**

Das Dashboard kann rechnen.

Aktueller Verbrauch: 1.150 Wh/Tag.
Aktueller Solar-Ertrag: 650 Wh/Tag.
Differenz: -500 Wh/Tag.

Akku hat noch 1.800 Wh.
Bei -500 Wh/Tag: noch 3,6 Tage.

Das ist keine Garantie.
Morgen kann Solar besser werden.
Oder der Verbrauch höher.

Aber es ist eine Orientierung.
Und Orientierung ist mehr als man vorher hatte.

---

Man fängt an, strategisch zu denken.

Drei bewölkte Tage vorhergesagt?
Heute schon Landstrom ran.
Oder eine Runde fahren.
Oder den Kühlschrank nachts aus, bis die Sonne wiederkommt.

Man reagiert nicht mehr.
Man agiert.

Das ist der Unterschied.

---

**Was man nicht sieht**

Das System zeigt viel.
Aber nicht alles.

Es zeigt nicht, wie alt der Akku ist.
Es zeigt nicht, ob die Zellen balanciert sind.
Es zeigt nicht, ob irgendwo ein Kriechstrom fließt.

Für das braucht man andere Werkzeuge.
Oder ein BMS mit besseren Daten.

Aber das, was es zeigt, reicht.
Für den Alltag.
Für die Entscheidungen, die man täglich trifft.

Perfekt ist das System nicht.
Aber perfekt muss es auch nicht sein.

---

**Die Routine**

Nach ein paar Wochen wird das Dashboard zur Gewohnheit.

Morgens: kurzer Blick.
SOC? Verbrauch gestern? Solar-Prognose heute?

Abends: kurzer Blick.
Wie viel Solar kam rein? Wie viel ging raus? Reicht es?

Man plant nicht mehr groß.
Man schaut einfach und weiß.

Und wenn man weiß, kann man entspannen.
Oder handeln.
Aber man wird nicht mehr überrascht.

---

**Was bleibt**

Ein System, das mitdenkt.
Nicht intelligent.
Aber informiert.

Es sagt nicht: "Du musst jetzt Landstrom nehmen."
Es sagt: "SOC 42 %. Bei aktuellem Verbrauch: noch 18 Stunden."

Und man entscheidet selbst.

Das ist das Schöne daran.
Man hat die Daten.
Man hat die Kontrolle.
Man muss nicht raten.

---

Autarkie war das Ziel.
Geworden ist es: informierte Abhängigkeit.

Man ist nicht unabhängig von Strom.
Man ist nur nicht mehr überrascht davon.

Man weiß, wann Solar reicht.
Man weiß, wann Fahren hilft.
Man weiß, wann Landstrom nötig ist.

Und das ist genug.

Mehr als genug.

---

**Epilog: Ein Jahr später**

Das Dashboard läuft.
Tag für Tag.
Ohne Pause, ohne Beschwerde.

Man schaut morgens drauf wie auf die Wettervorhersage.
Man plant danach wie nach dem Kalender.

Solar im Sommer: alles gut.
Solar im Winter: weniger gut, aber man weiß es.

Der Akku hält.
Das System funktioniert.
Die Zahlen stimmen, meistens.

Und wenn man ganz ehrlich ist:
Man könnte jetzt nicht mehr ohne.

Nicht weil es perfekt ist.
Sondern weil es reicht.

Und "reicht" ist das neue "perfekt".

---

Man sitzt abends im Cockpit.
Bier in der Hand.
Display zeigt: SOC 78 %, Verbrauch 11 W, Solar morgen: sonnig.

Man lehnt sich zurück.

Strom ist nie einfach.
Aber mit Daten ist es einfacher.

Und das, das reicht.

---
