#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Design: "Bouncing Ball Horizon" — simple ball rolling under a gradient sky.
// Functions: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
//            glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc,
//            glutMouseFunc, glutMotionFunc, glutTimerFunc, glutPostRedisplay

float ballX = -0.9f;
float ballY = -0.25f;
float ballSpeed = 0.01f;
bool paused = false;
bool dragging = false;
bool fullScreen = false;

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void display()
{
    float skyR = 0.6f;
    float skyG = 0.65f;
    float skyB = 0.9f;
    glClearColor(skyR, skyG, skyB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3f, 0.7f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.3f);
        glVertex2f(-1.0f, -0.3f);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(ballX, ballY);
    for (int i = 0; i <= 36; ++i) {
        float angle = (static_cast<float>(i) / 36.0f) * 6.28318f;
        glVertex2f(ballX + std::cos(angle) * 0.12f, ballY + std::sin(angle) * 0.12f);
    }
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.90f, "App5: Bouncing Ball Horizon");
    drawText(-0.95f, 0.75f, "Space: pause/resume");
    drawText(-0.95f, 0.60f, "Drag ball with left mouse");
    drawText(-0.95f, 0.45f, "F: fullscreen, Esc: quit");

    glutSwapBuffers();
}

void timerTick(int)
{
    if (!paused && !dragging) {
        ballX += ballSpeed;
        if (ballX > 0.9f || ballX < -0.9f) {
            ballSpeed = -ballSpeed;
            ballX += ballSpeed;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, timerTick, 0);
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        paused = !paused;
        break;
    case 'f':
    case 'F':
        if (!fullScreen) {
            glutFullScreen();
            fullScreen = true;
        } else {
            fullScreen = false;
            glutReshapeWindow(800, 600);
            glutPositionWindow(100, 60);
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
            int w = glutGet(GLUT_WINDOW_WIDTH);
            int h = glutGet(GLUT_WINDOW_HEIGHT);
            float nx = (static_cast<float>(x) / w) * 2.0f - 1.0f;
            float ny = 1.0f - (static_cast<float>(y) / h) * 2.0f;
            float dx = nx - ballX;
            float dy = ny - ballY;
            dragging = (dx * dx + dy * dy) <= 0.12f * 0.12f;
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
    ballX = (static_cast<float>(x) / w) * 2.0f - 1.0f;
    ballY = 1.0f - (static_cast<float>(y) / h) * 2.0f;
    if (ballY < -0.25f) ballY = -0.25f;
    if (ballY > 0.8f) ballY = 0.8f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("App5 - Bouncing Ball Horizon");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // keyboard control
    glutMouseFunc(handleMouse);       // mouse button control
    glutMotionFunc(handleMotion);     // drag control
    glutTimerFunc(0, timerTick, 0);   // timer updates

    glutMainLoop();
    return 0;
}
