#include <iostream>
#include "pet.h"

#include "dog.h"
#include "cat.h"
#include "elephant.h"

int main(int argc, char const *argv[])
{
    Pet *pets[]{
        new Dog("Snoopy"),
        new Cat("0", "Tobi"),
        new Elephant("A980543", "Dumbo"),
        new Dog("A98032", "Pluto"),
        new Elephant("Stompper")};

    for (Pet *p : pets)
        std::cout << p->speak() << std::endl;

    return 0;
}
