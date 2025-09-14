//Parameter and Return Value

#include <iostream>
using namespace std;

// Function prototype
double calculateArea(double radius);

int main() {
    double r = 7.0;
    double area = calculateArea(r); // Call the function with a parameter
    cout << "Area of circle with radius " << r << " is " << area << endl;
    return 0;
}

// Function definition
double calculateArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius; // Return the calculated area
}
