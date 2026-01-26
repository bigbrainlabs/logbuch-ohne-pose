# Band 3: Sensor-System - Alle 3 Boards

**Komplette Hardware-Dokumentation für KiCad / Target!3001**

---

## 📦 PROJEKT-ÜBERSICHT:

**3 Boards bilden das komplette Sensor-System:**

```
POWERBOARD          SENSORBOARD         MAINBOARD
──────────          ───────────         ─────────
USB-C 5V    ──5V──→ 6× Sensoren ──8×──→ ESP32
    │                                    ├─ 2× ADS1115
    └─3.3V──────────────────────────────├─ GY-521
                                         └─ Flowsensor
```

---

## 📂 DATEIEN:

```
kicad-projects/
├── README.md                    ← Diese Datei
│
├── powerboard/
│   ├── SCHEMATIC.md             ✅ Schaltplan-Beschreibung
│   └── (KiCad/Target!3001 Files)
│
├── sensorboard/
│   ├── SCHEMATIC.md             ✅ Schaltplan-Beschreibung
│   └── (KiCad/Target!3001 Files)
│
└── mainboard/
    ├── SCHEMATIC.md             ✅ Schaltplan-Beschreibung
    └── (KiCad/Target!3001 Files)
```

---

## 🎯 BOARD 1: POWERBOARD

**Funktion:** USB 5V → 3.3V + Stromverteilung

### **Komponenten:**
- USB-C Buchse (5V Input)
- AMS1117-3.3 (LDO Regler)
- 4× Kondensatoren (Stabilisierung)
- 3× Schraubklemmen (Outputs)

### **Outputs:**
- 5V → Sensorboard (max. 1.5A)
- 3.3V → Mainboard (max. 800mA)
- GND → Common

### **PCB Größe:** 50×40 mm

### **Kosten:** ~3€

➡️ [Detaillierter Schaltplan](powerboard/SCHEMATIC.md)

---

## 🎯 BOARD 2: SENSORBOARD

**Funktion:** 6× Sensoreingänge + Signal-Konditionierung

### **Sensoren:**
1. **Starterbatterie** (12V → Spannungsteiler → 3.8V)
2. **Verbraucherbatterie** (12V → Spannungsteiler → 3.8V)
3. **Tank** (VDO 10-180Ω → Shunt → 1.8-4.5V)
4. **Öldruck** (VDO 10-180Ω → Shunt → 1.8-4.5V)
5. **Motor-Temp** (VDO 10-180Ω → Shunt → 1.8-4.5V)
6. **Drehzahl** (W-Terminal AC → Optokoppler → Digital)

### **Komponenten:**
- 6× Schraubklemmen (Sensoreingänge)
- Spannungsteiler (100kΩ + 47kΩ)
- Shunt-Widerstände (100Ω für VDO)
- PC817 Optokoppler (Drehzahl)
- 8-pol Output (zu Mainboard)

### **PCB Größe:** 80×60 mm

### **Kosten:** ~4€

➡️ [Detaillierter Schaltplan](sensorboard/SCHEMATIC.md)

---

## 🎯 BOARD 3: MAINBOARD

**Funktion:** ESP32 + ADCs + Sensoren → MQTT

### **Komponenten:**
- ESP32 WROOM-32 DevKit
- 2× ADS1115 (16-bit ADC, I2C)
  - #1: 0x48 (4× Sensoren vom Sensorboard)
  - #2: 0x49 (Motor-Temp + 3× Reserve)
- GY-521 (MPU6050, Pitch/Roll/Yaw)
- Flowsensor-Eingang (GPIO4)
- I2C Pull-ups (4.7kΩ)

### **I2C Adressen:**
- ADS1115 #1: 0x48
- ADS1115 #2: 0x49
- GY-521 (MPU6050): 0x68

### **GPIO Mapping:**
- GPIO21: I2C SDA
- GPIO22: I2C SCL
- GPIO25: Drehzahl (digital)
- GPIO4: Flowsensor (digital)

