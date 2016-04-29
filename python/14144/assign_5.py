import pygame
from pygame.locals import *
from math import *
from OpenGL.GL import *
from OpenGL.GLU import *

verticies = (
        (-0.4,0.77,0),
        (0.4,0.77,0),
        (-0.45,-0.2,0),
        (0.45,-0.2,0),
        (-0.68,0.3,0),
        (0.68,0.3,0),
        (-0.3,-0.2,0),
        (-0.3,-0.7,0),
        (-0.2,-0.2,0),
        (-0.2,-0.7,0),
        (0.3,-0.2,0),
        (0.3,-0.7,0),
        (0.2,-0.2,0),
        (0.2,-0.7,0)
        )
edges = (
        (0,1),
        (2,3),
        (0,2),
        (1,3),
        (0,4),
        (1,5),
        (6,7),
        (8,9),
        (10,11),
        (12,13)
        )


def Face():
    glBegin(GL_POINTS)
    for i in range (1000):
        glVertex3fv((sin(2*3.14*i/1000.0)*0.4,cos(2*3.14*i/1000.0)*0.4,0))
    glEnd()  

def smile():
    glBegin(GL_POINTS)
    for i in range (25,75):
        glVertex3fv((sin(2*3.14*i/100.0)*0.65,cos(2*3.14*i/100.0)*0.65,-35))
    glEnd()    

def Circle_eye():
    glBegin(GL_POINTS)
    for i in range (100):
        glVertex3fv((sin(2*3.14*i/100.0)*-0.1,cos(2*3.14*i/100.0)*-0.1,-11))
    glEnd()    

def doll():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(verticies[vertex])
    glEnd()


def main():
    pygame.init()
    display = (1300,900)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)
    glTranslatef(0.0,0.0, -5)
    doll()
    glTranslatef(0,1.5,-2)
    Face()
    glTranslatef(-0.5,3,-2)
    Circle_eye()
    glTranslatef(1,0.5,-2)
    Circle_eye()
    glTranslatef(-0.4,3.8,-2)
    smile()
    pygame.display.flip()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

main()
