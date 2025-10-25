// m6sam4b.cpp
// Modernized array example: packs vertex positions and colors together
// and reuses one glDrawArrays stream to draw the same ice cream cone.

#include <GL/glut.h>

struct ColoredVertex
{
    GLfloat x;
    GLfloat y;
    GLfloat r;
    GLfloat g;
    GLfloat b;
};

// Geometry packed into a single array so we can issue multiple glDrawArrays
// calls without rebinding pointers.
static const ColoredVertex iceCreamGeometry[] = {
    // ----- Cone (first 3 vertices) -----
    { 0.0f, -0.7f, 0.87f, 0.66f, 0.43f },
    {-0.3f, -0.1f, 0.83f, 0.61f, 0.40f },
    { 0.3f, -0.1f, 0.83f, 0.61f, 0.40f },

    // ----- Scoop (next 8 vertices form a triangle fan) -----
    { 0.0f,  0.1f, 0.95f, 0.55f, 0.70f },
    {-0.35f, 0.05f, 0.97f, 0.60f, 0.74f },
    {-0.3f,  0.25f, 0.98f, 0.65f, 0.76f },
    {-0.15f, 0.35f, 0.99f, 0.70f, 0.80f },
    { 0.0f,  0.38f, 0.99f, 0.72f, 0.81f },
    { 0.15f, 0.35f, 0.98f, 0.65f, 0.76f },
    { 0.3f,  0.25f, 0.97f, 0.60f, 0.74f },
    { 0.35f, 0.05f, 0.96f, 0.58f, 0.73f },

    // ----- Sprinkles strip (last 4 vertices) -----
    {-0.15f, 0.28f, 0.40f, 0.20f, 0.60f },
    {-0.05f, 0.30f, 0.20f, 0.40f, 0.65f },
    { 0.05f, 0.25f, 0.60f, 0.30f, 0.15f },
    { 0.15f, 0.33f, 0.25f, 0.55f, 0.30f }
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
    // Light background keeps the pastel colors readable.
    glClearColor(0.95f, 0.95f, 0.85f, 1.0f);
}

// Draw the ice cream with a single interleaved array.
void drawIceCreamModern()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Provide both position and color data with one pointer setup.
    glVertexPointer(2, GL_FLOAT, sizeof(ColoredVertex), &iceCreamGeometry[0].x);
    glColorPointer(3, GL_FLOAT, sizeof(ColoredVertex), &iceCreamGeometry[0].r);

    // Draw each section by advancing the starting index.
    glDrawArrays(GL_TRIANGLES, 0, 3);          // cone slab
    glDrawArrays(GL_TRIANGLE_FAN, 3, 8);       // scoop cap
    glDrawArrays(GL_LINE_STRIP, 11, 4);        // sprinkle drizzle

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Annotate the onscreen geometry so students can trace data to output.
    glColor3f(0.2f, 0.2f, 0.2f);
    drawLabel(-0.18f, -0.05f, "iceCreamGeometry[0..2]");
    drawLabel(-0.12f, 0.18f, "iceCreamGeometry[3..10]");
    drawLabel(-0.05f, 0.32f, "iceCreamGeometry[11..14]");
    drawLabel(-0.95f, 0.85f, "drawIceCreamModern()");
}

// Display callback registered with GLUT.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawIceCreamModern();

    // Show which display function generated the current frame.
    glColor3f(0.2f, 0.2f, 0.2f);
    drawLabel(-0.95f, 0.95f, "display()");

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(180, 180);
    glutCreateWindow("Packed Arrays Ice Cream");

    initialize();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
