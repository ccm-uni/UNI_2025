#include "main.h"

void setup() {
  Wire.begin();
  initMotors();
}

void loop() {}

/**
 * Attaches the motors to their corrisponding pins
 */
bool initMotors() {
  for (int i = 0; i < 4; i++) {
    motor->attach(motorPins[i]);
  }

  return true;
}