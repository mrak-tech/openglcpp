#include <GL/glut.h>

void display() {
    glClearColor(0.2f, 0.2f, 0.3f, 1.0f); // Dark blue background
    glClear(GL_COLOR_BUFFER_BIT);

    // Start drawing triangles
    glBegin(GL_TRIANGLES);
    // Set the color for the triangle to yellow
    glColor3f(1.0f, 1.0f, 0.0f);

    // Define the three vertices of the triangle
    glVertex2f(0.0f, 0.5f); // Top vertex
    glVertex2f(-0.5f, -0.5f); // Bottom-left vertex
    glVertex2f(0.5f, -0.5f); // Bottom-right vertex
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Drawing a Triangle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}