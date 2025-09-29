#include <GL/freeglut.h>

float squareX = 0.0f;
float squareY = 0.0f;
float squareSize = 0.2f;
float color[3] = {0.2f, 0.7f, 1.0f};

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_9_BY_15,
                     reinterpret_cast<const unsigned char*>(text));
}

void drawSquare()
{
    glBegin(GL_QUADS);
        glVertex2f(squareX - squareSize, squareY - squareSize);
        glVertex2f(squareX + squareSize, squareY - squareSize);
        glVertex2f(squareX + squareSize, squareY + squareSize);
        glVertex2f(squareX - squareSize, squareY + squareSize);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(color);
    drawSquare();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Normal keys: R/G/B change color, C resets, Esc quits");
    drawText(-0.95f, 0.70f, "Arrow keys move the square (handled by glutSpecialFunc)");

    glutSwapBuffers();
}

void handleNormalKeys(unsigned char key, int, int)
{
    switch (key) {
    case 'r':
    case 'R':
        color[0] = 1.0f; color[1] = 0.1f; color[2] = 0.1f;
        break;
    case 'g':
    case 'G':
        color[0] = 0.2f; color[1] = 1.0f; color[2] = 0.2f;
        break;
    case 'b':
    case 'B':
        color[0] = 0.2f; color[1] = 0.5f; color[2] = 1.0f;
        break;
    case 'c':
    case 'C':
        color[0] = 0.2f; color[1] = 0.7f; color[2] = 1.0f;
        squareX = 0.0f;
        squareY = 0.0f;
        break;
    case 27:
        glutLeaveMainLoop();
        return;
    default:
        return;
    }

    glutPostRedisplay();
}

void handleSpecialKeys(int key, int, int)
{
    const float step = 0.05f;
    switch (key) {
    case GLUT_KEY_LEFT:
        squareX -= step;
        break;
    case GLUT_KEY_RIGHT:
        squareX += step;
        break;
    case GLUT_KEY_UP:
        squareY += step;
        break;
    case GLUT_KEY_DOWN:
        squareY -= step;
        break;
    default:
        return;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(720, 520);
    glutCreateWindow("glutKeyboardFunc example with movement");

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleNormalKeys); // Demonstrating glutKeyboardFunc registering a normal key handler
    glutSpecialFunc(handleSpecialKeys); // Additional keyboard hook for arrow keys

    glutMainLoop();
    return 0;
}
