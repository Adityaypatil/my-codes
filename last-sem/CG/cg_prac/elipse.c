#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


const float DEG2RAD = 3.14159/180.0;
 
void drawEllipse(float xradius, float yradius);
 
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
 
	drawEllipse(5.0, 5.0);
 
	glFlush();
}
 
void drawEllipse(float xradius, float yradius)
{
	glBegin(GL_LINE_LOOP);
 int i;
	for(i=0; i < 360; i++)
	{
		 //convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*xradius,sin(degInRad)*yradius);
	} 
	glEnd();
}
 
void setupEnv(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 400.0, 0.0, 400.0, 1.0, -1.0);
 	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
}
 
void main(int argc,char **argv)
{
   	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("GL01");
	glutInitWindowSize(400, 400);
	glutDisplayFunc(display);
 	setupEnv();
 	glutMainLoop();
}
