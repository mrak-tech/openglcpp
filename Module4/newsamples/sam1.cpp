
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // Yellow points

    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.3, 0.4);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.5, -0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.0, 0.8);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("GL_POINTS - Starfield");
    glClearColor(0.0, 0.0, 0.2, 0.0); // Dark blue background
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

