//DRAW A ELLIPS USING MID POINT ALGORITHM
#include <stdio.h>
#include <graphics.h>
void ellipseMidpoint(float, float, float, float);
void drawEllipse(float, float, float, float);
void main()
{
	float xc, yc, rx, ry;
	int gd = DETECT, gm;
	printf("\nEnter the center coordinates of ellipse: ");
	scanf("%f %f", &xc, &yc);
	printf("\nEnter x-radius coordinate: ");
	scanf("%f", &rx);
	printf("\nEnter y-radius coordiante: ");
	scanf("%f", &ry);
	initgraph(&gd, &gm, "");
	ellipseMidpoint(xc, yc, rx, ry);
	getch();
}
void ellipseMidpoint(float xc, float yc, float rx, float ry)
{
	float rxSq = rx * rx;
	float rySq = ry * ry;
	float x = 0, y = ry, p;
	float px = 0, py = 2 * rxSq * y;
	drawEllipse(xc, yc, x, y);
	p = rySq - (rxSq * ry) + (0.25 * rxSq);
	while (px < py)
	{
		x++;
		px = px + 2 * rySq;
		if (p < 0)
		p = p + rySq + px;
		else
		{
		y--;
		py = py - 2 * rxSq;
		p = p + rySq + px
		- py;
		}
		drawEllipse(xc, yc, x, y);
		delay(30);
	}
	//Region 2
	p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
	while (y > 0)
	{
		y--;
		py = py - 2 * rxSq;
		if (p > 0)
		p = p + rxSq - py;
		else
		{
		x++;
		px = px + 2 * rySq;
		p = p + rxSq - py + px;
		}
		drawEllipse(xc, yc, x, y);
		delay(30);
	}
}
void drawEllipse(float xc, float yc, float x, float y)
{
	putpixel(xc+x, yc+y, RED);
	putpixel(xc-x, yc+y, RED);
	putpixel(xc+x, yc-y, RED);
	putpixel(xc-x, yc-y, RED);
}
