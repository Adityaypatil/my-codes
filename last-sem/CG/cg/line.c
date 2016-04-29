#include<stdio.h>
#include<graphics.h>

int main()
{
	int m,dx,dy,i;
	int gd=DETECT,gm,x1=150,y1=150,x2=300,y2=300;
	
	initgraph(&gd,&gm,"");
	
	m=(y2-y1)/(x2-x1);
	
	dy=x2-x1;
	dx=y2-y1;
	
	while(x1<x2)
		{
		if(m<=1)
			{
				
				x1+=1; 
				y1+=m;
			}
		else
			{
				
				y1+=1;
			}
	
		putpixel(x1,y1,RED);
	
		}	
		//	delay(10000);

getch();
	return 0;
}
