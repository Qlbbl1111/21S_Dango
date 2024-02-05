#include "main.h"

okapi::ControllerButton kickerHold(okapi::ControllerDigital::R2);

bool toggleKicker = false;
bool latchKicker = false;
bool kicker_cycle = false;
bool kickerUp = false;

void setKicker() {
  if (toggleKicker or controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    kicker_motor = 127;
    kickerUp = false;
  } else {
    kicker_motor = 0;
    kickerUp = true;
    /*
    if (kickerRot.get_position() < 1 && !kickerUp) {
        kickerUp = true;
        kicker_motor = 0;
        kickerRot.set_position(0);
    } 
    */
  }

  if (kickerHold.isPressed()) {
    if (!latchKicker) { // if latch false, toggle one time and set latch true
      toggleKicker = !toggleKicker;
      latchKicker = true;
    }
  } else {
    latchKicker = false; // once button is released then release the latch too
  }
}
/*
void setKicker() {
  kicker_a.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  kicker_b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  
  if (kickerHold.ispressed()) {
    if (!toggleKicker) {
        toggleKicker = !toggleKicker;
    }
    else {
        toggleKicker = !toggleKicker;
    }
}
  //Cata Control (L1 for press, L2 for Toggle)
  if (toggleKicker ^ controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) ) {
    //set motors for toggle or press but Dont allow toggle and press
    kicker_motors = 127;
    kickerUp = false;

  } else {
    //turn off if neither
      if (kickerRot.get_position() < 1 && !kickerUp) {
        kickerUp = true;
        kicker_motors = 0;
        kickerRot.set_position(0);
      } 
  }
}
*/