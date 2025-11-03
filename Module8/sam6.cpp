/*
Combining Transformations
This program scales a point (1, 1, 1) by 2, then translates it by (5, 0, 0).
*/

#include <iostream>
using namespace std;

void scale(float sx, float sy, float sz, float& px, float& py, float& pz) {
    px *= sx;
    py *= sy;
    pz *= sz;
}

void translate(float x, float y, float z, float& px, float& py, float& pz) {
    px += x;
    py += y;
    pz += z;
}

int main() {
    // Original point
    float px = 1, py = 1, pz = 1;

    // Scale and translate
    scale(2, 2, 2, px, py, pz);
    translate(5, 0, 0, px, py, pz);

    // Display the result
    cout << "Transformed Point: (" << px << ", " << py << ", " << pz << ")" << endl;

    return 0;
}