#include <GL/glut.h> // Include the GLUT library

// This is our callback function for drawing
void display() {
    // Set the clear color to a nice light blue (R=0.5, G=0.7, B=1.0)
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f);

    // Clear the window to the currently set color
    glClear(GL_COLOR_BUFFER_BIT);

    // Force execution of OpenGL commands in finite time
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("A Window with a Blue Background");

    // Register our 'display' function as the display callback
    glutDisplayFunc(display);

    // Enter the main event loop
    glutMainLoop();
    return 0;
}