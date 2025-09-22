#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Green lines

    glBegin(GL_LINES);
    // Left vertical
    glVertex2f(-0.5, -0.8);
    glVertex2f(-0.5, 0.8);
    // Right vertical
    glVertex2f(0.5, -0.8);
    glVertex2f(0.5, 0.8);
    // Horizontal crossbar
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("GL_LINES - Letter H");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
