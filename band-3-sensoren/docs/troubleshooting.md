# Troubleshooting Guide - Boot-Monitoring System

**Häufige Probleme und ihre Lösungen**

---

## 🔴 Hardware-Probleme

### **Problem: I2C-Scanner findet nur 1 Gerät statt 3**

**Symptom:**
```
I2C Scanner
Device at 0x48
```

**Ursache:** ADDR Pin von ADS1115 #2 nicht verbunden oder falsch

**Lösung:**
```
1. Multimeter: ADS #2 ADDR Pin messen
   - Sollte 3.3V sein (VDD)
   - Ist GND? → ADDR Pin umlo

̈ten auf VDD!

2. Visuell prüfen:
   ADS #1: ADDR Pin → GND gelötet
   ADS #2: ADDR Pin → VDD gelötet ✓
```

**Check:**
```arduino
Wire.beginTransmission(0x49);
if(Wire.endTransmission() == 0) {
  Serial.println("0x49 found!");
}
```

---

### **Problem: MPU6050 wird nicht gefunden (0x68 fehlt)**

**Symptom:**
```
✗ MPU6050 NOT found!
```

**Ursachen & Lösungen:**

**1. Stromversorgung:**
```
Multimeter: VCC Pin am MPU6050
- Sollte: 3.25-3.35V
- Ist 0V? → VCC nicht verbunden!
- Ist >3.5V? → Falsche Spannung (5V statt 3.3V!)
```

**2. I2C Verkabelung:**
```
Durchgangsprüfung:
ESP32 GPIO21 → MPU SDA (should beep)
ESP32 GPIO22 → MPU SCL (should beep)
```

**3. AD0 Pin:**
```
MPU6050 AD0 Pin sollte auf GND oder offen sein
Adresse = 0x68 (wenn GND)
Adresse = 0x69 (wenn VDD)

Falls 0x69 gefunden:
→ AD0 Pin ist auf VDD, auf GND umlöten
```

---

### **Problem: ESP32 bootet nicht / keine serielle Ausgabe**

**Symptom:** Schwarzes Serial Monitor Fenster

**Lösungen:**

**1. Baud-Rate prüfen:**
```
Serial Monitor auf 115200 Baud einstellen
```

**2. USB-Kabel:**
```
Manche Kabel sind nur zum Laden!
→ Anderes Kabel probieren (mit Datenleitungen)
```

**3. Treiber:**
```
Windows: CH340 oder CP2102 Treiber installieren
macOS: Meist automatisch
Linux: Meist automatisch
```

**4. Boot-Modus:**
```
Boot-Button beim Einstecken gedrückt halten
→ ESP32 sollte in Download-Modus booten
```

---

### **Problem: Spannungen am ADC sind falsch**

**Symptom:** 
```
Batterie zeigt 8V statt 12V
oder: Batterie zeigt 18V statt 12V
```

**Ursache:** Spannungsteiler falsch dimensioniert

**Check:**
```
Mit 12V Testspannung:
Multimeter am Abgriffpunkt messen

Sollte sein (12V Input):
10kΩ / (10kΩ + 4.7kΩ) × 12V = 8.16V

Falls nicht:
→ Widerstände vertauscht!
→ Mit Multimeter Widerstandswerte prüfen
```

**Korrektur:**
```
10kΩ muss auf der High-Side (zur Batterie)
4.7kΩ muss auf der Low-Side (zu GND)

RICHTIG:
12V → 10kΩ → [Abgriff 8.16V] → 4.7kΩ → GND

FALSCH:
12V → 4.7kΩ → [Abgriff 3.84V] → 10kΩ → GND
```

---

### **Problem: 100nF Kondensatoren falsch platziert**

**Symptom:** Rauschen auf ADC-Messungen, instabile Werte

**Ursache:** Kondensatoren in Serie statt parallel

**RICHTIG:**
```
Signal ─┬─ ADC
        │
      100nF ← PARALLEL!
        │
       GND
```

**FALSCH:**
```
Signal ── 100nF ── ADC  ← SERIE (wirkt als Filter)
```

**Korrektur:** Kondensator umlöten (zwischen Signal und GND)

---

### **Problem: Power Board wird heiß**

**Symptom:** AMS1117 Regler sehr warm (>60°C)

**Normal?**
```
Leicht warm (30-40°C): OK
Heiß (>60°C): Problem!
Sehr heiß (>80°C): Sofort abschalten!
```

**Ursachen:**

**1. Zu viel Strom:**
```
AMS1117 max. 800mA
Wenn >800mA → überlastet!

Check: Strom messen
- ESP32 + ADS + MPU = ~200mA
- Falls >500mA: Kurzschluss suchen!
```

**2. Zu hohe Eingangsspannung:**
```
AMS1117 max. 15V Input
Bei 12V: OK
Bei >15V: überlastet!

Lösung: Buck Converter auf 5V einstellen (nicht 12V!)
```

**3. Kein Kühlkörper:**
```
Bei >400mA Last: Kühlkörper empfohlen
Kleine TO-220 Kühlkörper ~1€
Mit Wärmeleitpaste montieren
```

