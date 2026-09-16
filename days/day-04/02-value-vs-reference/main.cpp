#include <iostream>

// Pass-by-value receives a copy of the argument. Changes affect only the copy.
void changeByValue(int value)
{
    // The copied parameter usually has a different address from the original variable.
    std::cout << "Address inside the function(value): "<< &value << std::endl;
    value = 500;
}

// Pass-by-reference receives an alias to the original variable.
void changeByReference(int& value)
{
    // The reference refers to the original variable, so both addresses are the same.
    std::cout << "Address inside the function (reference): "<< &value << std::endl;

    // This change updates the variable in main.
    value = 500;
}

int main()
{
    int value = 10;

    // Store the original value and display its memory address for comparison.
    std::cout << "Address inside main: "<< &value << std::endl;

    // The function changes only its local copy; value remains 10 here.
    std::cout << "\n--- Pass by Value ---\n";

    changeByValue(value);

    // The function changes the original value through the reference.
    std::cout << "\n--- Pass by Reference ---\n";
    changeByReference(value);

    // Prints 500 because changeByReference modified value directly.
    std::cout << "Value after: " << value << std::endl;

    return 0;
}