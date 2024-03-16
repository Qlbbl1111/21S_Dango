#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void skillsAuton() {
    chassis.setPose(-48, -59.75, 135); //set robots starting position

    //score the 2 red preloads in the side of the blue goal
    kicker_motor = 127;
    chassis.moveToPoint(-60, -45, 2000, {.forwards = false, .minSpeed=20});
    chassis.waitUntilDone();
    kicker_motor = 0;
    chassis.turnToHeading(0, 1000, {.forwards = false, .minSpeed=20});
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, -30, 2000, {.forwards = false, .minSpeed=70});
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, -37, 2000);
    chassis.waitUntilDone();
    //shoot
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    kicker_motor = 127;
    chassis.moveToPoint(-60, -45, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(-65.7, -46.5, 70, 2000, {.forwards = false}); //postion the robot to touch bar for match loading
    chassis.waitUntilDone();
    back_wing_R.set_value(true); //make sure the robot is touching the bar
    left_side_motors = -50;
    right_side_motors = -50;
    pros::delay(500);
    left_side_motors = 0;
    right_side_motors = 0;
    float chassis_x = chassis.getPose().x;
    float chassis_y = chassis.getPose().y;
    float chassis_theta = chassis.getPose().theta;
    std::cout << "pos:" << chassis.getPose().theta <<", " << chassis_theta << "\n";
    pros::delay(24000); //run the kicker for 24 seconds to matchload all 44 balls
    kicker_motor = 0;
    chassis.setPose(chassis.getPose().x, chassis.getPose().y, chassis_theta);
    back_wing_R.set_value(false);
    chassis.moveToPoint(-60, -45, 2000);
    chassis.waitUntilDone();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

    //push balls over
    intake_motor = -127;
    chassis.moveToPoint(-21, -35, 3000, {.maxSpeed=80});
    chassis.waitUntilDone();
    //chassis.setPose(chassis.getPose().x, chassis.getPose().y, 90);
    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();
    front_wing_L.set_value(true);
    chassis.moveToPoint(-21, 33, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-21, 28, 2000, {.forwards = false, .minSpeed=70});
    chassis.waitUntilDone();
    front_wing_L.set_value(false);
    chassis.moveToPoint(-21, 39, 2000);
    chassis.waitUntilDone();

    //drive around
    chassis.moveToPoint(-21, 28, 2500, {.forwards = false});
    chassis.waitUntilDone();
    intake_motor = -127;
    chassis.moveToPoint(-49, 40, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-40, 60, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();
    front_wings(false);
    chassis.moveToPoint(24, 60, 4000);
    chassis.waitUntilDone();
    front_wings(false);
    intake_motor = 0;

    //score left side
    chassis.turnToHeading(90, 1000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.moveToPose(61, 27, 0, 4000, {.forwards=false, .minSpeed=70});
    chassis.waitUntil(12);
    back_wing_L.set_value(true);
    chassis.waitUntilDone();
    back_wings(false);
    chassis.moveToPoint(61, 42, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(61, 27, 2000, {.forwards = false, .minSpeed=70});
    chassis.waitUntilDone();
    chassis.waitUntilDone();
    //chassis.setPose(59.5, 27, 0);

    //score left front
    chassis.moveToPoint(59.5, 42, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(13, 28, 2000);
    chassis.waitUntilDone();
    chassis.turnToPoint(22, 12, 1000, {.forwards = false});
    chassis.waitUntilDone();
    back_wings(true);
    chassis.moveToPose(41, 9, 270, 3000, {.forwards=false, .maxSpeed=100});
    chassis.waitUntilDone();
    chassis.moveToPoint(33, 9, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(41, 9, 2000, {.forwards = false, .minSpeed=70});
    chassis.waitUntilDone();
    

    //score middle
    chassis.moveToPoint(13, 9, 2000);
    chassis.waitUntil(5);
    back_wings(false);
    chassis.waitUntilDone();
    chassis.moveToPoint(13, -6, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    back_wings(true);
    chassis.moveToPoint(41, -6, 2000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    chassis.moveToPoint(31, -6, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(41, -6, 2000, {.forwards = false, .minSpeed=70});
    chassis.waitUntilDone();
    chassis.setPose(41, -2, 270);

    //score right front
    chassis.moveToPoint(14, -2, 2000);
    chassis.waitUntil(5);
    back_wings(false);
    chassis.waitUntilDone();
    chassis.moveToPoint(14, -30, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();
    chassis.turnToPoint(30, -14, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    back_wings(true);
    chassis.moveToPose(42, -14, 270, 3000, {.forwards=false, .maxSpeed=100});
    chassis.waitUntilDone();
    chassis.moveToPoint(30, -14, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(41, -14, 2000, {.forwards = false, .minSpeed=70});
    chassis.waitUntilDone();
    chassis.moveToPoint(30, -14, 2000);
    chassis.waitUntil(5);
    back_wings(false);
    chassis.waitUntilDone();

    /*
    //score right side
    chassis.moveToPoint(15, -26, 3000);
    chassis.waitUntil(5);
    back_wings(false);
    chassis.waitUntilDone();
    chassis.turnToPoint(34, -38, 1000, false);
    chassis.waitUntilDone();
    back_wing_R.set_value(true);
    chassis.moveToPoint(34, -38, 3000, false);
    chassis.waitUntilDone();
    chassis.moveToPose(60, -30, 180, 3000, {.forwards=false});
    chassis.waitUntilDone();
    back_wings(false);
    chassis.moveToPoint(60, -40, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(60, -30, 1000, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(60, -35, 1000);
    chassis.waitUntilDone();
*/
}