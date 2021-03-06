#include <GL/glut.h>
#include <math.h>
char title[] = "3D Shapes";


void reshape(GLsizei width, GLsizei height) 
{
  if (height == 0) height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;

  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


void display() {
	int i;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
  glTranslatef(-0.8f,-1.3f,-6.0f);
  glColor3f(1.0f,0.0f,0.0f);
  glBegin(GL_LINES);
  glVertex3f(-2,3,0.0);
  glVertex3f(0,-2,0.0);
  glEnd();
  
  glLoadIdentity();
  glTranslatef(-0.7f,-1.3f,-6.0f);
  glColor3f(1.0f,0.0f,0.0f);
  glBegin(GL_LINES);
  glVertex3f(2,3,0.0);
  glVertex3f(0,-2,0.0);
  glEnd();

  
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow(title);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
//  initGL();
  glutMainLoop();
  return 0;
}
