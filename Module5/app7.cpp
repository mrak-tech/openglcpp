#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Design: "Campfire Evening" — minimal campfire flicker with drifting spark.
// Functions: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
//            glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc,
//            glutMouseFunc, glutMotionFunc, glutTimerFunc, glutPostRedisplay

float flameHeight = 0.25f;
bool flicker = true;
bool draggingSpark = false;
bool fullScreen = false;
float sparkX = 0.0f;
float sparkY = 0.5f;

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void drawGround()
{
    glColor3f(0.15f, 0.10f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.6f);
        glVertex2f(-1.0f, -0.6f);
    glEnd();
}

void drawFire()
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.9f, 0.4f, 0.1f);
        glVertex2f(-0.15f, -0.6f);
        glVertex2f( 0.15f, -0.6f);
        glColor3f(1.0f, 0.8f, 0.2f);
        glVertex2f(0.0f, -0.6f + flameHeight);
    glEnd();

    glColor3f(0.5f, 0.25f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.6f);
        glVertex2f( 0.2f, -0.6f);
        glVertex2f( 0.25f, -0.7f);
        glVertex2f(-0.25f, -0.7f);
    glEnd();
}

void drawSpark()
{
    glColor3f(1.0f, 0.9f, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sparkX, sparkY);
    for (int i = 0; i <= 20; ++i) {
        float angle = (static_cast<float>(i) / 20.0f) * 6.28318f;
        glVertex2f(sparkX + std::cos(angle) * 0.03f,
                   sparkY + std::sin(angle) * 0.03f);
    }
    glEnd();
}

void display()
{
    glClearColor(0.02f, 0.02f, 0.08f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawGround();
    drawFire();
    drawSpark();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.9f, "App7: Campfire Evening");
    drawText(-0.95f, 0.75f, "Space: pause/resume flicker");
    drawText(-0.95f, 0.60f, "Drag spark with left button");
    drawText(-0.95f, 0.45f, "F: fullscreen, Esc: quit");

    glutSwapBuffers();
}

void timerTick(int)
{
    if (flicker) {
        flameHeight += (std::rand() % 10 - 5) * 0.002f;
        if (flameHeight < 0.20f) flameHeight = 0.20f;
        if (flameHeight > 0.32f) flameHeight = 0.32f;
        glutPostRedisplay();
    }
    glutTimerFunc(70, timerTick, 0);
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        flicker = !flicker;
        break;
    case 'f':
    case 'F':
        if (!fullScreen) {
            glutFullScreen();
            fullScreen = true;
        } else {
            fullScreen = false;
            glutReshapeWindow(800, 600);
            glutPositionWindow(110, 70);
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
            draggingSpark = true;
            int w = glutGet(GLUT_WINDOW_WIDTH);
            int h = glutGet(GLUT_WINDOW_HEIGHT);
            sparkX = (static_cast<float>(x) / w) * 2.0f - 1.0f;
            sparkY = 1.0f - (static_cast<float>(y) / h) * 2.0f;
        } else {
            draggingSpark = false;
        }
    }
}

void handleMotion(int x, int y)
{
    if (!draggingSpark) {
        return;
    }
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    sparkX = (static_cast<float>(x) / w) * 2.0f - 1.0f;
    sparkY = 1.0f - (static_cast<float>(y) / h) * 2.0f;
    if (sparkY < -0.3f) sparkY = -0.3f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("App7 - Campfire Evening");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // keyboard input
    glutMouseFunc(handleMouse);       // mouse input
    glutMotionFunc(handleMotion);     // drag input
    glutTimerFunc(0, timerTick, 0);   // flicker timer

    glutMainLoop();
    return 0;
}
