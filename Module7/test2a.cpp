#define GLEW_STATIC // <----- define GLEW_STATIC
#include<iostream>
#include <chrono>
#include <GL/glew.h>  // <---- additional header files
#include <GL/glut.h>

// Same VBO sample as test2.cpp but wraps the draw call with timing.
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
    //1. Initialize the triangle using an array
    GLfloat trianglevertices[] = {
    0.0f, .75f, 0.0f,-0.75f, 0.0f, 0.0f,
    0.75f, 0.0f, 0.0f
    };
    //2. Generate a Vertex Object ID for your array of vertices and bind it
    GLuint VBOid;
    glGenBuffers(1, &VBOid);
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 9, trianglevertices,
        GL_STATIC_DRAW);
    //3. Activate and specify pointer to vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    //4. Draw the primitive object
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    //5. Disable client side capability for normal operation
    glDisableClientState(GL_VERTEX_ARRAY);
    // bind with 0, so, switch back to normal pointer operation
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBOid);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(.16f, .72f, .08f, 1.0f);
    // Track how long the buffer-based draw takes.
    auto start = std::chrono::high_resolution_clock::now();
    triangle();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken: " << elapsed.count() << " seconds\n";
    glFlush();
}
