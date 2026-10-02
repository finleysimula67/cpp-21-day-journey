#include<iostream>
#include "math.h"

using namespace std;
int main()
{
    Calculator c;
    c.value = add(10,20);

    cout << c.value << endl;

    return 0;
}