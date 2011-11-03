//Th CTDL de tai 17 + 18 + 19 + 20 khoa 08
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
int max(int a,int b);//Tim max 2 so
int chieucao(node root); //Tinh chieu cao = de quy
int sumnode(node root);//tong gia tri cac nut tren cay
void nodebac1(node root,int&);
int tim2(int x,node root);//Tim va dem so lan xuat hien cua x
void xuatdocao(node root,int h1,int h);//Xuat cac node co cung do cao
void main(){
	clrscr();
	int x;
	init(root);
	nhap();
	printf("\nDuyet NLR: ");NLR(root);
	printf("\nDuyet LNR: ");LNR(root);
	printf("\nDuyet LRN: ");LRN(root);
	int nut=0,la=0,nhanh=0;
	dem(root,la,nut);
	nhanh=nut-la;
	printf("\nNode la: %d \t Node nhanh: %d \t Tong so node: %d",la,nhanh,nut);
	printf("\nNhap x: ");scanf("%d",&x);
	if (tim(x,root)){
	 printf("\nCac node lon hon %d la: ",x);lonhon(x,root);
	}
	else printf("\nKhong tim thay %d !",x);
	printf("\nChieu cao: %d",chieucao(root));
	printf("\nTong gia tri cac nut tren cay: %d ",sumnode(root));

	int bac1=0;
	nodebac1(root,bac1);
	printf("\nSo luong nut bac 1: %d ",bac1);
	printf("Nhap x: ");scanf("%d",&x);
	printf("So lan xuat hien cua %d : %d",x,tim2(x,root));
	int h;
	printf("\nNhap do cao: ");scanf("%d",&h);
	printf("\nNhung nut co do cao la %d :",h);
	xuatdocao(root,0,h);
	getch();
}
void xuatdocao(node root,int h1,int h){
	if (root!=NULL){
		if (h1+1==h) printf("%4d",root->info);
		xuatdocao(root->left,h1+1,h);
		xuatdocao(root->right,h1+1,h);
	}
}
int tim2(int x,node root){
	if (root==NULL) return 0;
	else{
		if (root->info==x)
		return (tim2(x,root->left)+tim2(x,root->right)+1);
		else
			return (tim2(x,root->left)+tim2(x,root->right));
	}
}
void nodebac1(node root,int& bac1){
  if (root!=NULL){
	 if ((root->right!=NULL && root->left==NULL)||(root->left!=NULL && root->right==NULL))
		bac1++;
		nodebac1(root->right,bac1);
		nodebac1(root->left,bac1);
  }
}
int sumnode(node root){
 if (root==NULL) return 0;
 else return (root->info + sumnode(root->left) + sumnode(root->right));
}
int chieucao(node root){
	if (root==NULL) return 0;
	else return max(chieucao(root->left),chieucao(root->right))+1;
}
int max(int a,int b){
	return (a>b ? a:b);
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