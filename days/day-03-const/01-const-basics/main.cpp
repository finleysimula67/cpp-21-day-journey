#include<iostream>
using namespace std;

int main()
{
    int age = 10;
    const int birthYear = 2009;

    cout << "Age: " << age << endl;
    cout << "Birth year: " << birthYear << endl;

    age = 18;

    cout << "New age: " << age << endl;

    return 0;
}