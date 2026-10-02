#include <iostream>
#include <memory>

using namespace std;

class Buffer
{
private:
    unique_ptr<int> data;

public:
    Buffer()
    {
        data = make_unique<int>(100);
    }

    void setValue(int value)
    {
        *data = value;
    }

    int getValue() const
    {
        return *data;
    }

};

int main()
{
    Buffer buffer;

    cout << "Initial value: " << buffer.getValue() << endl;

    buffer.setValue(200);

    cout << "Updated value: " << buffer.getValue() << endl;

    return 0;
}