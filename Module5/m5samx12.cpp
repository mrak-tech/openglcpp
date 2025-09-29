#include <GL/freeglut.h>

float alpha = 1.0f;
bool fadingOut = true;
bool timerRunning = true;

void drawQuad()
{
    glColor4f(0.2f, 0.6f, 1.0f, alpha);
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();
}

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawQuad();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Timer adjusts alpha every 50 ms");
    drawText(-0.95f, 0.70f, "Press space to pause/resume, Esc to quit");
    drawText(-0.95f, 0.55f, "Press R to reset alpha");

    glutSwapBuffers();
}

void updateAlpha(int)
{
    if (timerRunning) {
        const float step = 0.05f;
        if (fadingOut) {
            alpha -= step;
            if (alpha <= 0.2f) {
                alpha = 0.2f;
                fadingOut = false;
            }
        } else {
            alpha += step;
            if (alpha >= 1.0f) {
                alpha = 1.0f;
                fadingOut = true;
            }
        }
        glutPostRedisplay();
    }

    glutTimerFunc(50, updateAlpha, 0); // Demonstrating glutTimerFunc scheduling repeated alpha updates
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        timerRunning = !timerRunning;
        break;
    case 'r':
    case 'R':
        alpha = 1.0f;
        fadingOut = true;
        timerRunning = true;
        break;
    case 27:
        glutLeaveMainLoop();
        return;
    default:
        return;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
    glutInitWindowSize(640, 480);
    glutCreateWindow("glutTimerFunc alpha fade");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND); // Enable blending so alpha values affect rendering
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutTimerFunc(0, updateAlpha, 0); // Kick off timer loop with glutTimerFunc

    glutMainLoop();
    return 0;
}
