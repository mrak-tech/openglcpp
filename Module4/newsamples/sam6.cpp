#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red arrow

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.6, 0.0);  // Tail left
    glVertex2f(-0.6, 0.2);  // Tail right
    glVertex2f(0.4, 0.0);   // Tip center
    glVertex2f(0.4, 0.2);   // (completes body)
    glVertex2f(0.8, 0.1);   // Arrowhead point
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("GL_TRIANGLE_STRIP - Arrow");
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
