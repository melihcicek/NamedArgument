#include <iostream>
#include"Person.h"


int main()
{
    Person p1(LastName{ "cicek" }, 
        FirstName{ "melih" },
        Address{ "istanbul" }, 
        CitizenID{ 123456 }, 
        LicenseID{159});

    Person p2(CitizenID{ 123456 },
        FirstName{ "melih" }, 
        LastName{ "cicek" },
        LicenseID{ 159 },
        Address{ "istanbul" });

    std::cout << p1;
    std::cout << "\n\n";
    std::cout << p2;
}