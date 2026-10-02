#include <iostream>
using namespace std;

class Buffer
{

public:
    int *data;

    Buffer()
    {
        data = new int;
        *data = 100;
    }

    Buffer(const Buffer &other)
    {
        data = new int;
        *data = *other.data;
    }

    Buffer &operator=(const Buffer &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete data;

        data = new int;
        *data = *other.data;

        return *this;
    }

    ~Buffer()
    {
        delete data;
    }
};

int main()
{
    Buffer b1;

    Buffer b2 = b1;

    Buffer b3;

    b3 = b1;

    *b2.data = 50;
    *b3.data = 70;

    cout << "b1: " << *b1.data << endl;
    cout << "b2: " << *b2.data << endl;
    cout << "b3: " << *b3.data << endl;

    return 0;
}