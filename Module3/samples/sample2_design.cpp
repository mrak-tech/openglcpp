#include <GL/glut.h>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(12.0f);

    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -0.6f);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glEnd();

    glLineWidth(4.0f);

    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.0f, 0.3f);

    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, 0.0f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.3f);

    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -0.6f);

    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.3f, 0.0f);

    glVertex2f(-0.3f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.3f, 0.0f);

    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 2 Design (Points + Lines)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
