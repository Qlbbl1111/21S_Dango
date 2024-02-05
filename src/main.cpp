#include "main.h"

 void motorTemp(){
  while(true) {
  float motorTemps = (left_front_motor.get_temperature() + left_mid_motor.get_temperature() + left_back_motor.get_temperature() + right_front_motor.get_temperature()+ right_mid_motor.get_temperature() + right_back_motor.get_temperature())/6;
  //std::cout << motorTemps << std::endl;
  
  if (motorTemps <= 30) {
    controller.print(0, 0, "Drive: COLD, %.2f", motorTemps);
  } else if (motorTemps > 30 && motorTemps <= 45) {
    controller.print(0, 0, "Drive: WARM, %.2f", motorTemps);
  } else if (motorTemps > 45) {
    controller.print(0, 0, "Drive: HOT, %.2f", motorTemps);
  }
  pros::delay(2000);
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
	kickerRot.reset_position();
	kickerRot.set_position(0);

	// thread to for brain screen and position logging
    pros::Task screenTask([&]() {
        lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });
	pros::Task temps(motorTemp);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  skillsAuton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	left_front_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	left_mid_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  	left_back_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	right_front_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	right_mid_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	right_back_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	while (true) {
		driveControl(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		setIntake();
		setKicker();
		setWings();
    setBarHang();
		pros::delay(10);
	}
}