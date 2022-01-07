// Custom libraries
#include <AlarmTypes.h>
#include <Receiver.h>
#include <LCDScreen.h>
#include <Actuators.h>

// LCD Screen libary
#include <LiquidCrystal.h>

// nRF24L01+ module libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// nRF24L01+ transceiver variables
RF24 radio (9, 10); // (CE_pin, CSN_pin)
int button_pin = A0;
Receiver receiver;

// LCD Screen variables
int A_pin = 1, V0_pin = 6;
LiquidCrystal temp_lcd(8, 7, 5, 4, 3, 2); // (RS, E, D4, D5, D6, D7)
LCDScreen lcd;

// Actuators variables
int vibration_pin = A3; 
int red_pin = A1, green_pin = -1, blue_pin = A2; // Note: Green is not used
Actuators actuators;

void setup() {
  Serial.end(); // RXI pin is used for LCD Screen
  
  receiver.NewSetUp(radio, button_pin);
  lcd.SetUp(temp_lcd, A_pin, V0_pin);
  actuators.SetUp(red_pin, green_pin, blue_pin, vibration_pin);
}

void loop() {
  receiver.NewUpdate();

  lcd.Update(receiver.curAlarm);
  actuators.Update(receiver.curAlarm);
}
