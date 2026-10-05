#include <iostream>
#include <memory>
using namespace std;

class Buffer
{
private:
    int *data;

public:
    Buffer()
    {
        data = new int;
        *data = 100;
        cout << "Constructor" << endl;
    }
    // Move constructor
    Buffer(Buffer &&other)
    {
        data = other.data;
        other.data = nullptr;
        cout << "Move Constructor" << endl;
    }

    ~Buffer()
    {
        delete data;
        cout << "Destructor" << endl;
    }

    void show() const
    {
        if (data != nullptr)
        {
            cout << "Value: " << *data << endl;
        }
        else
        {
            cout << "Buffer has no resource." << endl;
        }
    }
};
int main()
{
    Buffer a;

    cout << "\n Before move: " << endl;
    a.show();

    Buffer b = move(a);
    cout << "\n After move: " << endl;
    cout << "a: ";
    a.show();

    cout << "b: ";
    b.show();

    return 0;
}