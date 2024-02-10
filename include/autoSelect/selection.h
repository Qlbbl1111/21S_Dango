#pragma once

#include <string>

//selector configuration
#define HUE 135
#define DEFAULT 4
#define AUTONS "closeWP", "farWP", "sixBall", "Do Nothing"

namespace selector{

extern int auton;
const char *b[] = {AUTONS, ""};
void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b);

}
