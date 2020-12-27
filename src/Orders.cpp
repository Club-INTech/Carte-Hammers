//
// Created by tsimafei on 15/12/2020.
//

#include "Orders.h"

BufferedData* set_hammer_angle(BufferedData& args) {
  uint8_t servo_index;
  float   setpoint_dg;
  getData(servo_index, &args);
  getData(setpoint_dg, &args);

  hammer_servos[servo_index].write(setpoint_dg);

  return nullptr;
}

BufferedData* raise_hammer(BufferedData& args) {
  uint8_t servo_index;
  getData(servo_index, &args);

  hammer_servos[servo_index].write(raised_hammer_angle_dg);

  return nullptr;
}

BufferedData* lower_hammer(BufferedData& args) {
  uint8_t servo_index;
  getData(servo_index, &args);

  hammer_servos[servo_index].write(lowered_hammer_angle_dg);

  return nullptr;
}

BufferedData* toggle_valve(BufferedData& args) {
  size_t valve_index;
  bool   state;
  getData(valve_index, &args);
  getData(state, &args);

  digitalWrite(valve_pins[valve_index], state);

  return nullptr;
}

BufferedData* suck(BufferedData& args) {
  size_t pump_index;
  bool   state;
  getData(pump_index, &args);
  getData(state, &args);

  digitalWrite(pump_pins[pump_index], state);

  return nullptr;
}
