#include "main.h"

void closeWP() {
chassis.setPose(-35, -55, 0); //set robots starting position

//steal mid ball
intake_motor = 127;
kicker_motor = 127;
chassis.moveToPoint(-25, -8, 5000); //move to intake middle ball (fig.A)
waitUntilBall(2500);
chassis.cancelMotion();
kicker_motor = 0;

//push over
chassis.moveToPoint(-25, -15, 1500, {.forwards=false});
chassis.waitUntilDone();
chassis.turnToHeading(90, 1000); //turn to face the bar
chassis.waitUntilDone();
front_wings(true);
chassis.moveToPoint(-8, -15, 3000); //move to push over middle ball and middle bar ball (fig.A and fig.B)
chassis.waitUntilDone();
front_wings(false);
//go to matchload bar
chassis.turnToPoint(-41, -46, 1000); // turn to face the matchload bar
chassis.waitUntilDone();
chassis.moveToPoint(-41, -46, 3000); //move to the matchload bar (fig.C)
chassis.waitUntilDone();
intake_motor = 0;
//descore
back_wing_R.set_value(true);
chassis.turnToPoint(-33, -55, 1000);
chassis.waitUntilDone();
chassis.moveToPoint(-33, -55, 3000);
chassis.waitUntilDone();
chassis.turnToPoint(-25, -11, 1000, {.maxSpeed = 127}); //spin to remove the matchload zone ball for AWP (fig.D)
chassis.waitUntilDone();
back_wing_R.set_value(false);
//touch elevation bar
chassis.turnToPoint(0, -55, 1000);
chassis.waitUntilDone();
//pros::delay(1000); //wait for some time to let our allaince finish their auton
chassis.moveToPoint(-4, -55, 5000); //move to touch the elevation bar (fig.E)
chassis.waitUntilDone();
intake_motor = -127;
chassis.turnToPoint(1000, -55, 1000);
chassis.waitUntilDone();
chassis.moveToPoint(-3, -55, 5000);
chassis.waitUntilDone();
intake_motor = 0;
}