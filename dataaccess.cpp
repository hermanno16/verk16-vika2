#include "dataaccess.h"
#include <QSqlRecord>
#include <QSqlField>
#include <QString>
#include <QSqlDatabase>

using namespace std;
//-- Constructors --//
DataAccess::DataAccess()
{
    openDataBase();
}
DataAccess::~DataAccess()
{
    _dataBaseMain.close();
}

//-- Computer scientists --//
    //All scientists - functions.
vector<Scientist> DataAccess::getAllScientistInfoFromDataBase(QString queryCommand)
{
    vector<Scientist> allScientists;

    QSqlQuery query;
    query.prepare(queryCommand);
    query.exec();


    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        int yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toUInt();

        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}
vector<Scientist> DataAccess::getAllScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY FirstName Asc");
}
vector<Scientist> DataAccess::getAllScientistsZtoA()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY FirstName Desc");
}
vector<Scientist> DataAccess::getAllScientistsByYearOfBirthAsc()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY YearOfBirth Asc");
}
vector<Scientist> DataAccess::getAllScientistsByYearOfBirthDes()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY YearOfBirth Desc");
}
vector<Scientist> DataAccess::getAllMaleScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE Gender = 'Male' ORDER BY FirstName Asc");
}
vector<Scientist> DataAccess::getAllFemaleScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE Gender = 'Female' ORDER BY FirstName Asc");
}
vector<Scientist> DataAccess::getAllAliveScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE YearOfDeath is NULL ORDER BY FirstName Asc");
}
vector<Scientist> DataAccess::getAllDeceasedScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE YearOfDeath is NOT NULL ORDER BY FirstName Asc");
}
    //Scientist - search functions.
vector<Scientist> DataAccess::searchForScientistsByName(string searchString)
{
    QString qSearchString = QString::fromStdString(searchString);


    vector<Scientist> allScientists;

    QSqlQuery query;
    query.prepare("SELECT * FROM Scientists WHERE (FirstName) LIKE '%"+qSearchString+"%'");
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        int yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toUInt();

        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}
vector<Scientist> DataAccess::searchForScientistsByYearOfBirthAtoZ(string yearToFind)
{
    int yearOfBirth = atoi(yearToFind.c_str());

    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT * FROM Scientists WHERE YearOfBirth = (:something) ORDER BY FirstName Asc");
    query.bindValue(":something", yearOfBirth);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        int yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toUInt();

        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}
vector<Scientist> DataAccess::searchForScientistsByYearOfDeathAtoZ(string yearToFind)
{
    int yearOfDeath = atoi(yearToFind.c_str());

    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT * FROM Scientists WHERE YearOfDeath = (:something) ORDER BY FirstName Asc");
    query.bindValue(":something", yearOfDeath);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        int yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toUInt();

        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;


}
    //Scientist - other functions.
void DataAccess::addScientistToDataBase(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath)
{


    QSqlQuery query;
    query.prepare("INSERT INTO Scientists (FirstName, Gender, YearOfBirth, YearOfDeath) VALUES (:name, :gender, :yearofbirth, :yearofdeath)");

     query.bindValue(":name", QString::fromStdString(inputName));
     query.bindValue(":gender", QString::fromStdString(inputGender));
     query.bindValue(":yearofbirth", atoi(inputYearOfBirth.c_str()));
     query.bindValue(":yearofdeath", atoi(inputYearOfDeath.c_str()));
     query.exec();

}
//--Scientists and computers--//

