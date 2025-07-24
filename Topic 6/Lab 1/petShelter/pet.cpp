#include <stdexcept>

#include "pet.h"

Pet::Pet(const std::string &id, const std::string &name, Species species) : id{id}, species{species}
{
    setName(name);
}

Pet::Pet(const std::string &name, Species species) : Pet("", name, species) {}

std::string Pet::getId() const
{
    return id;
}

std::string Pet::getName() const
{
    return name;
}

Species Pet::getSpecies() const
{
    return species;
}

void Pet::setId(const std::string &id)
{
    this->id = id;
}

void Pet::setName(const std::string &name)
{
    if (name.empty())
        throw std::runtime_error("Name cannot be empty");
    this->name = name;
}
