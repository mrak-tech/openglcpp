//Void Function That Performs an Action
#include <iostream>
using namespace std;

// Function prototype
void printStars(int count);

int main() {
    int starCount = 10;
    printStars(starCount); // Call the function to print stars
    return 0;
}

// Function definition
void printStars(int count) {
    for (int i = 0; i < count; i++) {
        cout << "*";
    }
    cout << endl;
}
