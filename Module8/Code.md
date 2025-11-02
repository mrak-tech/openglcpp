### Codes

```cpp
//#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
```
- **`#include <GL/glew.h>`**:  
  Must be included **before** other OpenGL headers (like GLUT) to properly load OpenGL extensions.

- **`#include <GL/glut.h>`**:  
  GLUT (OpenGL Utility Toolkit) handles window creation, input, and the main loop.

---

###  Function Declarations

```cpp
void display();
void translate(float x, float y, float z, int startindex);
void polygon();
void modifyPolygon(int value);
```

- **`display()`**: Main rendering function.
- **`translate()`**: Manually applies a translation to a vertex using a 4x4 matrix.
- **`polygon()`**: Draws the polygon using VBO.
- **`modifyPolygon()`**: Timer callback that updates vertex positions.

---

### Global Variables

```cpp
GLfloat polygonvertices[] = {
    -0.5f, 0.5f, 0.0f,
     0.5f, 0.5f, 0.0f,
     1.0f, 0.0f, 0.0f,
     0.5f,-0.5f, 0.0f,
    -0.5f,-0.5f, 0.0f,
    -1.0f, 0.0f, 0.0f
};
```

- Defines a **hexagon** in 2D (z = 0 for all vertices).
- **6 vertices × 3 components = 18 floats**.

```cpp
GLfloat* mapV = NULL;  // Pointer to mapped VBO data
int forUpdate = 0;     // Flag: 0 = first draw (setup VBO), 1 = update mode
int ctr = 0;           // Counter for timer
GLuint VBOid;          // VBO identifier
```

---

###`main()` Function

```cpp
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("simple");
    glutDisplayFunc(display);
    GLenum err = glewInit();
    if (err == GLEW_OK) {
        glutMainLoop();
    }
}
```
- Initializes GLUT and creates a window.
- Sets `display()` as the render callback.
- Initializes **GLEW** to access modern OpenGL functions (like `glGenBuffers`, `glMapBuffer`, etc.).
- Enters the main event loop **only if GLEW initializes successfully**.

**Note**: If GLEW fails (`err != GLEW_OK`), the program silently exits without error message. In production, you'd print `glewGetErrorString(err)`.

---

### `display()` Function

```cpp
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(.16f, .72f, .08f, 1.0f); // Green color
    polygon();
    glFlush();
    glutTimerFunc(1000, modifyPolygon, ctr++);
}
```
- Clears the screen.
- Sets drawing color.
- Calls `polygon()` to draw.
- **Schedules a timer**: `modifyPolygon` will be called **every 1000 ms (1 second)**.
- `ctr++` passes an incrementing integer (`value`) to `modifyPolygon`.

> This creates an **animation loop**: draw → wait 1s → modify → redraw.

---

### `polygon()` Function

```cpp
void polygon() {
    if (!forUpdate) {
        // First-time setup: create and fill VBO
        glGenBuffers(1, &VBOid);
        glBindBuffer(GL_ARRAY_BUFFER, VBOid);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 18, polygonvertices, GL_DYNAMIC_DRAW);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, 0);
        glDrawArrays(GL_POLYGON, 0, 6); 
    } else {
        // Subsequent draws: just issue draw call
        glDrawArrays(GL_POLYGON, 0, 6); 
    }
}
```
---

### ⏱️ `modifyPolygon(int value)` Function

```cpp
void modifyPolygon(int value) {
    if (value == 10) {
        // Cleanup and exit after 10 updates
        glDisableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &VBOid);
        exit(0);
    }

    forUpdate = 1;
    mapV = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

    for (int i = 0; i < 18; i += 3) {
        translate(.025f, 0.0f, 0.0f, i);
    }

    glUnmapBuffer(GL_ARRAY_BUFFER);
    glutPostRedisplay();
}
```

- After **10 seconds** (`value == 10`), it cleans up OpenGL resources and exits.
- Otherwise:
  - Maps the VBO into CPU-accessible memory (`mapV` points to it).
  - Loops over each vertex (every 3 floats) and **translates it right by 0.025 units**.
  - Unmaps the buffer (uploads changes to GPU).
  - Requests a redraw via `glutPostRedisplay()`.

---

### `translate()` Function

```cpp
void translate(float x, float y, float z, int startindex) {
    GLfloat w = 1.0f;
    GLfloat ta[] = {
        1, 0, 0, x,
        0, 1, 0, y,
        0, 0, 1, z,
        0, 0, 0, 1
    };

    GLfloat tx = ta[0]*mapV[i] + ta[1]*mapV[i+1] + ta[2]*mapV[i+2] + ta[3]*w;
    // ... similarly for ty, tz

    mapV[startindex]     = tx;
    mapV[startindex + 1] = ty;
    mapV[startindex + 2] = tz;
}
```

