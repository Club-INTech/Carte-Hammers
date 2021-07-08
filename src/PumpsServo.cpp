#include "PumpsServo.h"

//Initialiser les broches des pompes et des valves
void initialize_pumps() {
  for (auto pin : pump_pins) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}
