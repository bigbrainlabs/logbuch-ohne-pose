# Band 1 – Kapitel 5: Die Idee

*Oder: "Das kann ich auch!"*

---

---

---

März.

Zu Hause.

Schreibtisch.

ESP32 liegt da.

Klein.

Unscheinbar.

8€.

Soll mein Boot digitalisieren.

Einer von vielen.

---

YouTube-Tutorial, Video 1:

"ESP32 Boot Monitoring Tutorial"

Länge: 22 Minuten.

Ich drücke Play.

---

Der Typ im Video erklärt:

ESP32 = Mini-Computer.

WiFi, Bluetooth, 30 Pins.

Programmierbar.

Kann Sensoren auslesen.

Kann Displays ansteuern.

Kann... alles.

Kein Budget-Stress.

---

Ich schaue auf den ESP32.

Dann aufs Video.

Zurück zum ESP32.

"Das Ding kann WiFi?"

Video sagt: Ja.

"Und Bluetooth?"

Video sagt: Ja.

"Für 8€?"

Video sagt: Ja.

Ich bin beeindruckt.

---

Video weiter:

"Arduino IDE installieren."

Pause.

Ich Google: "Arduino IDE Download"

Klick.

Download.

Installieren.

5 Minuten später: Fertig.

---

Arduino IDE öffnen.

Sieht sauber aus. Code-Editor?

Menü oben.

Leere Datei.

Cursor blinkt.

Arduino IDE. Alter Bekannter.

---

Video weiter:

"Board Manager öffnen."

Ich klicke.

Liste erscheint.

"ESP32 installieren."

Ich suche.

Finde.

Klicke Install.

Lädt.

Installiert.

Fertig.

---

"Board auswählen: ESP32 Dev Module"

Ich wähle aus.

"Port auswählen: COM3"

Ich wähle COM3.

"USB Kabel anschließen."

Ich schließe an.

ESP32 blinkt kurz.

Lebt.

---

Video zeigt Code:

void setup() { Serial.begin(115200); Serial.println("Hallo Welt!"); } void loop() { delay(1000); }

Ich tippe ab.

Genau so.

Ohne zu verstehen.

---

"Upload drücken."

Ich drücke.

Arduino IDE denkt.

"Verbinde..."

"Lädt hoch..."

"Fertig."

---

"Serial Monitor öffnen."

Ich öffne.

Schwarzes Fenster.

Leer.

Dann:

"Hallo Welt!"

---

Ich starre drauf.

Ein Mini-Computer.

Kein Budget-Stress.

Sagt "Hallo Welt".

Zu mir.

Über USB.

---

Das ist... cool.

Sehr cool.

Erster Code für's Boot.

Okay, Copy-Paste vom Tutorial.

Aber: Funktioniert!

---

Video 2:

"LED blinken lassen"

Der Klassiker.

Jeder fängt damit an.

---

Code:

void setup() { pinMode(2, OUTPUT); } void loop() { digitalWrite(2, HIGH); delay(1000); digitalWrite(2, LOW); delay(1000); }

Ich tippe.

Upload.

---

ESP32 hat eine interne LED.

Pin 2.

Sie blinkt.

An.

Aus.

An.

Aus.

---

LED blinkt. Wie hundert Mal vorher.

Aber diesmal:

Für's Boot.

Das fühlt sich anders an.

Besser.

Aber trotzdem:

Boot-Projekt Nummer 1 läuft.

Gefühlt.

---

Video 3:

"Externe LED anschließen"

Jetzt wird's praktisch.

---

Breadboard rausholen.

LED rausholen.

Widerstand rausholen (220 Ohm, sagt Video).

Jumper Kabel rausholen.

---

Video erklärt:

LED, Widerstand, Breadboard. Hab ich. Standard.

Das kann ich im Schlaf.

Seit Jahren.

Aber:

Boot-Elektrik ist was anderes als Bastelkiste.

---

Stecken:

ESP32 Pin 2 → Widerstand → LED (+) → LED (-) → GND

So wie im Video.

Hoffnung: Funktioniert.

Realität: ...

---

Code hochladen.

Gleicher wie vorhin.

LED blinkt!

Extern!

Auf dem Breadboard!

Ich habe Hardware gesteuert!

