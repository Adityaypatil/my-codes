
import pygame
from pygame.locals import *
from math import*
from OpenGL.GL import *
from OpenGL.GLU import *

verticies = (
  (-0.8,-0.6,0),
   (-0.4,-0.9,0),
   (0.4,-0.9,0),
   (0.8,-0.6,0),
   (-0.2,1.2,0),
   (0.2,1.2,0),
   (-0.5,1,0),
   (0.5,1,0),
   (-0.3,1.5,0),
   (0.3,1.5,0),
    (-0.1,1.7,0),
    (-0.2,0.6,0),
    (0.2,0.6,0),
    (-0.12,-0.08,0),
    (0.1,-0.2,0),
    (-0.45,-0.6,0),
    (-0.25,-0.65,0),
    (-0.55,-1.2,0),
   (-0.38,-1.3,0),
    (0.47,-0.6,0),
    (0.28,-0.65,0),
    (0.38,-1.4,0),
   (0.17,-1.35,0),
   (-0.45,-1.1,0),
   (-0.42,-1.25,0),
   (-1,-1.25,0),
   (-0.95,-1.37,0),
   (0.33,-1.18,0),
   (0.36,-1.33,0),
   (-0.23,-1.3,0),
   (-0.2,-1.44,0),
   (-0.23,1.42,0),
   (-0.26,1.28,0),
   (-0.75,1.38,0),
   (-0.75,1.28,0),
   (-0.72,1.2,0),
   (-0.72,1.1,0),
   (-0.33,1.2,0),
   (-0.3,1.1,0)
   )
edges = (
    (0,1),
    (0,4),
    (3,2),
    (3,5),
    (1,2),
    (4,5),
    (6,7),
    (6,8),
    (7,9),
    (8,10),
    (9,10),
    (11,12),
    (13,14),
    (11,13),
    (12,14),
    (15,16),
    (15,17),
    (16,18),
    (17,18),
    (19,20),
    (21,22),
    (19,21),
    (20,22),
    (23,24),
    (23,25),
    (24,26),
    (25,26),
    (27,28),
    (29,30),
    (27,29),
    (28,30),
    (31,32),
    (33,34),
    (31,33),
    (32,34),
    (35,36),
    (37,38),
    (35,37),
    (36,38)
    )

def eye():
    glBegin(GL_POINTS)
    for i in range (100):
        glVertex3fv((sin(2*3.14*i/100.0)*0.1,cos(2*3.14*i/100.0)*0.1,0))
    glEnd()   

def Hand_circle():
    glBegin(GL_POINTS)
    for i in range (100):
        glVertex3fv((sin(2*3.14*i/100.0)*0.3,cos(2*3.14*i/100.0)*0.3,0))
    glEnd()   

def Leg_circle():
    glBegin(GL_POINTS)
    for i in range (100):
        glVertex3fv((sin(2*3.14*i/100.0)*0.22,cos(2*3.14*i/100.0)*0.22,0))
    glEnd()    

def Leg_circle2():
    glBegin(GL_POINTS)
    for i in range (100):
        glVertex3fv((sin(2*3.14*i/100.0)*0.3,cos(2*3.14*i/100.0)*0.3,0))
    glEnd()    

def duck():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(verticies[vertex])
    glEnd()


def main():
    pygame.init()
    display = (1000,500)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)

    glTranslatef(0.0,0.0,0)
    duck()
    glTranslatef(-0.2,2.9,-5)
    eye()    
    glTranslatef(0.2,-1.5,-5)
    Hand_circle()
    glTranslatef(-1.4,-4.25,-5)
    Leg_circle()
    glTranslatef(3.3,-0.8,-5)
    Leg_circle2()

#        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    pygame.display.flip()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()


main()
