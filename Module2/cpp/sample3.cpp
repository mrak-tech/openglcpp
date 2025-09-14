//Function That Returns a Value
#include <iostream>
using namespace std;

// Function prototype
int square(int num);

int main() {
    int number = 5;
    int result = square(number); // Call the function and store the result
    cout << "The square of " << number << " is " << result << endl;
    return 0;
}

// Function definition
int square(int num) {
    return num * num; // Return the squared value
}
