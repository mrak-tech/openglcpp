# Module 2: Introduction to Computer Graphics and Visual Computing

## Subtopic 1: Review of Functions

### **Introduction**
- **Why Use Functions?**
  - Divide and conquer: Break down complex problems into smaller, manageable parts.
  - Reuse abstractions: Avoid rewriting the same code multiple times.
  - Don't reinvent the wheel: Leverage pre-existing functions or create reusable ones.

- **What Are Functions?**
  - Use prepackaged functions (e.g., `sqrt()`, `pow()`).
  - Create your own custom functions.
  - Pass parameters to functions.
  - Accept return values from functions.

---

### **Commonly Used Math Functions**
- Examples of commonly used math functions:
  - `floor(x)`: Rounds down to the nearest integer.
  - `pow(x, y)`: Computes $ x^y $.
  - `fmod(x, y)`: Returns the floating-point remainder of $ x / y $.
  - Trigonometric functions like `sin(x)`, `cos(x)`, and `tan(x)` (angles in radians).

---

### **Creating Your Own Function**
- **Steps to Create a Function:**
  1. **Choose a Name**: The function name should be concise and descriptive.
     - If you can't find a good name, the function might be doing too many tasks.
  2. **Define a Contract**:
     - **Inputs**: Specify the arguments and their types.
       - If no inputs are needed, use `void`.
       - Specify whether the function modifies parameter values.
     - **Output**: A function should return only one value.
       - By convention, returning `0` often indicates success.
  3. **Write a Prototype**:
     - Example: `int square(int y);`
     - This tells the compiler about valid input and output types.
  4. **Write the Body**:
     - Implement the logic inside the function.
  5. **Call the Function**:
     - Use the function in your program.

---

### **Different Types of Functions**
Functions can be categorized based on parameters and return values:

| Parameter | Return Value | Description                     |
|-----------|--------------|---------------------------------|
| No        | No           | Performs an action, no inputs or outputs. |
| Yes       | No           | Accepts inputs but doesn't return anything. |
| No        | Yes          | Doesn't accept inputs but returns a value. |
| Yes       | Yes          | Accepts inputs and returns a value. |
