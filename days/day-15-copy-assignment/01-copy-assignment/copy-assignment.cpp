#include <iostream>
using namespace std;

class Buffer
{
public:
    Buffer()
    {
        cout << "Constructor" << endl;
    }
    Buffer(const Buffer &other)
    {
        cout << "Copy Constructor" << endl;
    }
    Buffer &operator=(const Buffer &other)
    {
        cout << "Copy Assignment" << endl;
        return *this;
    }
};
int main()
{
    Buffer b1;
    Buffer b2;
    b2 = b1;
    return 0;
}