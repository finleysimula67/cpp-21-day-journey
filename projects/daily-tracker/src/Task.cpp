#include "Task.h"

Task::Task(int id , std::string title)
   :id(id) , title(title)
{

}
int Task::getId() const
{
    return id;
}
std::string Task::getTitle() const
{
    return title;
}