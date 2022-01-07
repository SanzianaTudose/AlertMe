#include "Arduino.h"
#include "LEDs.h"

LEDs::LEDs() {}

void LEDs::SetUp(int red_pin, int green_pin, int blue_pin) {
    _red_pin = red_pin;
    _green_pin = green_pin;
    _blue_pin = blue_pin;

    pinMode(_red_pin, OUTPUT);
    pinMode(_green_pin, OUTPUT);
    pinMode(_blue_pin, OUTPUT);
}

// TODO:
// We might need to scrap the blinking LEDs idea, since Arduino doesn't natively support multithreading
// so idk how the delay() calls would work out 
void LEDs::Update(AlarmType alarmType)
{
    switch (alarmType)
    {
    case NoAlarm:
        RGB_color(0, 0, 0);  // turn off LED if there's no alarm
        break;

    case Doorbell:
        digitalWrite(A3, HIGH);
        RGB_color(0, 0, 255);
        delay(1500);
        digitalWrite(A3, LOW);
        RGB_color(0, 0, 0);
        delay(1000);
        break;

    case FireAlarm:
        RGB_color(255, 0, 0); // RED for Fire Alarm
        break;

    default:
        RGB_color(0, 0, 0);
        break;
    }
}

void LEDs::RGB_color(int red_value, int green_value, int blue_value)
{
    analogWrite(_red_pin, red_value);
    // analogWrite(_green_pin, green_value);
    analogWrite(_blue_pin, blue_value);
}

/*

DISCLAIMER: i couldn't completely understand this part, 
so i rewrote it to do what i thought it was supposed to do?

bool prevButtonState;
bool ledBlinking;

void loop() {
    bool buttonState = digitalRead(button_pin);

    if (prevButtonState && !buttonState){
      ledBlinking = !ledBlinking;
    }
    prevButtonState = buttonState;
    if (ledBlinking){
      if(antenna_pin == HIGH ){
      RGB_color(255,0,0); // Red
      delay(500);
      RGB_color(255,0,0); // Red
    }
    if(antenna_pin == LOW);{
      RGB_color(0, 0, 255); // Blue
      delay(500);
      RGB_color(0, 0, 255); // Blue
    }
    }


 else{
     RGB_color(0,0,0); //CHANGE #2: this gives a new error since the variable led is not declared, not sure what you wanted to use this for
    }

  }

//  RGB_color(0, 255, 0); // Green
//  delay(1000);

*/