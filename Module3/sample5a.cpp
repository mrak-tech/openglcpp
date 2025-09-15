/*
Drawing a Pentagon (GL_POLYGON)
This example draws a single white pentagon in the center of a black window.
GL_POLYGON takes a list of vertices and connects them in order to form a single filled shape.

*/

#include <GL/glut.h>

void display() {
    // Clear the screen to black
    glClear(GL_COLOR_BUFFER_BIT);

    // Start drawing a polygon
    glBegin(GL_POLYGON);
    // Define the five corners of the pentagon
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.4755, 0.1545);
    glVertex2f(-0.2939, -0.4045);
    glVertex2f(0.2939, -0.4045);
    glVertex2f(0.4755, 0.1545);
    glEnd();

    // Send the drawing to the screen
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Example 5a: A Pentagon");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}