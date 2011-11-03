//Danh Sach sap xep theo thu tu tang dan cua ho ten
// su dung stack
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char inf1[20];
typedef float inf2;
typedef float inf3;

typedef struct _svien { //Dinh nghia kieu du lieu hsinh
 inf1 hten;
 inf2 cnang;
 inf3 ccao;
 struct _svien *next;
}  svien;

svien *top=NULL,*p=NULL;
// Nguyen mau ham
svien *nhapsv(svien *tem);//Nhap thong tin cho danh sach sinh vien
void xuatsv(svien *tem);//Xuat thong tin 1 sinh vien
void pus(svien *tem);//Them sv vao ds theo tu tang dan cua ho ten
void pus1(svien *tem);//Them mot sv vao dau danh sach
void xuatds(svien *top);
void nhapds();//Nhap danh sach sin vien
void xoasv(inf1 hten);//Xoa sv co ten la hten
void timsv(inf1 hten);//Tim va xuat thong tin sv co ten la hten
void menu();//Hien thi menu

int main(){
 clrscr();
inf1 hten;
int choice;
while (1){
 menu();
 printf("\nMoi lua chon:");scanf("%d",&choice); fflush(stdin);
 switch (choice){
  case 0: exit(0);
  case 1:top=NULL;nhapds();break;
  case 2:clrscr();p=new svien;p=nhapsv(p);pus1(p);break;
  case 3:clrscr();xuatds(top);break;
  case 4: printf("\Nhap ho ten sv muon xem thong tin: ");gets(hten);timsv(hten);break;
  case 5:if (top!=NULL) top=top->next; else printf("\nDanh sach rong !"); break;
  case 6: printf("\nNhap ho ten sv can xoa: ");gets(hten);xoasv(hten);break;

  default: printf("Lua chon khong hop le !");getch();break;

 }
 clrscr();
};
}
svien *nhapsv(svien *tem){
 inf1 hten={0};
 inf2 ccao=0;
 printf("\nNhap thong tin cho sv:");
 printf("\nNhap ten: "); gets(hten);
 strcpy(tem->hten,hten);
 printf("Nhap chieu cao (cm):");scanf("%f",&ccao);
 fflush(stdin);//xoa bo nho dem ban phim
 tem->ccao=ccao;
 tem->cnang=ccao-105;
 return tem;
}
void xuatsv(svien *tem){
 printf("\nTen sv: ");printf("%-20s",tem->hten);
 printf("\tChieu cao %.1f (cm) \t Can nang chuan %.1f",tem->ccao,tem->cnang);
}
void pus(svien *tem){  //Them sv vao ds theo thu tu tang dan ho ten
 svien *hientai=NULL,*ketruoc=NULL;
 hientai=top;
  while ((strcmpi(tem->hten,hientai->hten)>0)&&(hientai!=NULL)){
   ketruoc=hientai;
   hientai=hientai->next;
  }
 if (hientai==top) {tem->next=top;top=tem;}
 else {
  tem->next=ketruoc->next;
  ketruoc->next=tem;
 }
}
void pus1(svien *tem){//Them 1 sv vao dau danh sach
 tem->next=top;
 top=tem;
}
void xuatds(svien *top){
 svien *tem;
 tem=top;//Cat giu top
 if (tem==NULL) printf("\nDanh sach rong !");
 else printf("\nDanh sach sv:");
 while (tem!=NULL){
  xuatsv(tem);  //xuat thong tin
  tem=tem->next;//tro den sv tiep theo
 }
 getch();
}
void nhapds(){
 int end=2;
 while (end==2){
  p=new svien;//Cap phat moi bo nho cho sv moi
  p=nhapsv(p);//Nhap thong tin cho sv p
  pus(p);
  printf("\t\t\t1. Ket thuc");
  printf("\n\t\t\t2. Nhap tiep");
  printf("\n\t\t\tChoice ? ");
  scanf("%d",&end) ;fflush(stdin);
 }
 clrscr();
}
void xoasv(inf1 hten){
 svien *hientai,*ketruoc;
 hientai=top;
 while ((hientai!=NULL)&&strcmpi(hientai->hten,hten)) {
 ketruoc=hientai;
 hientai=hientai->next;
 };
 if (hientai==NULL) printf("\nKhong tim thay sinh vien !");
 else {
 if (hientai==top) top=hientai->next;
 else ketruoc->next=hientai->next;
 printf("\nXoa thanh cong");
 getch();
 }
}
void timsv(inf1 hten){
 svien *tem;
 tem=top;
 while ((tem!=NULL)&&strcmpi(tem->hten,hten)) tem=tem->next;
 if (tem==NULL) printf("\nKhong tim thay sinh vien");
 else xuatsv(tem);
 getch();
}
void menu(){
  printf("\n1. Nhap moi mot danh sach sinh vien");
  printf("\n2. Them mot sv vao dau danh sach");
  printf("\n3. Liet ke danh sach");
  printf("\n4. Nhap ten sv can xem thong tin");
  printf("\n5. Xoa sv dau tien ra khoi danh sach");
  printf("\n6. Nhap ten sinh vien can xoa ra khoi danh sach");
  printf("\n0. Ket thuc chuong trinh");
}