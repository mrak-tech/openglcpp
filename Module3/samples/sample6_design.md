# Explanation of `sample6_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample6_design.cpp`).

## Overview

The program uses **OpenGL** and **GLUT (OpenGL Utility Toolkit)** to
create a graphical window that displays two colored **triangles**
forming a simple geometric design.

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

    glBegin(GL_TRIANGLES);

    glColor3f(0.9f, 0.3f, 0.3f);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.1f, -0.4f);
    glVertex2f(-0.35f, 0.4f);

    glColor3f(0.2f, 0.5f, 0.8f);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.6f, -0.4f);
    glVertex2f(0.35f, 0.4f);

    glEnd();

    glFlush();
}
```

#### Explanation:

-   **`glClearColor(1.0f, 1.0f, 1.0f, 1.0f)`** → Sets the window
    background color to **white**.
-   **`glClear(GL_COLOR_BUFFER_BIT)`** → Clears the window before
    drawing.
-   **`glBegin(GL_TRIANGLES)` ... `glEnd()`** → Tells OpenGL to draw
    triangles using the specified vertices.
    -   **First Triangle (Red)**:
        -   Color: `(0.9f, 0.3f, 0.3f)` → reddish shade\
        -   Vertices: `(-0.6f, -0.4f)`, `(-0.1f, -0.4f)`,
            `(-0.35f, 0.4f)`\
    -   **Second Triangle (Blue)**:
        -   Color: `(0.2f, 0.5f, 0.8f)` → bluish shade\
        -   Vertices: `(0.1f, -0.4f)`, `(0.6f, -0.4f)`, `(0.35f, 0.4f)`\
-   Together, the two triangles form a symmetric shape resembling a
    polygon (like a diamond or hourglass split into two triangles).
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
    glutCreateWindow("Sample 6 Design (Triangles)");
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
-   **`glutCreateWindow("Sample 6 Design (Triangles)")`** → Creates a
    window with a title.
-   **`glutDisplayFunc(display)`** → Registers the `display()` function
    for rendering.
-   **`glutMainLoop()`** → Keeps the window active until closed.

------------------------------------------------------------------------

## Output

When executed, this program opens a **640x480 window** with a **white
background** and draws **two filled colored triangles** (red and blue)
side by side, forming a symmetric geometric design.

------------------------------------------------------------------------

## Visualization (Conceptual)

`/\       /  /  \     /   /    \   /    /      \ /` (The two triangles
are mirrored left and right, creating a polygon-like shape.)
