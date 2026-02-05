# Band 3 – Kapitel 4: Die Firmware

Hardware ohne Software ist wie ein Auto ohne Motor.
Sieht gut aus.
Macht aber nichts.

Zeit, dem ESP32 beizubringen, was er tun soll.

---

## Die Arbeitsteilung

Claude schreibt Code.
Ich teste Code.
Claude fixt Code.
Ich teste wieder.

So läuft das.

Claude ist schneller im Tippen.
Ich bin schneller im Fluchen, wenn was nicht funktioniert.
Zusammen sind wir effizient.

Irgendwie.

---

Die Anforderungen waren klar:

1. WLAN-Verbindung (aber flexibel, nicht hardcoded)
2. Sensoren auslesen (alle acht)
3. Daten per MQTT verschicken
4. Nicht abstürzen

Punkt vier klingt trivial.
Ist er nicht.

---

## Der WiFiManager

Hardcoded WLAN-Daten sind praktisch.
Für zu Hause.
Wo sich das Passwort nie ändert.
Wo man immer das gleiche Netzwerk hat.

Auf dem Boot?
Anderes Netzwerk.
Anderes Passwort.
Und keine Lust, jedes Mal die Firmware neu zu flashen.

Die Lösung: WiFiManager.

---

**So funktioniert's:**

ESP32 startet.
Sucht nach bekanntem WLAN.
Findet keins.
Macht sein eigenes auf.

Man verbindet sich mit dem Handy.
"ESP32-Config" oder so ähnlich.
Eine Webseite öffnet sich.
Captive Portal.

Dort gibt man die WLAN-Daten ein.
SSID, Passwort.
Speichern.
ESP32 startet neu.
Verbindet sich.
Fertig.

Beim nächsten Start erinnert er sich.
Keine Eingabe mehr nötig.
Außer man wechselt das Netzwerk.

---

**Der Captive-Portal-Bug**

So die Theorie.

Die Praxis sah anders aus.

ESP32 machte sein Netzwerk auf.
Handy verband sich.
Und dann: nichts.
Keine Webseite.
Kein Portal.
Nur Hoffnung und Enttäuschung.

---

Claude und ich haben gesucht.
Stundenlang.

Lag es am Code?
An der Library?
Am Handy?
Am Wetter?

Am Ende war es ein Timing-Problem.
Der Webserver startete, bevor das Netzwerk bereit war.
Ein kurzer Delay hat's gefixt.

Zwei Zeilen Code.
Drei Stunden Suche.

Willkommen in der Softwareentwicklung.

---

## Die Sensoren auslesen

Acht Sensoren.
Zwei ADS1115.
Ein MPU6050.
Verschiedene Signale.
Verschiedene Berechnungen.

---

**Die ADS1115-Kanäle:**

Jeder ADS1115 hat vier Kanäle.
Zwei ADS1115 machen acht Kanäle.
Passt perfekt.

Fast.

Kanal 0, ADS1115 #1: Batterie 1
Kanal 1, ADS1115 #1: Batterie 2
Kanal 2, ADS1115 #1: Tank
Kanal 3, ADS1115 #1: Öldruck

Kanal 0, ADS1115 #2: Temperatur
Kanal 1, ADS1115 #2: Drehzahl
Kanal 2, ADS1115 #2: Durchfluss
Kanal 3, ADS1115 #2: Reserve

Die Libraries machen das einfach.
Adafruit_ADS1X15.
Ein paar Zeilen Code, fertig.

```cpp
ads1.begin(0x48);
ads2.begin(0x49);

float batterie1 = ads1.readADC_SingleEnded(0);
float batterie2 = ads1.readADC_SingleEnded(1);
```

Roh-Werte.
Die muss man dann noch umrechnen.
Aber das kommt später.

---

**Der MPU6050:**

Neigung und Schlagseite.
Gyroskop und Beschleunigungssensor.

Auch hier: Library macht's einfach.
MPU6050_light.
Ein paar Zeilen, fertig.

```cpp
mpu.begin();
mpu.calcOffsets();

float pitch = mpu.getAngleX();
float roll = mpu.getAngleY();
```

Der `calcOffsets()`-Aufruf ist wichtig.
Kalibriert den Sensor.
Muss einmal beim Start passieren.
Wenn das Boot gerade liegt.

Wenn das Boot nicht gerade liegt?
Dann zeigt der Sensor später auch nicht gerade.
Müsste man dann in Software korrigieren.

Aber das Boot liegt meistens gerade.
Meistens.

---

## MQTT – die Datenautobahn

Die Sensoren liefern Werte.
Die müssen irgendwo hin.
Zum Raspberry Pi.
Zu BoatOS.
Ins Dashboard.

Der Weg: MQTT.

---

**MQTT für Dummies:**

Publisher und Subscriber.
Einer schickt, einer empfängt.
Dazwischen: ein Broker.

Der ESP32 published.
Der Raspberry Pi subscribed.
Der Broker (Mosquitto) vermittelt.

Wie eine Pinnwand.
Der ESP32 hängt Zettel auf.
Der Raspberry Pi liest sie ab.

---

**Die Topics:**

Jeder Sensor bekommt sein eigenes Topic.
Wie eine Adresse.

