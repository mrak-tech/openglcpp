//Function With Parameters

#include <iostream>
using namespace std;

// Function prototype
void greetUser(string name);

int main() {
    string userName = "hadji";
    greetUser(userName); // Pass argument to the function
    return 0;
}

// Function definition
void greetUser(string name) {
    cout << "Hello, " << name << "! Welcome to C++ programming." << endl;
}
