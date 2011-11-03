#include <stdio.h>
#include<iostream>
#include<math.h>
#include "graphics.h"

int init();
int close();
int pause();
int drawLine(int xa,int ya,int xb,int yb,int color=0);
int drawCircle(int x0,int y0,int R,int c=0);

int main()
{
	drawLine(0,300,23,123,3);
	drawCircle(200,200,200,4);
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
int drawCircle(int x0,int y0,int R,int c){
	int x,y,p;
	init();
	p=1-R;
	x=0;y=R;
	while(x<=y){
		putpixel(x+x0,y+y0,c);putpixel(y+x0,x+y0,c);
		putpixel(y+x0,-x+y0,c);putpixel(x+x0,-y+y0,c);
		putpixel(-x+x0,-y+y0,c);putpixel(-y+x0,-x+y0,c);
		putpixel(-y+x0,x+y0,c);putpixel(-x+x0,y+y0,c);
		if (p<0) p+=2*x+3;
		else{
			p+=2*(x-y)+5;
			y--;
			}
		x++;
		}
	pause();
	close();
	}
//----------------------------------------------
int drawLine(int xa,int ya,int xb,int yb,int c){
    int dx,dy,e,esi,eti,x,y;
	init();
    float m;
    dx=xb-xa;
    dy=yb-ya;
    m=dy/(float)dx;
        if (m>1||m<-1){
            dx=dx+dy;
            dy=dx-dy;
            dx=dx-dy;
        }
        if(m<0) dy*=-1;

    e=2*dy-dx;
    esi=2*(dy-dx);
    eti=2*dy;
    x=xa;
    y=ya;
        if(m>1||m<-1)
            while(y!=yb){
                putpixel(x,y,c);
                if (e<0) e+=eti;
                else {    e+=esi;
                    x++;
                }
                if(m>1) y++;
                else y--;
            }
        else
            while(x!=xb){
                putpixel(x,y,c);
                if (e<0) e+=eti;
                else {    e+=esi;
                    if (m>0) y++;
                    if (m<0) y--;
                }
                x++;

            }
	pause();
	close();
	return 0;
}
//-----------------------------------------
