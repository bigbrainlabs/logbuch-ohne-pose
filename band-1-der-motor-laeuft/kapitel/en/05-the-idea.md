# Volume 1 – Chapter 5: The Idea

*Or: "I can do this too!"*

---

March.

At home.

Desk.

ESP32 lying there.

Small.

Unassuming.

€8.

Supposed to digitise my boat.

Doesn't look like it.

---

YouTube tutorial, video 1:

"ESP32 for absolute beginners"

Length: 22 minutes.

I press play.

---

The guy in the video explains:

ESP32 = mini computer.

WiFi, Bluetooth, 30 pins.

Programmable.

Can read sensors.

Can drive displays.

Can... everything.

For €8.

---

I look at the ESP32.

Then at the video.

Back to the ESP32.

"This thing does WiFi?"

Video says: Yes.

"And Bluetooth?"

Video says: Yes.

"For €8?"

Video says: Yes.

I'm impressed.

---

Video continues:

"Install Arduino IDE."

Pause.

I Google: "Arduino IDE download"

Click.

Download.

Install.

5 minutes later: done.

---

Open Arduino IDE.

Looks like... a code editor?

Menu at the top.

Empty file.

Cursor blinking.

I have no idea what I'm doing.

---

Video continues:

"Open Board Manager."

I click.

List appears.

"Install ESP32."

I search.

Find it.

Click Install.

Downloads.

Installs.

Done.

---

"Select board: ESP32 Dev Module"

I select.

"Select port: COM3"

I select COM3.

"Connect USB cable."

I connect.

ESP32 blinks briefly.

Alive.

---

Video shows code:

```cpp
void setup() {
  Serial.begin(115200);
  Serial.println("Hello World!");
}

void loop() {
  delay(1000);
}
```

I type it out.

Exactly like that.

Without understanding.

---

"Press upload."

I press.

Arduino IDE thinks.

"Connecting..."

"Uploading..."

"Done."

---

"Open Serial Monitor."

I open.

Black window.

Empty.

Then:

"Hello World!"

---

I stare at it.

A mini computer.

For €8.

Says "Hello World."

To me.

Over USB.

---

That's... cool.

Very cool.

I just wrote my first code.

Okay, typed it out.

But: works!

---

Video 2:

"Make an LED blink"

The classic.

Everyone starts with this.

---

Code:

```cpp
void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);
}
```

I type.

Upload.

---

ESP32 has an internal LED.

Pin 2.

It blinks.

On.

Off.

On.

Off.

---

I just programmed an LED.

To blink.

With code.

That I wrote.

(Typed out.)

But still:

I'm a programmer now.

Feels like it.

---

Video 3:

"Connect an external LED"

Now it gets practical.

---

Get out the breadboard.

Get out an LED.

Get out a resistor (220 Ohm, says the video).

Get out jumper cables.

---

Video explains:

LED, resistor, breadboard. Got them. Standard stuff.

I can do this in my sleep.

Have been for years.

But:

Boat electrics are a different beast to the parts box.

---

Wiring:

ESP32 Pin 2 → Resistor → LED (+) → LED (-) → GND

Just like the video.

Hope: works.

Reality: ...

---

Upload code.

Same as before.

LED blinks!

External!

On the breadboard!

I've controlled hardware!

With software!

---

I lean back.

Grin.

That was easy.

Much easier than expected.

LED blinks.

I've understood it.

More or less.

---

Buster lifts his head.

Looks at the blinking light.

Blinking LED.

Buster watches.

LED blinks.

On. Off. On. Off.

On. Off. On. Off.

Buster tilts his head.

---

The way dogs do.

When their human does weird things.

What he doesn't know:

This is just the beginning.

Everything else is human stuff.

The LED keeps blinking.

"Yes."

Dogs are wise.

They know when to stop.

He goes.

LED keeps blinking.

---

Video 4:

"Measure voltage with ESP32"

NOW it gets relevant.

---

ESP32 has an ADC.

Analogue-to-digital converter.

Can measure voltage.

0–3.3V directly.

More: need a voltage divider.

---

Boat has 12V.

ESP32 tolerates 3.3V.

12V straight to the ADC? Obviously not. Not my first rodeo.

So: voltage divider.

Got everything I need.

---

Voltage divider:

Know this.

Calculated it a hundred times.

But: 12V boat battery is a different thing from a 5V bench power supply.

12V become 3.3V.

Maths.

---

Quick calculation:

```
Vout = Vin × (R2 / (R1 + R2))

For 12V → 3.3V:
R1 = 100kΩ
R2 = 38kΩ
```

I have:
- 100kΩ: Box. Three bags.
- 38kΩ: Not exactly, but 47kΩ works.

47kΩ gives 3.5V at the ADC.

Enough headroom.

Works.

---

Build on breadboard:

12V (power supply) → R1 (100kΩ) → R2 (47kΩ) → GND

Between R1 and R2: tap point

Tap → ESP32 Pin 34 (ADC)

---

Code:

```cpp
void setup() {
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(34);
  float voltage = value * (3.3 / 4095.0);
  float battery = voltage * 4.0; // back-calculation
  
  Serial.print("Battery: ");
  Serial.print(battery);
  Serial.println(" V");
  
  delay(1000);
}
```

Upload.

---

Serial Monitor:

"Battery: 11.8 V"

Power supply shows: 12.0V

Difference: 0.2V

Inaccurate, but: CLOSE!

---

I stare at the number.

11.8V.

A real measurement.

From an €8 computer.

That I programmed.

---

That's...

That's exactly what I need!

For the boat!

Instead of the useless 12.0V voltmeter!

Real voltage!

Live!

Precise!

---

I take a photo.

Breadboard.

