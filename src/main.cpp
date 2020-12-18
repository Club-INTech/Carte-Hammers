//
// Created by tsimafei on 15/12/2020.
//

#include <Arduino.h>
#include <Servo.h>

#include "HammerServo.h"
#include "I2CC.h"
#include "Orders.h"
#include "PumpsServo.h"

#include "OrderWrapper.hpp"

using namespace I2CC;

int test(int a) { return 0; }

void setup() {

  BufferedData a(0);
  WRAP_ORDER(test)(a);

#if defined(CARTE_HAMMERS)
  // Initialiser l'interface avec l'hardware
  initialize_hammer_servos();

  // Enregistrer les callbacks dans I2CC
  int i = 0;
  registerRPC(set_hammer_angle, i++);
  registerRPC(raise_hammer, i++);
  registerRPC(lower_hammer, i++);

  // Rejoindre le bus I2C en tant qu'esclave et se mettre en standby
  startI2CC(1);
#endif

#if defined(CARTE_PUMPS)
  // Initialiser l'interface avec l'hardware
  initialize_pumps();

  // Enregistrer les callbacks dans I2CC
  int i = 0;
  registerRPC(toggle_valve, i++);
  registerRPC(suck, i++);

  // Rejoindre le bus I2C en tant qu'esclave et se mettre en standby
  startI2CC(2);
#endif

#if defined(CARTE_MASTER)

  #pragma message "TODO : écrire le code pour le flag"

#endif
}

void loop() {}
