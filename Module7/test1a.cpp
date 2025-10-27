#include<iostream>
#include <chrono>
#include <GL/glut.h>

// Triangle example showing how to measure draw time with std::chrono.
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
    glutMainLoop();
}
void triangle() {
    // Draw the same triangle as test1.cpp.
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, .75f);
    glVertex2f(-0.75f, 0.0);
    glVertex2f(0.75, 0.0);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(.16f, .72f, .08f, 1.0f);
    // Measure just the triangle draw call.
    auto start = std::chrono::high_resolution_clock::now();
    triangle();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken: " << elapsed.count() << " seconds\n";
    glFlush();
}
