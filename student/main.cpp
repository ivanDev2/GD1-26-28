#include <iostream>

#include "Person.h"
#include "Student.h"

int main()
{
    Person* Ciccio = new Person("Mirko", "Alessandrini", 37);
    Person* Joker = new Person("Simone", "Alessandrini", 35);

    Student* Marco = new Student("Marco", "Bianchi", 25);

    Ciccio->PrintFullName();
    Joker->PrintFullName();

    Marco->PrintFullName();
    Marco->PrintGrades();

    return 0;
}