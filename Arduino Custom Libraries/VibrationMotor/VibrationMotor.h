#ifndef VibrationMotor_h
#define VibrationMotor_h

#include "Arduino.h"
#include "AlarmTypes.h"

class VibrationMotor {
  public:
    VibrationMotor();
    void SetUp(int vibration_pin);

    void Update(AlarmType alarmType);

  private:
    int _vibration_pin;
};

#endif