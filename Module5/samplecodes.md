### CODE 1
#include <GL/glut.h>

void renderBitmapString(const char* message) {
    for (const char* c = message; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.4f, 0.0f);
    renderBitmapString("Hello World FEU TECH ");

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("glRasterPos2f Sample");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/glut.h>
```
- This includes the GLUT library, which provides a simple interface for creating windows, handling input, and managing OpenGL contexts.
- GLUT simplifies many tasks, such as initializing OpenGL, creating windows, and handling events like keyboard and mouse input.

---

### **2. `renderBitmapString` Function**
```c
void renderBitmapString(const char* message) {
    for (const char* c = message; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
```
- **Purpose**: This function renders a string of text using bitmap fonts provided by GLUT.
- **How it works**:
  - It iterates through each character in the `message` string (`const char* message`) until it reaches the null terminator (`'\0'`).
  - For each character, it calls `glutBitmapCharacter`, which renders the character at the current raster position using the specified font (`GLUT_BITMAP_HELVETICA_18`).
  - The font `GLUT_BITMAP_HELVETICA_18` is a predefined bitmap font in GLUT that renders characters in a Helvetica style with a height of 18 pixels.

---

### **3. `display` Function**
```c
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.4f, 0.0f);
    renderBitmapString("Hello World FEU TECH ");

    glutSwapBuffers();
}
```
- **Purpose**: This function defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The color used for clearing is set by `glClearColor` in the `main` function.
  2. `glColor3f(1.0f, 1.0f, 1.0f)`:
     - Sets the drawing color to white (RGB values: 1.0, 1.0, 1.0).
  3. `glRasterPos2f(-0.4f, 0.0f)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(-0.4, 0.0)` in the normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  4. `renderBitmapString("Hello World FEU TECH ")`:
     - Calls the `renderBitmapString` function to render the text "Hello World FEU TECH" starting at the specified raster position.
  5. `glutSwapBuffers()`:
     - Swaps the front and back buffers to display the rendered content on the screen.
     - This is necessary because the program uses double buffering (`GLUT_DOUBLE` mode).

---

### **4. `reshape` Function**
```c
void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
```
- **Purpose**: This function adjusts the OpenGL viewport and projection matrix when the window is resized.
- **Step-by-step breakdown**:
  1. `glViewport(0, 0, width, height)`:
     - Sets the viewport to cover the entire window.
     - The viewport defines the area of the window where OpenGL rendering occurs.
  2. `glMatrixMode(GL_PROJECTION)`:
     - Switches to the projection matrix mode.
     - The projection matrix defines how 3D objects are projected onto the 2D screen.
  3. `glLoadIdentity()`:
     - Resets the current matrix to the identity matrix.
  4. `gluOrtho2D(-1.0, 1.0, -1.0, 1.0)`:
     - Sets up an orthographic projection with coordinates ranging from `-1.0` to `1.0` in both the x and y directions.
     - This ensures that the coordinates used in the `display` function (e.g., `glRasterPos2f`) are interpreted correctly.
  5. `glMatrixMode(GL_MODELVIEW)`:
     - Switches back to the modelview matrix mode.
     - The modelview matrix is used to transform objects in the scene (e.g., translation, rotation, scaling).
  6. `glLoadIdentity()`:
     - Resets the modelview matrix to the identity matrix.

---

### **5. `main` Function**
```c
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("glRasterPos2f Sample");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
```
- **Purpose**: This is the entry point of the program and sets up the GLUT environment.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the GLUT library.
  2. `glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_DOUBLE`: Enables double buffering to reduce flickering.
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(640, 480)`:
     - Sets the initial size of the window to 640x480 pixels.
  4. `glutCreateWindow("glRasterPos2f Sample")`:
     - Creates a window with the title "glRasterPos2f Sample".
  5. `glClearColor(0.1f, 0.1f, 0.2f, 1.0f)`:
     - Sets the background color of the window to a dark blue-gray (RGB values: 0.1, 0.1, 0.2).
  6. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  7. `glutReshapeFunc(reshape)`:
     - Registers the `reshape` function as the callback for handling window resizing.
  8. `glutMainLoop()`:
     - Enters the GLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **How It Works Together**
1. When the program starts, `main` initializes GLUT, creates a window, and sets up the OpenGL context.
2. The `reshape` function is called to set up the viewport and projection matrix.
3. The `display` function is called to render the text "Hello World FEU TECH" in white at the specified raster position.
4. The `glutMainLoop` keeps the program running, processing events like window resizing and redrawing.

---

### **Output**
- A window titled "glRasterPos2f Sample" appears.
- The background is a dark blue-gray color.
- The text "Hello World FEU TECH" is displayed in white near the center-left of the window.

---

### CODE 2
#include <GL/freeglut.h>

void renderText()
{
    const unsigned char text[] = "Hello, GLUT!";
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.5f, 0.0f);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, text);
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderText();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Basic glutBitmapString");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}


### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which is an open-source alternative to the original GLUT library.
- FreeGLUT provides similar functionality to GLUT but is actively maintained and supports modern systems.

---

### **2. `renderText` Function**
```c
void renderText()
{
    const unsigned char text[] = "Hello, GLUT!";
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.5f, 0.0f);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, text);
    glFlush();
}
```
- **Purpose**: This function renders the text "Hello, GLUT!" using a bitmap font.
- **Step-by-step breakdown**:
  1. `const unsigned char text[] = "Hello, GLUT!";`:
     - Defines the string to be rendered as an array of `unsigned char`. This is required because `glutBitmapString` expects a `const unsigned char*`.
  2. `glColor3f(1.0f, 0.0f, 0.0f)`:
     - Sets the drawing color to red (RGB values: 1.0, 0.0, 0.0).
  3. `glRasterPos2f(-0.5f, 0.0f)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(-0.5, 0.0)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  4. `glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, text)`:
     - Renders the text using the specified bitmap font (`GLUT_BITMAP_TIMES_ROMAN_24`), which is a predefined Times Roman-style font with a height of 24 pixels.
     - The `glutBitmapString` function automatically handles rendering multiple characters in sequence.
  5. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.
     - This is necessary because the program uses single buffering (`GLUT_SINGLE` mode).

---

### **3. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderText();
}
```
- **Purpose**: This function defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The color used for clearing is set by `glClearColor` in the `main` function.
  2. `renderText()`:
     - Calls the `renderText` function to render the text "Hello, GLUT!" at the specified raster position.

---

### **4. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Basic glutBitmapString");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
```
- **Purpose**: This is the entry point of the program and sets up the FreeGLUT environment.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(640, 480)`:
     - Sets the initial size of the window to 640x480 pixels.
  4. `glutCreateWindow("Basic glutBitmapString")`:
     - Creates a window with the title "Basic glutBitmapString".
  5. `glClearColor(0.0f, 0.0f, 0.0f, 1.0f)`:
     - Sets the background color of the window to black (RGB values: 0.0, 0.0, 0.0).
  6. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  7. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **How It Works Together**
1. When the program starts, `main` initializes FreeGLUT, creates a window, and sets up the OpenGL context.
2. The `display` function is called to clear the screen and render the text "Hello, GLUT!" in red at the specified raster position.
3. The `glutMainLoop` keeps the program running, processing events like redrawing when necessary.

---

### **Output**
- A window titled "Basic glutBitmapString" appears.
- The background is black.
- The text "Hello, GLUT!" is displayed in red near the center-left of the window.

---


### CODE 3

#include <GL/freeglut.h>

struct BitmapFontEntry {
    void* font;
    const char* label;
};

struct StrokeFontEntry {
    void* font;
    const char* label;
};

BitmapFontEntry bitmapFonts[] = {
    {GLUT_BITMAP_9_BY_15, "GLUT_BITMAP_9_BY_15"},
    {GLUT_BITMAP_8_BY_13, "GLUT_BITMAP_8_BY_13"},
    {GLUT_BITMAP_TIMES_ROMAN_10, "GLUT_BITMAP_TIMES_ROMAN_10"},
    {GLUT_BITMAP_TIMES_ROMAN_24, "GLUT_BITMAP_TIMES_ROMAN_24"},
    {GLUT_BITMAP_HELVETICA_10, "GLUT_BITMAP_HELVETICA_10"},
    {GLUT_BITMAP_HELVETICA_12, "GLUT_BITMAP_HELVETICA_12"},
    {GLUT_BITMAP_HELVETICA_18, "GLUT_BITMAP_HELVETICA_18"}
};

StrokeFontEntry strokeFonts[] = {
    {GLUT_STROKE_ROMAN, "GLUT_STROKE_ROMAN"},
    {GLUT_STROKE_MONO_ROMAN, "GLUT_STROKE_MONO_ROMAN"}
};

