#include "main.h"

void farWP() {
//rush middle ball
intake_motor = 127;
kicker_motor = 127;
chassis.setPose(35, -55, 0); //set robots starting position
chassis.moveToPoint(25.75, -4, 5000);
waitUntilBall(2500);
chassis.cancelMotion();
kicker_motor = 0;

//move back
chassis.moveToPoint(35, -42, 5000, {.forwards = false});
chassis.waitUntilDone();
float chassis_x = chassis.getPose().x;
float chassis_y = chassis.getPose().y;
//spit out ball
chassis.turnToHeading(60, 1000);
chassis.waitUntilDone();
intake_motor = -127;
pros::delay(200);

//get pre load
chassis.turnToHeading(180, 1000);
chassis.waitUntilDone();
chassis.setPose(chassis_x, chassis_y, chassis.getPose().theta);
intake_motor = 127;
chassis.moveToPoint(35, -63, 5000);
waitUntilBall(2500);
chassis.cancelMotion();

//descore side ball
/*
chassis.moveToPoint(47.5, -54, 2000, {.forwards = false, .minSpeed=40});
chassis.waitUntilDone();
back_wing_L.set_value(true);
chassis.moveToPoint(57.75, -45, 3000, {.forwards = false, .minSpeed=40});
chassis.waitUntilDone();
chassis_x = chassis.getPose().x;
chassis_y = chassis.getPose().y;
std::cout << chassis.getPose().x << ", " << chassis.getPose().y << "\n";
//chassis.turnToHeading(-10, 1000, {.forwards = false, .minSpeed=40});
//chassis.waitUntilDone();
//intake_motor = 0;
//back_wings(false);
*/
//spit out ball and score in side
chassis.moveToPoint(63, -44, 2000, {.forwards = false});
chassis.waitUntilDone();
chassis.turnToHeading(0, 1000);
chassis.waitUntil(10); 
back_wings(false);
chassis.waitUntilDone();
intake_motor = -127;
pros::delay(200);
chassis.turnToHeading(0, 1000, {.forwards=false});
chassis.waitUntilDone();
//std::cout << chassis.getPose().x << ", " << chassis.getPose().y;
//chassis.setPose(chassis_x+1.77, chassis_y+5.51, chassis.getPose().theta);
//back_wing_L.set_value(true);
chassis.moveToPoint(63, -24, 2000, {.forwards=false, .minSpeed=50});
chassis.waitUntilDone();
chassis.moveToPoint(63, -40, 1000, {.minSpeed=30});
chassis.waitUntilDone();
chassis.moveToPoint(63, -24, 2000, {.forwards=false, .minSpeed=50});
chassis.waitUntilDone();
chassis.setPose(chassis.getPose().x, -30, chassis.getPose().theta);
intake_motor = 0;
//back_wings(false);

//touch bar
intake_motor = 127;
chassis.moveToPoint(43, -60, 2000, {.minSpeed=40});
chassis.waitUntilDone();
chassis.turnToHeading(270, 1000, {.minSpeed=40});
chassis.waitUntilDone();
chassis.moveToPoint(22, -60, 5000);
chassis.waitUntilDone();
}