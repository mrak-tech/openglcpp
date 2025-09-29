#include <GL/freeglut.h>
#include <string>

float bgColor[3] = {0.1f, 0.1f, 0.2f};
float lastClickX = 0.0f;
float lastClickY = 0.0f;
std::string message = "Click anywhere";

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
    drawText(-0.95f, 0.85f, "Left click: record position");
    drawText(-0.95f, 0.70f, "Right click: toggle background");
    drawText(-0.95f, 0.55f, "Middle click: reset");
    drawText(-0.95f, -0.10f, "Size +/- keys resize text position display");
    drawText(-0.95f, -0.25f, "Esc quits");

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Last click at %.2f, %.2f", lastClickX, lastClickY);
    drawText(-0.95f, 0.25f, buffer);

    drawText(-0.95f, 0.40f, message.c_str());

    glFlush();
}

void handleMouse(int button, int state, int x, int y)
{
    if (state != GLUT_DOWN) {
        return;
    }

    // Convert window coordinates to normalized device coordinates [-1, 1]
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    lastClickX = (static_cast<float>(x) / width) * 2.0f - 1.0f;
    lastClickY = 1.0f - (static_cast<float>(y) / height) * 2.0f;

    switch (button) {
    case GLUT_LEFT_BUTTON:
        message = "Left button pressed";
        break;
    case GLUT_RIGHT_BUTTON:
        message = "Right button pressed";
        if (bgColor[0] < 0.5f) {
            bgColor[0] = bgColor[1] = bgColor[2] = 0.8f;
        } else {
            bgColor[0] = 0.1f;
            bgColor[1] = 0.1f;
            bgColor[2] = 0.2f;
        }
        glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
        break;
    case GLUT_MIDDLE_BUTTON:
        message = "Middle button pressed - reset";
        lastClickX = 0.0f;
        lastClickY = 0.0f;
        bgColor[0] = 0.1f;
        bgColor[1] = 0.1f;
        bgColor[2] = 0.2f;
        glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
        break;
    default:
        message = "Unknown button";
        break;
    }

    glutPostRedisplay();
}

void handleKeyboard(unsigned char key, int, int)
{
    if (key == '+') {
        lastClickX = (lastClickX + 0.1f > 1.0f) ? 1.0f : lastClickX + 0.1f;
        lastClickY = (lastClickY + 0.1f > 1.0f) ? 1.0f : lastClickY + 0.1f;
    } else if (key == '-') {
        lastClickX = (lastClickX - 0.1f < -1.0f) ? -1.0f : lastClickX - 0.1f;
        lastClickY = (lastClickY - 0.1f < -1.0f) ? -1.0f : lastClickY - 0.1f;
    } else if (key == 27) {
        glutLeaveMainLoop();
        return;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 500);
    glutCreateWindow("glutMouseFunc demo");

    glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);       // Demonstrating glutMouseFunc callback registration
    glutKeyboardFunc(handleKeyboard); // Additional keyboard interactions

    glutMainLoop();
    return 0;
}
