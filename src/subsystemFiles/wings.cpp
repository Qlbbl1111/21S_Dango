#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

okapi::ControllerButton wingsButton(okapi::ControllerDigital::B);
bool toggle = false;
bool latch = false;

void back_wings(bool value) {
  back_wing_R.set_value(value);
  back_wing_L.set_value(value);
}

void front_wings(bool value) {
  front_wing_R.set_value(value);
  front_wing_L.set_value(value);
}

void sideWings(){
  if (toggle) {
    front_wings(true);
  } else {
    front_wings(false);
  }

  if (wingsButton.isPressed()) {
    if (!latch) { // if latch false, toggle one time and set latch true
      toggle = !toggle;
      latch = true;
    }
  } else {
    latch = false; // once button is released then release the latch too
  }
}

okapi::ControllerButton backWingsButton(okapi::ControllerDigital::down);
bool toggleBack = false;
bool latchBack = false;

void backWings() {
  if (toggleBack) {
    back_wings(true);
  } else {
    back_wings(false);
  }

  if (backWingsButton.isPressed()) {
    if (!latchBack) { // if latch false, toggle one time and set latch true
      toggleBack = !toggleBack;
      latchBack = true;
    }
  } else {
    latchBack = false; // once button is released then release the latch too
  }
}

void setWings() { 
  sideWings();
  backWings();
}
