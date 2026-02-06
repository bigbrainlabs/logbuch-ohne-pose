# Volume 2 – Chapter 8: The System Learns Along

The ESP32 system runs.
The data flows.
MQTT hums in the background like a contented fridge.

But seeing data in the terminal is one thing.
Using it is another.

You need a dashboard.
Something you look at without thinking.
Something that shows at a glance: running or not running.

---

**The Requirement**

No Excel spreadsheet.
No log files.
No command line.

Simply: numbers, graphs, colours.
Red when it's bad.
Green when it's good.
Yellow when you should pay attention.

Like a cockpit.
Only for power.

---

**The Dashboard**

BoatOS on the Raspberry Pi.
Node-RED behind it, to process MQTT data.
A few widgets you click together.

Sounds complicated.
It is, at first.
But after the third attempt you know how it works.

You subscribe to the MQTT topics:
```
boat/energy/solar/power
boat/energy/consumption/total
boat/energy/battery/soc
```

And then you build widgets.

A gauge for solar.
A bar for the battery.
A graph for consumption over the last 24 hours.

After a few hours you have something that works.
After a few days you have something that looks good.
After a few weeks you have something you're proud of.

---

**What You See**

Solar power: live.
Not "should bring 260 Wp".
But: currently bringing 83 W.

That changes.
Every second.
Cloud passes by: 83 W → 12 W.
Cloud gone: 12 W → 91 W.

You see how sensitive solar is.
You see that a single cloud is enough to turn "charging well" into "barely charging".

You learn to hate clouds.
But you understand them too.

---

Consumption: live.
Not "about 1,200 Wh per day".
But: currently 14.2 W.

Fridge switches on: 14.2 W → 58 W.
Two minutes later: 58 W → 18 W.
Light on: 18 W → 28 W.

You see every consumer.
You see what draws how much.
You see that "just a quick light" spread over the day is 150 Wh.

Suddenly power is no longer abstract.
Power is visible.
And you start switching more consciously.

---

Battery SOC: live.
Not "somewhere between full and empty".
But: 68%.

With forecast:
"At current consumption: 32 hours remaining."

That's not perfect.
The forecast changes when consumption changes.
But it's a number.
A direction.
A sense of control.

You look at the dashboard in the morning like other people look at the weather.
And you plan your day accordingly.

---

**The Surprises**

You think you know how the boat runs.
Then you look at the dashboard and learn.

The fridge draws more at night than expected.
Not much more.
But enough to notice.
150 Wh instead of 100 Wh.

Why?
Because it's colder at night?
Because the compressor runs longer?
No idea.

But you see it.
And you can decide: turn off or not.

---

The light isn't the problem.
The radio is the problem.

Runs all day.
Only draws 8 W.
Sounds like nothing.

But 8 W × 12 hours = 96 Wh.
That's almost a tenth of daily consumption.

You turn off the radio when you're not listening.
Suddenly there's 100 Wh more in the battery.

Small change.
Big effect.

---

Solar in winter is even more depressing when you see it live.

Whole day cloudy: 180 Wh.
That's not even a quarter of consumption.

You look at the dashboard and think: Why do I even have solar?

Then a sunny day comes.
Three hours of sun in December: 420 Wh.

Ah. That's why.

You learn that solar isn't constant.
But you also learn when it's worth hoping for weather.

---

**The Forecast**

The dashboard can calculate.

Current consumption: 1,150 Wh/day.
Current solar yield: 650 Wh/day.
Difference: -500 Wh/day.

Battery has 1,800 Wh left.
At -500 Wh/day: 3.6 days remaining.

That's not a guarantee.
Tomorrow solar could be better.
Or consumption higher.

But it's orientation.
And orientation is more than you had before.

---

You start thinking strategically.

Three cloudy days forecast?
Connect shore power today.
Or go for a cruise.
Or turn off the fridge at night until the sun returns.

You don't react anymore.
You act.

That's the difference.

---

**What You Don't See**

The system shows a lot.
But not everything.

It doesn't show how old the battery is.
It doesn't show if the cells are balanced.
It doesn't show if there's a parasitic drain somewhere.

For that you need other tools.
Or a BMS with better data.

But what it shows is enough.
For everyday life.
For the decisions you make daily.

The system isn't perfect.
But it doesn't have to be perfect.

---

**The Routine**

After a few weeks the dashboard becomes habit.

Morning: quick look.
SOC? Consumption yesterday? Solar forecast today?

Evening: quick look.
How much solar came in? How much went out? Is it enough?

You don't plan big anymore.
You just look and know.

And when you know, you can relax.
Or act.
But you're no longer surprised.

---

**What Remains**

A system that thinks along.
Not intelligent.
But informed.

It doesn't say: "You need to connect shore power now."
It says: "SOC 42%. At current consumption: 18 hours remaining."

And you decide yourself.

That's the beauty of it.
You have the data.
You have the control.
You don't have to guess.

---

Self-sufficiency was the goal.
What it became: informed dependency.

You're not independent of power.
You're just no longer surprised by it.

You know when solar is enough.
You know when cruising helps.
You know when shore power is necessary.

And that's enough.

More than enough.

---

**Epilogue: One Year Later**

The dashboard runs.
Day after day.
Without pause, without complaint.

You look at it in the morning like the weather forecast.
You plan by it like a calendar.

Solar in summer: all good.
Solar in winter: less good, but you know it.

The battery holds.
The system works.
The numbers are right, mostly.

And if you're being honest:
You couldn't live without it now.

Not because it's perfect.
But because it's enough.

And "enough" is the new "perfect".

---

You sit in the cockpit in the evening.
Beer in hand.
Display shows: SOC 78%, consumption 11 W, solar tomorrow: sunny.

You lean back.

Power is never simple.
But with data it's simpler.

And that, that's enough.

---
