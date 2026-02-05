# Volume 1 – Chapter 8: The Engine Runs

*And everything else I'm digitising now*

---

June.

Package on the table.

Raspberry Pi 4.

Phase 1 begins.

---

I think back.

To the beginning.

To the purchase.

To the boat.

---

14 months ago:

Bought a boat.

Well maintained.

Works.

Engine runs.

Everything floats.

Perfect.

---

But:

Voltmeter showed 12.0V.

Always.

Fuel gauge showed 3/4.

Always.

Knew nothing.

Guessed everything.

---

That bugged me.

Not much.

But enough.

---

First attempt:

Accept it.

"It works."

"Engine runs."

"That's enough."

---

Worked.

For a few months.

Until winter came.

And questions came.

---

"Is the battery full?"

No idea.

"How much diesel do I have?"

Estimate.

"Is the alternator charging?"

Probably.

---

That wasn't enough any more.

I wanted to know.

Not guess.

Know.

---

So:

YouTube.

50 tabs.

3 in the morning.

"ESP32 for boats"

---

Then:

Amazon.

€8.

"Just for testing."

Ha.

---

Then:

Breadboard.

LED blinks.

"Hello World!"

The first code.

The first success.

---

Then:

Voltage measurement.

11.8V.

Real.

Precise.

Digital.

---

Then:

First installation.

LED in the boat.

With smoke.

With mistakes.

With success.

---

Then:

Voltmeter.

Fixed.

Permanent.

Professional.

14.1V vs. 12.0V.

Proof delivered.

---

Then:

The vision.

Not just a voltmeter.

Everything.

Complete.

System.

---

And now:

Raspberry Pi.

Phase 1.

It begins.

---

14 months.

From "no idea"

To "I'm building a complete digitisation system."

---

That's...

That's a journey.

A learning journey.

A DIY journey.

An "I can do this!" journey.

---

What have I learned?

---

**Lesson 1:**

Prior knowledge helps.

Really.

Electronics experience saves weeks.

Every question has an answer.

But boat electrics still need learning.

The hard lessons come on the water.

---

**Lesson 2:**

Having your own parts is gold.

Full parts box means: start immediately.

No waiting for Amazon.

No budget stress.

Just do it.

---

**Lesson 3:**

Mistakes are normal.

LED gets hot? → Resistor.

Display stays black? → Solder joint.

Code crashes? → Serial Monitor.

Everything solvable.

---

**Lesson 4:**

Start small.

Blink an LED.

Then measure voltage.

Then display.

Then install.

Step by step.

---

**Lesson 5:**

Community helps.

Forums.

Reddit.

Discord.

Someone's had the problem before.

Always.

---

**Lesson 6:**

Documenting pays off.

Take photos.

Write notes.

Save code.

For later.

For others.

For myself.

---

But:

The most important lesson:

---

**Lesson 7:**

I can do this.

Really.

Without marine training.

Without a boat electrician's licence.

Just with:
- Willpower
- YouTube
- €8 of hardware
- Time

---

That's...

That's empowering.

Liberating.

Motivating.

---

I open the package.

Raspberry Pi 4.

Small.

Unassuming.

Will be the brain.

---

Next weeks:

Setup.

Learn Linux.

Install MQTT.

Learn Node-RED.

Build dashboard.

---

Next months:

Connect sensors.

Program ESP32s.

Integrate system.

Test.

Debug.

Finalise.

---

By December:

Done.

Complete.

Digitised.

---

That's the plan.

Will it work out?

No idea.

But I'll try.

---

The boat sits at the dock.

Knows nothing about plans.

LED shining.

Voltmeter shows 12.4V.

Engine sleeping.

---

But soon:

Dashboard.

Sensors.

Data.

Knowledge.

---

From analogue to digital.

From old to new.

From guessing to knowing.

---

That's the journey.

It begins now.

For real.

---

I look at the boat.

Then at the Raspberry Pi.

Back at the boat.

---

"This is where it starts."

---

Not as a repair.

Not as a necessity.

But as:

Improvement.

Modernisation.

Project.

---

Because I can.

Because I want to.

Because it's possible.

