#include <GL/glut.h>

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glClear(GL_COLOR_BUFFER_BIT);

    /*
        The screen is divided into four quadrants by the X and Y axes:
        - Quadrant 1 (Top-Right):   X is positive (0 to 1), Y is positive (0 to 1)
        - Quadrant 2 (Top-Left):    X is negative (0 to -1), Y is positive (0 to 1)
        - Quadrant 3 (Bottom-Left): X is negative (0 to -1), Y is negative (0 to -1)
        - Quadrant 4 (Bottom-Right): X is positive (0 to 1), Y is negative (0 to -1)
    */

    // --- Draw X and Y Axes ---
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    // X-axis
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    // Y-axis
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();

    // --- Draw an object in each quadrant ---

    // Quadrant 1 (Top-Right): Red Triangle
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.8f, 0.2f);
    glVertex2f(0.5f, 0.8f);
    glEnd();

    // Quadrant 2 (Top-Left): Green Triangle
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.8f, 0.2f);
    glVertex2f(-0.5f, 0.8f);
    glEnd();

    // Quadrant 3 (Bottom-Left): Blue Triangle
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.8f, -0.2f);
    glVertex2f(-0.5f, -0.8f);
    glEnd();

    // Quadrant 4 (Bottom-Right): Yellow Triangle
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.8f, -0.2f);
    glVertex2f(0.5f, -0.8f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Objects in Quadrants");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
