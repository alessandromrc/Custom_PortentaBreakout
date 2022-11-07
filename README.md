# Custom Portenta Breakout Carrier Library

Custom version of the Portenta Breakout Carrier Library with easier to code and faster way to access pins.

### Analog Read
```cpp
#include <Custom_PortentaBreakout.h>

breakoutPin Analog_Pin = analog.A0;
const int ANALOG_RESOLUTION = 16;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Breakout.analogReadResolution(ANALOG_RESOLUTION);
}

void loop() {
  Serial.println("Analog Value = " + String(Breakout.analogRead(Analog_Pin)));
}
```
### Debouncing
```cpp
#include <Custom_PortentaBreakout.h>
#include <PortentaBreakout_debouncing.h>

Debouncing SW1 (gpio.G1, INPUT_PULLUP);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (SW1.toggle())
  {
    Serial.println("toggled on");
  }
  else
  {
    Serial.println("toggled off");
  }
}
```

You can find other examples after installing the Library inside the Arduino IDE under "Examples"

## Authors

* **alessandromrc** - *Main work* - [alessandromrc](https://github.com/alessandromrc)
