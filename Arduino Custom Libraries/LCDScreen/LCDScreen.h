/*
  LCD.h - library that handles displaying alarm information on the LCD Screen
*/

#ifndef LCDScreen_h
#define LCDScreen_h

#include "Arduino.h"
#include "LiquidCrystal.h"
#include "AlarmTypes.h"

class LCDScreen {
public: 
    LCDScreen();
    void SetUp(LiquidCrystal& lcd, int A_pin, int V0_pin);

    void Update(AlarmType alarmType);

private:
    LiquidCrystal* _lcd;
    int _A_pin;
    int _V0_pin;

    AlarmType _prevAlarm;
};

#endif
