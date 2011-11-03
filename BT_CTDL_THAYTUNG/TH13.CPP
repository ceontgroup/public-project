//Thuc hanh CTDL de 13
//Written by kem
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char  MSV[12];//102121081138
typedef char HTEN[20];
typedef float DIEM;

struct svien{
 MSV msv;
 HTEN hten;
 DIEM toan,ly,hoa;
 svien *next;
};
typedef svien *list;

list front,rear;
void init();//Khoi tao
void nhapds();//Nhap ds
void insert(list& p); //Chen 1 phan tu vao ds FIFO
void xuatds();
void xuatsv(list p);
DIEM diemtb(list p);//Tinh diem trung binh
void timsv(MSV msv);
void lietke(DIEM dtb);//liet ke sv co DTB >=dtb
void xoasv(HTEN hten);
void suasv(HTEN hten);
void themsv();
void menu();

void main(){
	MSV msv;
	HTEN hten;
	clrscr();
	init();
	int choice;
	while (1){
	 menu();
	 printf("\nMoi lua chon:");scanf("%d",&choice); fflush(stdin);
	 switch (choice){
	  case 0: exit(0);
	  case 1:clrscr();init();nhapds();break;
	  case 2:clrscr();xuatds();break;
	  case 3:clrscr();lietke(7);;break;
	  case 4:clrscr();printf("\nNhap msv:");gets(msv);timsv(msv);break;
	  case 5:clrscr();printf("\nNhap ten sv can xoa:");gets(hten);	xoasv(hten);break;
	  case 6:clrscr();printf("\nNhap ten sv can sua:");gets(hten);	suasv(hten);break;
	  case 7: themsv();break;
	  default: printf("Lua chon khong hop le !");getch();break;
	 }
  clrscr();
 }
}
void menu(){
  printf("\n1. Nhap moi mot danh sach sinh vien");
  printf("\n2. Liet ke danh sach");
  printf("\n3. Liet ke danh sach sv co DTB>=7");
  printf("\n4. Nhap msv can xem thong tin");
  printf("\n5. Xoa 1 sv ra khoi danh sach");
  printf("\n6. Sua thong tin sv vao danh sach");
  printf("\n7. Them 1 sv vao danh sach");
  printf("\n0. Ket thuc chuong trinh");
}
void themsv(){
	HTEN hten;
	MSV msv;
	DIEM toan,ly,hoa;
	list p;
	printf("\nMoi nhap thong tin sv can them");
		p=new svien;
		printf("\nHo ten: ");
		gets(hten);
			strcpy(p->hten,hten);
			printf("\nNhap thong tin cho sv %s ",hten);
			printf("\nNhap ma sinh vien: ");gets(msv);
			strcpy(p->msv,msv);
			printf("Diem toan: ");scanf("%f",&toan);fflush(stdin);
			printf("Diem ly: ");scanf("%f",&ly);fflush(stdin);
			printf("Diem hoa: ");scanf("%f",&hoa);fflush(stdin);
			p->toan=toan;p->ly=ly;p->hoa=hoa;
			p->next=NULL;
			insert(p);
 printf("\nDa them !");
 getch();
 }
void suasv(HTEN hten){
 list p;
 MSV msv;
 DIEM toan,ly,hoa;
 p=front;
 while ((p!=NULL)&&strcmpi(p->hten,hten)) p=p->next;
 if (p==NULL) printf("\nKhong tim thay !");
 else{
			printf("\nNhap thong tin cho sv %s ",hten);
			printf("\nNhap ma sinh vien: ");gets(msv);
			strcpy(p->msv,msv);
			printf("Diem toan: ");scanf("%f",&toan);fflush(stdin);
			printf("Diem ly: ");scanf("%f",&ly);fflush(stdin);
			printf("Diem hoa: ");scanf("%f",&hoa);fflush(stdin);
			p->toan=toan;p->ly=ly;p->hoa=hoa;
	  puts("\nSua thanh cong !");
	}
  getch();
}

void xoasv(HTEN hten){
 list tr,s;
 s=front;
 while ((s!=NULL)&&strcmpi(s->hten,hten)){
	tr=s;
	s=s->next;
 };
 if (s==NULL) printf("\nKhong tim thay !");
 else{
	if (s==front) front=front->next;
	else {
		tr->next=s->next;
		delete s;
	}
  puts("\nXoa thanh cong !");
 }
 getch();
}

void lietke(DIEM dtb){
 list tem;
 int i=1;
 tem=front;
 if (tem==NULL) printf("DS RONG !");
 else{
	printf("\nDS SV co diem TB>= %2.1f ",dtb);
	while (tem!=NULL){
	 if (diemtb(tem)>=dtb){
		printf("\n%d.",i);
		xuatsv(tem);
	}
	tem=tem->next;
  }
 }
 getch();
}
void timsv(MSV msv){
 list tem;
 tem=front;
 while ((tem!=NULL)&&strcmpi(tem->msv,msv)) tem=tem->next;
 if (tem!=NULL) xuatsv(tem);
 else printf("\nKhong tim thay !");
 getch();
}
void xuatsv(list tem){
	printf("\n>SV: %-20s MSV: %-12s",tem->hten,tem->msv);
	printf("\nDiem toan: %2.1f   Diem ly: %2.1f   Diem hoa %2.1f",tem->toan,tem->ly,tem->hoa);
	printf("\tDTB: %2.1f",diemtb(tem));
}
DIEM diemtb(list p){
 return (3*p->toan+2*p->ly+p->hoa)/6;
}
void xuatds(){
 list tem;
 int i=1;
 tem=front;
 if (tem!=NULL) printf("\nDS SINH VIEN:");
 else printf("\nDS RONG !");
 while (tem!=NULL){
	printf("\n%d.",i++);
	xuatsv(tem);
	tem=tem->next;
 }
 getch();
}
void insert(list& p){
	if (front==NULL) front=p;
	else rear->next=p;
	rear=p;
}
void nhapds(){
	HTEN hten;
	MSV msv;
	DIEM toan,ly,hoa;
	list p;
	printf("\nMoi nhap danh sach svien !");
	do{
		p=new svien;
		printf("\n(Nhap rong de ket thuc)Ho ten: ");
		gets(hten);
		if (hten[0]!=0){
			strcpy(p->hten,hten);
			printf("\nNhap thong tin cho sv %s ",hten);
			printf("\nNhap ma sinh vien: ");gets(msv);
			strcpy(p->msv,msv);
			printf("Diem toan: ");scanf("%f",&toan);fflush(stdin);
			printf("Diem ly: ");scanf("%f",&ly);fflush(stdin);
			printf("Diem hoa: ");scanf("%f",&hoa);fflush(stdin);
			p->toan=toan;p->ly=ly;p->hoa=hoa;
			p->next=NULL;
			insert(p);
		}
	}while (hten[0]!=0);
}
void init(){
	front=NULL;
	rear=NULL;
}