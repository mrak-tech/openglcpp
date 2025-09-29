#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.5f, 0.2f);
    glRasterPos2f(-0.6f, 0.0f);
    const unsigned char text[] = "glutInit example";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);             // Initialize GLUT state using command line args
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("glutInit Sample");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
