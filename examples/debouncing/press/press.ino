#include <Custom_PortentaBreakout.h>
#include <PortentaBreakout_debouncing.h>

Debouncing SW1 (gpio.G1, INPUT_PULLUP);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (SW1.press())
  {
    Serial.println("pressed");
  }
  else
  {
    Serial.println("not pressed");
  }
}
