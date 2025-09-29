#include <GL/freeglut.h>

bool showInstructions = true;

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    if (showInstructions) {
        drawText(-0.85f, 0.2f, "Press space to toggle the message");
    } else {
        drawText(-0.85f, 0.2f, "glutKeyboardFunc handled the key press!");
    }
    drawText(-0.85f, -0.1f, "Press Esc to exit");

    glFlush();
}

void handleKeyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        showInstructions = !showInstructions;
        glutPostRedisplay();
    } else if (key == 27) {
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("glutKeyboardFunc basic example");

    glClearColor(0.0f, 0.0f, 0.15f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // Demonstrating glutKeyboardFunc registering keyboard handler

    glutMainLoop();
    return 0;
}
