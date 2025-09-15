/*
Example 10: Drawing Text with Different Colors

Objective:
Demonstrate how to draw multiple strings of text, each with a different color, content, and position.

Concepts Used:
- Reusing the renderText function.
- Setting the text color using glColor3f before rendering.
- Positioning text using glRasterPos2f inside the helper function.
- Using different fonts available in GLUT.
*/

#include <GL/glut.h> // Include the FreeGLUT library

// A function to render bitmap text at a specified position and with a given font.
void renderText(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y); // Set the raster position for the text.
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c); // Draw each character of the string.
    }
}

// The display callback function.
void display() {
    // Set a dark background color.
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Draw the first line of text in Red ---
    glColor3f(1.0f, 0.0f, 0.0f); // Set the current color to red.
    renderText(-0.8f, 0.8f, GLUT_BITMAP_HELVETICA_18, "This text is RED.");

    // --- Draw the second line of text in Green ---
    glColor3f(0.0f, 1.0f, 0.0f); // Set the current color to green.
    renderText(-0.8f, 0.6f, GLUT_BITMAP_TIMES_ROMAN_24, "This text is GREEN and in Times New Roman.");

    // --- Draw the third line of text in Blue ---
    glColor3f(0.0f, 0.0f, 1.0f); // Set the current color to blue.
    renderText(-0.8f, 0.4f, GLUT_BITMAP_8_BY_13, "This text is BLUE and smaller.");

    // --- Draw the fourth line of text in Yellow ---
    glColor3f(1.0f, 1.0f, 0.0f); // Set the current color to yellow.
    renderText(-0.8f, 0.2f, GLUT_BITMAP_9_BY_15, "GLUT offers several bitmap fonts.");

    // --- Draw the fifth line of text in White ---
    glColor3f(1.0f, 1.0f, 1.0f); // Set the current color to white.
    renderText(-0.8f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Change colors by calling glColor3f before rendering text.");

    glFlush(); // Ensure all commands are executed.
}

// The main function.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Example 10: Colored Text");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
