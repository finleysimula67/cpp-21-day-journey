#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    string title;
    int pages;
    float price;

    Book(string title, int pages, float price)
    {
        this->title = title;
        this->pages = pages;
        this->price = price;
    }
    Book(const Book &others)
    {
        this->pages = others.pages;
    }
};
int main()
{
    Book b1("Atomic Habits", 275, 876.23);
    cout << "Before Copy: " << b1.title << ":" << b1.pages << "," << b1.price << endl;

    Book b2 = b1;
    b2.title = "Eat that Frog";
    b2.price = 586.45;

    cout << "After Copy: " << b2.title << ":" << b2.pages << "." << b2.price << endl;

    return 0;
}