#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int myatoi(char *s){
 int i=0,dau=1,gt=0;
 if (s[i]=='-') {dau=-1;i++ ;}
 while ((s[i]>='0') && (s[i]<='9') && s[i] != '\0'){
   gt=10*gt + s[i]-48;
   i++;
   }
 return (gt*dau);
}

void main(){
char ss[]="";
int a;
printf("\nNhap vao mot xau so: ");gets(ss);
a=atoi(ss);
printf("\nSo vua nhap la: %d  -- %d",a,myatoi(ss));
getch();
}