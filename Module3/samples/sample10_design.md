# Explanation of `sample10_design.cpp`

This document explains the functionality of the provided OpenGL C++ code
(`sample10_design.cpp`).

## Overview

The program uses **OpenGL** with **GLUT (OpenGL Utility Toolkit)** to
render a **quad strip** (pairs of quads sharing edges) with per‑vertex
colors. It also draws a **black outline** and **connector lines** to
emphasize the strip's structure.

------------------------------------------------------------------------

## Code Breakdown

### 1) Includes

``` cpp
#include <GL/glut.h>
```

-   Brings in GLUT to create a window and manage the render loop and
    input.

------------------------------------------------------------------------

### 2) `display()` --- drawing routine

``` cpp
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
```

-   Sets a **white background** and clears the color buffer before
    drawing each frame.

``` cpp
    glBegin(GL_QUAD_STRIP);

    glColor3f(0.8f, 0.3f, 0.3f);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.6f, 0.2f);

    glColor3f(0.3f, 0.5f, 0.8f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.2f, 0.4f);

    glColor3f(0.3f, 0.8f, 0.4f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.2f, 0.3f);

    glColor3f(0.8f, 0.7f, 0.2f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.6f, 0.4f);

    glEnd();
```

-   **`GL_QUAD_STRIP`** draws a series of **connected quads**. After the
    first pair of vertices (bottom/top of the first column), each
    **additional pair** adds a new quad sharing an edge with the
    previous one.
-   **Per‑vertex colors** are assigned before each vertex; OpenGL
    interpolates colors across each quad, creating smooth gradients.
-   The vertex pairs alternate **bottom, top** along the x‑axis (−0.6 →
    −0.2 → 0.2 → 0.6), producing a gently meandering ribbon.

``` cpp
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(-0.6f, 0.2f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.6f, 0.4f);
    glEnd();
```

-   Switches to **black** and draws a **`GL_LINE_STRIP`** through the
    same sequence of vertices to emphasize the **outer path** of the
    strip (snaking up/down as x increases).

``` cpp
    glBegin(GL_LINES);
    glVertex2f(-0.6f, -0.4f); glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.2f, -0.3f); glVertex2f( 0.2f, -0.4f);
    glVertex2f( 0.2f, -0.4f); glVertex2f( 0.6f, -0.3f);

    glVertex2f(-0.6f,  0.2f); glVertex2f(-0.2f,  0.4f);
    glVertex2f(-0.2f,  0.4f); glVertex2f( 0.2f,  0.3f);
    glVertex2f( 0.2f,  0.3f); glVertex2f( 0.6f,  0.4f);
    glEnd();

    glFlush();
}
```

-   Draws **horizontal connectors** between bottom vertices and between
    top vertices, making every quad's **bottom edge** and **top edge**
    explicit.
-   **`glFlush()`** ensures all drawing commands run immediately (useful
    with single buffering).

------------------------------------------------------------------------

### 3) `main()` --- window setup and loop

``` cpp
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 10 Design (Quad Strip)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

-   Initializes GLUT and creates a **640×480** window titled "Sample 10
    Design (Quad Strip)".\
-   Registers `display()` as the draw callback, then enters the **event
    loop** with `glutMainLoop()`.

------------------------------------------------------------------------

## Output

-   A **multi‑colored quad strip** forming a ribbon‑like band from left
    to right.\
-   A **black line strip** traces the vertex order (alternating
    bottom/top).\
-   **Connector lines** underline the bottom and top edges of each quad.

------------------------------------------------------------------------

## Tips

-   With `GL_QUAD_STRIP`, always provide vertices in **pairs** (bottom,
    top) along the path.\
-   For **crisper edges**, overlay outlines using `GL_LINE_STRIP` or
    `GL_LINE_LOOP` after drawing filled primitives.\
-   For portability to modern OpenGL, consider replacing fixed‑function
    calls with **vertex buffers** and **shaders** (the visual idea stays
    the same).
