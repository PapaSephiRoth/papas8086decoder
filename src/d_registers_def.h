#ifndef REG_ENC
#define REG_ENC(a,b,c)
#endif

REG_ENC(al, 000, 0) 
REG_ENC(ax, 000, 1) 
REG_ENC(cl, 001, 0) 
REG_ENC(cx, 001, 1) 
REG_ENC(dl, 010, 0) 
REG_ENC(dx, 010, 1) 
REG_ENC(bl, 011, 0) 
REG_ENC(bx, 011, 1) 
REG_ENC(ah, 100, 0) 
REG_ENC(sp, 100, 1) 
REG_ENC(ch, 101, 0) 
REG_ENC(bp, 101, 1) 
REG_ENC(dh, 110, 0) 
REG_ENC(si, 110, 1) 
REG_ENC(bh, 111, 0) 
REG_ENC(di, 111, 1)

#undef REG_ENC
