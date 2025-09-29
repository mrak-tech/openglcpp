#include <GL/freeglut.h>
#include <string>

float cursorX = 0.0f;
float cursorY = 0.0f;
bool isLeftDown = false;
std::string message = "Drag with left mouse button";

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
    drawText(-0.95f, 0.85f, "Drag the mouse: tracks normalized position");
    drawText(-0.95f, 0.70f, "Press R to reset, Esc to quit");

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Current cursor: %.2f, %.2f", cursorX, cursorY);
    drawText(-0.95f, 0.40f, buffer);
    drawText(-0.95f, 0.25f, message.c_str());

    glColor3f(0.2f, 0.8f, 0.4f);
    glPointSize(8.0f);
    glBegin(GL_POINTS);
        glVertex2f(cursorX, cursorY);
    glEnd();

    glFlush();
}

void handleMouse(int button, int state, int, int)
{
    if (button == GLUT_LEFT_BUTTON) {
        isLeftDown = (state == GLUT_DOWN);
        message = isLeftDown ? "Dragging active" : "Drag with left mouse button";
    }
}

void handleMotion(int x, int y)
{
    if (!isLeftDown) {
        return;
    }

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    cursorX = (static_cast<float>(x) / width) * 2.0f - 1.0f;
    cursorY = 1.0f - (static_cast<float>(y) / height) * 2.0f;

    glutPostRedisplay();
}

void handleKeyboard(unsigned char key, int, int)
{
    if (key == 'r' || key == 'R') {
        cursorX = 0.0f;
        cursorY = 0.0f;
        message = "Position reset";
        glutPostRedisplay();
    } else if (key == 27) {
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480);
    glutCreateWindow("glutMotionFunc demo");

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);
    glutMotionFunc(handleMotion);     // Demonstrating glutMotionFunc registering motion callback
    glutKeyboardFunc(handleKeyboard);

    glutMainLoop();
    return 0;
}
