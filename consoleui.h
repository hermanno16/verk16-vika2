#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "service.h"
#include <cstdlib>
#include <QString>
#include <QStringList>
#include <iostream>
#include <string>
#include <vector>


class ConsoleUI
{
public:
    ConsoleUI();

    //-- Booting functions --//
        //Booting - Print functions.
    void beginingOfProgramPrint();
    void mainMenuPrint();
        //Booting - Other functions.
    void mainMenu();

    //-- Computer scientists --//
        //Computer scientist - Menu functions.
    void scientistMenu();
    void scientistListMenu();
    void scientistListAllMenu();
    void scientistListAllGenderMenu();
    void scientistListAllDeadOrAliveMenu();
    void scientistListAllYearOfBirthMenu();
        //Computer scientist - Print functions.
    void scientistMenuPrint();
    void scientistListMenuPrint();
    void scientistListAllMenuPrint();
    void scientistListAllGenderMenuPrint();
    void scientistListAllDeadOrAliveMenuPrint();
    void scientistListAllYearOfBirthMenuPrint();
        //Computer scientist - Other functions.
    void scientistNameColumn();
    void addScientist();

    //-- Computers --//

        //--Computer - Menu functions.
    void computerMenu();
    void computerListMenu();
    void computerListAllMenu();
    void computerListAllTypeMenu();
    void computerListAllBuildYearMenu();
    void computerListAllDevelopmentMenu();
        //Computers - Print functions.
    void computerMenuPrint();
    void computerListMenuPrint();
    void computerListAllMenuPrint();
    void computerListAllTypeMenuPrint();
    void computerListAllBuiltYearMenuPrint();
    void computerListAllDevelopmentMenuPrint();
    void printComputers(vector<Computer> temp);

        //Computer scientist - Other functions.
    void computerNameColumn();
    void addComputer();

        //Computers and computer scientists --//
    void workedOn();
    void run();
    void openDataBase();
    void printScientist(vector<Scientist> temp);
    void quitSystem();

private:
    Service _service;

};

ostream& operator <<(ostream& os, Scientist& TempClass);
ostream& operator <<(ostream& os, Computer& TempClass);

#endif // CONSOLEUI_H