Mit Software!

---

Ich lehne mich zurück.

Grinse.

Das war einfach.

Viel einfacher als gedacht.

LED blinkt.

Ich habe es verstanden.

Quasi.

---

Buster hebt den Kopf.

Schaut auf das blinkende Licht.

Blinkende LED.

Buster schaut.

LED blinkt.

An. Aus. An. Aus.

An. Aus. An. Aus.

Buster legt den Kopf schief.

---

So wie Hunde halt schauen.

Wenn ihr Mensch komische Sachen macht.

Was er nicht weiß:

Das ist erst der Anfang.

Alles andere ist Menschenkram.

Die LED blinkt weiter.

"Ja."

Hunde sind weise.

Sie wissen, wann man aufhören sollte.

Geht.

LED blinkt weiter.

---

Video 4:

"Spannung messen mit ESP32"

JETZT wird's relevant.

---

ESP32 hat ADC.

Analog-Digital-Converter.

Kann Spannung messen.

0-3.3V direkt.

Mehr: Spannungsteiler nötig.

---

Boot hat 12V.

ESP32 verträgt 3.3V.

12V direkt auf den ADC? Schon klar. Nicht mein erstes Mal.

Also: Spannungsteiler.

Hab ich alles da.

---

Spannungsteiler:

Kenne ich.

Hundert Mal berechnet.

Aber: 12V Boot-Batterie ist was anderes als 5V Labornetzteil.

12V werden 3.3V.

Mathematik.

---

Kurz rechnen:

Vout = Vin × (R2 / (R1 + R2)) Für 12V → 3.3V: R1 = 100kΩ R2 = 38kΩ

Ich habe:

• 100kΩ: Kiste. Drei Beutel.

• 38kΩ: Nicht genau, aber 47kΩ passt.

47kΩ ergibt 3.5V am ADC.

Genug Headroom.

Passt.

Genug Headroom.

Passt.

---

Breadboard aufbauen:

12V (Netzteil) → R1 (100kΩ) → R2 (47kΩ) → GND

Zwischen R1 und R2: Abgriff

Abgriff → ESP32 Pin 34 (ADC)

---

Code:

