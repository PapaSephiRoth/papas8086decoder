#ifndef REG
  #define REG(reg, regw0, regw1)
#endif

#ifndef ADDR
  #define ADDR(name, print)
#endif

#ifndef RM
#define RM(mod, rm, addr, disp)
#endif

#define MOD00(rm, addr) RM(0, rm, addr, 0)
#define MOD01(rm, addr) RM(1, rm, addr, 1)
#define MOD10(rm, addr) RM(2, rm, addr, 2)



REG(0, al, ax)
REG(1, cl, cx)
REG(2, dl, dx)
REG(3, bl, bx)
REG(4, ah, sp)
REG(5, ch, bp)
REG(6, dh, si)
REG(7, bh, di)

ADDR(direct, "%d")
ADDR(bx_si, "bx+si")
ADDR(bx_di, "bx+di")
ADDR(bp_si, "bp+si")
ADDR(bp_di, "bp+di")

MOD00(0, bx_si)
MOD00(1, bx_di)
MOD00(2, bp_si)
MOD00(3, bp_di)
MOD00(4, si)
MOD00(5, di)
RM(0, 6, direct, 2)
MOD00(7, bx)

MOD01(0, bx_si)
MOD01(1, bx_di)
MOD01(2, bp_si)
MOD01(3, bp_di)
MOD01(4, si)
MOD01(5, di)
MOD01(6, bp)
MOD01(7, bx)

MOD10(0, bx_si)
MOD10(1, bx_di)
MOD10(2, bp_si)
MOD10(3, bp_di)
MOD10(4, si)
MOD10(5, di)
MOD10(6, bp)
MOD10(7, bx)
#undef REG
#undef ADDR
#undef RM
