# Volume 1 – Chapter 7: The Vision

*Or: "I'm rebuilding the whole thing"*

---

May.

Boat sits at the dock.

LED shining.

Voltmeter shows 12.4V.

Two successful projects.

Small.

But successful.

---

I sit in the cockpit.

Notepad on my lap.

Pen in hand.

Thinking.

"What's next?"

---

List:

```
✅ LED lighting
✅ Voltmeter (digital)
☐ Fuel gauge
☐ Engine temperature
☐ Oil pressure
☐ RPM (accurate)
☐ Diesel flow meter
☐ ...
```

The list grows.

Fast.

---

Each "☐" is a project.

Each project is:
- ESP32 (€8)
- Sensor (€5–20)
- Time (hours)
- Code
- Installation

Doable.

All doable.

---

But:

8 projects.

8 ESP32s.

8× programming.

8× installing.

Individually.

---

I look at the dashboard.

Voltmeter: new, digital.

Next to it: old voltmeter.

Next to that: tachometer (analogue).

Next to that: fuel gauge (lying).

Next to that: depth gauge (okay).

Next to that: 12 switches (half known).

---

All separate.

All on their own.

No connection.

No integration.

No system.

---

The idea forms.

Slowly.

Creeping.

---

"What if..."

"What if I brought ALL of this..."

"...together?"

---

One system.

One dashboard.

One display.

All the data.

Central.

Modern.

---

I sketch:

```
┌─────────────────────────┐
│    BOAT DASHBOARD       │
├─────────────────────────┤
│  Battery:  12.4V  85%  │
│  Tank:     156 L       │
│  Engine:   82°C        │
│  RPM:      1,850       │
│  Oil:      3.2 bar     │
├─────────────────────────┤
│  Everything on one      │
│  display!               │
└─────────────────────────┘
```

That would be...

That would be perfect.

---

I Google.

"Boat dashboard DIY"

"Marine display custom"

"ESP32 dashboard"

---

Results:

- SignalK server
- Node-RED dashboard
- Grafana
- Raspberry Pi as hub

Concepts.

Lots of concepts.

---

A video:

"Complete boat monitoring with Raspberry Pi"

45 minutes.

I watch.

---

The guy shows:

- Raspberry Pi (€50)
- Multiple ESP32s (€8 each)
- MQTT broker
- Node-RED
- Dashboard on tablet
- WiFi throughout the boat

---

All networked.

All data centralised.

Accessible from anywhere.

Phone.

Tablet.

Laptop.

---

That's...

That's exactly what I want!

Not 8 individual projects.

But:

ONE system.

For everything.

---

I pause the video.

Take screenshots.

Notes.

---

Components:

```
Hardware:
- Raspberry Pi 4 (4GB): €60
- 5× ESP32: €0 (from the drawer)
- Sensors: ~€100
- Cables, cases: €30
- Display (7" touch): €80

Software:
- Raspbian OS: free
- Mosquitto MQTT: free
- Node-RED: free
- All open source!

Total: ~€310
```

---

I look at the number.

€310.

For a complete system.

Not individual projects.

But:

All integrated.

Centrally controlled.

Professional.

---

Raymarine equivalent:

Multifunction display: €1,500

Plus sensors: +€800

Plus installation: +€500

Total: €2,800

---

My system: €310.

Difference: €2,490.

And: I understand it.

Can customise it.

Extend it.

Repair it.

---

The decision is clear.

I'm building it.

Completely.

From the ground up.

---

But:

This is big.

Very big.

Not a "little project" any more.

But:

Complete digitisation.

---

I make a new list.

Not "projects."

But "phases."

---

```
PHASE 1: Foundation
☐ Raspberry Pi setup
☐ MQTT broker
☐ Install Node-RED
☐ Basic dashboard

PHASE 2: Sensors
☐ Battery monitoring (3× batteries)
☐ Tank level
☐ Engine data (temp, oil, RPM)
☐ Diesel flow

PHASE 3: Integration
☐ Connect all ESP32s
☐ Finalise dashboard
☐ WiFi access point
☐ Mobile access

PHASE 4: Extensions
☐ Heater control
☐ Bilge pump monitor
☐ GPS/Navigation
☐ Alerts & notifications
```

Four phases.

Many months.

But: doable.

---

I look at the old list.

8 individual projects.

Then at the new list.

1 big system.

---

The new list is better.

More thought-through.

More complete.

More right.

---

But also:

Bigger.

More time-consuming.

More expensive.

---

I calculate:

```
Time (estimated):
- Phase 1: 20h
- Phase 2: 40h
- Phase 3: 30h
- Phase 4: 50h

Total: 140h

At 5h/week: 28 weeks
= 7 months
```

7 months.

Almost a year.

Until everything's done.

---

Cost:

```
Hardware: €310
Reserve (mistakes, replacements): €100
Tools (still to buy): €50

Total: €460
```

Not cheap.

But doable.

Spread over 7 months.

~€65/month.

---

I look at the boat.

Then at the list.

Back at the boat.

---

This is it.

This is THE idea.

Not "improve a little."

But:

"Rebuild completely."

---

Partner comes aboard.

Sees the notepad.

Sketches.

Lists.

Numbers.

---

"What are you planning?"

I show her.

Dashboard sketch.

Phase plan.

Cost overview.

---

She reads.

Silent.

Thinks.

---

"That's... big."

"Yes."

"And expensive."

"Not too bad. €460."

"Over how long?"

"7 months."

---

Pause.

"And all this... for data?"

"Yes."

"Do you need it?"

