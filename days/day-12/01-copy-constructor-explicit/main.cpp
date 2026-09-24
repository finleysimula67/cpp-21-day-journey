#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    int id;
    string name;

    Product(int id , string name)
    {
        this->id = id;
        this->name = name;
    }

    Product(const Product& others)
    {
        this->id = others.id;
        this->name = others.name;
    }
};
int main()
{
    Product p1(1, "Nabin");
    Product p2 = p1;
    p2.name = "Finley";
    cout << p1.id << "," << p1.name << endl;
    cout << p2.id << "," << p2.name << endl;

    return 0;
}