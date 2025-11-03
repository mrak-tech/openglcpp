#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

// Variant of test2.cpp that doubles the size of the original polygon by
// scaling every vertex coordinate by 2 before uploading to the VBO.
using namespace std;

void display();
void translate(float x, float y, float z, int startindex);
void polygon();
void modifyPolygon(int value);

// Vertex positions from test2.cpp multiplied by two.
GLfloat polygonvertices[] = {
    -1.0f,  1.0f, 0.0f,  // first vertex
     1.0f,  1.0f, 0.0f,  // second vertex
     2.0f,  0.0f, 0.0f,  // third vertex
     1.0f, -1.0f, 0.0f,  // fourth vertex
    -1.0f, -1.0f, 0.0f,  // fifth vertex
    -2.0f,  0.0f, 0.0f   // sixth vertex
};

GLfloat* mapV = NULL;
int forUpdate = 0;
int ctr = 0;
GLuint VBOid = 0;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("scaled polygon");
    glutDisplayFunc(display);

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
    glutTimerFunc(1000, modifyPolygon, ctr++);
}

void polygon() {
    if (!forUpdate) {
        glGenBuffers(1, &VBOid);
        glBindBuffer(GL_ARRAY_BUFFER, VBOid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 18, polygonvertices, GL_DYNAMIC_DRAW);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, 0);
        glDrawArrays(GL_POLYGON, 0, 6);
    } else {
        glDrawArrays(GL_POLYGON, 0, 6);
    }
}

void modifyPolygon(int value) {
    if (value == 10) {
        glDisableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &VBOid);
        exit(0);
    }

    forUpdate = 1;
    mapV = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

    for (int i = 0; i < 18; i += 3) {
        translate(.025f, 0.0f, 0.0f, i);
    }

    glUnmapBuffer(GL_ARRAY_BUFFER);
    glutPostRedisplay();
}

void translate(float x, float y, float z, int startindex) {
    GLfloat w = 1.0f;
    GLfloat ta[] = {
        1.0f, 0.0f, 0.0f, x,
        0.0f, 1.0f, 0.0f, y,
        0.0f, 0.0f, 1.0f, z,
        0.0f, 0.0f, 0.0f, w
    };

    GLfloat tx = (ta[0] * mapV[startindex]) + (ta[1] * mapV[startindex + 1]) + (ta[2] * mapV[startindex + 2]) + (ta[3] * w);
    GLfloat ty = (ta[4] * mapV[startindex]) + (ta[5] * mapV[startindex + 1]) + (ta[6] * mapV[startindex + 2]) + (ta[7] * w);
    GLfloat tz = (ta[8] * mapV[startindex]) + (ta[9] * mapV[startindex + 1]) + (ta[10] * mapV[startindex + 2]) + (ta[11] * w);

    mapV[startindex] = tx;
    mapV[startindex + 1] = ty;
    mapV[startindex + 2] = tz;
}
