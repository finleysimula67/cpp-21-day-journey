#include <iostream>
#include <utility>
using namespace std;

class Buffer
{
private:
    int *data;

public:
    /* Constructor */
    Buffer(int num)
    {
        data = new int(num);
    }

    /* Copy Constructor */
    Buffer(const Buffer &other)
    {
        if (other.data != nullptr)
        {
            data = new int(*other.data);
        }
        else
        {
            data = nullptr;
        }
    }

    /* Copy Assignment */
    Buffer &operator=(const Buffer &other)
    {
        if (this == &other)
        {
            return *this;
        }

        int *newData = nullptr;

        if (other.data != nullptr)
        {
            newData = new int(*other.data);
        }

        delete data;
        data = newData;

        return *this;
    }

    /* Move Constructor */
    Buffer(Buffer &&other) noexcept
    {
        data = other.data;
        other.data = nullptr;
    }

    /* Move Assignment */
    Buffer &operator=(Buffer &&other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        delete data;
        data = other.data;
        other.data = nullptr;

        return *this;
    }

    /* Destructor */
    ~Buffer()
    {
        delete data;
    }

    /* Display the resource */
    void show() const
    {
        if (data != nullptr)
        {
            cout << "Value: " << *data << endl;
        }
        else
        {
            cout << "No resource found" << endl;
        }
    }
};

int main()
{
    Buffer b1(67);

    cout << "Original buffer:" << endl;
    b1.show();

    /* Test copy construction */
    Buffer b2 = b1;
    cout << "\nAfter copy construction:" << endl;
    b1.show();
    b2.show();

    /* Test copy assignment */
    Buffer b3(89);
    b3 = b1;

    cout << "\nAfter copy assignment:" << endl;
    b3.show();

    /* Test move construction */
    Buffer b4 = move(b2);

    cout << "\nAfter move construction:" << endl;
    cout << "b2: ";
    b2.show();
    cout << "b4: ";
    b4.show();

    /* Test move assignment */
    b3 = move(b4);

    cout << "\nAfter move assignment:" << endl;
    cout << "b4: ";
    b4.show();
    cout << "b3: ";
    b3.show();

    return 0;
}