```
boot/sensor/batterie1
boot/sensor/batterie2
boot/sensor/tank
boot/sensor/oeldruck
boot/sensor/temperatur
boot/sensor/drehzahl
boot/sensor/durchfluss
boot/sensor/pitch
boot/sensor/roll
```

Dazu noch Topics für SignalK.
Weil Kompatibilität nie schadet.
Und weil SignalK ein Standard ist, den andere Systeme verstehen.

---

**PubSubClient:**

Die Library für MQTT auf dem ESP32.
Einfach zu benutzen.
Meistens zuverlässig.

```cpp
client.publish("boot/sensor/batterie1", "12.6");
client.publish("boot/sensor/tank", "75");
```

Fertig.
Die Daten sind unterwegs.

Der Raspberry Pi hört zu.
BoatOS zeigt an.
Das Dashboard aktualisiert sich.

Magie.
Oder zumindest: gut funktionierende Technik.

---

## Der Test-Modus

Ein Feature, das aus der Not geboren wurde.

---

Das Problem:
Die Hardware funktioniert am Schreibtisch.
Aber am Boot sind keine echten Sensoren angeschlossen.
Noch nicht.

Wie testet man ein System, das auf Sensoren wartet, die es noch nicht gibt?

---

Die Lösung: Fake-Werte.

```cpp
bool test_mode = true;

if (test_mode) {
    batterie1 = 12.6;
    batterie2 = 12.4;
    tank = 75.0;
    // ... etc
} else {
    batterie1 = readBatterie1();
    batterie2 = readBatterie2();
    tank = readTank();
    // ... etc
}
```

Im Test-Modus: statische Werte.
Im Normal-Modus: echte Sensoren.

Ein Schalter.
Eine Variable.
Unendlich praktisch.

---

Damit konnte ich das ganze System testen.
WLAN-Verbindung.
MQTT-Übertragung.
Dashboard-Anzeige.

Alles mit Fake-Werten.
Alles ohne Boot.
Alles am Schreibtisch.

Erst wenn das funktioniert, geht's ans Boot.
Mit echten Sensoren.
Mit echten Problemen.

Der Test-Modus war Claudes Idee.
Eine gute Idee.
Eine von vielen.

---

## Die Umrechnung

Roh-Werte sind schön.
Aber "2847" sagt mir nicht, wie voll der Tank ist.

Die Sensoren liefern Zahlen.
Der ADS1115 liefert Werte zwischen 0 und 32767.
Das muss umgerechnet werden.

---

**Batterie:**

Der Spannungsteiler macht aus 12V etwa 3.8V.
Der ADS1115 misst diese 3.8V.
Und gibt einen Wert aus.

Zurückrechnen:
Gemessener Wert → Spannung am ADS1115 → Spannung vor dem Spannungsteiler.

```cpp
float spannung_ads = (rohwert / 32767.0) * 4.096;
float spannung_real = spannung_ads * ((100.0 + 47.0) / 47.0);
```

Das 4.096 ist der Messbereich des ADS1115.
Die 100 und 47 sind die Widerstände im Spannungsteiler.

Mathematik.
Nicht kompliziert.
Aber man muss es einmal verstanden haben.

---

**Tank:**

Der VDO-Geber ändert seinen Widerstand.
Leer: hoher Widerstand.
Voll: niedriger Widerstand.
Oder umgekehrt.
Je nach Geber.

Das muss kalibriert werden.
Am Boot.
Mit echtem Tank.
Einmal leer messen, einmal voll messen.
Dann interpolieren.

Die Formel steht.
Die Werte kommen später.
Wenn der Sensor angeschlossen ist.

---

**Drehzahl:**

Die W-Klemme liefert Impulse.
Je schneller der Motor, desto mehr Impulse.

Impulse pro Sekunde messen.
Mit der Polzahl der Lichtmaschine verrechnen.
Ergebnis: Umdrehungen pro Minute.

```cpp
rpm = (impulse_pro_sekunde * 60) / polpaare;
```

Die Polpaare muss man kennen.
Oder raten.
Oder ausprobieren.

Bei meiner Lichtmaschine: noch herauszufinden.
Ein Problem für später.

---

## Der Code im Repo

Die komplette Firmware liegt auf GitHub.
Im Repository.
Für jeden einsehbar.

Dazu:
- Schaltpläne (einfach, aber verständlich)
- Hardware-Bilder (damit man sieht, wie's aussieht)
- Dokumentation (damit man versteht, was passiert)

Selbstgemacht ist wissen was drin ist und bezahlbar.

Und wenn's auf GitHub liegt, können andere davon lernen.
Oder Fehler finden.
Oder verbessern.

Open Source.
Wie es sein soll.

---

## Das Ergebnis

Die Firmware läuft.

ESP32 startet.
Verbindet sich mit WLAN.
Liest Sensoren (oder Fake-Werte).
Schickt alles per MQTT.
Alle paar Sekunden.
Zuverlässig.

Im Test-Modus: perfekt.
Im echten Modus: noch zu testen.

Aber die Basis steht.

---

Der nächste Schritt: echte Sensoren.
Am echten Boot.
Mit echten Kabeln.
Und echten Problemen.

Der Test-Modus war nur das Aufwärmen.
Jetzt kommt das Spiel.

---

Software ist nie fertig.
Software ist nur "gut genug für jetzt".

Und jetzt ist gut genug.
Erstmal.

---
