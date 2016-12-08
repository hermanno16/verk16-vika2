#ifndef Service_H
#define Service_H

#include <string>
#include <vector>
#include "scientist.h"
#include "dataaccess.h"
#include "computer.h"
#include <algorithm>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
using namespace std;


class Service
{
public:
    Service();
    //Scientist functions
    vector<Scientist> getAllScientistsAtoZ();
    vector<Scientist> getAllScientistsZtoA();
    vector<Scientist> getAllScientistsByYearOfBirthAsc();
    vector<Scientist> getAllScientistsByYearOfBirthDes();
    vector<Scientist> getAllDeadOrAliveScientistsAtoZ(string input);
    //Search Scientist functions
    vector<Scientist> searchForScientistsByName(string searchString);
    vector<Scientist> searchForScientistsByYearOfBirthAtoZ(string yearToFind);
    vector<Scientist> searchForScientistsByYearOfDeathAtoZ(string yearToFind);
    vector<Scientist> getScientistsByGenderAtoZ(string gender);
    vector<Scientist> getAllDeceasedScientistsAtoZ();
    //Computer Sort functions
    vector<Computer> getAllComputersAtoZ();
    vector<Computer> getAllComputersZtoA();
    vector<Computer> getAllComputersTypeAtoZ();
    vector<Computer> getAllComputersTypeZtoA();
    vector<Computer> getAllComputersBuiltYearAtoZ();
    vector<Computer> getAllComputersBuiltYearZtoA();
    vector<Computer> getAllComputersDevelopment();
    //Computer Search functions
    vector<Computer> searchForComputersByName(string inputName);
    vector<Computer> searchForComputersByBuiltYear(string builtYearToFind);
    vector<Computer> searchForComputersByType(string typeToFind);
    //Connection tables
    vector<Scientist> connectComputerToScientist(int idNumber);
    //Bool check
    bool isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath);
    void addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);
    bool inputNameValid(string input);

private:
    DataAccess _dAccess;
};




#endif // Service_H
