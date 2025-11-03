#include <iostream>
using namespace std;

void translate(float x, float y, float z, float& px, float& py, float& pz) {
    px += x;
    py += y;
    pz += z;
}

int main() {
    // Original point
    float px = 10, py = 10, pz = 10;

    // Translate the point
    translate(5, 0, 0, px, py, pz);

    // Display the result
    cout << "Translated Point: (" << px << ", " << py << ", " << pz << ")" << endl;

    return 0;
}