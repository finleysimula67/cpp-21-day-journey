#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Task
{
private:
    string *task;

public:
    Task(string text)
    {
        task = new string;
        *task = text;
    }
    Task(Task &&other)
    {
        task = other.task;
        other.task = nullptr;
    }
    ~Task()
    {
        delete task;
    }
    void show() const
    {
        if(task!= nullptr)
        {
            cout << "Value: " << *task << endl;
        }
        else
        {
            cout << "Task has no resource." << endl;
        }
    }
};
int main()
{
    Task first("Learning move semantics");

    cout << "Before move:" << endl;
    first.show();

    Task second = move(first);

    cout << "\nAfter move:" << endl;

    cout << "First: ";
    first.show();

    cout << "Second: ";
    second.show();

    return 0;
}