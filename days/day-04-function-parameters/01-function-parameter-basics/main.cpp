#include <iostream>
using namespace std;

void passByValue(int number)
{
    number = 100;
    cout << "Inside passByValue: " << number << endl;
}

void passByReference(int &number)
{
    number = 100;
    cout << "Inside passByReference: " << number << endl;
}

void passByPointer(int *number)
{
    if (number != nullptr)
    {
        *number = 100;
        cout << "Inside passByPointer: " << *number << endl;
    }
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;

    passByValue(a);
    cout << "After passByValue: " << a << endl;

    passByReference(b);
    cout << "After passByReference: " << b << endl;

    passByPointer(&c);
    cout << "After passByPointer: " << c << endl;

    return 0;
}