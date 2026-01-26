# PCB Layout & Schaltpläne

**ESP32 Sensor-Boards für Band 3: Sensoren & Monitoring**

> *3 handgelötete Platinen. 8 Sensoren. 1 MQTT-Stream.*

---

## 📋 Übersicht

Dieses Projekt umfasst **3 separate PCB-Boards**, die auf **Lochraster** handgelötet werden:

1. **Board 1: Battery Monitor** (3× Batterien)
2. **Board 2: Tank & Temperature Sensors** (Diesel, Wasser, Temperaturen)
3. **Board 3: Motor Data** (Drehzahl, Öldruck, Temperatur)

Alle Boards kommunizieren via **MQTT** mit dem Raspberry Pi / BoatOS.

---

## 🎯 Warum 3 separate Boards?

**Nicht ein großes Board, sondern 3 kleine:**

✅ **Modularer Aufbau** - einzeln testbar  
✅ **Einfacher zu debuggen** - klare Trennung  
✅ **Flexibler Einbau** - passen überall hin  
✅ **Ausfall-sicher** - ein Board tot ≠ alles tot  
✅ **Schrittweise Entwicklung** - eins nach dem anderen  

---

## 📐 Board 1: Battery Monitor

**Funktion:** 3× Batterien (Starter, Verbraucher 1, Verbraucher 2) überwachen

### **Sensoren:**
- 3× Spannungsmessung (Spannungsteiler)
- 3× Strommessung (INA219 Module)

### **Komponenten:**

```
ESP32 WROOM-32 DevKit
├── 3× Spannungsteiler (100kΩ + 47kΩ)
│   ├── Batterie 1 → GPIO34 (ADC1_CH6)
│   ├── Batterie 2 → GPIO35 (ADC1_CH7)
│   └── Batterie 3 → GPIO32 (ADC1_CH4)
│
├── 3× INA219 Module (I2C)
│   ├── Adresse 0x40 (Batterie 1)
│   ├── Adresse 0x41 (Batterie 2)
│   └── Adresse 0x44 (Batterie 3)
│   └── I2C: SDA=GPIO21, SCL=GPIO22
│
└── Stromversorgung
    ├── 12V Input (Klemme)
    ├── Buck Converter → 5V
    └── AMS1117 → 3.3V für ESP32
```

### **Schaltplan (vereinfacht):**

```
Batterie 1 (12V) ─┬─ 100kΩ ─┬─ GPIO34 (ESP32)
                  │         │
                  │         └─ 47kΩ ─ GND
                  │
                  └─ INA219 (0x40) ─ I2C Bus

Batterie 2 (12V) ─┬─ 100kΩ ─┬─ GPIO35
                  │         │
                  │         └─ 47kΩ ─ GND
                  │
                  └─ INA219 (0x41) ─ I2C Bus

Batterie 3 (12V) ─┬─ 100kΩ ─┬─ GPIO32
                  │         │
                  │         └─ 47kΩ ─ GND
                  │
                  └─ INA219 (0x44) ─ I2C Bus

I2C Bus:
├── SDA (GPIO21) ─ 4.7kΩ Pull-up ─ 3.3V
└── SCL (GPIO22) ─ 4.7kΩ Pull-up ─ 3.3V
```

### **Lochraster-Layout:**

```
┌─────────────────────────────────────┐
│  [ESP32 DevKit]                     │
│   │││││││││││││││││││││││││││││││   │
│                                     │
│  [100k] [47k]  [100k] [47k]  [100k]│
│    │     │       │     │       │   │
│  Bat1   GND    Bat2   GND    Bat3  │
│                                     │
│  [INA219]  [INA219]  [INA219]      │
│   0x40      0x41      0x44         │
│    ││        ││        ││          │
│   I2C       I2C       I2C          │
│                                     │
│  [Buck 12V→5V]  [AMS1117 5V→3.3V] │
└─────────────────────────────────────┘
```

### **MQTT Topics:**

```
boat/sensors/battery/1/voltage    (V)
boat/sensors/battery/1/current    (A)
boat/sensors/battery/1/power      (W)
boat/sensors/battery/2/voltage
boat/sensors/battery/2/current
boat/sensors/battery/2/power
boat/sensors/battery/3/voltage
boat/sensors/battery/3/current
boat/sensors/battery/3/power
```

### **BOM (Bill of Materials):**

