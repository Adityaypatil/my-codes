#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>



void func1()
{
	double x;
	int a=3;
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.19, 0.27, 1);
	glPointSize(3);
	glBegin(GL_POINTS);
	for ( x =-10 ; x <= 100; x += 0.01)
	{
		glVertex2f(x, sin(a));
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Sine Wave");
	glOrtho(-10, 10, -10, 10, -10, 10);
	glutDisplayFunc(func1);
	glutMainLoop();

	return 0;
}
