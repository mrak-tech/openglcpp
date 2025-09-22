#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.7, 0.7, 0.7); // Gray mountains

    glBegin(GL_TRIANGLES);
    // Mountain 1
    glVertex2f(-0.8, -0.5);
    glVertex2f(-0.4, 0.6);
    glVertex2f(0.0, -0.5);
    // Mountain 2
    glVertex2f(0.0, -0.5);
    glVertex2f(0.4, 0.7);
    glVertex2f(0.8, -0.5);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("GL_TRIANGLES - Mountains");
    glClearColor(0.2, 0.4, 0.8, 0.0); // Sky blue
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
