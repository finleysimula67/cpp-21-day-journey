#include <iostream>
#include <memory>
using namespace std;

void showValue(unique_ptr<int> value)
{
    cout << "Value: " << *value << endl;
}
int main()
{
    unique_ptr<int> value = make_unique<int>(500);

    unique_ptr<int> transfered_ownership = move(value);

    showValue(move(transfered_ownership));

    if (value == nullptr)
    {
        cout << "Ownership transferred." << endl;
    }

    return 0;
}