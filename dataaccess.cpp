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
        QString id = query.value(query.record().indexOf("Column ID")).toString();
        QString name = query.value(query.record().indexOf("Name")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        QString YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toString();
        QString yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toString();

        cout << query.record().indexOf("Column ID") << endl;
        Scientist newScientist(
                    id.toStdString(),
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}
vector<Scientist> DataAccess::getAllScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT Name,Gender,YearOfBirth,YearOfDeath FROM Scientists ORDER BY Name Asc");
}
vector<Scientist> DataAccess::getAllScientistsZtoA()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists ORDER BY Name Desc");
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
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE Gender = 'Male' ORDER BY Name Asc");
}
vector<Scientist> DataAccess::getAllFemaleScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE Gender = 'Female' ORDER BY Name Asc");
}
vector<Scientist> DataAccess::getAllAliveScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE YearOfDeath is NULL ORDER BY Name Asc");
}
vector<Scientist> DataAccess::getAllDeceasedScientistsAtoZ()
{
    return getAllScientistInfoFromDataBase("SELECT * FROM Scientists WHERE YearOfDeath is NOT NULL ORDER BY Name Asc");
}
    //Scientist - search functions.


vector<Scientist> DataAccess::searchForScientistsByName(string searchString)
{
    QString qSearchString = QString::fromStdString(searchString);


    vector<Scientist> allScientists;

    QSqlQuery query;
    query.prepare("SELECT * FROM Scientists WHERE (Name) LIKE '%"+qSearchString+"%'");
    query.exec();

    while(query.next())
    {
        QString id = query.value(query.record().indexOf("ID")).toString();
        QString name = query.value(query.record().indexOf("Name")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        QString YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toString();
        QString yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toString();

        Scientist newScientist(
                    id.toStdString(),
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
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

    query.prepare("SELECT * FROM Scientists WHERE YearOfBirth = (:something) ORDER BY Name Asc");
    query.bindValue(":something", yearOfBirth);
    query.exec();

    while(query.next())
    {
        QString id = query.value(query.record().indexOf("ID")).toString();
        QString name = query.value(query.record().indexOf("Name")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        QString YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toString();
        QString yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toString();

        Scientist newScientist(
                    id.toStdString(),
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
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

    query.prepare("SELECT * FROM Scientists WHERE YearOfDeath = (:something) ORDER BY Name Asc");
    query.bindValue(":something", yearOfDeath);
    query.exec();

    while(query.next())
    {
        QString id = query.value(query.record().indexOf("ID")).toString();
        QString name = query.value(query.record().indexOf("Name")).toString();
        QString gender = query.value(query.record().indexOf("Gender")).toString();
        QString YearOfBirth = query.value(query.record().indexOf("YearOfBirth")).toString();
        QString yearOfDeath = query.value(query.record().indexOf("YearOfDeath")).toString();

        Scientist newScientist(
                    id.toStdString(),
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;


}


void DataAccess::addScientistToDataBase(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath)
{


    QSqlQuery query;
    query.prepare("INSERT INTO Scientists (Name, Gender, YearOfBirth, YearOfDeath) VALUES (:name, :gender, :yearofbirth, :yearofdeath)");

     query.bindValue(":name", QString::fromStdString(inputName));
     query.bindValue(":gender", QString::fromStdString(inputGender));
     query.bindValue(":yearofbirth", atoi(inputYearOfBirth.c_str()));
     query.bindValue(":yearofdeath", atoi(inputYearOfDeath.c_str()));
     query.exec();

}
//Tengitöflu föllin
vector<Scientist> DataAccess::connectComputerToScientist(int idNumber)
{
    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT FirstName,Gender,YearOfBirth,YearOfDeath FROM Scientists, ConnectionTable WHERE Scientists.ID = ConnectionTable.ID AND ConnectionTable.Cid = (:something)");
    query.bindValue(":something", idNumber);
    query.exec();

    int idName = query.record().indexOf("FirstName");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");
    while(query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }



    return allScientists;
}
/*  Commenta þetta inn þegar Computer.h/cpp er komið
vector<Scientist> DataAccess::connectComputerToScientist(int idNumber)
{
    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT * FROM Computers, ConnectionTable WHERE Computers.Cid = ConnectionTable.Cid AND ConnectionTable.ID = (:something)");
    query.bindValue(":something", idNumber);
    query.exec();


}*/

//-- Computers--//





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
