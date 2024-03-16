#include "main.h"

void fiveBall() {
//rush middle ball
intake_motor = 127;
kicker_motor = 127;
chassis.setPose(35, -55, 0); //set robots starting position
chassis.moveToPoint(25.75, -4, 5000);
waitUntilBall(2500);
chassis.cancelMotion();
kicker_motor = 0;

//move back
chassis.moveToPoint(40, -57, 5000, {.forwards = false});
chassis.waitUntilDone();

//spit out ball
chassis.turnToHeading(30, 500);
chassis.waitUntilDone();
intake_motor = -127;
pros::delay(200);

//get elevation bar ball
intake_motor = 127;
chassis.moveToPose(4, -60, 270, 5000);
waitUntilBall(5000);
chassis.cancelMotion();

//descore side ball
chassis.moveToPoint(47.5, -54, 4000, {.forwards = false, .minSpeed=40});
chassis.waitUntilDone();
back_wing_L.set_value(true);
chassis.moveToPoint(57.75, -45, 3000, {.forwards = false, .minSpeed=40});
chassis.waitUntilDone();
float chassis_x = chassis.getPose().x;
float chassis_y = chassis.getPose().y;
std::cout << chassis.getPose().x << ", " << chassis.getPose().y << "\n";
chassis.turnToHeading(-10, 1000, {.forwards = false, .minSpeed=40});
chassis.waitUntilDone();
intake_motor = 0;
back_wings(false);

//spit out ball and score in side
chassis.turnToHeading(10, 1000);
chassis.waitUntilDone();
intake_motor = -127;
pros::delay(200);
chassis.turnToHeading(5, 1000, {.forwards=false});
chassis.waitUntilDone();
std::cout << chassis.getPose().x << ", " << chassis.getPose().y;
chassis.setPose(chassis_x, chassis_y, chassis.getPose().theta);
back_wing_L.set_value(true);
chassis.moveToPoint(62, -27, 3000, {.forwards=false});
chassis.waitUntilDone();
intake_motor = 0;
back_wings(false);

//get lone ball - 5 ball
chassis.moveToPoint(60, -38, 2000);
chassis.waitUntilDone();
intake_motor = 127;
chassis.turnToPoint(9, -26, 1000,{.minSpeed=20});
chassis.waitUntilDone();
chassis.moveToPoint(9, -26, 5000);
chassis.waitUntil(11);
waitUntilBall(2500);
chassis.cancelMotion();

//score in front - 5 ball
chassis.moveToPoint(18, -4, 3000);
chassis.waitUntilDone();
chassis.turnToHeading(90, 1000);
chassis.waitUntilDone();
front_wings(true);
intake_motor = -127;
chassis.moveToPoint(45, -4, 3000);
chassis.waitUntilDone();
chassis.moveToPoint(40, -4, 1000, {.forwards = false});
chassis.waitUntilDone();
intake_motor = 0;
front_wings(false);
}