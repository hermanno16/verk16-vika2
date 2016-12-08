#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(int id, string name, string type, int builtYear, string development);
    void setId(int id);
    void setName(string name);
    void setType(string type);
    void setBuiltYear(int builtYear);
    void setDevelopment(string developement);
    int getId() const;
    string getName() const;
    string getType() const;
    int getBuiltYear() const;
    string getDevelopment() const;

private:
    int    _id;
    string _name;
    string _type;
    int    _builtYear;
    string _development;

};

#endif // COMPUTER_H
