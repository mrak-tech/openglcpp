#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Design: "Calm Pond Ripples" — gentle ripples expanding outwards.
// Functions: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
//            glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc,
//            glutMouseFunc, glutMotionFunc, glutTimerFunc, glutPostRedisplay

float rippleRadius = 0.05f;
bool rippleActive = true;
bool dragging = false;
bool fullScreen = false;
float centerX = 0.0f;
float centerY = 0.0f;

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void drawRipples()
{
    glColor3f(0.6f, 0.8f, 0.9f);
    for (int r = 0; r < 5; ++r) {
        float radius = rippleRadius + r * 0.08f;
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 60; ++i) {
            float angle = (static_cast<float>(i) / 60.0f) * 6.28318f;
            glVertex2f(centerX + std::cos(angle) * radius,
                       centerY + std::sin(angle) * radius);
        }
        glEnd();
    }
}

void display()
{
    glClearColor(0.0f, 0.15f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawRipples();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.9f, "App6: Calm Pond Ripples");
    drawText(-0.95f, 0.75f, "Space: pause/resume");
    drawText(-0.95f, 0.60f, "Drag to move ripple center");
    drawText(-0.95f, 0.45f, "F: fullscreen, Esc: quit");

    glutSwapBuffers();
}

void timerTick(int)
{
    if (rippleActive) {
        rippleRadius += 0.01f;
        if (rippleRadius > 0.2f) {
            rippleRadius = 0.05f;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(50, timerTick, 0);
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        rippleActive = !rippleActive;
        break;
    case 'f':
    case 'F':
        if (!fullScreen) {
            glutFullScreen();
            fullScreen = true;
        } else {
            fullScreen = false;
            glutReshapeWindow(800, 600);
            glutPositionWindow(120, 80);
        }
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
        if (state == GLUT_DOWN) {
            dragging = true;
            int w = glutGet(GLUT_WINDOW_WIDTH);
            int h = glutGet(GLUT_WINDOW_HEIGHT);
            centerX = (static_cast<float>(x) / w) * 2.0f - 1.0f;
            centerY = 1.0f - (static_cast<float>(y) / h) * 2.0f;
        } else {
            dragging = false;
        }
    }
}

void handleMotion(int x, int y)
{
    if (!dragging) {
        return;
    }
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    centerX = (static_cast<float>(x) / w) * 2.0f - 1.0f;
    centerY = 1.0f - (static_cast<float>(y) / h) * 2.0f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("App6 - Calm Pond Ripples");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // keyboard input
    glutMouseFunc(handleMouse);       // mouse clicks
    glutMotionFunc(handleMotion);     // dragging updates center
    glutTimerFunc(0, timerTick, 0);   // ripple animation

    glutMainLoop();
    return 0;
}
