//Program 3: Pointer to Functions
//This program demonstrates how to use a pointer to call a function.

#include <iostream>
using namespace std;

void greet() {
    cout << "Hello, World!" << endl;
}

int main() {
    void (*funcPtr)() = greet;  // Declare a function pointer and assign it to greet
    funcPtr();                  // Call the function through the pointer
    return 0;
}
