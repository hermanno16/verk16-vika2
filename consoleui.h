#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "service.h"
#include "computer.h"
#include "scientist.h"
#include <cstdlib>
#include <QString>
#include <QStringList>
#include <iostream>
#include <string>
#include <vector>


class ConsoleUI
{
public:
    //--Constructor--//
    ConsoleUI();
    //--Booting functions--//
    //Booting - Print functions.
    void beginingOfProgramPrint();
    void mainMenuPrint();
    //Booting - Other functions.
    void mainMenu();
    bool goBackOrQuit(char command);
    //--Scientists--//
    //Scientists - Menu functions.
    void scientistWhatToDo();
    void scientistMenu();
    void scientistSearchMenu();
    void scientistListMenu();
    void scientistListAllMenu();
    void scientistListAllGenderMenu();
    void scientistListAllDeadOrAliveMenu();
    void scientistListAllYearOfBirthMenu();
    //Scientist - Print functions.
    void scientistWhatToDoPrint();
    void printScientist(vector<Scientist> temp);
    void scientistMenuPrint();
    void scientistSearchMenuPrint();
    void scientistListMenuPrint();
    void scientistListAllMenuPrint();
    void scientistListAllGenderMenuPrint();
    void scientistListAllDeadOrAliveMenuPrint();
    void scientistListAllYearOfBirthMenuPrint();
    bool wantToModifyOrNot(char command);
    //Scientist - Other functions.
    void scientistNameColumn();
    void addScientist();
    void removeScientistFromDataBase();

    void scientistWorkedOn();

    //-- Computers --//


    //Computers - Menu functions.

    void computerMenu();
    void computerListMenu();
    void computerSearchMenu();
    void computerListAllMenu();
    void computerListAllTypeMenu();
    void computerListAllBuildYearMenu();
    void computerListAllDevelopmentMenu();
    //Computers - Print functions.
    void computerWhatToDoPrint();
    void printComputer(vector<Computer> temp);
    void computerMenuPrint();
    void computerSearchMenuPrint();
    void computerListMenuPrint();
    void computerListAllMenuPrint();
    void computerListAllTypeMenuPrint();
    void computerListAllYearBuiltMenuPrint();
    void computerListAllDevelopmentMenuPrint();
    void computerAskMenuPrint();

    //Computers and computer scientists --//
    void computerWorkedOn();
    //Computer scientist - Other functions.
    void computerNameColumn();
    void addComputer();
    void removeComputerFromDataBase();
    //--Computers and computer scientists --//
    void connectComputerColumn(int idNumber);
    void connectScientistColumn(int idNumber);
    string getComputerName(int idNumber);
    string getScientistName(int idNumber);

    void run();
    void openDataBase();
    void quitSystem();
    void otherMenu();

private:
    Service _service;

};

ostream& operator <<(ostream& os, Scientist& TempClass);
ostream& operator <<(ostream& os, Computer& TempClass);

#endif // CONSOLEUI_
