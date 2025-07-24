#include <stdexcept>

#include "person.h"

Person::Person(const std::string &firstName, const std::string &lastName)
    : Person(firstName, lastName, "")
{}

Person::Person(const std::string &firstName, const std::string &lastName, const std::string &middleName)
{
    setFirstName(firstName);
    setLastName(lastName);
    setMiddleName(middleName);
}

std::string Person::getFirstName() const
{
    // gpa++; doesn't work as it cannot be modifie dby const
    // id = "HAHA"; works as it is labeled mutable
    return firstName;
}

std::string Person::getMiddleName() const
{
    return middleName;
}

std::string Person::getLastName() const
{
    return lastName;
}

void Person::setFirstName(const std::string &firstName)
{
    if (firstName.empty())
        throw std::runtime_error("First name cannot be empty!");
    this->firstName = firstName;
}

void Person::setMiddleName(const std::string &middleName)
{
    this->middleName = middleName;
}

void Person::setLastName(const std::string &lastName)
{
    if (lastName.empty())
        throw std::runtime_error("Last name cannot be empty!");
    this->lastName = lastName;
}

// std::string Person::speak() const
// {
//     // depends on what the person is
//     return "n/a";
// }
