#include <GL/glut.h> // Include the GLUT library

/*
List of some common colors and their RGB values:
- Red: (1.0, 0.0, 0.0)
- Green: (0.0, 1.0, 0.0)
- Blue: (0.0, 0.0, 1.0)
- Yellow: (1.0, 1.0, 0.0)
- Cyan: (0.0, 1.0, 1.0)
- Magenta: (1.0, 0.0, 1.0)
- White: (1.0, 1.0, 1.0)
- Black: (0.0, 0.0, 0.0)
- Gray: (0.5, 0.5, 0.5)
*/

// This is our callback function for drawing
void display() {
    // Set the clear color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Clear the window to the currently set color
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a red square
    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_POLYGON);
    glVertex2f(-0.9, 0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.9, 0.9);
    glEnd();

    // Draw a green square
    glColor3f(0.0, 1.0, 0.0); // Green
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.9, 0.1);
    glVertex2f(0.9, 0.9);
    glVertex2f(0.1, 0.9);
    glEnd();

    // Draw a blue square
    glColor3f(0.0, 0.0, 1.0); // Blue
    glBegin(GL_POLYGON);
    glVertex2f(-0.9, -0.9);
    glVertex2f(-0.1, -0.9);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.9, -0.1);
    glEnd();

    // Draw a yellow square
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glBegin(GL_POLYGON);
    glVertex2f(0.1, -0.9);
    glVertex2f(0.9, -0.9);
    glVertex2f(0.9, -0.1);
    glVertex2f(0.1, -0.1);
    glEnd();

    // Force execution of OpenGL commands in finite time
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Colored Squares");

    // Register our 'display' function as the display callback
    glutDisplayFunc(display);

    // Enter the main event loop
    glutMainLoop();
    return 0;
}
