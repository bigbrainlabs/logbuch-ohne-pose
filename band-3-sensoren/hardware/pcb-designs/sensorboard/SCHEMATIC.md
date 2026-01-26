# Sensorboard - Schaltplan Beschreibung

**6× Sensoreingänge mit Spannungsteilern**

---

## 📐 KOMPONENTEN:

```
J1: Power Input (5V + GND vom Powerboard)
J2-J7: Schraubklemmen 2-pol (6× Sensoreingänge)
R1-R6: Widerstände 100kΩ (oberer Spannungsteiler)
R7-R12: Widerstände 47kΩ (unterer Spannungsteiler)
J8: Output Stecker 8-pol (Signale zum Mainboard)
```

---

## 🔌 SENSOREINGÄNGE:

### **J2: Starterbatterie (12V)**
```
Pin 1: +12V (Batterie)
Pin 2: GND

Signal-Konditionierung:
+12V ─ R1 (100k) ─┬─ Out1 ─ zu ADS1115 A0
                  │
                  └─ R7 (47k) ─ GND

Spannungsteiler: 12V → ~3.8V
```

### **J3: Verbraucherbatterie (12V)**
```
Pin 1: +12V (Batterie)
Pin 2: GND

Signal-Konditionierung:
+12V ─ R2 (100k) ─┬─ Out2 ─ zu ADS1115 A1
                  │
                  └─ R8 (47k) ─ GND

Spannungsteiler: 12V → ~3.8V
```

### **J4: Tank (VDO Geber, 10-180Ω)**
```
Pin 1: +5V (Versorgung VDO)
Pin 2: Signal (variabler Widerstand)

Signal-Konditionierung:
+5V ─ VDO (10-180Ω) ─┬─ R3 (100Ω Shunt) ─ GND
                     │
                     └─ Out3 ─ zu ADS1115 A2

Shunt-Widerstand misst Spannungsabfall
→ Rückrechnung auf VDO Widerstand → Füllstand
```

### **J5: Öldruck (VDO Geber, 10-180Ω)**
```
Pin 1: +5V (Versorgung VDO)
Pin 2: Signal (variabler Widerstand)

Signal-Konditionierung:
+5V ─ VDO (10-180Ω) ─┬─ R4 (100Ω Shunt) ─ GND
                     │
                     └─ Out4 ─ zu ADS1115 A3

Spannungsabfall über Shunt
→ VDO Widerstand → Öldruck
```

### **J6: Motor-Temperatur (VDO Geber, 10-180Ω)**
```
Pin 1: +5V (Versorgung VDO)
Pin 2: Signal (variabler Widerstand)

Signal-Konditionierung:
+5V ─ VDO (10-180Ω) ─┬─ R5 (100Ω Shunt) ─ GND
                     │
                     └─ Out5 ─ zu ADS1115 A4 (2. ADS1115!)

Spannungsabfall über Shunt
→ VDO Widerstand → Temperatur
```

### **J7: Drehzahl (W-Terminal Lichtmaschine, 0-14V AC)**
```
Pin 1: W-Terminal (AC Signal)
Pin 2: GND (Lichtmaschine)

Signal-Konditionierung:
W-Terminal ─ Optokoppler (PC817) ─ Out6 ─ zu ESP32 GPIO25

WICHTIG: Galvanische Trennung!
Lichtmaschine-Masse ≠ ESP32-Masse!
```

---

## 📊 OUTPUT STECKER J8 (zu Mainboard):

**8-poliger Stecker:**

```
Pin 1: Out1 (Starterbatterie)    → ADS1115 #1 A0
Pin 2: Out2 (Verbraucherbatterie) → ADS1115 #1 A1
Pin 3: Out3 (Tank)                → ADS1115 #1 A2
Pin 4: Out4 (Öldruck)             → ADS1115 #1 A3
Pin 5: Out5 (Motor-Temp)          → ADS1115 #2 A0
Pin 6: Out6 (Drehzahl)            → ESP32 GPIO25
Pin 7: +5V                        → Power für Optokoppler
Pin 8: GND                        → Common Ground
```

---

## 🔧 SPANNUNGSTEILER BERECHNUNG:

