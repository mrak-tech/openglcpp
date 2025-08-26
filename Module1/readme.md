# Module 1 – Introduction to Computer Graphics
---

## Module 1: Introduction to Computer Graphics and Visual Computing 
**Content:** Module 1: Introduction to Computer Graphics and Visual Computing  
**Discussion:**  
This module introduces the **fundamentals of computer graphics (CG)** and its role in **visual computing**. Computer graphics is the study of how to generate, manipulate, and display visual images with the help of computers. It plays an essential role in applications ranging from **entertainment (movies, games)** to **scientific visualization (medical imaging, simulations)**.

---

## Subtopic 1: Introduction to Computer Graphics
**Content:**  
- Fundamentals of 2D and 3D graphics  
- IDE configuration for OpenGL  
- Review of Arrays and Pointers  

**Discussion:**  
At the start, we cover:  
- **2D graphics** (flat images like drawings, charts) vs. **3D graphics** (models with depth, lighting, perspective).  
- The importance of an **Integrated Development Environment (IDE)** setup, especially for **OpenGL**, one of the most widely used graphics APIs.  
- A **programming refresher** on arrays and pointers is included, since graphics programming often involves manipulating large datasets in memory (e.g., vertices, pixels).

---

## Core Areas of Computer Graphics
**Content:** Geometric Modeling, Human-Computer Interaction, Lighting and Shading, Rendering, Visualization, Perception, Animation, Simulation, Hardware/Software.  

**Discussion:**  
Each area represents a branch of CG research and practice:  
- **Geometric Modeling** – defining shapes mathematically (polygons, curves, surfaces).  
- **HCI** – how users interact with graphics (e.g., drawing on tablets, VR controllers).  
- **Lighting & Shading** – simulating how light interacts with objects to create realism.  
- **Rendering** – the process of turning geometry + lighting into final images.  
- **Visualization** – converting raw data into visual form (charts, MRI scans).  
- **Perception** – understanding how humans interpret visuals.  
- **Animation & Simulation** – movement, physics, and time-based changes.  
- **Software & Hardware** – GPUs, APIs, and tools for implementing these systems.

---

## Ivan Sutherland
**Content:**  
- Pioneer of computer graphics  
- Created **Sketchpad** (early CAD system, 1963).  

**Discussion:**  
Ivan Sutherland is regarded as the **“Father of Computer Graphics.”** His program **Sketchpad** allowed users to draw on a computer using a light pen — a groundbreaking step that inspired CAD software, graphical UIs, and interactive design systems.

---

## Applications of Computer Graphics
**Content:** Entertainment, CAD/CAM, Scientific/Medical Visualization, Training, Synthetic Realities, Art/Design, Games.  

**Discussion:**  
CG is applied in:  
- **Movies & Games** – realistic 3D rendering, animation.  
- **CAD/CAM** – designing mechanical, architectural, or electronic systems.  
- **Medical Imaging** – 3D visualization of organs and scans.  
- **Training Simulations** – flight simulators, VR military training.  
- **Art/Design** – digital painting, 3D modeling.  
- **Synthetic Realities** – VR, AR, Metaverse.  

---

## Raster vs. Vector
**Content:**  
- Raster (pixels, bitmap, good for photos, lossy).  
- Vector (mathematical shapes, scalable, non-lossy).  

**Discussion:**  
- **Raster images** (PNG, JPG) are pixel-based and lose quality when zoomed.  
- **Vector images** (SVG, DWG) use mathematical formulas for lines/shapes, keeping quality at any size — best for diagrams, logos, CAD.  
Both formats are widely used, depending on the task.

---

## History of Algorithms (1960s–1970s)
**Content:**  
- Hidden-line & surface algorithms (Roberts, Appel, Warnock, Watkins).  
- Lighting & shading: Gouraud, Phong.  
- Z-buffering (Catmull), Anti-aliasing (Crow).  

**Discussion:**  
The **1960s–70s** were foundational decades:  
- Solving the **visibility problem** (which surfaces are seen vs. hidden).  
- First **shading models** for realistic lighting.  
- **Z-buffering** introduced depth comparisons, still used in modern graphics.  
- **Anti-aliasing** techniques improved visual smoothness by reducing jagged edges.  

---

## Toward Realism (1980s–1990s)
**Content:**  
- Ray tracing, radiosity, rendering equation.  
- Photorealism advances (reflectance models, shading languages).  
- RenderMan (Pixar).  

**Discussion:**  
In the **1980s–90s**, CG shifted toward **realism**:  
- **Ray tracing** simulated light paths for reflections/refractions.  
- **Radiosity** improved soft shadowing and indirect light.  
- **Rendering equation** formalized global illumination.  
- Pixar’s **RenderMan** became an industry standard, powering movies like *Toy Story*.  

---

## Displays (CRT to Flat Panels)
**Content:**  
- CRT basics: electron beam, phosphors, refresh rate.  
- Resolution, persistence, aspect ratio, frame buffers.  
- Modern flat panels: LCD, Plasma, LED.  

**Discussion:**  
Early displays relied on **Cathode-Ray Tubes (CRT)**, which used electron beams on phosphor-coated screens.  
Key concepts:  
- **Resolution** – pixel density.  
- **Aspect Ratio** – proportion (e.g., 4:3, 16:9).  
- **Frame Buffer** – memory storing pixel values.  
Today, **flat-panel displays (LCD/LED)** dominate for their portability, clarity, and low power.

---

## Color Models
**Content:**  
- Beam-penetration (red/green).  
- Shadow-mask & RGB color systems.  
- Bit depth (1-bit to 24-bit = true color).  

**Discussion:**  
- **Early CRTs** used beam penetration (few colors).  
- **RGB shadow-mask** became standard, supporting millions of colors.  
- **Bit depth** determines how many tones/colors a pixel can display.  
- Modern displays use **true color (24-bit)** for lifelike images.  

---

## Flat-Panel Technologies
**Content:**  
- Emissive vs. Nonemissive displays.  
- Plasma, LCDs, LEDs.  

**Discussion:**  
- **Emissive** – light is generated (Plasma, OLED).  
- **Non-emissive** – light is controlled (LCDs, E-ink).  
Plasma displays gave way to **LCDs and LEDs**, which power most modern laptops, TVs, and phones.  

---

## Stereoscopic Graphics & VR
**Content:**  
- Stereo imaging (left/right eye views).  
- VR devices: HTC Vive, Oculus, Valve Index, PSVR2.  

**Discussion:**  
Stereoscopy provides depth by showing slightly different images to each eye. Today’s **VR headsets** use this principle, paired with sensors, to immerse users in 3D environments.

---

## Graphics Hardware
**Content:**  
- CPU + Display Controller (video processor).  
- Frame buffer, dedicated GPU memory.  

**Discussion:**  
Modern systems offload rendering tasks from the CPU to **specialized processors (GPUs)**. GPUs excel at parallel computation, essential for handling millions of pixels and 3D transformations in real time.

---
