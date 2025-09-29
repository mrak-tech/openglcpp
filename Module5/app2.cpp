#include <GL/freeglut.h>
#include <cstdlib>
#include <cmath>
#include <string>

// Functions demonstrated: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
// glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc, glutMouseFunc,
// glutMotionFunc, glutTimerFunc, glutPostRedisplay

float lanternGlow = 0.3f;
bool glowIncreasing = true;
bool glowPaused = false;
bool dragging = false;
bool fullScreen = false;
float dragX = 0.0f;
float dragY = 0.0f;
float stallColor[3] = {0.7f, 0.2f, 0.2f};

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void drawLantern(float x, float y, float glow)
{
    glColor3f(glow, glow * 0.6f, 0.1f + glow * 0.4f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 24; ++i) {
        float angle = (static_cast<float>(i) / 24.0f) * 6.28318f;
        glVertex2f(x + std::cos(angle) * 0.08f, y + std::sin(angle) * 0.08f);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(stallColor);
    glBegin(GL_QUADS);
        glVertex2f(-0.9f, -0.1f);
        glVertex2f( 0.9f, -0.1f);
        glVertex2f( 0.8f, -0.6f);
        glVertex2f(-0.8f, -0.6f);
    glEnd();

    drawLantern(-0.5f + dragX, 0.45f + dragY, lanternGlow);
    drawLantern(0.0f  + dragX, 0.50f + dragY, lanternGlow);
    drawLantern(0.5f + dragX, 0.42f + dragY, lanternGlow);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.9f, "App2: Night Market");
    drawText(-0.95f, 0.74f, "Drag left button: move lantern string");
    drawText(-0.95f, 0.58f, "Right click: random stall color");
    drawText(-0.95f, 0.42f, "Space: pause/resume glow");
    drawText(-0.95f, 0.26f, "F: toggle fullscreen, Esc: quit");

    glutSwapBuffers();
}

void glowTimer(int)
{
    if (!glowPaused) {
        if (glowIncreasing) {
            lanternGlow += 0.02f;
            if (lanternGlow > 0.8f) {
                lanternGlow = 0.8f;
                glowIncreasing = false;
            }
        } else {
            lanternGlow -= 0.02f;
            if (lanternGlow < 0.2f) {
                lanternGlow = 0.2f;
                glowIncreasing = true;
            }
        }
        glutPostRedisplay();
    }

    glutTimerFunc(80, glowTimer, 0); // Glow update using glutTimerFunc
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ': // pause/resume
        glowPaused = !glowPaused;
        break;
    case 'f':
    case 'F':
        if (!fullScreen) {
            glutFullScreen();
            fullScreen = true;
        } else {
            fullScreen = false;
            glutReshapeWindow(900, 600);
            glutPositionWindow(100, 80);
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

void handleMouse(int button, int state, int, int)
{
    if (button == GLUT_LEFT_BUTTON) {
        dragging = (state == GLUT_DOWN);
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        stallColor[0] = static_cast<float>(std::rand() % 100) / 100.0f;
        stallColor[1] = static_cast<float>(std::rand() % 100) / 100.0f;
        stallColor[2] = static_cast<float>(std::rand() % 100) / 100.0f;
        glutPostRedisplay();
    }
}

void handleMotion(int x, int y)
{
    if (!dragging) {
        return;
    }

    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    dragX = (static_cast<float>(x) / w) * 2.0f - 1.0f;
    dragY = 1.0f - (static_cast<float>(y) / h) * 2.0f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("App2 - Night Market");

    glClearColor(0.0f, 0.0f, 0.05f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // Keyboard input via glutKeyboardFunc
    glutMouseFunc(handleMouse);       // Mouse button input via glutMouseFunc
    glutMotionFunc(handleMotion);     // Drag motion via glutMotionFunc
    glutTimerFunc(0, glowTimer, 0);    // Start lantern glow updates

    glutMainLoop();
    return 0;
}