void renderBitmapLine(float y, void* font, const char* text)
{
    glRasterPos2f(-0.95f, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}

void renderStrokeLine(float y, void* font, const char* text)
{
    glPushMatrix();
    glTranslatef(-0.95f, y, 0.0f);
    glScalef(0.0015f, 0.0015f, 1.0f);
    glutStrokeString(font, reinterpret_cast<const unsigned char*>(text));
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);
    float y = 0.85f;
    for (const auto& entry : bitmapFonts) {
        renderBitmapLine(y, entry.font, entry.label);
        y -= 0.2f;
    }

    glColor3f(0.4f, 0.9f, 1.0f);
    for (const auto& entry : strokeFonts) {
        renderStrokeLine(y, entry.font, entry.label);
        y -= 0.3f;
    }

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("GLUT Font Examples");

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, and rendering text.

---

### **2. Font Definitions**
#### Bitmap Fonts
```c
BitmapFontEntry bitmapFonts[] = {
    {GLUT_BITMAP_9_BY_15, "GLUT_BITMAP_9_BY_15"},
    {GLUT_BITMAP_8_BY_13, "GLUT_BITMAP_8_BY_13"},
    {GLUT_BITMAP_TIMES_ROMAN_10, "GLUT_BITMAP_TIMES_ROMAN_10"},
    {GLUT_BITMAP_TIMES_ROMAN_24, "GLUT_BITMAP_TIMES_ROMAN_24"},
    {GLUT_BITMAP_HELVETICA_10, "GLUT_BITMAP_HELVETICA_10"},
    {GLUT_BITMAP_HELVETICA_12, "GLUT_BITMAP_HELVETICA_12"},
    {GLUT_BITMAP_HELVETICA_18, "GLUT_BITMAP_HELVETICA_18"}
};
```
- This array defines a list of **bitmap fonts** available in FreeGLUT.
- Each entry contains:
  - A pointer to the font (e.g., `GLUT_BITMAP_9_BY_15`).
  - A label describing the font name (e.g., `"GLUT_BITMAP_9_BY_15"`).

#### Stroke Fonts
```c
StrokeFontEntry strokeFonts[] = {
    {GLUT_STROKE_ROMAN, "GLUT_STROKE_ROMAN"},
    {GLUT_STROKE_MONO_ROMAN, "GLUT_STROKE_MONO_ROMAN"}
};
```
- This array defines a list of **stroke fonts** available in FreeGLUT.
- Each entry contains:
  - A pointer to the font (e.g., `GLUT_STROKE_ROMAN`).
  - A label describing the font name (e.g., `"GLUT_STROKE_ROMAN"`).

---

### **3. Rendering Functions**
#### `renderBitmapLine`
```c
void renderBitmapLine(float y, void* font, const char* text)
{
    glRasterPos2f(-0.95f, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a line of text using a specified **bitmap font**.
- **How it works**:
  1. `glRasterPos2f(-0.95f, y)`:
     - Sets the raster position where the text will start rendering. The x-coordinate is fixed at `-0.95` (left edge), and the y-coordinate determines the vertical position.
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the specified bitmap font.

#### `renderStrokeLine`
```c
void renderStrokeLine(float y, void* font, const char* text)
{
    glPushMatrix();
    glTranslatef(-0.95f, y, 0.0f);
    glScalef(0.0015f, 0.0015f, 1.0f);
    glutStrokeString(font, reinterpret_cast<const unsigned char*>(text));
    glPopMatrix();
}
```
- **Purpose**: Renders a line of text using a specified **stroke font**.
- **How it works**:
  1. `glPushMatrix()`:
     - Saves the current transformation matrix.
  2. `glTranslatef(-0.95f, y, 0.0f)`:
     - Moves the origin to the desired position (`-0.95` on the x-axis and `y` on the y-axis).
  3. `glScalef(0.0015f, 0.0015f, 1.0f)`:
     - Scales the text to make it visible. Stroke fonts are defined in a large coordinate system, so scaling is necessary to fit them into the NDC space.
  4. `glutStrokeString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the specified stroke font.
  5. `glPopMatrix()`:
     - Restores the previous transformation matrix.

---

### **4. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for bitmap fonts
    float y = 0.85f;
    for (const auto& entry : bitmapFonts) {
        renderBitmapLine(y, entry.font, entry.label);
        y -= 0.2f; // Move down for the next line
    }

    glColor3f(0.4f, 0.9f, 1.0f); // Cyan color for stroke fonts
    for (const auto& entry : strokeFonts) {
        renderStrokeLine(y, entry.font, entry.label);
        y -= 0.3f; // Move down for the next line
    }

    glFlush();
}
```
- **Purpose**: Renders all bitmap and stroke fonts in the window.
- **Step-by-step breakdown**:
  1. Clears the screen with `glClear(GL_COLOR_BUFFER_BIT)`.
  2. Sets the color to yellow (`1.0f, 1.0f, 0.0f`) for bitmap fonts.
  3. Iterates through the `bitmapFonts` array, calling `renderBitmapLine` for each font.
     - Starts at `y = 0.85` and decreases `y` by `0.2` after each font to avoid overlap.
  4. Sets the color to cyan (`0.4f, 0.9f, 1.0f`) for stroke fonts.
  5. Iterates through the `strokeFonts` array, calling `renderStrokeLine` for each font.
     - Decreases `y` by `0.3` after each font because stroke fonts are larger.

---

### **5. `reshape` Function**
```c
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
```
- **Purpose**: Adjusts the viewport and projection matrix when the window is resized.
- **How it works**:
  1. Sets the viewport to cover the entire window.
  2. Switches to the projection matrix mode and sets up an orthographic projection with coordinates ranging from `-1.0` to `1.0` in both the x and y directions.
  3. Switches back to the modelview matrix mode.

---

### **6. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("GLUT Font Examples");

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. Initializes FreeGLUT with `glutInit`.
  2. Sets the display mode to single-buffered RGB (`GLUT_SINGLE | GLUT_RGB`).
  3. Creates a window with the title "GLUT Font Examples" and size 800x600 pixels.
  4. Sets the background color to dark blue (`0.05f, 0.05f, 0.1f`).
  5. Registers the `display` function for rendering and the `reshape` function for resizing.
  6. Enters the FreeGLUT event loop with `glutMainLoop`.

---

### **Output**
- A window titled "GLUT Font Examples" appears.
- The background is dark blue.
- **Bitmap fonts** are displayed in yellow, with their names listed in descending order starting near the top of the window.
- **Stroke fonts** are displayed in cyan below the bitmap fonts, scaled smaller to fit within the window.

---

### CODE

#include <GL/freeglut.h>

void renderText(float x, float y, void* font, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    renderText(-0.8f, 0.5f, GLUT_BITMAP_HELVETICA_18, "Welcome to GLUT text!");

    glColor3f(0.0f, 1.0f, 0.0f);
    renderText(-0.8f, 0.2f, GLUT_BITMAP_9_BY_15, "Bitmap fonts draw on the screen.");

    glColor3f(1.0f, 0.7f, 0.0f);
    renderText(-0.8f, -0.2f, GLUT_BITMAP_TIMES_ROMAN_24, "Change colors, positions, fonts.");

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Simple GLUT Text Example");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, and rendering text.

---

### **2. `renderText` Function**
```c
void renderText(float x, float y, void* font, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a string of text at the specified position `(x, y)` using a given bitmap font.
- **How it works**:
  1. `glRasterPos2f(x, y)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(x, y)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the specified bitmap font (`font`).
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.

---

### **3. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    renderText(-0.8f, 0.5f, GLUT_BITMAP_HELVETICA_18, "Welcome to GLUT text!");

    glColor3f(0.0f, 1.0f, 0.0f);
    renderText(-0.8f, 0.2f, GLUT_BITMAP_9_BY_15, "Bitmap fonts draw on the screen.");

    glColor3f(1.0f, 0.7f, 0.0f);
    renderText(-0.8f, -0.2f, GLUT_BITMAP_TIMES_ROMAN_24, "Change colors, positions, fonts.");

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. **First Line**:
     - Sets the drawing color to white (`1.0f, 1.0f, 1.0f`).
     - Calls `renderText` to render the text `"Welcome to GLUT text!"` at position `(-0.8, 0.5)` using the `GLUT_BITMAP_HELVETICA_18` font.
  3. **Second Line**:
     - Sets the drawing color to green (`0.0f, 1.0f, 0.0f`).
     - Calls `renderText` to render the text `"Bitmap fonts draw on the screen."` at position `(-0.8, 0.2)` using the `GLUT_BITMAP_9_BY_15` font.
  4. **Third Line**:
     - Sets the drawing color to orange (`1.0f, 0.7f, 0.0f`).
     - Calls `renderText` to render the text `"Change colors, positions, fonts."` at position `(-0.8, -0.2)` using the `GLUT_BITMAP_TIMES_ROMAN_24` font.
  5. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.

---

### **4. `reshape` Function**
```c
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
```
- **Purpose**: Adjusts the viewport and projection matrix when the window is resized.
- **How it works**:
  1. `glViewport(0, 0, width, height)`:
     - Sets the viewport to cover the entire window.
  2. `glMatrixMode(GL_PROJECTION)`:
     - Switches to the projection matrix mode.
  3. `glLoadIdentity()`:
     - Resets the current matrix to the identity matrix.
  4. `gluOrtho2D(-1.0, 1.0, -1.0, 1.0)`:
     - Sets up an orthographic projection with coordinates ranging from `-1.0` to `1.0` in both the x and y directions.
  5. `glMatrixMode(GL_MODELVIEW)`:
     - Switches back to the modelview matrix mode.
  6. `glLoadIdentity()`:
     - Resets the modelview matrix to the identity matrix.

---

### **5. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Simple GLUT Text Example");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(640, 480)`:
     - Sets the initial size of the window to 640x480 pixels.
  4. `glutCreateWindow("Simple GLUT Text Example")`:
     - Creates a window with the title "Simple GLUT Text Example".
  5. `glClearColor(0.1f, 0.1f, 0.2f, 1.0f)`:
     - Sets the background color of the window to a dark blue-gray (RGB values: 0.1, 0.1, 0.2).
  6. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  7. `glutReshapeFunc(reshape)`:
     - Registers the `reshape` function as the callback for handling window resizing.
  8. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **Output**
- A window titled "Simple GLUT Text Example" appears.
- The background is a dark blue-gray color.
- Three lines of text are displayed:
  1. **Top Line**: `"Welcome to GLUT text!"` in white, rendered with the `GLUT_BITMAP_HELVETICA_18` font.
  2. **Middle Line**: `"Bitmap fonts draw on the screen."` in green, rendered with the `GLUT_BITMAP_9_BY_15` font.
  3. **Bottom Line**: `"Change colors, positions, fonts."` in orange, rendered with the `GLUT_BITMAP_TIMES_ROMAN_24` font.

---

### **Key Features**
1. **Bitmap Fonts**:
   - Predefined pixel-based fonts provided by FreeGLUT.
   - Rendered using `glutBitmapString`.
   - Fixed size and resolution.
2. **Customization**:
   - Different fonts (`GLUT_BITMAP_HELVETICA_18`, `GLUT_BITMAP_9_BY_15`, `GLUT_BITMAP_TIMES_ROMAN_24`) are used to demonstrate font variety.
   - Colors are changed for each line of text to show how `glColor3f` affects rendering.
   - Positions are adjusted to demonstrate control over text placement.

---

### CODE

#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.5f, 0.2f);
    glRasterPos2f(-0.6f, 0.0f);
    const unsigned char text[] = "glutInit example";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);             // Initialize GLUT state using command line args
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("glutInit Sample");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, and rendering text.

---

### **2. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.5f, 0.2f);
    glRasterPos2f(-0.6f, 0.0f);
    const unsigned char text[] = "glutInit example";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3f(1.0f, 0.5f, 0.2f)`:
     - Sets the drawing color to orange (`RGB: 1.0, 0.5, 0.2`).
  3. `glRasterPos2f(-0.6f, 0.0f)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(-0.6, 0.0)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  4. `const unsigned char text[] = "glutInit example";`:
     - Defines the string to be rendered as an array of `unsigned char`. This is required because `glutBitmapString` expects a `const unsigned char*`.
  5. `glutBitmapString(GLUT_BITMAP_HELVETICA_18, text)`:
     - Renders the string `"glutInit example"` using the `GLUT_BITMAP_HELVETICA_18` bitmap font.
     - The `glutBitmapString` function automatically handles rendering multiple characters in sequence.
  6. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.
     - This is necessary because the program uses single buffering (`GLUT_SINGLE` mode).

---