I think.

"No."

"But?"

"But I want it."

---

She smiles.

"You're crazy."

"Yes."

"But it's your boat."

"Our boat."

"Your project."

---

She looks at the sketch.

Dashboard.

All the data.

Central.

Modern.

---

"That looks... professional."

"It will be."

"Can you really do this?"

"Don't know. But I'll try."

---

She nods.

"Okay. But:"

"What?"

"Stick to the budget."

"Promise."

"And no new projects on the side."

"Promise."

"Finish first, then expand."

"Promise."

---

She leaves.

I stay.

With the list.

The vision.

The plan.

---

Evening.

At home.

Excel open.

---

Table 1: Budget

```
┌──────────────────────┬────────┬────────┐
│ Component            │ Price  │ Status │
├──────────────────────┼────────┼────────┤
│ Raspberry Pi 4       │  €60   │   ☐    │
│ ESP32 (5×)           │  €40   │   ☐    │
│ Sensor set           │ €100   │   ☐    │
│ 7" touch display     │  €80   │   ☐    │
│ Cables & cases       │  €30   │   ☐    │
│ Tools                │  €50   │   ☐    │
│ Reserve              │ €100   │   ☐    │
├──────────────────────┼────────┼────────┤
│ TOTAL                │ €460   │        │
└──────────────────────┴────────┴────────┘
```

Looks doable.

---

Table 2: Timeline

```
┌───────┬──────────────────┬──────────┐
│ Month │ Phase            │ Cost     │
├───────┼──────────────────┼──────────┤
│ Jun   │ Phase 1: Setup   │   €90    │
│ Jul   │ Phase 2a: Batt   │   €50    │
│ Aug   │ Phase 2b: Tank   │   €40    │
│ Sep   │ Phase 2c: Engine │   €80    │
│ Oct   │ Phase 3: WiFi    │   €50    │
│ Nov   │ Phase 4a: Heat   │   €60    │
│ Dec   │ Phase 4b: Rest   │   €90    │
├───────┼──────────────────┼──────────┤
│       │ TOTAL            │  €460    │
└───────┴──────────────────┴──────────┘
```

7 months.

Order something every month.

One step closer every month.

By December: done.

---

I lean back.

This is it.

The plan.

The vision.

The project.

---

No longer:

"I'll build a voltmeter."

But:

"I'm digitising the entire boat."

---

That's...

That's insane.

Ambitious.

Big.

Maybe too big.

---

But:

I've built LEDs.

I've built a voltmeter.

I've written code.

I've soldered.

I've learned.

---

If I can do that...

I can do the rest.

One step at a time.

One project at a time.

One phase at a time.

---

I save the spreadsheet.

"Boat_Digitisation_Master_Plan.xlsx"

Sounds official.

It is.

---

I open Amazon.

Basket:

- Raspberry Pi 4 (4GB)
- Official power supply
- 32GB MicroSD
- Case with fan

Total: €89.

Phase 1.

---

Finger hovering over the "Order" button.

Hesitate.

---

This is the point of no return.

If I order now:

No going back.

Project is live.

7 months.

€460.

140 hours.

---

But:

I want this.

Really.

Not because it's necessary.

But because it's possible.

---

Click.

"Order."

---

Order placed.

Arriving: tomorrow.

---

It has begun.

The digitisation.

The transformation.

From "old boat" to "smart boat."

---

The engine runs.

As always.

Doesn't care about plans.

Doesn't care about Raspberry Pi.

Just runs.

Since 1985.

Unchanged.

Reliable.

---

But around it:

Everything changes.

Analogue becomes digital.

Old becomes new.

Guessing becomes knowing.

---

I look at the order confirmation.

Raspberry Pi 4.

Arriving tomorrow.

Then it begins.

---

Partner comes in.

"Did you order?"

"Yes."

"How much?"

"€89. First instalment."

She sighs.

"You're really doing this."

"Yes."

"Madness."

"Yes."

---

She smiles.

"Good luck."

"Thanks."

"And don't forget:"

"What?"

"Document it. For others."

"Why?"

"Because you need to show this."

---

Document.

Good idea.

Take photos.

Save code.

Write notes.

---

Maybe.

At some point.

When it's done.

A blog?

A guide?

A... book?

---

But that comes later.

Much later.

First: build.

Learn.

Do.

---

The vision is clear:

Complete boat digitisation system.

Central.

Integrated.

Modern.

---

The road is long:

7 months.

4 phases.

Countless hours.

Many mistakes.

Even more learning.

---

But:

I'm ready.

Built LEDs.

Built a voltmeter.

Proved: I can do this.

---

Now:

It gets big.

Really big.

---

The boat doesn't know it yet.

Sits quietly at the dock.

LED shining.

Voltmeter shows 12.4V.

Engine sleeping.

---

But soon:

Raspberry Pi.

Sensors everywhere.

Dashboard.

Data.

Knowledge.

---

From "works somehow"

To "I know exactly what's happening."

---

That's the vision.

That's the plan.

That's the project.

---

The engine runs.

Will always run.

Unchanged.

Reliable.

Since 1985.

---

But everything else?

Gets new.

Digital.

Modern.

Smart.

---

Next summer:

Boat with a system.

With data.

With knowledge.

---

No more guessing.

But knowing.

---

That's worth it.

€460.

140 hours.

7 months.

---

For certainty.

For knowledge.

For control.

---

And for the fun.

The fun of building.

Of learning.

Of understanding.

---

The boat works.

Has always worked.

Will always work.

---

But now:

It's getting smart.

---
