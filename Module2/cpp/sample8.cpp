//No Parameter, Return Value

#include <iostream>
using namespace std;

// Function prototype
int getRandomNumber();

int main() {
    int number = getRandomNumber(); // Call the function and store the result
    cout << "Random number: " << number << endl;
    return 0;
}

// Function definition
int getRandomNumber() {
    return 42; // Simulating a random number
}
