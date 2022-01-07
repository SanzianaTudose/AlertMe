#include "Arduino.h"
#include "VibrationMotor.h"

VibrationMotor::VibrationMotor() {}

void VibrationMotor::SetUp(int vibration_pin) {
    _vibration_pin = vibration_pin;

    pinMode(_vibration_pin, OUTPUT);
}

void VibrationMotor::Update(AlarmType alarmType) 
{
    switch (alarmType)
    {
    case NoAlarm:
        digitalWrite(_vibration_pin, LOW);  // stop the vibration if you don't have an alarm
        break;

    case Doorbell:
        digitalWrite(_vibration_pin, HIGH); 
        delay(1500);
        digitalWrite(_vibration_pin, LOW);
        delay(1000);
        break;

    case FireAlarm:
        digitalWrite(_vibration_pin, HIGH); 
        delay(500);
        digitalWrite(_vibration_pin, LOW);
        delay(500);
        digitalWrite(_vibration_pin, HIGH);
        delay(500);
        digitalWrite(_vibration_pin, LOW);
        delay(500);
        break;

    default:
        digitalWrite(_vibration_pin, LOW);
        break;
    }
}

/*

DISCLAIMER: idk what this code is, it was int the .ino file
seems to be conflicting with the library code above

// if alarm_type == :
  // vibration_pattern(a, b);
  // maybe for the alarm it can be (250,1000)
  // for the door bell (500,1500)
}

void vibration_pattern(int x, int y)
{
  digitalWrite(vibration_pin, HIGH); // or write  numbers beween 0 - 255 instead of HIGH/LOW
  delay(x);
  digitalWrite(vibration_pin, LOW);  // is it useful to use millis()?
  delay(x);
  digitalWrite(vibration_pin, HIGH);
  delay(y);
  digitalWrite(vibration_pin, LOW);
  delay(x);
}


*/