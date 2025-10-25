// m6sam1.cpp
// Simple GLUT program that draws a triangle using the legacy immediate mode pipeline.

#include <GL/glut.h>

// Configure the initial GL state once at startup.
void initialize()
{
    // Set a dark background color for contrast.
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

// Render a single triangle using immediate-mode drawing commands.
void triangle()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.2f, 0.2f);  // Reddish color for the top vertex.
    glVertex2f(0.0f, 0.75f);

    glColor3f(0.2f, 0.8f, 0.2f);  // Green tint for the bottom-left vertex.
    glVertex2f(-0.75f, 0.0f);

    glColor3f(0.2f, 0.2f, 0.8f);  // Blue tint for the bottom-right vertex.
    glVertex2f(0.75f, 0.0f);
    glEnd();
}

// Display callback registered with GLUT.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    triangle();

    // Because we are using a single buffered window, make sure everything is drawn now.
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Legacy Triangle");

    initialize();

    // Register the main display callback and begin the event loop.
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
