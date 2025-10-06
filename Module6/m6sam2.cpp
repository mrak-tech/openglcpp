// m6sam2.cpp
// Draws the same triangle as m6sam1.cpp but uses vertex arrays instead of traditional mode.

#include <GL/glut.h>

// Predefined triangle positions feed the vertex array pipeline.
static const GLfloat vertices[] = {
    0.0f, 0.75f,
   -0.75f, 0.0f,
    0.75f, 0.0f
};

// Configure the initial GL state once at startup.
void initialize()
{
    // Set a dark background color for contrast.
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

// Display callback registered with GLUT.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Enable the fixed-function vertex array pipeline.
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);

    // Use a single color for the entire triangle when drawing via arrays.
    glColor3f(0.8f, 0.5f, 0.2f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    // Because we are using a single buffered window, make sure everything is drawn now.
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Vertex Array Triangle");

    initialize();

    // Register the main display callback and begin the event loop.
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
