#include <stdio.h>
#include <conio.h>
//void nhap(int **a);
void main() {
int **aa,x,y,*a;
 x=8;y=9;
 *aa=&y;
 a=&x;
 aa=&a;
 printf("%d ",**aa);
 getch();
}