| Komponente | Anzahl | Preis | Link |
|------------|--------|-------|------|
| ESP32 DevKit | 1 | 8€ | AliExpress |
| INA219 Modul | 3 | 6€ | AliExpress |
| 100kΩ Widerstand | 3 | <1€ | |
| 47kΩ Widerstand | 3 | <1€ | |
| 4.7kΩ Pull-up | 2 | <1€ | |
| Buck Converter 12→5V | 1 | 3€ | |
| AMS1117 3.3V | 1 | 1€ | |
| Lochraster 10×15cm | 1 | 2€ | |
| Klemmen, Kabel | - | 5€ | |
| **Gesamt** | | **~26€** | |

---

## 📐 Board 2: Tank & Temperature Sensors

**Funktion:** Tank-Füllstände (Diesel, Wasser) + Temperaturen überwachen

### **Sensoren:**
- 2× VDO Tankgeber (Widerstand → Füllstand)
- 3× DS18B20 (1-Wire Temperatursensoren)
- 1× ADS1115 (16-bit ADC für VDO-Geber)

### **Komponenten:**

```
ESP32 WROOM-32 DevKit
├── ADS1115 (16-bit ADC, I2C)
│   ├── Adresse 0x48
│   ├── A0: Diesel-Tankgeber (VDO)
│   ├── A1: Wasser-Tankgeber (VDO)
│   ├── A2: Reserve
│   └── A3: Reserve
│
├── 3× DS18B20 (1-Wire)
│   ├── Kabine Temperatur
│   ├── Außentemperatur
│   ├── Kühlwasser (Motor)
│   └── GPIO4 (1-Wire Bus)
│
└── Stromversorgung
    ├── 12V Input
    ├── Buck → 5V
    └── AMS1117 → 3.3V
```

### **Schaltplan VDO-Geber:**

```
VDO Tankgeber (variabel 10-180Ω)
│
├─ 12V (Versorgung)
│
└─ Signal ─ 100Ω ─ ADS1115 A0
            │
           GND

ADS1115:
- Misst Spannungsabfall über 100Ω Shunt
- 16-bit Auflösung = präzise!
- Umrechnung Widerstand → Liter via Kennlinie

Beispiel VDO-Kennlinie (Standard):
10Ω   = 0% (leer)
90Ω   = 50% (halb)
180Ω  = 100% (voll)
```

### **Schaltplan DS18B20:**

```
3× DS18B20 Temperatursensoren (1-Wire Bus)

DS18B20 #1 (Kabine) ─┐
DS18B20 #2 (Außen)  ─┼─ GPIO4 (ESP32)
DS18B20 #3 (Motor)  ─┘      │
                            4.7kΩ Pull-up
                              │
                            3.3V

Jeder Sensor hat unique ID!
Alle parallel auf 1-Wire Bus.
```

### **Lochraster-Layout:**

```
┌─────────────────────────────────────┐
│  [ESP32 DevKit]                     │
│                                     │
│  [ADS1115]                          │
│   A0  A1  A2  A3                    │
│   │   │                             │
│  Diesel Wasser                      │
│  (VDO) (VDO)                        │
│   │   │                             │
│  [100Ω Shunt]                       │
│                                     │
│  [DS18B20] [DS18B20] [DS18B20]     │
│    Kabine   Außen     Motor        │
│      └─────┬─────┘                  │
│          GPIO4                      │
│         [4.7k]                      │
│                                     │
│  [Buck 12V→5V]  [AMS1117]          │
└─────────────────────────────────────┘
```

### **MQTT Topics:**

```
boat/sensors/tank/diesel/level     (%)
boat/sensors/tank/diesel/liters    (L)
boat/sensors/tank/water/level      (%)
boat/sensors/tank/water/liters     (L)
boat/sensors/temperature/cabin     (°C)
boat/sensors/temperature/outside   (°C)
boat/sensors/temperature/coolant   (°C)
```

### **BOM:**

| Komponente | Anzahl | Preis |
|------------|--------|-------|
| ESP32 DevKit | 1 | 8€ |
| ADS1115 Modul | 1 | 3€ |
| DS18B20 Sensor | 3 | 6€ |
| 100Ω Shunt | 2 | <1€ |
| 4.7kΩ Pull-up | 1 | <1€ |
| Buck Converter | 1 | 3€ |
| AMS1117 | 1 | 1€ |
| Lochraster | 1 | 2€ |
| Kabel, Klemmen | - | 5€ |
| **Gesamt** | | **~29€** | |

---

## 📐 Board 3: Motor Data

**Funktion:** Motor-Parameter überwachen (Drehzahl, Öldruck, Temperatur)

