#include "main.h"

// DRIVETRAIN
pros::Motor left_front_motor(19, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS); 
pros::Motor left_mid_motor(18, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left_back_motor(16, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS); 
pros::Motor right_front_motor(11, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_mid_motor(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_back_motor(14, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS); 

pros::MotorGroup left_side_motors({left_front_motor, left_mid_motor, left_back_motor});
pros::MotorGroup right_side_motors({right_front_motor, right_mid_motor, right_back_motor});

// MOTORS
pros::Motor intake_motor(4, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor kicker_motor(6, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

// CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// SENSORS
pros::Imu inertial(21);
pros::Rotation kickerRot(7);
pros::ADIDigitalIn autoSwitch('A');

// PNUEMATICS
pros::ADIDigitalOut wings('H');
pros::ADIDigitalOut bar_hang('G');
pros::ADIDigitalOut back_wing_R('F');
pros::ADIDigitalOut back_wing_L('E');

// LIGHTS ADI expander on port 7
pros::ADILed left_drive_led(1, 39);

//GLOABALS
bool shift() {
  return controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
}