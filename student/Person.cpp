#include "Person.h"

#include <iostream>
#include <ostream>

Person::Person(const std::string& inName, const std::string& inSurname, int inAge)
{
    name = inName;
    surname = inSurname;
    age = inAge;

    std::cout << "Created new Person with Name: " << name << " " << "Surname: " << surname << " " << "Age: "<< age << std::endl;
}