void setup() { Serial.begin(115200); } void loop() { int wert = analogRead(34); float spannung = wert * (3.3 / 4095.0); float batterie = spannung * 4.0; // Rückrechnung Serial.print("Batterie: "); Serial.print(batterie); Serial.println(" V"); delay(1000); }

Upload.

---

Serial Monitor:

"Batterie: 11.8 V"

Netzteil zeigt: 12.0V

Differenz: 0.2V

Ungenau, aber: NAH DRAN!

---

Ich starre auf die Zahl.

11.8V.

Echte Batterie-Spannung.

Vom ESP32.

Direkt von der Klemme.

---

Das ist...

Das ist genau was ich brauche!

Für's Boot!

Statt nutzlosem 12.0V-Voltmeter!

Echte Spannung!

Live!

Genau!

---

Ich mache ein Foto.

Breadboard. Hab ich.

ESP32.

LED.

Widerstände.

Ich ziehe ihn weg.

Serial Monitor: "Batterie: 11.8 V"

---

Schicke es an einen Freund.

"Schau mal, funktioniert!"

Antwort: "Was ist das?"

"ESP32. Misst Spannung."

"Für's Boot?"

Unbeeindruckt.

"Cool. Kannst du das wirklich?"

"Gerade gelernt."

"Krass."

---

Ja.

Krass.

Bin ich auch.

---

Video 5:

"OLED Display anschließen"

Jetzt kommt das Display.

---

OLED 0.96 Zoll.

Klein.

128×64 Pixel.

I2C. Kenne ich.

Standard-Verkabelung:

• VCC (3.3V)

• GND

• SDA (Daten)

• SCL (Clock)

---

Breadboard erweitern:

Display anschließen.

ESP32 Pin 21 → SDA

ESP32 Pin 22 → SCL

VCC → 3.3V

GND → GND

---

Code:

Video hat Library.

Adafruit_SSD1306.

Arduino IDE → Library Manager.

Suchen: "SSD1306"

Installieren.

---

Beispiel-Code:

#include <Adafruit_SSD1306.h> Adafruit_SSD1306 display(128, 64); void setup() { display.begin(SSD1306_SWITCHCAPVCC, 0x3C); display.clearDisplay(); display.setTextSize(2); display.setTextColor(WHITE); display.setCursor(0,0); display.println("Hallo"); display.println("Boot!"); display.display(); } void loop() { }

Upload.

---

Display:

Zeigt:

"Hallo

Boot!"

In Weiß.

Auf Schwarz.

Scharf.

Lesbar.

Perfekt.

---

Ich kombiniere.

Spannungsmessung + Display.

Code schreiben:

void loop() { int wert = analogRead(34); float spannung = wert * (3.3 / 4095.0); float batterie = spannung * 4.0; display.clearDisplay(); display.setTextSize(2); display.setCursor(0,0); display.print("Batt:"); display.setCursor(0,20); display.print(batterie, 1); display.print(" V"); display.display(); delay(500); }

Upload.

---

Display zeigt:

Batt: 11.8 V

Live.

Aktualisiert alle 500ms.

Ich ändere die Spannung am Netzteil.

12.5V.

Display: "12.3 V"

Es funktioniert!

LIVE!

---

Ich starre drauf.

Das ist ein funktionierendes Voltmeter.

Für 15€ Bauteile.

Digital.

Genau.

Live.

Selbstgebaut.

---

Ich mache ein Video.

Zeige es:

• Breadboard mit ESP32

• Display zeigt "12.3 V"

• Ich drehe am Netzteil

• Spannung ändert sich

• Display aktualisiert

• Live

---

Schicke Video an Freund.

"SCHAU MAL!"

Antwort: "WTF! Du hast das gebaut?"

"Ja!"

"In wie vielen Stunden?"

"3."

"Alter."

"Ja."

---

Ich schaue auf die Uhr.

23:15 Uhr.

Ich habe seit 20:00 Uhr gebastelt.

3 Stunden.

5 Videos geschaut.

Code geschrieben (abgetippt).

Hardware aufgebaut.

Funktionierendes Voltmeter erstellt.

---

Für's Boot:

Statt 120€ fertiges Voltmeter.

Habe ich jetzt:

15€ DIY-Voltmeter.

Das ich VERSTEHE.

Das ich ANPASSEN kann.

Das MEINS ist.

---

Buster steht auf.

Streckt sich.

Tapst zum Schreibtisch.

Schnüffelt am Breadboard. Hab ich.

Breadboard. Hab ich.

Kabel-Chaos.

"Buster, NEIN. Das ist Technik."

Er schaut mich an.

"Ja!"

---

Ich zeige.

Ich zeige ihm das Display.

"Schau mal, Buster. 12.3 Volt!"

Er gähnt.

Geht zurück ins Körbchen.

Hunde sind harte Kritiker.

Aber egal.

ICH bin beeindruckt.

Und das zählt.

Buster schnarcht schon wieder.

Ich schaue auf die Uhr.

1:15 Uhr.

Buster hat recht.

Es ist spät.

Aber: Das Display zeigt echte Werte.

---

Ich bleibe auf.

Noch eine Stunde.

Noch ein Video.

"ESP32 WiFi Webserver"

---

Code:

ESP32 erstellt Webserver.

Im WiFi.

Man geht auf IP-Adresse.

Sieht Webseite.

Mit Daten.

Live.

---

Das bedeutet:

Boot-Daten.

Über WiFi.

Auf dem Handy.

Tablet.

Laptop.

Überall.

---

Der Gedanke explodiert.

Nicht nur Display im Boot.

Sondern:

Dashboard auf dem Handy!

Von überall!

Mit WiFi!

---

Ich notiere:

Projekt-Ideen: ✅ Voltmeter (funktioniert!) ☐ Tankanzeige (Ultraschall) ☐ Temperaturen (DS18B20) ☐ WiFi Dashboard ☐ Daten-Logging ☐ Alarme bei niedrigem Akku ☐ ...

Die Liste wächst.

Schnell.

---

1:00 Uhr nachts.

Ich gehe ins Bett.

Aber schlafe nicht.

Kopf voll.

Ideen.

Möglichkeiten.

---

ESP32 kann:

• Spannung messen ✅

• Display ansteuern ✅

• WiFi ✅

• Sensoren auslesen

• Daten speichern

• Webserver hosten

• MQTT

• SignalK

• Alles

Kein Budget-Stress.

---

Das Boot hat:

• Nutzloses Voltmeter

• Lügende Tankuhr

• Keine Temperaturen

• Keine Daten

• Nichts

Aber könnte haben:

• Alles.

Mit ESP32.

Und Code.

Und mir.

---

Ich schlafe ein.

Träume von Dashboards.

Displays.

Daten.

Einem Boot, das WEISS was es tut.

Nicht rät.

---

Nächster Tag.

Samstag.

Ich stehe auf.

Erste Gedanke:

"Ins Boot. Testen. JETZT."

---

Breadboard einpacken.

ESP32.

Display.

Widerstände.

Kabel.

Netzteil.

Laptop.

Alles.

---

Ab zum Boot.

Motor starten.

Läuft.

Natürlich.

Der Motor kümmert sich nicht um meine Pläne.

Läuft einfach.

Wie immer.

---

Ich baue auf.

Im Cockpit.

Breadboard auf den Tisch.

ESP32 an USB Powerbank.

Spannungsteiler an die Batterie.

Direkt.

Ohne Sicherung.

Ohne Schalter.

Ohne dazwischen.

Direkt.

---

Display einschalten.

Code laufen lassen.

Warten.

---

Display zeigt:

"Batt:

12.4 V"

Bordvoltmeter zeigt:

"12.0 V"

Mein Multimeter zeigt:

12.4V.

---

Mein ESP32 liegt RICHTIG!

Das Bord-Voltmeter LÜGT!

Beweis erbracht!

---

Motor an.

Lichtmaschine lädt.

Display:

"Batt:

14.2 V"

Bordvoltmeter:

"12.0 V"

Ignoriert komplett, dass geladen wird.

---

Mein ESP32:

Zeigt es.

Live.

Genau.

14.2V.

Laden läuft.

Perfekt.

---

Ich sitze da.

Grinse.

Wie ein Idiot.

Habe gerade mein erstes Boot-Projekt realisiert.

In 24 Stunden.

Von Idee zu funktionierendem Prototyp.

---

Das ist...

Das ist der Moment.

Der "Ich kann das!"-Moment.

Der "Das wird real!"-Moment.

Der "Jetzt gibt's kein Zurück mehr"-Moment.

---

Ich mache Fotos.

Breadboard im Boot.

Display zeigt 14.2V.

Bord-Voltmeter zeigt 12.0V.

Der Kontrast.

Alt vs. Neu.

1989 vs. 2025.

---

Ich weiß:

Das ist erst der Anfang.

Voltmeter ist simpel.

Tankanzeige kommt.

Temperaturen kommen.

Dashboard kommt.

WiFi kommt.

Alles kommt.

---

Aber heute:

Heute habe ich bewiesen:

Ich kann das.

Mit 8€ Hardware.

3 Stunden YouTube.

Und dem Willen, es besser zu machen.

---

Der Motor läuft.

Wie immer.

Kümmert sich nicht um ESP32.

Kümmert sich nicht um Displays.

Läuft einfach.

Zuverlässig.

Seit 1989.

---

Aber der Rest?

Der Rest wird jetzt digital.

Modern.

Messbar.

Verstehbar.

---

Ich packe ein.

Breadboard mitnehmen.

Zu Hause weiterentwickeln.

Dann: Richtig einbauen.

Fest.

Dauerhaft.

Im Boot.

---

Der erste Winter brachte Frustration.

Der Frühling brachte die Lösung.

Der Sommer wird die Umsetzung.

---

Ich fahre nach Hause.

Breadboard neben mir.

Display aus.

Aber in meinem Kopf:

Läuft es weiter.

Zeigt Daten.

Spannung.

Temperatur.

Tank.

Alles.

---

Das nächste Projekt:

LED-Beleuchtung im Boot.

Richtig.

Mit Schalter.

Dimmbar vielleicht?

---

Wie schwer kann das sein?

(Spoiler: Rauch kommt.)

Aber das kommt später.

Erstmal: Genießen.

Den Erfolg.

Das funktionierende Voltmeter.

Den Beweis:

Ich kann das.

---

---
