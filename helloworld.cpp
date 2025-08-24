#include <GL/glut.h>
#include <cstring> 

// Display callback - draws everything
void display() {
    // Clear the screen (use background color)
    glClear(GL_COLOR_BUFFER_BIT);

    // Set color to white for text
    glColor3f(1.0, 1.0, 1.0);  // White (RGB: 1,1,1)

    // Position the text near the center of the window
    glRasterPos2f(-0.2, 0.0);  // Approximate center (adjusted for text width)

    // Message to display
    const char* message = "Hello, World!";

    // Draw each character one by one
    for (int i = 0; i < strlen(message); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    // Force OpenGL to render the frame
    glFlush();
}

// Main function - Entry point
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);

    // Set display mode: single buffer & RGB color model
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set window size
    glutInitWindowSize(600, 400);

    // Set window position on screen (optional)
    glutInitWindowPosition(100, 100);

    // Create the window with title
    glutCreateWindow("OpenGL - Hello World");

    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background

    // Set up a 2D coordinate system: x and y from -1 to 1
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the main event loop (keeps window open)
    glutMainLoop();

    return 0;
}