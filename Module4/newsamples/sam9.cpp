
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.35, 0.05); // Wooden brown

    // Draw the two vertical sides of the ladder
    glBegin(GL_QUADS);
    // Left side
    glVertex2f(-0.3, -0.9);
    glVertex2f(-0.2, -0.9);
    glVertex2f(-0.2, 0.9);
    glVertex2f(-0.3, 0.9);

    // Right side
    glVertex2f(0.2, -0.9);
    glVertex2f(0.3, -0.9);
    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.9);
    glEnd();

    // Draw the rungs
    glBegin(GL_QUADS);
    // Rung 1
    glVertex2f(-0.2, -0.6);
    glVertex2f(0.2, -0.6);
    glVertex2f(0.2, -0.5);
    glVertex2f(-0.2, -0.5);

    // Rung 2
    glVertex2f(-0.2, -0.3);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.2, -0.2);
    glVertex2f(-0.2, -0.2);

    // Rung 3
    glVertex2f(-0.2, 0.0);
    glVertex2f(0.2, 0.0);
    glVertex2f(0.2, 0.1);
    glVertex2f(-0.2, 0.1);

    // Rung 4
    glVertex2f(-0.2, 0.3);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, 0.4);
    glVertex2f(-0.2, 0.4);

    // Rung 5
    glVertex2f(-0.2, 0.6);
    glVertex2f(0.2, 0.6);
    glVertex2f(0.2, 0.7);
    glVertex2f(-0.2, 0.7);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Fixed Ladder");
    glClearColor(1.0, 1.0, 0.8, 0.0); // Light yellow background
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
