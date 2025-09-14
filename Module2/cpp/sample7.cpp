// Parameter, No Return Value

#include <iostream>
using namespace std;

// Function prototype
void printMessage(string message);

int main() {
    string msg = "C++ is fun!";
    printMessage(msg); // Pass argument to the function
    return 0;
}

// Function definition
void printMessage(string message) {
    cout << message << endl;
}
