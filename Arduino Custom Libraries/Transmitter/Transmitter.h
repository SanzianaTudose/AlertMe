/*
  Transmitter.h - library that handles transmitting data using the nRF24L01+ module
                - transmision is triggered on button press
*/
#ifndef Transmitter_h
#define Transmitter_h

#include "Arduino.h"
#include "AlarmTypes.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

class Transmitter {
  public: 
    Transmitter();
    void SetUp(RF24& radio, AlarmType alarmType);

    void Update();
    void OptoUpdate();

  private: 
    RF24* _radio;    
    AlarmType _alarmType;
    int _opto_pin;
    int _fire_button = A1, _door_button = A2;
};

#endif
