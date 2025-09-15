#include <GL/glut.h>

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Drawing Commands ---
    // Set the point size to 10 pixels to make it visible
    glPointSize(50.0f);

    // Start a drawing block for points
    glBegin(GL_POINTS);
    // Define a single vertex at the center of the screen (0, 0)
    glVertex2f(0.0f, 0.0f);
    glEnd(); // End the drawing block
    // --- End of Drawing ---

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Drawing a Single Point");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}