#include "student_report.h"

void StudentReport::printStudent(const Student & student)
{
    std::cout << "Student Report:" << std::endl;
    std::cout << student.firstName << " " << student.lastName << " - " << student.gpa << std::endl;
}