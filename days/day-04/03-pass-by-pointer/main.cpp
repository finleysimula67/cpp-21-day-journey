#include <iostream>

// Receives the address of an integer and changes the original value through it.
void changeBypointer(int* value)
{
    // The pointer contains the address passed from main.
    std::cout << "Pointer stores: " << value << std::endl;

    // Dereferencing the pointer gives access to the original object's address.
    std::cout << "Original Object address: " << &*value << std::endl;

    // Dereferencing reads the value stored at that address.
    std::cout << "Value: " << *value << std::endl;

    // Dereferencing while assigning updates the original variable in main.
    *value = 500;
}
int main()
{
    int value = 10;

    // Display the address of the variable that will be passed by pointer.
    std::cout << "Main Object Address: " << &value << std::endl;

    // Pass value's address so the function can modify the original variable.
    changeBypointer(&value);

    // The change made through the pointer is visible here.
    std::cout << "Value after: " << value << std::endl;

    return 0;
}