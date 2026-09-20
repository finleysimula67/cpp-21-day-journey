#include <iostream>
#include <stdexcept>

int divide (int a , int b )
{
    if (b == 0)
    {
        throw std::runtime_error("Cannot divide by zero");
    }
    return a / b;
}
int main()
{
    try
    {
        std::cout << divide(10, 2) << std::endl;
        std::cout << divide(10, 0) << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}