#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include<math.h>

GLUquadricObj *p;
float width = 700;
float height = 600;

void base()
{
  double angle, angleInc;
  gluQuadricDrawStyle(p, GLU_FILL);
  gluCylinder (p,2, 2,6, 20, 20);

  gluQuadricDrawStyle (p, GLU_FILL);
  gluDisk (p, 0, 2, 20, 20);
  glFlush();
}

void display(void) 
{
  glClear(GL_COLOR_BUFFER_BIT );
 // glLoadIdentity();
  base();
 // glutSwapBuffers();
}

void init (void) {
  p = gluNewQuadric();
}

void reshape(int w, int h) {
  //glViewport(1, 1, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //gluPerspective(100.0, (GLfloat) w / (GLfloat) h, 0.5, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB );
  glutInitWindowSize(500, 400);
  glutCreateWindow("GLASS");
  glutInitWindowPosition(100,100);
  init();
  glutReshapeFunc(reshape);
  glClearColor(1.0,1.0,0.0,0.0);
  gluOrtho2D(0.0,500.0,0.0,400.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
 
}

