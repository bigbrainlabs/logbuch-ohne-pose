# Firmware für Band 3 Sensor-System

**ESP32 + 2× ADS1115 + GY-521 + Flowsensor**

## 📂 Dateien:

- `test_v1.1.ino` - Haupt-Firmware (aktuell)
- `config.h` - Konfiguration (geplant)
- `sensors.h` - Sensor-Funktionen (geplant)

## 🔧 Features:

✅ 2× ADS1115 auslesen (6× analoge Sensoren)
✅ GY-521 (Pitch/Roll/Yaw)
✅ Drehzahl-Zähler (GPIO25)
✅ Flowsensor-Zähler (GPIO4)
✅ MQTT Publish
✅ WiFi Auto-Reconnect

## 📊 I2C Adressen:

- ADS1115 #1: 0x48
- ADS1115 #2: 0x49
- MPU6050: 0x68

## 🚀 Installation:

1. Arduino IDE installieren
2. ESP32 Board-Support installieren
3. Libraries installieren:
   - Adafruit_ADS1X15
   - MPU6050_light
   - PubSubClient
   - WiFiManager
4. Code öffnen
5. Upload!

## 🎯 Konfiguration:

Siehe `config.h` (oder direkt im Code)

## 📝 Changelog:

### v1.1 (aktuell)
- Alle Sensoren funktionieren
- MQTT Topics korrekt
- Stabil!

### v1.0
- Initial version