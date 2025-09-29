#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.9f, 0.1f);
    const unsigned char text[] = "This window uses glutFullScreen()";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

void keyboard(unsigned char key, int, int)
{
    if (key == 27) { // Escape key to exit fullscreen and terminate
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fullscreen Example");

    glutFullScreen(); // Switch to fullscreen mode

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