- Applies a **translation matrix** to a single vertex.
- Since it's pure translation, this is **overkill** — you could just do:
  ```cpp
  mapV[startindex] += x;
  mapV[startindex + 1] += y;
  mapV[startindex + 2] += z;
  ```
> Note: The `w = 1.0f` is correct for points.

---

### What the Program Does

1. Draws a green hexagon.
2. Every second, **moves the entire hexagon 0.025 units to the right**.
3. After **10 moves (10 seconds)**, the program **exits cleanly**.

---

### Note
- Using **VBOs** for vertex data.
- **Mapping buffers** for CPU-side updates.
- **Manual transformation**.
- **Timer-based animation** in GLUT.

### Simulation

given the value void translate(float x, float y, float z, int startindex) {
    GLfloat w = 1.0f;
    GLfloat ta[] = {
        1, 0, 0, x,
        0, 1, 0, y,
        0, 0, 1, z,
        0, 0, 0, 1
    };

    GLfloat tx = ta[0]*mapV[i] + ta[1]*mapV[i+1] + ta[2]*mapV[i+2] + ta[3]*w;
    // ... similarly for ty, tz

    mapV[startindex]     = tx;
    mapV[startindex + 1] = ty;
    mapV[startindex + 2] = tz;
}

### Below is the **complete, step-by-step computation** for **all six vertices** during the **first call** to `modifyPolygon`, which invokes `translate(0.025f, 0.0f, 0.0f, startindex)` for each vertex.

Assume:

- `mapV` initially points to a copy of `polygonvertices`.
- Translation vector: **(x = 0.025, y = 0.0, z = 0.0)**
- `w = 1.0f`
- Translation matrix `ta` (16 elements, row-major):
  ```
  ta[0]  = 1,  ta[1]  = 0,  ta[2]  = 0,  ta[3]  = 0.025
  ta[4]  = 0,  ta[5]  = 1,  ta[6]  = 0,  ta[7]  = 0.0
  ta[8]  = 0,  ta[9]  = 0,  ta[10] = 1,  ta[11] = 0.0
  ta[12] = 0,  ta[13] = 0,  ta[14] = 0,  ta[15] = 1.0   ← (not used)
  ```

We process each vertex with `startindex = 0, 3, 6, 9, 12, 15`.
---
### 🔹 Vertex 0 → `startindex = 0`
Original: `mapV[0] = -0.5`, `mapV[1] = 0.5`, `mapV[2] = 0.0`

```
tx = ta[0]*mapV[0] + ta[1]*mapV[1] + ta[2]*mapV[2] + ta[3]*w
   = (1)*(-0.5)     + (0)*(0.5)      + (0)*(0.0)      + (0.025)*(1)
   = -0.5 + 0 + 0 + 0.025
   = -0.475

ty = ta[4]*mapV[0] + ta[5]*mapV[1] + ta[6]*mapV[2] + ta[7]*w
   = (0)*(-0.5)     + (1)*(0.5)      + (0)*(0.0)      + (0.0)*(1)
   = 0 + 0.5 + 0 + 0
   = 0.5

tz = ta[8]*mapV[0] + ta[9]*mapV[1] + ta[10]*mapV[2] + ta[11]*w
   = (0)*(-0.5)     + (0)*(0.5)      + (1)*(0.0)      + (0.0)*(1)
   = 0 + 0 + 0 + 0
   = 0.0
```
New: **(-0.475, 0.5, 0.0)**

---

### 🔹 Vertex 1 → `startindex = 3`
Original: `mapV[3] = 0.5`, `mapV[4] = 0.5`, `mapV[5] = 0.0`

```
tx = ta[0]*mapV[3] + ta[1]*mapV[4] + ta[2]*mapV[5] + ta[3]*w
   = (1)*(0.5)      + (0)*(0.5)      + (0)*(0.0)      + (0.025)*(1)
   = 0.5 + 0 + 0 + 0.025
   = 0.525

ty = ta[4]*mapV[3] + ta[5]*mapV[4] + ta[6]*mapV[5] + ta[7]*w
   = (0)*(0.5)      + (1)*(0.5)      + (0)*(0.0)      + (0.0)*(1)
   = 0 + 0.5 + 0 + 0
   = 0.5

tz = ta[8]*mapV[3] + ta[9]*mapV[4] + ta[10]*mapV[5] + ta[11]*w
   = (0)*(0.5)      + (0)*(0.5)      + (1)*(0.0)      + (0.0)*(1)
   = 0 + 0 + 0 + 0
   = 0.0
```
New: **(0.525, 0.5, 0.0)**

---

### 🔹 Vertex 2 → `startindex = 6`
Original: `mapV[6] = 1.0`, `mapV[7] = 0.0`, `mapV[8] = 0.0`

