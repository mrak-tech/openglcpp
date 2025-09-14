//Function With Multiple Parameters

#include <iostream>
using namespace std;

// Function prototype
int addNumbers(int a, int b);

int main() {
    int x = 10, y = 20;
    int sum = addNumbers(x, y); // Call the function with two arguments
    cout << "The sum of " << x << " and " << y << " is " << sum << endl;
    return 0;
}

// Function definition
int addNumbers(int a, int b) {
    return a + b; // Return the sum of two numbers
}
