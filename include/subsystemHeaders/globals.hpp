#include "main.h"
#include "pros/adi.hpp"

// DRIVETRAIN
extern pros::Motor left_front_motor;
extern pros::Motor left_mid_motor;
extern pros::Motor left_back_motor;
extern pros::Motor right_front_motor;
extern pros::Motor right_mid_motor;
extern pros::Motor right_back_motor;

extern pros::MotorGroup left_side_motors;
extern pros::MotorGroup right_side_motors;

// MOTORS
extern pros::Motor intake_motor;
extern pros::Motor kicker_motor;

// CONTROLLER
extern pros::Controller controller;

// SENSORS
extern pros::Imu inertial;
extern pros::Rotation kickerRot;

// PNUEMATICS
extern pros::ADIDigitalOut wings;
extern pros::ADIDigitalOut bar_hang;
extern pros::ADIDigitalOut back_wings;

// LIGHTS


// GLOBALS
bool shift();