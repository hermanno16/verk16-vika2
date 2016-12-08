#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>

using namespace std;

class Scientist
{
public:
    Scientist(string ID, string name, string gender, string yearOfBirth, string yearOfDeath);
    void setName(string name);
    void setGender(string gender);
    void setYearOfBirth(string yearOfBirth);
    void setYearOfDeath(string deceased);
    void setID(string ID);
    string getID() const;
    string getName() const;
    string getGender() const;
    string getYearOfBirth() const;
    string getYearOfDeath() const;

private:
    string _id;
    string _name;
    string _gender;
    string _yearOfBirth;
    string _yearOfDeath;
};

#endif // SCIENTIST_H
