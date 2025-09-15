# Module 3: Introduction to Computer Graphics and Visual Computing

## Subtopic 1: Introduction to OpenGL

### Learning Objectives
At the end of this subtopic, the student will be able to:
- Discuss the history and rendering pipeline of OpenGL.

### What is OpenGL?
- **OpenGL** is a computer graphics rendering application programming interface (API).
  - It generates high-quality color images by rendering geometric and image primitives.
  - Forms the basis of many interactive applications that include 3D graphics.
  - Graphics part of your application can be:
    - Operating system independent.
    - Window system independent.

- **History**:
  - First developed at Silicon Graphics (SGI) Computer Systems.
  - Version 1.0 released in 1994.
  - Follows a client-server model:
    - Application (Client).
    - Server (Vendor OpenGL implementation).
  - Not object-oriented.

### Khronos Group
- The **Khronos Visual Computing Ecosystem** refers to the collection of open, royalty-free standards developed and managed by The Khronos Group, an industry consortium.
  - These standards aim to enable hardware acceleration and cross-platform compatibility for visual computing applications, including:
    - 3D graphics.
    - Parallel computing.
    - Virtual and augmented reality.
    - Neural networks.
    - Computer vision.

### OpenGL Rendering Pipeline
- Latest version: 4.5.
- The **OpenGL rendering pipeline** processes 3D scene data to produce a 2D image displayed on the screen.
  - Fixed-function stages: Controlled by OpenGL.
  - Programmable stages: Developers write custom code called shaders.

#### Why the Pipeline Matters
The OpenGL rendering pipeline enables:
- Fast conversion of complex 3D data into 2D images using the GPU.
- Customization of visuals with shaders for unique effects.
- Efficiency by skipping unnecessary work (e.g., clipping off-screen objects).

#### Stages of the Pipeline
1. **Vertex Specification**:
   - Defines raw vertex data (positions, colors, texture coordinates, normals, etc.) in memory using Vertex Buffer Objects (VBOs) and Vertex Array Objects (VAOs).
2. **Vertex Shader**:
   - Processes each vertex individually, performing transformations (e.g., model-view-projection), lighting calculations, and passing data to subsequent stages.
3. **Primitive Assembly**:
   - Assembles vertices into primitives like points, lines, or triangles based on the drawing mode.
4. **Geometry Shader (Optional)**:
   - Generates new primitives or modifies existing ones for advanced effects like tessellation or procedural geometry generation.
5. **Rasterization**:
   - Converts geometric primitives into fragments (potential pixels on the screen). Performs clipping to discard parts of primitives outside the viewing frustum.
6. **Fragment Shader**:
   - Determines the final color of each fragment. Performs complex lighting, texturing, and other per-pixel calculations.
7. **Per-Sample Operations**:
   - Includes tests and operations on fragments, such as:
     - Depth testing (to determine visibility).
     - Stencil testing.
     - Blending (for transparency).
     - Scissoring before writing the final color to the framebuffer.
