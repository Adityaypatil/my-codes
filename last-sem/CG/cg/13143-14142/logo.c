#include <GL/glut.h>
#include <stdlib.h>
 
/* GLUT callback Handlers */
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
 
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glEnable( GL_LINE_SMOOTH );
    glEnable( GL_POLYGON_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        //gluLookAt(20, 0, 0, 0, 0, -10, 0, 1, 0);    
    
        glColor3d(1,0,0);
        glVertex3f(-2,2,-10);
       // glColor3d(1,1,0);
        glVertex3f(-0.1,2,-8);
        //glColor3d(1,1,1);
        glVertex3f(-0.1,0.1,-8);
        //glColor3d(0,1,1);
        glVertex3f(-2,0.1,-10);
    
        glColor3d(0,1,0);
        glVertex3f(0.1,1.9,-7.5);
       // glColor3d(1,1,0);
        glVertex3f(1.9,2,-5.5);
        //glColor3d(1,1,1);
        glVertex3f(1.9,0.1,-5.5);
        //glColor3d(0,1,1);
        glVertex3f(0.1,0.1,-7.5);

        glColor3d(0,0,1);
        glVertex3f(-0.1,-0.1,-8);
       // glColor3d(1,1,0);
        glVertex3f(-0.1,-2,-8);
        //glColor3d(1,1,1);
        glVertex3f(-2,-2,-10);
        //glColor3d(0,1,1);
        glVertex3f(-2,-0.1,-10);

        glColor3d(1,1,0);
        glVertex3f(0.1,-0.1,-7.5);
       // glColor3d(1,1,0);
        glVertex3f(1.9,-0.1,-5.5);
        //glColor3d(1,1,1);
        glVertex3f(1.9,-2,-5.5);
        //glColor3d(0,1,1);
        glVertex3f(0.1,-1.9,-7.5);

    		
    glEnd();
    glutSwapBuffers();
}
 

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}
 
static void idle(void)
{
    glutPostRedisplay();
}
 
/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
 
    glutCreateWindow("Windows 10");
 
    glRotatef(45, 0, 1, 0);

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
 
    glClearColor(0,0,0,0);
 
    glutMainLoop();
 
    return EXIT_SUCCESS;
}
