/*
  Transmitter.cpp - library that handles transmitting data using the nRF24L01+ module
                  - transmision is triggered on button press (TODO: change with Optocoupler)
*/

#include "Arduino.h"
#include "Transmitter.h"


const byte address[5] = { 'R','x','A','A','A' };      //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.

Transmitter::Transmitter() {}

void Transmitter::SetUp(RF24& radio, AlarmType alarmType) {
    _alarmType = alarmType;
    _radio = &radio;
    //_opto_pin = opto_pin;

    _radio->begin();                  // Starting the Wireless communication
    _radio->setDataRate(RF24_250KBPS);
    _radio->openWritingPipe(address); // Setting the address where we will send the data
    _radio->setPALevel(RF24_PA_MIN);  // You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
    _radio->stopListening();          // This sets the module as transmitter
    
    //pinMode(_opto_pin, INPUT);
    pinMode(_fire_button, INPUT_PULLUP);
    pinMode(_door_button, INPUT_PULLUP);
}

void Transmitter::Update() {
    AlarmType curAlarm = NoAlarm;
    if (digitalRead(_fire_button) == LOW) {
        curAlarm = FireAlarm;
    }
    else if (digitalRead(_door_button) == LOW) {
        curAlarm = Doorbell;
    }

    _radio->write(&curAlarm, sizeof(curAlarm));
}

void Transmitter::OptoUpdate() {
    AlarmType curAlarm = NoAlarm;
    if (digitalRead(_opto_pin) == HIGH) {
        curAlarm = _alarmType;
    }

    _radio->write(&curAlarm, sizeof(curAlarm));
}