### **3. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);             // Initialize GLUT state using command line args
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("glutInit Sample");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
     - Parses command-line arguments (if any) to configure GLUT behavior.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(640, 480)`:
     - Sets the initial size of the window to 640x480 pixels.
  4. `glutInitWindowPosition(100, 100)`:
     - Sets the initial position of the window on the screen (100 pixels from the left and top edges).
  5. `glutCreateWindow("glutInit Sample")`:
     - Creates a window with the title "glutInit Sample".
  6. `glClearColor(0.0f, 0.0f, 0.0f, 1.0f)`:
     - Sets the background color of the window to black (`RGB: 0.0, 0.0, 0.0`).
  7. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  8. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **Output**
- A window titled "glutInit Sample" appears.
- The background is black.
- The text `"glutInit example"` is displayed in orange near the center-left of the window.

---

### **Key Features**
1. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font, which is a predefined Helvetica-style font with a height of 18 pixels.
   - The `glutBitmapString` function renders the entire string at once, making it simpler than rendering one character at a time with `glutBitmapCharacter`.

2. **Single Buffering**:
   - The program uses single buffering (`GLUT_SINGLE`), which means there is no separate back buffer for rendering. Instead, rendering occurs directly to the front buffer.
   - Single buffering is simpler but may result in flickering during rendering.

3. **Raster Position**:
   - The `glRasterPos2f` function determines where the text will be rendered. In this case, the text starts at `(-0.6, 0.0)` in NDC space.

---


### CODE

#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.9f, 0.3f, 0.3f);
    glRasterPos2f(-0.8f, 0.0f);
    const unsigned char text[] = "glutInitWindowSize(640, 480)";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);     // Request a 640x480 window
    glutCreateWindow("glutInitWindowSize Example");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, and rendering text.

---

### **2. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.9f, 0.3f, 0.3f);
    glRasterPos2f(-0.8f, 0.0f);
    const unsigned char text[] = "glutInitWindowSize(640, 480)";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3f(0.9f, 0.3f, 0.3f)`:
     - Sets the drawing color to a reddish hue (`RGB: 0.9, 0.3, 0.3`).
  3. `glRasterPos2f(-0.8f, 0.0f)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(-0.8, 0.0)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  4. `const unsigned char text[] = "glutInitWindowSize(640, 480)";`:
     - Defines the string to be rendered as an array of `unsigned char`. This is required because `glutBitmapString` expects a `const unsigned char*`.
  5. `glutBitmapString(GLUT_BITMAP_HELVETICA_18, text)`:
     - Renders the string `"glutInitWindowSize(640, 480)"` using the `GLUT_BITMAP_HELVETICA_18` bitmap font.
     - The `glutBitmapString` function automatically handles rendering multiple characters in sequence.
  6. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.
     - This is necessary because the program uses single buffering (`GLUT_SINGLE` mode).

---

### **3. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);     // Request a 1024x768 window
    glutCreateWindow("glutInitWindowSize Example");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
     - Parses command-line arguments (if any) to configure GLUT behavior.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(1024, 768)`:
     - Requests the creation of a window with a size of **1024x768 pixels**.
     - Note: The actual window size may differ depending on the system's resolution and constraints.
  4. `glutCreateWindow("glutInitWindowSize Example")`:
     - Creates a window with the title `"glutInitWindowSize Example"`.
  5. `glClearColor(0.1f, 0.1f, 0.2f, 1.0f)`:
     - Sets the background color of the window to a dark blue-gray (`RGB: 0.1, 0.1, 0.2`).
  6. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  7. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **Output**
- A window titled `"glutInitWindowSize Example"` appears.
- The window size is **1024x768 pixels** (or the closest size supported by the system).
- The background is a dark blue-gray color.
- The text `"glutInitWindowSize(640, 480)"` is displayed in a reddish hue near the center-left of the window.

---

### **Key Features**
1. **Window Size**:
   - The program requests a window size of **1024x768** using `glutInitWindowSize(1024, 768)`.
   - The actual size may vary depending on the system's capabilities and constraints.

2. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font, which is a predefined Helvetica-style font with a height of 18 pixels.
   - The `glutBitmapString` function renders the entire string at once, making it simpler than rendering one character at a time with `glutBitmapCharacter`.

3. **Single Buffering**:
   - The program uses single buffering (`GLUT_SINGLE`), which means there is no separate back buffer for rendering. Instead, rendering occurs directly to the front buffer.
   - Single buffering is simpler but may result in flickering during rendering.

4. **Raster Position**:
   - The `glRasterPos2f` function determines where the text will be rendered. In this case, the text starts at `(-0.8, 0.0)` in NDC space.

---

### CODE

#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.7f, 1.0f);
    glRasterPos2f(-0.8f, 0.0f);
    const unsigned char text[] = "glutCreateWindow(\"GLUT Window\")";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("GLUT Window");  // Create the actual window with a title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, and rendering text.

---

### **2. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.7f, 1.0f);
    glRasterPos2f(-0.8f, 0.0f);
    const unsigned char text[] = "glutCreateWindow(\"GLUT Window\")";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3f(0.2f, 0.7f, 1.0f)`:
     - Sets the drawing color to a light blue (`RGB: 0.2, 0.7, 1.0`).
  3. `glRasterPos2f(-0.8f, 0.0f)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(-0.8, 0.0)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  4. `const unsigned char text[] = "glutCreateWindow(\"GLUT Window\")";`:
     - Defines the string to be rendered as an array of `unsigned char`. This is required because `glutBitmapString` expects a `const unsigned char*`.
  5. `glutBitmapString(GLUT_BITMAP_HELVETICA_18, text)`:
     - Renders the string `"glutCreateWindow("GLUT Window")"` using the `GLUT_BITMAP_HELVETICA_18` bitmap font.
     - The `glutBitmapString` function automatically handles rendering multiple characters in sequence.
  6. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.
     - This is necessary because the program uses single buffering (`GLUT_SINGLE` mode).

---

### **3. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("GLUT Window");  // Create the actual window with a title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
     - Parses command-line arguments (if any) to configure GLUT behavior.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(600, 400)`:
     - Requests the creation of a window with a size of **600x400 pixels**.
  4. `glutCreateWindow("GLUT Window")`:
     - Creates a window with the title `"GLUT Window"`.
  5. `glClearColor(0.0f, 0.0f, 0.0f, 1.0f)`:
     - Sets the background color of the window to black (`RGB: 0.0, 0.0, 0.0`).
  6. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  7. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **Output**
- A window titled `"GLUT Window"` appears.
- The window size is **600x400 pixels**.
- The background is black.
- The text `"glutCreateWindow("GLUT Window")"` is displayed in light blue near the center-left of the window.

---

### **Key Features**
1. **Window Title**:
   - The program creates a window with the title `"GLUT Window"` using `glutCreateWindow("GLUT Window")`.

2. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font, which is a predefined Helvetica-style font with a height of 18 pixels.
   - The `glutBitmapString` function renders the entire string at once, making it simpler than rendering one character at a time with `glutBitmapCharacter`.

3. **Single Buffering**:
   - The program uses single buffering (`GLUT_SINGLE`), which means there is no separate back buffer for rendering. Instead, rendering occurs directly to the front buffer.
   - Single buffering is simpler but may result in flickering during rendering.

4. **Raster Position**:
   - The `glRasterPos2f` function determines where the text will be rendered. In this case, the text starts at `(-0.8, 0.0)` in NDC space.

---


### CODE

#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.9f, 0.1f);
    const unsigned char text[] = "This window uses glutFullScreen()";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

void keyboard(unsigned char key, int, int)
{
    if (key == 27) { // Escape key to exit fullscreen and terminate
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fullscreen Example");

    glutFullScreen(); // Switch to fullscreen mode

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, and rendering text.

---

### **2. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.9f, 0.1f);
    const unsigned char text[] = "This window uses glutFullScreen()";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3f(1.0f, 1.0f, 1.0f)`:
     - Sets the drawing color to white (`RGB: 1.0, 1.0, 1.0`).
  3. `glRasterPos2f(-0.9f, 0.1f)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(-0.9, 0.1)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  4. `const unsigned char text[] = "This window uses glutFullScreen()";`:
     - Defines the string to be rendered as an array of `unsigned char`. This is required because `glutBitmapString` expects a `const unsigned char*`.
  5. `glutBitmapString(GLUT_BITMAP_HELVETICA_18, text)`:
     - Renders the string `"This window uses glutFullScreen()"` using the `GLUT_BITMAP_HELVETICA_18` bitmap font.
     - The `glutBitmapString` function automatically handles rendering multiple characters in sequence.
  6. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.
     - This is necessary because the program uses single buffering (`GLUT_SINGLE` mode).

---

### **3. `keyboard` Function**
```c
void keyboard(unsigned char key, int, int)
{
    if (key == 27) { // Escape key to exit fullscreen and terminate
        glutLeaveMainLoop();
    }
}
```
- **Purpose**: Handles keyboard input to allow exiting the program when the **Escape** key is pressed.
- **Step-by-step breakdown**:
  1. The function is called whenever a keyboard key is pressed.
  2. If the pressed key is `27` (ASCII code for the **Escape** key):
     - `glutLeaveMainLoop()` is called to terminate the GLUT event processing loop, effectively closing the program.

---

### **4. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fullscreen Example");

    glutFullScreen(); // Switch to fullscreen mode

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
     - Parses command-line arguments (if any) to configure GLUT behavior.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(800, 600)`:
     - Requests the creation of a window with a size of **800x600 pixels**. This size is used before switching to fullscreen mode.
  4. `glutCreateWindow("Fullscreen Example")`:
     - Creates a window with the title `"Fullscreen Example"`.
  5. `glutFullScreen()`:
     - Switches the window to fullscreen mode.
     - The window occupies the entire screen.
  6. `glClearColor(0.0f, 0.0f, 0.0f, 1.0f)`:
     - Sets the background color of the window to black (`RGB: 0.0, 0.0, 0.0`).
  7. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  8. `glutKeyboardFunc(keyboard)`:
     - Registers the `keyboard` function as the callback for handling keyboard input.
  9. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **Output**
- A fullscreen window appears with the title `"Fullscreen Example"`.
- The background is black.
- The text `"This window uses glutFullScreen()"` is displayed in white near the top-left corner of the screen.
- Pressing the **Escape** key exits fullscreen mode and terminates the program.

---

### **Key Features**
1. **Fullscreen Mode**:
   - The program switches to fullscreen mode using `glutFullScreen()`.
   - The window occupies the entire screen, hiding other windows and UI elements.

2. **Keyboard Input Handling**:
   - The program listens for keyboard input using the `glutKeyboardFunc` callback.
   - Pressing the **Escape** key (`ASCII 27`) calls `glutLeaveMainLoop()` to terminate the program.

3. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font, which is a predefined Helvetica-style font with a height of 18 pixels.
   - The `glutBitmapString` function renders the entire string at once.

4. **Single Buffering**:
   - The program uses single buffering (`GLUT_SINGLE`), which means there is no separate back buffer for rendering. Instead, rendering occurs directly to the front buffer.
   - Single buffering is simpler but may result in flickering during rendering.

5. **Raster Position**:
   - The `glRasterPos2f` function determines where the text will be rendered. In this case, the text starts at `(-0.9, 0.1)` in NDC space.

---

### CODE

#include <GL/freeglut.h>

bool showFirstMessage = true;

