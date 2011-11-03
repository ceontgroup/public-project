#include <stdio.h>
#include<iostream>
#include<math.h>
#include "graphics.h"
#include <dos.h>
#define Rad 0.017452
#define vuong 0.7071
int init();
int close();
int pause();
void Koch(int n,float l,float d);
void C(int n,float l,float d);
void CDragon(int n,float l,float d,int s);
void L(int n,float l,float d);
int main()
{
	init();
	 setcolor(LIGHTRED);
	 // Koch
	 outtextxy(10,0,"Cong Koch: ");
	 moveto(100,0);
	 Koch(4,200,0);
	 setcolor(LIGHTBLUE);
	 // C
	 outtextxy(10,100,"Cong C: ");
	 moveto(200,100);
	 C(10,100,0);
	 setcolor(LIGHTGREEN);
	 // Dragon
	 outtextxy(10,200,"Cong Dragon: ");
	 moveto(400,200);
	 CDragon(10,100,0,1);
	 setcolor(LIGHTGRAY);
	 // Cong l
	 outtextxy(10,300,"Cong L ");
	 moveto(400,300);
	 L(4,200,0);
	pause();
	close();
	return 0;
}


//---------------------------------------------
int init(){
	int gd=0,gm=DETECT;
	initgraph(&gd,&gm,"");
	return graphresult();
	}
//----------------------------------------------
int close(){
	closegraph();
	return 1;
	}
//---------------------------------------------
int pause(){
	while (!kbhit());
	return 1;
	}
//--------------------------------------------
// Duong cong Koch
void Koch(int n,float l,float d){
	delay(10);
	if(n>0){
		Koch(n-1,l/3,d);d+=60;
		Koch(n-1,l/3,d);d-=120;
		Koch(n-1,l/3,d);d+=60;
		Koch(n-1,l/3,d);
	}
	else
	linerel(int(l*cos(d*Rad)),int(l*sin(d*Rad)));
}
// Duong cong C
void C(int n,float l,float d){
	delay(10);
	if(n>0){
		d+=45;
		C(n-1,l*vuong,d);
		d-=90;
		C(n-1,l*vuong,d);
		d+=45;
	}
	else
		linerel(int(l*cos(d*Rad)),int(l*sin(d*Rad)));
}
// Duong cong Dragon
void CDragon(int n,float l,float d,int s){
	delay(10);
	if(n>0){
		d+=45*s;
		CDragon(n-1,l*vuong,d,-1);
		d-=90*s;
		CDragon(n-1,l*vuong,d,1);
		d+=45;
	}
	else
		linerel(int(l*cos(d*Rad)),int(l*sin(d*Rad)));
}
// duong cong L
void L(int n,float l,float d){
	delay(10);
	if(n>0){
		L(n-1,l/3,d);d+=90;
		L(n-1,l/3,d);d-=90;
		L(n-1,l/3,d);d-=90;
		L(n-1,l/3,d);d+=90;
		L(n-1,l/3,d);
	}
	else linerel(int(l*cos(d*Rad)),int(l*sin(d*Rad)));

}

