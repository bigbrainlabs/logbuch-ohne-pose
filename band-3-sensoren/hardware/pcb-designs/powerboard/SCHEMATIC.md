# Powerboard - Schaltplan Beschreibung

**USB 5V → 3.3V Stromversorgung + Verteilung**

---

## 📐 KOMPONENTEN:

```
J1: USB-C Buchse (5V Input)
U1: AMS1117-3.3 (LDO Regler 5V → 3.3V)
C1: 10µF Elko (Eingang)
C2: 10µF Elko (Ausgang)
C3: 100nF Kerko (Eingang)
C4: 100nF Kerko (Ausgang)
J2: Schraubklemme 2-pol (5V Out → Sensorboard)
J3: Schraubklemme 2-pol (3.3V Out → Mainboard)
J4: Schraubklemme 2-pol (GND Out)
```

---

## 🔌 SCHALTPLAN:

```
USB-C (J1)
│
├─ VBUS (5V) ─┬─ C1 (10µF) ─┬─ C3 (100nF) ─┬─ U1 (AMS1117) IN
│             │             │               │
│             │             └─ GND          │
│             │                             │
│             └─ J2+ (5V Out)               │
│                                           │
│                                           ├─ U1 OUT ─┬─ C2 (10µF) ─┬─ C4 (100nF) ─┬─ J3+ (3.3V Out)
│                                           │          │             │               │
│                                           │          └─ GND        └─ GND          │
│                                           │                                        │
└─ GND ────────────────────────────────────┴────────────────────────────────────────┴─ J4 (GND Out)
```

---

## 📊 PINOUT:

### **J1 (USB-C):**
```
Pin 1: VBUS (5V)
Pin 2: GND
```

### **J2 (5V Out → Sensorboard):**
```
Pin 1: +5V
Pin 2: GND
```

### **J3 (3.3V Out → Mainboard):**
```
Pin 1: +3.3V
Pin 2: GND
```

### **J4 (GND Common):**
```
Pin 1: GND
Pin 2: GND
```

---

## ⚡ SPEZIFIKATIONEN:

**Input:**
- USB-C 5V
- Max. Strom: 2A (USB-Limit)

**Output:**
- 5V: max. 1.5A (für Sensorboard)
- 3.3V: max. 800mA (AMS1117 Limit)

**AMS1117-3.3:**
- Dropout: 1.3V typ.
- Quiescent Current: 5mA
- Output Voltage: 3.3V ±2%
- Max Output Current: 800mA

---

## 🔧 BOM:

| Ref | Komponente | Wert | Gehäuse | Anzahl | Preis |
|-----|------------|------|---------|--------|-------|
| J1 | USB-C Buchse | - | THT | 1 | 1€ |
| U1 | AMS1117-3.3 | 3.3V | SOT-223 | 1 | 0.50€ |
| C1, C2 | Elko | 10µF/16V | 5mm | 2 | 0.20€ |
| C3, C4 | Kerko | 100nF | 0805 | 2 | 0.10€ |
| J2, J3, J4 | Schraubklemme | 2-pol | 5mm | 3 | 1€ |
| | | | | **Total** | **~3€** |

---

## 📐 PCB LAYOUT:

**Größe:** 50×40 mm

```
┌──────────────────────────┐
│                          │
│  [J1]                    │  ← USB-C (links)
│  USB-C                   │
│                          │
│  [C1] [C3]               │
│                          │
│  [U1 AMS1117]            │  ← Mitte
│                          │
│  [C2] [C4]               │
│                          │
│  [J2]  [J3]  [J4]        │  ← Schraubklemmen (unten)
│  5V    3.3V  GND         │
│                          │
└──────────────────────────┘
```

---

## 💡 DESIGN NOTES:

**Wichtig:**
- Kondensatoren NAH am AMS1117!
- Elkos für Stabilität
- Kerkos für HF-Störungen
- GND-Plane großflächig!
- 5V Trace: 1.0mm breit
- 3.3V Trace: 0.8mm breit

**Kühlkörper:**
- AMS1117 wird warm bei Last!
- PCB als Kühlkörper (große GND-Fläche unter U1)
- Optional: kleiner Kühlkörper

---

## 🎯 VERWENDUNG:

```
1. USB-C Kabel anschließen (5V/2A Netzteil)
2. 5V Out → Sensorboard (J2)
3. 3.3V Out → Mainboard (J3)
4. GND gemeinsam (J4)
```

**Fertig! ✅**
