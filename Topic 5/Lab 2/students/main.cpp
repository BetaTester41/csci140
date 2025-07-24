#include <iostream>

#include "student.h"
#include "student_report.h"
#include "pair.h"

int main(int argc, char const *argv[])
{
    std::cout << Student::studentCount() << std::endl;

    /* Start of pair
    Pair p{1, 2}; // 1 = key, 2 = value
    std::cout << p.key << ", " << p.value << std::endl;
    End of pair */

    const Student s1("A000000000", "John", "Doe", 0.0);
    Student s2("A000000001", "John", "Doe", 1.0); // if constructor is const, methods cannot be access unless flagged as non modifying.
    Student s3("A000000002", "John", "Doe", 2.0);
    Student s4("A000000003", "John", "Doe", 3.0);
    {
        Student s5("A000000004", "John", "Doe", 4.0);
        std::cout << s5.studentCount() << std::endl; // accessiable through the instance
    }
    std::cout << Student::studentCount() << std::endl;
    Student *s6{new Student("A000000006", "John", "Doe", 5.0)};
    StudentReport sr;

    std::cout << std::boolalpha; // to change output to print true / false.

    std::cout << (s1 == s2) << std::endl;
    std::cout << (s1 != s2) << std::endl;
    std::cout << (s1 > s2) << std::endl;
    std::cout << (s1 < s2) << std::endl;
    std::cout << (s1 >= s2) << std::endl;
    std::cout << (s1 <= s2) << std::endl;
    s2 = s1;
    std::cout << (s1 == s2) << std::endl;
    // proof that they are still different objects
    std::cout << &s1 << " " << &s2 << std::endl;

    Student s7 = s1; // calls the copy constructor
    std::cout << (s1 == s7) << std::endl;

    std::cout << s1 << std::endl; // magic friend

    std::cout << "Enter new GPA: ";
    std::cin >> s2;

    std::cout << s2 << std::endl; // magic friend

    /* debugging calls
    std::cout << Student::studentCount() << std::endl;
    std::cout << s1.getFirstName() << " " << s1.getLastName() << ", " << s1.getGpa() << std::endl;
    std::cout << s6->getFirstName() << " " << s6->getLastName() << ", " << s6->getGpa() << std::endl; // must derefrence to access information
    */

   sr.printStudent(s2);

    return 0;
}
