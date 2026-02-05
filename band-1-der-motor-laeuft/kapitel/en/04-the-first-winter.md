# Volume 1 – Chapter 4: The First Winter

*Questions upon questions*

---

December.

Cold.

Boat sits at the dock.

Hibernation.

Not mine.

---

Shore power connected.

Cable from the dock to the boat.

16 amps.

Should be enough.

For: battery charging, heater, lights.

Should.

---

I come on Saturday.

Step aboard.

Cold.

Very cold.

Heater not running.

---

Check the switch.

On.

Or so I thought.

I wiggle.

Left, right, in, out.

Nothing.

Again.

Nothing.

---

The loose connection is dead.

Not "needs finesse."

But: dead.

Contact gone.

Heater off.

Winter here.

Problem too.

---

Plan B: Electric heater.

Small, 500 watts.

Plug it into the outlet.

Boat has shore power, should work.

Plug in.

Heater... doesn't work.

Wait.

---

Check the fuse.

"Miscellaneous" (of course).

Out.

Blown.

New one in.

10A.

Heater on.

Works!

Five minutes later: off.

Fuse blown again.

---

500 watts.
12 volts.
Equals: 41 amps.

Fuse is 10A.

Maths says: won't work.

Reality confirms: won't work.

I'm sitting in a cold boat.

Learning Ohm's law.

The practical way.

---

Plan C: Bigger fuse.

20A.

In.

Heater on.

Works!

Ten minutes later: fuse is hot.

Very hot.

Smells funny.

Off.

---

I give up.

Boat stays cold.

Me too.

Go home.

Frustrated.

---

January.

Next visit.

Colder.

Even colder.

Boat frozen?

No.

But: cold.

---

Check the battery.

Voltmeter: 12.0V

Of course.

But IS the battery full?

No idea.

Shore power's been running for a month.

Should be full.

SHOULD.

---

I start the engine.

Test.

Turn the key.

Starter...

...turns heavy.

Engine coughs.

Twice.

Three times.

Then: hum.

Runs.

But: reluctantly.

---

Engine off.

Voltmeter: 12.0V

Was 12.0V before.

Is 12.0V now.

Helps me ZERO.

---

Is the battery now:
- At 100% (fully charged)?
- At 80% (okay)?
- At 50% (critical)?

Voltmeter says: "Yes."

Helpful.

---

I Google on my phone.

"12V battery state of charge"

Table:
```
12.6V = 100%
12.4V = 75%
12.2V = 50%
12.0V = 25%
11.8V = dead
```

Ah.

My battery is at 25%?

Or does the voltmeter show 12.0V because it always shows 12.0V?

Both possible.

No idea.

---

I go to the outlet.

Check the shore power connection.

Plug in: yes.

Power arriving: presumably.

LED on the charger lit: no.

Wait.

---

Check the charger.

Plug in.

LED off.

Look for a switch.

Find one.

Flip it.

LED: on.

Ah.

---

The charger was OFF.

For a month.

Shore power was arriving.

But not being used.

Battery wasn't charging.

Only discharging.

From the onboard electrics.

Which draw something.

Always.

---

Voltmeter: 12.0V

But really: probably 11.8V.

So: nearly empty.

No wonder the engine started hard.

---

I turn on the charger.

LED glows green.

"Charging."

Good.

I wait.

One hour.

---

Voltmeter after one hour: 12.0V

Of course.

Is the battery fuller now?

No idea.

Voltmeter says: same as before.

Helpful: zero.

---

I drive home.

Frustrated.

Cold.

Angry at a voltmeter.

That can't do its one job.

Namely: show voltage.

Correctly.

---

February.

Third visit.

Even colder.

But: prepared.

Multimeter in hand.

---

Multimeter on the battery.

Direct.

Measure.

12.4V.

Ah.

FINALLY a real number.

---

Voltmeter on the dashboard: 12.0V

Multimeter on the battery: 12.4V

Difference: 0.4V

The voltmeter isn't broken.

It's just... optimised.

For one number.

12.0.

Always.

---

I switch on the lights.

Multimeter: 12.3V (drops slightly)

