#include "arduino.h"
#include "Simcontrol.h"
#include "button.h"

#define BUTTON1_PIN 2
#define BUTTON2_PIN 3
#define CASELED_PIN 4

int button1_state, button2_state;

void button_setup(){
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
  digitalWrite(CASELED_PIN, HIGH);

}

void button_loop(){

  digitalWrite(BUTTON1_PIN, LOW);
  digitalWrite(BUTTON2_PIN, LOW);
  button1_state = digitalRead(BUTTON1_PIN);
  button2_state = digitalRead(BUTTON2_PIN);


  if (button1_state == HIGH){
    led_mode = 2;
  }
  else{
    led_mode = 1;
  }

  if (button2_state == HIGH){
    display_mode = 2;
  }
  else{
    display_mode = 1;
  }

  Serial.print("led_mode =   ");
  Serial.print(led_mode);
  Serial.print("  display_mode =   ");
  Serial.println(display_mode);

  }
