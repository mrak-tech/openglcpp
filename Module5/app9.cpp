#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Design: "Mountain Dawn" - scenery with drifting clouds and a rising sun.
// Functions: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
//            glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc,
//            glutMouseFunc, glutMotionFunc, glutTimerFunc, glutPostRedisplay

float cloudOffset = 0.0f;
bool animateCloud = true;
bool draggingCloud = false;
bool fullScreen = false;
float cloudDragX = 0.0f;
float cloudDragY = 0.6f;

float sunProgress = 0.0f; // 0 = behind mountains, 1 = high in the sky
bool animateSun = true;

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void drawSun()
{
    const float sunX = -0.6f;
    const float sunY = -0.15f + sunProgress * 0.9f;
    const float sunRadius = 0.15f;

    float r = 0.9f + 0.1f * sunProgress;
    float g = 0.75f + 0.2f * sunProgress;
    float b = 0.3f + 0.05f * sunProgress;

    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sunX, sunY);
    for (int i = 0; i <= 48; ++i) {
        float angle = (static_cast<float>(i) / 48.0f) * 6.28318f;
        glVertex2f(sunX + std::cos(angle) * sunRadius,
                   sunY + std::sin(angle) * sunRadius);
    }
    glEnd();
}

void drawMountains()
{
    glColor3f(0.25f, 0.35f, 0.3f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f( 0.2f, -0.2f);

        glVertex2f(-0.3f, -0.2f);
        glVertex2f( 0.3f, 0.5f);
        glVertex2f( 0.9f, -0.2f);
    glEnd();

    glColor3f(0.6f, 0.8f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.2f);
        glVertex2f(-1.0f, -0.2f);
    glEnd();
}

void drawBird(float cx, float cy, float scale)
{
    glBegin(GL_LINES);
        glVertex2f(cx - 0.05f * scale, cy);
        glVertex2f(cx, cy + 0.03f * scale);

        glVertex2f(cx, cy + 0.03f * scale);
        glVertex2f(cx + 0.05f * scale, cy);
    glEnd();
}

void drawBirds()
{
    glColor3f(0.1f, 0.1f, 0.15f);
    drawBird(-0.2f, 0.65f, 1.0f);
    drawBird(0.05f, 0.78f, 0.8f);
    drawBird(0.35f, 0.70f, 1.1f);
}

void drawCloud()
{
    float cx = cloudDragX + cloudOffset;
    float cy = cloudDragY;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 32; ++i) {
        float angle = (static_cast<float>(i) / 32.0f) * 6.28318f;
        glVertex2f(cx + std::cos(angle) * 0.25f,
                   cy + std::sin(angle) * 0.12f);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx + 0.25f, cy + 0.05f);
    for (int i = 0; i <= 32; ++i) {
        float angle = (static_cast<float>(i) / 32.0f) * 6.28318f;
        glVertex2f(cx + 0.25f + std::cos(angle) * 0.18f,
                   cy + 0.05f + std::sin(angle) * 0.10f);
    }
    glEnd();
}

void display()
{
    float skyR = 0.35f + 0.3f * sunProgress;
    float skyG = 0.45f + 0.35f * sunProgress;
    float skyB = 0.65f + 0.3f * sunProgress;
    glClearColor(skyR, skyG, skyB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun();
    drawMountains();
    drawCloud();
    drawBirds();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.9f, "App9: Mountain Dawn");
    drawText(-0.95f, 0.75f, "Space: pause/resume cloud & sun");
    drawText(-0.95f, 0.60f, "Drag cloud with left button");
    drawText(-0.95f, 0.45f, "F: toggle fullscreen, Esc: quit");

    glutSwapBuffers();
}

void timerTick(int)
{
    if (animateCloud && !draggingCloud) {
        cloudOffset += 0.0035f;
        if (cloudOffset > 1.5f) {
            cloudOffset = -1.5f;
        }
    }

    if (animateSun) {
        sunProgress += 0.0018f;
        if (sunProgress > 1.2f) {
            sunProgress = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, timerTick, 0);
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        animateCloud = !animateCloud;
        animateSun = !animateSun;
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
    case 'r':
    case 'R':
        sunProgress = 0.0f;
        cloudOffset = 0.0f;
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

            float cx = cloudDragX + cloudOffset;
            float cy = cloudDragY;
            float dx = nx - cx;
            float dy = ny - cy;
            draggingCloud = (dx * dx + dy * dy) <= (0.3f * 0.3f);
            if (draggingCloud) {
                cloudDragX = nx - cloudOffset;
                cloudDragY = ny;
            }
        } else {
            draggingCloud = false;
        }
    }
}

void handleMotion(int x, int y)
{
    if (!draggingCloud) {
        return;
    }
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    float nx = (static_cast<float>(x) / w) * 2.0f - 1.0f;
    float ny = 1.0f - (static_cast<float>(y) / h) * 2.0f;

    cloudDragX = nx - cloudOffset;
    cloudDragY = ny;
    if (cloudDragY > 0.85f) cloudDragY = 0.85f;
    if (cloudDragY < 0.3f) cloudDragY = 0.3f;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("App9 - Mountain Dawn");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // keyboard controls
    glutMouseFunc(handleMouse);       // mouse press controls
    glutMotionFunc(handleMotion);     // drag controls
    glutTimerFunc(0, timerTick, 0);   // animation timer

    glutMainLoop();
    return 0;
}
