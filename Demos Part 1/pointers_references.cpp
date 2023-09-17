#include <iostream>
using namespace std;

int main() {
    int number = 42;
    int* pointer = &number; // Pointer pointing to the address of 'number'
    int& reference = number; // Reference to 'number'

    cout << "Original number: " << number << endl;

    // Using a pointer to modify the value
    *pointer = 100;
    cout << "Number after using a pointer: " << number << endl;

    // Using a reference to modify the value
    reference = 200;
    cout << "Number after using a reference: " << number << endl;

    // Display the address of 'number'
    cout << "Address of number: " << &number << endl;

    // Display the address stored in the pointer
    cout << "Address stored in the pointer: " << pointer << endl;

    return 0;
}
