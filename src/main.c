#include "d_registers.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  union {
    struct {
      // BYTE 1
      uint8_t w : 1;
      uint8_t d : 1;
      uint8_t op_code : 6;
      // BYTE 2
      uint8_t rm : 3;
      uint8_t reg : 3;
      uint8_t mod : 2;
    } fields;
    uint16_t bits;
  };
} instruction_t;

instruction_t swap_instruction(instruction_t inst) {
  return (instruction_t){.bits = _byteswap_ushort(inst.bits)};
}

void print_instruction(instruction_t *inst) {

  printf("OP_CODE:%d|D:%d|W:%d|MOD:%d|REG:%d|RM:%d",
         inst->fields.op_code, inst->fields.d, inst->fields.w, inst->fields.mod,
         inst->fields.reg, inst->fields.rm);
}

int main(int argc, char **argv) {
  if(2 != argc) exit(1);

  const char *filename = argv[1];

  FILE *file;
  instruction_t inst;

  // use appropriate location if you are using MacOS or Linux
  file = fopen(filename, "r");
  if (file == NULL) {
    perror("fopen");
    exit(1);
  }

  printf("bits 16\n");
  while(fread(&inst, sizeof(inst), 1, file) == 1) {
    register_e reg_f = get_reg(inst.fields.reg, inst.fields.w);
    register_e reg_t = get_reg(inst.fields.rm, inst.fields.w);
    printf("mov %s, %s\n", register_names[reg_t], register_names[reg_f]);
  }
  return 0;
}