vector<Scientist> DataAccess::connectComputerToScientist(int idNumber)
{
    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT ID,FirstName,Gender,YearOfBirth,YearOfDeath FROM Scientists, ConnectionTable WHERE Scientists.ID = ConnectionTable.ID AND ConnectionTable.Cid = (:something)");
    query.bindValue(":something", idNumber);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("FirstName")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        int YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toUInt();
        int yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toUInt();

        cout << id << endl;

        Scientist newScientist(
                    id,
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth,
                    yearOfDeath
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}
/*
vector<Scientist> DataAccess::connectComputerToScientist(int idNumber)
{
    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT * FROM Computers, ConnectionTable WHERE Computers.Cid = ConnectionTable.Cid AND ConnectionTable.ID = (:something)");
    query.bindValue(":something", idNumber);
    query.exec();


}
*/
//-- Computers--//
    //All Computers - functions.
vector<Computer> DataAccess::getAllComputerInfoFromDataBase(QString queryCommand)
{
    vector<Computer> allComputers;

    QSqlQuery query;
    query.prepare(queryCommand);
    query.exec();


    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("ComputerName")).toString();
        QString type = query.value(query.record().indexOf("Type")).toString();
        int builtYear = query.value(query.record().indexOf("BuiltYear")).toUInt();
        QString development = query.value(query.record().indexOf("Development")).toString();


        Computer newComputer(
                    id,
                    name.toStdString(),
                    type.toStdString(),
                    builtYear,
                    development.toStdString()
                    );

        allComputers.push_back(newComputer);
    }

    return allComputers;
}
vector<Computer> DataAccess::getAllComputersAtoZ()
{
    return getAllComputerInfoFromDataBase("SELECT ComputerName,BuiltYear,Type,Developed FROM Scientists ORDER BY Name Asc");
}
vector<Computer> DataAccess::getAllComputersZtoA()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDER BY ComputerName Desc");
}
vector<Computer> DataAccess::getAllComputersBuiltYearAtoZ()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDERBY BuiltYear Asc");
}
vector<Computer> DataAccess::getAllComputersBuiltYearZtoA()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDERBY BuiltYear Desc");
}
vector<Computer> DataAccess::getAllComputersTypeAtoZ()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDERBY Type Asc");
}
vector<Computer> DataAccess::getAllComputersTypeZtoA()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computers ORDERBY Type Desc");
}
vector<Computer> DataAccess::getAllComputersDevelopment()
{
    return getAllComputerInfoFromDataBase("SELECT * FROM Computer WHERE Development is NOT NULL ORDER BY ComputerName Asc");
}
    //Computers - search functions
vector<Computer> DataAccess::searchForComputersByName(string inputName)
{
    QString qSearchString = QString::fromStdString(inputName);


    vector<Computer> allComputers;

    QSqlQuery query;
    query.prepare("SELECT * FROM Computers WHERE (ComputerName) LIKE '%"+qSearchString+"%'");
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("Name")).toString();
        QString type = query.value(query.record().indexOf("Type")).toString();
        int builtYear = query.value(query.record().indexOf("builtYear")).toUInt();
        QString development = query.value(query.record().indexOf("Development")).toString();

        Computer newComputer(
                    id,
                    name.toStdString(),
                    type.toStdString(),
                    builtYear,
                    development.toStdString()
                    );

        allComputers.push_back(newComputer);
    }

    return allComputers;

}
vector<Computer> DataAccess::searchForComputersByBuiltYear(string builtYearToFind)
{
    int builtYear = atoi(builtYearToFind.c_str());

    vector<Computer> allComputers;

    QSqlQuery query;

    query.prepare("SELECT * FROM Computer WHERE BuiltYear = (:something) ORDER BY ComputerName Asc");
    query.bindValue(":something", builtYear);
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("ComputerName")).toString();
        QString type = query.value(query.record().indexOf("Type")).toString();
        int builtYear = query.value(query.record().indexOf("builtYear")).toUInt();
        QString development = query.value(query.record().indexOf("Development")).toString();

        Computer newComputer(
                    id,
                    name.toStdString(),
                    type.toStdString(),
                    builtYear,
                    development.toStdString()
                    );

        allComputers.push_back(newComputer);
    }

    return allComputers;

}
vector<Computer> DataAccess::searchForComputersByType(string typeToFind)
{
    QString qSearchString = QString::fromStdString(typeToFind);


    vector<Computer> allComputers;

    QSqlQuery query;
    query.prepare("SELECT * FROM Computers WHERE (Type) LIKE '%"+qSearchString+"%'");
    query.exec();

    while(query.next())
    {
        int id = query.value(query.record().indexOf("ID")).toUInt();
        QString name = query.value(query.record().indexOf("Name")).toString();
        QString type = query.value(query.record().indexOf("Type")).toString();
        int builtYear = query.value(query.record().indexOf("builtYear")).toUInt();
        QString development = query.value(query.record().indexOf("Development")).toString();

        Computer newComputer(
                    id,
                    name.toStdString(),
                    type.toStdString(),
                    builtYear,
                    development.toStdString()
                    );

        allComputers.push_back(newComputer);
    }

    return allComputers;
}

//-- Connect to database --//
void DataAccess::openDataBase()
{
    _dataBaseMain = QSqlDatabase::addDatabase("QSQLITE");
    _dataBaseMain.setDatabaseName("Verk1.sqlite");

    if(!_dataBaseMain.open())
    {
        qDebug() << "Error: connection with database failed!";
    }
    else
    {
        qDebug() << "Connection succeeded";
    }
}
QSqlDatabase DataAccess::readDataBase()
{
    return _dataBaseMain;
}
