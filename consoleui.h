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
    ConsoleUI();

    //-- Booting functions --//
        //Booting - Print functions.
    void beginingOfProgramPrint();
    void mainMenuPrint();
        //Booting - Other functions.
    void mainMenu();
    bool goBackOrQuit(char command);

    //-- Computer scientists --//
        //Computer scientist - Menu functions.
    void scientistWhatToDo();
    void scientistMenu();
    void scientistSearchMenu();
    void scientistListMenu();
    void scientistListAllMenu();
    void scientistListAllGenderMenu();
    void scientistListAllDeadOrAliveMenu();
    void scientistListAllYearOfBirthMenu();
        //Computer scientist - Print functions.
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
        //Computer scientist - Other functions.
    void scientistNameColumn();
    void addScientist();
    void removeScientist();

    //-- Computers --//

        //--Computer - Menu functions.
    void computerMenu();
    void computerListMenu();
    void computerListAllMenu();
    void computerListAllTypeMenu();
    void computerListAllBuildYearMenu();
    void computerListAllDevelopmentMenu();
        //Computers - Print functions.
    void printComputer(vector<Computer> temp);
    void computerMenuPrint();
    void computerListMenuPrint();
    void computerListAllMenuPrint();
    void computerListAllTypeMenuPrint();
    void computerListAllYearBuiltMenuPrint();
    void computerListAllDevelopmentMenuPrint();


        //Computer scientist - Other functions.
    void computerNameColumn();
    void addComputer();

        //Computers and computer scientists --//
    void workedOn();
    void run();
    void openDataBase();

    void quitSystem();

    void otherMenu();

private:
    Service _service;

};

ostream& operator <<(ostream& os, Scientist& TempClass);
ostream& operator <<(ostream& os, Computer& TempClass);

#endif // CONSOLEUI_H
