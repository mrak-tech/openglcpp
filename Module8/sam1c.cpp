/*
Matrix 1 (2x3):
1  2  3
4  5  6

Matrix 2 (3x2):
7  8
9  10
11 12
*/

#include <iostream>
using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions of the first matrix
    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> rows1 >> cols1;

    // Input dimensions of the second matrix
    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> rows2 >> cols2;

    // Check if multiplication is possible
    if (cols1 != rows2) {
        cout << "Matrix multiplication is not possible. Number of columns in the first matrix must equal the number of rows in the second matrix.\n";
        return 0;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    // Input elements of the first matrix
    cout << "Enter elements of the first matrix:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Input elements of the second matrix
    cout << "Enter elements of the second matrix:\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Perform matrix multiplication with visualization
    cout << "\nPerforming matrix multiplication...\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize the result element to 0

            // Display the row from matrix1 and the column from matrix2
            cout << "\nComputing result[" << i << "][" << j << "]:\n";
            cout << "Row from matrix1: ";
            for (int k = 0; k < cols1; k++) {
                cout << matrix1[i][k] << " ";
            }
            cout << "\nColumn from matrix2: ";
            for (int k = 0; k < rows2; k++) {
                cout << matrix2[k][j] << " ";
            }
            cout << "\nIntermediate computations:\n";

            // Perform the dot product and display intermediate steps
            for (int k = 0; k < cols1; k++) {
                int product = matrix1[i][k] * matrix2[k][j];
                result[i][j] += product;
                cout << "matrix1[" << i << "][" << k << "] * matrix2[" << k << "][" << j << "] = "
                    << matrix1[i][k] << " * " << matrix2[k][j] << " = " << product << "\n";
            }

            cout << "Sum of products = " << result[i][j] << "\n";
        }
    }

    // Display the resultant matrix
    cout << "\nResultant matrix after multiplication:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}