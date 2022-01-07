// Custom libraries
#include <Receiver.h>
#include <AlarmTypes.h>

// nRF24L01+ module libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// nRF24L01+ transceiver variables
RF24 radio (9, 10); // (CE_pin, CSN_pin)
Receiver receiver;

void setup() {
  receiver.SetUp(radio);
}

void loop() {
  receiver.Update();
}
