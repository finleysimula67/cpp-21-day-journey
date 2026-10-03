#include <iostream>
#include <memory>
#include <string>
using namespace std;
class Task
{
private:
    string title;
public:
    Task(string title ): title(title){
        cout << "Task created: " << title << endl;
    }
    ~Task(){
        cout << "Task destroyed: " << title << endl;
    }
    void show() const{
        cout << "Task: " << title << endl;
    }
};
void processTask(unique_ptr<Task> task){
    task->show();
}
int main(){
    unique_ptr<Task> task = make_unique<Task>("Learn C++ Memory Management");
    processTask(move(task));
    if (task == nullptr){
        cout << "Ownership transferred." << endl;
    }
    return 0;
}