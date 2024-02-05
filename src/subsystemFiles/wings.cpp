#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

okapi::ControllerButton wingsButton(okapi::ControllerDigital::B);
bool toggle = false;
bool latch = false;

void sideWings(){
  if (toggle) {
    wings.set_value(true);
  } else {
    wings.set_value(false);
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
    back_wings.set_value(true);
  } else {
    back_wings.set_value(false);
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

okapi::ControllerButton barHangButton(okapi::ControllerDigital::A);
bool toggleBar = false;
bool latchBar = false;

void setBarHang() {
  if (toggleBar) {
    bar_hang.set_value(true);
  } else {
    bar_hang.set_value(false);
  }

  if (barHangButton.isPressed()) {
    if (!latchBar) { // if latch false, toggle one time and set latch true
      toggleBar = !toggleBar;
      latchBar = true;
    }
  } else {
    latchBar = false; // once button is released then release the latch too
  }
}