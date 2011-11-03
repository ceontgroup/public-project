//Thuc hanh cau truc du lieu - Khoa 08

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _pixel{//Dinh nghia kieu du lieu pixel
 int info;
 struct _pixel *next;
} pixel;

pixel *top=NULL,*topam=NULL,*topduong=NULL;
//Nguyen mau ham

void nhap();//Nhap thong tin cho danh sach pixel
void pusam(pixel *tem);//Them 1 phan tu am vao dau danh sach so am
void pusduong(pixel *tem);//Them 1 phan tu duong vao dau danh sach so duong
void tachds();//Tach danh sach thanh 2 danh sach duong va am, khong pha huy ds ban dau
int tichduong();// Tinh va tra ve tich cac so duong co trong danh sach
void sapxep();//sap xep ds
void xuatds(pixel *top);//Xuat ra danh sach
void menu(); //Hien thi menu cong viec

int main(){
 int choice;
 while (1){
  clrscr();
  menu();
  printf("\nChoice = ");scanf("%d",&choice);
 switch (choice){
  case 0: exit(0);
  case 1: top=NULL;nhap();break;
  case 2: clrscr();xuatds(top);break;
  case 3: tachds();break;
  case 4: clrscr();xuatds(topam);break;
  case 5: clrscr();xuatds(topduong);break;
  case 6: printf("\nTich cac phan tu duong: %d ",tichduong());getch();break;
  case 7: sapxep();printf("\nDanh sach sau khi sap xep:\n");xuatds(top);getch();break;
  default: printf("\nLua chon khong hop le ! vui long chon lai");getch();break;
 }
 }
}
void menu(){
  printf("\n1. Nhap moi danh sach cac pixel !");
  printf("\n2. Hien thi danh sach pixel");
  printf("\n3. Tach danh sach lien ket lam 2 ds am va ds duong");
  printf("\n4. Hien thi danh sach pixel am");
  printf("\n5. Hien thi danh sach pixel duong");
  printf("\n6. Tich cac phan tu duong");
  printf("\n7. Sap xep danh sach theo pp noi bot");
  printf("\n0. Thoat");
}
void nhap(){
 int i=0;
 pixel *p;
 printf("\nMoi nhap du lieu cho danh sach, nhap vao 0 de ket thuc !\n");
 do{
  p=new pixel;//cap phat bo nho cho pixel moi
  i++;
  printf("Pixel[%d] = ",i);scanf("%d",&p->info);
  //Dua pixel vua nhap vao danh sach pixel dang LIFO
  p->next=top;
  top=p;
 }while (p->info!=0);
}
void xuatds(pixel *top){
 pixel *tem;
 tem=top;
 if (tem==NULL) printf("\nDanh sach rong !");
 else {
  printf("\nDanh sach pixel: ");
  while (tem!=NULL){
   printf("%3d",tem->info);
   tem=tem->next;
  }
 }
 getch();
}
void tachds(){
 pixel *tem;
 tem=top;
 while (tem!=NULL){
  if ((tem->info)>0) pusduong(tem);
  else if (tem->info<0) pusam(tem);
  tem=tem->next;
  }
printf("\nTach thanh cong !");getch();
}
void pusam(pixel *tem){
 pixel *p;
 p=new pixel; //Cap phat vung nho moi cho pixel chan muon them vao
 p->info=tem->info;
 //Nap them phan tu moi
 p->next=topam;
 topam=p;
}
void pusduong(pixel *tem){
 pixel *p;
 p=new pixel; //Cap phat vung nho moi cho pixel le muon them vao
 p->info=tem->info;
 //Nap them phan tu moi
 p->next=topduong;
 topduong=p;
}
int tichduong(){
 int tich=1;
 pixel *p;
 p=top;
 if (p==NULL) {
  printf("\nDanh sach rong !");
  tich=0;
 } else while (p!=NULL){
 if (p->info>0) tich=tich*p->info;
 p=p->next;
 }
 return tich;
}
void sapxep(){
 pixel p;
 pixel *i,*j;
 for (i=top;i!=NULL;i=i->next)
  for (j=i->next;j!=NULL;j=j->next)
    if (i->info>j->info){
      p.info=i->info;
      i->info=j->info;
      j->info=p.info;
    }
}