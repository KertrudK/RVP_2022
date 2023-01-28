#include <HID-Project.h>
#include <HID-Settings.h>

 //#include <Keyboard.h>

// Switch 1 is using 18 pin on ATmega32u4, it would be Digital 3 pin
// Switch 2 is using 19 pin on Atmega32u4, it would be Digital 2 pin
// Switch 3 is using 20 pin on ATmega32u4, it would be Digital 0 pin
// Switch 4 is using 21 pin on ATmega32u4, it would be Digital 1 pin
// Switch 5 is using 25 pin on ATmega32u4, it would be Digital 4 pin
// Switch 6 is using 27 pin on ATmega32u4, it would be Digital 6 pin
// For LED's 32 pin on ATmega32u4, it would be Digital 13 pin


/*
For connecting wires from PCB board to Arduino Uno for programming
Black = GND
Red = 5V
Green = Pin 13(on Arduino Uno)
Brown = Pin 12(on Arduino Uno)
Yellow = Pin 11(on Arduino Uno)
White = Pin 10(RESET(on Arduino Uno))
10uf Cap = GND & RESET
*/

/*

*/
const byte Next_track_button = 3;  //Switch 1
const byte Previous_track_button = 2; // Switch 2
const byte Mute_button = 0;  // Switch 3
const byte Volume_down_button = 1;   // Switch 4
const byte Volume_up_button = 4; // Switch 5
const byte Play_pause_button = 6; // Switch 6
//int ledPin = 13 ; // LED


int previousButtonState_S1 = HIGH;
int previousButtonState_S2 = HIGH;
int previousButtonState_S3 = HIGH;
int previousButtonState_S4 = HIGH;
int previousButtonState_S5 = HIGH;
int previousButtonState_S6 = HIGH;

int holdTime = 250;
int hold = 0;
long onTime = 0;

void setup() {
  pinMode(Next_track_button, INPUT_PULLUP);       // Switch 1
  pinMode(Previous_track_button, INPUT_PULLUP);   // Switch 2
  pinMode(Mute_button, INPUT_PULLUP);             // Switch 3
  pinMode(Volume_down_button, INPUT_PULLUP);      // Switch 4
  pinMode(Volume_up_button, INPUT_PULLUP);        // Switch 5
  pinMode(Play_pause_button, INPUT_PULLUP);       // Switch 6
  //pinMode(ledPin, OUTPUT);  

  Consumer.begin();
}

void loop() {
  int buttonState_S1 = digitalRead(Next_track_button);
  int buttonState_S2 = digitalRead(Previous_track_button);
  int buttonState_S3 = digitalRead(Mute_button);
  int buttonState_S4 = digitalRead(Volume_down_button);
  int buttonState_S5 = digitalRead(Volume_up_button);
  int buttonState_S6 = digitalRead(Play_pause_button);

// digitalWrite(ledPin, HIGH); // sets the LED on

/* -------------- NEXT TRACK ------------*/
/*---------------- SWICTH 1 --------------*/
if (buttonState_S1 == LOW && previousButtonState_S1 == HIGH) {
    if (buttonState_S1 == LOW){
      // and it's currently pressed:
    Consumer.write(MEDIA_NEXT);
    delay(10);
    }
    else{
      Consumer.releaseAll();
    delay(10);
  }
  }

/* -------------- PREVIOUS TRACK ------------*/
/*---------------- SWICTH 2 --------------*/
  if (buttonState_S2 == LOW && previousButtonState_S2 == HIGH) {
    if (buttonState_S2 == LOW){
      // and it's currently pressed:
    Consumer.write(MEDIA_PREVIOUS);
    delay(10);
    }
    else{
      Consumer.releaseAll();
    delay(10);
  }
  }

/* ---------------- MUTE ---------------*/
/*---------------- SWICTH 3 --------------*/
   if (buttonState_S3 == LOW && previousButtonState_S3 == HIGH) {
    if (buttonState_S3 == LOW){
      // and it's currently pressed:
    Consumer.write(MEDIA_VOLUME_MUTE);
    delay(10);
    }
    else{
      Consumer.releaseAll();
    delay(10);
  }
  }

  
/* ---------------- VOLUME DOWN ---------------*/
/*---------------- SWICTH 4 --------------*/

   if (buttonState_S4 == LOW && previousButtonState_S4 == LOW) {
    if ((millis() - onTime) > holdTime) {
      Consumer.write(MEDIA_VOLUME_DOWN);
      hold = 1;
      delay(10);
    }
    else{
      Consumer.releaseAll();
    delay(10);
  }
  }



/* -------------- VOLUME UP ------------*/
/*---------------- SWICTH 5 --------------*/  
  if (buttonState_S5 == LOW && previousButtonState_S5 == LOW) {
    if ((millis() - onTime) > holdTime) {
      Consumer.write(MEDIA_VOLUME_UP);
      hold = 1;
      delay(10);
    }
    else{
      Consumer.releaseAll();
    delay(10);
  }
  }

/* -------------- PLAY & PUASE ------------*/
/*---------------- SWICTH 6 --------------*/  
  if (buttonState_S6 == LOW && previousButtonState_S6 == HIGH) {
    if (buttonState_S6 == LOW){
      // and it's currently pressed:
    Consumer.write(MEDIA_PLAY_PAUSE);
    delay(10);
    }
    else{
      Consumer.releaseAll();
    delay(10);
  }
  }

  previousButtonState_S1 = buttonState_S1;
  previousButtonState_S2 = buttonState_S2;
  previousButtonState_S3 = buttonState_S3;
  previousButtonState_S4 = buttonState_S4;
  previousButtonState_S5 = buttonState_S5;
  previousButtonState_S6 = buttonState_S6;
  
}