 #include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include<math.h>

#define alpha 0.0
#define pi 3.14159265

GLfloat anglex=0;
GLfloat angley=0;
GLfloat anglez=0;
GLUquadricObj *p;
GLfloat ambient[3];
GLfloat diffuse[3];
GLfloat specular[3];
GLfloat shiness[] = {50.0f};
float width = 700;
float height = 600;

void base(void);
void init(void);
void display(void);
void reshape (int width, int height);
void keyboard(unsigned char, int, int);
void processSpecialKeys(int, int, int);
void init1 (void);

void base (void) {
double angle, angleInc;
int i;
angle = pi / 180;
angleInc = angle;
glPushMatrix();
glRotatef (-90.0, 1.0, 0.0, 0.0);
gluQuadricDrawStyle(p, GLU_FILL);
gluCylinder (p,2, 3,6, 20, 20);
glPopMatrix();

glPushMatrix();
gluQuadricDrawStyle (p, GLU_FILL);
glTranslatef (0.0, 0, 0.0);
glRotatef (-90.0, 1, 0.0, 0.0);
gluDisk (p, 0, 2, 20, 20);
glPopMatrix();
}

void display(void) 
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0, 5,10, 0.0, 1, 0.0, 0.0, 1.0, 0.0);
  glTranslatef (0,  0, 0);

  glRotatef(anglex, 1, 0, 0);
  glRotatef(angley, 0, 1, 0);
  glRotatef(anglez, 0, 0, 1);
  base();
  glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y) 
{
switch (key) 
  {
  case 27:
  exit(0);
  case 'x':
    anglex-=5;
    break;
  case 'X':
  anglex+=5;
  break;
  case 'y':
    angley+=5;
   break;
  case 'Y':
    angley-=5;
  break;
  case 'z':
    anglez+=5;
    break;
  case 'Z':
   anglez-=5;
   break;
   
   
  }
 glutPostRedisplay();
}
void reshape(int w, int h) {
  glViewport(1, 1, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(100.0, (GLfloat) w / (GLfloat) h, 0.5, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void init (void) {
//GLfloat lightIntensity[] = {0.7f, 0.7f, 0.7f, 1.0f};
//GLfloat light_position[] = {2.0f, 6.0f, 3.0f, 0.0f};

//glEnable(GL_LIGHTING);
//glEnable(GL_LIGHT0);
//glShadeModel(GL_FLAT );
//glEnable(GL_DEPTH_TEST);
//glEnable(GL_NORMALIZE);

//glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//lLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

glClearColor(0.1, 0.0, 1.0, 0.0);//x
glColor3f(1.0, 1.0, 0.0);
 p = gluNewQuadric();
}

void init1(void)
{
GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_shininess[] = {50.20};
GLfloat light_position[] = {1.0, 0.1, 0.1, 1.0};
GLfloat white_light[] = {0.3, 0.3, 0.3, 1.0};
GLfloat lmodel_ambient[] = {1.0, 1.0, 0.0, 1.0};
glClearColor(0.1, 0.0, 0.1, 0.0);
//glShadeModel(GL_SMOOTH);

//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(width, height);
  glutCreateWindow("GLASS");
  glutInitWindowPosition(100,100);
  init();
  init1();
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;

}
  
