//
// Created by tsimafei on 15/12/2020.
//

#ifndef CARTE_HAMMERS_ORDERS_H
#define CARTE_HAMMERS_ORDERS_H

#include <Arduino.h>
#include <Servo.h>

#include "HammerServo.h"
#include "I2CC.h"
#include "PinMapping.h"

using namespace I2CC;

// Angles des marteaux par rapport au plan horizontal lorsqu'ils sont levés et
// baissés (en degré)
constexpr int raised_hammer_angle_dg = 0;
constexpr int lowered_hammer_angle_dg = -90;

BufferedData* set_hammer_angle(BufferedData&);
BufferedData* raise_hammer(BufferedData&);
BufferedData* lower_hammer(BufferedData&);

#endif //CARTE_HAMMERS_ORDERS_H