### **PCB Größe:** 100×80 mm

### **Kosten:** ~18€

➡️ [Detaillierter Schaltplan](mainboard/SCHEMATIC.md)

---

## 💰 GESAMTKOSTEN:

```
Powerboard:      ~3€
Sensorboard:     ~4€
Mainboard:      ~18€
───────────────────
Komponenten:    ~25€

+ PCBs (JLCPCB):
  3× Boards je 5 Stück = ~30€

+ Kabel, Gehäuse, etc: ~20€
───────────────────────
GESAMT:         ~75€
```

**vs. Raymarine System: 2.000€+**  
**Ersparnis: 1.925€! 💰**

---

## 🔧 FÜR TARGET!3001 NUTZER:

### **Was du machen musst:**

1. ✅ **Schaltpläne lesen:**
   - `powerboard/SCHEMATIC.md`
   - `sensorboard/SCHEMATIC.md`
   - `mainboard/SCHEMATIC.md`

2. ✅ **In Target!3001 nachbauen:**
   - Alle Komponenten platzieren
   - Verbindungen wie beschrieben
   - Netze benennen (wichtig!)

3. ✅ **PCB Layout erstellen:**
   - Komponenten optimal platzieren
   - Routen (siehe Layout-Vorschläge!)
   - Ground Plane nicht vergessen!
   - DRC durchführen

4. ✅ **Ätzen:**
   - Gerber exportieren (für Service)
   - ODER direkt aus Target!3001 drucken
   - Belichten, ätzen, bohren
   - Optional: Lötstopplack

5. ✅ **Löten & Testen:**
   - Board für Board aufbauen
   - Einzeln testen!
   - Erst wenn alle funktionieren: Verbinden

---

## 🎯 FÜR KICAD NUTZER:

**Du kannst die Projekte auch in KiCad erstellen:**

1. KiCad installieren (kicad.org)
2. Schaltpläne öffnen (*.SCHEMATIC.md)
3. In KiCad nachbauen:
   - Schematic Editor
   - Komponenten platzieren
   - Verbinden wie beschrieben
4. PCB Layout erstellen
5. Gerber exportieren
6. Zu JLCPCB hochladen!

---

## 📐 WICHTIGE DESIGN-REGELN:

### **Allgemein:**
- GND als große Ground Plane!
- Kondensatoren NAH an ICs
- Kurze I2C-Leitungen (<30cm)
- Pull-ups am Master (ESP32)

### **Trace-Breiten:**
```
Power (12V, 5V, 3.3V): 1.0mm
I2C (SDA, SCL):        0.5mm
Signale:               0.3mm
GND: Ground Plane
```

### **Via-Größen:**
```
Durchmesser: 0.8mm
Bohrung:     0.4mm
```

### **Clearance:**
```
Trace-to-Trace:  0.3mm
Trace-to-Pad:    0.3mm
Pad-to-Pad:      0.3mm
```

---

## 🔌 VERBINDUNGEN ZWISCHEN BOARDS:

### **Powerboard → Sensorboard:**
```
Kabel: 2-adrig (5V + GND)
Länge: ~20cm
Querschnitt: 0.5mm² min.
```

### **Powerboard → Mainboard:**
```
Kabel: 2-adrig (3.3V + GND)
Länge: ~20cm
Querschnitt: 0.5mm² min.
```

### **Sensorboard → Mainboard:**
```
Kabel: 8-adrig (6× Signal + 5V + GND)
Länge: ~30cm
Querschnitt: 0.25mm² (Signal)
Typ: Flachbandkabel ODER
     8-pol Stecker/Buchse
```

---

## 🎊 REIHENFOLGE BEIM BAU:

**Empfohlen:**

### **1. Powerboard zuerst:**
```
✅ Einfachste!
✅ Löten
✅ Testen: 3.3V Output OK?
✅ Wenn ja → weiter!
```

