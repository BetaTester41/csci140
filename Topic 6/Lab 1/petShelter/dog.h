#include "pet.h"

#ifndef DOG_H
#define DOG_H

struct Dog : public Pet
{
    Dog(const std::string &, const std::string &);
    Dog(const std::string &);

    std::string speak() const;
    // since private methods are not needed, a struct is sufficent
};

#endif