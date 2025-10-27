#define GLEW_STATIC // <----- define GLEW_STATIC
#include<iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <string>
#include <sstream>
#include <GL/glew.h>  // <---- additional header files
#include <GL/glut.h>

// Basic VBO example: load triangle data into a buffer each frame.
using namespace std;
void display();
void triangle();
void init();
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("simple");
    glutDisplayFunc(display);
    GLenum err = glewInit();  // <------- Include glew initialization calls before the main loop
    if (err == GLEW_OK) {
        glutMainLoop();
    }
}
void triangle() {
    //1. Initialize vertex data for two shapes (triangle + rectangle)
    GLfloat trianglevertices[] = {
        0.0f, 0.65f, 0.0f,
       -0.6f, 0.0f, 0.0f,
        0.6f, 0.0f, 0.0f
    };
    GLfloat rectangleVertices[] = {
       -0.55f, -0.15f, 0.0f,
        0.55f, -0.15f, 0.0f,
       -0.55f, -0.75f, 0.0f,
        0.55f, -0.75f, 0.0f
    };
    //2. Generate Vertex Buffer Object IDs and bind them individually
    GLuint vboIds[2] = { 0, 0 };
    glGenBuffers(2, vboIds);
    stringstream titleStream;
    titleStream << "VBO IDs: " << vboIds[0] << ", " << vboIds[1];
    const string windowTitle = titleStream.str();
    stringstream buffer;
    buffer << windowTitle << " (GL_ARRAY_BUFFER)";
    const string message = buffer.str();
    cout << message << endl;
    cout.flush();
    glutSetWindowTitle(windowTitle.c_str());
#ifdef _WIN32
    OutputDebugStringA((message + "\n").c_str());
#endif
    //3. Activate and specify pointer to vertex array
    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, vboIds[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(trianglevertices), trianglevertices,
        GL_STATIC_DRAW);
    glColor4f(0.12f, 0.40f, 0.88f, 1.0f); // cool blue triangle
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindBuffer(GL_ARRAY_BUFFER, vboIds[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), rectangleVertices,
        GL_STATIC_DRAW);
    glColor4f(0.93f, 0.45f, 0.18f, 1.0f); // warm orange rectangle
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    //4. Disable client side capability for normal operation
    glDisableClientState(GL_VERTEX_ARRAY);
    // bind with 0, so, switch back to normal pointer operation
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(2, vboIds);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    triangle();
    glFlush();
}
