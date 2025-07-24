#include "pet.h"

#ifndef CAT_H
#define CAT_H

struct Cat : public Pet
{
    Cat(const std::string &, const std::string &);
    Cat(const std::string &);

    std::string speak() const;
    // since private methods are not needed, a struct is sufficent
};

#endif