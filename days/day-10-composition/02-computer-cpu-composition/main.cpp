#include <iostream>
using namespace std;

class CPU
{
public:
    CPU() {}

    void run()
    {
        cout << "Cpu running.";
    }
};
class Computer
{
    CPU cpu;

public:
    void start()
    {
        cout << "Computer starting..." << endl;
        cpu.run();
    }
};
int main()
{
    Computer computer;
    computer.start();
    return 0;
}