### **Sensoren:**
- 1× VDO Drehzahlgeber (W-Terminal Lichtmaschine)
- 1× VDO Öldruck-Geber (Widerstand)
- 1× VDO Temperatur-Geber (Widerstand)
- 1× MPU6050 (6-DOF IMU: Pitch, Roll, Yaw)

### **Komponenten:**

```
ESP32 WROOM-32 DevKit
├── Drehzahl (GPIO25)
│   ├── W-Terminal (AC, 0-14V Wechselspannung)
│   ├── Optokoppler (Galvanische Trennung!)
│   └── Impulszähler
│
├── ADS1115 (I2C, 0x48)
│   ├── A0: Öldruck-Geber (VDO)
│   └── A1: Motor-Temperatur (VDO)
│
├── MPU6050 (I2C, 0x68)
│   ├── 3-Achsen Beschleunigung
│   ├── 3-Achsen Gyroskop
│   └── Berechnet: Pitch, Roll
│
└── Stromversorgung
    └── 12V → 5V → 3.3V
```

### **Schaltplan Drehzahl:**

```
W-Terminal (Lichtmaschine)
│ AC Wechselspannung, 0-14V
│ 1 Impuls pro Umdrehung (bei 1-polig)
│
├─ Gleichrichter (Diode)
│
├─ Optokoppler (PC817)
│   ├── LED-Seite: Lichtmaschine
│   └── Transistor-Seite: ESP32
│
└─ GPIO25 (Impulszähler)

Galvanische Trennung wichtig!
Lichtmaschine ≠ ESP32 Masse!

Berechnung:
Impulse/min × 60 = U/min (RPM)
```

### **Schaltplan Öldruck & Temperatur:**

```
VDO Öldruck-Geber (10-180Ω)
│
├─ 12V
│
└─ Signal ─ 100Ω ─ ADS1115 A0
            │
           GND

VDO Temperatur-Geber (variabel)
│
├─ 12V
│
└─ Signal ─ 100Ω ─ ADS1115 A1
            │
           GND

Kennlinien siehe VDO Datenblätter!
```

### **Schaltplan MPU6050:**

```
MPU6050 (I2C)
├── VCC ─ 3.3V
├── GND ─ GND
├── SDA ─ GPIO21 (I2C)
├── SCL ─ GPIO22 (I2C)
└── INT ─ (optional)

I2C Adresse: 0x68

Liefert:
- Pitch (Neigung längs)
- Roll (Neigung quer)
- Optional: Yaw (Kompass)
```

### **Lochraster-Layout:**

```
┌─────────────────────────────────────┐
│  [ESP32 DevKit]                     │
│                                     │
│  [Optokoppler PC817]                │
│   W-Terminal ──→ GPIO25 (Drehzahl) │
│                                     │
│  [ADS1115]                          │
│   A0: Öldruck (VDO)                 │
│   A1: Motor Temp (VDO)              │
│   [100Ω] [100Ω]                     │
│                                     │
│  [MPU6050]                          │
│   Pitch / Roll                      │
│   I2C @ 0x68                        │
│                                     │
│  [Buck] [AMS1117]                   │
└─────────────────────────────────────┘
```

### **MQTT Topics:**

```
boat/sensors/engine/rpm            (U/min)
boat/sensors/engine/oil_pressure   (bar)
boat/sensors/engine/temperature    (°C)
boat/sensors/motion/pitch          (°)
boat/sensors/motion/roll           (°)
boat/sensors/motion/heading        (° optional)
```

### **BOM:**

| Komponente | Anzahl | Preis |
|------------|--------|-------|
| ESP32 DevKit | 1 | 8€ |
| ADS1115 | 1 | 3€ |
| MPU6050 | 1 | 3€ |
| PC817 Optokoppler | 1 | 1€ |
| Diode (1N4007) | 1 | <1€ |
| 100Ω Shunt | 2 | <1€ |
| Buck Converter | 1 | 3€ |
| AMS1117 | 1 | 1€ |
| Lochraster | 1 | 2€ |
| Kabel, Klemmen | - | 5€ |
| **Gesamt** | | **~27€** | |

---

## 🔧 Gesamtkosten

```
Board 1 (Battery):     ~26€
Board 2 (Tank/Temp):   ~29€
Board 3 (Motor):       ~27€
───────────────────────────
GESAMT:                ~82€

+ VDO-Geber (falls nötig): ~50€
+ Gehäuse (3D-Druck):      ~15€
+ Silikon-Verguss:         ~10€
───────────────────────────
KOMPLETT:              ~157€
```

---

## 🛠️ Bauanleitung

### **1. Boards einzeln aufbauen:**
- Board 1 zuerst (einfachste!)
- Jedes Board separat testen
- Erst wenn 100% → nächstes