---

The engine runs.

Will run.

Always run.

Since 1985.

Until... who knows.

---

The engine needs nothing.

No ESP32.

No Raspberry Pi.

No dashboard.

---

Just runs.

Diesel in.

Ignition on.

Done.

---

But everything else?

That's getting an upgrade.

A massive upgrade.

---

That's the difference.

Between "works"

And "optimal."

---

Between "enough"

And "perfect."

---

Between "old"

And "modern."

---

The boat is good.

Has always been good.

Will always be good.

---

But:

Good isn't enough for me any more.

I want better.

---

Not because it's necessary.

But because it's possible.

---

That's the motivation.

The driving force.

The reason.

---

I unpack the Raspberry Pi.

Connect.

Boot.

Install.

---

The project begins.

Now.

Really.

---

The road is long.

7 months.

Many hours.

Many mistakes.

---

But:

I'm ready.

I've learned.

I have experience.

I have willpower.

---

And:

I have a boat.

That wants to get better.

That can get better.

That will get better.

---

The engine runs.

The keyboard types.

The journey begins.

---

Here ends Volume 1.

But the story continues.

In Volume 2.

And 3.

And 4.

And...

---

Because:

Digitisation has no end.

Only phases.

Projects.

Improvements.

---

The boat will never be "finished."

Will always be a project.

Will always be improvable.

---

But that's okay.

That's even good.

Because:

That's the fun.

That's the journey.

That's the hobby.

---

The engine runs.

And everything else?

I'm digitising it.

Now.

---

---

## EPILOGUE

### 3 years later...

---

December 2027.

Boat sits at the dock.

Winter.

Cold.

---

Dashboard in the cockpit:

7" touchscreen.

Live data:

```
┌─────────────────────────────┐
│    BOATOS v2.4              │
├─────────────────────────────┤
│  Battery 1:  13.8V   98%   │
│  Battery 2:  13.7V   96%   │
│  Battery 3:  12.9V   78%   │
│                             │
│  Diesel:     187 L   93%   │
│  Water:       78 L   52%   │
│                             │
│  Engine Temp:  OFF          │
│  Heater:      22.5°C  ON   │
│  Cabin:       21.8°C       │
│                             │
│  Solar:         0 W        │
│  Consumption:  35 W        │
│                             │
│  WiFi:         Online      │
│  Clients:      2           │
└─────────────────────────────┘
```

All live.

All precise.

All digital.

---

8 ESP32s installed:

- ESP32 #1: Battery monitoring (3× batteries)
- ESP32 #2: Tank levels (diesel + water)
- ESP32 #3: Engine data (temp, oil, RPM)
- ESP32 #4: Solar & consumption
- ESP32 #5: Temperatures (5× sensors)
- ESP32 #6: Heater control
- ESP32 #7: Bilge pump & alarms
- ESP32 #8: Navigation & GPS

---

Raspberry Pi 4:

- MQTT broker (Mosquitto)
- Node-RED dashboard
- InfluxDB (data logging)
- Grafana (historical data)
- WiFi access point
- VPN access (Tailscale)

---

All networked.

All centralised.

All accessible:

- On the touchscreen in the boat
- On the phone (WiFi)
- From home (VPN)

---

Features:

- Live monitoring of all values
- Historical data (1 year)
- Alerts for critical values
- Heater control via app
- Automatic bilge pump
- Solar yield tracking
- Diesel consumption per trip

---

Total cost:

Hardware: €487 (€27 over budget)

Time: ~180h (40h over estimate)

Nerves: priceless

Success: 100%

---

The boat is smart.

Really smart.

Smarter than many new builds.

---

Friends come aboard.

See the dashboard.

"What the hell?"

"BoatOS."

"You built that?"

"Yes."

"Mate."

---

They tap the screen.

Switch between views.

Battery.

Tank.

Solar.

History.

---

"That's... professional."

"Thanks."

"How long did it take?"

"3 years. On and off."

"And cost?"

"€500."

"WHAT?"

---

I show the old dashboard.

Next to it.

Still there.

As backup.

---

Voltmeter: 12.0V (still)

