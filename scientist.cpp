#include "scientist.h"
using namespace std;

Scientist::Scientist(string ID, string name, string gender, string yearOfBirth, string yearOfDeath)
{
    _id = ID;
    _name = name;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;
}
string Scientist::getID() const
{
    return _id;
}
string Scientist::getName() const
{
    return _name;
}
string Scientist::getGender() const
{
    return _gender;
}
string Scientist::getYearOfBirth() const
{
    return _yearOfBirth;
}
string Scientist::getYearOfDeath() const
{
    return _yearOfDeath;
}
void Scientist::setID(string ID)
{
    _id = ID;
}
void Scientist::setName(string name)
{
    _name = name;
}
void Scientist::setGender(string gender)
{
    _gender = gender;
}
void Scientist::setYearOfBirth(string yearOfBirth)
{
    _yearOfBirth = yearOfBirth;
}
void Scientist::setYearOfDeath(string deceased)
{
    _yearOfDeath = deceased;
}
