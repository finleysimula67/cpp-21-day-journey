#include <iostream>

using namespace std;

class Engine
{
public:
    Engine()
    {
    }
    void start()
    {
        cout << "Engine started." << endl;
    }
};
class Car
{
    Engine engine;

public:
    void start()
    {
        cout << "Car Started" << endl;
        engine.start();
    }
};
int main()
{
    Car c1;
    c1.start();
    return 0;
}