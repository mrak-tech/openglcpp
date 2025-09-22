# Explanation of `sample2_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample2_design.cpp`).

## Overview

The program uses **OpenGL** and **GLUT (OpenGL Utility Toolkit)** to
create a simple graphical window that displays a plus (`+`) shape.
Unlike the previous version (`sample1_design.cpp`) which only used
**points**, this version uses **both points and lines** to render a
clearer and connected plus shape.

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
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(12.0f);

    glBegin(GL_POINTS);
    // Vertical and horizontal points of the plus sign
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -0.6f);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glEnd();

    glLineWidth(4.0f);

    glBegin(GL_LINES);
    // Vertical line segments
    glVertex2f(0.0f, 0.6f); glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, 0.3f); glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f); glVertex2f(0.0f, -0.3f);
    glVertex2f(0.0f, -0.3f); glVertex2f(0.0f, -0.6f);

    // Horizontal line segments
    glVertex2f(-0.6f, 0.0f); glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, 0.0f); glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f); glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, 0.0f); glVertex2f(0.6f, 0.0f);
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
-   **`glPointSize(12.0f)`** → Enlarges the points for visibility.
-   **Points (`GL_POINTS`)** → Marks important coordinates of the plus
    sign.
-   **`glLineWidth(4.0f)`** → Sets the thickness of the lines.
-   **Lines (`GL_LINES`)** → Connects the points to form a continuous
    plus sign with visible strokes.

------------------------------------------------------------------------

### 3. Main Function

``` cpp
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 2 Design (Points + Lines)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

#### Explanation:

-   **`glutInit(&argc, argv)`** → Initializes GLUT.
-   **`glutInitWindowSize(640, 480)`** → Sets the window size to
    **640x480 pixels**.
-   **`glutInitWindowPosition(100, 100)`** → Places the window at screen
    position (100,100).
-   **`glutCreateWindow("Sample 2 Design (Points + Lines)")`** → Creates
    a window with a title.
-   **`glutDisplayFunc(display)`** → Registers the `display()` function
    for rendering.
-   **`glutMainLoop()`** → Starts the main loop, keeping the window
    active.

------------------------------------------------------------------------

## Output

When executed, this program opens a **640x480 window** with a **white
background** and draws a **black plus sign (`+`)** at the center.\
- The **points** show the key positions.\
- The **lines** connect them, making a solid, clear plus shape.

------------------------------------------------------------------------

## Visualization (Conceptual)

       |
       |
    ---+---
       |
       |

(The plus shape is rendered with both points and connected lines.)
