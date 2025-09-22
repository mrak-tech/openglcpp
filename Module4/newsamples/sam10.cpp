
#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red stop sign

    glBegin(GL_POLYGON);
    for (int i = 0; i < 8; i++) {
        float angle = i * (2.0 * M_PI / 8.0) + M_PI / 8.0; // Rotate 22.5° to align flat side down
        glVertex2f(0.7 * cos(angle), 0.7 * sin(angle));
    }
    glEnd();

    // Optional: White "STOP" text simulated with white polygon center
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 8; i++) {
        float angle = i * (2.0 * M_PI / 8.0) + M_PI / 8.0;
        glVertex2f(0.4 * cos(angle), 0.4 * sin(angle));
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("GL_POLYGON - Stop Sign");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
