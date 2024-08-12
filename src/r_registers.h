#include "types.h"
#define W_MAX 2
#define REG_MAX 8
#define EDA_MODS 3
#define REG_ENUM(n) reg_##n
#define ADDR_ENUM(n) addr_##n

typedef enum {
  #define REG(_, w0, w1) ADDR_ENUM(w0), ADDR_ENUM(w1),
  #define ADDR(addr, ...) ADDR_ENUM(addr),
  #include "r_register_table_def.h"
  ADDR_ENUM(count)
} field_enc_e;

static const field_enc_e reg_field_table[REG_MAX][W_MAX] = {
  #define REG(r, w0, w1) [r] = {ADDR_ENUM(w0), ADDR_ENUM(w1)},
  #include "r_register_table_def.h"
};


typedef struct {
  field_enc_e addr;
  u8 offset;
} rm_field;

static const struct {
  u8 mod;
  u8 rm;
  rm_field rmf;
} rm_field_table[EDA_MODS*REG_MAX] = {
  #define RM(mod, rm, addr, disp) { mod, rm, {ADDR_ENUM(addr), disp} },
  #include "r_register_table_def.h"
};

static const char* field_enc_to_str[addr_count] = {
  #define ADDR(n, print)
  #define REG(reg, w0, w1) \
  #w0,\
  #w1,
  #include "r_register_table_def.h"
};

field_enc_e query_reg_table(u8 reg, u8 w) {
  return reg_field_table[reg][w];
}
