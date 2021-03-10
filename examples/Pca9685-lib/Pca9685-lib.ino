#include "Pca9685.h"
#include "Pca9685Board.h"

#define NO_OF_BOARDS 3

int MAX_PINS = 0;

Pca9685Board pca9685Board;

void setup() {
  Serial.begin(9600);
  pca9685Board.initPca9685Boards(NO_OF_BOARDS);
  pca9685Board.setFrequency(50);
  MAX_PINS = NO_OF_BOARDS * 16;
  for (int i = 1; i <= MAX_PINS; i++) {
    pca9685Board.setSwitchRange(i, 1200, 1800);
  }
}

void loop() {
  int pins[] = {1, 17, 33};
  for (int i = 0; i < 3; i++) {
    int pinNo = pins[i];
    //int pinNo = random(0, MAX_PINS);
    Serial.print("MAX PIN ");
    Serial.println(MAX_PINS);
    Serial.print("PIN NO ");
    Serial.println(pinNo);
    delay(1000);
    pca9685Board.throwSwitch(pinNo);
    pca9685Board.displayPinState();
    delay(1000);
    pca9685Board.closeSwitch(pinNo);
    pca9685Board.displayPinState();
    delay(1000);
  }

}
