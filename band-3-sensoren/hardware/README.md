# Hardware-Dokumentation

**ESP32 Sensor-Boards für Band 3**

---

## 📂 Inhalt

### **Dateien:**

| Datei | Beschreibung |
|-------|--------------|
| [PCB_LAYOUTS.md](PCB_LAYOUTS.md) | Komplette Schaltpläne & Layouts für alle 3 Boards |
| [boat_sensor_pcb_layout.html](boat_sensor_pcb_layout.html) | Interaktive Visualisierung (im Browser öffnen!) |
| [bom.md](bom.md) | Bill of Materials - alle Teile mit Links |

---

## 🎯 Die 3 Boards

### **Board 1: Battery Monitor**
- 3× Batterien (Spannung + Strom)
- 3× INA219 + Spannungsteiler
- Kosten: ~26€

### **Board 2: Tank & Temperature**
- 2× VDO Tankgeber (Diesel, Wasser)
- 3× DS18B20 Temperatursensoren
- 1× ADS1115 (16-bit ADC)
- Kosten: ~29€

### **Board 3: Motor Data**
- Drehzahl (W-Terminal)
- Öldruck (VDO)
- Motor-Temperatur (VDO)
- MPU6050 (Pitch/Roll)
- Kosten: ~27€

**Gesamt: ~82€ für alle 3 Boards!**

---

## 🚀 Quick Links

**Schaltpläne ansehen:**
→ [PCB_LAYOUTS.md](PCB_LAYOUTS.md)

**Interaktive Visualisierung:**
→ [boat_sensor_pcb_layout.html](boat_sensor_pcb_layout.html) (Download & im Browser öffnen!)

**Teile bestellen:**
→ [bom.md](bom.md)

**Installation:**
→ [../docs/installation.md](../docs/installation.md)

---

## 💡 Warum 3 separate Boards?

✅ **Modularer Aufbau** - einzeln testbar  
✅ **Einfacher zu debuggen** - klare Trennung  
✅ **Flexibler Einbau** - passen überall hin  
✅ **Ausfall-sicher** - ein Board tot ≠ alles tot  
✅ **Schrittweise Entwicklung** - eins nach dem anderen  

---

## 🔧 Bauanleitung (Kurzfassung)

1. **Teile bestellen** (siehe bom.md)
2. **Board 1 aufbauen** (Batterie = einfachste!)
3. **Board 1 testen** (MQTT funktioniert?)
4. **Board 2 aufbauen** (Tank/Temp)
5. **Board 2 testen**
6. **Board 3 aufbauen** (Motor)
7. **Board 3 testen**
8. **Im Boot verbauen** (Gehäuse, Silikon-Verguss!)
9. **BoatOS anbinden** (MQTT Topics!)
10. **GENIEẞEN!** 🎉

---

## 📊 Technologie-Stack

**Hardware:**
- ESP32 WROOM-32 DevKit (3×)
- INA219 Module (3×)
- ADS1115 ADC (2×)
- MPU6050 IMU (1×)
- DS18B20 Sensoren (3×)
- VDO Marine-Geber (4-5×)

**Software:**
- Arduino IDE
- WiFiManager (WiFi-Config)
- PubSubClient (MQTT)
- Diverse Sensor-Libraries

**Integration:**
- MQTT Broker (Mosquitto)
- Home Assistant
- BoatOS Dashboard

---

## 🎊 Ergebnis

**Nach dem Bau hast du:**

✅ 8+ Sensoren live  
✅ MQTT-Stream zu BoatOS  
✅ Alle Bootsdaten zentral  
✅ Dashboard mit Live-Werten  
✅ Verstanden wie's funktioniert  
✅ Reparierbar & erweiterbar  

**Das ist DIY Marine-Elektronik! 🚤⚓💻**

---

**Viel Erfolg! 🔧**
