#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.9f, 0.3f, 0.3f);
    glRasterPos2f(-0.8f, 0.0f);
    const unsigned char text[] = "glutInitWindowSize(640, 480)";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);     // Request a 640x480 window
    glutCreateWindow("glutInitWindowSize Example");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
