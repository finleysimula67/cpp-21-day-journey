#include <iostream>

// Passes the original variable by reference.
// Changes made to 'value' affect the variable in main().
void change(int &value)
{
    value = 500;
}

int main()
{
    int value = 10;

    // Shows the value before calling the function.
    std::cout << "Before: " << value << std::endl;

    // Sends 'value' by reference, so the original value is changed.
    change(value);

    // Shows the updated value after the function call.
    std::cout << "After: " << value << std::endl;

    return 0;
}