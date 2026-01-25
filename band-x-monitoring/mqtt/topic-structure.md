# MQTT Topic-Struktur

**Alle Topics die das Boot-Monitoring System published**

---

## 📡 Topic-Hierarchie

```
boot/
├── sensoren/
│   ├── batterie/
│   ├── tank/
│   ├── motor/
│   ├── durchfluss/
│   └── lage/
└── status/
    └── esp32/

signalk/
└── vessels/
    └── self/
        ├── electrical/
        ├── tanks/
        ├── propulsion/
        └── navigation/
```

---

## 🔋 Boot-Topics (Eigenes Format)

### **Batterie-Sensoren**

| Topic | Typ | Bereich | Unit | Update | Beschreibung |
|-------|-----|---------|------|--------|--------------|
| `boot/sensoren/batterie/starter` | float | 9.0-16.0 | V | 5s | Starterbatterie Spannung |
| `boot/sensoren/batterie/verbraucher` | float | 9.0-16.0 | V | 5s | Verbraucherbatterie Spannung |

**Beispiel:**
```
boot/sensoren/batterie/starter 12.58
boot/sensoren/batterie/verbraucher 13.24
```

---

### **Tank-Sensoren**

| Topic | Typ | Bereich | Unit | Update | Beschreibung |
|-------|-----|---------|------|--------|--------------|
| `boot/sensoren/tank/diesel/prozent` | float | 0.0-100.0 | % | 1s | Tankfüllstand prozentual |
| `boot/sensoren/tank/diesel/liter` | float | 0.0-200.0 | L | 1s | Tankfüllstand in Litern |

**Tank-Kapazität:**
- Im Code konfigurierbar: `TANK_CAPACITY_LITERS`
- Standard: 200 L

**Beispiel:**
```
boot/sensoren/tank/diesel/prozent 65.5
boot/sensoren/tank/diesel/liter 131.0
```

---

### **Motor-Sensoren**

| Topic | Typ | Bereich | Unit | Update | Beschreibung |
|-------|-----|---------|------|--------|--------------|
| `boot/sensoren/motor/temperatur` | float | 0.0-120.0 | °C | 1s | Kühlwasser-Temperatur |
| `boot/sensoren/motor/oeldruck` | float | 0.0-6.0 | bar | 1s | Motoröldruck |
| `boot/sensoren/motor/drehzahl` | float | 0.0-3500.0 | RPM | 200ms | Motor-Drehzahl |

**Beispiel:**
```
boot/sensoren/motor/temperatur 82.5
boot/sensoren/motor/oeldruck 3.2
boot/sensoren/motor/drehzahl 1850.0
```

---

### **Durchfluss**

| Topic | Typ | Bereich | Unit | Update | Beschreibung |
|-------|-----|---------|------|--------|--------------|
| `boot/sensoren/durchfluss/rate` | float | 0.0-50.0 | L/h | 200ms | Diesel-Durchfluss |

**Beispiel:**
```
boot/sensoren/durchfluss/rate 12.8
```

---

### **Lage-Sensoren (IMU)**

| Topic | Typ | Bereich | Unit | Update | Beschreibung |
|-------|-----|---------|------|--------|--------------|
| `boot/sensoren/lage/neigung` | float | -90.0-90.0 | ° | 5s | Pitch (Neigung vor/zurück) |
| `boot/sensoren/lage/schlagseite` | float | -90.0-90.0 | ° | 5s | Roll (Schlagseite links/rechts) |

**Koordinaten:**
- **Pitch positiv:** Bug hoch
- **Pitch negativ:** Bug runter
- **Roll positiv:** Backbord hoch
- **Roll negativ:** Steuerbord hoch

**Beispiel:**
```
boot/sensoren/lage/neigung 2.5      # Bug leicht hoch
boot/sensoren/lage/schlagseite -1.2  # Leicht nach Steuerbord
```

---

### **System-Status**

