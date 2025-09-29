#include <GL/freeglut.h>

int frame = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);
    glRasterPos2f(-0.9f, 0.1f);

    const char* message = (frame % 2 == 0)
        ? "Frame A: Press space to switch"
        : "Frame B: glutPostRedisplay() ran";

    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(message));

    glFlush();
}

void keyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        frame++;
        glutPostRedisplay(); // Demonstrates requesting a redraw with glutPostRedisplay()
    }
    if (key == 27) {
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("glutPostRedisplay (space toggles)");

    glClearColor(0.05f, 0.05f, 0.15f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
