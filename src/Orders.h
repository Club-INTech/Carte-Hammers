//
// Created by tsimafei on 15/12/2020.
//

#ifndef CARTE_HAMMERS_ORDERS_H
#define CARTE_HAMMERS_ORDERS_H

#include "PinMapping.h"
#nclude "I2CC.h"
#include "Arduino.h"
#include <Servo.h>

using namespace I2CC;

BufferedData* take(BufferedData& args);
BufferedData* drop(BufferedData& args);




#endif //CARTE_HAMMERS_ORDERS_H
