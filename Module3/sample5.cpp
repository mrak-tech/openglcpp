/*
Drawing a Square (GL_POLYGON)
This example, based on the one in the PDF, draws a single white square in the center of a black window.
GL_POLYGON takes a list of vertices and connects them in order to form a single filled shape.

*/

#include <GL/glut.h>

void display() {
    // Clear the screen to black
    glClear(GL_COLOR_BUFFER_BIT);

    // Start drawing a polygon
    glBegin(GL_POLYGON);
    // Define the four corners of the square
    glVertex2f(-0.5, -0.5); // Bottom-left
    glVertex2f(-0.5, 0.5); // Top-left
    glVertex2f(0.5, 0.5); // Top-right
    glVertex2f(0.5, -0.5); // Bottom-right
    glEnd();

    // Send the drawing to the screen
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Example 1: A Square");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}