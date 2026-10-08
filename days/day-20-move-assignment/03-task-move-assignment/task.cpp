#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Task
{
private:
    string *title;

public:
    Task(string name)
    {
        title = new string;
        *title = name;
    }

    Task &operator=(Task &&other)
    {
        delete title;
        title = other.title;
        other.title = nullptr;
        return *this;
    }
    void show() const
    {
        if (title != nullptr)
        {
            cout << "Task: " << *title << endl;
        }
        else
        {
            cout << "No task" << endl;
        }
    }

    ~Task()
    {
        delete title;
    }
};

int main()
{
    Task t1("Learn C++");
    Task t2("Build a project");

    cout << "Before moving the task:" << endl;
    t1.show();
    t2.show();

    t2 = move(t1);

    cout << "\nAfter moving the task:" << endl;
    cout << "First Task: ";
    t1.show();

    cout << "Second Task: ";
    t2.show();

    return 0;
}