#include <Arduino.h>
#include "MotorControl.h"
#include "Linefollower.h"

// Motor #1
int enA = 5;
int in1 = 7;
int in2 = 8;

// Motor #2
int enB = 3;
int in3 = 2;
int in4 = 4;

// Analog input from line sensor
int d1 = A0;
int d3 = A1;
int d4 = A2;
int d5 = A3;
int d6 = A4;
int d8 = A5;

MotorControl motor(enA, in1, in2, enB, in3, in4);
LineFollower lineFollower(d1, d3, d4, d5, d6, d8);

void setup()
{
  Serial.begin(9600);
  motor.initialize();
}

void loop()
{
  //linefollower1();
}