void renderText(float x, float y, void* font, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (showFirstMessage) {
        glColor3f(0.2f, 0.8f, 0.4f);
        renderText(-0.7f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Frame 1: Waiting for redisplay");
    } else {
        glColor3f(0.8f, 0.4f, 0.8f);
        renderText(-0.7f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Frame 2: glutPostRedisplay() called");
    }

    glFlush();
}

void timer(int)
{
    showFirstMessage = !showFirstMessage;
    glutPostRedisplay();           // Ask GLUT to redraw using the new state
    glutTimerFunc(1000, timer, 0); // Repeat every second
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("glutPostRedisplay Example");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, rendering text, and managing timers.

---

### **2. Global Variable**
```c
bool showFirstMessage = true;
```
- **Purpose**: A boolean flag that determines which message to display.
  - When `true`, the program displays `"Frame 1: Waiting for redisplay"`.
  - When `false`, the program displays `"Frame 2: glutPostRedisplay() called"`.

---

### **3. `renderText` Function**
```c
void renderText(float x, float y, void* font, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(font, reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a string of text at the specified position `(x, y)` using a given bitmap font.
- **How it works**:
  1. `glRasterPos2f(x, y)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(x, y)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the specified bitmap font (`font`).
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.

---

### **4. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (showFirstMessage) {
        glColor3f(0.2f, 0.8f, 0.4f); // Light green color
        renderText(-0.7f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Frame 1: Waiting for redisplay");
    } else {
        glColor3f(0.8f, 0.4f, 0.8f); // Purple color
        renderText(-0.7f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Frame 2: glutPostRedisplay() called");
    }

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. Conditional rendering:
     - If `showFirstMessage` is `true`:
       - Sets the drawing color to light green (`RGB: 0.2, 0.8, 0.4`).
       - Calls `renderText` to render `"Frame 1: Waiting for redisplay"`.
     - Otherwise:
       - Sets the drawing color to purple (`RGB: 0.8, 0.4, 0.8`).
       - Calls `renderText` to render `"Frame 2: glutPostRedisplay() called"`.
  3. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.

---

### **5. `timer` Function**
```c
void timer(int)
{
    showFirstMessage = !showFirstMessage; // Toggle the message flag
    glutPostRedisplay();                 // Request a redraw
    glutTimerFunc(1000, timer, 0);       // Schedule the next timer event after 1 second
}
```
- **Purpose**: Implements a timer callback to toggle the message and request a redraw every second.
- **Step-by-step breakdown**:
  1. `showFirstMessage = !showFirstMessage`:
     - Toggles the value of `showFirstMessage` between `true` and `false`.
  2. `glutPostRedisplay()`:
     - Requests GLUT to call the `display` function again, causing the window to be redrawn with the updated message.
  3. `glutTimerFunc(1000, timer, 0)`:
     - Schedules the `timer` function to be called again after 1000 milliseconds (1 second).

---

### **6. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("glutPostRedisplay Example");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(700, 400)`:
     - Requests the creation of a window with a size of **700x400 pixels**.
  4. `glutCreateWindow("glutPostRedisplay Example")`:
     - Creates a window with the title `"glutPostRedisplay Example"`.
  5. `glClearColor(0.1f, 0.1f, 0.1f, 1.0f)`:
     - Sets the background color of the window to dark gray (`RGB: 0.1, 0.1, 0.1`).
  6. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  7. `glutTimerFunc(0, timer, 0)`:
     - Starts the timer immediately (with a delay of 0 milliseconds) and registers the `timer` function as the callback.
  8. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **Output**
- A window titled `"glutPostRedisplay Example"` appears.
- The background is dark gray.
- The program alternates between two messages every second:
  1. `"Frame 1: Waiting for redisplay"` in light green.
  2. `"Frame 2: glutPostRedisplay() called"` in purple.

---

### **Key Features**
1. **Dynamic Redrawing**:
   - The `glutPostRedisplay` function requests GLUT to redraw the window whenever the state changes.
   - This allows the program to dynamically update the displayed text without requiring user interaction.

2. **Timer Callback**:
   - The `glutTimerFunc` function schedules periodic updates using the `timer` callback.
   - In this case, the timer toggles the `showFirstMessage` flag and requests a redraw every second.

3. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font, which is a predefined Helvetica-style font with a height of 18 pixels.
   - The `glutBitmapString` function renders the entire string at once.

4. **Single Buffering**:
   - The program uses single buffering (`GLUT_SINGLE`), which means there is no separate back buffer for rendering. Instead, rendering occurs directly to the front buffer.
   - Single buffering is simpler but may result in flickering during rendering.

---


### CODE

#include <GL/freeglut.h>

int frame = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);
    glRasterPos2f(-0.9f, 0.1f);

    const char* message = (frame % 2 == 0)
        ? "Frame A: Press space to switch"
        : "Frame B: glutPostRedisplay() ran";

    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(message));

    glFlush();
}

void keyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        frame++;
        glutPostRedisplay(); // Demonstrates requesting a redraw with glutPostRedisplay()
    }
    if (key == 27) {
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("glutPostRedisplay (space toggles)");

    glClearColor(0.05f, 0.05f, 0.15f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, rendering text, and managing redraws.

---

### **2. Global Variable**
```c
int frame = 0;
```
- **Purpose**: Tracks the current frame number.
  - If `frame % 2 == 0`, the program displays `"Frame A: Press space to switch"`.
  - Otherwise, it displays `"Frame B: glutPostRedisplay() ran"`.

---

### **3. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);
    glRasterPos2f(-0.9f, 0.1f);

    const char* message = (frame % 2 == 0)
        ? "Frame A: Press space to switch"
        : "Frame B: glutPostRedisplay() ran";

    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(message));

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3f(1.0f, 1.0f, 0.0f)`:
     - Sets the drawing color to yellow (`RGB: 1.0, 1.0, 0.0`).
  3. `glRasterPos2f(-0.9f, 0.1f)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(-0.9, 0.1)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  4. Conditional message selection:
     - If `frame % 2 == 0`, the message is `"Frame A: Press space to switch"`.
     - Otherwise, the message is `"Frame B: glutPostRedisplay() ran"`.
  5. `glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char*>(message))`:
     - Renders the selected string using the `GLUT_BITMAP_HELVETICA_18` bitmap font.
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.
  6. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.

---

### **4. `keyboard` Function**
```c
void keyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        frame++;
        glutPostRedisplay(); // Demonstrates requesting a redraw with glutPostRedisplay()
    }
    if (key == 27) {
        glutLeaveMainLoop();
    }
}
```
- **Purpose**: Handles keyboard input to toggle between frames or exit the program.
- **Step-by-step breakdown**:
  1. If the **spacebar** (`' '`) is pressed:
     - Increments the `frame` counter.
     - Calls `glutPostRedisplay()` to request a redraw of the window with the updated message.
  2. If the **Escape** key (`ASCII 27`) is pressed:
     - Calls `glutLeaveMainLoop()` to terminate the program.

---

### **5. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("glutPostRedisplay (space toggles)");

    glClearColor(0.05f, 0.05f, 0.15f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(700, 400)`:
     - Requests the creation of a window with a size of **700x400 pixels**.
  4. `glutCreateWindow("glutPostRedisplay (space toggles)")`:
     - Creates a window with the title `"glutPostRedisplay (space toggles)"`.
  5. `glClearColor(0.05f, 0.05f, 0.15f, 1.0f)`:
     - Sets the background color of the window to dark blue-gray (`RGB: 0.05, 0.05, 0.15`).
  6. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  7. `glutKeyboardFunc(keyboard)`:
     - Registers the `keyboard` function as the callback for handling keyboard input.
  8. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **Output**
- A window titled `"glutPostRedisplay (space toggles)"` appears.
- The background is dark blue-gray.
- Initially, the text `"Frame A: Press space to switch"` is displayed in yellow near the top-left corner of the window.
- Pressing the **spacebar** toggles between two messages:
  1. `"Frame A: Press space to switch"`.
  2. `"Frame B: glutPostRedisplay() ran"`.
- Pressing the **Escape** key exits the program.

---

### **Key Features**
1. **Dynamic Redrawing**:
   - The `glutPostRedisplay` function requests GLUT to redraw the window whenever the state changes.
   - This allows the program to dynamically update the displayed text without requiring user interaction beyond pressing the spacebar.

2. **Keyboard Input Handling**:
   - The program listens for keyboard input using the `glutKeyboardFunc` callback.
   - Pressing the **spacebar** increments the `frame` counter and triggers a redraw.
   - Pressing the **Escape** key terminates the program.

3. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font, which is a predefined Helvetica-style font with a height of 18 pixels.
   - The `glutBitmapString` function renders the entire string at once.

4. **Single Buffering**:
   - The program uses single buffering (`GLUT_SINGLE`), which means there is no separate back buffer for rendering. Instead, rendering occurs directly to the front buffer.
   - Single buffering is simpler but may result in flickering during rendering.

---

### CODE

#include <GL/freeglut.h>

float squareX = 0.0f;
float squareY = 0.0f;
float squareSize = 0.2f;
float color[3] = {0.2f, 0.7f, 1.0f};

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_9_BY_15,
                     reinterpret_cast<const unsigned char*>(text));
}

void drawSquare()
{
    glBegin(GL_QUADS);
        glVertex2f(squareX - squareSize, squareY - squareSize);
        glVertex2f(squareX + squareSize, squareY - squareSize);
        glVertex2f(squareX + squareSize, squareY + squareSize);
        glVertex2f(squareX - squareSize, squareY + squareSize);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(color);
    drawSquare();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Normal keys: R/G/B change color, C resets, Esc quits");
    drawText(-0.95f, 0.70f, "Arrow keys move the square (handled by glutSpecialFunc)");

    glutSwapBuffers();
}

void handleNormalKeys(unsigned char key, int, int)
{
    switch (key) {
    case 'r':
    case 'R':
        color[0] = 1.0f; color[1] = 0.1f; color[2] = 0.1f;
        break;
    case 'g':
    case 'G':
        color[0] = 0.2f; color[1] = 1.0f; color[2] = 0.2f;
        break;
    case 'b':
    case 'B':
        color[0] = 0.2f; color[1] = 0.5f; color[2] = 1.0f;
        break;
    case 'c':
    case 'C':
        color[0] = 0.2f; color[1] = 0.7f; color[2] = 1.0f;
        squareX = 0.0f;
        squareY = 0.0f;
        break;
    case 27:
        glutLeaveMainLoop();
        return;
    default:
        return;
    }

    glutPostRedisplay();
}

void handleSpecialKeys(int key, int, int)
{
    const float step = 0.05f;
    switch (key) {
    case GLUT_KEY_LEFT:
        squareX -= step;
        break;
    case GLUT_KEY_RIGHT:
        squareX += step;
        break;
    case GLUT_KEY_UP:
        squareY += step;
        break;
    case GLUT_KEY_DOWN:
        squareY -= step;
        break;
    default:
        return;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(720, 520);
    glutCreateWindow("glutKeyboardFunc example with movement");

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleNormalKeys); // Demonstrating glutKeyboardFunc registering a normal key handler
    glutSpecialFunc(handleSpecialKeys); // Additional keyboard hook for arrow keys

    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, rendering shapes, and managing redraws.

---

### **2. Global Variables**
```c
float squareX = 0.0f;
float squareY = 0.0f;
float squareSize = 0.2f;
float color[3] = {0.2f, 0.7f, 1.0f};
```
- **Purpose**: These variables define the state of the square:
  - `squareX` and `squareY`: The center position of the square in normalized device coordinates (NDC).
  - `squareSize`: Half the width/height of the square.
  - `color[3]`: The RGB color of the square, initialized to light blue (`0.2, 0.7, 1.0`).

---

### **3. `drawText` Function**
```c
void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_9_BY_15,
                     reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a string of text at the specified position `(x, y)` using a bitmap font.
- **How it works**:
  1. `glRasterPos2f(x, y)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(x, y)` in NDC space.
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the `GLUT_BITMAP_9_BY_15` font.
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.

---

### **4. `drawSquare` Function**
```c
void drawSquare()
{
    glBegin(GL_QUADS);
        glVertex2f(squareX - squareSize, squareY - squareSize);
        glVertex2f(squareX + squareSize, squareY - squareSize);
        glVertex2f(squareX + squareSize, squareY + squareSize);
        glVertex2f(squareX - squareSize, squareY + squareSize);
    glEnd();
}
```
- **Purpose**: Draws a square centered at `(squareX, squareY)` with a size determined by `squareSize`.
- **Step-by-step breakdown**:
  1. `glBegin(GL_QUADS)`:
     - Begins defining a quadrilateral (square).
  2. `glVertex2f(...)`:
     - Specifies the four corners of the square:
       - Bottom-left: `(squareX - squareSize, squareY - squareSize)`.
       - Bottom-right: `(squareX + squareSize, squareY - squareSize)`.
       - Top-right: `(squareX + squareSize, squareY + squareSize)`.
       - Top-left: `(squareX - squareSize, squareY + squareSize)`.
  3. `glEnd()`:
     - Completes the definition of the square.

---

### **5. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(color);
    drawSquare();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Normal keys: R/G/B change color, C resets, Esc quits");
    drawText(-0.95f, 0.70f, "Arrow keys move the square (handled by glutSpecialFunc)");

    glutSwapBuffers();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3fv(color)`:
     - Sets the drawing color to the current value of `color`.
  3. `drawSquare()`:
     - Draws the square at its current position and size.
  4. `glColor3f(1.0f, 1.0f, 1.0f)`:
     - Sets the drawing color to white for rendering text.
  5. `drawText(...)`:
     - Displays instructions for interacting with the program.
  6. `glutSwapBuffers()`:
     - Swaps the front and back buffers to display the rendered content on the screen.
     - This is necessary because the program uses double buffering (`GLUT_DOUBLE` mode).

---

### **6. `handleNormalKeys` Function**
```c
void handleNormalKeys(unsigned char key, int, int)
{
    switch (key) {
    case 'r':
    case 'R':
        color[0] = 1.0f; color[1] = 0.1f; color[2] = 0.1f;
        break;
    case 'g':
    case 'G':
        color[0] = 0.2f; color[1] = 1.0f; color[2] = 0.2f;
        break;
    case 'b':
    case 'B':
        color[0] = 0.2f; color[1] = 0.5f; color[2] = 1.0f;
        break;
    case 'c':
    case 'C':
        color[0] = 0.2f; color[1] = 0.7f; color[2] = 1.0f;
        squareX = 0.0f;
        squareY = 0.0f;
        break;
    case 27:
        glutLeaveMainLoop();
        return;
    default:
        return;
    }

    glutPostRedisplay();
}
```
- **Purpose**: Handles normal keyboard input to change the square's color or exit the program.
- **Step-by-step breakdown**:
  1. Switches based on the pressed key:
     - `'r'` or `'R'`: Changes the color to red.
     - `'g'` or `'G'`: Changes the color to green.
     - `'b'` or `'B'`: Changes the color to blue.
     - `'c'` or `'C'`: Resets the color and moves the square back to the center.
     - `27` (Escape): Terminates the program.
  2. Calls `glutPostRedisplay()` to request a redraw of the window with the updated state.

---

### **7. `handleSpecialKeys` Function**
```c
void handleSpecialKeys(int key, int, int)
{
    const float step = 0.05f;
    switch (key) {
    case GLUT_KEY_LEFT:
        squareX -= step;
        break;
    case GLUT_KEY_RIGHT:
        squareX += step;
        break;
    case GLUT_KEY_UP:
        squareY += step;
        break;
    case GLUT_KEY_DOWN:
        squareY -= step;
        break;
    default:
        return;
    }

    glutPostRedisplay();
}
```
- **Purpose**: Handles special keyboard input (arrow keys) to move the square.
- **Step-by-step breakdown**:
  1. Switches based on the pressed special key:
     - `GLUT_KEY_LEFT`: Moves the square left by decreasing `squareX`.
     - `GLUT_KEY_RIGHT`: Moves the square right by increasing `squareX`.
     - `GLUT_KEY_UP`: Moves the square up by increasing `squareY`.
     - `GLUT_KEY_DOWN`: Moves the square down by decreasing `squareY`.
  2. Calls `glutPostRedisplay()` to request a redraw of the window with the updated position.

---

### **8. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(720, 520);
    glutCreateWindow("glutKeyboardFunc example with movement");

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleNormalKeys); // Demonstrating glutKeyboardFunc registering a normal key handler
    glutSpecialFunc(handleSpecialKeys); // Additional keyboard hook for arrow keys

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. Initializes FreeGLUT and sets up the display mode (`GLUT_DOUBLE | GLUT_RGB`).
  2. Creates a window with the title `"glutKeyboardFunc example with movement"`.
  3. Registers callback functions:
     - `display` for rendering.
     - `handleNormalKeys` for normal keyboard input.
     - `handleSpecialKeys` for special keyboard input (arrow keys).
  4. Enters the FreeGLUT event processing loop with `glutMainLoop`.

---

### **Output**
- A window titled `"glutKeyboardFunc example with movement"` appears.
- A square is displayed in the center of the window, initially light blue.
- Text instructions are displayed at the top of the window:
  - Normal keys (`R`, `G`, `B`, `C`) change the square's color or reset its position.
  - Arrow keys move the square.
- Pressing the **Escape** key exits the program.

---

### **Key Features**
1. **Interactive Input Handling**:
   - Normal keys (`R`, `G`, `B`, `C`) change the square's color or reset its position.
   - Special keys (arrow keys) move the square.

2. **Double Buffering**:
   - The program uses double buffering (`GLUT_DOUBLE`), which reduces flickering during rendering.

3. **Dynamic Redrawing**:
   - The `glutPostRedisplay` function requests GLUT to redraw the window whenever the state changes (e.g., color or position updates).

4. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_9_BY_15` font to render text instructions.

---


### CODE

#include <GL/freeglut.h>
#include <string>

float bgColor[3] = {0.1f, 0.1f, 0.2f};
float lastClickX = 0.0f;
float lastClickY = 0.0f;
std::string message = "Click anywhere";

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Left click: record position");
    drawText(-0.95f, 0.70f, "Right click: toggle background");
    drawText(-0.95f, 0.55f, "Middle click: reset");
    drawText(-0.95f, -0.10f, "Size +/- keys resize text position display");
    drawText(-0.95f, -0.25f, "Esc quits");

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Last click at %.2f, %.2f", lastClickX, lastClickY);
    drawText(-0.95f, 0.25f, buffer);

    drawText(-0.95f, 0.40f, message.c_str());

    glFlush();
}

void handleMouse(int button, int state, int x, int y)
{
    if (state != GLUT_DOWN) {
        return;
    }

    // Convert window coordinates to normalized device coordinates [-1, 1]
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    lastClickX = (static_cast<float>(x) / width) * 2.0f - 1.0f;
    lastClickY = 1.0f - (static_cast<float>(y) / height) * 2.0f;

    switch (button) {
    case GLUT_LEFT_BUTTON:
        message = "Left button pressed";
        break;
    case GLUT_RIGHT_BUTTON:
        message = "Right button pressed";
        if (bgColor[0] < 0.5f) {
            bgColor[0] = bgColor[1] = bgColor[2] = 0.8f;
        } else {
            bgColor[0] = 0.1f;
            bgColor[1] = 0.1f;
            bgColor[2] = 0.2f;
        }
        glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
        break;
    case GLUT_MIDDLE_BUTTON:
        message = "Middle button pressed - reset";
        lastClickX = 0.0f;
        lastClickY = 0.0f;
        bgColor[0] = 0.1f;
        bgColor[1] = 0.1f;
        bgColor[2] = 0.2f;
        glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
        break;
    default:
        message = "Unknown button";
        break;
    }

    glutPostRedisplay();
}

void handleKeyboard(unsigned char key, int, int)
{
    if (key == '+') {
        lastClickX = (lastClickX + 0.1f > 1.0f) ? 1.0f : lastClickX + 0.1f;
        lastClickY = (lastClickY + 0.1f > 1.0f) ? 1.0f : lastClickY + 0.1f;
    } else if (key == '-') {
        lastClickX = (lastClickX - 0.1f < -1.0f) ? -1.0f : lastClickX - 0.1f;
        lastClickY = (lastClickY - 0.1f < -1.0f) ? -1.0f : lastClickY - 0.1f;
    } else if (key == 27) {
        glutLeaveMainLoop();
        return;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 500);
    glutCreateWindow("glutMouseFunc demo");

    glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);       // Demonstrating glutMouseFunc callback registration
    glutKeyboardFunc(handleKeyboard); // Additional keyboard interactions

    glutMainLoop();
    return 0;
}