Voltmeter: 12.0V (doesn't move)

I start the engine.

Multimeter: 14.1V (alternator charging!)

Voltmeter: 12.0V (couldn't care less)

---

The thing is hopeless.

It doesn't show voltage.

It shows "power exists."

Binary.

On or off.

12.0 = on.

Everything else: invisible.

---

I note:

```
Problems:
1. Voltmeter useless
2. Battery state unknown
3. Charger was off (switch!)
4. Heater dead
5. Fuses too small
6. Fuel gauge still lying
7. I know NOTHING
```

The list is depressing.

---

But:

Engine runs.

Still.

Despite a nearly empty battery.

Despite winter.

Despite everything.

The engine is the MVP.

Most Valuable Part.

---

Evening at home.

Laptop open.

YouTube.

"Boat electrics done right"

Video: 45 minutes.

I watch.

Learn.

Understand.

---

The guy in the video explains:

Voltmeter needs to go directly to the battery.

Not through fuses.

Not through switches.

Direct.

Then it shows real values.

---

My voltmeter?

Goes through 3 fuses.

2 switches.

And probably a relay.

No wonder it shows 12.0V.

It's measuring somewhere in the middle.

Where there's always 12.0V.

Because: battery has 12.4V.

Voltage drop: 0.4V.

Remainder: 12.0V.

Always.

---

I could rewire it.

Run a new cable.

Direct to the battery.

Would work.

Or:

I could build it NEW.

Digital.

With ESP32.

For €15.

---

Second video.

"DIY battery monitor with ESP32"

30 minutes.

Schematic.

Code.

Instructions.

Looks... doable.

---

I pause the video.

Screenshot.

Save.

"Project_Voltmeter.png"

Create folder: "Boat_Projects"

First file in it.

---

Third video.

"Boat heater repair"

The guy in the video:

"Loose connection? Replace the switch. €5. 10 minutes."

Sounds easy.

Probably is.

I note: "Buy switch"

---

Fourth video.

"Fuel gauge calibration"

40 minutes about resistors.

Sender in the tank.

Receiver on the dashboard.

Calibration.

Complicated.

---

Or:

"DIY fuel gauge with ultrasonic sensor"

€15 sensor.

Measures fill level.

ESP32 converts.

Display shows litres.

Precise.

Simple.

Better.

---

Tab 5, 6, 7...

"MQTT for boats"

"SignalK introduction"

"Node-RED dashboard"

Concepts.

Lots of concepts.

Understand half.

But: interesting.

---

I look at the clock.

23:47.

I've been watching YouTube for 3 hours.

Have 12 tabs open.

Notes on 3 pages.

Amazon basket: €87.

---

Buster comes padding in.

Lies down next to the desk.

Looks at me.

With that look.

That "You do know it's 11 PM?" look.

I know, Buster. I know.

But: 12 tabs open.

Amazon basket full.

Notes on 3 pages.

---

Pause.

Buster yawns.

Loudly.

Demonstratively.

Rolls over.

Falls asleep.

Mid-sentence.

Dogs have no appreciation for digitisation.

But honestly?

He's right.

It's late.

---

Buster snores.

Quietly.

Contentedly.

He has his bed.

I have 12 tabs.

To each their own happiness.

I think it over.

"No. You don't have to."

"But?"

"But I WANT to know."

---

I look at Buster.

Then at the screen.

He goes.

I stay.

YouTube keeps playing.

---

Tab 13: "ESP32 boat monitoring tutorial"

Tab 14: "Install Arduino IDE"

Tab 15: "How does I2C work"

Tab 16: "Connect OLED display"

Tab 17: "Calculate voltage divider"

---

Parts box inventory:

- ESP32 DevKit (already got one)
- Voltage divider (box, got it)
- OLED Display 0.96" (box, three of them)
- Resistors (whole drawer full)
- Breadboard (got it)
- Jumper cables (got them)
- USB cable (got it, ten of them)
- Ultrasonic sensor (€12, need to order that one)
- Temperature sensor DS18B20 (box, five of them)
- Current sensor INA219 (€18, order that too)
- ...

To order: €30. Rest: already here.

"Finally a project."

Sure.

---

I look at the list.

Then at the boat photo.

Dashboard.

Voltmeter: 12.0V (useless).

Fuel gauge: 3/4 (lying).

Then at the YouTube videos.

ESP32.

Small.

€8.

Can do everything.

---

The decision ripens.

Not suddenly.

Creeping.

Over weeks.

Over videos.

Over frustration.

Over the will to make it better.

---

March.

Boat still cold.

Me too.

But: prepared.

---

New switch bought: €5.

Installed: 10 minutes.

Heater runs: yes.

Without wiggling: yes.

Problem solved: yes.

---

That was easy.

Too easy.

Should have done it sooner.

But: done.

Heater works.

Boat gets warm.

Me too.

Better.

---

I sit in the warm boat.

Look at the dashboard.

Voltmeter: 12.0V

Fuel gauge: 3/4

And think:

"Next project: digital voltmeter."

Then: "Digital fuel gauge."

Then: "Everything digital."

---

The winter was frustrating.

Cold.

Full of questions without answers.

Voltmeter useless.

Battery unknown.

Heater dead.

---

But:

Now I know what I DON'T want:

Guessing.

Estimating.

Hoping.

"Works somehow."

---

I want data.

Real data.

Numbers.

Facts.

Knowing what's going on.

Not assuming.

---

ESP32 is at home.

On the desk.

Waiting.

Tutorials are bookmarked.

Code is downloaded.

Arduino IDE installed.

Ready.

---

The winter was the preparation.

The frustration.

The motivation.

The drive.

---

The summer will be the execution.

The first project.

LED lighting.

Then voltmeter.

Then... we'll see.

Start small.

(Ha. No.)

---

The engine?

Ran all winter.

Every time.

No drama.

Despite a nearly empty battery in January.

Despite the cold.

Despite everything.

---

I sit in the boat.

Heater running (finally).

Voltmeter shows 12.0V (useless).

Engine running (reliable).

---

And I think:

"Next winter will be different."

Digital.

Measurable.

Understandable.

---

But first: summer.

And the first project.

LEDs.

How hard can it be?

---

Spoiler:

Harder than expected.

Smoke included.

But: educational.

---

The first winter was tough.

Cold.

Frustrating.

Full of "I don't know."

---

The second winter will be better.

Warmer.

With data.

With knowledge.

With "I know exactly."

---

I think.

I hope.

I'll build it.

---
