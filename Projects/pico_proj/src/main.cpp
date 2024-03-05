// Simple blink example
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

LiquidCrystal_I2C lcd (0x3F, 16, 2);
int buttonPin = 15;
int servoPin = 16;
bool servoState = true;
Servo myServo;
int i = 0;

void toggleServo() {
    if (servoState) {
        myServo.write(180);
    }
    else if (!servoState) {
        myServo.write(90);
    }
    servoState = !servoState;
}

void setup() {
    // For Serial
    Serial.begin(9600);

    // For Button
    pinMode(buttonPin, INPUT);

    // For LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Click to reveal!");

    // For Servo
    myServo.attach(servoPin);
    myServo.write(90);
}

void loop() {
    String words[4] = {"You", "are", "very", "dumb..."};

    if (digitalRead(buttonPin) == HIGH) {
        toggleServo();
        delay(20);
        if (i == 0) {
            lcd.clear();
            lcd.setCursor(0, 0);
        }
        else if (i == 3) {
           lcd.setCursor(0, 1);
        }
        lcd.print(words[i] + " ");
        i++;
        while (digitalRead(buttonPin) == HIGH);
    }
}
