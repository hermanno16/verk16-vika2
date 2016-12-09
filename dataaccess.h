#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "scientist.h"
#include <iostream>
#include <string>
#include <vector>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QtSql>
#include "scientist.h"
#include "computer.h"

using namespace std;

class DataAccess
{

public:
    //--Constructors--//
    DataAccess();
    ~DataAccess();
    //--Booting functions--//
    QSqlDatabase readDataBase();
    void openDataBase();
    //--Scientists--//
    vector<Scientist> getAllScientistInfoFromDataBase(QString queryCommand);
    vector<Scientist> getAllScientistsAtoZ();
    vector<Scientist> getAllScientistsZtoA();
    vector<Scientist> getAllScientistsByYearOfBirthAsc();
    vector<Scientist> getAllScientistsByYearOfBirthDes();
    vector<Scientist> getAllMaleScientistsAtoZ();
    vector<Scientist> getAllFemaleScientistsAtoZ();
    vector<Scientist> getAllAliveScientistsAtoZ();
    vector<Scientist> getAllDeceasedScientistsAtoZ();
    //--Scientist search functions
    vector<Scientist> searchForScientistsByName(string input);
    vector<Scientist> searchForScientistsByYearOfBirthAtoZ(string yearToFind);
    vector<Scientist> searchForScientistsByYearOfDeathAtoZ(string yearToFind);
    //--Scientist other functions
    void addScientistToDataBase(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);
    void removeScientistFromDatabase(int idOfScientist);
    bool addScientistToComputer(int ID, int Cid);
    void removeRelationFromDatabase(int id, int cID);
    //--Computers--//
    vector<Computer> getAllComputerInfoFromDataBase(QString queryCommand);
    vector<Computer> getAllComputersAtoZ();
    vector<Computer> getAllComputersZtoA();
    vector<Computer> getAllComputersYearBuiltAtoZ();
    vector<Computer> getAllComputersYearBuiltZtoA();
    vector<Computer> getAllComputersTypeAtoZ();
    vector<Computer> getAllComputersTypeElectronic();
    vector<Computer> getAllComputersTypeElectronicMechanical();
    vector<Computer> getAllComputersTypeMechanical();
    vector<Computer> getAllComputersTransistor();
    vector<Computer> getAllComputersTypeMicrocomputer();
    vector<Computer> getAllComputersTypeTernary();
    vector<Computer> getAllComputersDeveloped();
    vector<Computer> getAllComputersOriginal();
    vector<Computer> getAllComputersDevelopedAndOriginal();
    //--Computer search functions
    vector<Computer> searchForComputersByName(string inputName);
    vector<Computer> searchForComputersByYearBuilt(string yearBuiltToFind);
    vector<Computer> searchForComputersByType(string typeToFind);
    string getComputerName(int idNumber);
    string getScientistName(int idNumber);
    //--Computer other functions--//
    void addComputerToDataBase(string inputName, string inputYearBuilt, string inputType, string inputDevelopment);
    void removeComputerFromDatabase(int idOfComputer);
    //--Scientists and computers--//
    vector<Scientist> connectComputerToScientist(int idNumber);
    vector<Computer> connectScientistToComputer(int idNumber);

private:
    QSqlDatabase _dataBaseMain;
};


#endif // DATAACCESS_H
