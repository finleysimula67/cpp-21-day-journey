#ifndef TASK_H
#define TASK_H
#include <string>

class Task
{
private:
    int id;
    std::string title;

public:
    Task(int id, std::string title);
    int getId() const;
    std::string getTitle() const;
};

#endif