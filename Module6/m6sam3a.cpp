// m6sam3a.cpp
// Legacy immediate-mode example: draws a simple house using glBegin/glEnd calls.

#include <GL/glut.h>

// Configure the initial GL state once at startup.
void initialize()
{
    // Soft blue background makes the house shape stand out.
    glClearColor(0.5f, 0.7f, 0.9f, 1.0f);
}

// Small helper to draw on-screen labels using GLUT bitmap fonts.
void drawLabel(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text++);
    }
}

// Draw a simple "house" shape to keep the scene relatable for students.
void drawHouseLegacy()
{
    // Draw the square base of the house brick-red.
    glBegin(GL_QUADS);
    glColor3f(0.75f, 0.2f, 0.2f);
    glVertex2f(-0.5f, -0.7f);
    glVertex2f(0.5f, -0.7f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(-0.5f, -0.1f);
    glEnd();

    // Add a small door so the shape looks more like a house.
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.35f, 0.2f);
    glVertex2f(-0.15f, -0.7f);
    glVertex2f(0.15f, -0.7f);
    glVertex2f(0.15f, -0.3f);
    glVertex2f(-0.15f, -0.3f);
    glEnd();

    // Draw the roof as a triangle on top of the base.
    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.3f, 0.1f);
    glVertex2f(-0.6f, -0.1f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.0f, 0.4f);
    glEnd();

    // Label each section so students can connect the code to the visual output.
    glColor3f(0.1f, 0.1f, 0.1f);
    drawLabel(-0.15f, -0.05f, "Roof (glBegin)");
    drawLabel(-0.45f, -0.25f, "Base (glBegin)");
    drawLabel(-0.12f, -0.32f, "Door (glBegin)");
    drawLabel(-0.95f, 0.85f, "drawHouseLegacy()");
}

// Display callback registered with GLUT.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawHouseLegacy();

    // Tag the top of the frame with the active display function name.
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
    glutInitWindowPosition(120, 120);
    glutCreateWindow("Legacy House");

    initialize();

    // Register the main display callback and begin the event loop.
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
