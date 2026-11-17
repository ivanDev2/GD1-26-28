#include "Student.h"

void Student::PrintGrades()
{
    if (grades.empty())
    {
        std::cout << "Student " << name << " " << surname << " does not have any grades" << std::endl;
        return;
    }

    std::cout << "Grades for student " << name << " " << surname << ": ";
    for (const auto& grade : grades)
    {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}
