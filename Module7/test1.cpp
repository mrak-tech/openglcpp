#include<iostream>
#include <GL/glut.h>

// Simple immediate-mode triangle example without timing.
using namespace std;
void display();
void triangle();
void init();
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("simple");
    glutDisplayFunc(display);
    glutMainLoop();
}
void triangle() {
    // Define the triangle vertices directly between glBegin/glEnd.
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, .75f);
    glVertex2f(-0.75f, 0.0);
    glVertex2f(0.75, 0.0);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(.16f, .72f, .08f, 1.0f);
    triangle();
    glFlush();
}
