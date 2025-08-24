// window1.cpp
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear screen
    glFlush();  // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                    // Initialize GLUT
    glutCreateWindow("My first Open GL Program");    // Create window
    glutDisplayFunc(display);                 // Set display callback
    glutMainLoop();                           // Enter event loop
    return 0;
}