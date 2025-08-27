//Program 9: Dynamic Array Allocation
//This program demonstrates dynamic memory allocation for an array.

#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];  // Dynamically allocate memory for the array

    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Array elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Free dynamically allocated memory

    return 0;
}
