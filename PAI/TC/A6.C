/*
Assignment 5
23340
F11
*/

#include <dos.h>
#include <process.h>
#include <stdio.h>
#include<conio.h>
// Function Prototypes
void addfile();
void deletefile();
void createdirectory();
void deletedirectory();
void copy();

int main(void)
{
   int lp=1, ch;
   while(lp)
   {
   		// Menu Driven Program
		printf("\n1. Add File\n2. Delete File\n3. Make Directory\n4. Delete Directory\n5. Copy\n6. Exit\n Enter Choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				addfile();		//Add File
				break;
			case 2:	
				deletefile();	//Delete File
				break;
			case 3:
				createdirectory();//Create Directory
				break;
			case 4:
				deletedirectory();//Delete Directory
				break;
			case 5:
				copy();		//Copy File
				break;
			case 6:
				lp = 0;		//Break Loop
	  }
   }
   getch();
   return 0;
}

void addfile()
{
   char filename[80];
   union REGS inregs, outregs;
   struct SREGS segregs;
   printf("\nEnter filename: ");
   fflush(stdin);
   gets(filename);
   inregs.h.ah = 0x3c;		//Add File
   inregs.x.cx=00;
   inregs.x.dx = FP_OFF(filename);
   segregs.ds = FP_SEG(filename);
   int86x(0x21, &inregs, &outregs, &segregs);
   if(outregs.x.cflag)		//Check Error
   printf("Error Creating File");
   else
   printf("File created");
}

void deletefile()
{
   char filename[80];
   union REGS inregs, outregs;
   struct SREGS segregs;
   printf("\nEnter filename: ");
   fflush(stdin);
   gets(filename);
   inregs.h.ah = 0x41;		//Delete File
   inregs.x.cx=00;
   inregs.x.dx = FP_OFF(filename);
   segregs.ds = FP_SEG(filename);
   int86x(0x21, &inregs, &outregs, &segregs);
   if(outregs.x.cflag)		//Check Error
   printf("Error Deleting File");
   else
   printf("File Deleted");
}
void createdirectory()
{
   char filename[80];
   union REGS inregs, outregs;
   struct SREGS segregs;
   printf("\nEnter Directory name: ");
   fflush(stdin);
   gets(filename);
   inregs.h.ah = 0x39;		//Add Directory
   inregs.x.cx=00;
   inregs.x.dx = FP_OFF(filename);
   segregs.ds = FP_SEG(filename);
   int86x(0x21, &inregs, &outregs, &segregs);
   if(outregs.x.cflag)		//Check Error
   printf("Error Creating Directory");
   else
   printf("Directory created");
}
void deletedirectory()
{
   char filename[80];
   union REGS inregs, outregs;
   struct SREGS segregs;
   printf("\nEnter Directory name: ");
   fflush(stdin);
   gets(filename);
   inregs.h.ah = 0x3a;		//Delete Directory
   inregs.x.cx=00;
   inregs.x.dx = FP_OFF(filename);
   segregs.ds = FP_SEG(filename);
   int86x(0x21, &inregs, &outregs, &segregs);
   if(outregs.x.cflag)		//Check Error
   printf("Error Deleting Directory");
   else
   printf("Directory deleted");
}
void copy()
{
	char file1[80], file2[80], buffer[100];
	union REGS inregs, outregs;
	struct SREGS segregs;
	int h1,h2;

	printf("\nEnter source file name: ");
	scanf("%s",file1);
	printf("\nEnter destination file name: ");
	scanf("%s",file2);

	//Open first file
	inregs.h.ah = 0x3D;  //Open
	inregs.h.al = 00;	//Read
	inregs.x.dx = FP_OFF(file1);
	segregs.ds = FP_SEG(file1);
	int86x(0x21, &inregs, &outregs, &segregs);
	if(outregs.x.cflag)
		printf("\nError");
	else
		printf("\nFile Opened Successfully");
	h1 = outregs.x.ax;

	//Open second file
	inregs.h.ah = 0x3D;  //Open
	inregs.h.al = 01;	 //Write
	inregs.x.dx = FP_OFF(file2);
	segregs.ds = FP_SEG(file2);
	int86x(0x21, &inregs, &outregs, &segregs);
	if(outregs.x.cflag)
		printf("\nError");
	else
		printf("\nFile Opened Successfully");
	h2 = outregs.x.ax;

	//Read first file
	inregs.h.ah = 0x3F;  //Read
	inregs.x.bx = h1;    //Handle from open file 1
	inregs.x.cx = 0xFF;
	inregs.x.dx = FP_OFF(buffer);
	segregs.ds = FP_SEG(buffer);
	int86x(0x21, &inregs, &outregs, &segregs);
	if(outregs.x.cflag)
		printf("\nError");
	else
		printf("\nFile Read Successfully");

	//Write to second file
	inregs.h.ah = 0x40;  //Write
	inregs.x.bx = h2;    //Handle from open file 2
	inregs.x.cx = 0xFF;
	inregs.x.dx = FP_OFF(buffer);
	segregs.ds = FP_SEG(buffer);
	int86x(0x21, &inregs, &outregs, &segregs);
	if(outregs.x.cflag)
		printf("\nError");
	else
		printf("\nFile Written Successfully");

	 //Close file1
	inregs.h.ah = 0x3E;  //
	inregs.x.bx = h2;    //Handle from open file 2
	inregs.x.dx = FP_OFF(file1);
	segregs.ds = FP_SEG(file1);
	int86x(0x21, &inregs, &outregs, &segregs);
	if(outregs.x.cflag)
		printf("\nError");
	else
		printf("\nFile Closed Successfully");

	 //Close file1
	inregs.h.ah = 0x3E;  //
	inregs.x.bx = h2;    //Handle from open file 2
	inregs.x.dx = FP_OFF(file2);
	segregs.ds = FP_SEG(file2);
	int86x(0x21, &inregs, &outregs, &segregs);
	if(outregs.x.cflag)
		printf("\nError");
	else
		printf("\nFile Closed Successfully");

}
