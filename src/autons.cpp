#include "main.h"
#include "lemlib/api.hpp"

ASSET(drive_across_txt);
void skillsAuton() {
    chassis.setPose(-46.8, -58.6, 135);

    chassis.moveToPoint(-60, -45, 5000, false);
    chassis.waitUntilDone();
    chassis.turnTo(47, -15, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-63.435, -46.961, 5000);
    chassis.waitUntilDone();

    kicker_motor = 127;
    pros::delay(2000);
    kicker_motor = 0;
    chassis.moveToPoint(-60, -45, 5000);
    chassis.waitUntilDone();

    //preloads
    chassis.turnTo(-60, -70, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, -24, 5000, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, -37, 5000, true);
    chassis.waitUntilDone();

    //drive to the other side
    chassis.moveToPoint(-31, -58, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(37, -58, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(57, -38, 5000);
    chassis.waitUntilDone();

    //side balls
    intake_motor = -127;
    chassis.moveToPoint(57, -28, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(57, -38, 1000, false);
    chassis.waitUntilDone();
    chassis.turnTo(57, 0, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(57, -28, 2000);
    chassis.waitUntilDone();
    intake_motor = 0;

    //goal right
    chassis.moveToPoint(57, -40, 3000, false);
    chassis.waitUntilDone();
    chassis.turnTo(6, -21,  1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(10, -20,  3000);
    chassis.waitUntilDone();
    chassis.moveToPose(41, -8,90, 2000);
    chassis.waitUntil(5);
    intake_motor = -127;
    wings.set_value(true);
    chassis.waitUntilDone();
    chassis.moveToPoint(20, -8, 3000, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(42, -8, 1000);
    chassis.waitUntilDone();
    intake_motor = 0;

    //goal middle
    chassis.moveToPoint(6, -2, 5000, false);
    chassis.waitUntil(5);
    wings.set_value(false);
    chassis.waitUntilDone();
    back_wings.set_value(true);
    chassis.moveToPose(43, -2, 270, 3000, {.forwards=false});
    chassis.waitUntilDone();
    chassis.moveToPoint(34, -2, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(43, -2, 3000, false);
    chassis.waitUntilDone();

    //goal left
    chassis.moveToPoint(20, -2, 5000);
    chassis.waitUntil(5);
    back_wings.set_value(false);
    chassis.waitUntilDone();
    chassis.moveToPose(13, 30, 180, 3000, {.forwards=false});
    chassis.waitUntilDone();

    chassis.moveToPose(43, 6, 270, 3000, {.forwards=false});
    chassis.waitUntil(10);
    back_wings.set_value(true);
    chassis.waitUntilDone();
    chassis.moveToPoint(30, 6, 2000, true);
    chassis.waitUntilDone();
    chassis.moveToPoint(43, 6, 3000, false);
    chassis.waitUntilDone();

    //for testing
    pros::delay(1000);
    chassis.moveToPoint(28, 5, 5000, true);
    chassis.waitUntilDone();
    back_wings.set_value(false);

}

void sixBall() {

}

void closeWP() {

}

void farWP() {

}

void closeElim() {

}