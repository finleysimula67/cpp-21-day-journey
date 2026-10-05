#include <iostream>
#include <string>
using namespace std;

class Task
{
private:
    string title;

public:
    Task(string title) : title(title)
    {
        cout << "Task created: " << title << endl;
    }

    ~Task()
    {
        cout << "Task destroyed: " << title << endl;
    }

    void show() const
    {
        cout << "Task: " << title << endl;
    }
};

void processTask(const Task &task)
{
    task.show();
}

int main()
{
    Task task("Learn C++ Memory Management");

    processTask(task);

    return 0;
}