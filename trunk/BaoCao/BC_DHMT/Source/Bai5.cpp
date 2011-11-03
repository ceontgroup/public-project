#include <stdio.h>
#include<iostream>
#include<math.h>
#include "graphics.h"
struct Point{
	int x;
	int y;
};

int init();
int close();
int pause();
void Bezier(int n,int *a);

int main()
{
	int i,j=0,n=3;
	int a[50];
	printf("\n Nhap so diem kiem soat= ");scanf("%d",&n);
	for(i=0;i<n*2-1;i+=2){
		printf("\n x%d= ",j);scanf("%d",&a[i]);
		printf("\n y%d= ",j);scanf("%d",&a[i+1]);
		j++;
	}
	init();
	Bezier(n,a);
	pause();
	close();
	return 0;
}

//----------------------
int init(){
	int gd=0,gm=DETECT;
	initgraph(&gd,&gm,"");
	return graphresult();
	}
//----------------------
int close(){
	closegraph();
	return 1;
	}
//----------------------
int pause(){
	while (!kbhit());
	return 1;
	}
//------------
void Bezier(int n,int *a){
	int r,i,pn=0,t;
	Point p[50][50];
	// tao gia tri diem cho p
	for(i=0;i<n*n-1;i+=2){
		p[pn][0].x=a[i];
		p[pn][0].y=a[i+1];
		putpixel(p[pn][0].x,p[pn][0].y,LIGHTCYAN);
		pn++;
	};
	// ve
	   for(t=1;t<100;t++){
	      for(r=1;r<n;r++)
		   for(i=0;i<n-r;i++) {
				p[i][r].x=(1-t/100.0)*p[i][r-1].x+(t/100.0)*p[i+1][r-1].x;
				p[i][r].y=(1-t/100.0)*p[i][r-1].y+(t/100.0)*p[i+1][r-1].y;
		   }
	       putpixel(p[0][n-1].x,p[0][n-1].y,LIGHTRED);
	   }

}
