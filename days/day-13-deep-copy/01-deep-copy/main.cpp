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

    Buffer(const Buffer& other)
    {
        data = new int;
        *data = *other.data;
    }
};
int main()
{
    Buffer b1;
    cout << "Value inside of object b1: " << *b1.data << endl;

    Buffer b2 = b1;
    cout << "Value inside of object b2: " << *b2.data << endl;

    cout << "Address of b1: " << b1.data << endl;
    cout << "Address of b2: " << b2.data << endl;

    return 0;
}