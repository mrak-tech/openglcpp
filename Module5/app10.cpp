#include <GL/freeglut.h>
#include <cstdlib>
#include <cmath>
#include <string>

// Design: "Night Sky Trail" - starry sky with drifting comet trails.
// Functions: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
//            glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc,
//            glutMouseFunc, glutMotionFunc, glutTimerFunc, glutPostRedisplay

constexpr int STAR_COUNT = 80;
float stars[STAR_COUNT][2];

float cometX = -1.2f;
float cometY = 0.45f;
float cometSpeed = 0.005f;
bool animateScene = true;
bool dragComet = false;
bool fullScreen = false;

void initStars()
{
    for (int i = 0; i < STAR_COUNT; ++i) {
        stars[i][0] = static_cast<float>(std::rand() % 200 - 100) / 100.0f; // -1..1
        stars[i][1] = static_cast<float>(std::rand() % 100) / 100.0f * 1.8f - 0.1f;  // -0.1..0.8
    }
}

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void drawStars()
{
    glColor3f(0.9f, 0.9f, 1.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < STAR_COUNT; ++i) {
        glVertex2f(stars[i][0], stars[i][1]);
    }
    glEnd();
}

void drawComet()
{
    glColor3f(0.8f, 0.9f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cometX, cometY);
        for (int i = 0; i <= 20; ++i) {
            float angle = (static_cast<float>(i) / 20.0f) * 6.28318f;
            glVertex2f(cometX + std::cos(angle) * 0.03f,
                       cometY + std::sin(angle) * 0.03f);
        }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.3f, 0.5f, 0.9f);
        glVertex2f(cometX, cometY);
        glVertex2f(cometX - 0.12f, cometY + 0.02f);
        glVertex2f(cometX - 0.12f, cometY - 0.02f);

        glColor3f(0.1f, 0.2f, 0.4f);
        glVertex2f(cometX - 0.22f, cometY + 0.05f);
        glVertex2f(cometX - 0.22f, cometY - 0.05f);
    glEnd();
}

void display()
{
    glClearColor(0.02f, 0.03f, 0.08f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawStars();
    drawComet();

    glColor3f(0.8f, 0.85f, 1.0f);
    drawText(-0.95f, 0.92f, "App10: Night Sky Trail");
    drawText(-0.95f, 0.78f, "Space: pause/resume comet");
    drawText(-0.95f, 0.64f, "Drag comet with left button");
    drawText(-0.95f, 0.50f, "R: reset, F: fullscreen, Esc: quit");

    glutSwapBuffers();
}

void timerTick(int)
{
    if (animateScene && !dragComet) {
        cometX += cometSpeed;
        cometY -= cometSpeed * 0.15f;
        if (cometX > 1.3f) {
            cometX = -1.2f;
            cometY = 0.45f + static_cast<float>(std::rand() % 40) / 100.0f; // vary path
        }
        glutPostRedisplay();
    }

    glutTimerFunc(16, timerTick, 0);
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        animateScene = !animateScene;
        break;
    case 'r':
    case 'R':
        cometX = -1.2f;
        cometY = 0.45f;
        animateScene = true;
        break;
    case 'f':
    case 'F':
        if (!fullScreen) {
            glutFullScreen();
            fullScreen = true;
        } else {
            fullScreen = false;
            glutReshapeWindow(900, 600);
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
            int w = glutGet(GLUT_WINDOW_WIDTH);
            int h = glutGet(GLUT_WINDOW_HEIGHT);
            float nx = (static_cast<float>(x) / w) * 2.0f - 1.0f;
            float ny = 1.0f - (static_cast<float>(y) / h) * 2.0f;

            float dx = nx - cometX;
            float dy = ny - cometY;
            dragComet = (dx * dx + dy * dy) <= 0.035f * 0.035f;
            if (dragComet) {
                cometX = nx;
                cometY = ny;
            }
        } else {
            dragComet = false;
        }
        glutPostRedisplay();
    }
}

void handleMotion(int x, int y)
{
    if (!dragComet) {
        return;
    }
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    cometX = (static_cast<float>(x) / w) * 2.0f - 1.0f;
    cometY = 1.0f - (static_cast<float>(y) / h) * 2.0f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("App10 - Night Sky Trail");

    initStars();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // keyboard controls
    glutMouseFunc(handleMouse);       // mouse controls
    glutMotionFunc(handleMotion);     // drag controls
    glutTimerFunc(0, timerTick, 0);   // animation timer

    glutMainLoop();
    return 0;
}
