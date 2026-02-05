# Volume 1 – Chapter 6: The First Project

*LED instead of light bulb*

---

April.

Boat sits at the dock.

Me too.

With tools.

And a plan.

---

The plan:

Modernise the cabin lighting.

Old light bulb out.

LED in.

Simple.

Should work.

---

I have:
- LED strip (12V, warm white)
- Cable (red, black)
- Switch (new, no wiggle)
- Soldering iron
- Heat shrink tubing
- Optimism

---

Old light bulb:

5 watts.

Warm.

Inefficient.

But: working since 1985.

Getting replaced.

By progress.

---

LED strip:

3 watts.

Same brightness.

More efficient.

More modern.

Better.

Theoretically.

---

Step 1: Remove old lamp.

Loosen the screw.

Lamp comes down.

Two cables visible:
- Red
- Black

Classic.

Understandable.

Beautiful.

---

Step 2: Prepare LED strip.

Cut 20cm.

Strip the ends.

Solder cables on:
- Red to +
- Black to −

Heat shrink over it.

Heat gun.

Done.

---

Looks professional.

Feels professional.

I'm proud.

---

Step 3: Connect.

LED cable to boat cable.

Red to red.

Black to black.

Terminal block.

Tighten.

---

Step 4: Test.

Switch on.

LED lights up!

Bright!

Beautiful!

Perfect!

---

I lean back.

First project.

Successful.

In 30 minutes.

No problems.

No drama.

Just works.

---

I enjoy the moment.

For 5 minutes.

Then:

Do I smell something?

---

Odd.

Sweet.

Plastic?

I look around.

Where from?

---

LED strip.

Getting... warm?

Very warm.

Too warm.

---

I touch it.

"OUCH!"

Hot!

Very hot!

That's not normal!

---

Switch off.

Immediately.

LED off.

Heat remains.

Slowly cooling.

---

I look closer.

LED strip.

One LED is... brown.

Discoloured.

Others too.

Damn.

---

I check again.

Packaging of the LED strip:

"12V DC, 3W/m, warm white"

Boat has: 12V

Should fit.

But: doesn't.

---

I Google.

"LED strip getting hot"

Forum post:

"Too much current? Checked the power supply?"

I check.

Battery: 12.4V.

Engine running: 14.2V.

Ah.

---

Alternator running.

14.2V.

LED strip tolerates: 12V.

Difference: 2.2V.

Too much.

LED gets hot.

Dies slowly.

---

Google more:

"LED 12V overvoltage"

Solution: voltage regulator.

Or: buy 14V LEDs.

Or: put a resistor in series.

---

I don't have a voltage regulator.

No 14V LEDs.

But: resistors.

---

Second attempt.

Disconnect LED strip.

(The brown LED is done for, anyway.)

Find a resistor.

10 Ohm? 100 Ohm?

Which one?

---

Google: "Calculate resistor for LED"

Formula:

```
R = (Vin - Vled) / I

Vin = 14V (alternator)
Vled = 12V (LED)
Difference = 2V

I = 3W / 12V = 0.25A

R = 2V / 0.25A = 8 Ohm
```

I have: 10 Ohm.

Close enough.

Will work.

---

New LED strip.

20cm.

Solder resistor in series.

10 Ohm, 5 watt (important: power rating!).

Cable on.

Heat shrink.

---

Connect.

Again.

Terminal block.

Tighten.

Hope.

---

Switch on.

LED lights up.

I wait.

5 minutes.

10 minutes.

Touch:

Warm.

But not hot.

Resistor warm too.

But okay.

---

15 minutes:

LED lights up.

Not brown.

Not too hot.

Works!

---

Start engine.

Alternator at 14.2V.

LED keeps shining.

Evenly.

No hotter.

Resistor does its job.

---

Success!

On the second attempt!

Trial & error!

More error, less trial!

But: works!

---

I sit there.

Looking at the LED.

My first real boat project.

Small.

Just LEDs.

But: MINE.

---

Friend comes by.

"What are you doing?"

"Installed LEDs."

He looks.

"Looks good."

"Thanks. Was my second attempt."

"Second?"

"First one got too hot."

He laughs.

"Welcome to the DIY club."

---

We sit in the cockpit.

Beer open.

LED shining.

Friend asks:

"What's the next project?"

---

I think.

List in my head:

- ✅ LED lighting (done!)
- ☐ Install voltmeter (breadboard → permanent)
- ☐ Fuel gauge (ultrasonic sensor)
- ☐ Engine temperature
- ☐ Dashboard (permanent display)
- ☐ WiFi access
- ☐ ...

---

"Voltmeter. Permanent install."

"The breadboard one?"

"Yes."

"Permanently?"

"Yes."

"Can you do that?"

I hesitate.

"Don't know. But I'll try."

---

He nods.

"That's all it takes."

"What?"

"Trying. The rest follows."

He's right.

---

Evening.

Boat alone.

LED shining.

Warm.

Pleasant.

Self-built.

---

I think back:

3 months ago:

Knew nothing about ESP32.

Nothing about Arduino.

Nothing about LEDs and resistors.

---

Now:

Written code.

Built hardware.

Built a voltmeter (breadboard).

Installed LEDs (with mistakes, but successfully).

---

That's...

That's progress.

Real progress.

From "no idea" to "it works."

In 3 months.

---

The first project was small.

Just LEDs.

Just light.

But:

It was the proof.

Proof that I can do this.

That YouTube is enough.

That €8 of hardware is enough.

