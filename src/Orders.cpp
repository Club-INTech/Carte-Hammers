//
// Created by tsimafei on 15/12/2020.
//

BufferedData* set_hammer_angle(BufferedData& args) {
  float  setpoint_dg;
  uint8_t servo_index;
  getData<float>(setpoint_dg, &args);
  getData<uint8_t>(servo_index, &args);

  hammer_servos[servo_index].write(setpoint_dg);

  return nullptr;
}

BufferedData* raise_hammer(BufferedData& args) {
    uint8_t servo_index;
    getData<uint8_t>(servo_index, &args);

  hammer_servos[servo_index].write(raised_hammer_angle_dg);

  return nullptr;
}

BufferedData* lower_hammer(BufferedData& args) {
    uint8_t servo_index;
    getData<uint8_t>(servo_index, &args);

  hammer_servos[servo_index].write(lowered_hammer_angle_dg);

  return nullptr;
}