---

## 🟡 Software-Probleme

### **Problem: Bootloop beim Start**

**Symptom:**
```
ESP32 bootet
ESP32 bootet
ESP32 bootet
...
```

**Ursache:** Watchdog resettet zu früh (vor WiFi-Setup)

**Lösung:** Code v1.1 verwenden (Watchdog startet NACH WiFi)

**Temporäre Lösung:**
```arduino
// In setup():
// esp_task_wdt_init(...);  // Auskommentieren
```

---

### **Problem: Captive Portal öffnet sich nicht**

**Symptome:**
- AP "BootMonitor-Setup" ist da
- Verbindung funktioniert
- Aber: Keine Webseite öffnet

**Lösungen:**

**1. Manuell URL eingeben:**
```
http://192.168.4.1
```

**2. Browser-Trick:**
```
Versuche zu öffnen:
http://1.1.1.1
http://8.8.8.8
http://google.com

→ WiFiManager fängt Request ab und zeigt Portal
```

**3. Gerät wechseln:**
```
iPhone mit Private Relay: AUS schalten
Android: Meist problemlos
Windows: Firewall temporär aus
```

**4. Factory Reset:**
```
Boot-Button 3s beim Start gedrückt halten
→ Settings werden gelöscht
→ AP startet neu
```

---

### **Problem: WiFi verbindet nicht**

**Symptom:**
```
*wm:Connecting to saved AP
*wm:Connection Failed
```

**Lösungen:**

**1. SSID/Passwort falsch:**
```
Factory Reset machen
Neu konfigurieren (Tippfehler vermeiden!)
```

**2. WiFi zu schwach:**
```
ESP32 näher an Router
oder: Bessere Antenne
```

**3. 5GHz statt 2.4GHz:**
```
ESP32 kann nur 2.4GHz!
Router auf 2.4GHz prüfen
```

---

### **Problem: MQTT verbindet nicht**

**Symptom:**
```
Connecting to MQTT... failed!
```

**Lösungen:**

**1. Broker läuft nicht:**
```bash
# Auf Raspberry Pi:
sudo systemctl status mosquitto

# Sollte zeigen:
Active: active (running)

# Falls nicht:
sudo systemctl start mosquitto
```

**2. Falsche IP:**
```
Ping testen:
ping 192.168.1.100

Sollte antworten.
Falls nicht: IP im Captive Portal korrigieren
```

**3. Port falsch:**
```
Standard MQTT Port: 1883
Falls geändert: in Config anpassen
```

**4. Firewall:**
```bash
# Raspberry Pi Firewall prüfen:
sudo ufw status

# Port 1883 öffnen:
sudo ufw allow 1883/tcp
```

---

### **Problem: MQTT zeigt 0.00 für alle Werte**

**Symptom:**
```
boot/sensoren/motor/drehzahl 0.00
boot/sensoren/tank/diesel/prozent 0.00
boot/sensoren/motor/oeldruck 0.00
```

**Aber:**
```
boot/sensoren/batterie/starter 12.50  ← funktioniert
boot/sensoren/lage/neigung 2.34       ← funktioniert
```

**Ursache:** Meist temporär beim Start (erste Werte)

**Lösung:** 1-2 Minuten warten, dann kommen echte Werte

**Falls nach 5 Minuten noch 0.00:**
```
Serial Monitor checken:
- Werden Werte angezeigt?
- sensorsOK = true?

Falls sensorsOK = false:
→ ADS1115 oder MPU6050 nicht gefunden
→ I2C-Scanner laufen lassen
```

---

### **Problem: VDO Sensoren zeigen falsche Werte**

**Symptom:**
```
Tank leer aber zeigt 80%
oder: Tank voll aber zeigt 20%
```

**Ursache:** Kennlinien nicht kalibriert

**Lösung:** Siehe [Kalibrierung](../kalibrierung/vdo-kennlinien.md)

**Quick-Check:**
```
1. Sensor abklemmen (offener Eingang)
   → Tank sollte 0% zeigen (240Ω = leer)

2. Sensor kurzschließen (0Ω)
   → Tank sollte 100% zeigen (33Ω = voll)

Falls umgekehrt:
→ Kennlinie im Code invertieren!
```

---

## 🟢 System-Probleme

### **Problem: Dashboard zeigt keine Daten**

**Check-Liste:**

**1. MQTT Sub Test:**
```bash
mosquitto_sub -h localhost -t 'boot/#' -v
```
Kommen Daten? Ja → MQTT OK, Problem ist Dashboard
Nein → Problem ist ESP32/MQTT

**2. Node-RED läuft?**
```bash
sudo systemctl status nodered
```

**3. MQTT Nodes konfiguriert?**
```
Node-RED UI → MQTT In Nodes
Server: localhost:1883
Topic: boot/#
```

**4. Dashboard deployed?**
```
Rechts oben: "Deploy" klicken!
```

---

### **Problem: Werte flackern / springen**

**Symptom:** RPM springt zwischen 800-2000 wild hin und her

**Ursachen:**

