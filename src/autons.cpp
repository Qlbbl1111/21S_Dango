#include "main.h"
#include "lemlib/api.hpp"


void sixBall() {
chassis.setPose(38.728, -53.346, 0);

//Get mid bar ball
intake_motor = 127;
chassis.moveToPoint(6, -2.7, 5000);
chassis.waitUntilDone();

//Push in
chassis.turnTo(45.113, -2, 1000);
chassis.waitUntilDone();
wings.set_value(true);
chassis.moveToPoint(40, -2, 3000);
chassis.waitUntil(26);
intake_motor = -127;
chassis.waitUntilDone();
wings.set_value(false);

//get lone ball
chassis.moveToPoint(27.135, -13.021, 5000, false);
chassis.waitUntilDone();
intake_motor = 0;
chassis.turnTo(11.005, -20.414, 1000);
chassis.waitUntilDone();
intake_motor = 127;
chassis.moveToPoint(6.5, -23, 5000);
chassis.waitUntilDone();

//Outtake ball at side
chassis.moveToPoint(46.289, -41.417, 5000);
chassis.waitUntilDone();
intake_motor = 0;
chassis.turnTo(61.411, -27.135, 1000);
chassis.waitUntilDone();
intake_motor = -127;
pros::delay(250);

//get elevation bar ball
chassis.turnTo(33, -55.5, 1000);
chassis.waitUntilDone();
chassis.moveToPoint(22, -55.5, 5000);
chassis.waitUntilDone();
intake_motor = 127;
chassis.moveToPoint(6, -58, 5000);
chassis.waitUntilDone();

//move to descore
chassis.moveToPoint(47, -56, 5000, false);
chassis.waitUntilDone();

//descore
intake_motor = 0;
back_wing_L.set_value(true);
chassis.moveToPoint(61.5, -42, 5000, false);
chassis.waitUntilDone();
//descore spin
chassis.turnTo(62.5, -26, 5000, false);
chassis.waitUntilDone();
back_wing_L.set_value(false);
//side score
back_wing_R.set_value(true);
chassis.moveToPoint(62.5, -26, 5000, false);
chassis.waitUntilDone();
back_wing_R.set_value(false);
//intake ball score
chassis.moveToPoint(62.5, -33, 5000);
chassis.waitUntilDone();
chassis.turnTo(62.5, -29, 5000);
chassis.waitUntilDone();
intake_motor = -127;
chassis.moveToPoint(62.5, -27, 5000);
chassis.waitUntilDone();

}

void closeWP() {
chassis.setPose(-35, -55, 0); //set robots starting position

//steal mid ball
intake_motor = 127;
chassis.moveToPoint(-25.25, -9, 5000); //move to intake middle ball (fig.A)
chassis.waitUntilDone();

//push over
chassis.turnTo(-8, -9, 1000); //turn to face the bar
chassis.waitUntilDone();
wings.set_value(true);
chassis.moveToPoint(-8, -9, 5000); //move to push over middle ball and middle bar ball (fig.A and fig.B)
chassis.waitUntilDone();
wings.set_value(false);
//go to matchload bar
chassis.turnTo(-41, -46, 1000); // turn to face the matchload bar
chassis.waitUntilDone();
chassis.moveToPoint(-41, -46, 5000); //move to the matchload bar (fig.C)
chassis.waitUntilDone();
intake_motor = 0;
//descore
back_wing_R.set_value(true);
chassis.turnTo(-33, -55, 5000);
chassis.waitUntilDone();
chassis.moveToPoint(-33, -55, 5000);
chassis.waitUntilDone();
chassis.turnTo(-25, -11, 1000, true, 127); //spin to remove the matchload zone ball for AWP (fig.D)
chassis.waitUntilDone();
back_wing_R.set_value(false);
//touch elevation bar
chassis.turnTo(0, -55, 1000);
chassis.waitUntilDone();
pros::delay(2500); //wait for some time to let our allaince finish their auton
chassis.moveToPoint(-4, -55, 5000); //move to touch the elevation bar (fig.E)
chassis.waitUntilDone();
intake_motor = -127;
chassis.turnTo(1000, -55, 1000);
chassis.waitUntilDone();
chassis.moveToPoint(-3, -55, 5000);
chassis.waitUntilDone();
intake_motor = 0;
}

