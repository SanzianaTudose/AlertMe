/*
  LCD.h - library that handles displaying alarm information on the LCD Screen
*/

#include "Arduino.h"
#include "LCDScreen.h"

LCDScreen::LCDScreen() {}

void LCDScreen::SetUp(LiquidCrystal& lcd, int A_pin, int V0_pin) {
    _lcd = &lcd;
    _A_pin = A_pin; // Backlight pin
    _V0_pin = V0_pin; // Contrast pin

    analogWrite(_A_pin, 254); // Set backlight
    analogWrite(_V0_pin, 150); // Set contrast

    (_lcd)->begin(16, 2);
}
void LCDScreen::Update(AlarmType alarmType) {
    char message[25];

    switch (alarmType)
    {
    case NoAlarm:
        strcpy(message, "No Alarm");
        break;
    case Doorbell:
        strcpy(message, "Doorbell");
        break;
    case FireAlarm:
        strcpy(message, "Fire Alarm");
        break;

    default:
        strcpy(message, "AlarmType not found.");
        break;
    }

    // Clear screen on message change
    if (_prevAlarm != alarmType)
        (_lcd)->clear();
    
    (_lcd)->setCursor(0, 0);
    (_lcd)->print(message); 

    _prevAlarm = alarmType;
}