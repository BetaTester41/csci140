#include <string>

#ifndef PET_H
#define PET_H

enum class Species
{
    Dog,
    Cat,
    Elephant
};

class Pet
{
public:
    Pet(const std::string&, const std::string&, Species);
    Pet(const std::string&, Species);

    std::string getId() const;
    std::string getName() const;
    Species getSpecies() const;

    void setId(const std::string&);
    void setName(const std::string&);

    virtual std::string speak() const = 0;

private:
    std::string id;
    std::string name;
    Species species;

};

#endif