void farWP() {
chassis.setPose(35, -55, 0); //set robots starting position

//Get mid bar ball
chassis.moveToPoint(15.542, -15.038, 5000); //move to middle of the field
chassis.waitUntilDone();
chassis.turnTo(42.761, -10, 1000); //turn to face goal
chassis.waitUntilDone();
intake_motor = -127; //outtake preload ball to goal
pros::delay(250);
intake_motor = 127;
chassis.turnTo(9, -3, 1000);
chassis.waitUntilDone();
chassis.moveToPoint(9, -3, 5000); //move to intake middle bar ball (fig.A)
chassis.waitUntilDone();

//Push in
chassis.turnTo(45, 0, 1000); //turn to face goal
chassis.waitUntilDone();
wings.set_value(true);
chassis.moveToPoint(38, 0, 2000); //push middle ball and middle bar ball (fig.A and fig.B) into goal.
chassis.waitUntil(26);
intake_motor = -127;
chassis.waitUntilDone();
wings.set_value(false);

//get lone ball
intake_motor = 0;
chassis.moveToPoint(30, 0, 2000, false); //back up from goal
chassis.waitUntilDone();
chassis.turnTo(8, -21, 1000);
chassis.waitUntilDone();
intake_motor = 127;
chassis.moveToPoint(8, -21, 5000); //move to intake lone ball (fig.C)
chassis.waitUntilDone();
intake_motor = 0;

//score lone ball
chassis.moveToPoint(38, -4,  3000); //move back to goal to score lone ball
chassis.waitUntil(26);
intake_motor = -127;
chassis.waitUntilDone();
intake_motor = 0;

//touch bar
chassis.moveToPoint(9, -36.5, 5000, false); //move to the corrner of long and short barrier (fig.D)
chassis.waitUntilDone();
chassis.turnTo(-16, -38, 1000, false);
chassis.waitUntilDone();
back_wing_R.set_value(true); //activate back wing to touch bar
chassis.moveToPoint(2, -36.5, 2000, false);
chassis.waitUntilDone();
chassis.turnTo(-16, -32, 1000, false); //turn slightly to ensure we touch the bar
chassis.waitUntilDone();
}


ASSET(drive_across_txt); //path to drive to other side of feild
void skillsAuton() {
    chassis.setPose(-46.8, -58.6, 135); //set robots starting position

    chassis.moveToPoint(-60, -45, 5000, false);
    chassis.waitUntilDone();
    chassis.turnTo(46, -23, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-65.7, -46.5, 2000); //postion the robot to touch bar for match loading
    chassis.waitUntilDone();
    kicker_motor = 127;
    back_wing_R.set_value(true); //make sure the robot is touching the bar
    pros::delay(25000); //run the kiker for 24.5 seconds to matchload all 44 balls
    kicker_motor = 0;
    back_wing_R.set_value(false);
    chassis.moveToPoint(-60, -45, 5000);
    chassis.waitUntilDone();

    //score the 2 red preloads in the side of the blue goal
    chassis.turnTo(-60, -70, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, -24, 3000, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, -37, 2000, true);
    chassis.waitUntilDone();

    //drive to the other side of the feild to score
    chassis.moveToPoint(-31, -58, 2500);
    chassis.waitUntilDone();
    chassis.moveToPoint(37, -58, 2500);
    chassis.waitUntilDone();
    chassis.moveToPoint(57, -38, 4000);
    chassis.waitUntilDone();

    //push balls into the side of the goal
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

    //push balls into the goal on the right with front
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

    //push balls into the goal on in the middle with back
    chassis.moveToPoint(6, -2, 5000, false);
    chassis.waitUntil(5);
    wings.set_value(false);
    chassis.waitUntilDone();
    back_wings(true);
    chassis.moveToPose(43, -2, 270, 3000, {.forwards=false});
    chassis.waitUntilDone();
    chassis.moveToPoint(34, -2, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(43, -2, 3000, false);
    chassis.waitUntilDone();

    //push balls into the goal on the left with back
    chassis.moveToPoint(20, -2, 5000);
    chassis.waitUntil(5);
    back_wings(false);
    chassis.waitUntilDone();
    chassis.moveToPose(13, 30, 180, 3000, {.forwards=false});
    chassis.waitUntilDone();

    chassis.moveToPose(43, 6, 270, 3000, {.forwards=false});
    chassis.waitUntil(10);
    back_wings(true);
    chassis.waitUntilDone();
    chassis.moveToPoint(30, 6, 2000, true);
    chassis.waitUntilDone();
    chassis.moveToPoint(43, 6, 3000, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(28, 5, 5000, true);
    chassis.waitUntilDone();
    back_wings(false);
}

void nothing() {

}