#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.7f, 1.0f);
    glRasterPos2f(-0.8f, 0.0f);
    const unsigned char text[] = "glutCreateWindow(\"GLUT Window\")";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("GLUT Window");  // Create the actual window with a title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