That willpower is enough.

---

The engine runs.

As always.

Doesn't care about LEDs.

Doesn't care about resistors.

Just runs.

Since 1985.

Unchanged.

Reliable.

---

But around it:

Things are changing.

LED instead of light bulb.

Digital instead of analogue.

Data instead of guessing.

Modern instead of old.

---

I switch off the LED.

Dark.

Boat sleeps.

Me too.

Satisfied.

---

Next day.

Sunday.

I come back.

With a new plan.

---

Voltmeter.

From breadboard to PCB.

Fixed.

Permanent.

Installed.

---

I have:
- Stripboard
- ESP32
- Resistors
- OLED display
- Case (3D printed, from a mate)
- Cables
- Soldering iron
- Courage

---

The plan:

Everything that works on the breadboard.

Transfer to PCB.

Solder permanently.

Into the case.

Install.

Done.

---

Reality:

Gets more complicated.

Much more complicated.

---

Soldering.

I'm not a soldering pro.

Looks like...

Mediocre.

But works.

Mostly.

---

ESP32 onto the board.

With pin headers.

(In case I need to swap it.)

Solder resistors.

100k and 47k.

Voltage divider.

---

OLED display.

4 pins.

VCC, GND, SDA, SCL.

Solder on.

Cable running out.

To the display.

---

2 hours later:

Board done.

Looks... handmade.

But: complete.

---

Test.

USB cable to ESP32.

Upload code.

Connect display.

Power on.

---

Display stays black.

Damn.

---

Check:

Cables right?

Yes.

Solder joints?

Look okay.

Code?

Same as before.

---

Multimeter out.

Continuity check.

VCC to display: no contact.

Ah.

---

Rework the solder joint.

More solder.

Better.

Test:

Continuity: yes!

---

Power on.

Display:

"Batt:
12.4 V"

YES!

Works!

---

Board into the case.

3D printed.

Black.

Professional.

---

Fits.

Almost.

ESP32 sticks out 2mm.

Lid won't close.

---

Dremel out.

Trim the lid.

2mm removed.

Try.

Fits!

---

Screw together.

Display on the outside.

Visible.

Cable out the back.

To the battery.

---

Install in the boat.

Dashboard.

Next to the old voltmeter.

The comparison.

---

Double-sided tape.

Holds.

For now.

Later: screws.

---

Route cables.

Through the wall.

To the battery.

Direct.

No fuse.

(Only measures, draws barely any current.)

---

Connect.

Plus to plus.

Minus to minus.

Power on.

---

Display glows.

In the boat.

Permanently installed.

Professional.

Self-built.

---

"Batt:
12.4 V"

Old voltmeter next to it:

"12.0 V"

The contrast remains.

---

Start engine.

New display:

"14.1 V"

Old display:

"12.0 V"

Completely ignores the alternator.

---

I sit there.

Looking at both.

Old and new.

Side by side.

---

The new one shows the truth.

The old one... shows something.

But the old one stays.

As backup.

As a reminder.

As "it was like that."

---

Friend comes by.

Sees the new display.

"Impressive. Looks professional."

"Thanks."

"How long did it take?"

"6 hours. Including mistakes."

"And cost?"

"€15."

"Mate."

---

He looks at the old voltmeter.

"And that one?"

"Stays. For comparison."

"Does it show correctly?"

"No."

"But it stays?"

"Yes."

He laughs.

"Typical boat."

---

We sit in the cockpit.

Two displays.

One shows 14.1V (true).

One shows 12.0V (false).

Both glow.

Both have their right to exist.

---

The first project was LEDs.

Small.

Simple.

But successful.

---

The second project was the voltmeter.

Bigger.

More complex.

But successful.

---

From breadboard to PCB.

From prototype to product.

From test to permanent.

---

The engine runs.

As always.

Doesn't care about displays.

Just runs.

14.1V alternator.

Since 1985.

Reliable.

---

But now I KNOW it.

14.1V.

Precise.

Live.

Measurable.

---

No longer:

"Engine's running, so it's fine."

But:

"Engine's running, charging at 14.1V, battery at 85%, everything perfect."

---

Data instead of assumptions.

Knowledge instead of guessing.

Measuring instead of estimating.

---

That's the difference.

Between "works" and "understanding."

Between "okay" and "optimal."

Between old and new.

---

I switch everything off.

LED off.

Display off (but stays live, barely draws current).

Engine off.

---

Boat sleeps.

But wakes up with data.

With information.

With knowledge.

---

The next project:

Fuel gauge.

Ultrasonic sensor.

Measures fill level.

Shows litres.

Precise.

Not "3/4" any more.

But "156 litres."

---

But that comes later.

First: enjoy.

Two successful projects.

LED: ✅

Voltmeter: ✅

---

From "no idea" to "2 successful projects."

In 4 months.

With YouTube.

With €8 of hardware.

With trial & error.

---

More error than trial.

But: error is learning.

Trial is trying.

Success is both together.

---

The first summer is coming.

With new LEDs.

With a new voltmeter.

With new knowledge.

---

And with the realisation:

I can do this.

Really.

Not just breadboard.

But: fixed. Permanent. In the boat.

---

That's just the beginning.

Voltmeter was small.

The vision is big.

Very big.

---

But more on that later.

First: be proud.

Of the LEDs.

Of the voltmeter.

Of myself.

---

The engine runs.

The LED shines.

The display shows data.

---

The boat is getting smart.

Slowly.

Project by project.

---

But it's happening.

---
