#include "pet.h"

#ifndef ELEPHANT_H
#define ELEPHANT_H

struct Elephant : public Pet
{
    Elephant(const std::string &, const std::string &);
    Elephant(const std::string &);

    std::string speak() const;
    // since private methods are not needed, a struct is sufficent
};

#endif