#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include "model/loader.h"
#include <math.h>

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            //quit
            exit(0);
            break;
        case 'x':
            //rotate camera around model
            glRotatef(10.0, 1.0, 0.0, 0.0);
            break;
        case 'y':
            //rotate camera around model
            glRotatef(10.0, 0.0, 1.0, 0.0);
            break;
        case 'z':
            //rotate camera around model
            glRotatef(10.0, 0.0, 0.0, 1.0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Plane Simulation");
    glMatrixMode(GL_MATRIX_MODE);
    glLoadIdentity();

    double dist = sqrt(1 / 5.0);

    gluLookAt(dist, dist, dist,
            0.0,  0.0,  0.0,
            0.0,  0.0,  1.0);

    glutDisplayFunc(renderPlane);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}