Fuel gauge: 3/4 (still)

Tachometer: something (still)

---

"Why still there?"

"A reminder."

"Of what?"

"Where I came from."

---

They nod.

Understand.

---

The old system:

Worked.

Always worked.

Will work.

---

The new system:

Is better.

Much better.

But:

Stands on the shoulders of the old.

---

Without the old:

No new.

Without "works":

No "optimised."

---

The old stays.

As respect.

As backup.

As history.

---

I start the engine.

Test.

---

Starter turns.

Engine hums.

Runs.

---

Dashboard shows:

```
Engine Temp:  Cold start
Oil Pressure: 3.8 bar   ✓
RPM:          850
Alternator:   14.2V     ✓
```

All live.

All precise.

---

Old voltmeter:

12.0V

Of course.

Never changed.

Never will.

---

Friend laughs.

"That old thing still shows 12.0?"

"Yup."

"And you keep it?"

"Yup."

"Why?"

---

I look at both displays.

Old and new.

Side by side.

---

"Because it reminds me."

"Of what?"

"That the engine runs."

---

Pause.

"Always?"

"Always."

---

"Since?"

"1985."

---

"And you digitised everything around it?"

"Yes."

---

"But the engine?"

"Just runs."

---

He nods.

Understands.

---

The engine:

Built 1985.

No electronics.

No sensors.

No computers.

---

Just:

Diesel.

Ignition.

Mechanics.

---

Running for 40 years.

Will keep running.

Always running.

---

Around it:

8 ESP32s.

1 Raspberry Pi.

47 sensors.

Countless lines of code.

---

All modern.

All digital.

All smart.

---

But the heart?

The heart is the engine.

1985.

Analogue.

Simple.

Reliable.

---

That's the irony.

The beauty.

The truth.

---

I digitise everything.

But the most important thing?

Doesn't need it.

Just runs.

---

The boat is smart now.

The dashboard is perfect.

The data is precise.

---

But:

Without the engine?

Without the heart from 1985?

---

None of it would matter.

---

The engine runs.

Has always run.

Will always run.

---

And that?

That's reassuring.

In a digitised world.

Where everything is complex.

Where everything is networked.

Where everything depends on software.

---

The engine runs.

Simply.

Without ifs or buts.

Since 1985.

---

That's the lesson.

The most important lesson.

After 3 years of digitisation.

---

Modern is good.

Digital is better.

Smart is great.

---

But:

Simple is unbeatable.

---

The engine runs.

The boat floats.

Everything else?

Is a bonus.

---

I look at the dashboard.

BoatOS v2.4.

3 years of work.

€500 in hardware.

180 hours of time.

---

And at the engine.

1985.

Unchanged.

Reliable.

---

Both have their place.

Both are important.

Both are right.

---

The new system shows me:

What's happening.

How much.

How well.

---

The old engine shows me:

That it runs.

Always runs.

Simply runs.

---

That's balance.

Modern and old.

Digital and analogue.

Smart and simple.

---

That's my boat.

2024 meets 1985.

ESP32 meets diesel.

Code meets mechanics.

---

And it works.

Everything works.

Better than ever.

---

The engine runs.

The dashboard glows.

The boat is ready.

---

For the next trip.

The next season.

The next improvement.

---

Because:

It's never finished.

Never will be.

---

But:

That's okay.

That's even good.

---

Because:

The journey is the destination.

Learning is the fun.

Building is the hobby.

---

And as long as the engine runs?

I can keep going.

Improving.

Digitising.

---

Forever.

---

**END Volume 1**

---

*The story continues in:*

**Volume 2: Power Is Never Simple**
*Solar, batteries & the reality of self-sufficiency*

**Volume 3: Sensors & Monitoring**
*ESP32, MQTT & hardware for beginners*

**Volume 4–5: BoatOS**
*The complete system – from vision to reality*

**Volume 6: The Valve Heater**
*Frost protection, clamshell & why you can't buy this*

**Volume 7: The Auto-Sat**
*GPS, stepper motors & automatic satellite alignment*

*More volumes in the works...*

---

*"The engine runs."*

*Always.*

⚓
