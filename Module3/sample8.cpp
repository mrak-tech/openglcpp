/*
Drawing a Square (GL_QUADS)
The GL_QUADS primitive is used to draw four-sided polygons (quadrilaterals).
It takes vertices in groups of four, where each group defines a single quad.
The vertices should be specified in a consistent order (either clockwise or counter-clockwise) to ensure the quad is drawn correctly.
In this example, we will draw a single square.
*/

#include <GL/glut.h> // Include the FreeGLUT library for windowing and input

// This function is registered as the display callback.
// It's called whenever the window needs to be redrawn.
void display() {
    // Clears the color buffer, wiping the canvas to the background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Specifies the beginning of a group of primitives to be drawn.
    // GL_QUADS indicates that we are about to draw a quadrilateral.
    glBegin(GL_QUADS);

    // Defines the four vertices of the square in counter-clockwise order.
    // The '2f' means we are providing 2 floating-point coordinates (x, y).
    glVertex2f(-0.5, -0.5); // Bottom-left vertex
    glVertex2f(0.5, -0.5);  // Bottom-right vertex
    glVertex2f(0.5, 0.5);   // Top-right vertex
    glVertex2f(-0.5, 0.5);  // Top-left vertex

    // Marks the end of the primitive drawing section.
    glEnd();

    // Forces all buffered OpenGL commands to be executed, ensuring the square is rendered on the screen.
    glFlush();
}

// The main entry point of the application.
int main(int argc, char** argv) {
    // Initializes the GLUT library. This must be called first.
    glutInit(&argc, argv);
    // Creates a window with the specified title.
    glutCreateWindow("Square with Detailed Explanations");
    // Registers the 'display' function as the callback for when the window needs to be painted.
    glutDisplayFunc(display);
    // Enters the GLUT event processing loop, which handles rendering and user input.
    glutMainLoop();
    // This part of the code is reached only when the user closes the window.
    return 0;
}