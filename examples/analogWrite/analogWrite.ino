/*
  Portenta Breakout - analogWrite

  The sketch shows how to use analogWrite API of the Portenta Breakout.

  The circuit:
   - Portenta H7
   - Portenta Breakout

  This example code is in the public domain.
*/
#include "custom_PortentaBreakout.h"

void setup() {
  Serial.begin(9600);
  while (!Serial);

  //Default write resolution is 8bits
  Breakout.analogWriteResolution(8);

  //PWM0 and PWM3 are using HRTIM peripheral and minimum frequency is 760Hz
  Breakout.analogWrite(pwm.P0, 25);
  Breakout.analogWrite(pwm.P1, 50);
  Breakout.analogWrite(pwm.P2, 75);
  Breakout.analogWrite(pwm.P3, 100);
  // PWM4 and PWM8 are sharing the same timer channel therefore is not possible
  // to use both outputs at the same time
  Breakout.analogWrite(pwm.P4, 125);
  Breakout.analogWrite(pwm.P5, 150);
  Breakout.analogWrite(pwm.P6, 175);
  Breakout.analogWrite(pwm.P7, 200);
  //Breakout.analogWrite(pwm.P8, 225);
  Breakout.analogWrite(pwm.P9, 250);
}

void loop() {
    delay(100);
}
