//Thuc hanh cau truc du lieu - Khoa 08
//Nhom 4 - De tai so 4

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _pixel{//Dinh nghia kieu du lieu pixel
 int info;
 _pixel *next;
} pixel;

pixel *top=NULL,*tople=NULL,*topchan=NULL,*p=NULL;
//Nguyen mau ham

int isngto(int a);//Kiem tra mot so co phai so nguyen to khong
void nhap();//Nhap thong tin cho danh sach pixel
void puschan(pixel *tem);//Them 1 phan tu chan vao dau danh sach so chan
void pusle(pixel *tem);//Them 1 phan tu le vao dau danh sach so le
void tachds();//Tach danh sach thanh 2 danh sach chan va le, khong pha huy ds ban dau
int tongam();// Tinh va tra ve tong cac so am co trong danh sach
int demngto();//Dem cac so ngto co trong ds
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
  case 4: clrscr();xuatds(topchan);break;
  case 5: clrscr();xuatds(tople);break;
  case 6: printf("\nSo luong so ngto trong danh sach: %d ",demngto());getch();break;
  case 7: printf("\nTong cac pixel am: %d",tongam());getch();break;
  default: printf("\nLua chon khong hop le ! vui long chon lai");getch();break;
 }
 }
}
void menu(){
  printf("\n1. Nhap moi danh sach cac pixel !");
  printf("\n2. Hien thi danh sach pixel");
  printf("\n3. Tach danh sach lien ket lam 2 ds chan va ds le");
  printf("\n4. Hien thi danh sach pixel chan");
  printf("\n5. Hien thi danh sach pixel le");
  printf("\n6. Dem cac so nguyen to trong danh sach pixel");
  printf("\n7. Tinh tong cac so am co trong danh sach pixel");
  printf("\n0. Thoat");
}
void nhap(){
 int i=0;
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
  if ((tem->info)%2) pusle(tem);
  else puschan(tem);
  tem=tem->next;
  }
printf("\nTach thanh cong !");getch();
}
void puschan(pixel *tem){
 p=new pixel; //Cap phat vung nho moi cho pixel chan muon them vao
 p->info=tem->info;
 //Nap them phan tu moi
 p->next=topchan;
 topchan=p;
}
void pusle(pixel *tem){
 p=new pixel; //Cap phat vung nho moi cho pixel le muon them vao
 p->info=tem->info;
 //Nap them phan tu moi
 p->next=tople;
 tople=p;
}
int isngto(int a){
 int i=2;
 if (a<=1) return 0;
 while ((i<=sqrt(a))&&(a%i)) i++;
 if (i>sqrt(a)) return 1;
 else return 0;
}
int demngto(){
 int dem=0;
 pixel *tem;
 tem=top;
 while (tem!=NULL) {
  if (isngto(tem->info)) dem++;
  tem=tem->next;
 }
 return dem;
}
int tongam(){
 int tong=0;
 pixel *tem;
 tem=top;
 while (tem!=NULL) {
  if ((tem->info)<0) tong+=tem->info;
  tem=tem->next;
 }
 return tong;
}