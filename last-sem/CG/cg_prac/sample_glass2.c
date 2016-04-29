#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

GLUquadricObj *p;
	static int flag=0;
float tx=0.0,ty=0.0,tz=0.0;
float ball_x=0.0,ball_y=0.0,ball_z=0.0;

void reshaped(int w,int h){}


void init (void) {
  p = gluNewQuadric();
}

void base()
{
  double angle, angleInc;
  glPushMatrix();
  glColor3f(0,0,1);
  gluQuadricDrawStyle(p, GLU_FILL);
  gluCylinder(p, 2, 3, 6, 20, 20);
  glPopMatrix();	
  
  glPushMatrix();
  gluQuadricDrawStyle (p, GLU_FILL);
  gluDisk(p, 0, 2, 20, 20);
  glPopMatrix();
  /*glBegin(GL_LINE_LOOP);
  glColor3f(1,1,0);
  glVertex2f(0,0);
  glVertex2f(10,20);
  glEnd();
  glFlush();*/
}

void display()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  
        glClearColor(1,1,1,0);
        glPushMatrix();
        glColor3f(1,0,1);
       
        glPopMatrix();
 //       updateBall();
   		base();
        glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(720,720);
    glutCreateWindow("Cylinder");
	init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshaped);
    glutMainLoop();  
}
