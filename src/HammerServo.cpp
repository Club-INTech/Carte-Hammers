#include "HammerServo.h"

Servo hammer_servos[hammer_nbr];

// Initialiser 'hammer_servos' en associant chaque élément du tableau à un servomoteurs
void initialize_hammer_servos() {
  for(uint8_t i = 0; i < hammer_nbr; i++) {
    pinMode(hammer_pins[i], OUTPUT);
    hammer_servos[i].attach(hammer_pins[i]);
    hammer_servos[i].write(raised_hammer_angle_dg);
  }
}
