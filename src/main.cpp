//
// Created by tsimafei on 15/12/2020.
//

#include <Arduino.h>
#include <Servo.h>

#include "HammerServo.h"
#include "I2CC.h"
#include "Orders.h"
#include "PumpsServo.h"

// Depuis le code du master
// #include <external.hpp>

using namespace I2CC;

void setup() {
  // using namespace external;

#if defined(CARTE_HAMMERS)
  // Initialiser l'interface avec l'hardware
  initialize_hammer_servos();

  // Enregistrer les callbacks dans I2CC
  registerRPC(set_hammer_angle, set_hammer_angle_id);
  registerRPC(raise_hammer, raise_hammer_id);
  registerRPC(lower_hammer, lower_hammer_id);

  // Rejoindre le bus I2C en tant qu'esclave et se mettre en standby
  startI2CC(hammers_id);
#endif

#if defined(CARTE_PUMPS)
  // Initialiser l'interface avec l'hardware
  initialize_pumps();

  // Enregistrer les callbacks dans I2CC
  registerRPC(toggle_valve, toggle_valve_id);
  registerRPC(suck, suck_id);

  // Rejoindre le bus I2C en tant qu'esclave et se mettre en standby
  startI2CC(pumps_id);
#endif

#if defined(CARTE_MASTER)

  #pragma message "TODO : écrire le code pour le flag"

#endif
}

void loop() {}
