
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0); // Cyan fan

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);   // Center
    glVertex2f(0.0, 0.7);   // Top
    glVertex2f(0.5, 0.5);   // Top-right
    glVertex2f(0.7, 0.0);   // Right
    glVertex2f(0.5, -0.5);  // Bottom-right
    glVertex2f(0.0, -0.7);  // Bottom
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("GL_TRIANGLE_FAN - Pie Slice");
    glClearColor(0.3, 0.3, 0.3, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
