#include <GL/freeglut.h>

struct BitmapFontEntry {
    void* font;
    const char* label;
};

struct StrokeFontEntry {
    void* font;
    const char* label;
};

BitmapFontEntry bitmapFonts[] = {
    {GLUT_BITMAP_9_BY_15, "GLUT_BITMAP_9_BY_15"},
    {GLUT_BITMAP_8_BY_13, "GLUT_BITMAP_8_BY_13"},
    {GLUT_BITMAP_TIMES_ROMAN_10, "GLUT_BITMAP_TIMES_ROMAN_10"},
    {GLUT_BITMAP_TIMES_ROMAN_24, "GLUT_BITMAP_TIMES_ROMAN_24"},
    {GLUT_BITMAP_HELVETICA_10, "GLUT_BITMAP_HELVETICA_10"},
    {GLUT_BITMAP_HELVETICA_12, "GLUT_BITMAP_HELVETICA_12"},
    {GLUT_BITMAP_HELVETICA_18, "GLUT_BITMAP_HELVETICA_18"}
};

StrokeFontEntry strokeFonts[] = {
    {GLUT_STROKE_ROMAN, "GLUT_STROKE_ROMAN"},
    {GLUT_STROKE_MONO_ROMAN, "GLUT_STROKE_MONO_ROMAN"}
};

void renderBitmapLine(float y, void* font, const char* text)
{
    glRasterPos2f(-0.95f, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}

void renderStrokeLine(float y, void* font, const char* text)
{
    glPushMatrix();
    glTranslatef(-0.95f, y, 0.0f);
    glScalef(0.0015f, 0.0015f, 1.0f);
    glutStrokeString(font, reinterpret_cast<const unsigned char*>(text));
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);
    float y = 0.85f;
    for (const auto& entry : bitmapFonts) {
        renderBitmapLine(y, entry.font, entry.label);
        y -= 0.2f;
    }

    glColor3f(0.4f, 0.9f, 1.0f);
    for (const auto& entry : strokeFonts) {
        renderStrokeLine(y, entry.font, entry.label);
        y -= 0.3f;
    }

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("GLUT Font Examples");

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
