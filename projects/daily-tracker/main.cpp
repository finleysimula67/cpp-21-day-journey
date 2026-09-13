#include<iostream>
#include "Task.h"

using namespace std;
int main()
{
    Task task(1, "Workout");

    cout << "Task: " << endl;
    cout << task.getId() <<" " <<task.getTitle();
    return 0;
}