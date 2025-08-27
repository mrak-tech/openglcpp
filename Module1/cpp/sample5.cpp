//Program 5: Passing Arrays to Functions
//This program demonstrates how to pass an array to a function and modify its elements.


#include <iostream>
using namespace std;

void incrementArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i]++;
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Before incrementing: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    incrementArray(arr, 5);

    cout << "After incrementing: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
