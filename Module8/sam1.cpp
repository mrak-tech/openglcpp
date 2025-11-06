
/*
Matrix A :
[1 2]
[3 4]

Matrix B:
[5 6]
[7 8]

Result(A + B) :
[1+5  2+6] = [6  8]
[3+7  4+8]   [10 12]
*/
#include <iostream>
using namespace std;

int main() {
    // Define two 2x2 matrices
    int A[2][2] = { {1, 2}, {3, 4} };
    int B[2][2] = { {5, 6}, {7, 8} };
    int result[2][2];

    // Add matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    // Display the result
    cout << "Matrix Addition Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}