
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0); // Magenta loop

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 0.8);   // Top
    glVertex2f(0.8, 0.0);   // Right
    glVertex2f(0.0, -0.8);  // Bottom
    glVertex2f(-0.8, 0.0);  // Left
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("GL_LINE_LOOP - Diamond");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
