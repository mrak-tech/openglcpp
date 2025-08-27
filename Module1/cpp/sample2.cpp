#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;  // Pointer points to the first element of the array

    cout << "Array elements using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Element at index " << i << ": " << *(ptr + i) << endl;
    }

    // Incrementing the pointer
    ptr++;
    cout << "Pointer incremented. Now pointing to: " << *ptr << endl;

    return 0;
}
