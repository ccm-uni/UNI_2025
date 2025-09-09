#include "main.h"

void setup() {
  Wire.begin(10, 11);
  initMotors();

  while (!camera.begin(Wire)) {
    Serial.println(F("Begin failed!"));
    Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS "
                     "(General Settings>>Protocol Type>>I2C)"));
    Serial.println(F("2.Please recheck the connection."));
    delay(100);
  }

  while (!controller.begin(PS4MacAddress)) {
    Serial.println("Failled to connect to PS4 Controller");
  }
}

void loop() {
  safetyCheck();
  updateControllers();

  drive(lStickY, lStickX, rStickX);
}

void updateControllers() {
  lStickX = controller.data.analog.stick.lx;
  lStickY = controller.data.analog.stick.ly;
  rStickX = controller.data.analog.stick.rx;
  rStickY = controller.data.analog.stick.ry;
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

  if (1) {
    /* code */
  }
}

/**
 * Attaches the motors to their corrisponding pins
 */
bool initMotors() {
  for (int i = 0; i < 4; i++) {
    motor->attach(motorPins[i]);
  }

  return true;
}

void drive(float xSpeed, float ySpeed, float turn) {

  motorPowers[0] = xSpeed + ySpeed + turn;
  motorPowers[1] = xSpeed + ySpeed + turn;
  motorPowers[2] = xSpeed + ySpeed + turn;
  motorPowers[3] = xSpeed + ySpeed + turn;
}