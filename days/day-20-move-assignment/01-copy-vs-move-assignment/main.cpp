#include <iostream>
#include <memory>
using namespace std;

class Buffer
{
public:
    Buffer()
    {
        cout << "Constructor" << endl;
    }
    Buffer(const Buffer& other)
    {
        cout << "Copy Constructor" << endl;
    }
    Buffer(Buffer&& other)
    {
        cout << "Move Constructor" << endl;
    }
    Buffer& operator = (const Buffer& other)
    {
        cout << "Copy Assignment" << endl;
        return *this;
    }
    Buffer& operator=(Buffer&& other)
    {
        cout << "Move Assignment" << endl;
        return *this;
    }
};
int main()
{
    Buffer a;
    Buffer b;

    b = a;
    b = move(a);

    return 0;
}