### **2. Mainboard als zweites:**
```
✅ ESP32 + Module auflöten
✅ Mit Powerboard verbinden
✅ Code flashen (Test-Sketch)
✅ I2C Scanner laufen lassen
✅ Alle 3 I2C-Devices gefunden? ✅
```

### **3. Sensorboard als letztes:**
```
✅ Spannungsteiler löten
✅ Optokoppler testen
✅ Mit Mainboard verbinden
✅ Test-Signale anlegen
✅ ADC-Werte prüfen
```

### **4. Integration:**
```
✅ Alle 3 Boards verbinden
✅ Sensoren anschließen
✅ Kompletten Code flashen
✅ MQTT Topics prüfen
✅ Im Boot verbauen! 🚤
```

---

## 📊 MQTT TOPICS (zur Erinnerung):

```
boat/sensors/battery/starter/voltage       (V)
boat/sensors/battery/house/voltage         (V)
boat/sensors/tank/diesel/level             (%)
boat/sensors/engine/oil_pressure           (bar)
boat/sensors/engine/temperature            (°C)
boat/sensors/engine/rpm                    (U/min)
boat/sensors/engine/fuel_flow              (L/h)
boat/sensors/motion/pitch                  (°)
boat/sensors/motion/roll                   (°)
boat/sensors/motion/yaw                    (°)
```

---

## 🎯 TESTING-CHECKLISTE:

### **Powerboard:**
```
□ USB-C anschließen
□ 5V Output messen: 5.0V ±0.1V?
□ 3.3V Output messen: 3.3V ±0.05V?
□ Last-Test: 500mA @ 3.3V OK?
```

### **Sensorboard:**
```
□ 5V anlegen
□ Spannungsteiler testen (Multimeter)
□ Optokoppler testen (LED leuchtet?)
□ Alle 6 Ausgänge OK?
```

### **Mainboard:**
```
□ 3.3V anlegen
□ ESP32 startet?
□ I2C Scanner: 3 Devices @ 0x48, 0x49, 0x68?
□ ADS1115 liest Werte?
□ GY-521 liefert Daten?
□ GPIO4 zählt Impulse?
```

### **Integration:**
```
□ Alle Boards verbunden
□ Keine Kurzschlüsse?
□ Alle Spannungen OK?
□ MQTT Daten kommen an?
□ Alle Sensoren funktionieren?
```

---

## 🚀 NÄCHSTE SCHRITTE:

**Jetzt:**
1. ✅ Schaltpläne lesen (alle 3!)
2. ✅ Verstehen wie's funktioniert
3. ✅ Teile bestellen

**Dann:**
1. ⏳ In Target!3001 nachbauen
2. ⏳ PCB Layouts erstellen
3. ⏳ Ätzen (oder bestellen)
4. ⏳ Löten
5. ⏳ Testen
6. ⏳ Im Boot verbauen!

---

## 📸 PHOTOS (später):

**Nach dem Bau bitte Photos machen:**

```
photos/
├── powerboard-top.jpg
├── powerboard-assembled.jpg
├── sensorboard-top.jpg
├── sensorboard-assembled.jpg
├── mainboard-top.jpg
├── mainboard-assembled.jpg
├── all-three-connected.jpg
└── installed-in-boat.jpg
```

**Für's Buch & GitHub! 📚**

---

## 🎊 CREDITS:

**Design:** Maik (bigbrainlabs)  
**Projekt:** Logbuch ohne Pose - Band 3  
**GitHub:** github.com/bigbrainlabs/logbuch-ohne-pose  
**Lizenz:** MIT License  

---

## 💡 SUPPORT:

**Fragen? Probleme?**

- GitHub Issues
- Discussions
- Oder: Foto vom Problem schicken! 😊

---

**VIEL ERFOLG BEIM BAU! 🔧⚓**

*"Von Schaltplan zu PCB. Von Lochraster zu professionell. WEIL ICH'S KANN!"* 🚀

---

**Das ist das komplette 3-Board Sensor-System! 🎉**
