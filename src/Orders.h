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

BufferedData* set_hammer_angle(BufferedData&);
BufferedData* raise_hammer(BufferedData&);
BufferedData* lower_hammer(BufferedData&);

BufferedData* toggle_valve(BufferedData&);
BufferedData* suck(BufferedData&);

#endif //CARTE_HAMMERS_ORDERS_H
