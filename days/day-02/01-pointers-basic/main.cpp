#include <iostream>
using namespace std;

int main()
{
    int value = 10;

    cout << "Value: " << value <<endl;
    cout << "Address: " << &value <<endl;

    int *ptr = &value;

    cout << "Pointer stores: " << ptr << endl;
    cout << "Value through pointer: " << *ptr << endl;

    int &ref = value;

    cout << "Vlaue through reference: " << ref << endl;

    *ptr = 20;

    cout << "\nAfter modification:\n";
    cout << "Value: " << value << endl;
    cout << "Pointer sees: " << *ptr << endl;
    cout << "Reference sees: " << ref << endl;

    return 0;
}
