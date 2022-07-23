/*
  Portenta Breakout - GPIO Management

  The sketch shows how to use the Portenta Breakout
  and how to turn a PIN on for one second, then off for one
  second, repeatedly.

  The circuit:
   - Portenta H7
   - Portenta Breakout

  This example code is in the public domain.
*/
#include <Arduino_PortentaBreakout.h>


breakoutPin pin = analog.A7;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  int res = Breakout.pinMode(pin, OUTPUT);
  if (res == -1) {
    Serial.println("Error: pin not connected");
    while(1);
  }
  Breakout.digitalWrite(pin, LOW);
}

void loop() {
  Breakout.digitalWrite(pin, HIGH);
  Serial.print("Read: ");
  Serial.println(Breakout.digitalRead(pin));
  delay(1000);
  Breakout.digitalWrite(pin, LOW);
  Serial.print("Read: ");
  Serial.println(Breakout.digitalRead(pin));
  delay(1000);
}
