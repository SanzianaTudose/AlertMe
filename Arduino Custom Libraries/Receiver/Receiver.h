/*
  Receiver.h - library that handles receiving data using the nRF24L01+ module
             - updates an LED based on data from transmitter (TODO: update {curAlarmType})
*/

#ifndef Receiver_h
#define Receiver_h

#include "Arduino.h"
#include "AlarmTypes.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

class Receiver {
  public: 
    Receiver();
    void NewSetUp(RF24& radio, int button_pin); // TODO: replace SetUp with NewSetUp

    void NewUpdate(); // TODO: replace Update with NewUpdate
        
    AlarmType curAlarm;

  private: 
    RF24* _radio;      
    int _button_pin;
};

#endif
