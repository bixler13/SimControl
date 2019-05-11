#include "arduino.h"
#include "SimControl.h"

#define T1_PIN 0
#define T2_PIN 1
#define T3_PIN 2


void get_temperature(){
  read1 = analogRead(T1_PIN); //reading input
  read2 = analogRead(T2_PIN);
  read3 = analogRead(T3_PIN);

  volt1 = read1 * 5; //voltage in mv
  volt1 /= 1024;
  volt2 = read2 * 5;
  volt2 /= 1024;
  volt3 = read3 * 5;
  volt3 /= 1024;

  temp1c = (volt1 - 0.5) * 100; //temperature in C
  temp2c = (volt2 - 0.5) * 100;
  temp3c = (volt3 - .5) * 100;

  temp1f = (temp1c * 9.0 / 5.0) + 32.0; // temperature in F
  temp2f = (temp2c * 9.0 / 5.0) + 32.0;
  temp3f = (temp3c * 9.0 / 5.0) + 32.0;

  // Serial.print(volt1); // print the temps in the serial port
  // Serial.print(" , ");
  // Serial.print(volt2);
  // Serial.print(" , ");
  // Serial.println(volt3);
}
