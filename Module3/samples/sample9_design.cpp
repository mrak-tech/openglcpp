#include <GL/glut.h>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.7f, 0.5f);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.5f, -0.3f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.5f, -0.3f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.35f, 0.05f);
    glVertex2f(0.35f, 0.05f);

    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, 0.4f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 9 Design (Quads)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
