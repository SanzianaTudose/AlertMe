/*
  Actuators.h - library that handles RGB LEDs and Vibration Motor
*/

#ifndef Actuators_h
#define Actuators_h

#include "Arduino.h"
#include "AlarmTypes.h"

class Actuators {
public:
    Actuators();
    void SetUp(int red_pin, int green_pin, int blue_pin, int vibration_pin);

    void Update(AlarmType alarmType);

private:
    int _vibration_pin;
    int _red_pin, _green_pin, _blue_pin;

    void RGB_color(int red_value, int green_value, int blue_value);
};

#endif