#include <stdint.h>

#define REG_NAME(n) reg_##n

typedef enum {
  REG_INVALID = -1, 
  #define REG_ENC(n, ...) REG_NAME(n),
  #include "d_registers_def.h"
  REG_COUNT
} register_e;

typedef struct {
  uint8_t reg;
  uint8_t reg_val : 3;
  uint8_t w_val : 1;
} register_table_entry_t;

static const register_table_entry_t register_lut[REG_COUNT] = {
  #define REG_ENC(n, r, w) {REG_NAME(n), 0b##r, 0b##w},
  #include "d_registers_def.h"
};

static const char* register_names[REG_COUNT] = {
  #define REG_ENC(n, ...) #n,
  #include "d_registers_def.h"
};

#undef REG_NAME

register_e get_reg(uint8_t reg, uint8_t w);

