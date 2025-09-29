#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Functions demonstrated: glutInit, glutInitDisplayMode, glutInitWindowSize, glutCreateWindow,
// glutFullScreen, glRasterPos2f, glutBitmapString, glutKeyboardFunc, glutMouseFunc,
// glutMotionFunc, glutTimerFunc, glutPostRedisplay

float dayProgress = 0.0f; // 0 dawn, 1 dusk
bool paused = false;
bool draggingSun = false;
bool fullScreen = false;

float sunX = -0.9f;
float sunY = -0.3f;

void updateSunPosition()
{
    const float angle = dayProgress * 3.14159f; // sunrise to sunset
    sunX = -0.9f + dayProgress * 1.8f;
    sunY = std::sin(angle) * 0.7f - 0.3f;
}

void drawText(float x, float y, const std::string& text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text.c_str()));
}

void drawSun()
{
    glColor3f(1.0f, 0.8f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sunX, sunY);
    for (int i = 0; i <= 36; ++i) {
        float angle = (static_cast<float>(i) / 36.0f) * 6.28318f;
        glVertex2f(sunX + std::cos(angle) * 0.12f, sunY + std::sin(angle) * 0.12f);
    }
    glEnd();
}

void drawGround()
{
    glColor3f(0.1f, 0.35f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.35f);
        glVertex2f(-1.0f, -0.35f);
    glEnd();
}

void display()
{
    float skyR = 0.1f + 0.6f * dayProgress;
    float skyG = 0.2f + 0.4f * dayProgress;
    float skyB = 0.5f + 0.2f * (1.0f - std::fabs(dayProgress - 0.5f) * 2.0f);

    if (dayProgress < 0.1f) {
        skyR += 0.3f;
        skyG += 0.1f;
    } else if (dayProgress > 0.9f) {
        skyR += 0.2f;
    }

    glClearColor(skyR, skyG, skyB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawGround();
    drawSun();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.90f, "App4: Sunrise to Sunset");
    drawText(-0.95f, 0.75f, "Space: pause/resume");
    drawText(-0.95f, 0.60f, "R: reset dawn, F: toggle fullscreen");
    drawText(-0.95f, 0.45f, "Left drag sun across the sky");
    drawText(-0.95f, -0.90f, "Esc: quit");

    glutSwapBuffers();
}

void advanceTime(int)
{
    if (!paused) {
        dayProgress += 0.0025f;
        if (dayProgress > 1.0f) {
            dayProgress = 0.0f;
        }
        updateSunPosition();
        glutPostRedisplay();
    }

    glutTimerFunc(16, advanceTime, 0); // ~60 updates per second
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ': // pause
        paused = !paused;
        break;
    case 'r':
    case 'R':
        dayProgress = 0.0f;
        updateSunPosition();
        break;
    case 'f':
    case 'F':
        if (!fullScreen) {
            glutFullScreen();
            fullScreen = true;
        } else {
            fullScreen = false;
            glutReshapeWindow(900, 600);
            glutPositionWindow(80, 60);
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

bool insideSun(float x, float y)
{
    const float dx = x - sunX;
    const float dy = y - sunY;
    return (dx * dx + dy * dy) <= 0.12f * 0.12f;
}

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            int w = glutGet(GLUT_WINDOW_WIDTH);
            int h = glutGet(GLUT_WINDOW_HEIGHT);
            float nx = (static_cast<float>(x) / w) * 2.0f - 1.0f;
            float ny = 1.0f - (static_cast<float>(y) / h) * 2.0f;
            draggingSun = insideSun(nx, ny);
        } else {
            draggingSun = false;
        }
    }
}

void handleMotion(int x, int y)
{
    if (!draggingSun) {
        return;
    }

    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    float nx = (static_cast<float>(x) / w) * 2.0f - 1.0f;

    dayProgress = (nx + 0.9f) / 1.8f;
    if (dayProgress < 0.0f) dayProgress = 0.0f;
    if (dayProgress > 1.0f) dayProgress = 1.0f;

    updateSunPosition();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("App4 - Sunrise to Sunset");

    updateSunPosition();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // Keyboard callback registration
    glutMouseFunc(handleMouse);       // Mouse button callback registration
    glutMotionFunc(handleMotion);     // Mouse drag callback registration
    glutTimerFunc(0, advanceTime, 0); // Start timer loop

    glutMainLoop();
    return 0;
}
