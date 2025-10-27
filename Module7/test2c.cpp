#define GLEW_STATIC
#include<iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <GL/glew.h>
#include <GL/glut.h>

//house assembled from VBO triangles.
using namespace std;

GLuint houseVBO = 0;

void display();
void setupHouse();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("VBO House");
    glutDisplayFunc(display);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        cerr << "GLEW failed to initialize.\n";
        return 1;
    }

    setupHouse();
    glutMainLoop();
}

void setupHouse() {
    // Two triangles for the walls and one for the roof (total 9 vertices).
    GLfloat vertices[] = {
        // Wall triangle 1
        -0.5f, -0.3f, 0.0f,
         0.5f, -0.3f, 0.0f,
         0.5f,  0.2f, 0.0f,
         // Wall triangle 2
         -0.5f, -0.3f, 0.0f,
          0.5f,  0.2f, 0.0f,
         -0.5f,  0.2f, 0.0f,
         // Roof triangle
         -0.6f,  0.2f, 0.0f,
          0.6f,  0.2f, 0.0f,
          0.0f,  0.5f, 0.0f
    };

    glGenBuffers(1, &houseVBO);
    glBindBuffer(GL_ARRAY_BUFFER, houseVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBindBuffer(GL_ARRAY_BUFFER, houseVBO);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    auto start = std::chrono::high_resolution_clock::now();

    // Draw the wall using the first 6 vertices.
    glColor3f(0.9f, 0.7f, 0.5f);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // Draw the roof using the next 3 vertices.
    glColor3f(0.8f, 0.2f, 0.2f);
    glDrawArrays(GL_TRIANGLES, 6, 3);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "House (VBO) draw time: " << elapsed.count() << " seconds\n";

    std::ostringstream title;
    title << std::fixed << std::setprecision(3)
        << "VBO House - " << (elapsed.count() * 1000.0) << " ms";
    glutSetWindowTitle(title.str().c_str());

    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glFlush();
}
