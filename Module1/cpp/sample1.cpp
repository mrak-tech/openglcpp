//Program 1: Basic Pointer Usage
//This program demonstrates how to declare, initialize, and dereference pointers.

#include <iostream>
using namespace std;

int main() {
    int x = 42;       // Declare an integer variable
    int* ptr = &x;    // Declare a pointer and assign it the address of x

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value stored in ptr (address of x): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    *ptr = 100;       // Modify the value of x through the pointer
    cout << "New value of x: " << x << endl;

    return 0;
}
