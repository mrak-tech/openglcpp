#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Functions demonstrated: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
// glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc, glutMouseFunc,
// glutMotionFunc, glutTimerFunc, glutPostRedisplay

float orbitAngle = 0.0f;
bool animate = true;
bool inFullScreen = false;
bool dragging = false;
float planetOffsetX = 0.0f;
float planetOffsetY = 0.0f;
float bgColor[3] = {0.02f, 0.05f, 0.10f};

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void drawScene()
{
    // Sun
    glColor3f(1.0f, 0.8f, 0.1f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= 32; ++i) {
        float angle = (static_cast<float>(i) / 32.0f) * 2.0f * 3.14159f;
        glVertex2f(std::cos(angle) * 0.18f, std::sin(angle) * 0.18f);
    }
    glEnd();

    // Planet orbiting with drag offset
    float radius = 0.55f;
    float px = std::cos(orbitAngle) * radius + planetOffsetX;
    float py = std::sin(orbitAngle) * radius + planetOffsetY;

    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(px, py);
    for (int i = 0; i <= 24; ++i) {
        float angle = (static_cast<float>(i) / 24.0f) * 2.0f * 3.14159f;
        glVertex2f(px + std::cos(angle) * 0.12f, py + std::sin(angle) * 0.12f);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawScene();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.90f, "App1: Orbit Demo");
    drawText(-0.95f, 0.75f, "Space: pause/resume animation");
    drawText(-0.95f, 0.62f, "F: toggle fullscreen");
    drawText(-0.95f, 0.49f, "Left drag: offset orbit");
    drawText(-0.95f, 0.36f, "Right click: reset background");
    drawText(-0.95f, -0.90f, "Esc: quit");

    glutSwapBuffers();
}

void updateTimer(int)
{
    if (animate) {
        orbitAngle += 0.02f;
        if (orbitAngle > 2.0f * 3.14159f) {
            orbitAngle -= 2.0f * 3.14159f;
        }
        glutPostRedisplay();
    }

    glutTimerFunc(16, updateTimer, 0); // 60 FPS approx
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        animate = !animate;
        break;
    case 'f':
    case 'F':
        if (!inFullScreen) {
            glutFullScreen();
            inFullScreen = true;
        } else {
            inFullScreen = false;
            glutReshapeWindow(800, 600);
            glutPositionWindow(50, 50);
        }
        break;
    case 'c':
    case 'C':
        bgColor[0] = 0.05f;
        bgColor[1] = 0.10f;
        bgColor[2] = 0.25f;
        glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
        glutPostRedisplay();
        break;
    case 27:
        glutLeaveMainLoop();
        return;
    default:
        return;
    }

    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        dragging = (state == GLUT_DOWN);
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        bgColor[0] = 0.02f;
        bgColor[1] = 0.05f;
        bgColor[2] = 0.10f;
        glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
        planetOffsetX = 0.0f;
        planetOffsetY = 0.0f;
    }

    glutPostRedisplay();
}

void handleMotion(int x, int y)
{
    if (!dragging) {
        return;
    }

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    planetOffsetX = (static_cast<float>(x) / width) * 2.0f - 1.0f;
    planetOffsetY = 1.0f - (static_cast<float>(y) / height) * 2.0f;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("App1 - Orbit Demo");

    glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // Register keyboard handler
    glutMouseFunc(handleMouse);       // Register mouse handler
    glutMotionFunc(handleMotion);     // Register drag handler
    glutTimerFunc(0, updateTimer, 0); // Start timer updates

    glutMainLoop();
    return 0;
}
