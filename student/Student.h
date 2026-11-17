#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "Person.h"

class Student : public Person
{
public:

    Student(const std::string& inName, const std::string& inSurname, int inAge) : Person(inName, inSurname, inAge)
    {
        grades = {};

        std::cout << "Added new student: " << name << " " << surname << " " << age << " years old" << std::endl;
    }

    ~Student()
    {
        std::cout << "Clearing up memory for student " << name << " " << surname << std::endl;
        grades.clear();
    }

    void AddGrade(int grade)
    {
        grades.push_back(grade);
    }

    bool RemoveLastGrade()
    {
        if (grades.empty())
        {
            std::cout << "Student " << name << " " << surname << " does not have any grades" << std::endl;
            return false;
        }

        grades.pop_back();
        return true;
    }

    void PrintGrades();

protected:
    std::vector<int> grades;
};
