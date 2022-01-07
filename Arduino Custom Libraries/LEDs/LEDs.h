#ifndef LEDs_h
#define LEDs_h

#include "Arduino.h"
#include "AlarmTypes.h"

class LEDs {
  public:
    LEDs();
    void SetUp(int red_pin, int green_pin, int blue_pin);

    void Update(AlarmType alarmType);

  private:
    int _red_pin, _green_pin, _blue_pin;

    void RGB_color(int red_value, int green_value, int blue_value);
};

#endif