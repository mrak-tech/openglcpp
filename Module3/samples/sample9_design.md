# Sample9_Design.cpp - Explanation

This program is an **OpenGL/GLUT-based graphics program** that demonstrates the use of **GL_POLYGON** and **color gradients** to draw a filled convex polygon with outlines.

## Key Components

### 1. Header and Setup
```cpp
#include <GL/glut.h>
```
- The **GLUT** library is included for handling windowing and OpenGL rendering.

### 2. Display Function
```cpp
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
```
- Sets a white background.
- Clears the screen before drawing.

### 3. Drawing a Polygon
```cpp
glBegin(GL_POLYGON);
glColor3f(...);
glVertex2f(...);
...
glEnd();
```
- `GL_POLYGON` is used to draw a convex polygon with multiple vertices.
- Each vertex has its own color, which creates a **smooth gradient fill** across the polygon.

### 4. Outlining the Polygon
```cpp
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(2.5f);
glBegin(GL_LINE_LOOP);
...
glEnd();
```
- Draws a **black border** around the polygon using `GL_LINE_LOOP`.

### 5. Rendering
```cpp
glFlush();
```
- Forces execution of OpenGL commands to ensure immediate rendering.

### 6. Main Function
```cpp
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sample 9 Design (Polygon)");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```
- Initializes GLUT and creates a window.
- Registers the **display function**.
- Enters the **main loop** to keep the window running.

## Output Description
- A **convex polygon** with gradient colors is displayed.
- The shape has a **black outline** around it, giving a bordered look.

---

✅ This program shows how to combine **GL_POLYGON** with **per-vertex coloring** to achieve **gradient-filled shapes** in OpenGL.
