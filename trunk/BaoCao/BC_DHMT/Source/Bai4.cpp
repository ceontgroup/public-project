#include <stdio.h>
#include<iostream>
#include<math.h>
#include <dos.h>
#include "graphics.h"
#define RAD 0.017452
typedef float Point[2];
typedef float Affine[3][3];

int init();
int close();
int pause();
void ptoa(Point A,Affine &B);
void MatMul(Affine A,Affine B,Affine &C,int m,int n);
void Quay(Affine &T,float fi);
void Tinhtien(Affine &T,float x,float y);
void Nghieng(Affine &T,float h,float g);
void Codan(Affine &T,float Sx,float Sy);

int main()
{	
	init();
	int k[50],n=0;
	Point x={300,200},y;
	Affine Tz,Ty,Tzz,Tx,Txx,Tyy,Tu,Tuu,T;
	ptoa(x,Tx);
	//ve tam giac
	Tinhtien(T,-x[0],-x[1]);MatMul(Tx,T,Txx,1,3);
	Tinhtien(T,0,100);MatMul(Txx,T,Ty,1,3);
	Quay(T,120*RAD);MatMul(Ty,T,Tz,1,3);
	Quay(T,120*RAD);MatMul(Tz,T,Tu,1,3);
	Tinhtien(T,x[0],x[1]);
	MatMul(Txx,T,Tx,1,3);
	MatMul(Ty,T,Tyy,1,3);
	MatMul(Tz,T,Tzz,1,3);
	MatMul(Tu,T,Tuu,1,3);
	circle(int(x[0]),int(x[1]),101);
	
	//quat quay
	
	setwritemode(XOR_PUT);
	while(!kbhit()){
	
	//Tinhtien
	Tinhtien(T,-x[0],-x[1]);
	MatMul(Tyy,T,Ty,1,3);
	MatMul(Tzz,T,Tz,1,3);
	MatMul(Tuu,T,Tu,1,3);
	
	//Quay
	Quay(T,n*RAD);
	MatMul(Ty,T,Tyy,1,3);
	MatMul(Tz,T,Tzz,1,3);
	MatMul(Tu,T,Tuu,1,3);
	
	//tinhtien
	Tinhtien(T,x[0],x[1]);
	MatMul(Tyy,T,Ty,1,3);
	MatMul(Tzz,T,Tz,1,3);
	MatMul(Tuu,T,Tu,1,3);
	Tyy[0][0]=Ty[0][0];Tyy[0][1]=Ty[0][1];
	Tzz[0][0]=Tz[0][0];Tzz[0][1]=Tz[0][1];
	Tuu[0][0]=Tu[0][0];Tuu[0][1]=Tu[0][1];
	//ve tam giac
	k[0]=Ty[0][0];k[1]=Ty[0][1];
	k[2]=Tz[0][0];k[3]=Tz[0][1];
	k[4]=Tu[0][0];k[5]=Tu[0][1];
	k[6]=Ty[0][0];k[7]=Ty[0][1];
	setcolor(LIGHTRED);
	drawpoly(4,k);
	delay(50);
	drawpoly(4,k);
	n+=1;
	}
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
//----------------------------------------------

void ptoa(Point A,Affine &B){
	B[0][0]=A[0];
	B[0][1]=A[1];
	B[0][2]=1;


}
void MatMul(Affine A,Affine B,Affine &C,int m,int n){
	int i,j,k;
		for(i=0;i<m;i++)
		   for(j=0;j<n;j++){
			C[i][j]=0;
			for(k=0;k<n;k++)
			  C[i][j]+=A[i][k]*B[k][j];
		   }
}

void Quay(Affine &T,float fi){
	T[0][0]=cos(fi);
	T[0][1]=sin(fi);
	T[0][2]=0;
	T[1][0]=-sin(fi);
	T[1][1]=cos(fi);
	T[1][2]=0;
	T[2][0]=0;
	T[2][1]=0;
	T[2][2]=1;
}
void Tinhtien(Affine &T,float x,float y){
	T[0][0]=1;
	T[0][1]=0;
	T[0][2]=0;
	T[1][0]=0;
	T[1][1]=1;
	T[1][2]=0;
	T[2][0]=x;
	T[2][1]=y;
	T[2][2]=1;
}
void Nghieng(Affine &T,float h,float g){
	T[0][0]=1;
	T[0][1]=g;
	T[0][2]=0;
	T[1][0]=h;
	T[1][1]=1;
	T[1][2]=0;
	T[2][0]=0;
	T[2][1]=0;
	T[2][2]=1;
}
void Codan(Affine &T,float Sx,float Sy){
	T[0][0]=Sx;
	T[0][1]=0;
	T[0][2]=0;
	T[1][0]=0;
	T[1][1]=Sy;
	T[1][2]=0;
	T[2][0]=0;
	T[2][1]=0;
	T[2][2]=1;
}
