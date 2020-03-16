#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "model/loader.h"
#include <math.h>

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
            0.0,  0.0,  -1.0);
    glutDisplayFunc(renderPlane);
    glutMainLoop();
    return 0;
}