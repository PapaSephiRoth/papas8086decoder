#include "types.h"
#include "r_registers.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  union {
    struct {
      // BYTE 1
      u8 w : 1;
      u8 d : 1;
      u8 op_code : 6;
      // BYTE 2
      u8 rm : 3;
      u8 reg : 3;
      u8 mod : 2;
    } fields;
    u16 bits;
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
    
    field_enc_e regf = query_reg_table(inst.fields.reg, inst.fields.w);
    field_enc_e rmf = query_reg_table(inst.fields.rm, inst.fields.w);

    

    printf("mov %s, %s ; ", field_enc_to_str[rmf], field_enc_to_str[regf]);
    print_instruction(&inst);
    printf("\n");
  }

  return 0;
}

