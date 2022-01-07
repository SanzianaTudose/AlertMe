/*
  Receiver.h - library that handles receiving data using the nRF24L01+ module
             - updates public variable {curAlarmType} based on data from transmitter 
*/

#include "Arduino.h"
#include "Receiver.h"

const byte address[5] = { 'R','x','A','A','A' };     // Byte of array representing the address

Receiver::Receiver() {}

void Receiver::NewSetUp(RF24& radio, int button_pin) {
    _radio = &radio;
    _button_pin = button_pin;

    _radio->begin();
    _radio->setDataRate(RF24_250KBPS);
    _radio->openReadingPipe(1, address);   // Setting the address at which we will receive the data
    _radio->setPALevel(RF24_PA_MIN);       
    _radio->startListening();              // This sets the module as receiver

    pinMode(_button_pin, INPUT_PULLUP);
}

void Receiver::NewUpdate() {

    // Reading new data
    AlarmType newAlarm = NoAlarm;
    if (_radio->available()) 
        _radio->read(&newAlarm, sizeof(newAlarm));   
    
    // Button functionality: when user presses button as alarm is ongoing => wearable alerts stop
    if (curAlarm != NoAlarm) {
        if (digitalRead(_button_pin) == LOW)
            curAlarm = NoAlarm;

        return;
    }

    curAlarm = newAlarm;
}
