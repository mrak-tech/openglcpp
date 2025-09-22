
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.5, 0.0); // Orange line

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.9, -0.8);
    glVertex2f(-0.6, 0.3);
    glVertex2f(-0.3, -0.5);
    glVertex2f(0.0, 0.6);
    glVertex2f(0.3, -0.4);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.9, -0.7);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("GL_LINE_STRIP - Zigzag");
    glClearColor(0.1, 0.1, 0.1, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
