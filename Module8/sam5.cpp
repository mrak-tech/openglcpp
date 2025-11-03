#include <GL/glut.h>

GLfloat vertices[] = {
    0.0f, 1.0f, 0.0f, // Top vertex
   -1.0f, -1.0f, 0.0f, // Bottom-left vertex
    1.0f, -1.0f, 0.0f  // Bottom-right vertex
};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f, // Red
    0.0f, 1.0f, 0.0f, // Green
    0.0f, 0.0f, 1.0f  // Blue
};

void displayTriangle() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices); // Vertices
    glColorPointer(3, GL_FLOAT, 0, colors); // Colors

    glDrawArrays(GL_TRIANGLES, 0, 3); // Draw a colorful triangle

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Colorful Triangle");
    glutDisplayFunc(displayTriangle);
    glutMainLoop();
    return 0;
}