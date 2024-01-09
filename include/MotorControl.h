#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

class MotorControl{
public:
    MotorControl(int enA, int in1, int in2, int enB, int in3, int in4);
    void initialize();
    void moveForward(int speed);
    void turnRight(int speed);
    void turnLeft(int speed);
    void stop();

private:
    int enA, in1, in2, enB, in3, in4;
};

#endif