#include <GL/glut.h>

void displayTriangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES); // Start drawing a triangle
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(0.0f, 1.0f, 0.0f); // Top vertex
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(-1.0f, -1.0f, 0.0f); // Bottom-left vertex
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(1.0f, -1.0f, 0.0f); // Bottom-right vertex
    glEnd(); // Finish drawing
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Simple Triangle");
    glutDisplayFunc(displayTriangle);
    glutMainLoop();
    return 0;
}