**1. Schlechte Verkabelung:**
```
Wackelkontakt im Stecker
→ Schraubklemmen nachziehen!
```

**2. Elektrisches Rauschen:**
```
Motor/Lichtmaschine erzeugt Störungen
→ 10µF Kondensator am RPM Eingang prüfen
→ Evtl. größer (47µF oder 100µF)
```

**3. Software-Filter:**
```arduino
// Im Code: Moving Average hinzufügen
float rpmFiltered = 0.9 * rpmFiltered + 0.1 * rpmRaw;
```

---

### **Problem: System hängt sich auf**

**Symptom:** ESP32 reagiert nicht mehr, keine MQTT Daten

**Watchdog sollte resetten:**
```
Nach 10 Sekunden automatischer Neustart
Falls nicht: Watchdog deaktiviert?
```

**Manueller Reset:**
```
ESP32 Reset-Button drücken
oder: Strom aus/ein
```

**Debug:**
```
Serial Monitor anschauen:
Wo hängt es?
- Beim WiFi Connect?
- Beim MQTT Connect?
- Bei Sensor-Lesung?
```

---

### **Problem: Nach OTA-Update bootet ESP32 nicht mehr**

**Symptom:** Nach OTA Upload keine Reaktion

**Lösungen:**

**1. Warten:**
```
OTA braucht 30-60 Sekunden
Geduld!
```

**2. Power-Cycle:**
```
Strom aus
10 Sekunden warten
Strom an
```

**3. USB Re-Flash:**
```
Letzte funktionierende Version per USB hochladen
OTA-Update nochmal versuchen
```

---

## 📊 Messwert-Probleme

### **Problem: Batterien zeigen immer 12.8V (konstant)**

**Ursache:** Spannungsteiler nicht verbunden

**Check:**
```
1. Batterie-Plus wirklich angeschlossen?
2. Spannungsteiler-Ausgang am ADC?
3. ADC konfiguriert für Kanal A0/A1?
```

---

### **Problem: Pitch/Roll zeigen unsinnige Werte**

**Symptom:** Neigung 87° obwohl Boot flach liegt

**Ursachen:**

**1. MPU6050 falsch montiert:**
```
Chip-Seite sollte nach oben zeigen
Pfeil auf Breakout zeigt Richtung "vorne"
```

**2. Koordinaten vertauscht:**
```arduino
// Im Code prüfen:
pitch = atan2(a.acceleration.x, ...);
roll = atan2(a.acceleration.y, ...);

// Evtl. x/y vertauschen
```

**3. Offset kalibrieren:**
```arduino
// Boot flach legen, dann:
pitchOffset = -measuredPitch;
rollOffset = -measuredRoll;

// In Code eintragen
```

---

## 🆘 Notfall-Kommandos

### **Factory Reset (Settings löschen):**
```
Boot-Button 3s beim ESP32-Start gedrückt halten
→ WiFi + MQTT Settings werden gelöscht
→ AP "BootMonitor-Setup" startet
```

### **Serial Monitor Debug:**
```
Tools → Serial Monitor → 115200 Baud
→ Alle Meldungen live sehen
```

### **I2C-Scanner:**
```arduino
// Separate Sketch hochladen
// Zeigt alle I2C Geräte

#include <Wire.h>
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
}
void loop() {
  for(byte i = 1; i < 127; i++) {
    Wire.beginTransmission(i);
    if(Wire.endTransmission() == 0) {
      Serial.printf("0x%02X\n", i);
    }
  }
  delay(5000);
}
```

### **MQTT Test (ohne ESP32):**
```bash
# Raspberry Pi:
# Publish Test
mosquitto_pub -h localhost -t 'test/topic' -m 'hello'

# Subscribe Test
mosquitto_sub -h localhost -t 'test/#' -v

# Sollte "hello" anzeigen
```

---

## 📞 Weitere Hilfe

**GitHub Issues:**
→ [Issues öffnen](https://github.com/.../issues)

**Community:**
→ [Discussions](https://github.com/.../discussions)

**Dokumentation:**
→ [Installation Guide](installation.md)
→ [BOM](../hardware/bom.md)
→ [Schaltpläne](../hardware/schaltplaene/)

---

**Häufigste Probleme nach Kategorie:**

| Problem | Häufigkeit | Schwierigkeit | Zeitaufwand |
|---------|------------|---------------|-------------|
| ADDR Pin vergessen | ⭐⭐⭐⭐⭐ | Leicht | 5 Min |
| 100nF in Serie | ⭐⭐⭐⭐ | Mittel | 15 Min |
| WiFi Connect Timeout | ⭐⭐⭐ | Leicht | 5 Min |
| Captive Portal öffnet nicht | ⭐⭐⭐ | Leicht | 2 Min |
| VDO falsche Werte | ⭐⭐ | Mittel | 30 Min |
| MPU6050 nicht gefunden | ⭐⭐ | Leicht | 10 Min |
| Bootloop | ⭐ | Leicht | 2 Min |

**90% der Probleme sind: ADDR Pin oder 100nF!** 😄
