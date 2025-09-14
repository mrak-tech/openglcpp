//Using fmod() Function
//The fmod(x, y) returns the remainder of x / y as a floating-point value.

#include <iostream>
#include <cmath> // Required for fmod()
using namespace std;

int main() {
    double x = 13.657;
    double y = 2.333;

    double remainder = fmod(x, y);

    cout << "fmod(" << x << ", " << y << ") = " << remainder << endl;
    // Output: ~1.992

    return 0;
}
