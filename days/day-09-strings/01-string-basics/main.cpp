#include <iostream>
#include <string>

int main()
{
    std::string name = "Nabin ";

    std::cout << "Name: " << name << std::endl;
    std::cout << "Name Length: " << name.size() << std::endl;

    name = name + "Oli";

    std::cout << "Full Name: " << name << std::endl;

    return 0;
}