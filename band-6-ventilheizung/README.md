# Band 6: Die Ventil-Heizung

**Von Kabelgewirr zu smarten Heizringen**

> *"Kabelheizungen wickeln ist wie Weihnachtsbeleuchtung entwirren. Nur kälter."*

---

## 📖 Übersicht

Ein modulares Heizsystem für Ventile und Rohre auf dem Boot. Aufklappbare Heizringe mit Klettband-Fixierung, zentral gesteuert über eine ESP32 Controller-Einheit.

**Status:** 🔧 Prototyp V3 in Entwicklung  
**3D-Druck:** ASA (PETG als Alternative)  
**Geplant:** Q2/Q3 2026

---

## 🎯 Das Problem

Klassische Kabelheizungen:
- ❌ Wickeln bei Minusgraden
- ❌ Klamme Finger, starre Kabel
- ❌ Nie die richtige Länge
- ❌ Kabelchaos
- ❌ Jedes Jahr das gleiche Drama

---

## ✅ Die Lösung

Modulare Heizringe:
- ✅ Aufklappbar (Clamshell-Design)
- ✅ Klettband-Fixierung
- ✅ Verschiedene Größen (DN15, DN20, DN25, ...)
- ✅ Beliebig viele Ringe an einem Controller
- ✅ Einmal installiert, fertig

---

## 🔄 Die Evolution

```
V1: Manschette (komplette Ventillänge)
    → Problem: Jedes Ventil ist anders

V2: Heizringe (vor und hinter Ventil)
    → Problem: Manuelle Steuerung

V3: Controller-Einheit + Klemmleiste  ← AKTUELL
    → Beliebig viele Ringe, zentral gesteuert
```

---

## 📑 Kapitelstruktur

| Kapitel | Titel | Inhalt |
|---------|-------|--------|
| 1 | Das Gefummel | Warum Kabelheizungen nerven |
| 2 | Die erste Idee | Manschette für alles (Fail) |
| 3 | Die Heizringe | Kleiner denken, flexibler werden |
| 4 | Die Heiztechnik | Watt, Widerstand, Regelung |
| 5 | Der 3D-Druck | ASA, PETG und geschmolzenes PLA |
| 6 | Die Controller-Einheit | ESP32 + Klemmleiste |
| 7 | Das Gesamtsystem | Alles zusammen, BoatOS-Integration |
| 8 | Open Source & Business | DIY frei, Firmen zahlen |

---

## 🛠️ Technologie

### Hardware
- ESP32 (Controller)
- Relais/MOSFETs (Schaltung)
- DS18B20 Temperatursensoren
- Heizelemente
- Klemmleiste
- 3D-Druck: ASA (oder PETG)

### Software
- Arduino/ESP-IDF Firmware
- Temperaturregelung
- MQTT (optional → BoatOS)

---

## 💼 Business-Modell

### DIY (kostenlos):
```
✅ STL-Dateien
✅ Schaltpläne
✅ Firmware
✅ Anleitung
```

### Firmen (Lizenz):
```
💼 2.500€ einmalig – dann unbegrenzt produzieren
📜 Geschützt durch Gebrauchsmuster
🤝 Kein Tracking, kein Aufwand
```

---

## 🔗 Verbindungen

- **Band 5 (BoatOS):** Dashboard-Integration möglich
- **Band 2 (Strom):** Winterbetrieb, Energieverbrauch
- **Standalone:** Funktioniert auch ohne BoatOS

---

## 📜 Lizenz

- **DIY:** CC BY-NC-SA (kostenlos für privat)
- **Kommerziell:** Lizenz erforderlich
- **Schutz:** Gebrauchsmuster (10 Jahre)

---

*"Klick, Klett, frostfrei."*
