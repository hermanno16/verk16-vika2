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
    vector<Scientist> searchForScientistsByName(string input);
    vector<Scientist> searchForScientistsByYearOfBirthAtoZ(string yearToFind);
    vector<Scientist> searchForScientistsByYearOfDeathAtoZ(string yearToFind);
    void addScientistToDataBase(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);
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

    vector<Computer> searchForComputersByName(string inputName);
    vector<Computer> searchForComputersByYearBuilt(string yearBuiltToFind);
    vector<Computer> searchForComputersByType(string typeToFind);
    //--Scientists and computers--//
    vector<Scientist> connectComputerToScientist(int idNumber);

private:
    QSqlDatabase _dataBaseMain;
};


#endif // DATAACCESS_H
