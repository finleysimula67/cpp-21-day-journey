#include <iostream>
#include <string>
using namespace std;

class User
{
public:
    int id;
    string name;

    User(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
};

int main()
{
    User u2(1, "Nabin");

    //copy of constructor
    User u3 = u2;
    u3.name = "Praveen";

    cout << u2.id << "," << u2.name << endl;
    cout << u3.id << "," << u3.name << endl;

    return 0;
}