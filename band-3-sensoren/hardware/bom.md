# Bill of Materials (BOM) - Boot-Monitoring System

**Stand:** Januar 2025  
**Preise:** Circa-Angaben, Deutschland

---

## 🎯 Hauptkomponenten

### **Mikrocontroller & Module**

| Teil | Anzahl | Spezifikation | Preis | Gesamt | Bezugsquelle |
|------|--------|---------------|-------|--------|--------------|
| ESP32 DevKit | 1 | WROOM-32, 38-Pin | 8€ | 8€ | [AZ-Delivery](https://www.az-delivery.de/products/esp32-developmentboard), Amazon |
| ADS1115 Breakout | 2 | 16-bit ADC, I2C | 6€ | 12€ | Amazon, eBay, AliExpress |
| MPU6050 Breakout | 1 | GY-521, 6-DOF IMU | 4€ | 4€ | Amazon, eBay |
| **Subtotal** | | | | **24€** | |

---

## 🔌 Stromversorgung

| Teil | Anzahl | Spezifikation | Preis | Gesamt | Bezugsquelle |
|------|--------|---------------|-------|--------|--------------|
| Buck Converter | 1 | 12V→5V, 10A (LM2596) | 10€ | 10€ | Amazon |
| AMS1117-3.3V | 1 | Linear Regler TO-220 | 1€ | 1€ | [Reichelt](https://www.reichelt.de), Conrad |
| Kondensator 100µF | 2 | Elko, 16V | 0.50€ | 1€ | Reichelt, Conrad |
| Kondensator 100nF | 6 | Keramik, 50V | 0.20€ | 1.20€ | Reichelt, Conrad |
| Kondensator 10µF | 1 | Elko, 16V | 0.30€ | 0.30€ | Reichelt, Conrad |
| **Subtotal** | | | | **13.50€** | |

---

## ⚡ Elektronik-Bauteile

### **Widerstände (1/4W, Metallfilm)**

| Wert | Anzahl | Verwendung | Preis | Gesamt |
|------|--------|------------|-------|--------|
| 1kΩ | 4 | Pull-up (VDO Sensoren) | 0.10€ | 0.40€ |
| 4.7kΩ | 6 | Spannungsteiler Low-Side | 0.10€ | 0.60€ |
| 10kΩ | 6 | Spannungsteiler High-Side | 0.10€ | 0.60€ |
| **Subtotal** | | | | **1.60€** | |

**Tipp:** Widerstandssortiment (E12, 1/4W) = ~8€ für 600 Stück

### **Dioden & Sonstiges**

| Teil | Anzahl | Spezifikation | Preis | Gesamt |
|------|--------|---------------|-------|--------|
| 1N4007 | 1 | Gleichrichterdiode (RPM) | 0.50€ | 0.50€ |
| LED 3mm rot | 1 | Status-LED (optional) | 0.20€ | 0.20€ |
| **Subtotal** | | | | **0.70€** | |

---

## 🔧 Mechanik & Verbindungen

### **Platinen**

| Teil | Größe | Anzahl | Preis | Gesamt | Bezugsquelle |
|------|-------|--------|-------|--------|--------------|
| Lochraster | 50×70mm | 1 | 1.50€ | 1.50€ | Conrad, Reichelt |
| Lochraster | 50×50mm | 2 | 1.20€ | 2.40€ | Conrad, Reichelt |
| **Subtotal** | | | | **3.90€** | |

### **Steckverbinder**

| Teil | Anzahl | Spezifikation | Preis | Gesamt |
|------|--------|---------------|-------|--------|
| Schraubklemme 2-polig | 6 | 5mm Raster | 0.50€ | 3€ |
| Schraubklemme 3-polig | 4 | 5mm Raster | 0.60€ | 2.40€ |
| Stiftleiste männlich | 2 | 2.54mm, 20-polig | 0.50€ | 1€ |
| Buchsenleiste | 2 | 2.54mm, 20-polig (ESP32) | 0.80€ | 1.60€ |
| **Subtotal** | | | | **8€** | |

### **Kabel & Draht**

| Teil | Menge | Spezifikation | Preis | Gesamt |
|------|-------|---------------|-------|--------|
| Kupferlackdraht | 5m | 0.6mm (für Lochraster) | 3€ | 3€ |
| Litze 0.75mm² | 10m | Rot/Schwarz (extern) | 1€/m | 10€ |
| Schrumpfschlauch | 1m | Sortiment 2-10mm | 5€ | 5€ |
| **Subtotal** | | | | **18€** | |

---

## 📦 Gehäuse & Montage

| Teil | Anzahl | Spezifikation | Preis | Gesamt | Bezugsquelle |
|------|--------|---------------|-------|--------|--------------|
| Gehäuse 3D-Druck | 1 | PETG, ~50g | 3€ | 3€ | Selbst gedruckt |
| *oder: Kunststoff-Gehäuse* | 1 | IP65, 120×80×60mm | 15€ | 15€ | Conrad, Reichelt |
| Kabelverschraubung PG7 | 4 | Grau, Kunststoff | 1€ | 4€ | Conrad |
| Belüftungsmembran M12 | 1 | Gore-Tex ähnlich | 2€ | 2€ | Amazon, eBay |
| Abstandshalter M3 | 12 | 10mm, Kunststoff | 0.20€ | 2.40€ | Reichelt |
| Schrauben M3×8 | 12 | Edelstahl | 0.10€ | 1.20€ | Baumarkt |
| Silikon neutral | 50ml | Elektronik-geeignet | 8€ | 8€ | Beko, Kontakt Chemie |
| **Subtotal (3D-Druck)** | | | | **20.60€** | |
| **Subtotal (Fertiggehäuse)** | | | | **32.60€** | |

---

## 🧰 Werkzeug (falls nicht vorhanden)

| Teil | Preis | Bemerkung |
|------|-------|-----------|
| Lötkolben | 25€ | Z.B. Ersa i-Tool |
| Lötzinn bleifrei | 8€ | 0.5mm, 100g |
| Seitenschneider | 10€ | Für Draht |
| Multimeter | 20€ | Digital, min. 10MΩ |
| Entlötlitze | 3€ | Für Fehler |
| Dritte Hand | 8€ | Löthelfer |
| **Gesamt** | **74€** | *Einmalig* |

---

## 🚢 Boot-spezifisch (optional)

### **VDO Sensoren (falls nicht vorhanden)**

| Teil | Anzahl | Typ | Preis | Gesamt |
|------|--------|-----|-------|--------|
| VDO Tank-Sensor | 1 | 240-33Ω | 40€ | 40€ |
| VDO Temp-Sensor | 1 | M14×1.5 | 35€ | 35€ |
| VDO Öldruck-Sensor | 1 | M10×1 | 45€ | 45€ |
| **Subtotal** | | | | **120€** | |

*Hinweis: Meist schon am Motor vorhanden!*

### **Verkabelung Boot**

| Teil | Menge | Spezifikation | Preis | Gesamt |
|------|-------|---------------|-------|--------|
| Marine-Kabel | 20m | 0.75mm², verzinnt | 2€/m | 40€ |
| Aderendhülsen | 50 | 0.75mm² | 5€ | 5€ |
| Kabelschellen | 20 | UV-beständig | 0.30€ | 6€ |
| **Subtotal** | | | | **51€** | |

---

## 💰 Gesamtkosten

### **Minimalkonfiguration (alles vorhanden außer Elektronik):**
```
Hauptkomponenten:        24.00€
Stromversorgung:         13.50€
Elektronik:               2.30€
Platinen & Verbinder:    11.90€
Kabel (intern):           8.00€
─────────────────────────────
Gesamt:                  59.70€ ≈ 60€
```

### **Standard (mit 3D-Druck Gehäuse):**
```
Minimal:                 60.00€
Gehäuse & Montage:       20.60€
─────────────────────────────
Gesamt:                  80.60€ ≈ 81€
```

### **Komplett (mit Fertiggehäuse, Boot-Verkabelung):**
```
Standard:                81.00€
Fertiggehäuse (Diff):    12.00€
Boot-Verkabelung:        51.00€
─────────────────────────────
Gesamt:                 144.00€ ≈ 144€
```

### **Wenn VDO Sensoren fehlen:**
```
Komplett + VDO Sensoren: 264€
```

---

## 🛒 Bezugsquellen-Übersicht

### **Deutschland:**
- **Reichelt:** [www.reichelt.de](https://www.reichelt.de) (Elektronik, schnell)
- **Conrad:** [www.conrad.de](https://www.conrad.de) (alles, teurer, Filialen)
- **Pollin:** [www.pollin.de](https://www.pollin.de) (günstig, Lagerware)
- **AZ-Delivery:** [www.az-delivery.de](https://www.az-delivery.de) (ESP32, Arduino)

### **International (langsam aber günstig):**
- **AliExpress:** ESP32 (~3€), ADS1115 (~2€), MPU6050 (~1.50€)
- **eBay:** Gebraucht-Module oft günstiger

### **Marine-Spezifisch:**
- **SVB:** [www.svb.de](https://www.svb.de) (VDO Sensoren, Verkabelung)
- **Pohl:** [www.pohl.de](https://www.pohl.de) (Marine-Elektronik)

---

## 📝 Tipps zum Einkauf

**Spar-Tipps:**
- ✅ Widerstände & Kondensatoren als Sortiment kaufen (600 Stk für 8-15€)
- ✅ ESP32 & Sensoren bei AliExpress (3-6 Wochen Lieferzeit)
- ✅ Lochraster-Reste nutzen (oft kostenlos bei Elektronik-Läden)
- ✅ Kabel-Reste vom letzten Projekt verwenden

**Sicherheits-Tipps:**
- ⚠️ Nicht am Buck Converter sparen (billige brennen durch)
- ⚠️ Nicht an Kondensatoren sparen (ESR wichtig für Stabilität)
- ⚠️ Marine-Kabel muss verzinnt sein (Korrosion!)

**Zeit-Spar-Tipps:**
- 📦 Alles auf einmal bestellen (nicht 5× Versand warten)
- 📦 Reichelt/Conrad = 1-2 Tage (teurer aber schnell)
- 📦 AliExpress = 3-6 Wochen (günstiger aber Geduld!)

---

## 🔄 Ersatzteile (empfohlen)

| Teil | Warum | Preis |
|------|-------|-------|
| ESP32 | Falls beim Flashen zerschossen | 8€ |
| ADS1115 | Falls beim Löten gegrillt | 6€ |
| AMS1117 | Falls Kurzschluss | 1€ |
| Widerstände | Falscher Wert gelötet | 5€ |
| **Gesamt** | | **20€** |

**Tipp:** Bestell gleich 2× ESP32 und 3× ADS1115 (Murphy's Law!)

---

## ✅ Checkliste vor Bestellung

- [ ] Werkzeug vorhanden? (Lötkolben, Multimeter)
- [ ] VDO Sensoren schon am Boot? (Check erst!)
- [ ] 3D-Drucker vorhanden? (Sonst Fertiggehäuse)
- [ ] Lieferzeit OK? (AliExpress vs. Conrad)
- [ ] Ersatzteile mit bestellt?
- [ ] Buck Converter Leistung passt? (min. 3A)
- [ ] Marine-Kabel verzinnt? (Korrosionsschutz)

---

**Letzte Aktualisierung:** Januar 2025  
**Währung:** EUR (Deutschland)

*Preise können variieren. Links ohne Gewähr. Keine Affiliate-Links.*
