#include <iostream>

#include "student.h"
#include "pair.h"

int main(int argc, char const *argv[])
{
    std::cout << Student::studentCount() << std::endl;

    /* Start of pair */
    Pair p{1, 2}; // 1 = key, 2 = value
    std::cout << p.key << ", " << p.value << std::endl;
    /* End of pair*/

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

    std::cout << Student::studentCount() << std::endl;
    std::cout << s1.getFirstName() << " " << s1.getLastName() << ", " << s1.getGpa() << std::endl;
    std::cout << s6->getFirstName() << " " << s6->getLastName() << ", " << s6->getGpa() << std::endl; // must derefrence to access information

    return 0;
}
