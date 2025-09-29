#include <GL/freeglut.h>
#include <cmath>

float angle = 0.0f;
bool animate = true;

void drawRotatingTriangle()
{
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.2f, 0.2f);
        glVertex2f(0.0f, 0.6f);
        glColor3f(0.2f, 0.8f, 0.2f);
        glVertex2f(-0.5f, -0.3f);
        glColor3f(0.2f, 0.2f, 1.0f);
        glVertex2f(0.5f, -0.3f);
    glEnd();

    glPopMatrix();
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

    drawRotatingTriangle();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Timer updates rotation every 16 ms");
    drawText(-0.95f, 0.70f, "Press space to pause/resume, Esc to quit");

    glutSwapBuffers();
}

void updateTimer(int)
{
    if (animate) {
        angle += 2.5f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        glutPostRedisplay();
    }

    glutTimerFunc(16, updateTimer, 0); // Demonstrating glutTimerFunc scheduling a periodic callback
}

void handleKeyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        animate = !animate;
    } else if (key == 27) {
        glutLeaveMainLoop();
        return;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(720, 520);
    glutCreateWindow("glutTimerFunc rotation demo");

    glClearColor(0.05f, 0.05f, 0.10f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutTimerFunc(0, updateTimer, 0); // Start timer loop with glutTimerFunc

    glutMainLoop();
    return 0;
}
