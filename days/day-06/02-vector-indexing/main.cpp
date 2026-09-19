#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {10, 20, 30};

    std::cout << "Before: " << numbers[1] << '\n';

    numbers[1] = 200;

    std::cout << "After: " << numbers[1] << '\n';

    return 0;
}