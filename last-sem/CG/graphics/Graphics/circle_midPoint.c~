//DRAW A CIRCLE USING MID POINT ALGORITHM
#include<stdio.h>
#include<graphics.h>
//#include<dos.h>

void cir(int ,int ,int );
void draw(int ,int ,int ,int );


main()
{
	int xc,yc,r;
	
	int gd = DETECT,gm;
	
	
	printf("\n Enter the coordinate of cicle:");
	scanf("%d%d",&xc,&yc);
	printf("\n Enter the radius:");	
	scanf("%d",&r);
	initgraph(&gd,&gm,"");
	
	cir(xc,yc,r);
	getch();
}


void cir(int xc,int yc,int r)
{
	int x=0,y=r;
	int p=1-r;
	
	while(x<y)
	{
		draw(xc,yc,x,y);
		x++;
		
		if(p<0)
			p=p+2*x+1;
		else
			{
				y--;
				p=p+2*(x-y)+1;
			}
			draw(xc,yc,x,y);
			delay(1);
	}
}


void draw(int xc,int yc,int x,int y)
{
	putpixel(xc+x,yc+y,RED);
	putpixel(xc-x,yc+y,RED);
	putpixel(xc+x,yc-y,RED);
	putpixel(xc-x,yc-y,RED);
	putpixel(xc+y,yc+x,RED);
	putpixel(xc-y,yc+x,RED);
	putpixel(xc+y,yc-x,RED);
	putpixel(xc-y,yc-x,RED);
}
