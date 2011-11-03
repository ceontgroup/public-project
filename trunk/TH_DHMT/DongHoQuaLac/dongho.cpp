
#include <conio.h>
#include <stdio.h>
#include "graphics.h"
#include <math.h>
#include <dos.h>
#include "Affine.h"
#define RAD 0.017453293

int R=100;
Point O={300,200};
void kimgio(Affine const &A);
void kimphut(Affine const &A);
void kimgiay(Affine const &A);
void dongho();
void reset(Affine &gio,Affine &phut,Affine &giay);
void qualac(Affine &vitri);
void VeSo();
int main(){
	time_t t=time(0);
	tm *now=localtime(&t);
	int giay,phut,gio;
	Affine H,M,S,H1,M1,S1,Q,lac,trai,phai;
	reset(H,M,S);
	gio=now->tm_hour;
	phut=now->tm_min;
	giay=now->tm_sec;
	//tim toa do qua lac
	lac[0][0]=300;lac[0][1]=400;lac[0][2]=1;
	QuayTamO(Q,10*RAD,300,310);
	MatMul(lac,Q,trai,1,3);
	QuayTamO(Q,-10*RAD,300,310);
	MatMul(lac,Q,phai,1,3);
	// chay
	initwindow(600,600);
	dongho();
    setwritemode(XOR_PUT);
	while(!kbhit()){
		QuayTamO(Q,(gio*30+phut/2)*RAD,O[0],O[1]);
		MatMul(H,Q,H1,1,3);
		QuayTamO(Q,(phut*6+giay/10)*RAD,O[0],O[1]);
		MatMul(M,Q,M1,1,3);
		QuayTamO(Q,6*giay*RAD,O[0],O[1]);
		MatMul(S,Q,S1,1,3);
		setcolor(LIGHTRED);kimgiay(S1);
		setcolor(LIGHTCYAN);kimphut(M1);
		setcolor(LIGHTBLUE);kimgio(H1);
		qualac(trai);
		qualac(phai); 
		setcolor(LIGHTRED);kimgiay(S1);
		setcolor(LIGHTCYAN);kimphut(M1);
		setcolor(LIGHTBLUE);kimgio(H1);
		giay++;
		if(giay>=60){giay=0;phut++;}
		if(phut>=60){phut=0;gio++;}
		if(gio>=24) gio=0;
	}
	closegraph();
	return 0;
}

void kimgio(Affine const &A){
	line(int(A[0][0]),int(A[0][1]),int(O[0]),int(O[1]));
}
void kimphut(Affine const &A){
	line(int(A[0][0]),int(A[0][1]),int(O[0]),int(O[1]));
}
void kimgiay(Affine const &A){
	line(int(A[0][0]),int(A[0][1]),int(O[0]),int(O[1]));
}
void dongho(){
    int maunen=3;
	Affine A,B,A1,B1,T;
	int i=0;
	A[0][0]=300;A[0][1]=100;A[0][2]=1;
	B[0][0]=300;B[0][1]=106;B[0][2]=1;
	setcolor(YELLOW);
	circle(300,200,5);
	setfillstyle(1,RED);
	floodfill(300,200,YELLOW);
	//ve vo dong ho
	setcolor(maunen);
	circle(300,200,R);
	rectangle(190,90,410,450);
	line(190,310,410,310);
	line(250,310,250,420);
	line(350,310,350,420);
	line(250,420,350,420);
	setfillstyle(11,maunen);
	floodfill(191,201,maunen);
	floodfill(191,320,maunen);
	// ve so gio
	VeSo();
	setcolor(LIGHTGREEN);
	while(i<360){
		QuayTamO(T,i*RAD,int(O[0]),int(O[1]));
		MatMul(A,T,A1,1,3);
		MatMul(B,T,B1,1,3);
		line(int(A1[0][0]),int(A1[0][1]),int(B1[0][0]),int(B1[0][1]));	
		i+=30;
	}
}
void VeSo(){
	setcolor(LIGHTMAGENTA);
	outtextxy(292,110,"12");
	outtextxy(297,278,"6");
	outtextxy(209,196,"9");
	outtextxy(385,196,"3");	
	outtextxy(338,117,"1");	
	outtextxy(368,150,"2");
	outtextxy(368,236,"4");		
	outtextxy(338,264,"5");		
	outtextxy(258,264,"7");			
	outtextxy(223,236,"8");		
	outtextxy(223,150,"10");
	outtextxy(254,117,"11");				
	}
void reset(Affine &gio,Affine &phut,Affine &giay){
	gio[0][0]=300;gio[0][1]=150;gio[0][2]=1;
	phut[0][0]=300;phut[0][1]=130;phut[0][2]=1;
	giay[0][0]=300;giay[0][1]=110;giay[0][2]=1;
}
void qualac(Affine &vitri){
	int maulac=6;
	setcolor(maulac);	
	line(300,310,int(vitri[0][0]),int(vitri[0][1]));
	circle(int(vitri[0][0]),int(vitri[0][1]),10);
	setfillstyle(1,maulac);
	floodfill(int(vitri[0][0])+1,int(vitri[0][1])+1,maulac);	
	delay(505);	
	line(300,310,int(vitri[0][0]),int(vitri[0][1]));
	circle(int(vitri[0][0]),int(vitri[0][1]),10);
	floodfill(int(vitri[0][0])+1,int(vitri[0][1])+1,0);		

}

