#define GLEW_STATIC
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <sstream>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

namespace {
    std::string g_windowTitle;
}

void display();
void renderMultipleVBOs();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("multiple VBO demo");
    glutDisplayFunc(display);

    GLenum err = glewInit();
    if (err == GLEW_OK) {
        glutMainLoop();
    }
}

void renderMultipleVBOs() {
    // Triangle vertices stored in two separate buffers so we can show unique VBO ids.
    GLfloat triangleOne[] = {
        -0.8f, -0.2f, 0.0f,
        -0.2f, -0.2f, 0.0f,
        -0.5f,  0.4f, 0.0f
    };
    GLfloat triangleTwo[] = {
         0.2f, -0.2f, 0.0f,
         0.8f, -0.2f, 0.0f,
         0.5f,  0.4f, 0.0f
    };

    GLuint vboIds[2] = { 0, 0 };
    glGenBuffers(2, vboIds);

    stringstream titleStream;
    titleStream << "VBO IDs: " << vboIds[0] << ", " << vboIds[1];
    g_windowTitle = titleStream.str();
    glutSetWindowTitle(g_windowTitle.c_str());

    stringstream logStream;
    logStream << g_windowTitle << " (GL_ARRAY_BUFFER)";
    const string logMessage = logStream.str();
    cout << logMessage << endl;
    cout.flush();
#ifdef _WIN32
    OutputDebugStringA((logMessage + "\n").c_str());
#endif

    glEnableClientState(GL_VERTEX_ARRAY);

    // Upload first triangle
    glBindBuffer(GL_ARRAY_BUFFER, vboIds[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleOne), triangleOne, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Upload second triangle
    glBindBuffer(GL_ARRAY_BUFFER, vboIds[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleTwo), triangleTwo, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(2, vboIds);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.16f, 0.72f, 0.08f, 1.0f);
    renderMultipleVBOs();
    glFlush();
}
