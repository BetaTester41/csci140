#include <iostream>
#include <fstream>

#include "student.h"

void printStudent(const Student &, std::ostream &);

int main(int argc, char const *argv[])
{
    Student s1{"John, Doe", 25, 3.55};
    Student s2{"Jane Doe", 25, 3.56};
    Student s3{"James Smith", 25, 3.57};
    Student s4{"Joana Smith", 25, 3.58};
    Student students[]{s1, s2, s3, s4};

    std::ofstream exportFile("export.csv", std::ios::out);

    for (Student s : students)
        printStudent(s, exportFile);

    exportFile.close();

    return 0;
}

void printStudent(const Student &s, std::ostream &out)
{
    out << "\"" << s.name << "\","
        << s.age << ","
        << s.gpa << std::endl;
}
