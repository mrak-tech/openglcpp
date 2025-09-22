#include <GL/glut.h>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(0.0f, -0.6f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 4 Design (Line Loop)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
