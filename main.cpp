#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <math.h>
#include "model/loader.h"
#include <math.h>

static float *up_vector = (float*) malloc(3*sizeof(float));
static double dist = sqrt(1 / 5.0);
static void help();

static float* rotateVector(float input[3], float derajat, char axis){
    float *output = (float*) malloc(3 * sizeof(float));
    if(axis == 'x'){
        output[0] = input[0];
        output[1] = cos(derajat)*input[1] - sin(derajat)*input[2];
        output[2] = sin(derajat)*input[1] + cos(derajat)*input[2];
    }else if (axis =='y'){
        output[0] = cos(derajat)*input[0] + sin(derajat)*input[2];
        output[1] = input[1];
        output[2] = -sin(derajat)*input[0] + cos(derajat)*input[2];
    }else if (axis == 'z'){
        output[0] = cos(derajat)*input[0] - sin(derajat)*input[1];
        output[1] = sin(derajat)*input[0] + cos(derajat)*input[1];
        output[2] = input[2];
    }
    return output;
}

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
            //rotate up vector around x axis (10 degree)
            up_vector = rotateVector(up_vector, 10, 'x');
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MATRIX_MODE);
            glLoadIdentity();
            gluLookAt(dist, dist, dist,
                    0.0, 0.0, 0.0,
                    up_vector[0], up_vector[1], up_vector[2]);
            break;
        case '2':
            //rotate up vector around x axis (10 degree)
            up_vector = rotateVector(up_vector, 10, 'y');
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glMatrixMode(GL_MATRIX_MODE);
            glLoadIdentity();
            gluLookAt(dist, dist, dist,
                    0.0, 0.0, 0.0,
                    up_vector[0], up_vector[1], up_vector[2]);
            break;
        case '3':
            //rotate up vector around x axis (10 degree)
            up_vector = rotateVector(up_vector, 10, 'z');
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
    up_vector[0] = 0.0;
    up_vector[1] = 1.0;
    up_vector[2] = 0.0;
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
