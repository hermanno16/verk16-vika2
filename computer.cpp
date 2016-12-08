#include "computer.h"

using namespace std;
//--Constructors--//
Computer::Computer()
{

}
Computer::Computer(int ID, string name, string type, int yearBuilt, string development)
{
    _id = ID;
    _name = name;
    _type = type;
    _yearBuilt = yearBuilt;
    _development = development;
}
//--Get funcitons--//
int Computer::getId() const
{
    return _id;
}
string Computer::getName() const
{
    return _name;
}
string Computer::getType() const
{
    return _type;
}
int Computer::getYearBuilt() const
{
    return _yearBuilt;
}
string Computer::getDevelopment() const
{
    return _development;
}
//--Set functions--//
void Computer::setId(int ID)
{
    _id = ID;
}
void Computer::setName(string name)
{
    _name = name;
}
void Computer::setType(string type)
{
    _type = type;
}
void Computer::setYearBuilt(int yearBuilt)
{
    _yearBuilt = yearBuilt;
}
void Computer::setDevelopment(string development)
{
    _development = development;
}
