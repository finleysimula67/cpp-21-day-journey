#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> value = make_unique<int>(100);

    cout << "Value: " << *value << endl;

    *value = 200;

    cout << "Updated value: " << *value << endl;

    return 0;
}