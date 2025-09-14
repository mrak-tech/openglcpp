//Using pow() Function
//The pow(x, y) function computes xy

#include <iostream>
#include <cmath> // Required for pow()
using namespace std;

int main() {
    double result1 = pow(2, 7);   // 2^7 = 128
    double result2 = pow(9, -5);  // 9^-5 = 1/(9^5)

    cout << "pow(2, 7) = " << result1 << endl;     // Output: 128.0
    cout << "pow(9, -5) = " << result2 << endl;    // Output: ~3.0e-5

    return 0;
}
