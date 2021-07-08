//
// Created by tsimafei on 15/12/2020.
// Toutes les constantes utiles sont définies ici. A termes, l'objectif serait
// de définir les différentes constantes via des macro définies par le CMake.
//
// 'hammer_pins' est un tableau 'constexpr' qui permet d'associer chaque broche
// reliée à un des servomoteurs à un index. Le reste du code de la carte servo
// est fait de tel manière que pour ajouter un servomoteur supplémentaire : il
// suffit simplement d'ajouter le numéro de la broche correspondante à
// 'hammer_pins'.
//
// Idem pour 'valve_pins' et 'pump_pins'.
//

#ifndef CARTE_HAMMERS_PINMAPPING_H
#define CARTE_HAMMERS_PINMAPPING_H

#include "Arduino.h"

constexpr int hammer_pins[] = {3, 5, 6, 10, 9, 11};
constexpr auto hammer_nbr = sizeof(hammer_pins) / sizeof(*hammer_pins);
constexpr int pump_pins[] = {A0, A1, A2, A3};
constexpr auto pump_nbr = sizeof(pump_pins) / sizeof(*pump_pins);

#endif //CARTE_HAMMERS_PINMAPPING_H