```
tx = ta[0]*mapV[6] + ta[1]*mapV[7] + ta[2]*mapV[8] + ta[3]*w
   = (1)*(1.0)      + (0)*(0.0)      + (0)*(0.0)      + (0.025)*(1)
   = 1.0 + 0 + 0 + 0.025
   = 1.025

ty = ta[4]*mapV[6] + ta[5]*mapV[7] + ta[6]*mapV[8] + ta[7]*w
   = (0)*(1.0)      + (1)*(0.0)      + (0)*(0.0)      + (0.0)*(1)
   = 0 + 0 + 0 + 0
   = 0.0

tz = ta[8]*mapV[6] + ta[9]*mapV[7] + ta[10]*mapV[8] + ta[11]*w
   = (0)*(1.0)      + (0)*(0.0)      + (1)*(0.0)      + (0.0)*(1)
   = 0 + 0 + 0 + 0
   = 0.0
```
New: **(1.025, 0.0, 0.0)**

---

### 🔹 Vertex 3 → `startindex = 9`
Original: `mapV[9] = 0.5`, `mapV[10] = -0.5`, `mapV[11] = 0.0`

```
tx = ta[0]*mapV[9] + ta[1]*mapV[10] + ta[2]*mapV[11] + ta[3]*w
   = (1)*(0.5)       + (0)*(-0.5)      + (0)*(0.0)       + (0.025)*(1)
   = 0.5 + 0 + 0 + 0.025
   = 0.525

ty = ta[4]*mapV[9] + ta[5]*mapV[10] + ta[6]*mapV[11] + ta[7]*w
   = (0)*(0.5)       + (1)*(-0.5)      + (0)*(0.0)       + (0.0)*(1)
   = 0 + (-0.5) + 0 + 0
   = -0.5

tz = ta[8]*mapV[9] + ta[9]*mapV[10] + ta[10]*mapV[11] + ta[11]*w
   = (0)*(0.5)       + (0)*(-0.5)      + (1)*(0.0)       + (0.0)*(1)
   = 0 + 0 + 0 + 0
   = 0.0
```
New: **(0.525, -0.5, 0.0)**

---

### 🔹 Vertex 4 → `startindex = 12`
Original: `mapV[12] = -0.5`, `mapV[13] = -0.5`, `mapV[14] = 0.0`

```
tx = ta[0]*mapV[12] + ta[1]*mapV[13] + ta[2]*mapV[14] + ta[3]*w
   = (1)*(-0.5)       + (0)*(-0.5)      + (0)*(0.0)        + (0.025)*(1)
   = -0.5 + 0 + 0 + 0.025
   = -0.475

ty = ta[4]*mapV[12] + ta[5]*mapV[13] + ta[6]*mapV[14] + ta[7]*w
   = (0)*(-0.5)       + (1)*(-0.5)      + (0)*(0.0)        + (0.0)*(1)
   = 0 + (-0.5) + 0 + 0
   = -0.5

tz = ta[8]*mapV[12] + ta[9]*mapV[13] + ta[10]*mapV[14] + ta[11]*w
   = (0)*(-0.5)       + (0)*(-0.5)      + (1)*(0.0)        + (0.0)*(1)
   = 0 + 0 + 0 + 0
   = 0.0
```
New: **(-0.475, -0.5, 0.0)**

---

### 🔹 Vertex 5 → `startindex = 15`
Original: `mapV[15] = -1.0`, `mapV[16] = 0.0`, `mapV[17] = 0.0`

```
tx = ta[0]*mapV[15] + ta[1]*mapV[16] + ta[2]*mapV[17] + ta[3]*w
   = (1)*(-1.0)       + (0)*(0.0)       + (0)*(0.0)        + (0.025)*(1)
   = -1.0 + 0 + 0 + 0.025
   = -0.975

ty = ta[4]*mapV[15] + ta[5]*mapV[16] + ta[6]*mapV[17] + ta[7]*w
   = (0)*(-1.0)       + (1)*(0.0)       + (0)*(0.0)        + (0.0)*(1)
   = 0 + 0 + 0 + 0
   = 0.0

tz = ta[8]*mapV[15] + ta[9]*mapV[16] + ta[10]*mapV[17] + ta[11]*w
   = (0)*(-1.0)       + (0)*(0.0)       + (1)*(0.0)        + (0.0)*(1)
   = 0 + 0 + 0 + 0
   = 0.0
```
New: **(-0.975, 0.0, 0.0)**

---

### Final Updated Vertex Array After 1st Translation:
```
[-0.475,  0.5, 0.0,
  0.525,  0.5, 0.0,
  1.025,  0.0, 0.0,
  0.525, -0.5, 0.0,
 -0.475, -0.5, 0.0,
 -0.975,  0.0, 0.0]
```

This hexagon has now **shifted 0.025 units to the right** as a whole.

Each subsequent call to `modifyPolygon` repeats this process on the **updated** values, moving it further right by 0.025 each second.