---

### **1. Header Files**
```c
#include <GL/freeglut.h>
#include <string>
```
- `GL/freeglut.h`: Includes the FreeGLUT library for creating windows, handling input, rendering text, and managing redraws.
- `string`: Used to store and manipulate the `message` string dynamically.

---

### **2. Global Variables**
```c
float bgColor[3] = {0.1f, 0.1f, 0.2f};
float lastClickX = 0.0f;
float lastClickY = 0.0f;
std::string message = "Click anywhere";
```
- **Purpose**: These variables define the state of the program:
  - `bgColor[3]`: The RGB background color of the window, initialized to a dark blue-gray (`0.1, 0.1, 0.2`).
  - `lastClickX`, `lastClickY`: The normalized device coordinates (NDC) of the last mouse click, initially `(0.0, 0.0)`.
  - `message`: A dynamic string that displays the most recent action or event.

---

### **3. `drawText` Function**
```c
void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a string of text at the specified position `(x, y)` using a bitmap font.
- **How it works**:
  1. `glRasterPos2f(x, y)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(x, y)` in NDC space.
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the `GLUT_BITMAP_HELVETICA_18` font.
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.

---

### **4. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Left click: record position");
    drawText(-0.95f, 0.70f, "Right click: toggle background");
    drawText(-0.95f, 0.55f, "Middle click: reset");
    drawText(-0.95f, -0.10f, "Size +/- keys resize text position display");
    drawText(-0.95f, -0.25f, "Esc quits");

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Last click at %.2f, %.2f", lastClickX, lastClickY);
    drawText(-0.95f, 0.25f, buffer);

    drawText(-0.95f, 0.40f, message.c_str());

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3f(1.0f, 1.0f, 1.0f)`:
     - Sets the drawing color to white for rendering text.
  3. `drawText(...)`:
     - Displays instructions for interacting with the program.
  4. `snprintf(buffer, sizeof(buffer), ...)`:
     - Formats the string `"Last click at %.2f, %.2f"` with the current `lastClickX` and `lastClickY` values.
  5. `drawText(-0.95f, 0.40f, message.c_str())`:
     - Displays the current `message` string.
  6. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.

---

