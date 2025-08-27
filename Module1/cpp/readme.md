# Introduction to Pointers

## What are Pointers?
A **pointer** is a variable that stores the memory address of another variable.  
Instead of holding a value directly, it *"points"* to the location where the value is stored.

---

## Declaring and Initializing Pointers
To declare a pointer, you specify the type of data it will point to, followed by an asterisk (`*`).

```cpp
int x = 10;       // An integer variable
int* ptr = &x;    // A pointer to an integer, initialized with the address of x
```

- `&x`: The **address-of operator** retrieves the memory address of `x`.  
- `*ptr`: The **dereference operator** accesses the value stored at the memory address held by `ptr`.

---

## Dereferencing Pointers
Dereferencing a pointer gives you access to the value stored at the memory address it points to.

```cpp
cout << *ptr; // Outputs: 10
```

---

## Common Pointer Operations
- Assigning addresses to pointers.  
- Modifying the value at the memory address pointed to by a pointer.  
- Comparing pointers.  
