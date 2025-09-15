#include <GL/glut.h>
/*
glutInit(): Initializes the GLUT library. You must call this first.
glutCreateWindow(): Creates the window that your graphics will appear in.
glutDisplayFunc(): Tells GLUT which function to use for drawing. In this case, it's our display function.
glutMainLoop(): Starts the program's event loop. It listens for events (like needing to redraw the window) and never returns. It should be the last thing you call.
*/

// This is our drawing function.
void display() {
    // Drawing commands go here
}

// This is the main function.
int main(int argc, char** argv) {
    // 1. Initialize GLUT
    glutInit(&argc, argv);

    // 2. Create the window
    glutCreateWindow("My OpenGL Program");

    // 3. Register the display function
    glutDisplayFunc(display);

    // 4. Enter the main event loop
    glutMainLoop();

    return 0;
}