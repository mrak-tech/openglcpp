# Explanation of `sample8_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample8_design.cpp`).

## Overview

The program uses **OpenGL** and **GLUT (OpenGL Utility Toolkit)** to
render a **triangle fan** (a set of triangles sharing a common center)
with per-vertex colors, plus a **black outline** and **radial
connectors** drawn over it for clarity and emphasis.

------------------------------------------------------------------------

## Code Breakdown

### 1) Includes

``` cpp
#include <GL/glut.h>
```

-   Brings in **GLUT** to create a window, handle the render loop, and
    manage basic input.

------------------------------------------------------------------------

### 2) `display()` --- the drawing routine

``` cpp
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.9f, 0.4f, 0.2f);
    glVertex2f(0.0f, 0.0f);

    glColor3f(0.2f, 0.6f, 0.8f);
    glVertex2f(0.0f, 0.6f);

    glColor3f(0.3f, 0.8f, 0.3f);
    glVertex2f(-0.4f, 0.2f);

    glColor3f(0.8f, 0.7f, 0.2f);
    glVertex2f(-0.3f, -0.4f);

    glColor3f(0.6f, 0.3f, 0.8f);
    glVertex2f(0.3f, -0.4f);

    glColor3f(0.2f, 0.5f, 0.4f);
    glVertex2f(0.4f, 0.2f);

    glColor3f(0.9f, 0.4f, 0.2f);
    glVertex2f(0.0f, 0.6f);
    glEnd();
```

**What this does** - **Clearing**: `glClearColor` sets the background to
white; `glClear` wipes the color buffer. - **Triangle fan**:
`GL_TRIANGLE_FAN` uses the **first vertex** as the **hub** (here,
`(0.0, 0.0)`), then every pair of consecutive vertices forms a triangle
with that hub. This efficiently draws pie‑slice triangles around a
center. - **Per‑vertex color**: Each `glColor3f` before a `glVertex2f`
sets the color for that vertex. OpenGL smoothly **interpolates colors**
across each triangle, yielding a subtle gradient between vertices. -
**Vertex order**: The outer vertices trace a loop roughly around the
center (top, upper-left, lower-left, lower-right, upper-right), with the
last vertex returning to the top to neatly close the fan.

``` cpp
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(0.3f, -0.4f);
    glVertex2f(0.4f, 0.2f);
    glEnd();
```

**What this adds** - **Outline**: Switches to black and draws a
**`GL_LINE_LOOP`** around the same outer vertices (excluding the
center). This creates a crisp **border** around the colored fan.

``` cpp
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.6f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.4f, 0.2f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.3f, -0.4f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.3f, -0.4f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.4f, 0.2f);
    glEnd();

    glFlush();
}
```

**What this adds** - **Radial connectors**: Uses `GL_LINES` to draw
straight **spokes** from the center to each outer vertex. This makes the
fan structure explicit (helpful when teaching `GL_TRIANGLE_FAN`).\
- **`glFlush()`**: Forces queued commands to execute, ensuring the frame
is rendered immediately in single‑buffered contexts.

------------------------------------------------------------------------

### 3) `main()` --- window setup and loop

``` cpp
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 8 Design (Triangle Fan)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

-   **Initialization**: Prepares GLUT and creates a **640×480** window.
-   **Title**: Names the window "Sample 8 Design (Triangle Fan)".
-   **Display callback**: Registers `display()` to draw each time the
    window needs repainting.
-   **Event loop**: `glutMainLoop()` keeps the app running until the
    user closes it.

------------------------------------------------------------------------

## Output

-   A white window showing a **multi‑colored triangle fan**, bordered
    with a **black line loop**, and with **black spokes** joining the
    center to each outer vertex. The per‑vertex colors blend smoothly
    across each wedge, giving a subtle gradient between slices.

------------------------------------------------------------------------

## Quick Tips

-   **Order matters**: For `GL_TRIANGLE_FAN`, ensure you start with the
    center vertex, then list the rim vertices **in order around the
    shape**, finally repeating the first rim vertex to close.\
-   **Outlines**: Use `GL_LINE_LOOP` over the outer vertices to add a
    clean border on top of filled geometry.\
-   **Teaching aid**: Drawing spokes with `GL_LINES` makes the triangle
    composition easy to see.