### **Batterie-Spannungsteiler (12V → 3.8V):**
```
R1, R2 = 100kΩ
R7, R8 = 47kΩ

V_out = V_in × (R_unten / (R_oben + R_unten))
      = 12V × (47k / (100k + 47k))
      = 12V × 0.32
      = 3.84V

→ Passt perfekt in ADS1115 Messbereich (0-5V)!
```

### **VDO-Geber Shunt (10-180Ω → 0.3-0.9V):**
```
R_Shunt = 100Ω

Bei VDO = 10Ω (leer):
I = 5V / (10Ω + 100Ω) = 45mA
V_Shunt = 45mA × 100Ω = 4.5V

Bei VDO = 180Ω (voll):
I = 5V / (180Ω + 100Ω) = 18mA
V_Shunt = 18mA × 100Ω = 1.8V

→ Messbereich: 1.8V - 4.5V
→ Gut auflösbar mit 16-bit ADS1115!
```

---

## 🔧 BOM:

| Ref | Komponente | Wert | Gehäuse | Anzahl | Preis |
|-----|------------|------|---------|--------|-------|
| J1 | Schraubklemme | 2-pol | 5mm | 1 | 0.30€ |
| J2-J7 | Schraubklemme | 2-pol | 5mm | 6 | 2€ |
| J8 | Stiftleiste | 8-pol | 2.54mm | 1 | 0.50€ |
| R1, R2 | Widerstand | 100kΩ | 0805 | 2 | 0.10€ |
| R3-R5 | Widerstand | 100Ω | 0805 | 3 | 0.15€ |
| R7, R8 | Widerstand | 47kΩ | 0805 | 2 | 0.10€ |
| U1 | Optokoppler | PC817 | DIP-4 | 1 | 0.30€ |
| D1 | Diode | 1N4007 | DO-41 | 1 | 0.10€ |
| | | | | **Total** | **~4€** |

---

## 📐 PCB LAYOUT:

**Größe:** 80×60 mm

```
┌────────────────────────────────────┐
│ [J1] Power In                      │
│                                    │
│ [J2] [J3] [J4] [J5] [J6] [J7]     │  ← 6× Schraubklemmen (oben)
│ Bat1 Bat2 Tank Öl  Temp RPM       │
│                                    │
│ [R1] [R2] [R3] [R4] [R5] [PC817]  │  ← Komponenten (mitte)
│ [R7] [R8]                          │
│                                    │
│              [J8]                  │  ← 8-pol Output (unten)
│           Zum Mainboard            │
│                                    │
└────────────────────────────────────┘
```

---

## 💡 DESIGN NOTES:

**Wichtig:**
- Spannungsteiler-Widerstände NAH beieinander
- Kurze Verbindungen zu Output-Pins
- GND-Plane großflächig
- Optokoppler galvanisch getrennt!
- 12V Traces: 0.5mm (geringe Ströme)
- Signal Traces: 0.3mm

**Optokoppler-Schaltung:**
```
W-Terminal ─ D1 (1N4007) ─┐
                          ├─ PC817 LED
                          │   │
                         GND  └─ 220Ω ─ GND

PC817 Transistor:
├─ Collector ─ +5V
└─ Emitter ─ Out6 (zu GPIO25)
            └─ 10kΩ Pull-down ─ GND
```

---

## 🎯 VERWENDUNG:

```
1. Power vom Powerboard anschließen (J1: 5V + GND)
2. 6× Sensoren anschließen (J2-J7)
3. Output-Stecker (J8) zum Mainboard
```

**Fertig! ✅**

---

## 📊 SIGNAL-LEVELS:

| Sensor | Input | Output (zu ADS1115) |
|--------|-------|---------------------|
| Batterie 1 | 0-15V | 0-4.8V |
| Batterie 2 | 0-15V | 0-4.8V |
| Tank | VDO 10-180Ω | 1.8-4.5V |
| Öldruck | VDO 10-180Ω | 1.8-4.5V |
| Motor-Temp | VDO 10-180Ω | 1.8-4.5V |
| Drehzahl | 0-14V AC | 0/5V Digital |

**Alles im sicheren Bereich für ADS1115 und ESP32! ✅**
