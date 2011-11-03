#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define filein "datain.txt"
#define fileout "dataout.txt"

int downHeap(int *a,int start,int n);
int makeHeap(int *a,int n);
int heapSort(int *a,int n);
int readFile(int *a,int &n);
int writeFile(int *a,int n);

int main()
{
	int n=0,a[100];
	system("cls");
	if (readFile(a,n)==1)
	{
		getch();
		exit(1);
	}
	heapSort(a,n);
	if (writeFile(a,n)==1)
	{
		getch();
		exit(1);
	}
    getch();
	return 0;
}

int writeFile(int *a, int n)
{
	FILE *f;
	f=fopen(fileout,"wt");
	if (f==NULL)
	{
		printf("Can't create file !");
		return 1;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			fprintf(f,"%4d",a[i]);
		}
		fclose(f);
	}
	return 0;
}
int readFile(int *a,int &n)
{
	FILE *f;
	f=fopen(filein,"rt");
	if (f==NULL)
	{
		printf("File not found !");
		return 1;
	}
	else
	{
		fscanf(f,"%d",&n);
		for (int i=1;i<=n;i++)
		{
			fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
	return 0;
}
int heapSort(int a[],int n)
{  int end=n,tem;
	makeHeap(a,n);
	while (end>0)
	{
		tem=a[end];a[end]=a[1];a[1]=tem;
		end--;
		downHeap(a,1,end);
	}
	return 0;
}
int makeHeap(int a[],int n)
{
	int start=(n)/2;
	while (start>0)
	{
		downHeap(a,start,n);
		start--;
	}
 return 0;
}
int downHeap(int a[],int start,int n)
{
	int i=start,j,tem;
	while (2*i <= n)
	{
		j=2*i;
		if ((j+1<= n)&&(a[j]<a[j+1]))
		j++;
		if (a[i]<a[j])
		{
			tem=a[i];a[i]=a[j];a[j]=tem;
			//i=j;
		}
		else return 0;
	}
  return 0;
}

