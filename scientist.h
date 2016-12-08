#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>

using namespace std;

class Scientist
{
public:
    //--Constructors--//
    Scientist(int ID, string name, string gender, int yearOfBirth, int yearOfDeath);
    //--Set functions--//
    void setName(string name);
    void setGender(string gender);
    void setYearOfBirth(int yearOfBirth);
    void setYearOfDeath(int yearOfDeath);
    void setID(int ID);
    //--Get funcitons--//
    int getID() const;
    string getName() const;
    string getGender() const;
    int getYearOfBirth() const;
    int getYearOfDeath() const;

private:
    int _id;
    string _name;
    string _gender;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // SCIENTIST_H
