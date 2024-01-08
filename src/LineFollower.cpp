#include "LineFollower.h"
#include <Arduino.h>

LineFollower::LineFollower(int d1, int d3, int d4, int d5, int d6, int d8)
    : d1(d1), d3(d3), d4(d4), d5(d5), d6(d6), d8(d8) {}

void LineFollower::linefollower1() {
    float threshold = 4.00;
    int p1 = 150;

    int l3 = analogRead(d3);
    int l6 = analogRead(d6);

    float v3 = l3 * (5.0 / 1024.0);
    float v6 = l6 * (5.0 / 1024.0);

    if (v3 < threshold && v6 < threshold) { // Robot moves forward
        // Implement forward motion logic using MotorControl functions
    } else if (v3 > threshold && v6 < threshold) { // Robot turns right
        // Implement right turn logic using MotorControl functions
    } else if (v3 < threshold && v6 > threshold) { // Robot turns left
        // Implement left turn logic using MotorControl functions
    } else if (v3 > threshold && v6 > threshold) { // Robot stops
        // Implement stop logic using MotorControl functions
    }
}

void LineFollower::linefollower2() {
    // 
}

void LineFollower::linefollower3() {
    // 
}

void LineFollower::linefollower4() {
    // 
}
