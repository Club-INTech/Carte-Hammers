//
// Created by tsimafei on 15/12/2020.

#include "Orders.h"
#include "Arduino.h"
#include "I2CC.h"
#include <Servo.h>

using namespace I2CC;

void setup() {

    // definition of pin modes
    pinMode();

    //register functions for I2CC

    registerRPC(take,1);
    registerRPC(take,2);

}

void loop() {

}
//

