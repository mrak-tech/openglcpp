#include <GL/glut.h>

GLfloat vertices[] = {
    0.0f, 1.0f, 0.0f, // Top vertex
   -1.0f, -1.0f, 0.0f, // Bottom-left vertex
    1.0f, -1.0f, 0.0f  // Bottom-right vertex
};

void displayTriangle() {
    glEnableClientState(GL_VERTEX_ARRAY); // Enable vertex arrays
    glVertexPointer(3, GL_FLOAT, 0, vertices); // Tell OpenGL where the vertices are
    glDrawArrays(GL_TRIANGLES, 0, 3); // Draw a triangle
    glDisableClientState(GL_VERTEX_ARRAY); // Disable vertex arrays
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Vertex Array Triangle");
    glutDisplayFunc(displayTriangle);
    glutMainLoop();
    return 0;
}