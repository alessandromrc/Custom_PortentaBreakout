/*
  Portenta Breakout - analogRead

  The sketch shows how to use analog inputs of the Portenta Breakout.

  The circuit:
   - Portenta H7
   - Portenta Breakout

  This example code is in the public domain.
*/
#include <custom_PortentaBreakout.h>

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
