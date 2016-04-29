#include<stdio.h>
#include<graphics.h>

int main(void){
		int gd=DETECT,gm;
		int x1 = 15,y1 = 10, x2 = 50, y2 = 70,dx,dy,E,NE,M;
		initgraph(&gd, &gm, NULL);
		dx = x2-x1;
		dy = y2-y1;
		M =(dy/dx);
		putpixel(x1,y1, RED);
		while(x1<=x2 || y1 <= y2)
		{
				if(M <= 1)
				{
						x1++;
						y1=(y1+M);
				}
				else
				{
						y1++;
						x1=(x1+(1/M));
				}
				putpixel(x1,y1, RED);
		}
		getch();
		closegraph();
		return 0;
}
