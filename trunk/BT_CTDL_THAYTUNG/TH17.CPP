//Th CTDL de tai 17 khoa 08
// written by kem
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct _node{
 int info;
 _node *left,*right;
} *node;
node root;
void init(node& root);//Khoi tao
void nhap();//Nhap node moi
void insert(node p,node& root);
void NLR(node root);//Duyet cay theo NLR
void LNR(node root);//Duyet cay theo LNR
void LRN(node root);
void dem(node root,int&,int&);
int tim(int x,node root);
void lonhon(int,node);//in ra cac phan tu lon hon x

void main(){
	clrscr();
	int nut=0,la=0,nhanh=0;
	init(root);
	nhap();
	printf("\nDuyet NLR: ");NLR(root);
	printf("\nDuyet LNR: ");LNR(root);
	printf("\nDuyet LRN: ");LRN(root);
	dem(root,la,nut);
//	nhanh=nut-la;
//	printf("\nNode la: %d \t Node nhanh: %d \t Tong so node: %d",la,nhanh,nut);
	int x;
	printf("\nNhap x: ");scanf("%d",&x);
	if (tim(x,root)){
	 printf("\nCac node lon hon %d la: ",x);lonhon(x,root);
	}
	else printf("\nKhong tim thay %d !",x);
	getch();
}
void lonhon(int x,node root){
	if (root!=NULL){
		if (root->info>x) printf("%4d",root->info);
		lonhon(x,root->left);
		lonhon(x,root->right);
	}
}
int tim(int x,node root){
	if (root!=NULL){
		if (root->info==x) return 1;
		if ((x>root->info)) tim(x,root->right);
		else tim(x,root->left);
	}
	else return 0;
}
void init(node& root){
	root=NULL;
}
void nhap(){
	int info;
	node p;
	do{
		p=new _node;
		printf("(Nhap 0 de ket thuc) Nhap gia tri:");
		scanf("%d",&info);
		p->info=info;
		p->left=NULL;
		p->right=NULL;
		if (info) insert(p,root);
	}while (info);
}
void insert(node p,node& root){
	if (root==NULL) root=p;
	else{
	  if(p->info>root->info) insert(p,root->right);
	  else insert(p,root->left);
	}
}
void NLR(node root){
 if (root!=NULL){
	printf("%-4d",root->info);
	NLR(root->left);
	NLR(root->right);
 }
}
void LNR(node root){
 if (root!=NULL){
	LNR(root->left);
	printf("%-4d",root->info);
	LNR(root->right);
 }
}
void LRN(node root){
 if (root!=NULL){
	LRN(root->left);
	LRN(root->right);
	printf("%-4d",root->info);

 }
}
void dem(node root,int& la,int& nut){
 if (root!=NULL){
	nut++;
	if (root->left==NULL && root->right==NULL) la++;
	dem(root->left,la,nut);
	dem(root->right,la,nut);
 }
}