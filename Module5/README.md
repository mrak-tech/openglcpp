### **Module 5 Subtopic 1: Glut Extensions**

#### **1. Text & Raster Positioning Functions**
These functions are used for rendering text or pixel-based operations in OpenGL using GLUT.

##### **a. `glRasterPos2f(float x, float y)`**
- **Purpose**: Sets the current raster position in 2D space for rendering bitmap text or images.
- **Parameters**: 
  - `x`, `y`: Floating-point coordinates in object space.
- **Usage Context**: Defines where bitmap text or pixel images will be drawn. The position is transformed by the current model-view and projection matrices.
- **Syntax**:
  ```c
  glRasterPos2f(GLfloat x, GLfloat y);
  ```
- **Example**:
  ```c
  void textSample() {
      glClear(GL_COLOR_BUFFER_BIT);
      const unsigned char str[] = "FEU-TECH";
      glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
      glRasterPos2f(0.0, 0.0);     // Set raster position to (0, 0)
      glutBitmapString(GLUT_BITMAP_HELVETICA_18, str); // Render text
      glFlush();
  }
  ```

##### **b. `glutBitmapString(void* font, const unsigned char* string)`**
- **Purpose**: Renders a string of bitmap characters at the current raster position using a specified GLUT bitmap font.
- **Parameters**:
  - `font`: A constant specifying the font type (e.g., `GLUT_BITMAP_HELVETICA_18`).
  - `string`: The text to be rendered.
- **Syntax**:
  ```c
  glutBitmapString(void* font, const unsigned char* string);
  ```
- **Example**:
  ```c
  void renderText() {
      const unsigned char text[] = "Hello, GLUT!";
      glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
      glRasterPos2f(-0.5, 0.0);    // Set raster position
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, text); // Render text
      glFlush();
  }
  ```

---

#### **2. Available GLUT Font Constants**
These constants define the font styles available for rendering text.

##### **a. Bitmap Fonts**
- **Examples**:
  - `GLUT_BITMAP_9_BY_15`: Fixed-size bitmap font, 9 pixels wide and 15 pixels tall.
  - `GLUT_BITMAP_HELVETICA_18`: Helvetica-style bitmap font with 18-point height.
- **Use Case**: Suitable for rendering small, readable text in 2D overlays or HUDs.

##### **b. Stroke Fonts**
- **Examples**:
  - `GLUT_STROKE_ROMAN`: Scalable vector-based text rendered using line segments.
  - `GLUT_STROKE_MONO_ROMAN`: Monospaced stroke font.
- **Use Case**: Ideal for zoomable or transformable text in 3D scenes.

---

### **Module 5 Subtopic 2: GLUT Callbacks**

#### **1. Window Initialization & Configuration**
These functions handle the creation and setup of the OpenGL window.

##### **a. `glutInit(int* argc, char** argv)`**
- **Purpose**: Initializes the GLUT library. Must be called once at the start of the program.
- **Syntax**:
  ```c
  glutInit(int* argc, char** argv);
  ```
- **Example**:
  ```c
  int main(int argc, char** argv) {
      glutInit(&argc, argv);
      return 0;
  }
  ```

##### **b. `glutInitWindowSize(int width, int height)`**
- **Purpose**: Sets the initial size of the window.
- **Syntax**:
  ```c
  glutInitWindowSize(int width, int height);
  ```
- **Example**:
  ```c
  glutInitWindowSize(1024, 768); // Set window size to 1024x768
  ```

##### **c. `glutCreateWindow(const char* title)`**
- **Purpose**: Creates a top-level window with the specified title.
- **Syntax**:
  ```c
  glutCreateWindow(const char* title);
  ```
- **Example**:
  ```c
  glutCreateWindow("My First OpenGL"); // Create a window titled "My First OpenGL"
  ```

##### **d. `glutFullScreen()`**
- **Purpose**: Requests the current window to be made full-screen.
- **Syntax**:
  ```c
  glutFullScreen();
  ```

##### **e. `glutPostRedisplay()`**
- **Purpose**: Marks the current window as needing to be redrawn. Often used in callbacks.
- **Syntax**:
  ```c
  glutPostRedisplay();
  ```

---

#### **2. Input Handling Functions**
These functions handle user interactions like keyboard, mouse, and motion events.

##### **a. `glutDisplayFunc(void (*func)(void))`**
- **Purpose**: Sets the display callback for the current window.
- **Syntax**:
  ```c
  glutDisplayFunc(void (*func)(void));
  ```
- **Example**:
  ```c
  void defaultDisplay() {
      glClear(GL_COLOR_BUFFER_BIT);
      glutSwapBuffers();
  }
  glutDisplayFunc(defaultDisplay);
  ```

##### **b. `glutKeyboardFunc(void (*func)(unsigned char key, int x, int y))`**
- **Purpose**: Sets the keyboard callback for handling key presses.
- **Syntax**:
  ```c
  glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));
  ```
- **Example**:
  ```c
  void keyboardMonitor(unsigned char key, int x, int y) {
      if (key == 'a') {
          printf("Key 'a' pressed.\n");
      }
  }
  glutKeyboardFunc(keyboardMonitor);
  ```

##### **c. `glutMouseFunc(void (*func)(int button, int state, int x, int y))`**
- **Purpose**: Sets the mouse callback for handling button presses and releases.
- **Syntax**:
  ```c
  glutMouseFunc(void (*func)(int button, int state, int x, int y));
  ```
- **Example**:
  ```c
  void mouseMonitor(int button, int state, int x, int y) {
      if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
          printf("Left mouse button clicked at (%d, %d)\n", x, y);
      }
  }
  glutMouseFunc(mouseMonitor);
  ```

##### **d. `glutMotionFunc(void (*func)(int x, int y))`**
- **Purpose**: Sets the motion callback for when the mouse moves while buttons are pressed.
- **Syntax**:
  ```c
  glutMotionFunc(void (*func)(int x, int y));
  ```

##### **e. `glutPassiveMotionFunc(void (*func)(int x, int y))`**
- **Purpose**: Sets the passive motion callback for when the mouse moves without buttons pressed.
- **Syntax**:
  ```c
  glutPassiveMotionFunc(void (*func)(int x, int y));
  ```

##### **f. `glutTimerFunc(unsigned int millis, void (*func)(int value), int value)`**
- **Purpose**: Registers a timer callback to be triggered after a specified number of milliseconds.
- **Syntax**:
  ```c
  glutTimerFunc(unsigned int millis, void (*func)(int value), int value);
  ```
- **Example**:
  ```c
  void animateString(int value) {
      printf("Timer triggered with value: %d\n", value);
  }
  glutTimerFunc(1000, animateString, 1); // Trigger after 1 second
  ```

---
