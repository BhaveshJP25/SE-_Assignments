#include <dos.h>
#include <process.h>
#include <stdio.h>

int main(void)
{
   char filename[80];
   union REGS inregs, outregs;
   struct SREGS segregs;

   printf("Enter filename: ");
   gets(filename);
   inregs.h.ah = 0x3c;
   inregs.h.al = 0x21;
   inregs.x.dx = FP_OFF(filename);
   segregs.ds = FP_SEG(filename);
   int86x(0x21, &inregs, &outregs, &segregs);
   printf("File attribute: %X\n", outregs.x.cx);
   return 0;
}
