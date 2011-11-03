#include <iostream.h>
#include <math.h>
#include <conio.h>
void nhap(int &a){
 cout<<"\nNhap so nguyen: ";
 cin>>a;
}
void (*troham)(int &a);//Khai bao con tro ham

void main(){
int a;
clrscr();
troham=nhap;//Tro toi ham nhap
troham(a);
cout<<a;
getch();
}