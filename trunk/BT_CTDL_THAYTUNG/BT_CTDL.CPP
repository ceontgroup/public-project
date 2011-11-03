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
}  svien;

typedef svien list[MAX];

list p;
// Nguyen mau ham
int nhap();//Nhap thong tin cho danh sach sinh vien
svien nhapsv();//Nhap thong tin cho 1 sien vien
void xuat(int);//Xuat danh sach sinh vien ra man hinh
int them(svien,int,int);//Them mot sv vao ds
int timkiem(inf1,int);//Tim 1 nguoi tra ve vi tri trong ds
int xoa(int,int); //Xoa mot sv ra ds
void menu();//hien thi menu

int main(){
clrscr();
svien temp;
inf1 hten;
 int n=0,choice,vitri;//n la so luong sinh vien
while (1){
 clrscr();
 menu();
 printf("\nMoi lua chon:");scanf("%d",&choice); fflush(stdin);
 switch (choice){
  case 0: exit(0);
  case 1:n=nhap();break;
  case 2:clrscr();xuat(n);break;
  case 3:strcpy(temp.hten,"Le Them");
	 temp.ccao=155;temp.cnang=temp.ccao-105;
	 n=them(temp,2,n);break;
  case 4:temp=nhapsv();
	 printf("\nVi tri muon them:");scanf("%d",&vitri);
	 n=them(temp,vitri,n);break;
  case 5:timkiem("Le Tim",n); break;
  case 6:printf("\nNhap ten sv: ");gets(hten);timkiem(hten,n);break;
  case 7:n=xoa(2,n);break;
  case 8:printf("\nNhap vi tri can xoa: ");scanf("%d",&vitri);fflush(stdin);
	 n=xoa(vitri,n);break;
  case 9:if((vitri=timkiem("Le Xoa",n))!=0) n=xoa(vitri,n);break;
  case 10: printf("\nNhap ten: ");gets(hten);
  if ((vitri=timkiem(hten,n))!=0) n=xoa(vitri,n); break;
  default: printf("Lua chon khong hop le !");getch();break;

 }

};


}
int nhap(){
 inf1 hten;
 int i=0;
 inf3 ccao;
 do{
 printf("\nNhap ten sv thu %d (nhap 'end' de ket thuc) :",i+1); gets(hten);
 if (strcmpi(hten,"end")&&(i<MAX)) {
   strcpy(p[i].hten,hten);
   printf("\nNhap thong tin cho sv %s:",p[i].hten);
   printf("\nChieu cao (cm): ");scanf("%f",&ccao);fflush(stdin);
   p[i].ccao=ccao;
   p[i].cnang= ccao - 105;
   i++;
  }
  if (i==MAX) printf("FULL");
 } while (strcmpi(hten,"end")&&(i<MAX));
 return i;
}
svien nhapsv(){
 svien temp;
 inf2 ccao;
 inf1 hten;
 printf("\nHo ten: ");gets(hten);
 strcpy(temp.hten,hten);
 printf("\nChieu cao: (cm) ");scanf("%f",&ccao);fflush(stdin);
 temp.ccao=ccao;
 temp.cnang=ccao-105;
 return temp;
}
void xuat(int n){
 int i;
 if (n==0) printf("\nDanh sach Rong !");
  for (i=0;i<n;i++){
  printf("\n%d,Sv:%-20s",i+1,p[i].hten);
  printf("\tcc: %4.1f (cm) \tcn: %4.1f (kg) ",p[i].ccao,p[i].cnang);
 }
getch();
}
int them(svien temp, int vitri,int n){
 int i;
 if (vitri<1||vitri>n+1) printf("\nVi tri khong hop le !");
 else if (n>=100) printf("\nDanh sach het cho trong !");
 else{
  n++;
  for (i=n-1;i>=vitri;i--) p[i]=p[i-1];
  p[i]=temp;
 printf("\nThanh cong !");
 }
 getch();
 return n;
}
int timkiem(inf1 hten,int n){
 int i=0;
  while (strcmpi(p[i].hten,hten)) i++;
  if (i>=n) printf("\nKhong tim thay %s trong danh sach !",hten);
  else{
   printf("\nThong tin sv %s :",hten);
   printf("\nCcao: %4.1f \t Cnang: %4.1f \t Vi tri: %3d",p[i].ccao,p[i].cnang,i+1);
  }
 getch();
 if (i<100) return i+1;
 else return 0;
}
int xoa(int vitri,int n){
 int i;
 if (vitri<1||vitri>n) printf("\nVi tri khong thich hop");
 else {
 for(i=vitri-1;i<n;i++) p[i]=p[i+1];
 n--;
 printf("\nThanh Cong ");
 }
 getch();
return n;
}
void menu(){
 printf("\n1. Nhap moi mot danh sach sinh vien");
  printf("\n2. Liet ke danh sach");
   printf("\n3. Them 'Le Them' ccao 155 vao vi tri thu 2 danh sach");
    printf("\n4. Them mot sv vao danh sach");
     printf("\n5. Tim kiem sv 'Le Tim' trong danh sach");
      printf("\n6. Xem thong tin mot sv");
       printf("\n7. Xoa sv thu 2 ra khoi danh sach");
	printf("\n8. Xoa sv co vi tri x ra khoi danh sach");
	 printf("\n9. Xoa sv 'Le Xoa' trong ds neu co");
	 printf("\n10. Xoa mot sv ra khoi danh sach");
	 printf("\n0. Ket thuc chuong trinh");
}