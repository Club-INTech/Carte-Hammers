//
// Created by tsimafei on 15/12/2020.
//

#include <Arduino.h>
#include <Servo.h>

#include "external.hpp"
#include "HammerServo.h"
#include "I2CC.h"
#include "Orders.h"
#include "PumpsServo.h"


void setup() {
  using namespace I2CC;
  using namespace external;

  // Initialiser l'interface avec l'hardware
  initialize_hammer_servos();
  initialize_pumps();

  // Enregistrer les callbacks dans I2CC
  registerRPC(set_hammer_angle, set_hammer_angle_id);
  registerRPC(raise_hammer, raise_hammer_id);
  registerRPC(lower_hammer, lower_hammer_id);
  registerRPC(suck, suck_id);

  // Rejoindre le bus I2C en tant qu'esclave et se mettre en standby
  startI2CC(hammers_id);
}

void loop() {}
