//#define GLEW_STATIC  // Uncomment when linking against the static GLEW library.
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

// Demonstrates a VBO that is updated every timer tick by mapping the buffer,
// modifying the underlying vertex data, and re-drawing the polygon.
using namespace std;

void display();
void translate(float x, float y, float z, int startindex);
void polygon();
void modifyPolygon(int value);

// Initial vertex positions for a hexagon laid out counter-clockwise.
GLfloat polygonvertices[] = {
    -0.5f,  0.5f, 0.0f,  // first vertex
     0.5f,  0.5f, 0.0f,  // second vertex
     1.0f,  0.0f, 0.0f,  // third vertex
     0.5f, -0.5f, 0.0f,  // fourth vertex
    -0.5f, -0.5f, 0.0f,  // fifth vertex
    -1.0f,  0.0f, 0.0f   // sixth vertex
};

// Pointer returned by glMapBuffer; used to edit VBO data in-place.
GLfloat* mapV = NULL;

int forUpdate = 0;  // Toggled after first draw so later frames reuse the VBO.
int ctr = 0;        // Counts how many timer callbacks have executed.

GLuint VBOid = 0;   // Identifier for the polygon vertex buffer.

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("simple");
    glutDisplayFunc(display);

    // Make sure all OpenGL entry points are loaded before using VBO APIs.
    GLenum err = glewInit();
    if (err == GLEW_OK) {
        glutMainLoop();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(.16f, .72f, .08f, 1.0f);
    polygon();
    glFlush();

    // Trigger the animation step once per second.
    glutTimerFunc(1000, modifyPolygon, ctr++);
}

void polygon() {
    if (!forUpdate) {
        // Upload the initial vertex data to the GPU the first time we draw.
        glGenBuffers(1, &VBOid);
        glBindBuffer(GL_ARRAY_BUFFER, VBOid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 18, polygonvertices, GL_DYNAMIC_DRAW);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, 0);

        // Render the six vertices stored in the buffer (18 floats total).
        glDrawArrays(GL_POLYGON, 0, 6);
    }
    else {
        // Subsequent frames reuse the buffer already bound/configured.
        glDrawArrays(GL_POLYGON, 0, 6);
    }
}

void modifyPolygon(int value) {
    if (value == 10) {
        // After ten updates tear down the buffer and exit cleanly.
        glDisableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &VBOid);
        exit(0);
    }

    forUpdate = 1;

    // Gain CPU access to the VBO so we can adjust each vertex.
    mapV = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

    // Move every vertex slightly along +X to animate the polygon.
    for (int i = 0; i < 18; i += 3) {
        translate(.025f, 0.0f, 0.0f, i);
    }

    glUnmapBuffer(GL_ARRAY_BUFFER);
    glutPostRedisplay();
}

void translate(float x, float y, float z, int startindex) {
    GLfloat w = 1.0f;

    // 4x4 translation matrix represented in column-major order.
    GLfloat ta[] = {
        1.0f, 0.0f, 0.0f, x,
        0.0f, 1.0f, 0.0f, y,
        0.0f, 0.0f, 1.0f, z,
        0.0f, 0.0f, 0.0f, w
    };

    // Multiply the matrix by the current vertex (treated as homogeneous coord).
    GLfloat tx = (ta[0] * mapV[startindex]) + (ta[1] * mapV[startindex + 1]) + (ta[2] * mapV[startindex + 2]) + (ta[3] * w);
    GLfloat ty = (ta[4] * mapV[startindex]) + (ta[5] * mapV[startindex + 1]) + (ta[6] * mapV[startindex + 2]) + (ta[7] * w);
    GLfloat tz = (ta[8] * mapV[startindex]) + (ta[9] * mapV[startindex + 1]) + (ta[10] * mapV[startindex + 2]) + (ta[11] * w);

    mapV[startindex] = tx;
    mapV[startindex + 1] = ty;
    mapV[startindex + 2] = tz;
}
