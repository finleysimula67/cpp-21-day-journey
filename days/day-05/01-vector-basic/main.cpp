#include <iostream>
#include <vector>

int main()
{
    std::vector<int> tasks;

    tasks.push_back(101);
    tasks.push_back(102);
    tasks.push_back(103);

    std::cout << "Tasks: " << tasks.size() << std::endl;

    for(int task : tasks)
    {
        std::cout << task << std::endl;
    }
    return 0;
}