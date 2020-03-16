#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <math.h>
#include "model/loader.h"
#include <math.h>

static float up_vector[3] = {0.0, 1.0, 0.0};
static float new_up[3];
static double dist = sqrt(1 / 5.0);
static void help();


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
        case 'r':
            //reset
            up_vector[0] = 0.0;
            up_vector[1] = 1.0;
            up_vector[2] = 0.0;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MATRIX_MODE);
            glLoadIdentity();
            gluLookAt(dist, dist, dist,
                    0.0, 0.0, 0.0,
                    up_vector[0], up_vector[1], up_vector[2]);
            break;
            break;
        case '1':
            //rotate up vector around x axis (10)
            new_up[0] = up_vector[0];
            new_up[1] = cos(10)*up_vector[1] - sin(10)*up_vector[2];
            new_up[2] = sin(10)*up_vector[1] + cos(10)*up_vector[2];
            up_vector[0] = new_up[0];
            up_vector[1] = new_up[1];
            up_vector[2] = new_up[2];
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MATRIX_MODE);
            glLoadIdentity();
            gluLookAt(dist, dist, dist,
                    0.0, 0.0, 0.0,
                    up_vector[0], up_vector[1], up_vector[2]);
            break;
        case '2':
            //rotate up vector around y axis (10)
            new_up[0] = cos(10)*up_vector[0] + sin(10)*up_vector[2];
            new_up[1] = up_vector[1];
            new_up[2] = -sin(10)*up_vector[0] + cos(10)*up_vector[2];
            up_vector[0] = new_up[0];
            up_vector[1] = new_up[1];
            up_vector[2] = new_up[2];
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MATRIX_MODE);
            glLoadIdentity();
            gluLookAt(dist, dist, dist,
                    0.0, 0.0, 0.0,
                    up_vector[0], up_vector[1], up_vector[2]);
            break;
        case '3':
            //rotate up vector around z axis (10)
            new_up[0] = cos(10)*up_vector[0] - sin(10)*up_vector[1] + 0*up_vector[2];
            new_up[1] = sin(10)*up_vector[0] + cos(10)*up_vector[1] + 0*up_vector[2];
            new_up[2] = up_vector[2];
            up_vector[0] = new_up[0];
            up_vector[1] = new_up[1];
            up_vector[2] = new_up[2];
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MATRIX_MODE);
            glLoadIdentity();
            gluLookAt(dist, dist, dist,
                    0.0, 0.0, 0.0,
                    up_vector[0], up_vector[1], up_vector[2]);
            break;
        case '+':
            //Zoom in
            glScalef(1.5, 1.5, 1.5);
            //glutPostRedisplay();
            break;

        case '-':
            //Zoom out
            glScalef(0.5, 0.5, 0.5);
            //glutPostRedisplay();
            break;
        case 'h':
            //Zoom out
            help();
            //glutPostRedisplay();
            break;

    }
    /*
    if (key =='+')
        glScaled(1.5, 1.5, 1.5);
    else if (key =='-')
        glScaled(0.5, 0.5, 0.5);
    */
    glutPostRedisplay();
}

static void help()
{
    const unsigned char kata[] = "HELP";
    int w;
    w = glutBitmapLength(GLUT_BITMAP_8_BY_13, kata);

    glRasterPos2f(0., 0.);

    float x = .5;
    glRasterPos2f(x - (float) w / 2, 0.);
    const char* kata2 = "HELP";

    glColor3ub(1., 0., 0.);

    size_t len = strlen(kata2);
    int i;
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, kata[i]);
    }






}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Plane Simulation");
    glMatrixMode(GL_MATRIX_MODE);
    glLoadIdentity();

    gluLookAt(dist, dist, dist,
            0.0,  0.0,  0.0,
            up_vector[0],  up_vector[1],  up_vector[2]);

    glutDisplayFunc(renderPlane);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
