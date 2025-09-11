#include "main.h"


// Runs once at the begining of the program
void setup() {
  Wire.begin(i2cSDA1, i2cSCL1); // Start i2c bus

  initMotors(); // Attach motors to the

  // Attach i2c HUSKYLENS Camera
  while (!camera.begin(Wire)) {
    // If connection fails, print out a sugesition to fix it
    Serial.println(F("Begin failed!"));
    Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS "
                     "(General Settings>>Protocol Type>>I2C)"));
    Serial.println(F("2.Please recheck the connection."));
    delay(100);
  }

  // Connect to PS4 controller
  while (!controller.begin(PS4MacAddress))
    Serial.println("Failled to connect to PS4 Controller");
}


// Main program loop
void loop() {
  safetyCheck(); // Make sure that everything is running properly

  drive(lStickY, lStickX, rStickX);
}


/**
 * Safety loop to check if stuff is still connected
 * Shuts stuff off if not
 */
void safetyCheck() {
  if (!controller.isConnected()) {
    Serial.println("ALERT: PS4 Controller disconnected");
    drive(0, 0, 0);
  }

  if (1) { /* code */
  }
}


/**
 * Attaches the motors to their corrisponding pins
 */
bool initMotors() {
  for (int i = 0; i < 4; i++)
    motor->attach(motorPins[i]);

  return true;
}


/**
 * Calculate motor speeds for a mechanum based system
 */
void drive(float xSpeed, float ySpeed, float turn) {

  motorPowers[0] = xSpeed + ySpeed + turn;
  motorPowers[1] = xSpeed + ySpeed + turn;
  motorPowers[2] = xSpeed + ySpeed + turn;
  motorPowers[3] = xSpeed + ySpeed + turn;
}