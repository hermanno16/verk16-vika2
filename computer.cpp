#include "computer.h"

using namespace std;
//--Constructors--//
Computer::Computer()
{

}
Computer::Computer(int id, string name, string type, int builtYear, string development)
{
    _id = id;
    _name = name;
    _type = type;
    _builtYear = builtYear;
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
int Computer::getBuiltYear() const
{
    return _builtYear;
}
string Computer::getDevelopment() const
{
    return _development;
}
//--Set functions--//
void Computer::setId(int id)
{
    _id = id;
}
void Computer::setName(string name)
{
    _name = name;
}
void Computer::setType(string type)
{
    _type = type;
}
void Computer::setBuiltYear(int builtYear)
{
    _builtYear = builtYear;
}
void Computer::setDevelopment(string development)
{
    _development = development;
}
