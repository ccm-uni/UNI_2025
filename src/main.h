#ifndef main
#define main

#define PS4MacAddress "MacAddressHere" // Mac address for the PS4 Controller

#define i2cSDA1 10
#define i2cSCL1 11

#include <Arduino.h>
#include <ESP32Servo.h>
#include <Wire.h>

#include "HUSKYLENS.h"
#include "MotorDriver.h"
#include "PS4Controller.h"

#define lStickX controller.data.analog.stick.lx
#define lStickY controller.data.analog.stick.ly
#define rStickX controller.data.analog.stick.rx
#define rStickY controller.data.analog.stick.ry

HUSKYLENS camera; // Vision camera
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


void safetyCheck();
bool initMotors();
void drive(float xSpeed, float ySpeed, float turn);

#endif