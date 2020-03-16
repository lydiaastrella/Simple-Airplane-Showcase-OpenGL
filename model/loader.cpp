#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

void drawCartesianLine() {
    glBegin(GL_LINES);

    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(1.0, 0.0, 0.0);

    glColor3d(0.0, 1.0, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0, 1.0, 0.0);

    glColor3d(0.0, 0.0, 1.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0, 0.0, 1.0);

    glEnd();
}

void loadFromFile(void) {
    std::ifstream definitionFile("definition/definition.txt");
    if (definitionFile.is_open()) {
        std::string str;
        while (getline(definitionFile, str)) {
            if (str[0] == '{') {
                glBegin(GL_POLYGON);
                float color[3];
                definitionFile >> color[0] >> color[1] >> color[2];
                glColor3f(color[0], color[1], color[2]);
                while (getline(definitionFile, str)) {
                    if (str[0] == '}') {
                        glEnd();
                        break;
                    } else if (str.length() == 0) {
                        continue;
                    } else {
                        float x, y, z;
                        sscanf(str.c_str(), "%f %f %f", &x, &y, &z);
                        glVertex3f(x/20, y/20, z/20);
                    }
                }
            }
        }
        definitionFile.close();
    }
}

void renderPlane() {
    //drawCartesianLine();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    loadFromFile();
    glPopMatrix();
    glFlush();
}
