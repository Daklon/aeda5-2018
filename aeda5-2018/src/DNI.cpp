#include "DNI.h"

DNI::DNI(){
    std::random_device rd;
    void* mem = malloc(1);
    std::mt19937 eng((int)mem);
    std::uniform_int_distribution<> distr(10000000,99999999);
    std::uniform_int_distribution<> distr2(65,90);
    this->number = distr(eng);
    this->letra = distr2(eng);
}

DNI::DNI(unsigned long number, std::string name, std::string surname){
    this->number = number;
    this->name = name;
    this->surname = surname;
}

DNI::DNI(unsigned long number){
    this->number = number;
}

unsigned long DNI::getDni(){
    return this->number + (unsigned long) this->letra;
}

std::string DNI::getname(){
    return this->name;
}

std::string DNI::getsurname(){
    return this->surname;
}

DNI::operator long unsigned int()
{
    return this->getDni() ;
}

bool DNI::operator ==(int other){
    return (other == (int) (this->getDni()));
}

bool DNI::operator ==(DNI other){
    return (other.getDni() == this->getDni());
}

bool DNI::operator < (DNI other){
    return (this->getDni() < other.getDni());
}

std::ostream& DNI::operator <<(std::ostream& stream){
    stream << this->number;
    return stream;
}

char DNI::getletra(){
    return this->letra;
}

