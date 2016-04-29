#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>


void init()
{
glOrtho(-10, 10, -10, 10, -10, 10);
}

void func1()
{
	double x;
	glClearColor(.45, .29, .76, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.19, 0.27, 0.39);
	glPointSize(3);
	glBegin(GL_POINTS);
	for ( x =-5; x <= 10; x += 0.01)
	{
		glVertex2f(x, sin(2*x));
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
	init();
	glutDisplayFunc(func1);
	glutMainLoop();

	return 0;
}
