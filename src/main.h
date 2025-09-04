#ifndef main
#define main

#include <Arduino.h>
#include <ESP32Servo.h>
#include <Wire.h>

Servo motor[4];

/**
 * Motor pins
 * 0 - FLMotor
 * 1 - BLMotor
 * 2 - BRMotor
 * 3 - 
 */
byte motorPins[4] = {0, 1, 2, 3};

bool initMotors();

#endif