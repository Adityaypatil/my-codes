#include<graphics.h>

int main()
{
	int gd=DETECT;
	int gm;
	initgraph(&gd,&gm,"");
	
	arc(200,200,0,360,50);//fst two arg is pos of arc,0 degree is starts from right hand side,angle,radius

	getch();
	return 0;
}
