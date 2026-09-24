#include <iostream>
#include <string>
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
};
int main()
{
    Buffer b1;
    cout << "Value inside of object b1: " << *b1.data << endl;

    Buffer b2 = b1;
    *b2.data = 50;
    cout << "Value inside of object b2: " << *b2.data << endl;

    *b1.data = 80;
    cout << "Value of object b1 after changing: " << *b1.data << endl;

    cout << "B1 address: " << b1.data << endl;
    cout << "B2 address: " << b2.data << endl;
    
    return 0;
}