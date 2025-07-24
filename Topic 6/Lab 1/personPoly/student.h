#include <iostream> // output of iostream
#include <string>

#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

// no student can be created without an ID, First Name, or Last Name
class Student : public Person
{
    friend std::ostream &operator<<(std::ostream &, const Student &); // friend is not a member of a object
    friend std::istream &operator>>(std::istream &, Student &);
    // friend class StudentReport;

public:
    // a constructor does not need to be public;
    Student(const std::string &, const std::string &, const std::string &);                              // * id, fname, lname
    Student(const std::string &, const std::string &, const std::string &, double);                      // * id, fname, lname, GPA
    Student(const std::string &, const std::string &, const std::string &, const std::string &);         // * id, fname, mname, lname
    Student(const std::string &, const std::string &, const std::string &, const std::string &, double); // * id, fname, mname, lname, GPA

    // copy constructor
    // Student(const Student&) = delete; for none
    Student(const Student &) = default; // for defualt duh

    // destructions (cannot be private, no parameters)
    ~Student();

    // accessors
    std::string getId() const;
    double getGpa() const;
    static size_t studentCount(); // part of the class, can be accessed by an instance.

    // mutator
    void setId(const std::string &);
    void setGpa(double);

    // operators
    bool operator==(const Student &) const;
    bool operator!=(const Student &) const;
    bool operator>(const Student &) const;
    bool operator<(const Student &) const;
    bool operator<=(const Student &) const;
    bool operator>=(const Student &) const;

    // assignment
    Student &operator=(const Student &); // copies over all instance vars

    // additoina on 11/7 overriding
    std::string speak() const;

private:
    mutable std::string id; // mutable tag makes the var able to change inside a const funciton.
    double gpa;

    static size_t count; // you must declare it in the global scope
};
/*
public:
    still allowed syntax
*/

#endif