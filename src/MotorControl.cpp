#include <Arduino.h>
#include "MotorControl.h"

MotorControl::MotorControl(int enA, int in1, int in2, int enB, int in3, int in4) : enA(enA), in1(in1), in2(in2) {}

void MotorControl::initialize() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void MotorControl::moveForward(int speed) {

};