| Topic | Typ | Wert | Retained | Update | Beschreibung |
|-------|-----|------|----------|--------|--------------|
| `boot/status/esp32/online` | bool | true/false | Ja | LWT | ESP32 Online-Status |
| `boot/status/esp32/uptime` | int | 0-∞ | Nein | 10s | Uptime in Sekunden |
| `boot/status/esp32/wifi_rssi` | int | -100-0 | Nein | 10s | WiFi Signalstärke |
| `boot/status/esp32/sensors_ok` | bool | true/false | Nein | 10s | Alle Sensoren OK |
| `boot/status/esp32/mode` | string | TEST_MODE/LIVE | Nein | 10s | Betriebsmodus |

**Last Will Testament (LWT):**
```
boot/status/esp32/online false  # Wird bei Disconnect automatisch gesetzt
```

**Beispiel:**
```
boot/status/esp32/online true
boot/status/esp32/uptime 3625
boot/status/esp32/wifi_rssi -42
boot/status/esp32/sensors_ok true
boot/status/esp32/mode LIVE
```

---

## ⛵ SignalK-Topics (Standard-konform)

### **Electrical (Batterien)**

| Topic | Typ | Unit | SignalK Path |
|-------|-----|------|--------------|
| `signalk/vessels/self/electrical/batteries/starter/voltage` | float | V | `electrical.batteries.starter.voltage` |
| `signalk/vessels/self/electrical/batteries/house/voltage` | float | V | `electrical.batteries.house.voltage` |

**Format:** SignalK Delta (wird von Gateway konvertiert)

**Beispiel:**
```json
{
  "updates": [{
    "values": [{
      "path": "electrical.batteries.starter.voltage",
      "value": 12.58
    }]
  }]
}
```

---

### **Tanks**

| Topic | Typ | Unit | SignalK Path |
|-------|-----|------|--------------|
| `signalk/vessels/self/tanks/fuel/0/currentLevel` | float | 0.0-1.0 | `tanks.fuel.0.currentLevel` |

**Wichtig:** SignalK verwendet **Ratio** (0.0-1.0), nicht Prozent!
- 0.0 = leer
- 0.5 = halb
- 1.0 = voll

**Beispiel:**
```
signalk/vessels/self/tanks/fuel/0/currentLevel 0.655
```

---

### **Propulsion (Motor)**

| Topic | Typ | Unit | SignalK Path |
|-------|-----|------|--------------|
| `signalk/vessels/self/propulsion/main/temperature` | float | K | `propulsion.main.temperature` |
| `signalk/vessels/self/propulsion/main/oilPressure` | float | Pa | `propulsion.main.oilPressure` |
| `signalk/vessels/self/propulsion/main/revolutions` | float | Hz | `propulsion.main.revolutions` |

**Unit-Konversion:**
```
Temperatur: °C → Kelvin (K = °C + 273.15)
Druck:      bar → Pascal (Pa = bar × 100000)
RPM:        RPM → Hz (Hz = RPM / 60)
```

**Beispiel:**
```
signalk/vessels/self/propulsion/main/temperature 355.65  # 82.5°C
signalk/vessels/self/propulsion/main/oilPressure 320000  # 3.2 bar
signalk/vessels/self/propulsion/main/revolutions 30.83   # 1850 RPM
```

---

### **Navigation (Lage)**

| Topic | Typ | Unit | SignalK Path |
|-------|-----|------|--------------|
| `signalk/vessels/self/navigation/attitude/pitch` | float | rad | `navigation.attitude.pitch` |
| `signalk/vessels/self/navigation/attitude/roll` | float | rad | `navigation.attitude.roll` |

**Unit-Konversion:**
```
Grad → Radiant (rad = ° × π / 180)
```

**Beispiel:**
```
signalk/vessels/self/navigation/attitude/pitch 0.0436   # 2.5°
signalk/vessels/self/navigation/attitude/roll -0.0209   # -1.2°
```

---

## 🔄 Update-Raten

| Kategorie | Topics | Rate | Intervall |
|-----------|--------|------|-----------|
| **Schnell** | RPM, Durchfluss | 5 Hz | 200ms |
| **Normal** | Tank, Temp, Öl | 1 Hz | 1s |
| **Langsam** | Batterien, Lage | 0.2 Hz | 5s |
| **Status** | Uptime, WiFi | 0.1 Hz | 10s |

