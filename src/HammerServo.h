//
// Created by Stercutius on 15/12/2020.
// 'hammer_servos' est un tableau 'extern' de même taille que 'hammer_pins'
// (voir PinMapping.h). Il permet de donner accès aux objets Servo controllant
// les servomoteurs. En outre, il est nécessaire d'appeller
// 'initialize_hammer_servos' avant d'utiliser hammer_servos.
//

#ifndef CARTE_HAMMERS_HAMMER_SERVO_H
#define CARTE_HAMMERS_HAMMER_SERVO_H

#include <array>

#include <Servo.h>

#include "PinMapping.h"

// Angles des marteaux par rapport au plan horizontal lorsqu'ils sont levés et
// baissés (en degré)
constexpr int raised_hammer_angle_dg = 0;
constexpr int lowered_hammer_angle_dg = -90;

extern std::array<Servo, hammer_nbr> hammer_servos;

void initialize_hammer_servos();

#endif //CARTE_HAMMERS_HAMMER_SERVO_H
