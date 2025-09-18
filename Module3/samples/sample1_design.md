
# Explanation of `sample1_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample1_design.cpp`).

## Overview

The program uses **OpenGL** and **GLUT (OpenGL Utility Toolkit)** to
create a simple graphical window that displays a plus (`+`) shape made
of points.

------------------------------------------------------------------------

## Code Breakdown

### 1. Libraries

``` cpp
#include <GL/glut.h>
```

-   This imports the **GLUT library** which provides functions to create
    windows, handle user input, and manage rendering.

------------------------------------------------------------------------

### 2. Display Function

``` cpp
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(12.0f);

    glBegin(GL_POINTS);
    // Vertical line of plus
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -0.6f);

    // Horizontal line of plus
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glEnd();

    glFlush();
}
```

#### Explanation:

-   **`glClearColor(1.0f, 1.0f, 1.0f, 1.0f)`** → Sets the window
    background color to **white**.
-   **`glClear(GL_COLOR_BUFFER_BIT)`** → Clears the screen before
    drawing.
-   **`glColor3f(0.0f, 0.0f, 0.0f)`** → Sets the drawing color to
    **black**.
-   **`glPointSize(12.0f)`** → Makes points larger for better
    visibility.
-   **`glBegin(GL_POINTS) ... glEnd()`** → Draws a collection of
    **points**:
    -   Vertical line (y-axis): from `(0.0, 0.6)` down to `(0.0, -0.6)`.
    -   Horizontal line (x-axis): from `(-0.6, 0.0)` to `(0.6, 0.0)`.
-   **`glFlush()`** → Ensures all drawing commands are executed
    immediately.

------------------------------------------------------------------------

### 3. Main Function

``` cpp
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 1 Design (Points)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

#### Explanation:

-   **`glutInit(&argc, argv)`** → Initializes GLUT.
-   **`glutInitWindowSize(640, 480)`** → Sets the window size to
    **640x480 pixels**.
-   **`glutInitWindowPosition(100, 100)`** → Positions the window on the
    screen.
-   **`glutCreateWindow("Sample 1 Design (Points)")`** → Creates a
    window with a title.
-   **`glutDisplayFunc(display)`** → Registers the `display()` function
    for rendering.
-   **`glutMainLoop()`** → Enters the GLUT main loop (keeps window
    running).

------------------------------------------------------------------------

## Output

When executed, this program opens a **640x480 window** with a **white
background**, and draws a **black plus sign (`+`)** made of large points
at the center of the screen.

------------------------------------------------------------------------

## Visualization (Conceptual)

       *
       *
    ***+***
       *
       *

(The `+` shape is made of points, not continuous lines.)
