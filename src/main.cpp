#include "main.h"
#include "autoSelect/selection.h"
#include "pros/misc.h"

okapi::ControllerButton motor_temp_button(okapi::ControllerDigital::X);
 void motorTemp(){
  while(true) {
  float motorTemps = (left_front_motor.get_temperature() + left_mid_motor.get_temperature() + left_back_motor.get_temperature() + right_front_motor.get_temperature()+ right_mid_motor.get_temperature() + right_back_motor.get_temperature())/6;
  float kickerMotorTemp = kicker_motor.get_temperature();
  //std::cout << motorTemps << std::endl;
  if (motor_temp_button.isPressed()){
    if (kickerMotorTemp <= 30) {
      controller.print(0, 0, "Kicker: COLD, %.0lf°C", kickerMotorTemp);
      } else if (kickerMotorTemp > 30 && kickerMotorTemp <= 45) {
      controller.print(0, 0, "Kicker: WARM, %.0lf°C", kickerMotorTemp);
      } else if (kickerMotorTemp > 45) {
      controller.print(0, 0, "Kicker: HOT, %.0lf°C", kickerMotorTemp);
      }
      pros::delay(2000);
    } else {
      if (motorTemps <= 30) {
      controller.print(0, 0, "Drive: COLD, %.0lf°C", motorTemps);
      } else if (motorTemps > 30 && motorTemps <= 45) {
      controller.print(0, 0, "Drive: WARM, %.0lf°C", motorTemps);
      } else if (motorTemps > 45) {
      controller.print(0, 0, "Drive: HOT, %.0lf°C", motorTemps);
      }
      pros::delay(2000);
    }
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
bool testing = true;
void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
	kickerRot.reset_position();
	kickerRot.set_position(0);
  if (!testing) selector::init();
  pros::Task temps(motorTemp);

  left_drive_led.set_all(0x808080);
  left_drive_led.update();

	// thread to for brain screen and position logging
  if (testing){
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
  }

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

void auto_selector() {
}

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
  if (testing) {
  selector::auton = 0;
  }
  //red
  if(selector::auton == 1)  closeWP();  
  if(selector::auton == 2)  farWP(); 
  if(selector::auton == 3)  fiveBall();
  if(selector::auton == 4)  elimClose(); 
  if(selector::auton == 5)  nothing(); 
  //blue
  if(selector::auton == -1)  closeWP();  
  if(selector::auton == -2)  farWP(); 
  if(selector::auton == -3)  fiveBall();
  if(selector::auton == -4)  elimClose(); 
  if(selector::auton == -5)  nothing(); 
  //skills
  if(selector::auton == 0)  skillsAuton();
  chassis.cancelAllMotions();
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
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.cancelAllMotions();
  left_side_motors = 0;
  right_side_motors = 0;
  reset_drive_sensors();
	while (true) {
		driveControl(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		setIntake();
		setKicker();
		setWings();
    setBarHang();
		pros::delay(10);
	}
}
