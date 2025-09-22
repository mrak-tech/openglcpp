# Explanation of `sample3_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample3_design.cpp`).

## Overview

The program uses **OpenGL** and **GLUT (OpenGL Utility Toolkit)** to
create a simple graphical window that displays a zigzag-like connected
line figure using a **line strip**.

------------------------------------------------------------------------

## Code Breakdown

### 1. Libraries

``` cpp
#include <GL/glut.h>
```

-   This imports the **GLUT library**, which provides functions to
    create windows, handle input, and manage rendering.

------------------------------------------------------------------------

### 2. Display Function

``` cpp
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.6f, 0.4f);
    glEnd();

    glFlush();
}
```

#### Explanation:

-   **`glClearColor(1.0f, 1.0f, 1.0f, 1.0f)`** → Sets the background
    color to **white**.
-   **`glClear(GL_COLOR_BUFFER_BIT)`** → Clears the window before
    drawing.
-   **`glColor3f(0.0f, 0.0f, 0.0f)`** → Sets the drawing color to
    **black**.
-   **`glLineWidth(4.0f)`** → Sets the thickness of the lines.
-   **`glBegin(GL_LINE_STRIP)` ... `glEnd()`** → Creates a **line
    strip**, which connects each vertex with a continuous line.
    -   The vertices defined are:
        -   `(-0.6f, -0.4f)`\
        -   `(-0.2f, 0.4f)`\
        -   `(0.2f, -0.4f)`\
        -   `(0.6f, 0.4f)`\
    -   These points form a zigzag-like pattern across the window.
-   **`glFlush()`** → Ensures all drawing commands are executed
    immediately.

------------------------------------------------------------------------

### 3. Main Function

``` cpp
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 3 Design (Line Strip)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

#### Explanation:

-   **`glutInit(&argc, argv)`** → Initializes GLUT.
-   **`glutInitWindowSize(640, 480)`** → Sets the window size to
    **640x480 pixels**.
-   **`glutInitWindowPosition(100, 100)`** → Sets the window position on
    the screen.
-   **`glutCreateWindow("Sample 3 Design (Line Strip)")`** → Creates a
    window with a title.
-   **`glutDisplayFunc(display)`** → Registers the `display()` function
    for rendering.
-   **`glutMainLoop()`** → Keeps the window open in a continuous loop
    until closed.

------------------------------------------------------------------------

## Output

When executed, this program opens a **640x480 window** with a **white
background** and draws a **black zigzag line strip** across the screen.\
- The line connects all four points in sequence, forming alternating
peaks and valleys.

------------------------------------------------------------------------

## Visualization (Conceptual)

    (-0.6,-0.4)    (-0.2,0.4)    (0.2,-0.4)    (0.6,0.4)

         /\      /\
        /  \    /  \

(The figure is a connected line strip zigzag pattern.)
