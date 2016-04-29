import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *

verticies = (
        (-0.8,1,0),
        (0.3,0.6,0),
        (0.3,-1,0),
        (-0.8,-0.6,0)
        )

edges = (
        (0,1),
        (2,3)
        )

def line():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(verticies[vertex])
    glEnd()

def main():
    pygame.init()
    display = (800,600)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)
    glTranslatef(0.0,0.0, -5)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)

        glRotate(1,0,0,1)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)

        glScalef(1.0,1.0,0.7)
        line()
        pygame.display.flip()

main()
