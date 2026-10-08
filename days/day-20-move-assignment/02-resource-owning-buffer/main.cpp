#include <iostream>
#include <utility>
using namespace std;
class Buffer
{
private:
    int *value;

public:
    Buffer(int num)
    {
        value = new int;
        *value = num;
    }

    Buffer &operator=(Buffer &&other)
    {
        delete value;
        value = other.value;
        other.value = nullptr;
        return *this;
    }

    void show() const
    {
        if (value != nullptr)
        {

            cout << "Value: " << *value << endl;
        }
        else
        {
            cout << "No resource" << endl;
        }
    }

    ~Buffer()
    {
        delete value;
    }
};
int main()
{
    Buffer a(100);
    Buffer b(200);

    cout << "Before move:" << endl;
    a.show();
    b.show();

    b = move(a);
    cout << "\nAfter move:" << endl;

    a.show();
    b.show();

    return 0;
}
