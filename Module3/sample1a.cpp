#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glRasterPos2f(-0.5, 0.0); // Position the text

    const char* text = "Hello World";
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Hello World");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
