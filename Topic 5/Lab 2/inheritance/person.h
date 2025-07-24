#include <string>

#ifndef PERSON_H
#define PERSON_H

class Person
{
    friend std::ostream &operator<<(std::ostream &, const Person &); // friend is not a member of a object
    friend std::istream &operator>>(std::istream &, Person &);

public:
    Person(const std::string &, const std::string &);
    Person(const std::string &, const std::string &, const std::string &);

    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getLastName() const;

    void setFirstName(const std::string &);
    void setMiddleName(const std::string &);
    void setLastName(const std::string &);

    // addition at 11/7
    std::string speak() const;

private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
};

#endif