#include <iostream>

class Buffer
{
public:
    int *data;

    //No Args constructor
    Buffer()
    {
        data = new int;
        *data = 100;
    }

    //Copy constructor
    Buffer(const Buffer &other)
    {
        data = new int;
        *data = *other.data;
    }

    //Destructor
    ~Buffer()
    {
        delete data;
    }
};

int main()
{
    Buffer b1;
    Buffer b2 = b1;

    *b2.data = 50;

    std::cout << "b1: " << *b1.data << '\n';
    std::cout << "b2: " << *b2.data << '\n';

    return 0;
}