### **5. `handleMouse` Function**
```c
void handleMouse(int button, int state, int x, int y)
{
    if (state != GLUT_DOWN) {
        return;
    }

    // Convert window coordinates to normalized device coordinates [-1, 1]
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    lastClickX = (static_cast<float>(x) / width) * 2.0f - 1.0f;
    lastClickY = 1.0f - (static_cast<float>(y) / height) * 2.0f;

    switch (button) {
    case GLUT_LEFT_BUTTON:
        message = "Left button pressed";
        break;
    case GLUT_RIGHT_BUTTON:
        message = "Right button pressed";
        if (bgColor[0] < 0.5f) {
            bgColor[0] = bgColor[1] = bgColor[2] = 0.8f;
        } else {
            bgColor[0] = 0.1f;
            bgColor[1] = 0.1f;
            bgColor[2] = 0.2f;
        }
        glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
        break;
    case GLUT_MIDDLE_BUTTON:
        message = "Middle button pressed - reset";
        lastClickX = 0.0f;
        lastClickY = 0.0f;
        bgColor[0] = 0.1f;
        bgColor[1] = 0.1f;
        bgColor[2] = 0.2f;
        glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
        break;
    default:
        message = "Unknown button";
        break;
    }

    glutPostRedisplay();
}
```
- **Purpose**: Handles mouse input to update the display based on the type of click.
- **Step-by-step breakdown**:
  1. Ignores events where the mouse button is not pressed (`state != GLUT_DOWN`).
  2. Converts the mouse's window coordinates `(x, y)` to normalized device coordinates (NDC):
     - `lastClickX = (x / width) * 2.0f - 1.0f`: Maps `x` from `[0, width]` to `[-1, 1]`.
     - `lastClickY = 1.0f - (y / height) * 2.0f`: Maps `y` from `[0, height]` to `[-1, 1]` (inverted because OpenGL's Y-axis increases upward).
  3. Switches based on the pressed mouse button:
     - `GLUT_LEFT_BUTTON`: Updates the `message` to indicate a left-click.
     - `GLUT_RIGHT_BUTTON`: Toggles the background color between light gray (`0.8, 0.8, 0.8`) and dark blue-gray (`0.1, 0.1, 0.2`).
     - `GLUT_MIDDLE_BUTTON`: Resets the `message`, `lastClickX`, `lastClickY`, and background color.
  4. Calls `glutPostRedisplay()` to request a redraw of the window with the updated state.

---

### **6. `handleKeyboard` Function**
```c
void handleKeyboard(unsigned char key, int, int)
{
    if (key == '+') {
        lastClickX = (lastClickX + 0.1f > 1.0f) ? 1.0f : lastClickX + 0.1f;
        lastClickY = (lastClickY + 0.1f > 1.0f) ? 1.0f : lastClickY + 0.1f;
    } else if (key == '-') {
        lastClickX = (lastClickX - 0.1f < -1.0f) ? -1.0f : lastClickX - 0.1f;
        lastClickY = (lastClickY - 0.1f < -1.0f) ? -1.0f : lastClickY - 0.1f;
    } else if (key == 27) {
        glutLeaveMainLoop();
        return;
    }

    glutPostRedisplay();
}
```
- **Purpose**: Handles keyboard input to adjust the `lastClickX` and `lastClickY` values or exit the program.
- **Step-by-step breakdown**:
  1. If the `'+'` key is pressed:
     - Increments `lastClickX` and `lastClickY` by `0.1`, clamping them to the range `[-1.0, 1.0]`.
  2. If the `'-'` key is pressed:
     - Decrements `lastClickX` and `lastClickY` by `0.1`, clamping them to the range `[-1.0, 1.0]`.
  3. If the **Escape** key (`ASCII 27`) is pressed:
     - Terminates the program using `glutLeaveMainLoop()`.
  4. Calls `glutPostRedisplay()` to request a redraw of the window with the updated state.

---

### **7. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 500);
    glutCreateWindow("glutMouseFunc demo");

    glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);       // Demonstrating glutMouseFunc callback registration
    glutKeyboardFunc(handleKeyboard); // Additional keyboard interactions

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. Initializes FreeGLUT and sets up the display mode (`GLUT_SINGLE | GLUT_RGB`).
  2. Creates a window with the title `"glutMouseFunc demo"`.
  3. Registers callback functions:
     - `display` for rendering.
     - `handleMouse` for handling mouse input.
     - `handleKeyboard` for handling keyboard input.
  4. Enters the FreeGLUT event processing loop with `glutMainLoop`.

---

### **Output**
- A window titled `"glutMouseFunc demo"` appears.
- The background is initially dark blue-gray.
- Text instructions are displayed at the top of the window:
  - Left click: Records the mouse position.
  - Right click: Toggles the background color.
  - Middle click: Resets the state.
  - `'+'`/`'-'` keys: Adjust the recorded mouse position.
  - Escape: Exits the program.
- Clicking the mouse updates the `message` and records the position.
- Pressing `'+'` or `'-'` adjusts the recorded position within the range `[-1.0, 1.0]`.

---

### **Key Features**
1. **Mouse Input Handling**:
   - Left click: Records the mouse position.
   - Right click: Toggles the background color.
   - Middle click: Resets the state.

2. **Keyboard Input Handling**:
   - `'+'`/`'-'` keys: Adjust the recorded mouse position.
   - Escape: Exits the program.

3. **Dynamic Redrawing**:
   - The `glutPostRedisplay` function requests GLUT to redraw the window whenever the state changes.

4. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font to render text instructions.

---

### CODE

#include <GL/freeglut.h>
#include <string>

float cursorX = 0.0f;
float cursorY = 0.0f;
bool isLeftDown = false;
std::string message = "Drag with left mouse button";

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Drag the mouse: tracks normalized position");
    drawText(-0.95f, 0.70f, "Press R to reset, Esc to quit");

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Current cursor: %.2f, %.2f", cursorX, cursorY);
    drawText(-0.95f, 0.40f, buffer);
    drawText(-0.95f, 0.25f, message.c_str());

    glColor3f(0.2f, 0.8f, 0.4f);
    glPointSize(8.0f);
    glBegin(GL_POINTS);
        glVertex2f(cursorX, cursorY);
    glEnd();

    glFlush();
}

void handleMouse(int button, int state, int, int)
{
    if (button == GLUT_LEFT_BUTTON) {
        isLeftDown = (state == GLUT_DOWN);
        message = isLeftDown ? "Dragging active" : "Drag with left mouse button";
    }
}

void handleMotion(int x, int y)
{
    if (!isLeftDown) {
        return;
    }

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    cursorX = (static_cast<float>(x) / width) * 2.0f - 1.0f;
    cursorY = 1.0f - (static_cast<float>(y) / height) * 2.0f;

    glutPostRedisplay();
}

void handleKeyboard(unsigned char key, int, int)
{
    if (key == 'r' || key == 'R') {
        cursorX = 0.0f;
        cursorY = 0.0f;
        message = "Position reset";
        glutPostRedisplay();
    } else if (key == 27) {
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480);
    glutCreateWindow("glutMotionFunc demo");

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);
    glutMotionFunc(handleMotion);     // Demonstrating glutMotionFunc registering motion callback
    glutKeyboardFunc(handleKeyboard);

    glutMainLoop();
    return 0;
}



---

### **1. Header Files**
```c
#include <GL/freeglut.h>
#include <string>
```
- `GL/freeglut.h`: Includes the FreeGLUT library for creating windows, handling input, rendering text, and managing redraws.
- `string`: Used to store and manipulate the `message` string dynamically.

---

### **2. Global Variables**
```c
float cursorX = 0.0f;
float cursorY = 0.0f;
bool isLeftDown = false;
std::string message = "Drag with left mouse button";
```
- **Purpose**: These variables define the state of the program:
  - `cursorX`, `cursorY`: The normalized device coordinates (NDC) of the current mouse position, initially `(0.0, 0.0)`.
  - `isLeftDown`: A boolean flag indicating whether the left mouse button is pressed.
  - `message`: A dynamic string that displays the most recent action or event.

---

### **3. `drawText` Function**
```c
void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a string of text at the specified position `(x, y)` using a bitmap font.
- **How it works**:
  1. `glRasterPos2f(x, y)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(x, y)` in NDC space.
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the `GLUT_BITMAP_HELVETICA_18` font.
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.

---

### **4. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Drag the mouse: tracks normalized position");
    drawText(-0.95f, 0.70f, "Press R to reset, Esc to quit");

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Current cursor: %.2f, %.2f", cursorX, cursorY);
    drawText(-0.95f, 0.40f, buffer);
    drawText(-0.95f, 0.25f, message.c_str());

    glColor3f(0.2f, 0.8f, 0.4f);
    glPointSize(8.0f);
    glBegin(GL_POINTS);
        glVertex2f(cursorX, cursorY);
    glEnd();

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3f(1.0f, 1.0f, 1.0f)`:
     - Sets the drawing color to white for rendering text.
  3. `drawText(...)`:
     - Displays instructions for interacting with the program.
  4. `snprintf(buffer, sizeof(buffer), ...)`:
     - Formats the string `"Current cursor: %.2f, %.2f"` with the current `cursorX` and `cursorY` values.
  5. `drawText(-0.95f, 0.25f, message.c_str())`:
     - Displays the current `message` string.
  6. `glColor3f(0.2f, 0.8f, 0.4f)`:
     - Sets the drawing color to a light green for rendering the cursor point.
  7. `glPointSize(8.0f)`:
     - Sets the size of the point to 8 pixels.
  8. `glBegin(GL_POINTS)`:
     - Draws a single point at the current `cursorX` and `cursorY` position.
  9. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.

---

### **5. `handleMouse` Function**
```c
void handleMouse(int button, int state, int, int)
{
    if (button == GLUT_LEFT_BUTTON) {
        isLeftDown = (state == GLUT_DOWN);
        message = isLeftDown ? "Dragging active" : "Drag with left mouse button";
    }
}
```
- **Purpose**: Handles mouse button events to track when the left mouse button is pressed or released.
- **Step-by-step breakdown**:
  1. Checks if the left mouse button (`GLUT_LEFT_BUTTON`) is involved.
  2. Updates the `isLeftDown` flag based on whether the button is pressed (`GLUT_DOWN`) or released.
  3. Updates the `message` string to indicate whether dragging is active or inactive.

---

### **6. `handleMotion` Function**
```c
void handleMotion(int x, int y)
{
    if (!isLeftDown) {
        return;
    }

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    cursorX = (static_cast<float>(x) / width) * 2.0f - 1.0f;
    cursorY = 1.0f - (static_cast<float>(y) / height) * 2.0f;

    glutPostRedisplay();
}
```
- **Purpose**: Tracks the mouse position while the left button is pressed and updates the cursor's normalized coordinates.
- **Step-by-step breakdown**:
  1. Ignores motion events if the left mouse button is not pressed (`!isLeftDown`).
  2. Retrieves the window's width and height using `glutGet`.
  3. Converts the mouse's window coordinates `(x, y)` to normalized device coordinates (NDC):
     - `cursorX = (x / width) * 2.0f - 1.0f`: Maps `x` from `[0, width]` to `[-1, 1]`.
     - `cursorY = 1.0f - (y / height) * 2.0f`: Maps `y` from `[0, height]` to `[-1, 1]` (inverted because OpenGL's Y-axis increases upward).
  4. Calls `glutPostRedisplay()` to request a redraw of the window with the updated cursor position.

---

### **7. `handleKeyboard` Function**
```c
void handleKeyboard(unsigned char key, int, int)
{
    if (key == 'r' || key == 'R') {
        cursorX = 0.0f;
        cursorY = 0.0f;
        message = "Position reset";
        glutPostRedisplay();
    } else if (key == 27) {
        glutLeaveMainLoop();
    }
}
```
- **Purpose**: Handles keyboard input to reset the cursor position or exit the program.
- **Step-by-step breakdown**:
  1. If the `'R'` key is pressed:
     - Resets `cursorX` and `cursorY` to `(0.0, 0.0)`.
     - Updates the `message` string to indicate the reset.
     - Calls `glutPostRedisplay()` to update the display.
  2. If the **Escape** key (`ASCII 27`) is pressed:
     - Terminates the program using `glutLeaveMainLoop()`.

---

### **8. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480);
    glutCreateWindow("glutMotionFunc demo");

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);
    glutMotionFunc(handleMotion);     // Demonstrating glutMotionFunc registering motion callback
    glutKeyboardFunc(handleKeyboard);

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. Initializes FreeGLUT and sets up the display mode (`GLUT_SINGLE | GLUT_RGB`).
  2. Creates a window with the title `"glutMotionFunc demo"`.
  3. Registers callback functions:
     - `display` for rendering.
     - `handleMouse` for handling mouse button events.
     - `handleMotion` for handling mouse motion events.
     - `handleKeyboard` for handling keyboard input.
  4. Enters the FreeGLUT event processing loop with `glutMainLoop`.

---

### **Output**
- A window titled `"glutMotionFunc demo"` appears.
- The background is dark gray (`0.05, 0.05, 0.05`).
- Text instructions are displayed at the top of the window:
  - Dragging the mouse updates the cursor's normalized position.
  - Pressing `'R'` resets the cursor position.
  - Pressing **Escape** exits the program.