### **2. Lochraster-Technik:**
- Komponenten platzieren (Bleistift markieren!)
- Löten (Rückseite)
- Drahtbrücken für Verbindungen
- Ordentlich = weniger Fehler

### **3. I2C Bus sauber verlegen:**
- SDA/SCL parallel zu allen I2C-Devices
- Pull-ups nur 1× pro Bus!
- Kurze Leitungen (<30cm)
- Twisted Pair bei langen Strecken

### **4. Stromversorgung zentral:**
- 12V Hauptleitung dick (mind. 1.5mm²)
- Buck Converter nah am ESP32
- Keramik-Kondensatoren (100nF) an jedem IC!

### **5. Testen, testen, testen:**
- Multimeter ist dein Freund
- I2C-Scanner Code nutzen
- Serieller Monitor für Debug
- Einzelne Sensoren erst, dann alle

---

## 📡 Software

**Alle 3 Boards nutzen:**

- Arduino IDE
- WiFiManager (WiFi-Config über Captive Portal)
- PubSubClient (MQTT)
- Adafruit_ADS1X15 (für ADS1115)
- Adafruit_INA219 (für INA219)
- OneWire + DallasTemperature (für DS18B20)
- MPU6050_light (für MPU6050)

**Code-Struktur:**

```cpp
void setup() {
  // WiFi verbinden
  // MQTT verbinden
  // Sensoren initialisieren
}

void loop() {
  // Sensoren auslesen
  // MQTT publishen
  // Delay (z.B. 1s)
}
```

**GitHub:** Kompletter Code in `/firmware` Ordner!

---

## 🔌 Verkabelung im Boot

**Wichtig:**

1. **Bootsmasse verwenden** (nicht ESP32 GND direkt!)
2. **Absicherung** (Sicherung vor jedem Board!)
3. **Wasserdicht** (Gehäuse IP65+)
4. **Beschriftung** (welches Kabel wohin!)
5. **Zugentlastung** (Kabelbinder, Clips)

**Empfehlung:**

```
Batterie 12V ─ Hauptsicherung 10A
    │
    ├─ Board 1 (Battery Monitor)
    ├─ Board 2 (Tank/Temp)
    └─ Board 3 (Motor)

Jedes Board:
- Eigene Zuleitung (mind. 1mm²)
- Eigene Sicherung (3A)
- Kurze Wege zu Sensoren
```

---

## 🎯 Visualisierung

**Interaktive PCB-Layouts:**

➡️ [boat_sensor_pcb_layout.html](boat_sensor_pcb_layout.html)

- Alle 3 Boards visualisiert
- Interaktiv (Zoom, Pan)
- Farbcodiert
- Pin-Nummern
- Komponenten-Labels

**Im Browser öffnen!**

---

## 📚 Weiterführende Docs

- [BOM (Bill of Materials)](bom.md) - Komplette Teileliste
- [Installation Guide](../docs/installation.md) - Schritt-für-Schritt
- [Troubleshooting](../docs/troubleshooting.md) - Häufige Probleme
- [MQTT Topics](../mqtt/topic-structure.md) - Alle Topics

---

## ⚡ Quick Start

**1. Board kaufen:**
```bash
# Siehe bom.md für Links
# AliExpress, Amazon, Reichelt
```

**2. Löten:**
```bash
# Reihenfolge:
# 1. Widerstände
# 2. ICs/Module
# 3. Klemmen
# 4. Testen!
```

**3. Code flashen:**
```bash
git clone https://github.com/bigbrainlabs/logbuch-ohne-pose
cd band-3-sensoren/firmware
# Arduino IDE öffnen
# Board auswählen: ESP32 Dev Module
# Upload!
```

**4. Konfigurieren:**
```bash
# ESP32 startet WiFi-Hotspot
# Verbinden: "BoatSensors-XXXX"
# WiFi + MQTT konfigurieren
# Speichern → Reboot
```

**5. Testen:**
```bash
# MQTT-Client öffnen (z.B. MQTT Explorer)
# Topics abonnieren: boat/sensors/#
# Daten sollten ankommen!
```

---

## 🎊 Fertig!

**Du hast jetzt:**

✅ 3 Sensor-Boards  
✅ 8+ Sensoren live  
✅ MQTT-Stream zu BoatOS  
✅ Verstanden wie's funktioniert  

**Das ist DIY Marine-Elektronik! 🚤⚓💻**

---

**Viel Erfolg beim Nachbauen! 🔧**

*"Hier ist alles. Bau's nach!"* 😊
