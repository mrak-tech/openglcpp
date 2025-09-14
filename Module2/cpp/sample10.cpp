//Nested Function Calls

#include <iostream>
using namespace std;

// Function prototypes
int multiply(int a, int b);
int add(int a, int b);

int main() {
    int x = 5, y = 10, z = 2;
    int result = multiply(add(x, y), z); // Nested function calls
    cout << "Result: " << result << endl;
    return 0;
}

// Function definitions
int multiply(int a, int b) {
    return a * b;
}

int add(int a, int b) {
    return a + b;
}
