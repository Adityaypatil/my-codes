#include<GL/glut.h>

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_TRINGLES);	
	glColor3f(221.0f, 122.0f, 111.0f);
	
      glVertex2f(0.0f, 1.0f);
      glVertex2f(-0.5f, 0.0f);
      glVertex2f(0.5f, 0.0f);
      glEnd();
     
 }


int main(int argc,char *argv[])
{
   glutInit(&argc, argv);                 
   glutCreateWindow("OpenGL Setup Test"); 
   glutInitWindowSize(500, 500);   
   glutInitWindowPosition(500, 500)

glutDisplayFunc(display);

}
