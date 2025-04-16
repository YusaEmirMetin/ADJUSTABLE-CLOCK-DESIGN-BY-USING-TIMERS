//Arda Ali Altıncı
//Yüşa Emir Metin
//Yaşar Düzdün
//Mert Koçoğlu
#include <Wire.h>
#include "rgb_lcd.h"


rgb_lcd lcd;


const int buttonPin = A0;
int buttonState = HIGH, lastButtonState = HIGH;
int pressCount = 0;
unsigned long lastPressTime = 0, currentTime = 0;
const unsigned long debounceDelay = 50, pressWindow = 2000;


int hour = 0, minute = 0, second = 0;

void setup() {
    
    lcd.begin(16, 2);
    pinMode(buttonPin, INPUT_PULLUP);
    Serial.begin(9600);

    
    lcd.setRGB(0, 255, 255);
    lcd.setCursor(0, 0);
    lcd.print("HH:MM:SS");
}

void loop() {
    currentTime = millis();

    
    handleButtonInput();

    
    if (currentTime % 1000 == 0) {
        updateClock();
        updateDisplay();
    }
}

void handleButtonInput() {
    buttonState = digitalRead(buttonPin);

    
    if (buttonState == LOW && lastButtonState == HIGH && (currentTime - lastPressTime) > debounceDelay) {
        lastPressTime = currentTime;
        pressCount++;
    }

    
    if ((currentTime - lastPressTime) > pressWindow && pressCount > 0) {
        handleButtonActions(pressCount);
        pressCount = 0;
    }

    
    lastButtonState = buttonState;
}

void handleButtonActions(int count) {
    
    if (count == 1) {
        Serial.println("Enter hour (0-23):");
        while (Serial.available() == 0); 
        int newHour = Serial.parseInt();
        hour = newHour % 24; 
        Serial.print("Hour set to: ");
        Serial.println(hour);
    }
    
    else if (count == 2) {
        Serial.println("Enter minute (0-59):");
        while (Serial.available() == 0); 
        int newMinute = Serial.parseInt();
        minute = newMinute % 60; 
        Serial.print("Minute set to: ");
        Serial.println(minute);
    }
}

void updateClock() {
    
    second++;
    if (second >= 60) {
        second = 0;
        minute++;
        if (minute >= 60) {
            minute = 0;
            hour++;
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
}

void updateDisplay() {
    
    lcd.setCursor(0, 0);
    if (hour < 10) lcd.print("0");
    lcd.print(hour);
    lcd.print(":");
    if (minute < 10) lcd.print("0");
    lcd.print(minute);
    lcd.print(":");
    if (second < 10) lcd.print("0");
    lcd.print(second);
}