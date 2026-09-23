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
};
int main()
{
    Book b1("Atomic Habits", 286, 875.36);
    Book b2 = b1;
    cout << "Original: " << endl;
    cout << b1.title << "," << b1.pages << "," << b1.price << endl;

    cout << "Copy: " << endl;
    cout << b2.title << "," << b2.pages << "," << b2.price << endl;

    b2.title = "Mindset";
    b2.price = 523.65;

    cout << "After Modifying Copy: " << endl;

    cout << "Original: " << endl;
    cout << b1.title << "," << b1.pages << "," << b1.price << endl;

    cout << "Copy: " << endl;
    cout << b2.title << "," << b2.pages << "," << b2.price << endl;

    return 0;
}