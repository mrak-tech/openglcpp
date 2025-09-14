//Using sin(), cos(), and tan() Functions
//These are trigonometric functions that take angles in radians.

#include <iostream>
#include <cmath> // Required for sin(), cos(), tan()
using namespace std;

int main() {
    double angle = 0.0;

    cout << "sin(" << angle << ") = " << sin(angle) << endl;   // Output: 0.0
    cout << "cos(" << angle << ") = " << cos(angle) << endl;   // Output: 1.0
    cout << "tan(" << angle << ") = " << tan(angle) << endl;   // Output: 0.0

    return 0;
}
