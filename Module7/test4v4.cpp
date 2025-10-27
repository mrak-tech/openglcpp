#define GLEW_STATIC
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <sstream>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

namespace {
    vector<int> g_windows;
}

void display();
void idle();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50, 50);

    int windowOne = glutCreateWindow("VBO Window 1");
    g_windows.push_back(windowOne);
    glutDisplayFunc(display);
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        cerr << "GLEW init failed for window 1" << endl;
        return 1;
    }

    glutInitWindowPosition(500, 50);
    int windowTwo = glutCreateWindow("VBO Window 2");
    g_windows.push_back(windowTwo);
    glutDisplayFunc(display);
    err = glewInit();
    if (err != GLEW_OK) {
        cerr << "GLEW init failed for window 2" << endl;
        return 1;
    }

    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    const int windowId = glutGetWindow();
    const GLfloat offset = (windowId % 2 == 0) ? 0.25f : -0.25f;
    GLfloat triangle[] = {
        -0.5f + offset, -0.5f, 0.0f,
         0.5f + offset, -0.5f, 0.0f,
         0.0f + offset,  0.5f, 0.0f
    };

    GLuint vboId = 0;
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    stringstream titleStream;
    titleStream << "Window " << windowId << " - VBO ID: " << vboId;
    const string windowTitle = titleStream.str();
    glutSetWindowTitle(windowTitle.c_str());

    stringstream logStream;
    logStream << windowTitle << " (GL_ARRAY_BUFFER)";
    const string logMessage = logStream.str();
    cout << logMessage << endl;
    cout.flush();
#ifdef _WIN32
    OutputDebugStringA((logMessage + "\n").c_str());
#endif

    glVertexPointer(3, GL_FLOAT, 0, 0);
    glColor4f(0.16f, 0.72f, windowId % 2 == 0 ? 0.30f : 0.08f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vboId);

    glFlush();
}

void idle() {
    for (int windowId : g_windows) {
        glutSetWindow(windowId);
        glutPostRedisplay();
    }
}
