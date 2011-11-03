//Written by kem
#include <stdio.h>
#include <conio.h>
typedef struct _string{
 char ch;
 struct _string *next;
 }string;

 string *front=NULL,*rear=NULL,*front1=NULL,*rear1=NULL;
 string *front2=NULL,*rear2=NULL;

 void nhap();//Nhap xau
 void xuat(string *front);//In ra xau
 void pusqueu(string *p);//dua 1 phan tu vao queu
 int demsotu();//dem so tu trong xau
 string *nhaptu(string *front,string *rear);//nhap 1 tu moi, bat dau tai front1 va ket thuc tai rear1
 int timkiem(string *front1,string **b,string **e);//tim kiem tu trong xau
 // b vi tri bat dau, e la vi tri ket thuc cua tu trong xau
 void thaytu(string *front2,string **b,string **e);//thay tu
 void xuatn(int n);
void main(){
 clrscr();
 int n=0;
 string *e=NULL,*b=NULL;
 nhap();
 printf("Xau vua nhap: ");
 xuat(front);
 printf("\nSo tu trong xau vua nhap: %d ",demsotu());
 printf("\nNhap tu can tim: ");
 front1=nhaptu(front1,rear1);
 if(timkiem(front1,&b,&e)) {
 printf("\nDa tim thay tu trong xau !");
  printf("\nNhap tu can thay tu: '"); xuat(front1); printf("' trong xau:");
 front2=nhaptu(front2,rear2);
 thaytu(front2,&b,&e);
 printf("\nXau sau khi thay: ");xuat(front);
 }
 else  printf("\nKhong tim thay tu vua nhap trong xau !");
 printf("\nNhap n: ");scanf("%d",&n);
 printf("\nNhung tu co do dai %d la :",n);xuatn(n);
 getch();
}

void pusqueu(string *p){
 p->next=NULL;
 if (front==NULL) front=p;
 else rear->next=p;
 rear=p;
}
void nhap(){
 char ch;
 string *p=NULL;
 printf("\nType string, end by '.' ");
 do{
 p=new string;
 scanf("%c",&ch);
 p->ch=ch;
 if (ch!='\n') pusqueu(p);
 }while ((ch!='.')&&(ch!='\n'));
}
string *nhaptu(string *front,string *rear){
 string *p=NULL;
 char ch;
 fflush(stdin);//xoa bo dem ban phim
 do{
  p=new string;
  scanf("%c",&ch);p->ch=ch;
  if ((ch!=' ')&&(ch!='\n')){
   p->next=NULL;
   if (front==NULL) front=p;
   else rear->next=p;
   rear=p;
  }
 }while((ch!=' ')&&(ch!='\n'));
 return front;
}
void xuat(string *front){
 string *p;
 p=front;
 if (p==NULL) printf("String is null !");
 else{
  while(p!=NULL) {
  printf("%c",p->ch);
  p=p->next;
  }
 }
}
int demsotu(){
 int dem=0,tu=0;
 string *p;
 p=front;
 while ((p->ch!=NULL)&&(p->ch!='.')){
  while (p->ch==' ') p=p->next;//Bo qua cac ki tu trang
  while ((('A'<=p->ch)&&(p->ch<='Z'))||((p->ch<='z')&&(p->ch>='a'))){
  p=p->next;
  tu=1;
  }
  if (tu==1) dem++;
  tu=0;
 }
 return dem;
}
int timkiem(string *front1,string **b,string **e){
 string *p,*p1;
 p=front;p1=front1;
 while ((p->ch!=NULL)&&(p->ch!='.')){
  while ((p->ch!=p1->ch)&&(p!=NULL)) {
  (*b)=p;
  p=p->next;
  }
  while ((p->ch==p1->ch)&&(p1!=NULL)&&(p!=NULL)) {
  p=p->next;
  (*e)=p;
  p1=p1->next;
  }
  if (p1==NULL) return 1;
  p1=front1;
 }
 return 0;
}
void thaytu(string *front2,string **b,string **e){
 string *p,*tem;
 tem=front2;
 printf("%c %c",(*b)->ch,(*e)->ch);
 (*b)->next=tem;
 while (tem->next!=NULL) tem=tem->next;
 tem->next=(*e);
}
void xuatn(int n){
 string *front1=NULL,*rear1=NULL,*p,*tem;
 p=front;
 int dem=0;
 while ((p!=NULL)&&(p->ch!='.')){
  while (p->ch==' ') p=p->next;
  while ((('A'<=p->ch)&&(p->ch<='Z'))||((p->ch<='z')&&(p->ch>='a'))){
   //tang bien dem len
   dem++;
   //Dua ky tu vao queu
   tem=new string;
   tem->ch=p->ch;
   tem->next=NULL;
   if (front1==NULL) front1=tem;
   else rear1->next=tem;
   rear1=tem;
  //tro den ky tu tiep theo
  p=p->next;
  }
  if (n==dem) {
  xuat(front1);
  printf(" , ");
  }
  front1=rear1=NULL;
  dem=0;
 }
}