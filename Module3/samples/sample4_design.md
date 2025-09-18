# Explanation of `sample4_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample4_design.cpp`).

## Overview

The program uses **OpenGL** and **GLUT (OpenGL Utility Toolkit)** to
create a graphical window that displays a closed polygonal shape using a
**line loop**.

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

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.3f);
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
-   **`glColor3f(0.0f, 0.0f, 0.0f)`** → Sets the drawing color to
    **black**.
-   **`glLineWidth(4.0f)`** → Sets the line thickness.
-   **`glBegin(GL_LINE_LOOP)` ... `glEnd()`** → Draws a closed loop by
    connecting all vertices in order, and automatically connecting the
    last point back to the first.
    -   The vertices defined are:
        -   `(-0.5f, -0.3f)`\
        -   `(0.0f, 0.5f)`\
        -   `(0.5f, -0.3f)`\
        -   `(0.0f, -0.6f)`\
    -   These points form a diamond/kite-like shape.
-   **`glFlush()`** → Executes all drawing commands immediately.

------------------------------------------------------------------------

### 3. Main Function

``` cpp
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 4 Design (Line Loop)");
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
-   **`glutCreateWindow("Sample 4 Design (Line Loop)")`** → Creates a
    window with a title.
-   **`glutDisplayFunc(display)`** → Registers the `display()` function
    for rendering.
-   **`glutMainLoop()`** → Keeps the window active until closed.

------------------------------------------------------------------------

## Output

When executed, this program opens a **640x480 window** with a **white
background** and draws a **black diamond/kite-shaped polygon** at the
center using a closed line loop.

------------------------------------------------------------------------

## Visualization (Conceptual)

          /\
         /  \
        /    \
        \    /
         \  /
          \/

(The figure resembles a diamond or kite shape formed by connecting the
four points in a loop.)