ESP32.

LED.

Resistors.

Cable chaos.

Serial Monitor: "Battery: 11.8 V"

---

Send it to a friend.

"Look, it works!"

Reply: "What is that?"

"ESP32. Measures voltage."

"For the boat?"

"Yes!"

"Cool. Can you really do that?"

"Just learned."

"Wow."

---

Yes.

Wow.

I'm surprised too.

---

Video 5:

"Connect an OLED display"

Now comes the display.

---

OLED 0.96 inch.

Small.

128×64 pixels.

I2C connection.

Just 4 wires:
- VCC (3.3V)
- GND
- SDA (data)
- SCL (clock)

---

Extend the breadboard:

Connect display.

ESP32 Pin 21 → SDA

ESP32 Pin 22 → SCL

VCC → 3.3V

GND → GND

---

Code:

Video has a library.

Adafruit_SSD1306.

Arduino IDE → Library Manager.

Search: "SSD1306"

Install.

---

Example code:

```cpp
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello");
  display.println("Boat!");
  display.display();
}

void loop() {
}
```

Upload.

---

Display:

Shows:

"Hello
Boat!"

In white.

On black.

Sharp.

Readable.

Perfect.

---

I combine them.

Voltage measurement + display.

Write code:

```cpp
void loop() {
  int value = analogRead(34);
  float voltage = value * (3.3 / 4095.0);
  float battery = voltage * 4.0;
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print("Batt:");
  display.setCursor(0,20);
  display.print(battery, 1);
  display.print(" V");
  display.display();
  
  delay(500);
}
```

Upload.

---

Display shows:

```
Batt:
11.8 V
```

Live.

Updates every 500ms.

I change the voltage on the power supply.

12.5V.

Display: "12.3 V"

It works!

LIVE!

---

I stare at it.

That's a working voltmeter.

For €15 in parts.

Digital.

Precise.

Live.

Self-built.

---

I make a video.

Show it:

- Breadboard with ESP32
- Display shows "12.3 V"
- I turn the power supply knob
- Voltage changes
- Display updates
- Live

---

Send video to a friend.

"LOOK AT THIS!"

Reply: "WTF! You built that?"

"Yes!"

"How many hours?"

"3."

"Mate."

"Yeah."

---

I look at the clock.

23:15.

I've been tinkering since 20:00.

3 hours.

5 videos watched.

Code written (typed out).

Hardware assembled.

Working voltmeter created.

---

For the boat:

Instead of €120 off-the-shelf voltmeter.

I now have:

€15 DIY voltmeter.

That I UNDERSTAND.

That I can CUSTOMISE.

That is MINE.

---

Buster stands up.

Stretches.

Comes over.

Sniffs the breadboard.

"Buster, NO. That's technology."

He doesn't care.

Sniffs again.

Lies down on my feet.

---

"Look, Buster. 12.3 volts!"

He yawns.

Classic.

---

Buster's already snoring again.

I look at the display.

Buster's right.

Time for bed.

---

Next day.

Saturday.

I get up.

First thought:

"To the boat. Test. NOW."

---

Pack the breadboard.

ESP32.

Display.

Resistors.

Cables.

Power supply.

Laptop.

Everything.

---

Off to the boat.

Start engine.

Runs.

Of course.

The engine doesn't care about my plans.

Just runs.

As always.

---

I set up.

In the cockpit.

Breadboard on the table.

ESP32 on USB power bank.

Voltage divider on the battery.

Direct.

No fuse.

No switch.

Nothing in between.

Direct.

---

Switch on the display.

Run the code.

Wait.

---

Display shows:

"Batt:
12.4 V"

Onboard voltmeter shows:

"12.0 V"

My multimeter shows:

12.4V.

---

My ESP32 is RIGHT!

The onboard voltmeter is LYING!

Proof delivered!

---

Engine on.

Alternator charging.

Display:

"Batt:
14.2 V"

Onboard voltmeter:

"12.0 V"

Completely ignores the fact that charging is happening.

---

My ESP32:

Shows it.

Live.

Precise.

14.2V.

Charging in progress.

Perfect.

---

I sit there.

Grinning.

Like an idiot.

Just completed my first boat project.

In 24 hours.

From idea to working prototype.

---

That's...

That's the moment.

The "I can do this!" moment.

The "This is becoming real!" moment.

The "No turning back now" moment.

---

I take photos.

Breadboard in the boat.

Display shows 14.2V.

Onboard voltmeter shows 12.0V.

The contrast.

Old vs. new.

1985 vs. 2024.

---

I know:

This is just the beginning.

Voltmeter is simple.

Fuel gauge is coming.

Temperature sensors are coming.

Dashboard is coming.

WiFi is coming.

Everything is coming.

---

But today:

Today I proved:

I can do this.

With €8 of hardware.

3 hours of YouTube.

And the will to make it better.

---

The engine runs.

As always.

Doesn't care about ESP32s.

Doesn't care about displays.

Just runs.

Reliably.

Since 1985.

---

But the rest?

The rest is going digital now.

Modern.

Measurable.

Understandable.

---

I pack up.

Take the breadboard home.

Develop further at home.

Then: install properly.

Fixed.

Permanent.

In the boat.

---

The first winter brought frustration.

Spring brought the solution.

Summer will bring the execution.

---

I drive home.

Breadboard beside me.

Display off.

But in my head:

It keeps running.

Showing data.

Voltage.

Temperature.

Tank.

Everything.

---

The next project:

LED lighting in the boat.

Properly.

With a switch.

Dimmable maybe?

---

How hard can it be?

(Spoiler: smoke incoming.)

But that comes later.

First: enjoy.

The success.

The working voltmeter.

The proof:

I can do this.

---
