#include <GL/glut.h>

// Simple "Sample 1 Design" using points: a plus (+) shape
void display() {
    // White background
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Black points
    glColor3f(0.0f, 0.0f, 0.0f);

    // Bigger points for visibility
    glPointSize(12.0f);

    glBegin(GL_POINTS);
    // Vertical line of plus
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -0.6f);

    // Horizontal line of plus
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 1 Design (Points)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

