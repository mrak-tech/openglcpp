#include <GL/freeglut.h>

bool showFirstMessage = true;

void renderText(float x, float y, void* font, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (showFirstMessage) {
        glColor3f(0.2f, 0.8f, 0.4f);
        renderText(-0.7f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Frame 1: Waiting for redisplay");
    } else {
        glColor3f(0.8f, 0.4f, 0.8f);
        renderText(-0.7f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Frame 2: glutPostRedisplay() called");
    }

    glFlush();
}

void timer(int)
{
    showFirstMessage = !showFirstMessage;
    glutPostRedisplay();           // Ask GLUT to redraw using the new state
    glutTimerFunc(1000, timer, 0); // Repeat every second
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("glutPostRedisplay Example");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
