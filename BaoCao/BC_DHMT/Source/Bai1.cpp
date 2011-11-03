#include <stdio.h>
#include<iostream>
#include<math.h>
#include "graphics.h"

int init();
int close();
int pause();
int drawSin(int c=0);

int main()
{
	drawSin(3);
	return 0;
}

int drawSin(int c){
	int x,y;
	int donvi=100; //Do dai 1 don vi
	init();
	setcolor(4);	
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    for(int i=-180;i<=180;i++){
	    x=getmaxx()/2 + int((i*M_PI/180)*donvi);
	    y=getmaxy()/2 - int (sin(i*M_PI/180)*donvi);
		if (i==-180) moveto(x,y);
		putpixel(x,y,c);
    }
	pause();
	close();
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
