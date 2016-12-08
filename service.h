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
    //--Constructor--//
    Service();
    //--Scientists--//
    vector<Scientist> getAllScientistsAtoZ();
    vector<Scientist> getAllScientistsZtoA();
    vector<Scientist> getAllScientistsByYearOfBirthAsc();
    vector<Scientist> getAllScientistsByYearOfBirthDes();
    vector<Scientist> getAllDeadOrAliveScientistsAtoZ(string input);
        //Scientist - search functions.
    vector<Scientist> searchForScientistsByName(string searchString);
    vector<Scientist> searchForScientistsByYearOfBirthAtoZ(string yearToFind);
    vector<Scientist> searchForScientistsByYearOfDeathAtoZ(string yearToFind);
    vector<Scientist> getScientistsByGenderAtoZ(string gender);
    vector<Scientist> getAllDeceasedScientistsAtoZ();
    //--Scientists and computers--//


    //Computer Sort functions
    vector<Computer> getAllComputersAtoZ();
    vector<Computer> getAllComputersZtoA();
    vector<Computer> getAllTypeComputersAtoZ();
    vector<Computer> getAllTypeComputersZtoA();
    vector<Computer> getAllBuildYearComputersAtoZ();
    vector<Computer> getAllBuildYearComputersZtoA();
    vector<Computer> getAllDevelopmentComputers();
    //Computer Search functions
    vector<Computer> searchForComputersByName(string inputName);
    vector<Computer> searchForComputersByYearBuilt(string yearBuiltToFind);
    vector<Computer> searchForComputersByType(string typeToFind);
    //Connection tables

    vector<Scientist> connectComputerToScientist(int idNumber);
    //--Check functions--//
    bool isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath);
    void addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);
    bool inputNameValid(string input);

private:
    DataAccess _dAccess;
};




#endif // Service_H
