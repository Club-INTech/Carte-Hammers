//
// Created by tsimafei on 15/12/2020.
//

#include <Arduino.h>
#include <Servo.h>

#include "HammerServo.h"
#include "I2CC.h"
#include "Orders.h"

using namespace I2CC;

void setup() {
  // Initialiser l'interface avec les servomoteurs
  initialize_hammer_servos();

  // Enregistrer les callback dans I2CC
  int i = 0;
  registerRPC(set_hammer_angle, i++);
  registerRPC(raise_hammer, i++);
  registerRPC(lower_hammer, i++);

  // Rejoindre le bus I2C en tant qu'esclave et se mettre en standby
  #pragma message "TODO : spécifier l'addresse de chaque carte sur le bus I2C dans un fichier global"
  startI2CC(0);
}

void loop() {}
