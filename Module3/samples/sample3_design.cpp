#include <GL/glut.h>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.6f, 0.4f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 3 Design (Line Strip)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
