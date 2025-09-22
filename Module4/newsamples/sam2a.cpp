#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Green lines

    glLineWidth(5.0);

    glBegin(GL_LINES);

    // Letter H
    // Left-vertical
    glVertex2f(-0.8, 0.5);
    glVertex2f(-0.8, -0.5);
    // Right-vertical
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.4, -0.5);
    // Horizontal
    glVertex2f(-0.8, 0.0);
    glVertex2f(-0.4, 0.0);

    // Letter J
    // Top-horizontal
    glVertex2f(-0.2, 0.5);
    glVertex2f(0.2, 0.5);
    // Vertical
    glVertex2f(0.0, 0.5);
    glVertex2f(0.0, -0.5);
    // Bottom-horizontal
    glVertex2f(-0.2, -0.5);
    glVertex2f(0.0, -0.5);


    // Letter T
    // Top-horizontal
    glVertex2f(0.4, 0.5);
    glVertex2f(1.0, 0.5);
    // Vertical
    glVertex2f(0.7, 0.5);
    glVertex2f(0.7, -0.5);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("HJT Letters");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.5, 1.5, -1.0, 1.0); // Adjusted ortho for better letter spacing
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
