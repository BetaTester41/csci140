#include <stdexcept>

#include "student.h"

Student::Student(const std::string &id, const std::string &firstName, const std::string &lastName)
    : Student(id, firstName, lastName, {}, 0.0)
// you are able to execute methods and define vars before the constructor space is created.
{}

Student::Student(const std::string &id, const std::string &firstName, const std::string &lastName, double gpa)
    : Student(id, firstName, lastName, {}, gpa)
{
}

Student::Student(const std::string &id, const std::string &firstName, const std::string &lastName, const std::string &middleName)
    : Student(id, firstName, lastName, middleName, 0.0)
{
}

Student::Student(const std::string &id, const std::string &firstName, const std::string &lastName, const std::string &middleName, double gpa)
    : Person(firstName, lastName, middleName)
{
    // all constructor calls are made to here
    setId(id);
    setGpa(gpa);

    ++count; // changes the global value reguardless;
}

// Student::Student(const Student &other)
// {
//     *this = other;
// }

Student::~Student() { --count; } // not nessarry if you don't need it.

std::string Student::getId() const
{
    return id;
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

void Student::setGpa(double gpa)
{
    if (gpa < 0)
        throw std::runtime_error("Gpa cannot be less than 0!");
    this->gpa = gpa;
}

bool Student::operator==(const Student &other) const
{
    return gpa == other.gpa;
}

bool Student::operator!=(const Student &other) const
{
    return !(*this == other);
}

bool Student::operator>(const Student &other) const
{
    return gpa > other.gpa; // comparing current object with the other object.
}

bool Student::operator<(const Student &other) const
{
    return gpa < other.gpa;
}

bool Student::operator<=(const Student &other) const
{
    return !(*this > other);
}

bool Student::operator>=(const Student &other) const
{
    return !(*this < other);
}

Student &Student::operator=(const Student &other)
{
    id = other.id;
    setFirstName(other.getFirstName());
    setLastName(other.getLastName());
    setMiddleName(other.getMiddleName());
    gpa = other.gpa;
    return *this;
}

std::string Student::speak() const
{
    return "You forgot const?";
}

std::ostream &operator<<(std::ostream &out, const Student &student)
{
    out << student.id << ": " << student.getLastName() << " - " << student.gpa;
    return out;
}

std::istream &operator>>(std::istream &in, Student &student)
{
    in >> student.gpa;
    return in;
}

size_t Student::count{}; // decleared in the global scope