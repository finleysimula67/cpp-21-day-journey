#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> first = make_unique<int>(100);

    unique_ptr<int> second = move(first);

    cout << "Second: " << *second << endl;

    if (first == nullptr)
    {
        cout << "First no longer owns the resource." << endl;
    }
    return 0;
}