/*
Nhom 14 De tai 68
1. Le Sua
2. Trinh Duy Nhan
3. Truong Dinh Thuan
*/


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define max 10000

#define fin "fin.txt"
#define fout "fout.txt"

int div(char N[],int n);// N = N chia n du r
int readFile(char *N);
int writeFile(int n);
int process(char N[]);
int main()
{
    char N[max]={0}; 
	if((readFile(N))==1)
	{
		getch();
		exit(1);
	}
    int n=process(N);
    if (writeFile(n)==1)
    {
		getch();
		exit(1);
    }
	return 0;
}
int process(char N[])
{
    int len,count=0;
	while ((strlen(N)>0)&&N[0]>'0')
	{
        len=strlen(N);
        if ((N[len-1] - '0') % 2 == 1) N[len-1]= N[len-1] - 1;
        else div(N,2);
        count++;
    }   
    return count;
}
int div(char N[],int n)// N = N chia n du r
{
    int i=0,j=0,r,len=strlen(N);
    r=N[0]-'0';
    while ((i<len)&&(r<n))
    {
        i++;
        r=(10*r + N[i]-'0');
    }
    while (i<len)
    {
        N[j]=r/n + '0';
        r=r%n;
        i++;j++;
        if (i<len) r=(10*r + N[i]-'0');
    }
	N[j]='\0';
    return r;//So du
}

int readFile(char *N)
{
	FILE *f;
	char ch;
	int i=0;
	f=fopen(fin,"rt");
	if (f==NULL)
	{
		printf("File not found !");
		return 1;
	}
	else
	{
		while (!feof(f))
		{
		  ch=getc(f);
		  if (ch!=EOF)
			{
				if (!(ch=='0' && i==0)) N[i++]=ch;
			}
		  else N[i]='\0';
		}
	fclose(f);
	}
 return 0;
}
int writeFile(int n)
{
	FILE *f;
	f=fopen(fout,"w");
	if (f==NULL)
	{
		printf("Can't write file !");
		return 1;
	}
	else
	{
		fprintf(f,"So lan thuc hien it nhat: %d lan",n);
		fclose(f);
	}
	return 0;
}
