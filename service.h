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
    vector<Scientist> getAllDeadOrAliveScientistsAtoZ(char input);
    //Scientist - search functions.
    vector<Scientist> searchForScientistsByName(string searchString);
    vector<Scientist> searchForScientistsByYearOfBirthAtoZ(string yearToFind);
    vector<Scientist> searchForScientistsByYearOfDeathAtoZ(string yearToFind);
    vector<Scientist> getScientistsByGenderAtoZ(char gender);
    vector<Scientist> getAllDeceasedScientistsAtoZ();
    string getScientistName(int idNumber);
    //Scientist - other functions.
    void removeScientistFromDataBase(int idOfScientist);
    //--Computer--//
    vector<Computer> getAllComputersAtoZ();
    vector<Computer> getAllComputersZtoA();
    vector<Computer> getAllTypesComputersAtoZ(string type);
    vector<Computer> getAllComputersDevelopment();
    vector<Computer> getAllBuildYearComputers(string yearBuilt);
    vector<Computer> getAllDevelopmentAndOriginalComputers(string development);
    //Computer Search functions
    vector<Computer> searchForComputersByName(string inputName);
    vector<Computer> searchForComputersByYearBuilt(string yearBuiltToFind);
    vector<Computer> searchForComputersByType(string typeToFind);
    string getComputerName(int idNumber);
    //Connection tables
    vector<Scientist> connectComputerToScientist(int idNumber);
    vector<Computer> connectScientistToComputer(int idNumber);
    //--Check functions--//
    bool isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath);
    bool isAddComputerValid(string name, string yearBuilt, string type, string development);
    void addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);
    void addComputerToData(string inputName, string inputYearBuilt, string inputType, string inputDevelopment);
    bool inputNameValid(string input);


private:
    DataAccess _dAccess;
};


#endif // Service_H
