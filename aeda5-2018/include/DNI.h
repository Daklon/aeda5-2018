#ifndef DNI_H
#define DNI_H

#include "stdlib.h"
#include "time.h"
#include "random"
#include <iostream>

class DNI
{
public:
    DNI();
    DNI(unsigned long number);
    DNI(unsigned long number,std::string name, std::string surname);
    bool operator ==(int other);
    bool operator ==(DNI other);
    bool operator <(DNI other);
    std::ostream& operator <<(std::ostream& stream);
    operator unsigned long();
    unsigned long getDni();
    std::string getname();
    std::string getsurname();
    char getletra();


private:
    unsigned long number;
    std::string name;
    std::string surname;
    char letra;
};

#endif

