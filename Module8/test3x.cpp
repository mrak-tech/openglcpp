//#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#define BUFFER_OFFSET(i) ((void*)(i))


void GLAPIENTRY MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam); //error handling function prototype

using namespace std;

void displayObject();

GLfloat vertices[] = {
    //Triangle
    0.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,

    0.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, -1.0f,

    0.0f, 1.0f, 0.0f,
    1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,

    0.0f,  1.0f,  0.0f,
    -1.0f,-1.0f, -1.0f,
    -1.0f,-1.0f,  1.0f,

    //Cube

    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f,  1.0f,
     1.0f, 1.0f,  1.0f,

     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

     1.0f,  1.0f, 1.0f,
    -1.0f,  1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,
     1.0f, -1.0f, 1.0f,


     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,

    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,

    1.0f,  1.0f, -1.0f,
    1.0f,  1.0f,  1.0f,
    1.0f, -1.0f,  1.0f,
    1.0f, -1.0f, -1.0f,

};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,

    1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f,

    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,

    1.0f,0.0f,0.0f,
    0.0f,0.0f,1.0f,
    0.0f,1.0f,0.0f
};



int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutCreateWindow("simple");
    glutDisplayFunc(displayObject);
    GLenum err = glewInit();
    if (err == GLEW_OK) {
        glEnable(GL_DEBUG_OUTPUT);//this part is for the error handling
        glDebugMessageCallback(MessageCallback, 0);
        printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
        printf("OpenGL vendor (%s): \n", glGetString(GL_VENDOR));
        glutMainLoop();
    }
}



void displayObject() {
    //this part is for triangle and cube

    GLuint VBOid;
    glGenBuffers(1, &VBOid);
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
    glBufferData(GL_ARRAY_BUFFER, ((9 * 4) + (12 * 6)) * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    glEnableClientState(GL_VERTEX_ARRAY);
    glClear(GL_COLOR_BUFFER_BIT);
    //glVertexPointer(3, GL_FLOAT, 0, 0);//for the triangle
    glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(36)); //for cube
    //glDrawArrays(GL_TRIANGLES, 0, 12); //for the triangle
    glDrawArrays(GL_QUADS, 0, 24); //for cube
    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBOid);
    glFlush();


    //this part is the triangle with colors
    // GLuint VBOid;
    // glGenBuffers(1, &VBOid);
    // glBindBuffer(GL_ARRAY_BUFFER, VBOid);
    // glBufferData(GL_ARRAY_BUFFER, ((9 * 4) + (12 * 6) + (9 * 4)) * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, ((9 * 4) + (12 * 6)) * sizeof(GLfloat), ((9 * 4) * sizeof(GLfloat)), colors);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    // glVertexPointer(3, GL_FLOAT, 0, 0);
    // glColorPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(((9 * 4) + (12 * 6)) * sizeof(GLfloat)));
    // glBegin(GL_TRIANGLES);
    // glArrayElement(0);
    // glArrayElement(1);
    // glArrayElement(2);
    //Of course you can just create a loop for all 12 vertices
    glEnd();
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBOid);
    glFlush();


    /*glBegin(GL_TRIANGLES);

    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);


     glEnd();

    glFlush();*/


}

void GLAPIENTRY MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)//function for error handling
{
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        (type == GL_DEBUG_TYPE_ERROR ? " GL ERROR " : ""),
        type, severity, message);
}