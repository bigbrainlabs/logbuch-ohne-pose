# Volume 1 – Chapter 2: The First Inspection

*Archaeology below deck*

---

January.

The boat sits at the dock.

Shore power connected, heater running (mostly), all quiet.

Time to REALLY look around.

Not superficially like during the purchase.

But: thoroughly.

---

I took a Saturday.

Toolbox, torch, notepad.

Plan: trace every cable.
Understand every instrument.
Map every fuse.

"How hard can it be?"

---

Dashboard.

Let's start at the top.

Left: Tachometer.
Analogue, with a needle, classic.
Looks like 1980s.
Probably is.

Function: Shows RPM.
Sometimes.
When it feels like it.

At 800 RPM the needle reads 1,000.
At 2,000 RPM it reads 2,400.

Inaccurate, but consistently inaccurate.

You get used to it.

---

Centre: Voltmeter.

Digital, 3 digits, red LEDs.

12.0

Always.

No matter what happens.

Engine on? 12.0
Engine off? 12.0
Shore power connected? 12.0
Battery half empty? Probably also 12.0

The thing is less a measuring device than an art installation.

Shows that power IS there.

How much?

Irrelevant.

---

Right: Depth gauge.

Digital, more recent, works.

Shows depth.

Correctly.

Reliably.

The only instrument I trust.

---

Far right: Fuel gauge.

Analogue, needle, scale from E to F.

Needle sits at 3/4.

For months.

Whether I fill up.
Whether I drive.

3/4.

Schrödinger's tank.

Is it full? Is it empty? Both at the same time?

You don't know until you run out and drift.

---

Below the dashboard: switches.

12 of them.

Toggle switches, old, plastic.

Half of them labelled.

"Light," "Pump," "Heater," "Nav."

The other half: mysteries.

Switch 7: Does what?
I flick it.
Nothing happens.

Again.
Nothing.

Okay.

Switch 8: Does what?
I flick it.
A light comes on.

Which light?

No idea.

Somewhere a light comes on.

---

I make a list:

```
Switch overview:
1. Light cabin       ✓
2. Light exterior    ✓
3. Bilge pump        ✓
4. Heater            ✓ (loose connection)
5. Navigation        ✓ (GPS)
6. ???               ?
7. ???               ? (does nothing?)
8. Light ???         ? (something lights up)
9. ???               ?
10. Outlet           ✓
11. ???              ?
12. ???              ? (or reserve?)
```

50% success rate.

Good enough for daily use.

---

Fuse box.

Under the seat, port side.

Open the hatch.

10 fuses, 2 rows.

Top:
1. Light - 10A
2. Pump - 10A
3. Engine - 20A
4. Heater - 15A
5. Miscellaneous - 10A

Bottom:
6. Reserve - empty
7. Reserve - empty
8. GPS - 5A
9. ??? - 10A (installed, but for what?)
10. Reserve - empty

Miscellaneous.

My favourite word.

---

I trace the cables.

From the fuse box outward.

Black = negative.
Red = positive.

So far, so standard.

But then:

Yellow cables.
White cables.
Blue cables.
One green cable (lone wolf).

All going somewhere.

Where?

Good question.

---

I follow a yellow cable.

From the fuse box to the outlet.

Makes sense.

Why yellow?

Because previous owner #1 (circa 1995, I'm guessing) liked yellow.

Works though.

---

White cable.

From the fuse box to... the battery?

No.

To a SECOND battery.

Wait.

Two batteries?

I check.

Yes.

Two batteries.

One large (main battery, 100 Ah).
One small (GPS battery, 40 Ah).

The GPS has its own battery.

Why?

"It was like that when I bought it."

Presumably.

---

Blue cable.

From the fuse box to the bilge pump.

Why blue?

Because previous owner #3 (circa 2015, estimated) had blue.

Or because "bilge = water = blue"?

Creative logic.

But works.

---

Green cable.

Lone wolf.

Goes from... somewhere... to... somewhere else.

I trace it.

Starts at the fuse box (not connected).
Goes through the wall.
Ends... nowhere.

Cut off.

Insulated.

Waiting.

For what?

No idea.

Probably a project that never got finished.

---

I sit down.

Notepad full.

Drawings, arrows, question marks.

The electrical system is... organic.

Grown.

Over 40 years.

Four previous owners.

Each with their own style.

---

Layer 1 (1985): Original.

Black = negative.
Red = positive.
Simple, clear, works.

Main battery, engine, light, pump.

Base system.

Solid.

---

Layer 2 (1995): Previous owner #1.

"I need an outlet."

Yellow cable from the fuse box.
New fuse: "Miscellaneous."
Outlet installed.

Works.

Documentation?

"It was like that."

---

Layer 3 (2005): Previous owner #2.

"GPS would be nice."

Second battery installed (for whatever reason).
White cable routed.
GPS mounted.

Runs.

But: GPS takes 10 minutes to start.

Why?

Because the battery is half empty?
Because the GPS is old?
Both?

"It was like that."

---

Layer 4 (2015): Previous owner #3.

"Automatic bilge pump would be good."

Blue cable.
Float switch.
Pump runs automatically.

Works!

Except when it doesn't.

Sometimes it runs.
Sometimes it doesn't.

Loose connection in the float switch?

Probably.

"It was like that."

---

Layer 5 (2024): Me.

Staring at the masterpiece.

Understand half of it.
Guessing the other half.

Everything works.

Somehow.

But WHY it works?

Magic.

Or luck.

Or both.

---

I take a photo.

Fuse box, cables, everything.

Send it to a friend.

"Check out my boat."

Reply: "Mate. That's art."

Yes.

Modern art.

"Electrical Installation, mixed media, 1985–2024."

Would hang in a museum.

---

That evening I sit at home.

Laptop open.

Google: "Boat electrics tidy up"

First results:
- "Redo completely"
- "Professional boatyard"
- "Costs €5,000"

Second results:
- "DIY for beginners"
- Arduino
- ESP32
- Self-build

Interesting.

---

I click.

YouTube video: "Boat electrics with Arduino"

30 minutes later: 5 more videos.

"ESP32 battery monitor"
"MQTT for boats"
"DIY instrument display"

Rabbit hole.

---

2 hours later.

I look into my parts box.

Shopping list:
- ESP32 DevKit (already got one)
- Voltage divider (box, got it)
- Cables (€10)
- Resistors (€3)

Total: €26

"Just for testing," I think.

Checkout.

---

A week later the package arrives.

I unpack it.

ESP32. Old friend, new project.

"From today, you're the boat ESP."

---

3 years later:

8 ESP32s installed.
47 sensors.
3 hand-soldered PCBs.
Custom operating system.
Dashboard for everything.

The original electrics?

Still running.

Unchanged.

Layer 6 (my layer) is ON TOP.

Like a digital skin.

The old electrics stay.

As backup.

As a reminder.

As "it was like that."

---

The engine?

Still running.

Doesn't care about layers.

Doesn't care about ESP32s.

Only cares about diesel and ignition.

Runs.

As always.

---

But that came later.

Much later.

First I had to learn how boat electrics tick.

And that 12V at the dock isn't the same as 12V from a bench power supply.

Trial & error.

Lots of error.

Little trial.

But: it came together.

---

At the end of the day I sat in the boat.

Looked at the dashboard.

Voltmeter: 12.0V.
Fuel gauge: 3/4.
Tachometer: Something.

And thought:

"I'm rebuilding this."

Not because it's broken.

But because I can do it BETTER.

I think.

I hope.

I'll try.

---

The first step: LEDs.

How hard can it be?

---
