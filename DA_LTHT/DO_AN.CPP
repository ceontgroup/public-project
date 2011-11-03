/*
Ma loi:
1: Loi ve doc ghi file
2: Loi ve dia
*/

#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>

#define filename "bootsect.bkp"
//Ten file luu tru
union REGS v,r; //Gia thanh ghi 16bit va 8bit
struct SREGS s;// Gia thanh ghi doan
typedef struct _sector
{
 int head,cylinder,sector;
} sector;

sector bootsector={0,0,1};

/*Khai bao bootsector
Dia chi bootsector head=0;cylinder=0;sector=1;
*/

int taotep(char *filename);//Tao tep
int motep(char *filename, unsigned mode); // (mode 0=Read, 1=Write 2= Read/Write)
int dongtep(int sh_tep);//Dong tep co so hieu la sh_tep
int ghitep(int sh_tep, char *buffer);//Ghi Sector vua doc ra file
int docsect(int sh_dia,sector bootsector,char *buffer);//Doc 1 sector dia
void trangthai(int sh_dia);//Lay trang thai cua dia
void error(int e);//In ma loi

int main()
{
 clrscr();
 char buffer[512];//Khai bao bo nho dem
 int sh_tep,sh_dia=0;
 printf("\nNhap so hieu dia: (0=A,1=B,128=HDD1)");scanf("%d",&sh_dia);fflush(stdin);
 sh_tep=taotep(filename);
 dongtep(sh_tep);
 docsect(sh_dia,bootsector,buffer);
 sh_tep=motep(filename,1);
 ghitep(sh_tep,buffer);
 dongtep(sh_tep);
 return 0;
}
//----------------------------------------------------//
int taotep(char *filename){
 // Ngat 21h chuc nang 3Ch
 unsigned off,seg;
 off=FP_OFF(filename); //Lay dia chi offset cua filename
 seg=FP_SEG(filename);//Lay dia chi segment cua filename
 v.h.ah=0x3c;//Nap so hieu chuc nang vao ah
 v.x.cx=0; //Tep binh thuong
 v.x.dx=off;//Gan dia chi offet vao dx
 s.ds=seg;//Gan dia chi segment vao ds
 intdosx(&v,&r,&s); //Goi ngat
 if (r.x.cflag==0) return r.x.ax; //Tra lai so hieu tep vua tao ra
 else {
 printf("\nTao tep khong thanh cong !");
 getch();
 exit(1);
 return 0;
 }
}
//----------------------------------------------------//
int motep(char *filename,unsigned mode){
 unsigned off,seg;
 off=FP_OFF(filename);seg=FP_SEG(filename);//lay dia chi cua filename
 v.h.ah=0x3d; //Nap so hieu chuc nang vao ah
 v.h.al=mode;//mode 0: chi doc, mode 1: chi ghi, mode 2: doc va ghi
 v.x.dx=off; //Gan dia chi offset
 s.ds=seg;  //gan dia chi segment
 intdosx(&v,&r,&s);      //Goi ngat
 if (r.x.cflag==2) {
  printf("\nKhong tim thay tep de mo !");getch();exit(1);return 0;
 }
 else return r.x.ax; //tra lai so hieu tep vua mo
}
//----------------------------------------------------//
int dongtep(int sh_tep){
 //Dong tep co so hieu la sh_tep dang mo
 v.h.ah=0x3e;
 v.x.bx=sh_tep;//Nap so hieu can dong vao bx
 intdos(&v,&r);
 return sh_tep;
}
//----------------------------------------------------//
int ghitep(int sh_tep,char *buffer){
 unsigned off,seg;
 off=FP_OFF(buffer);seg=FP_SEG(buffer);
 v.h.ah=0x40;
 v.x.bx=sh_tep;
 v.x.cx=512;
 v.x.dx=off;
 s.ds=seg;
 intdosx(&v,&r,&s);
 if (r.x.cflag==0) return 0;
 else {
  printf("\nCo loi trong qua trinh ghi len file !");
  getch();exit(1);return 1;
 }
}
//----------------------------------------------------//
void trangthai(int sh_dia){
 v.h.ah=1;
 v.x.dx=sh_dia;
 int86(0x13,&v,&r);
 if (r.h.ah!=0) {
  error(r.h.ah);
  getch();
  exit(2);
 }
}
//----------------------------------------------------//
int docsect(int sh_dia,sector bootsector,char *buffer){
  v.h.ah=0x02;
  v.h.dl=sh_dia;
  v.h.dh=bootsector.head ;
  v.h.ch=bootsector.cylinder;
  v.h.cl=bootsector.sector;
  v.h.al=1;
  s.es=FP_SEG(buffer);
  v.x.bx=FP_OFF(buffer);
  int86x(0x13,&v,&r,&s);
 if(r.x.cflag==0) {error(r.h.ah);getch();return 0;}
 else{
  error(r.h.ah);
  getch();
  exit(2);
  return 0;
 }
}
void error(int e)
{
switch (e)
{
 case 0x00:printf("\nSuccessful completion");break;
 case 0x01:printf("\nInvalid function in AH or invalid parameter");break;
 case 0x02:printf("\nAddress mark not found");break;
 case 0x03:printf("\nDisk write-protected"); break;
 case 0x04:printf("\nSector not found/read error");break;
 case 0xe1:printf("\nSeset failed (hard disk)");break;
 case 0x05:printf("\nData did not verify correctly (TI Professional PC)");break;
 case 0x06:printf("\nDisk changed (floppy)");break;
 case 0x07:printf("\nDrive parameter activity failed (hard disk)");break;
 case 0x08:printf("\nDMA overrun");break;
 case 0x09:printf("\nData boundary error (attempted DMA across 64K boundary or >80h sectors)");break;
 case 0x0A:printf("\nBad sector detected (hard disk)");     break;
 case 0x0B:printf("\nBad track detected (hard disk)");      break;
 case 0x0C:printf("\nUnsupported track or invalid media");   break;
 case 0x0D:printf("\nInvalid number of sectors on format (PS/2 hard disk)");break;
 case 0x0E:printf("\nControl data address mark detected (hard disk)");break;
 case 0x0F:printf("\nDMA arbitration level out of range (hard disk)");break;
 case 0x10:printf("\nUncorrectable CRC or ECC error on read");      break;
 case 0x11:printf("\nData ECC corrected (hard disk)");              break;
 case 0x20:printf("\nController failure");                          break;
 case 0x31:printf("\nNo media in drive (IBM/MS INT 13 extensions)");break;
 case 0x32:printf("\nIncorrect drive type stored in CMOS (Compaq)");break;
 case 0x40:printf("\nSeek failed");                   break;
 case 0x80:printf("\nTimeout (not ready)");           break;
 case 0xAA:printf("\nDrive not ready (hard disk)");   break;
 case 0xB0:printf("\nVolume not locked in drive (INT 13 extensions)");break;
 case 0xB1:printf("\nVolume locked in drive (INT 13 extensions)");    break;
 case 0xB2:printf("\nVolume not removable (INT 13 extensions)");      break;
 case 0xB3:printf("\nVolume in use (INT 13 extensions)");             break;
 case 0xB4:printf("\nLock count exceeded (INT 13 extensions)");       break;
 case 0xB5:printf("\nValid eject request failed (INT 13 extensions)");break;
 case 0xBB:printf("\nUndefined error (hard disk)");     break;
 case 0xCC:printf("\nWrite fault (hard disk)");         break;
 case 0xE0:printf("\nStatus register error (hard disk)");break;
 case 0xFF:printf("\nSense operation failed (hard disk)");break;
 }
}
