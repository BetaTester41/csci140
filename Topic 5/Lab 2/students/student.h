#include <iostream> // output of iostream
#include <string>

#ifndef STUDENT_H
#define STUDENT_H
// no student can be created without an ID, First Name, or Last Name
class Student
{
    friend class StudentReport; // being a friend of StudentReport doesnt mean that student report is a friend with you :L
    friend std::ostream &operator<<(std::ostream &, const Student &); // friend is not a member of a object
    friend std::istream &operator>>(std::istream &, Student &);
    // friend class StudentReport;

public:
    // a constructor does not need to be public;
    Student(const std::string &, const std::string &, const std::string &);                              // * id, fnmae, lname
    Student(const std::string &, const std::string &, const std::string &, double);                      // * id, fnmae, lname, GPA
    Student(const std::string &, const std::string &, const std::string &, const std::string &);         // * id, fnmae, mname, lname
    Student(const std::string &, const std::string &, const std::string &, const std::string &, double); // * id, fname, mname, lname, GPA

    // copy constructor
    // Student(const Student&) = delete; for none
    Student(const Student &) = default; // for defualt duh

    // destructions (cannot be private, no parameters)
    ~Student();

    // accessors
    std::string getId() const;
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getLastName() const;
    double getGpa() const;
    static size_t studentCount(); // part of the class, can be accessed by an instance.

    // mutator
    void setId(const std::string &);
    void setFirstName(const std::string &);
    void setMiddleName(const std::string &);
    void setLastName(const std::string &);
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

private:
    mutable std::string id; // mutable tag makes the var able to change inside a const funciton.
    std::string firstName;
    std::string lastName;
    std::string middleName;

    double gpa;

    static size_t count; // you must declare it in the global scope
};
/*
public:
    still allowed syntax
*/

#endif