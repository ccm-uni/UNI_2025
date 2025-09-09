#ifndef main
#define main

#define PS4MacAddress "MacAddressHere" // Mac address for the PS4 Controller

#include <Arduino.h>
#include <ESP32Servo.h>
#include <Wire.h>

#include "HUSKYLENS.h"
#include "PS4Controller.h"

HUSKYLENS camera;

PS4Controller controller; // Main ps4 controller

Servo motor[4]; // Array that stores the motors

/**
 * Motor pins
 * 0 - FLMotor
 * 1 - BLMotor
 * 2 - BRMotor
 * 3 - FR Motor
 */
byte motorPins[4] = {0, 1, 2, 3};

// Stores the current target powers of the motors
int8_t motorPowers[4] = {0, 0, 0, 0};

int8_t lStickX, lStickY, rStickX, rStickY;

void safetyCheck();
void updateControllers();
bool initMotors();
void drive(float xSpeed, float ySpeed, float turn);

#endif