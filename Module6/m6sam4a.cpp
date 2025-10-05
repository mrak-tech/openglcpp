// m6sam4a.cpp
// Transitional legacy example: uses client-side arrays with glDrawArrays
// to draw an ice cream cone.

#include <GL/glut.h>

// Position-only data kept in system memory; we rebind it before every draw call.
static const GLfloat coneVertices[] = {
    0.0f, -0.7f,  // bottom tip of the cone
   -0.3f, -0.1f,
    0.3f, -0.1f
};

// Triangle fan for the scoop: first vertex is the center, the rest outline the scoop.
static const GLfloat scoopVertices[] = {
     0.0f,  0.1f,
    -0.35f, 0.05f,
    -0.3f,  0.25f,
    -0.15f, 0.35f,
     0.0f,  0.38f,
     0.15f, 0.35f,
     0.3f,  0.25f,
     0.35f, 0.05f
};

// Sprinkles drawn as a simple strip for extra detail.
static const GLfloat sprinkleVertices[] = {
    -0.15f, 0.28f,
    -0.05f, 0.30f,
     0.05f, 0.25f,
     0.15f, 0.33f
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
    // Light background makes the ice cream colors pop.
    glClearColor(0.95f, 0.95f, 0.85f, 1.0f);
}

// Draw the entire cone using client-side vertex arrays.
void drawIceCreamLegacy()
{
    // Enable vertex arrays each time before use (older workflow).
    glEnableClientState(GL_VERTEX_ARRAY);

    // Draw the cone body.
    glColor3f(0.87f, 0.66f, 0.43f);
    glVertexPointer(2, GL_FLOAT, 0, coneVertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Draw the scoop with a triangle fan.
    glColor3f(0.95f, 0.55f, 0.70f);
    glVertexPointer(2, GL_FLOAT, 0, scoopVertices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

    // Add a sprinkle strip so the scene feels more detailed.
    glColor3f(0.35f, 0.15f, 0.45f);
    glVertexPointer(2, GL_FLOAT, 0, sprinkleVertices);
    glDrawArrays(GL_LINE_STRIP, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);

    // Label each array so students can connect variable names with shapes.
    glColor3f(0.2f, 0.2f, 0.2f);
    drawLabel(-0.18f, -0.05f, "coneVertices");
    drawLabel(-0.12f, 0.18f, "scoopVertices");
    drawLabel(-0.05f, 0.32f, "sprinkleVertices");
}

// Display callback registered with GLUT.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawIceCreamLegacy();

    // Single buffered window, so flush immediately.
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(140, 140);
    glutCreateWindow("Legacy Arrays Ice Cream");

    initialize();

    // Register the main display callback and begin the event loop.
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
