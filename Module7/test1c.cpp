#include<iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <GL/glut.h>

// house made with immediate-mode quads and triangles.
using namespace std;

void display();
void drawHouse();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Immediate Mode House");
    glutDisplayFunc(display);
    glutMainLoop();
}

void drawHouse() {
    // Draw the house body as a single quad.
    glColor3f(0.9f, 0.7f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glEnd();

    // Draw the roof as a triangle.
    glColor3f(0.8f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.45f, 0.2f);
    glVertex2f(0.45f, 0.2f);
    glVertex2f(0.0f, 0.45f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Measure how long the immediate-mode drawing takes.
    auto start = std::chrono::high_resolution_clock::now();
    drawHouse();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "House draw time: " << elapsed.count() << " seconds\n";

    std::ostringstream title;
    title << std::fixed << std::setprecision(3)
        << "Immediate Mode House - " << (elapsed.count() * 1000.0) << " ms";
    glutSetWindowTitle(title.str().c_str());

    glFlush();
}
