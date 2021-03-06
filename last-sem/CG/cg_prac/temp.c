#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
    
 int screenheight = 600;  
 int screenwidth = 800;  
 int flag = 1;  
   
 double angle = 30;        //The angle for the rotation (in degrees)  
   
 typedef struct{  
   float x;  
   float y;  
 }Point2D;  
   
 Point2D p1,p2;  
   
 void DrawLineSegment(Point2D pt1, Point2D pt2){  
     glPointSize(1.0);  
     glBegin(GL_LINES);  
     glVertex2i(pt1.x, pt1.y);  
     glVertex2i(pt2.x, pt2.y);  
     glEnd();  
   
     glPointSize(6.0);  
     glBegin(GL_POINTS);  
     glVertex2i(pt2.x, pt2.y);  
     glEnd();  
     glFlush();  
   
 }  
   
 Point2D rotate(Point2D p, float ang){  
   ang = ang * 3.14 / 180.0;                 //angle in radians  
   Point2D ptemp;  
   
   ptemp.x = p.x * cos(ang) - p.y * sin(ang);  
   ptemp.y = p.x * sin(ang) + p.y * cos(ang);  
   
      return ptemp;  
 }  
   
 void myMouse(int button, int state, int x, int y) {  
     if(state == GLUT_DOWN) {  
        if(button == GLUT_LEFT_BUTTON) {  
            glClear(GL_COLOR_BUFFER_BIT);  
            Point2D p1;  
            p1.x = 0;  
            p1.y = 0;  
   
            p2.x = x;  
            p2.y = screenheight - y;  
   
            DrawLineSegment(p1, p2);  
        }  
        else if (button == GLUT_RIGHT_BUTTON) {  
            Point2D Rotated_p2 = rotate(p2,angle);  
            DrawLineSegment(p1,Rotated_p2);  
        }  
     }  
 }  
   
 void myDisplay(){  
     glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  
     glClear(GL_COLOR_BUFFER_BIT);  
     glColor3f(0.0f, 0.0f, 0.0f);  
 }  
    
 int main( int argc, char ** argv ) {  
     glutInit( &argc, argv );  
     glutInitWindowPosition( 0, 0 );  
     glutInitWindowSize( 800, 600 );  
     glutCreateWindow( "Rotate Line" );  
     glMatrixMode( GL_PROJECTION );  
     glLoadIdentity();  
     gluOrtho2D( 0, 800, 0, 600 );  
     glViewport(0, 0, 800, 600);  
     glutMouseFunc( myMouse );  
     glutDisplayFunc( myDisplay );  
     glutMainLoop();  
     return( 0 );  
 } 
