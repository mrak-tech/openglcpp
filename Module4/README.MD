# Module 4
In OpenGL, geometric primitives are the basic building blocks used to
render graphics. These primitives are defined by a sequence of
vertices---points in 3D space specified by their x, y, and z
coordinates. OpenGL uses these vertices to construct shapes such as
points, lines, triangles, and polygons.

Each primitive type determines how the vertices are interpreted and
connected to form visible geometry.

# Overview of OpenGL Geometric Primitives

Below is a complete list of the standard OpenGL geometric primitives,
along with their syntax, description, and examples.

## 1.  GL_POINTS Description: Each vertex is rendered as an individual
    point. Syntax: glBegin(GL_POINTS); glVertex3f(x0, y0, z0);
    glVertex3f(x1, y1, z1); // ... more points glEnd();

**Example:**
```c
glBegin(GL_POINTS); glVertex3f(0.0, 0.0, 0.0); // Point at origin
glVertex3f(1.0, 1.0, 0.0); // Another point glEnd();

```

## 2.  GL_LINES Description: Vertices are paired to form separate line
    segments. Every two vertices make one line. Syntax:
    glBegin(GL_LINES); glVertex3f(x0, y0, z0); // Start of line 1
    glVertex3f(x1, y1, z1); // End of line 1 glVertex3f(x2, y2, z2); //
    Start of line 2 glVertex3f(x3, y3, z3); // End of line 2 glEnd();

**Example:**
```c
glBegin(GL_LINES); glVertex3f(0.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
// Horizontal line glVertex3f(0.5, 0.0, 0.0); glVertex3f(0.5, 1.0, 0.0);
// Vertical line glEnd();
```

## 3.  GL_LINE_STRIP Description: A strip of connected line segments. The
    first vertex starts the strip; each new vertex connects to the
    previous one. Syntax:

glBegin(GL_LINE_STRIP); glVertex3f(x0, y0, z0); glVertex3f(x1, y1, z1);
glVertex3f(x2, y2, z2); // ... glEnd();

**Example:**
```c
glBegin(GL_LINE_STRIP); glVertex3f(0.0, 0.0, 0.0); glVertex3f(1.0, 0.0,
0.0); glVertex3f(1.0, 1.0, 0.0); glVertex3f(0.0, 1.0, 0.0); glEnd();
```

glBegin(GL_LINE_STRIP); glVertex3f(0.0, 0.0, 0.0); glVertex3f(1.0, 0.0,
0.0); glVertex3f(1.0, 1.0, 0.0); glVertex3f(0.0, 1.0, 0.0); glEnd();

Draws a square outline (connected path).

## 4.  GL_LINE_LOOP Description: Like GL_LINE_STRIP, but the last vertex
    connects back to the first, forming a closed loop. Syntax:
    glBegin(GL_LINE_LOOP); glVertex3f(x0, y0, z0); glVertex3f(x1, y1,
    z1); glVertex3f(x2, y2, z2); // ... glEnd();

**Example:**
```c
glVertex3f(1.0, 0.0, 0.0); glVertex3f(1.0, 1.0, 0.0); glVertex3f(0.0,
1.0, 0.0); glEnd();
```

Draws a closed rectangle.

## 5.  GL_TRIANGLES Description: Every three consecutive vertices define a
    triangle. No shared vertices between triangles. Syntax:

glBegin(GL_TRIANGLES); glVertex3f(0.0, 0.0, 0.0); glVertex3f(1.0, 0.0,
0.0); glVertex3f(0.5, 1.0, 0.0); // Triangle 1 glVertex3f(0.5, 1.0,
0.0); glVertex3f(1.0, 0.0, 0.0); glVertex3f(1.5, 1.0, 0.0); // Triangle
2 glEnd();

## 6.  GL_TRIANGLE_STRIP Description: Triangles are formed from a strip
    where each new vertex forms a triangle with the previous two.
    Pattern: V₀,V₁,V₂ → triangle 1; V₁,V₂,V₃ → triangle 2; V₂,V₃,V₄ →
    triangle 3; etc. Syntax: glBegin(GL_TRIANGLE_STRIP); glVertex3f(x0,
    y0, z0); glVertex3f(x1, y1, z1); glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3); // ... glEnd();

