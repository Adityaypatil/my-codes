#include<stdio.h>
#include<graphics.h>

void line(int x1,int y1,int xn,int yn)
{
	int dx,dy,m,i;
	m=(yn-y1)/(xn-x1);
	for(i=x1;i<=xn;i++)
	{
		if(m<=1)
		{
			dx=1;
			dy=m*dx;
			
		}
		else
		{
			dy=1;
			dx=dy/m;
		}
		x1=x1+dx;
		y1=y1+dy;
		putpixel(x1,y1,RED);
		delay(100);
		getch();
	}
}


main()
{
	int x1,y1,xn,yn;
	int gd=DETECT,gm;
	printf("\n Enter the starting coordinate of line:");
	scanf("%d%d",&x1,&y1);
	printf("\n Enter the Ending coordinates:");
	scanf("%d%d",&xn,&yn);
	
	initgraph(&gd,&gm,"");
	line(150,150,300,300);	
}
