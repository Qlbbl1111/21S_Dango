#include "main.h"

void waitUntilBall(int timeout) {
    pros::delay(250);
    int timeleft = timeout + pros::millis();
    while (true) {
    if (intake_motor.get_power() > 7 or timeleft <= pros::millis()){
        break;
    } else {
        pros::delay(10);
    }
    }
}

void nothing() {
    //do nothing :)
}