**Example:**
```c
glVertex3f(1.0, 0.0, 0.0); glVertex3f(0.5, 1.0, 0.0); glVertex3f(1.5,
1.0, 0.0); glEnd();
```

Renders two adjacent triangles sharing the middle edge.

## 7.  GL_TRIANGLE_FAN Description: All triangles share a common vertex
    (the "center"). First vertex is the center; subsequent vertices form
    triangles with it and the previous one. Pattern: V₀,V₁,V₂ → triangle
    1; V₀,V₂,V₃ → triangle 2; V₀,V₃,V₄ → triangle 3; etc. Syntax:

glBegin(GL_TRIANGLE_FAN); glVertex3f(x0, y0, z0); // Center
glVertex3f(x1, y1, z1); glVertex3f(x2, y2, z2); glVertex3f(x3, y3, z3);
// ... glEnd();

glBegin(GL_TRIANGLE_FAN); glVertex3f(x0, y0, z0); // Center
glVertex3f(x1, y1, z1); glVertex3f(x2, y2, z2); glVertex3f(x3, y3, z3);
// ... glEnd(); Example: glBegin(GL_TRIANGLE_FAN); glVertex3f(0.5, 0.5,
0.0); // Center glVertex3f(0.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
glVertex3f(1.0, 1.0, 0.0); glVertex3f(0.0, 1.0, 0.0); glEnd();

Renders a filled quadrilateral as four triangles around the center.

## 8.  GL_QUADS (Quadrilaterals) Description: Each group of four vertices
    defines a quadrilateral (quad). Not recommended in modern OpenGL.
**Syntax:**
```c
    y1, z1); glVertex3f(x2, y2, z2); glVertex3f(x3, y3, z3); // One quad
    // More quads... glEnd();
```

**Example:**
```c
glBegin(GL_QUADS); glVertex3f(0.0, 0.0, 0.0); glVertex3f(1.0,
0.0, 0.0); glVertex3f(1.0, 1.0, 0.0); glVertex3f(0.0, 1.0, 0.0);
glEnd();

```

## 9.  GL_QUAD_STRIP Description: Strips of quads where each new pair of
    vertices creates a new quad with the previous pair. Pattern:
    V₀,V₁,V₂,V₃ → quad 1; V₂,V₃,V₄,V₅ → quad 2; etc. Syntax:

glBegin(GL_QUAD_STRIP); glVertex3f(x0, y0, z0); glVertex3f(x1, y1, z1);
glVertex3f(x2, y2, z2); glVertex3f(x3, y3, z3); // ... glEnd(); Example:
glBegin(GL_QUAD_STRIP); glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.0, 1.0,
0.0); glVertex3f(1.0, 0.0, 0.0); glVertex3f(1.0, 1.0, 0.0);
glVertex3f(2.0, 0.0, 0.0); glVertex3f(2.0, 1.0, 0.0); glEnd();

## 10. GL_POLYGON Description: Draws a single convex polygon from a list of
    vertices. The vertices must be ordered (clockwise or
    counter-clockwise). Syntax

glBegin(GL_POLYGON); glVertex3f(x0, y0, z0); glVertex3f(x1, y1, z1);
glVertex3f(x2, y2, z2); // ... glEnd();

**Example:**
```c
glBegin(GL_POLYGON); glVertex3f(0.0, 0.0, 0.0); glVertex3f(1.0, 0.0,
0.0); glVertex3f(1.0, 1.0, 0.0); glVertex3f(0.0, 1.0, 0.0); glEnd();
```



# Examples

glClearColor(r, g, b, a) --- Set the Background (Clear) Color Purpose:
Sets the color that OpenGL will use to clear the screen (i.e., "paint"
the background) when you call glClear(GL_COLOR_BUFFER_BIT).

Think of it as choosing the "canvas color" before you start drawing.
**Syntax:**
```c
GLfloat alpha);
```

Parameters: red, green, blue: Color components, each from 0.0 to 1.0.
0.0 = none of that color 1.0 = full intensity alpha: Transparency
(usually ignored in basic 2D drawing unless blending is enabled). Also
0.0 to 1.0.

# Examples

glClearColor(0.0, 0.0, 0.0, 1.0); // Black background glClearColor(1.0,
1.0, 1.0, 1.0); // White background glClearColor(0.0, 0.5, 1.0, 1.0); //
Sky blue glClearColor(1.0, 0.0, 0.0, 1.0); // Red
