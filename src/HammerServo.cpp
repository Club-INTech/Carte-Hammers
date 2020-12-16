#include "HammerServo.h"

std::array<Servo, hammer_nbr> hammer_servos;

// Initialiser 'hammer_servos' en associant chaque élément du tableau à un servomoteurs
void initialize_hammer_servos() {
  for(auto i = 0; i < hammer_servos.size(); i++) {
    pinMode(hammer_pins[i], OUTPUT);
    hammer_servos[i].attach(hammer_pins[i]);
    hammer_servos[i].write(raised_hammer_angle);
  }
}
