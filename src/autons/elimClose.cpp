#include "main.h"

void elimClose() {
closeWP();
chassis.moveToPoint(-44, -57, 5000, {.forwards=false});
chassis.waitUntilDone();
}