/*
 Drawing Points (GL_POINTS)
This program uses the GL_POINTS primitive to draw four individual points on the screen. Each glVertex call creates a single visible dot.

*/


#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the point size to be larger and more visible
    glPointSize(10.0f);

    // Start drawing points
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);   // Center
    glVertex2f(-0.5, 0.5);  // Top-left
    glVertex2f(0.5, 0.5);   // Top-right
    glVertex2f(-0.5, -0.5); // Bottom-left
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Example 2: Points");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}