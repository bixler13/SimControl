#include "arduino.h"
#include "Simcontrol.h"
#include "led.h"
#include <Adafruit_NeoPixel.h>


#define LED_PIN 7
#define NUM_LED 25

int c1,c2,c3, counter;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LED, LED_PIN, NEO_GRB + NEO_KHZ800);

void led_setup(){
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


void led_show(){

counter = counter + 1;

  if (counter > 20){
    rainbowCycle();
  }
  else{
    chase();
  }

  if (counter >= 22){
    counter = 0;
  }

}

void chase() {

c1 = random(0,255);
c2 = random(0,255);
c3 = random(0,255);
  for(uint16_t i=0; i<NUM_LED+4; i++) {
      strip.setPixelColor(i  , strip.Color(c1, c2, c3)); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(10);
    }
  }



void solid_red(){
    for (int n = 0; n <= NUM_LED; n++) {
      strip.setPixelColor(n, 255, 0, 0);
      strip.show();
    }
}


void rainbowCycle() {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(5);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
