#include <GL/glut.h>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(0.9f, 0.3f, 0.3f);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.1f, -0.4f);
    glVertex2f(-0.35f, 0.4f);

    glColor3f(0.2f, 0.5f, 0.8f);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.6f, -0.4f);
    glVertex2f(0.35f, 0.4f);

    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 6 Design (Triangles)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
