#include "User.h"

User::User(int id)
    : id(id)
{
}

int User::getId() const
{
    return id;
}