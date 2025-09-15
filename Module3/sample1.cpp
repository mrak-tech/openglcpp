#include <GL/glut.h> // Include the GLUT library

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glFlush(); // Render now

    // glClearColor(0.3,1.0,0.11,0);//Always take 4 arguments.Last argument alpha value is
    // //used to set transparency or opaqueness.0 for completly tansparent and 1 for fully
    // //opaque.First 3 Argumets are Red,Green,Blue Color intensities.

    // glClear(GL_COLOR_BUFFER_BIT);//Clear previous color.

    // glFlush();//use in case when GLUT_SINGLE is used in GLUT_DISPLAY_FUNC. Else if
    // // GLUT_DOUBLE is used dont necessary to use it.

    // glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA); //Must include at least 1 argument
    //that is type of buffer i-e SINGLE or DOUBLE buffer.here as I am dealing with the color so I
    //have used GL_RGBA also as I have dealt with these 4 colours.
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);

    // --- New Functions ---
    // Set the initial window size to 640x480 pixels
    glutInitWindowSize(640, 480);
    // Set the initial window position to 100 pixels from the left and top edges of the screen
    glutInitWindowPosition(100, 100);
    // --- End of New ---

    // Create the window with a more descriptive title
    glutCreateWindow("A Sized and Positioned Window");

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the main event loop
    glutMainLoop();

    return 0;
}
