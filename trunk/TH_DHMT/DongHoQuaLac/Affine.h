#include<math.h>

typedef float Point[2];
typedef float Affine[3][3];

void Change(Point A,Affine &B){
	B[0][0]=A[0];
	B[0][1]=A[1];
	B[0][2]=1;
}
void Cover(Affine &A,Affine B){
	A[0][0]=B[0][0];
	A[0][1]=B[0][1];
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
	T[0][2]=0.0;
	T[1][0]=-sin(fi);
	T[1][1]=cos(fi);
	T[1][2]=0.0;
	T[2][0]=0.0;
	T[2][1]=0.0;
	T[2][2]=1.0;
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

void Tich(Affine A,Affine B,Affine &C){
	Affine Tr1,Tr;
	Tr1[0][0]=A[2][0];Tr1[0][1]=A[2][1];Tr1[0][2]=1;
	MatMul(A,B,C,2,2);
	MatMul(Tr1,B,Tr,1,2);
	C[2][0]=Tr[0][0]+B[2][0];C[2][1]=Tr[0][1]+B[2][1];
}

void QuayTamO(Affine &T,float fi,float x,float y){
	Affine T1,T2,Q,tam;
	tam[0][2]=0;
	Tinhtien(T1,-x,-y);
	Tinhtien(T2,x,y);
	Quay(Q,fi);
	Tich(T1,Q,tam);
	Tich(tam,T2,T);
}