- A green dot represents the cursor's position, which moves as the mouse is dragged while the left button is pressed.
- The current cursor position and status are displayed dynamically.

---

### **Key Features**
1. **Mouse Dragging**:
   - Tracks the mouse position while the left button is pressed using `glutMotionFunc`.

2. **Keyboard Input Handling**:
   - `'R'` resets the cursor position.
   - **Escape** exits the program.

3. **Dynamic Redrawing**:
   - The `glutPostRedisplay` function requests GLUT to redraw the window whenever the state changes.

4. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font to render text instructions.

---


### CODE

#include <GL/freeglut.h>
#include <cmath>

float angle = 0.0f;
bool animate = true;

void drawRotatingTriangle()
{
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.2f, 0.2f);
        glVertex2f(0.0f, 0.6f);
        glColor3f(0.2f, 0.8f, 0.2f);
        glVertex2f(-0.5f, -0.3f);
        glColor3f(0.2f, 0.2f, 1.0f);
        glVertex2f(0.5f, -0.3f);
    glEnd();

    glPopMatrix();
}

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawRotatingTriangle();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Timer updates rotation every 16 ms");
    drawText(-0.95f, 0.70f, "Press space to pause/resume, Esc to quit");

    glutSwapBuffers();
}

void updateTimer(int)
{
    if (animate) {
        angle += 2.5f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        glutPostRedisplay();
    }

    glutTimerFunc(16, updateTimer, 0); // Demonstrating glutTimerFunc scheduling a periodic callback
}

void handleKeyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        animate = !animate;
    } else if (key == 27) {
        glutLeaveMainLoop();
        return;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(720, 520);
    glutCreateWindow("glutTimerFunc rotation demo");

    glClearColor(0.05f, 0.05f, 0.10f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutTimerFunc(0, updateTimer, 0); // Start timer loop with glutTimerFunc

    glutMainLoop();
    return 0;
}


---

### **1. Header Files**
```c
#include <GL/freeglut.h>
#include <cmath>
```
- `GL/freeglut.h`: Includes the FreeGLUT library for creating windows, handling input, rendering shapes, and managing timers.
- `cmath`: Provides mathematical functions (though not directly used in this example).

---

### **2. Global Variables**
```c
float angle = 0.0f;
bool animate = true;
```
- **Purpose**: These variables define the state of the program:
  - `angle`: The current rotation angle of the triangle in degrees.
  - `animate`: A boolean flag indicating whether the animation is active.

---

### **3. `drawRotatingTriangle` Function**
```c
void drawRotatingTriangle()
{
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.2f, 0.2f);
        glVertex2f(0.0f, 0.6f);
        glColor3f(0.2f, 0.8f, 0.2f);
        glVertex2f(-0.5f, -0.3f);
        glColor3f(0.2f, 0.2f, 1.0f);
        glVertex2f(0.5f, -0.3f);
    glEnd();

    glPopMatrix();
}
```
- **Purpose**: Draws a rotating triangle with vertex colors.
- **Step-by-step breakdown**:
  1. `glPushMatrix()`:
     - Saves the current transformation matrix.
  2. `glRotatef(angle, 0.0f, 0.0f, 1.0f)`:
     - Applies a rotation transformation around the Z-axis by `angle` degrees.
  3. `glBegin(GL_TRIANGLES)`:
     - Begins defining a triangle.
  4. `glColor3f(...)` and `glVertex2f(...)`:
     - Specifies the color and position of each vertex:
       - Top vertex: Red (`1.0, 0.2, 0.2`) at `(0.0, 0.6)`.
       - Bottom-left vertex: Green (`0.2, 0.8, 0.2`) at `(-0.5, -0.3)`.
       - Bottom-right vertex: Blue (`0.2, 0.2, 1.0`) at `(0.5, -0.3)`.
  5. `glEnd()`:
     - Completes the definition of the triangle.
  6. `glPopMatrix()`:
     - Restores the previous transformation matrix.

---

### **4. `drawText` Function**
```c
void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a string of text at the specified position `(x, y)` using a bitmap font.
- **How it works**:
  1. `glRasterPos2f(x, y)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(x, y)` in normalized device coordinates (NDC).
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the `GLUT_BITMAP_HELVETICA_18` font.
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.

---

### **5. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawRotatingTriangle();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Timer updates rotation every 16 ms");
    drawText(-0.95f, 0.70f, "Press space to pause/resume, Esc to quit");

    glutSwapBuffers();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `drawRotatingTriangle()`:
     - Draws the rotating triangle with the current rotation angle.
  3. `glColor3f(1.0f, 1.0f, 1.0f)`:
     - Sets the drawing color to white for rendering text.
  4. `drawText(...)`:
     - Displays instructions for interacting with the program.
  5. `glutSwapBuffers()`:
     - Swaps the front and back buffers to display the rendered content on the screen.
     - This is necessary because the program uses double buffering (`GLUT_DOUBLE` mode).

---

### **6. `updateTimer` Function**
```c
void updateTimer(int)
{
    if (animate) {
        angle += 2.5f;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        glutPostRedisplay();
    }

    glutTimerFunc(16, updateTimer, 0); // Demonstrating glutTimerFunc scheduling a periodic callback
}
```
- **Purpose**: Updates the rotation angle periodically using a timer callback.
- **Step-by-step breakdown**:
  1. If `animate` is `true`:
     - Increments the `angle` by `2.5` degrees.
     - Wraps the angle back to `0` if it exceeds `360` degrees.
     - Calls `glutPostRedisplay()` to request a redraw of the window with the updated angle.
  2. `glutTimerFunc(16, updateTimer, 0)`:
     - Schedules the next timer event after approximately 16 milliseconds (about 60 frames per second).

---

### **7. `handleKeyboard` Function**
```c
void handleKeyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        animate = !animate;
    } else if (key == 27) {
        glutLeaveMainLoop();
        return;
    }

    glutPostRedisplay();
}
```
- **Purpose**: Handles keyboard input to toggle animation or exit the program.
- **Step-by-step breakdown**:
  1. If the **spacebar** is pressed:
     - Toggles the `animate` flag to pause or resume the animation.
  2. If the **Escape** key (`ASCII 27`) is pressed:
     - Terminates the program using `glutLeaveMainLoop()`.
  3. Calls `glutPostRedisplay()` to ensure the display is updated immediately.

---

### **8. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(720, 520);
    glutCreateWindow("glutTimerFunc rotation demo");

    glClearColor(0.05f, 0.05f, 0.10f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutTimerFunc(0, updateTimer, 0); // Start timer loop with glutTimerFunc

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. Initializes FreeGLUT and sets up the display mode (`GLUT_DOUBLE | GLUT_RGB`).
  2. Creates a window with the title `"glutTimerFunc rotation demo"`.
  3. Registers callback functions:
     - `display` for rendering.
     - `handleKeyboard` for handling keyboard input.
     - `updateTimer` for updating the animation periodically.
  4. Enters the FreeGLUT event processing loop with `glutMainLoop`.

---

### **Output**
- A window titled `"glutTimerFunc rotation demo"` appears.
- A triangle rotates continuously around its center, with each vertex colored differently (red, green, blue).
- Text instructions are displayed at the top of the window:
  - The timer updates the rotation every 16 milliseconds (~60 FPS).
  - Pressing the **spacebar** pauses or resumes the animation.
  - Pressing **Escape** exits the program.
- The background is dark blue-gray (`0.05, 0.05, 0.10`).

---

### **Key Features**
1. **Periodic Updates**:
   - The `glutTimerFunc` function schedules periodic updates to the rotation angle, creating smooth animation.

2. **Keyboard Input Handling**:
   - The **spacebar** toggles the animation on/off.
   - The **Escape** key exits the program.

3. **Double Buffering**:
   - The program uses double buffering (`GLUT_DOUBLE`), which reduces flickering during rendering.

4. **Transformation Matrix**:
   - The `glPushMatrix` and `glPopMatrix` functions ensure that transformations (e.g., rotation) do not affect other parts of the scene.

5. **Dynamic Redrawing**:
   - The `glutPostRedisplay` function requests GLUT to redraw the window whenever the state changes.

---


### CODE

#include <GL/freeglut.h>

bool showInstructions = true;

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    if (showInstructions) {
        drawText(-0.85f, 0.2f, "Press space to toggle the message");
    } else {
        drawText(-0.85f, 0.2f, "glutKeyboardFunc handled the key press!");
    }
    drawText(-0.85f, -0.1f, "Press Esc to exit");

    glFlush();
}

void handleKeyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        showInstructions = !showInstructions;
        glutPostRedisplay();
    } else if (key == 27) {
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("glutKeyboardFunc basic example");

    glClearColor(0.0f, 0.0f, 0.15f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // Demonstrating glutKeyboardFunc registering keyboard handler

    glutMainLoop();
    return 0;
}


---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library, which provides utilities for creating windows, handling input, rendering text, and managing redraws.

---

### **2. Global Variable**
```c
bool showInstructions = true;
```
- **Purpose**: A boolean flag that determines whether to display instructions or a confirmation message.
  - When `true`, the program displays `"Press space to toggle the message"`.
  - When `false`, the program displays `"glutKeyboardFunc handled the key press!"`.

---

### **3. `drawText` Function**
```c
void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a string of text at the specified position `(x, y)` using a bitmap font.
- **How it works**:
  1. `glRasterPos2f(x, y)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(x, y)` in normalized device coordinate (NDC) space.
     - NDC space ranges from `-1.0` to `1.0` in both the x and y directions.
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the `GLUT_BITMAP_HELVETICA_18` font.
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.

---

### **4. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    if (showInstructions) {
        drawText(-0.85f, 0.2f, "Press space to toggle the message");
    } else {
        drawText(-0.85f, 0.2f, "glutKeyboardFunc handled the key press!");
    }
    drawText(-0.85f, -0.1f, "Press Esc to exit");

    glFlush();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `glColor3f(1.0f, 1.0f, 1.0f)`:
     - Sets the drawing color to white for rendering text.
  3. Conditional rendering:
     - If `showInstructions` is `true`, the program displays `"Press space to toggle the message"`.
     - Otherwise, it displays `"glutKeyboardFunc handled the key press!"`.
  4. `drawText(-0.85f, -0.1f, "Press Esc to exit")`:
     - Displays instructions for exiting the program.
  5. `glFlush()`:
     - Ensures that all OpenGL commands are executed immediately and sent to the graphics hardware for rendering.

---

### **5. `handleKeyboard` Function**
```c
void handleKeyboard(unsigned char key, int, int)
{
    if (key == ' ') {
        showInstructions = !showInstructions;
        glutPostRedisplay();
    } else if (key == 27) {
        glutLeaveMainLoop();
    }
}
```
- **Purpose**: Handles keyboard input to toggle the message or exit the program.
- **Step-by-step breakdown**:
  1. If the **spacebar** (`' '`) is pressed:
     - Toggles the `showInstructions` flag between `true` and `false`.
     - Calls `glutPostRedisplay()` to request a redraw of the window with the updated message.
  2. If the **Escape** key (`ASCII 27`) is pressed:
     - Terminates the program using `glutLeaveMainLoop()`.

---

