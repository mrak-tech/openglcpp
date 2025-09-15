/*
Drawing Separate Lines (GL_LINES)
The GL_LINES primitive is used to draw individual, separate line segments.
It takes vertices in pairs, where each pair of vertices defines a single line.
For example, the first two vertices create the first line, the next two create the second line, and so on.
In this example, we will draw two disconnected lines.
*/

#include <GL/glut.h> // Include the FreeGLUT library for windowing and input

// This function is registered as the display callback.
// It's called whenever the window needs to be redrawn.
void display() {
    // Clears the color buffer, effectively wiping the canvas clean to the background color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Sets the width of the lines that will be drawn.
    // The value is a float, and 5.0f makes the lines quite thick.
    glLineWidth(5.0f);

    // Specifies the beginning of a group of primitives to be drawn.
    // GL_LINES indicates that we are about to draw separate line segments.
    glBegin(GL_LINES);

    // Defines the first vertex of the first line segment.
    // The '2f' means we are providing 2 floating-point coordinates (x, y).
    // This vertex is at (-0.8, 0.5).
    glVertex2f(-0.8, 0.5);
    // Defines the second vertex of the first line segment.
    // This completes the first line, which will be drawn from (-0.8, 0.5) to (0.8, 0.5).
    glVertex2f(0.8, 0.5);

    // Defines the first vertex of the second line segment.
    // This vertex is at (-0.8, -0.5).
    glVertex2f(-0.8, -0.5);
    // Defines the second vertex of the second line segment.
    // This completes the second line, which will be drawn from (-0.8, -0.5) to (0.8, -0.2).
    glVertex2f(0.8, -0.2);

    // Marks the end of the primitive drawing section.
    glEnd();

    // Forces all buffered OpenGL commands to be executed.
    // This ensures that what we've "drawn" in memory actually appears on the screen.
    glFlush();
}

// The main entry point of the application.
int main(int argc, char** argv) {
    // Initializes the GLUT library. This must be called first.
    glutInit(&argc, argv);
    // Creates a window with the specified title.
    glutCreateWindow("Example 3: Separate Lines with Detailed Explanations");
    // Registers the 'display' function as the callback for when the window needs to be painted.
    glutDisplayFunc(display);
    // Enters the GLUT event processing loop. This is a perpetual loop that handles events (like rendering, input, etc.).
    glutMainLoop();
    // The program will not reach here until the window is closed.
    return 0;
}
