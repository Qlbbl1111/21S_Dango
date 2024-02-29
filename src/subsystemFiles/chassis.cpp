#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/motors.h"

int curve(int input) {
    double t = 7;
    return (exp(-(t/10))+exp((abs(input)-127)/10)*(1- exp(-(t/10))))*input;
}

void reset_drive_sensor(){
    left_front_motor.tare_position();
    right_front_motor.tare_position();  
}
void set_tank(int left, int right) {
    left_side_motors = left;
    right_side_motors = right;
}

float active_brake_kp = 70;
bool op_started = true;
void driveControl(int l_stick, int r_stick) {
    if (op_started) {
        left_back_motor.tare_position();
        right_back_motor.tare_position();
        op_started = false;
    }
        //left side
        if (abs(l_stick) > 5) { // Threshold if joysticks don't come back to perfect 0
            left_side_motors = curve(l_stick);
            if (active_brake_kp != 0) left_back_motor.tare_position();
        }
        //When joys are released, run active brake (P) on drive left
        else {
            left_side_motors = (0 - left_back_motor.get_position()) * active_brake_kp;
        }
        //right side
        if (abs(r_stick) > 5) { // Threshold if joysticks don't come back to perfect 0
            right_side_motors = curve(r_stick); 
            if (active_brake_kp != 0) right_back_motor.tare_position(); 
        }
        //When joys are released, run active brake (P) on drive right
        else {
            right_side_motors = (0 - right_back_motor.get_position()) * active_brake_kp;
        }
}

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_side_motors, // left motor group
                              &right_side_motors, // right motor group
                              10.5, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
                              450, // drivetrain rpm is 360
                              8 // chase power is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(11, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(1.5, // proportional gain (kP)
                                             0.1, // integral gain (kI)
                                             4, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// sensors for odometry
// note that in this example we use internal motor encoders (IMEs), so we don't pass vertical tracking wheels
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial // inertial sensor
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);
