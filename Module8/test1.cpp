#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

// Hexagon vertices laid out counter-clockwise (position only).
static const GLfloat kPolygonVertices[] = {
    -0.5f,  0.5f, 0.0f,  // first vertex
     0.5f,  0.5f, 0.0f,  // second vertex
     1.0f,  0.0f, 0.0f,  // third vertex
     0.5f, -0.5f, 0.0f,  // fourth vertex
    -0.5f, -0.5f, 0.0f,  // fifth vertex
    -1.0f,  0.0f, 0.0f   // sixth vertex
};

void polygon()
{
    GLuint vboId = 0;
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);

    // Upload the six vertices once per draw; small demo keeps things simple.
    glBufferData(GL_ARRAY_BUFFER, sizeof(kPolygonVertices), kPolygonVertices, GL_STATIC_DRAW);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, nullptr);

    // Render the buffered data; 6 vertices form the hexagon.
    glDrawArrays(GL_POLYGON, 0, 6);

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vboId);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.16f, 0.72f, 0.08f, 1.0f);
    polygon();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("simple");
    glutDisplayFunc(display);

    // Initialize GLEW after creating the GL context.
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "GLEW initialization failed\n";
        return -1;
    }

    glutMainLoop();
    return 0;
}
