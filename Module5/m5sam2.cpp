#include <GL/freeglut.h>

void renderText()
{
    const unsigned char text[] = "Hello, GLUT!";
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.5f, 0.0f);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, text);
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderText();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Basic glutBitmapString");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
