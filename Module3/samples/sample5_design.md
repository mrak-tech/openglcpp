# Explanation of `sample5_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample5_design.cpp`).

## Overview

The program uses **OpenGL** and **GLUT (OpenGL Utility Toolkit)** to
create a graphical window that displays a **filled polygon** shape with
a custom color.

------------------------------------------------------------------------

## Code Breakdown

### 1. Libraries

``` cpp
#include <GL/glut.h>
```

-   Imports the **GLUT library**, which provides functions to create
    windows, handle input, and manage rendering.

------------------------------------------------------------------------

### 2. Display Function

``` cpp
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.6f, 0.8f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.5f, -0.4f);
    glVertex2f(0.0f, -0.6f);
    glEnd();

    glFlush();
}
```

#### Explanation:

-   **`glClearColor(1.0f, 1.0f, 1.0f, 1.0f)`** → Sets the window
    background color to **white**.
-   **`glClear(GL_COLOR_BUFFER_BIT)`** → Clears the window before
    drawing.
-   **`glColor3f(0.2f, 0.6f, 0.8f)`** → Sets the drawing color to a
    **cyan-like shade** (light blue-green).
-   **`glBegin(GL_POLYGON)` ... `glEnd()`** → Draws a **filled polygon**
    using the specified vertices.
    -   The vertices form a pentagon-like shape:
        -   `(-0.5f, -0.4f)`\
        -   `(-0.2f, 0.4f)`\
        -   `(0.2f, 0.4f)`\
        -   `(0.5f, -0.4f)`\
        -   `(0.0f, -0.6f)`\
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
    glutCreateWindow("Sample 5 Design (Polygon)");
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
-   **`glutCreateWindow("Sample 5 Design (Polygon)")`** → Creates a
    window with a title.
-   **`glutDisplayFunc(display)`** → Registers the `display()` function
    for rendering.
-   **`glutMainLoop()`** → Keeps the window active until closed.

------------------------------------------------------------------------

## Output

When executed, this program opens a **640x480 window** with a **white
background** and draws a **cyan-colored polygon** at the center.

------------------------------------------------------------------------

## Visualization (Conceptual)

          /\
         /  \
        /    \
       /      \
       \      /
        \    /
         \  /
          \/

(The shape resembles a pentagon or house-like figure filled with color.)
