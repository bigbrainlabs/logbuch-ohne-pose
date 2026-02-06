# Volume 2 – Chapter 7: Measuring Instead of Guessing

Display shows 12.4 V.

That's somewhere between "all good" and "getting tight".
Not really helpful.

You stare at the number and try to read the future from two decimal places.
Like reading tea leaves, only with volts.

---

12.4 V with LiFePO₄.
That could be 80%.
Or 40%.
Or something in between.

The curve is flat.
Very flat.
So flat that the difference between "three more days" and "empty tonight" is about 0.2 V.

The display doesn't lie.
It just doesn't say enough.

---

You develop a feel.

12.8 V: all relaxed.
12.4 V: still running.
12.2 V: time to act.
12.0 V: too late.

That works.
Mostly.

Until it doesn't, because you forgot that yesterday was cloudy and today is too.
Or because the fridge draws more at night than expected.
Or because "just a quick TV session" became three episodes.

Then you stand there in the morning, staring at 12.1 V and thinking: How did this happen?

---

There's a solution.
Not a perfect one.
But a better one.

Not measuring volts.
Measuring watt-hours.

Not guessing how much is left.
Knowing how much is left.

Not hoping that solar brings something.
Seeing how much solar brings.

The tool for that: an ESP32, a few sensors, and the willingness to solder a few wires.

---

**The Idea**

You build a system that delivers real numbers.

Solar: how many Wh came in today?
Consumption: how many Wh went out today?
Battery: how many Wh are still in there?

Not felt.
Measured.

Sounds complicated.
It is.
But only the first time.

---

**The Setup**

An ESP32.
Small, cheap, has WiFi.
The brain.

A shunt.
Measures current flowing through it.
Not perfectly accurate, but accurate enough.

A few voltage dividers.
For batteries, solar, consumers.
So the ESP32 doesn't die at 12 V.

An MQTT broker.
Raspberry Pi sitting in the cupboard, collecting data.
Like an accountant, only with fewer questions.

---

The idea isn't new.
Victron has been doing this for years.
Just expensive.
And proprietary.

ESP32 does it cheaper.
And you know what's happening, because you built it yourself.

The disadvantage: you have to build it yourself.
The advantage: you know what's happening.

---

**The Build**

Three boards.
Hand-soldered, because PCB is too much effort and stripboard is enough.

Power Board: turns 12 V into clean 3.3 V for the ESP32.
Sensor Board: reads the voltages and currents.
Main Board: ESP32 and I2C modules that process the data.

Sounds like a lot of work.
It is.
But once you've started, there's no stopping.

You solder.
You test.
You curse because the I2C scanner only finds one device instead of three.
You discover that the ADDR pin on the second ADS1115 isn't connected to VDD. *Of course.*

You re-solder.
You test again.
All three devices found.

Success tastes like solder and coffee.

---

**The First Measurements**

ESP32 runs.
Sensors run.
MQTT runs.

You open the terminal and look at what's coming in.

```
boat/energy/solar/power 45.2
boat/energy/consumption/total 12.8
boat/energy/battery/soc 67
```

Real numbers.
Live.
Not estimated, not guessed.
Measured.

You stare at the numbers like at a miracle.
And then you start to understand.

---

**The Aha Moments**

Solar brings 45 W.
Consumption is 13 W.

That means: battery is charging.
Slowly, but it's charging.

You knew that before.
Theoretically.

But *seeing* how the numbers change is different.
You see how the sun works.
You see how the fridge draws.
You see how the TV takes more than expected.

Suddenly "should be enough" becomes a clear "is enough" or "isn't enough".

No more guessing.
No more hoping.
Just physics, in real time.

---

**What You Learn**

The fridge doesn't draw "about 600 Wh per day".
It sometimes draws 620, sometimes 580, sometimes 650.
Depending on how warm it is.
How often you open the door.
How much beer is inside.

The light isn't "negligible".
Four LED lights, six hours in the evening: 120 Wh.
That's a tenth of daily consumption.

Solar doesn't bring "260 Wp".
Solar brings 1,200 Wh in July.
500 Wh in October.
200 Wh in December.
And on some days you wonder if the panels are still there or have already gone into hibernation.

You stop trusting datasheets.
You start trusting your own measurements.

---

**The Display**

12.4 V is still there.
But now next to it: 67%.

And below: "2,200 Wh remaining".

That's not perfect.
Estimating LiFePO₄ SOC from voltage is difficult.
But it's better than before.

Much better.

You now know how long it will last.
Not felt.
Calculated.

And when the forecast says "empty tomorrow afternoon", you're not surprised.
You're prepared.

---

**The Limits**

The system isn't perfect.

The shunt has an accuracy of ±1%.
Sounds good.
But after a week it adds up.

The voltage fluctuates depending on whether something is drawing.
The temperature affects the measurement.
The wind too, somehow.

You learn that "measuring" doesn't mean "absolute truth".
Just: better than guessing.

But that's enough.

---

**What Remains**

A system that delivers data.
Not perfect.
But useful.

You don't look at the display and hope anymore.
You look at the dashboard and know.

Solar today: 850 Wh.
Consumption today: 1,100 Wh.
Difference: -250 Wh.

Tomorrow solar won't be enough.
But you know it.
And you can react.

Shore power connected.
Or go for a cruise.
Or turn off the fridge at night.

No more surprises.
Just decisions.

And that's the difference between "I hope" and "I know".

---

After a few weeks you don't look at volts anymore.
You look at watt-hours.

And you wonder how you ever lived without it.

---
