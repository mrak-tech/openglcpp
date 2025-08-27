//Program 4: Array Initialization and Access
//This program shows how to declare, initialize, and access elements of an array.

#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};  // Initialize an array

    cout << "Array elements:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}
