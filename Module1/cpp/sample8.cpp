#include <iostream>
using namespace std;

// Function to reverse an array using pointers
void reverseArray(int* arr, int size) {
    int* start = arr;           // Pointer to the start of the array
    int* end = arr + size - 1;  // Pointer to the end of the array

    cout << "Simulation of reverseArray function:" << endl;

    while (start < end) {
        // Print the current state of the array
        cout << "Current array: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Print the values pointed to by start and end
        cout << "Swapping *start (" << *start << ") with *end (" << *end << ")" << endl;

        // Swap the values at start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers
        start++;
        end--;

        // Print the updated pointers' positions
        cout << "New start pointer position: " << *start << ", New end pointer position: " << *end << endl;
        cout << "-----------------------------" << endl;
    }

    cout << "Final array after reversal: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the reverseArray function
    reverseArray(arr, 5);

    cout << "Reversed array: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
