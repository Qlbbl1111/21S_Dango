#include "main.h"

void setIntake() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !shift()) {
    intake_motor = 127;
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && shift()) {
    intake_motor = -127;
  } else {
    intake_motor = 0;
  }
}