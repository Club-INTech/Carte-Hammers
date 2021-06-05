#include "HammerServo.h"

Servo hammer_servos[hammer_nbr];

// Initialiser 'hammer_servos' en associant chaque élément du tableau à un servomoteurs puis en recalant mécaniquement
// les marteaux contre la pièce fixe et enfin les relever
void initialize_hammer_servos() {
  for (uint8_t i = 0; i < hammer_nbr; i++) {
    pinMode(hammer_pins[i], OUTPUT);
    hammer_servos[i].attach(hammer_pins[i]);
    hammer_servos[i].write(lowered_hammer_angle_dg);
  }

  delay(swing_duration);

  for (auto& servo : hammer_servos) servo.write(raised_hammer_angle_dg);
}
