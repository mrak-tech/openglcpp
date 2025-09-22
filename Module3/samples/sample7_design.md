# Explanation of `sample7_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample7_design.cpp`).

## Overview

The program uses **OpenGL** and **GLUT (OpenGL Utility Toolkit)** to
create a graphical window that displays a **triangle strip** with
multiple colors, along with an outlined border using a line strip.

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

    glBegin(GL_TRIANGLE_STRIP);

    glColor3f(0.9f, 0.3f, 0.3f);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.2f, -0.4f);

    glColor3f(0.2f, 0.6f, 0.8f);
    glVertex2f(0.0f, 0.4f);

    glColor3f(0.3f, 0.8f, 0.3f);
    glVertex2f(0.2f, -0.4f);

    glColor3f(0.8f, 0.7f, 0.2f);
    glVertex2f(0.4f, 0.4f);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.2f, -0.4f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glEnd();

    glFlush();
}
```

#### Explanation:

-   **`glClearColor(1.0f, 1.0f, 1.0f, 1.0f)`** → Sets the window
    background color to **white**.
-   **`glClear(GL_COLOR_BUFFER_BIT)`** → Clears the window before
    drawing.
-   **`glBegin(GL_TRIANGLE_STRIP)` ... `glEnd()`** → Creates a
    **triangle strip**, where each new vertex forms a new triangle
    together with the two previous vertices.
    -   The strip uses vertices in alternating top-bottom positions to
        form a zigzag shape.
    -   Each vertex has its own **color**, producing a
        **gradient-colored strip**:
        -   Red (`0.9, 0.3, 0.3`)
        -   Blue (`0.2, 0.6, 0.8`)
        -   Green (`0.3, 0.8, 0.3`)
        -   Yellow (`0.8, 0.7, 0.2`)
-   **`glBegin(GL_LINE_STRIP)` ... `glEnd()`** → Draws a connected black
    outline around the same vertices for a clearer border.
-   **`glFlush()`** → Executes all drawing commands immediately.

------------------------------------------------------------------------

### 3. Main Function

``` cpp
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 7 Design (Triangle Strip)");
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
-   **`glutCreateWindow("Sample 7 Design (Triangle Strip)")`** → Creates
    a window with a title.
-   **`glutDisplayFunc(display)`** → Registers the `display()` function
    for rendering.
-   **`glutMainLoop()`** → Keeps the window active until closed.

------------------------------------------------------------------------

## Output

When executed, this program opens a **640x480 window** with a **white
background** and draws a **colored triangle strip** at the center.\
- The strip alternates between bottom and top points.\
- Each vertex is assigned a color, producing a multi-colored effect.\
- A **black outline** connects all vertices, highlighting the shape.

------------------------------------------------------------------------

## Visualization (Conceptual)

`/\    /\    /  /  \  /  \  /   /    \/    \/` (The strip forms
connected triangles with different colors and an outline.)
