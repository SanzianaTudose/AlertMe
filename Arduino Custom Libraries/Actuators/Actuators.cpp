/*
  Actuators.h - library that handles RGB LEDs and Vibration Motor
*/

#include "Arduino.h"
#include "Actuators.h"

Actuators::Actuators() {}

void Actuators::SetUp(int red_pin, int green_pin, int blue_pin, int vibration_pin) {
    _red_pin = red_pin;
    _green_pin = green_pin;
    _blue_pin = blue_pin; 
    _vibration_pin = vibration_pin;

    pinMode(_red_pin, OUTPUT);
    pinMode(_green_pin, OUTPUT);
    pinMode(_blue_pin, OUTPUT);
    pinMode(_vibration_pin, OUTPUT);
}

void Actuators::Update(AlarmType alarmType)
{
    switch (alarmType)
    {
    case NoAlarm:
        RGB_color(0, 0, 0);  // turn off LED if there's no alarm
        digitalWrite(_vibration_pin, LOW);  // stop the vibration if there's no alarm
        break;

    case Doorbell:
        digitalWrite(_vibration_pin, HIGH);
        RGB_color(0, 0, 255);
        delay(1000);
        digitalWrite(_vibration_pin, LOW);
        RGB_color(0, 0, 0);
        delay(1000);
        break;

    case FireAlarm:
        RGB_color(255, 0, 0); // RED for Fire Alarm
        digitalWrite(_vibration_pin, HIGH);
        delay(500);
        RGB_color(0, 0, 0);
        digitalWrite(_vibration_pin, LOW);
        delay(500);
        break;

    default:
        RGB_color(0, 0, 0);
        digitalWrite(_vibration_pin, LOW);
        break;
    }
}

void Actuators::RGB_color(int red_value, int green_value, int blue_value)
{
    analogWrite(_red_pin, red_value);
    // analogWrite(_green_pin, green_value); GREEN IS NOT USED CURRENTLY
    analogWrite(_blue_pin, blue_value);
}
