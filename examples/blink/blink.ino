#include <Custom_PortentaBreakout.h>
#include <PortentaBreakout_debouncing.h>

const breakoutPin ledPin =  pwm.P0;

PinStatus ledState = LOW;

unsigned long previousMillis = 0;

const long interval = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    Breakout.digitalWrite(ledPin, ledState);
  }
}
