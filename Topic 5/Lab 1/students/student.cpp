#include <stdexcept>

#include "student.h"

Student::Student(const std::string &id, const std::string &firstName, const std::string &lastName)
    : Student(id, firstName, lastName, {}, 0.0)
// you are able to execute methods and define vars before the constructor space is created.
{
}

Student::Student(const std::string &id, const std::string &firstName, const std::string &lastName, double gpa)
    : Student(id, firstName, lastName, {}, gpa)
{
}

Student::Student(const std::string &id, const std::string &firstName, const std::string &lastName, const std::string &middleName)
    : Student(id, firstName, lastName, middleName, 0.0)
{
}

Student::Student(const std::string &id, const std::string &firstName, const std::string &lastName, const std::string &middleName, double gpa)
{
    // all constructor calls are made to here
    setId(id);
    setFirstName(firstName);
    setLastName(lastName);
    setMiddleName(middleName);
    setGpa(gpa);

    ++count; // changes the global value reguardless;
}

Student::~Student() { --count; } // not nessarry if you don't need it.

std::string Student::getId() const
{
    return id;
}

std::string Student::getFirstName() const
{
    // gpa++; doesn't work as it cannot be modifie dby const
    // id = "HAHA"; works as it is labeled mutable
    return firstName;
}

std::string Student::getMiddleName() const
{
    return middleName;
}

std::string Student::getLastName() const
{
    return lastName;
}

double Student::getGpa() const
{
    return gpa;
}

size_t Student::studentCount()
{
    return count;
}

void Student::setId(const std::string &id)
{
    if (id.empty())
        throw std::runtime_error("ID cannot be empty!");
    this->id = id;
}

void Student::setFirstName(const std::string &firstName)
{
    if (firstName.empty())
        throw std::runtime_error("First name cannot be empty!");
    this->firstName = firstName;
}

void Student::setMiddleName(const std::string &middleName)
{
    this->middleName = middleName;
}

void Student::setLastName(const std::string &lastName)
{
    if (lastName.empty())
        throw std::runtime_error("Last name cannot be empty!");
    this->lastName = lastName;
}

void Student::setGpa(double gpa)
{
    if (gpa < 0)
        throw std::runtime_error("Gpa cannot be less than 0!");
    this->gpa = gpa;
}

size_t Student::count{}; // decleared in the global scope