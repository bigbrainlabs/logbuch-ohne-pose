# Band 7: Die AutoSat

**Vollautomatische Sat-Tracking-Anlage für unter 150€**

> *"Die teuren fahren nur Koordinaten an. Meine trackt in Echtzeit."*

---

## 📖 Übersicht

Eine Satelliten-Anlage die in Echtzeit auf Bootsbewegungen reagiert – bei Wellengang, Drehung, Neigung. Für unter 150€ statt 3.000€+.

**Status:** 💭 Konzeptphase  
**Ziel:** Echtzeit-Sat-Tracking bei Bewegung  
**Geplant:** 2026/2027

---

## 🎯 Das Problem

| Preisklasse | Funktion | Problem |
|-------------|----------|---------|
| ~300€ | Manuell | Jedes Mal neu ausrichten |
| ~1.000€ | Koordinaten-Anfahrt | Boot dreht → Signal weg |
| ~3.000€+ | Echtzeit-Tracking | Unbezahlbar |

**AutoSat:** Echtzeit-Tracking für **unter 150€**

---

## ✅ Die Lösung

```
Boot dreht sich    → Schüssel korrigiert ✅
Boot neigt sich    → Schüssel korrigiert ✅
Wellengang         → Schüssel korrigiert ✅
Fahrt              → Schüssel korrigiert ✅
```

**Die Vision:** Die Schüssel behält den Satelliten im Blick – egal was das Boot macht.

---

## 🔧 Technik

### Hardware:
```
- ESP32 (Controller)
- GPS-Modul (Position)
- Kompass (Heading)
- IMU (Roll, Pitch)
- 4× Schrittmotoren
- 3D-Druck (Podest, Wellen)
```

### Regelkreis:
```
GPS + Kompass → Soll-Position
      ↓
IMU → Boot-Lage
      ↓
Algorithmus → Delta
      ↓
Motoren → Korrektur
      ↓
(Loop: 10-50x/Sekunde)
```

---

## 💰 Kosten

| Komponente | Preis |
|------------|-------|
| ESP32 | 8€ |
| GPS + Kompass + IMU | 25€ |
| 4× Stepper + Driver | 55€ |
| 3D-Druck, Mechanik | 35€ |
| Netzteil, Kabel | 20€ |
| **Gesamt** | **~143€** |

**vs. 3.000€+ kommerziell = Faktor 20 günstiger!**

---

## 📑 Kapitel

1. Das Sat-Problem (DVB-T? IPTV? Sat!)
2. Wie Tracking funktioniert (Theorie)
3. Die Hardware-Planung
4. Das drehbare Podest (3D-Druck)
5. Die Elektronik (ESP32, Sensoren)
6. Der Algorithmus (das Gehirn)
7. Der Praxistest
8. AutoSat v1 & Open Source

---

## 💼 Business-Modell

### 100% Open Source – Keine Lizenz!

```
✅ STL-Dateien
✅ Schaltpläne
✅ Firmware + Algorithmus
✅ Anleitung
✅ Für JEDEN – auch Firmen!
```

**Warum?**
> *"Vielleicht gehen die Preise ja mal runter, wenn's gefährliche Konkurrenz gibt."*

Open Source als Kampfansage an überteuerte Marine-Elektronik! 💪

---

### 💸 "Lizenzgebühren"

> *"Du willst das kommerziell nutzen? Kauf die Buchreihe. Dann sind wir quitt."* 😄

**~50€ für 7 Bände statt 2.500€ Lizenz. Deal.**

---

## 🔗 Serie

```
Band 1-3: Grundlagen (Motor, Strom, Sensoren)
Band 4-5: BoatOS (Bordcomputer)
Band 6: Ventil-Heizung (150€ vs. Kabelgewirr)
Band 7: AutoSat (150€ vs. 3.000€) ← DU BIST HIER
```

---

*"Faktor 20 günstiger. Und besser als die für 1.000€."*
