//Combining Multiple Math Functions
//Here’s a complete program that demonstrates all six functions together.

#include <iostream>
#include <cmath> // For all math functions
using namespace std;

int main() {
    double x = 9.2;
    double y = 2.333;
    double angle = 0.0;

    // Floor example
    cout << "floor(" << x << ") = " << floor(x) << endl;

    // Power example
    cout << "pow(2, 7) = " << pow(2, 7) << endl;

    // Modulo example
    cout << "fmod(" << x << ", " << y << ") = " << fmod(x, y) << endl;

    // Trigonometry examples
    cout << "sin(" << angle << ") = " << sin(angle) << endl;
    cout << "cos(" << angle << ") = " << cos(angle) << endl;
    cout << "tan(" << angle << ") = " << tan(angle) << endl;

    return 0;
}
