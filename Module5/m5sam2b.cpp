#include <GL/freeglut.h>

void renderText(float x, float y, void* font, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    renderText(-0.8f, 0.5f, GLUT_BITMAP_HELVETICA_18, "Welcome to GLUT text!");

    glColor3f(0.0f, 1.0f, 0.0f);
    renderText(-0.8f, 0.2f, GLUT_BITMAP_9_BY_15, "Bitmap fonts draw on the screen.");

    glColor3f(1.0f, 0.7f, 0.0f);
    renderText(-0.8f, -0.2f, GLUT_BITMAP_TIMES_ROMAN_24, "Change colors, positions, fonts.");

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
    glutInitWindowSize(640, 480);
    glutCreateWindow("Simple GLUT Text Example");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