### **6. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("glutKeyboardFunc basic example");

    glClearColor(0.0f, 0.0f, 0.15f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard); // Demonstrating glutKeyboardFunc registering keyboard handler

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. `glutInit(&argc, argv)`:
     - Initializes the FreeGLUT library.
  2. `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`:
     - Sets the display mode:
       - `GLUT_SINGLE`: Uses single buffering (no back buffer).
       - `GLUT_RGB`: Uses the RGB color model.
  3. `glutInitWindowSize(600, 400)`:
     - Requests the creation of a window with a size of **600x400 pixels**.
  4. `glutCreateWindow("glutKeyboardFunc basic example")`:
     - Creates a window with the title `"glutKeyboardFunc basic example"`.
  5. `glClearColor(0.0f, 0.0f, 0.15f, 1.0f)`:
     - Sets the background color of the window to dark blue (`RGB: 0.0, 0.0, 0.15`).
  6. `glutDisplayFunc(display)`:
     - Registers the `display` function as the callback for rendering the window contents.
  7. `glutKeyboardFunc(handleKeyboard)`:
     - Registers the `handleKeyboard` function as the callback for handling keyboard input.
  8. `glutMainLoop()`:
     - Enters the FreeGLUT event processing loop, which waits for user input and redraws the window as needed.

---

### **Output**
- A window titled `"glutKeyboardFunc basic example"` appears.
- The background is dark blue.
- Initially, the text `"Press space to toggle the message"` is displayed in white near the center of the window.
- Pressing the **spacebar** toggles between two messages:
  1. `"Press space to toggle the message"`.
  2. `"glutKeyboardFunc handled the key press!"`.
- The text `"Press Esc to exit"` is displayed below the main message.
- Pressing the **Escape** key exits the program.

---

### **Key Features**
1. **Keyboard Input Handling**:
   - The program listens for keyboard input using the `glutKeyboardFunc` callback.
   - Pressing the **spacebar** toggles the `showInstructions` flag and triggers a redraw.
   - Pressing the **Escape** key terminates the program.

2. **Dynamic Redrawing**:
   - The `glutPostRedisplay` function requests GLUT to redraw the window whenever the state changes (e.g., toggling the message).

3. **Bitmap Font Rendering**:
   - The program uses the `GLUT_BITMAP_HELVETICA_18` font, which is a predefined Helvetica-style font with a height of 18 pixels.
   - The `glutBitmapString` function renders the entire string at once.

4. **Single Buffering**:
   - The program uses single buffering (`GLUT_SINGLE`), which means there is no separate back buffer for rendering. Instead, rendering occurs directly to the front buffer.
   - Single buffering is simpler but may result in flickering during rendering.

---



### CODE

#include <GL/freeglut.h>

float alpha = 1.0f;
bool fadingOut = true;
bool timerRunning = true;

void drawQuad()
{
    glColor4f(0.2f, 0.6f, 1.0f, alpha);
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();
}

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawQuad();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Timer adjusts alpha every 50 ms");
    drawText(-0.95f, 0.70f, "Press space to pause/resume, Esc to quit");
    drawText(-0.95f, 0.55f, "Press R to reset alpha");

    glutSwapBuffers();
}

void updateAlpha(int)
{
    if (timerRunning) {
        const float step = 0.05f;
        if (fadingOut) {
            alpha -= step;
            if (alpha <= 0.2f) {
                alpha = 0.2f;
                fadingOut = false;
            }
        } else {
            alpha += step;
            if (alpha >= 1.0f) {
                alpha = 1.0f;
                fadingOut = true;
            }
        }
        glutPostRedisplay();
    }

    glutTimerFunc(50, updateAlpha, 0); // Demonstrating glutTimerFunc scheduling repeated alpha updates
}

void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        timerRunning = !timerRunning;
        break;
    case 'r':
    case 'R':
        alpha = 1.0f;
        fadingOut = true;
        timerRunning = true;
        break;
    case 27:
        glutLeaveMainLoop();
        return;
    default:
        return;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
    glutInitWindowSize(640, 480);
    glutCreateWindow("glutTimerFunc alpha fade");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND); // Enable blending so alpha values affect rendering
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutTimerFunc(0, updateAlpha, 0); // Kick off timer loop with glutTimerFunc

    glutMainLoop();
    return 0;
}



---

### **1. Header File**
```c
#include <GL/freeglut.h>
```
- This includes the FreeGLUT library for creating windows, handling input, rendering shapes, and managing timers.

---

### **2. Global Variables**
```c
float alpha = 1.0f;
bool fadingOut = true;
bool timerRunning = true;
```
- **Purpose**: These variables define the state of the program:
  - `alpha`: The current transparency level of the rectangle (ranges from `0.2` to `1.0`).
  - `fadingOut`: A boolean flag indicating whether the rectangle is fading out (`true`) or fading in (`false`).
  - `timerRunning`: A boolean flag indicating whether the timer is active (`true`) or paused (`false`).

---

### **3. `drawQuad` Function**
```c
void drawQuad()
{
    glColor4f(0.2f, 0.6f, 1.0f, alpha);
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();
}
```
- **Purpose**: Draws a blue rectangle with a specified transparency (`alpha`).
- **Step-by-step breakdown**:
  1. `glColor4f(0.2f, 0.6f, 1.0f, alpha)`:
     - Sets the drawing color to a light blue (`RGB: 0.2, 0.6, 1.0`) with the current `alpha` value.
  2. `glBegin(GL_QUADS)`:
     - Begins defining a quadrilateral (rectangle).
  3. `glVertex2f(...)`:
     - Specifies the four corners of the rectangle:
       - Bottom-left: `(-0.4, -0.4)`.
       - Bottom-right: `(0.4, -0.4)`.
       - Top-right: `(0.4, 0.4)`.
       - Top-left: `(-0.4, 0.4)`.
  4. `glEnd()`:
     - Completes the definition of the rectangle.

---

### **4. `drawText` Function**
```c
void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     reinterpret_cast<const unsigned char*>(text));
}
```
- **Purpose**: Renders a string of text at the specified position `(x, y)` using a bitmap font.
- **How it works**:
  1. `glRasterPos2f(x, y)`:
     - Sets the raster position (where the text will start rendering) to the coordinates `(x, y)` in normalized device coordinate (NDC) space.
  2. `glutBitmapString(font, reinterpret_cast<const unsigned char*>(text))`:
     - Renders the string `text` using the `GLUT_BITMAP_HELVETICA_18` font.
     - The `reinterpret_cast` ensures compatibility between `const char*` and `const unsigned char*`.

---

### **5. `display` Function**
```c
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawQuad();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.85f, "Timer adjusts alpha every 50 ms");
    drawText(-0.95f, 0.70f, "Press space to pause/resume, Esc to quit");
    drawText(-0.95f, 0.55f, "Press R to reset alpha");

    glutSwapBuffers();
}
```
- **Purpose**: Defines what is drawn in the OpenGL window.
- **Step-by-step breakdown**:
  1. `glClear(GL_COLOR_BUFFER_BIT)`:
     - Clears the color buffer (the screen) to prepare it for rendering.
     - The background color is set by `glClearColor` in the `main` function.
  2. `drawQuad()`:
     - Draws the blue rectangle with the current `alpha` value.
  3. `glColor3f(1.0f, 1.0f, 1.0f)`:
     - Sets the drawing color to white for rendering text.
  4. `drawText(...)`:
     - Displays instructions for interacting with the program.
  5. `glutSwapBuffers()`:
     - Swaps the front and back buffers to display the rendered content on the screen.
     - This is necessary because the program uses double buffering (`GLUT_DOUBLE` mode).

---

### **6. `updateAlpha` Function**
```c
void updateAlpha(int)
{
    if (timerRunning) {
        const float step = 0.05f;
        if (fadingOut) {
            alpha -= step;
            if (alpha <= 0.2f) {
                alpha = 0.2f;
                fadingOut = false;
            }
        } else {
            alpha += step;
            if (alpha >= 1.0f) {
                alpha = 1.0f;
                fadingOut = true;
            }
        }
        glutPostRedisplay();
    }

    glutTimerFunc(50, updateAlpha, 0); // Demonstrating glutTimerFunc scheduling repeated alpha updates
}
```
- **Purpose**: Updates the `alpha` value periodically to create a fading effect.
- **Step-by-step breakdown**:
  1. If `timerRunning` is `true`:
     - Decreases `alpha` by `0.05` when fading out.
     - Increases `alpha` by `0.05` when fading in.
     - Clamps `alpha` to the range `[0.2, 1.0]`.
     - Toggles `fadingOut` when the limits are reached.
     - Calls `glutPostRedisplay()` to request a redraw of the window with the updated `alpha`.
  2. `glutTimerFunc(50, updateAlpha, 0)`:
     - Schedules the next timer event after 50 milliseconds, creating a smooth animation loop.

---

### **7. `handleKeyboard` Function**
```c
void handleKeyboard(unsigned char key, int, int)
{
    switch (key) {
    case ' ':
        timerRunning = !timerRunning;
        break;
    case 'r':
    case 'R':
        alpha = 1.0f;
        fadingOut = true;
        timerRunning = true;
        break;
    case 27:
        glutLeaveMainLoop();
        return;
    default:
        return;
    }
    glutPostRedisplay();
}
```
- **Purpose**: Handles keyboard input to control the animation or exit the program.
- **Step-by-step breakdown**:
  1. If the **spacebar** is pressed:
     - Toggles the `timerRunning` flag to pause or resume the animation.
  2. If the `'R'` key is pressed:
     - Resets `alpha` to `1.0`, sets `fadingOut` to `true`, and resumes the animation.
  3. If the **Escape** key (`ASCII 27`) is pressed:
     - Terminates the program using `glutLeaveMainLoop()`.
  4. Calls `glutPostRedisplay()` to ensure the display is updated immediately.

---

### **8. `main` Function**
```c
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
    glutInitWindowSize(640, 480);
    glutCreateWindow("glutTimerFunc alpha fade");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND); // Enable blending so alpha values affect rendering
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutTimerFunc(0, updateAlpha, 0); // Kick off timer loop with glutTimerFunc

    glutMainLoop();
    return 0;
}
```
- **Purpose**: Initializes the FreeGLUT environment and starts the rendering loop.
- **Step-by-step breakdown**:
  1. Initializes FreeGLUT and sets up the display mode (`GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA`).
  2. Creates a window with the title `"glutTimerFunc alpha fade"`.
  3. Registers callback functions:
     - `display` for rendering.
     - `handleKeyboard` for handling keyboard input.
     - `updateAlpha` for updating the animation periodically.
  4. Enters the FreeGLUT event processing loop with `glutMainLoop`.

---

### **Output**
- A window titled `"glutTimerFunc alpha fade"` appears.
- A blue rectangle fades in and out smoothly.
- Text instructions are displayed at the top of the window:
  - The timer updates the rectangle's transparency every 50 milliseconds.
  - Pressing the **spacebar** pauses or resumes the animation.
  - Pressing `'R'` resets the rectangle's transparency to fully opaque.
  - Pressing **Escape** exits the program.
- The background is black (`RGB: 0.0, 0.0, 0.0`).

---

### **Key Features**
1. **Alpha Blending**:
   - The program uses `glEnable(GL_BLEND)` and `glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)` to enable transparency effects.

2. **Timer-Based Animation**:
   - The `glutTimerFunc` function schedules periodic updates to the rectangle's transparency, creating a smooth fading effect.

3. **Keyboard Input Handling**:
   - The program listens for keyboard input using the `glutKeyboardFunc` callback.
   - Pressing the **spacebar** toggles the animation.
   - Pressing `'R'` resets the animation.
   - Pressing **Escape** exits the program.

4. **Double Buffering**:
   - The program uses double buffering (`GLUT_DOUBLE`), which reduces flickering during rendering.

---
