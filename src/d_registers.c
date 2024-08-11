#include "d_registers.h"

register_e get_reg(uint8_t reg, uint8_t w) {
  for (int i = 0; i < REG_COUNT; ++i) {
    if(register_lut[i].reg_val == reg && register_lut[i].w_val == w)
      return (register_e) register_lut[i].reg;
  }

  return REG_INVALID;
}