**Begründung:**
- **RPM:** Muss schnell reagieren (Beschleunigung)
- **Durchfluss:** Pulszählung braucht hohe Rate
- **Tank/Temp/Öl:** Ändern sich langsam
- **Batterien:** Sehr langsame Änderung
- **Lage:** Mittel (Boot-Bewegung)
- **Status:** Heartbeat

---

## 🔐 QoS & Retained

### **Quality of Service (QoS):**

| Topic-Typ | QoS | Grund |
|-----------|-----|-------|
| Sensoren | 0 | Fire-and-forget, neue Werte kommen sofort |
| Status | 1 | Wichtig dass ankommt |
| Online (LWT) | 1 | Muss ankommen bei Disconnect |

### **Retained Messages:**

| Topic | Retained | Grund |
|-------|----------|-------|
| `boot/status/esp32/online` | ✅ Ja | Letzter Status bleibt |
| Alle anderen | ❌ Nein | Alte Werte irrelevant |

---

## 📊 Datentypen

### **Float-Formatting:**
```
Präzision: 2 Dezimalstellen
Format: "%.2f"

Beispiele:
12.5789 → "12.58"
0.0001  → "0.00"
1850.0  → "1850.00"
```

### **Boolean:**
```
true  → String "true"
false → String "false"

NICHT: 1/0 oder TRUE/FALSE
```

### **Integer:**
```
Ohne Dezimalpunkt
Beispiel: 3625 (uptime)
```

---

## 🛠️ MQTT Client Beispiele

### **Subscribe alle Boot-Topics:**
```bash
mosquitto_sub -h localhost -t 'boot/#' -v
```

### **Subscribe nur Motor:**
```bash
mosquitto_sub -h localhost -t 'boot/sensoren/motor/#' -v
```

### **Subscribe SignalK:**
```bash
mosquitto_sub -h localhost -t 'signalk/vessels/self/#' -v
```

### **Publish Test:**
```bash
mosquitto_pub -h localhost -t 'boot/sensoren/test' -m '42.0'
```

---

## 🔗 SignalK Integration

**MQTT → SignalK Gateway Plugin:**
```bash
# SignalK Server
cd ~/.signalk
npm install @signalk/signalk-mqtt-gw
```

**Konfiguration:**
```json
{
  "enabled": true,
  "host": "localhost",
  "port": 1883,
  "username": "",
  "password": "",
  "subscriptions": [
    {
      "topic": "signalk/vessels/self/#",
      "type": "delta"
    }
  ]
}
```

**SignalK empfängt dann automatisch:**
- Alle `signalk/vessels/self/*` Topics
- Konvertiert zu SignalK Deltas
- Integriert in SignalK Data Model

---

## 📝 Payload-Format

### **Standard (Boot-Topics):**
```
Plaintext, Float als String
Beispiel: "12.58"
```

### **SignalK:**
```
Float als String (wird vom Gateway zu Delta konvertiert)
Beispiel: "0.655"
```

**KEIN JSON:**
```
❌ FALSCH: {"value": 12.58, "unit": "V"}
✅ RICHTIG: 12.58
```

**Grund:** Einfachheit, weniger Overhead, kompatibel mit allen Dashboards

---

## 🚀 Erweiterungen

**Zukünftige Topics (geplant):**
```
boot/energie/solar/leistung         # Für Band 2!
boot/energie/solar/spannung
boot/energie/solar/strom
boot/energie/batterie/soc
boot/energie/verbrauch/gesamt
boot/steuerung/heizung/status
boot/steuerung/heizung/temperatur
boot/steuerung/bilge/niveau
boot/steuerung/bilge/pumpe
```

---

## 📖 Dokumentation

**Vollständige Topic-Liste:** Siehe Code
**SignalK Spec:** https://signalk.org/specification/
**MQTT Spec:** https://mqtt.org/

---

**Letzte Aktualisierung:** Januar 2025
