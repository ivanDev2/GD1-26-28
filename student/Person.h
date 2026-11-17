#pragma once

#include <iostream>
#include <ostream>
#include <string>

class Person
{
public:
    Person(const std::string &inName, const std::string &inSurname, int inAge);

    void PrintName()
    {
        std::cout << "My name is: " << name << std::endl;
    }

    void PrintSurname()
    {
        std::cout << "My surname is: " << surname << std::endl;
    }

    void PrintFullName()
    {
        std::cout << "My full name is: " << name << " " << surname << std::endl;
    }

    void PrintAge()
    {
        std::cout << "My age is: " << age << std::endl;
    }

protected:
    std::string name;
    std::string surname;
    int age;
};
