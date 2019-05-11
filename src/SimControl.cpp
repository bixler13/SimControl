#include <Arduino.h>
#include "SimControl.h"
#include "temp.h"
#include "led.h"
#include "display.h"
#include "button.h"

int read1, read2, read3;
float volt1, volt2, volt3;
int temp1c, temp2c, temp3c;
int temp1f, temp2f, temp3f;
int led_mode, display_mode;

void setup() {
  Serial.begin(9600); //start serial

  led_setup();
  display_setup();
  button_setup();

}

void loop() {

  get_temperature();
  led_show();
  display_show();
  button_loop();

  //delay(10);
}
