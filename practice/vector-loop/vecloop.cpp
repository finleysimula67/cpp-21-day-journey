#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> books = {"Atomic Habits , Mindset , Deep Work , Eat that Frog "};

    for(const std::string& book : books)
    {
        std::cout << book << std::endl;
    }

    return 0;
}