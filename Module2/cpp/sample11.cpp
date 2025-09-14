//Using floor() Function
//The floor() function rounds a number down to the largest integer not greater than the input.

#include <iostream>
#include <cmath> // Required for floor()
using namespace std;

int main() {
    double x1 = 9.2;
    double x2 = -9.8;

    cout << "floor(" << x1 << ") = " << floor(x1) << endl; // Output: 9.0
    cout << "floor(" << x2 << ") = " << floor(x2) << endl; // Output: -10.0

    return 0;
}
