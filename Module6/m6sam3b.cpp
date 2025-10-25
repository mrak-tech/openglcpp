// m6sam3b.cpp
// Modern fixed-function example: draws the same house using vertex arrays.

#include <GL/glut.h>

// Vertex data reused by glDrawArrays instead of issuing individual vertices.
static const GLfloat baseVertices[] = {
    -0.5f, -0.7f,
    -0.5f, -0.1f,
     0.5f, -0.7f,
     0.5f, -0.1f
};

static const GLfloat doorVertices[] = {
    -0.15f, -0.7f,
    -0.15f, -0.3f,
     0.15f, -0.7f,
     0.15f, -0.3f
};

static const GLfloat roofVertices[] = {
    -0.6f, -0.1f,
     0.6f, -0.1f,
     0.0f,  0.4f
};

// Small helper to draw on-screen labels using GLUT bitmap fonts.
void drawLabel(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text++);
    }
}

// Configure the initial GL state once at startup.
void initialize()
{
    // Soft blue background makes the house shape stand out.
    glClearColor(0.5f, 0.7f, 0.9f, 1.0f);
}

// Draw the entire house using vertex arrays and glDrawArrays.
void drawHouseModern()
{
    // Enable the fixed-function vertex array pipeline.
    glEnableClientState(GL_VERTEX_ARRAY);

    // Draw the square base using a triangle strip sourced from our array.
    glVertexPointer(2, GL_FLOAT, 0, baseVertices);
    glColor3f(0.75f, 0.2f, 0.2f);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    // Draw the door using the same approach.
    glVertexPointer(2, GL_FLOAT, 0, doorVertices);
    glColor3f(0.55f, 0.35f, 0.2f);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    // Draw the roof as a triangle from its vertex data.
    glVertexPointer(2, GL_FLOAT, 0, roofVertices);
    glColor3f(0.6f, 0.3f, 0.1f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    // Label each vertex array so students can see which buffer drew which part.
    glColor3f(0.1f, 0.1f, 0.1f);
    drawLabel(-0.45f, -0.25f, "baseVertices");
    drawLabel(-0.12f, -0.32f, "doorVertices");
    drawLabel(-0.15f, -0.05f, "roofVertices");

    // Add the name of the helper function for clarity.
    drawLabel(-0.95f, 0.85f, "drawHouseModern()");
}

// Display callback registered with GLUT.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawHouseModern();

    // Tag the frame with the active display function name.
    glColor3f(0.1f, 0.1f, 0.1f);
    drawLabel(-0.95f, 0.95f, "display()");

    // Because we are using a single buffered window, make sure everything is drawn now.
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(160, 160);
    glutCreateWindow("Vertex Array House");

    initialize();

    // Register the main display callback and begin the event loop.
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
