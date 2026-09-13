#include <iostream>
#include "User.h"
using namespace std;

int main()
{
    User user(256);

    cout << user.getId() << endl;
    return 0;
}