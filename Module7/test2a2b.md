### **Code 1: Immediate Mode with Timing**

#### **Overview**
This code uses **immediate mode** (a deprecated OpenGL feature) to draw a triangle. It also measures the time taken to execute the `triangle()` function using the `std::chrono` library.

#### **Key Components**
1. **Immediate Mode Rendering (`glBegin`/`glEnd`):**
   - The `triangle()` function uses `glBegin(GL_TRIANGLES)` and `glEnd()` to define and render a triangle.
   - Inside `glBegin`/`glEnd`, the vertices of the triangle are specified using `glVertex2f()`.
   - This is an older, inefficient way of rendering in OpenGL because it sends vertex data to the GPU every frame.

2. **Timing with `std::chrono`:**
   - The `display()` function measures the time taken to execute the `triangle()` function.
   - It uses `std::chrono::high_resolution_clock` to record the start and end times, then calculates the elapsed time.
   - The result is printed to the console.

3. **Main Loop:**
   - The `main()` function initializes the GLUT window and enters the main loop (`glutMainLoop()`), which repeatedly calls the `display()` function.

#### **Code Walkthrough**
- **Initialization:**
  ```cpp
  glutInit(&argc, argv);
  glutInitWindowSize(800, 600);
  glutCreateWindow("simple");
  glutDisplayFunc(display);
  ```
  - Initializes the GLUT window and sets the display callback to `display()`.

- **Triangle Drawing:**
  ```cpp
  glBegin(GL_TRIANGLES);
  glVertex2f(0.0f, .75f);
  glVertex2f(-0.75f, 0.0);
  glVertex2f(0.75, 0.0);
  glEnd();
  ```
  - Draws a triangle with three vertices.

- **Timing:**
  ```cpp
  auto start = std::chrono::high_resolution_clock::now();
  triangle();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Time taken: " << elapsed.count() << " seconds\n";
  ```
  - Measures the time taken to call `triangle()` and prints it.

---

### **Code 2: VBO with Timing**

#### **Overview**
This code uses a **Vertex Buffer Object (VBO)** to render a triangle strip. It also measures the time taken to execute the `glDrawArrays()` function using the `std::chrono` library.

#### **Key Components**
1. **Vertex Buffer Object (VBO):**
   - The `setupGeometry()` function creates a VBO to store the vertex data for a triangle strip.
   - The vertex data is uploaded to the GPU once during initialization, making subsequent rendering more efficient.

2. **Rendering with `glDrawArrays`:**
   - The `display()` function binds the VBO, enables the vertex array, and uses `glDrawArrays(GL_TRIANGLE_STRIP, 0, 4)` to render the triangle strip.
   - This is a modern and efficient way to render in OpenGL.

3. **Timing with `std::chrono`:**
   - Similar to the first code, this code measures the time taken to execute the `glDrawArrays()` function using `std::chrono`.

4. **GLEW Initialization:**
   - The `glewInit()` function initializes GLEW, which is required to use modern OpenGL features like VBOs.

#### **Code Walkthrough**
- **Initialization:**
  ```cpp
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutCreateWindow("VBO Triangle Strip");
  glutDisplayFunc(display);

  GLenum err = glewInit();
  if (err != GLEW_OK) {
      cerr << "GLEW failed to initialize.\n";
      return 1;
  }
  ```
  - Initializes the GLUT window, sets the display callback to `display()`, and initializes GLEW.

- **Setting Up Geometry (VBO):**
  ```cpp
  GLfloat vertices[] = {
      -0.5f,  0.3f, 0.0f,
      -0.2f, -0.3f, 0.0f,
       0.2f,  0.3f, 0.0f,
       0.5f, -0.3f, 0.0f
  };

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  ```
  - Creates a VBO, uploads the vertex data to the GPU, and unbinds the buffer.

- **Rendering and Timing:**
  ```cpp
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, 0);

  auto start = std::chrono::high_resolution_clock::now();
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "VBO draw time: " << elapsed.count() << " seconds\n";

  glDisableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  ```
  - Binds the VBO, enables the vertex array, and renders the triangle strip using `glDrawArrays()`.
  - Measures the time taken to execute `glDrawArrays()` and prints it.

---

### **Key Differences Between the Two Codes**

| Feature                     | Code 1 (Immediate Mode)                         | Code 2 (VBO)                                   |
|-----------------------------|-------------------------------------------------|-----------------------------------------------|
| **Rendering Method**        | Immediate mode (`glBegin`/`glEnd`)              | Vertex Buffer Object (VBO)                    |
| **Efficiency**              | Inefficient (deprecated in modern OpenGL)       | Efficient (preferred in modern OpenGL)        |
| **Timing Measurement**      | Measures `triangle()` function                  | Measures `glDrawArrays()` function            |
| **GLEW Required?**          | No                                              | Yes                                           |
| **Vertex Data Storage**     | Sent to GPU every frame                         | Stored on GPU once during initialization      |
| **Scalability**             | Not scalable for large scenes                   | Scalable for complex scenes                   |

---

- **Code 1** demonstrates immediate mode rendering, which is simple but inefficient and outdated. It measures the time taken to draw a triangle using `glBegin`/`glEnd`.
- **Code 2** demonstrates modern OpenGL rendering using a VBO. It measures the time taken to render a triangle strip using `glDrawArrays`. This approach is efficient and scalable.

Both codes include timing measurements to compare performance, but Code 2 is the better choice for modern OpenGL applications due to its efficiency and scalability.
