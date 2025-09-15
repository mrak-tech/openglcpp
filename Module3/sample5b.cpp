/*
Drawing Buildings (GL_POLYGON)
This example draws a simple city skyline with several buildings.
*/

#include <GL/glut.h>

void display() {
    // Clear the screen to a light blue (sky)
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Building 1 (Dark Gray)
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9, -1.0);
    glVertex2f(-0.9, 0.2);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.5, -1.0);
    glEnd();

    // Building 2 (Gray)
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -1.0);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.2, 0.5);
    glVertex2f(-0.2, -1.0);
    glEnd();

    // Building 3 (Light Gray)
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, -1.0);
    glVertex2f(-0.3, -0.2);
    glVertex2f(0.3, -0.2);
    glVertex2f(0.3, -1.0);
    glEnd();

    // Building 4 (Dark Gray)
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_POLYGON);
    glVertex2f(0.2, -1.0);
    glVertex2f(0.2, 0.7);
    glVertex2f(0.7, 0.7);
    glVertex2f(0.7, -1.0);
    glEnd();
    
    // Building 5 (Gray)
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_POLYGON);
    glVertex2f(0.6, -1.0);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.9, 0.3);
    glVertex2f(0.9, -1.0);
    glEnd();

    // Send the drawing to the screen
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Example 5b: Buildings");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
