#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

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
                    printf("%s\n", str.c_str());
                    if (str[0] == '}') {
                        glEnd();
                        break;
                    } else if (str.length() == 0) {
                        continue;
                    } else {
                        float x, y, z;
                        sscanf(str.c_str(), "%f %f %f", &x, &y, &z);
                        glVertex3f(x, y, z);
                    }
                }
            }
        }
        definitionFile.close();
        glFlush();
    }
}