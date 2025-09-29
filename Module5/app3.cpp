#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Functions demonstrated: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
// glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc, glutMouseFunc,
// glutMotionFunc, glutTimerFunc, glutPostRedisplay

float dialAngle = 0.0f;
bool dialForward = true;
bool paused = false;
bool grabbingSlider = false;
bool isFullScreen = false;
float sliderValue = 0.0f;
float bgShade = 0.1f;

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void drawGauge()
{
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 50; ++i) {
        float angle = (-135.0f + i * (270.0f / 50.0f)) * 3.14159f / 180.0f;
        glVertex2f(std::cos(angle) * 0.5f, std::sin(angle) * 0.5f);
    }
    glEnd();

    float angleRad = (-135.0f + dialAngle) * 3.14159f / 180.0f;
    glColor3f(1.0f, 0.3f, 0.3f);
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(std::cos(angleRad) * 0.45f, std::sin(angleRad) * 0.45f);
    glEnd();
}

void drawSlider()
{
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, -0.7f);
        glVertex2f( 0.6f, -0.7f);
        glVertex2f( 0.6f, -0.75f);
        glVertex2f(-0.6f, -0.75f);
    glEnd();

    float knobX = -0.6f + (sliderValue + 1.0f) * 0.3f;
    glColor3f(0.2f, 0.8f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(knobX - 0.05f, -0.68f);
        glVertex2f(knobX + 0.05f, -0.68f);
        glVertex2f(knobX + 0.05f, -0.77f);
        glVertex2f(knobX - 0.05f, -0.77f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGauge();
    drawSlider();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.90f, "App3: Retro Dashboard");
    drawText(-0.95f, 0.75f, "Space: pause/resume dial");
    drawText(-0.95f, 0.60f, "Drag slider with left button");
    drawText(-0.95f, 0.45f, "R: reset, B: darker bg, F: fullscreen");
    drawText(-0.95f, -0.88f, "Esc: quit");

    glutSwapBuffers();
}

void timerTick(int)
{
    if (!paused) {
        if (dialForward) {
            dialAngle += 3.0f;
            if (dialAngle >= 270.0f) {
                dialAngle = 270.0f;
                dialForward = false;
            }
        } else {
            dialAngle -= 3.0f;
            if (dialAngle <= 0.0f) {
                dialAngle = 0.0f;
                dialForward = true;
            }
        }
        glutPostRedisplay();
    }

    glutTimerFunc(40, timerTick, 0); // Periodic update with glutTimerFunc
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        paused = !paused;
        break;
    case 'r':
    case 'R':
        dialAngle = 0.0f;
        dialForward = true;
        sliderValue = 0.0f;
        break;
    case 'b':
    case 'B':
        bgShade += 0.05f;
        if (bgShade > 0.3f) {
            bgShade = 0.1f;
        }
        glClearColor(bgShade, bgShade, bgShade + 0.05f, 1.0f);
        break;
    case 'f':
    case 'F':
        if (!isFullScreen) {
            glutFullScreen();
            isFullScreen = true;
        } else {
            isFullScreen = false;
            glutReshapeWindow(800, 600);
            glutPositionWindow(120, 60);
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
        grabbingSlider = (state == GLUT_DOWN);
    }
}

void handleMotion(int x, int y)
{
    if (!grabbingSlider) {
        return;
    }

    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    float nx = (static_cast<float>(x) / w) * 2.0f - 1.0f;
    float ny = 1.0f - (static_cast<float>(y) / h) * 2.0f;

    if (ny < -0.6f && ny > -0.85f) {
        sliderValue = nx;
        if (sliderValue > 1.0f) sliderValue = 1.0f;
        if (sliderValue < -1.0f) sliderValue = -1.0f;
        dialAngle = (sliderValue + 1.0f) * 135.0f; // map [-1,1] to [0,270]
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("App3 - Retro Dashboard");

    glClearColor(bgShade, bgShade, bgShade + 0.05f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // Keyboard input hook
    glutMouseFunc(handleMouse);       // Mouse button hook
    glutMotionFunc(handleMotion);     // Dragging hook
    glutTimerFunc(0, timerTick, 0);   // Start dial updates

    glutMainLoop();
    return 0;
}
