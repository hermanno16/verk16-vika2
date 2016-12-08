#include "consoleui.h"
#include "scientist.h"
#include "service.h"
#include <iomanip>

using namespace std;

//--Sjálfgefinn Smiður--//
ConsoleUI::ConsoleUI()
{

}
//---------------------------------------------------------------------------------
bool ConsoleUI::goBackOrQuit(char command)
{
    if(command == 'b' || command == 'B')
    {
        return true;
    }

    else if(command == 'q' || command == 'Q')
    {
        cout << "Quitting program..." << endl;
        exit(1);
    }

    return false;
}
//---------------------------------------------------------------------------------
//-- Booting functions --//
    //Booting - Print functions.
void ConsoleUI::beginingOfProgramPrint()
{
    cout << endl << endl;
    cout << "   _________________________________________  " << endl;
    cout << "  |                                         | " << endl;
    cout << "  |                                         | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   ##  __  __  __        __   _      ##  | " << endl;
    cout << "  |   ## | _ |__||  | |  | |__|  _| |_| ##  | " << endl;
    cout << "  |   ## |__|| \\ |__| |__| |     _|   | ##  |" << endl;
    cout << "  |   ##                                ##  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   #### --- Computer Scientists--- ####  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   ###########  Vika 2.0  #############  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |                                     o   | " << endl;
    cout << "  |_________________________________________| " << endl;
    cout << "                  |          |                " << endl;
    cout << "                  |          |                " << endl;
    cout << "    ______________|__________|_____________   " << endl;
    cout << "   |                                       |  " << endl;
    cout << "   |  =======                       7 8 9  |  " << endl;
    cout << "   |        o                       4 5 6  |  " << endl;
    cout << "   |                                1 2 3  |  " << endl;
    cout << "   |_______________________________________|\n" << endl;
}
void ConsoleUI::mainMenuPrint()
{
    cout << "  =======================================================================================  " << endl;
    cout << " |                                     MAIN MENU                                         | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |     1. Computers.                                       2. Computer scientists.       | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program.                                                        | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " > Please enter a number: ";
}
    //Booting - Other functions.
void ConsoleUI::mainMenu()
{
    char mainCommand = ' ';
    mainMenuPrint();
    cin >> mainCommand;

    if(mainCommand == '1')
    {
        //computerMenu();
    }
    else if(mainCommand == '2')
    {
        scientistMenu();
    }
    else if(goBackOrQuit(mainCommand))
    {
        mainMenu();
    }

    cout << "  Invalid input!" << endl;
    mainMenu();
}
void ConsoleUI::run()
{
    beginingOfProgramPrint();
    mainMenu();
}


//-- Computer scientists --//
    //Computer scientists - Menu functions.
void ConsoleUI::scientistMenu()
{
    char command = ' ';

    scientistMenuPrint();
    cin >> command;

    if(command == '1')
    {
        scientistListMenu();
    }
    else if(command == '2')
    {
        scientistSearchMenu();

    }
    else if(goBackOrQuit(command))
    {
        mainMenu();
    }

    cout << "  > Invalid input!" << endl;
    scientistMenu();
}
void ConsoleUI::scientistSearchMenu()
{
    char wantToModify = ' ';
    char commandSearch = ' ';
    scientistSearchMenuPrint();
    cin >> commandSearch;

    if(commandSearch == '1')        //Specific name.
    {
        string searchString;

        do
        {
            cin.ignore();
            cout << "  > Please enter a name of a scientist: ";
            getline(cin, searchString);

            if(searchString == "q" || searchString == "Q")
            {
                cout << "Quitting program..." << endl;
                exit(1);
            }
        }
        while(!_service.inputNameValid(searchString));

        vector<Scientist> scientists = _service.searchForScientistsByName(searchString);

        scientistNameColumn();
        printScientist(scientists);
        cout << "  ======================================================================================= " << endl;

        cout << " > Want to modify the list(Y/N)? ";
        cin >> wantToModify;

        if(wantToModify == 'Y' || wantToModify == 'y')
        {
            char command = ' ';
            scientistWhatToDoPrint();
            if(command == '1')
            {
                addScientist();
            }
            else if(command == '2')
            {
                removeScientist();
            }
            else if(goBackOrQuit(command))
            {
                scientistSearchMenu();
            }
        }

        scientistSearchMenu();
    }
    else if(commandSearch == '2')      //specific year of birth.
    {
        string yearToFind;
        cout << "  > Please enter the year in question: ";
        cin >> yearToFind;

        vector<Scientist> scientists = _service.searchForScientistsByYearOfBirthAtoZ(yearToFind);

        if(scientists.size() == 0)
        {
            cout << "  > Year not found!" << endl;
        }
        else
        {
            scientistNameColumn();
            printScientist(scientists);
            cout << "  ======================================================================================= " << endl << endl;
            scientistSearchMenu();
        }

        cout << " > Want to modify the list(Y/N)? ";
        cin >> wantToModify;

        if(wantToModify == 'Y' || wantToModify == 'y')
        {
            char command = ' ';
            scientistWhatToDoPrint();
            cin >> command;
            if(command == '1')
            {
                addScientist();
            }
            else if(command == '2')
            {
                removeScientist();
            }
            else if(goBackOrQuit(command))
            {
                scientistSearchMenu();
            }
        }
        scientistSearchMenu();
    }
    else if(commandSearch == '3')      //specific year of Death.
    {
        string yearToFind;
        cout << "  > Please enter the year in question: ";
        cin >> yearToFind;

        vector<Scientist> scientists = _service.searchForScientistsByYearOfDeathAtoZ(yearToFind);

        if(scientists.size() == 0)
        {
            cout << "  > Year not found!" << endl;
        }
        else
        {
            scientistNameColumn();
            printScientist(scientists);
            cout << "  ======================================================================================= " << endl << endl;
            scientistSearchMenu();
        }

        cout << " > Want to modify the list(Y/N)? ";
        cin >> wantToModify;

        if(wantToModify == 'Y' || wantToModify == 'y')
        {
            char command = ' ';
            scientistWhatToDoPrint();
            cin >> command;
            if(command == '1')
            {
                addScientist();
            }
            else if(command == '2')
            {
                removeScientist();
            }
            else if(goBackOrQuit(command))
            {
                scientistSearchMenu();
            }
        }

        scientistSearchMenu();
    }
    else if(goBackOrQuit(commandSearch))
    {
        scientistMenu();
    }

    cout << "  > Invalid input!" << endl;
    cout << endl;
    scientistSearchMenu();
}
void ConsoleUI::scientistListMenu()
{
    char listCommand = ' ';
    char wantToModify = ' ';

    scientistListMenuPrint();
    cin >> listCommand;

    if(listCommand == '1')           //A-Z
    {
        vector<Scientist> scientists = _service.getAllScientistsAtoZ();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl;
        cout << " > Want to modify the list(Y/N)? ";
        cin >> wantToModify;

        if(wantToModify == 'Y' || wantToModify == 'y')
        {
            char command = ' ';
            scientistWhatToDoPrint();
            cin >> command;
            if(command == '1')
            {
                addScientist();
            }
            else if(command == '2')
            {
                removeScientist();
            }
            else if(goBackOrQuit(command))
            {
                scientistListMenu();
            }
        }

        scientistListMenu();
    }

    else if(listCommand == '2')    //Z-A
    {
        vector<Scientist> scientists = _service.getAllScientistsZtoA();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl;
        cout << " > Want to modify the list(Y/N)? ";
        cin >> wantToModify;

        if(wantToModify == 'Y' || wantToModify == 'y')
        {
            char command = ' ';
            scientistWhatToDoPrint();
            cin >> command;
            if(command == '1')
            {
                addScientist();
            }
            else if(command == '2')
            {
                removeScientist();
            }
            else if(goBackOrQuit(command))
            {
                scientistListMenu();
            }
        }
        scientistListMenu();
    }

    else if(listCommand == '3')    //Gender
    {
        scientistListAllGenderMenu();
    }

    else if(listCommand == '4') //Year Of birth.
    {
        scientistListAllYearOfBirthMenu();
    }

    else if(listCommand == '5')    //Dead or Alive.
    {
        scientistListAllDeadOrAliveMenu();
    }

    else if(goBackOrQuit(listCommand))
    {
        scientistMenu();
    }

    cout << "  > Invalid input!" << endl;
    scientistListMenu();

}
void ConsoleUI::scientistListAllGenderMenu()
{
    char wantToModify = ' ';
    char genderCommand = ' ';
    scientistListAllGenderMenuPrint();
    cin >> genderCommand;

    if(genderCommand == 'b' || genderCommand == 'b')
    {
        scientistListMenu();
    }

    else if(genderCommand != '1' && genderCommand != '2' && genderCommand != '3')
    {
        cout << "  > Invalid input!" << endl;
        cout << endl;
        scientistListAllGenderMenu();
    }


    vector<Scientist> scientists = _service.getScientistsByGenderAtoZ(genderCommand);
    scientistNameColumn();
    printScientist(scientists);

    cout << "  ======================================================================================= " << endl;

    cout << " > Want to modify the list(Y/N)? ";
    cin >> wantToModify;

    if(wantToModify == 'Y' || wantToModify == 'y')
    {
        char command = ' ';
        scientistWhatToDoPrint();
        cin >> command;
        if(command == '1')
        {
            addScientist();
        }
        else if(command == '2')
        {
            removeScientist();
        }
        else if(goBackOrQuit(command))
        {
            scientistListMenu();
        }
    }


    scientistListAllGenderMenu();

}
void ConsoleUI::scientistListAllDeadOrAliveMenu()
{
    char wantToModify = ' ';
    char aliveOrDeseaced = ' ';

    scientistListAllDeadOrAliveMenuPrint();
    cin >> aliveOrDeseaced;

    if(goBackOrQuit(aliveOrDeseaced))
    {
        scientistListMenu();
    }
    else if (aliveOrDeseaced != '1' && aliveOrDeseaced != '2' && aliveOrDeseaced != '3')
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
        scientistListAllDeadOrAliveMenu();
    }
    vector<Scientist> scientists = _service.getAllDeadOrAliveScientistsAtoZ(aliveOrDeseaced);
    scientistNameColumn();
    printScientist(scientists);

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        cout << scientists[i];
    }

    cout << "  ======================================================================================= " << endl << endl;
    cout << " > Want to modify the list(Y/N)? ";
    cin >> wantToModify;

    if(wantToModify == 'Y' || wantToModify == 'y')
    {
        char command = ' ';
        scientistWhatToDoPrint();
        cin >> command;
        if(command == '1')
        {
            addScientist();
        }
        else if(command == '2')
        {
            removeScientist();
        }
        else if(goBackOrQuit(command))
        {
            scientistListMenu();
        }
    }

    scientistListAllDeadOrAliveMenu();
}
void ConsoleUI::scientistListAllYearOfBirthMenu()
{
    scientistListAllYearOfBirthMenuPrint();
    char wantToModify = ' ';
    char yearOfBirth = ' ';
    cin >> yearOfBirth;

    if(yearOfBirth == '1')    //Year of birth
    {
        vector<Scientist> scientists = _service.getAllScientistsByYearOfBirthAsc();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl;
        cout << " > Want to modify the list(Y/N)? ";
        cin >> wantToModify;

        if(wantToModify == 'Y' || wantToModify == 'y')
        {
            char command = ' ';
            scientistWhatToDoPrint();
            cin >> command;
            if(command == '1')
            {
                addScientist();
            }
            else if(command == '2')
            {
                removeScientist();
            }
            else if(goBackOrQuit(command))
            {
                scientistListMenu();
            }
        }


        scientistListMenu();
    }
    else if(yearOfBirth == '2')    //Year of birth descending
    {

        vector<Scientist> scientists = _service.getAllScientistsByYearOfBirthDes();
        scientistNameColumn();
        printScientist(scientists);


        cout << "  ======================================================================================= " << endl;
        cout << " > Want to modify the list(Y/N)? ";
        cin >> wantToModify;

        if(wantToModify == 'Y' || wantToModify == 'y')
        {
            char command = ' ';
            scientistWhatToDoPrint();
            cin >> command;
            if(command == '1')
            {
                addScientist();
            }
            else if(command == '2')
            {
                removeScientist();
            }
            else if(goBackOrQuit(command))
            {
                scientistListMenu();
            }
        }
    }
        cout << "  > Invalid input!" << endl;
        cout << endl;
        scientistListAllYearOfBirthMenu();
}
     //Computer scientists - Print functions.
void ConsoleUI::scientistWhatToDoPrint()
{
    cout << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |                                     MODIFY MENU                                       | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " | 1 - Add scientist.                                         2 - Delete scientist.      | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistMenuPrint()
{
    cout << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |                                   SCIENTIST MENU                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " | 1 - List all scientists.                            2 - Search for scientists         | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListMenuPrint()
{
    cout << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |                                 SCIENTIST LIST MENU                                   | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " | 1 - A to Z.                       2 - Z to A.                          3 - Gender.    | " << endl;
    cout << " | 4 - Year of birth.                5. Alive/deceased                                   | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistSearchMenuPrint()
{   cout << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |                                  SCIENTIST SEARCH MENU                                | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " | 1 - Specific name.                                    2 -  Specific year of birth.    | " << endl;
    cout << " | 3 - Specific year of death.                                                           | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllGenderMenuPrint()
{
    cout << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |                                SCIENTIST LIST GENDER MENU                             | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " | 1 - Only females.                     2 - Only males.                3 - All.         | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllDeadOrAliveMenuPrint()
{
    cout << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |                            SCIENTIST LIST DECEASED/ALIVE MENU                         | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " | 1 - Only Alive.                      2 - Only Deceased.             3 - All.          | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllYearOfBirthMenuPrint()
{
    cout << endl;
    cout << "  ======================================================================================== " << endl;
    cout << " |                             SCIENTIST LIST YEAR OF BIRTH MENU                          | " << endl;
    cout << "  ======================================================================================== " << endl;
    cout << " |     1 - Year of birth(A-Z).                                  2 - Year of birth(Z-A).   |" << endl;
    cout << " |                                                                                        |" << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                       |" << endl;
    cout << "  ======================================================================================== " << endl;
    cout << " > Please enter a number: ";
}
void ConsoleUI::printScientist(vector<Scientist> temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }
    int print = temp.size();
    cout << "  =======================================================================================" << endl;
    cout << " | ";
    cout << setfill(' ') << setw(50);
    cout << right << "Number of results return: ";
    cout << setw(36);
    cout << left << print;
    cout << setw(1) << "|" << endl;
}
    //Computer scientists - Other functions.
void ConsoleUI::removeScientist()
{
    int idOfScientist;
    char areYouSure;
    scientistWhatToDoPrint();

    cout << "  > Enter id of scientist to remove from the list: ";
    cin >> idOfScientist;

    cout << "  > Are you sure you want to remove scientist with id " << idOfScientist << "(Y/N)? " ;
    cin >> areYouSure;

    if(areYouSure == 'y' || areYouSure == 'Y')
    {
        _service.removeScientist(idOfScientist);
        mainMenu();
    }
    else if(areYouSure == 'b' || areYouSure == 'B')
    {
        mainMenu();
        //utfaera location breytu til ad vita hvert a ad fara.
    }

    else if(goBackOrQuit(areYouSure))
    {
        scientistListMenu();
    }

}
void ConsoleUI::addScientist()
{
    string name, gender, yearOfBirth, yearOfDeath;

    cin.ignore();                                                                                    //NAME
    cout << endl;
    cout << "  =======================================================================================" << endl;
    cout << "  > Input name of scientist: ";
    getline(cin, name);

    cout << "  > Input gender (male/female): ";
    getline(cin, gender);

    cout << "  > Input year of birth: ";
    getline(cin, yearOfBirth);

    cout << "  > Input year of death if applicable, if not please enter N/A): ";
    getline(cin, yearOfDeath);


    if(_service.isAddScientistValid(name, gender, yearOfBirth, yearOfDeath))
    {
        _service.addScientistToData(name, gender, yearOfBirth, yearOfDeath);

        scientistMenu();
    }

    {
        cout << "  > Invalid input!" << endl;

        scientistMenu();
    }
}
void ConsoleUI::scientistNameColumn()
{
    cout << "  ======================================================================================= " << endl;
    cout.width(4);
    cout << left << " | ID:";
    cout.width(34);
    cout << left << "  Name:";
    cout.width(15);
    cout << left << "Gender:";
    cout.width(17);
    cout << left << "Birth year:";
    cout.width(17);
    cout << left << "Year of Death:";
    cout << "|" << endl;
    cout << "  ======================================================================================= " << endl;
}
//---------------------------------------------------------------------------------

//-- Computers--//
    //Computers - Menu function
/*
void ConsoleUI::computerMenu()
{
    char command = ' ';

    computerMenuPrint();

    while(command != 'q')
    {
        cin >> command;

        if(command == '1')
        {
            computerListMenu();
        }
        else if (command =='2')
        {
            addComputer();
        }
        else if (command =='3')
        {
            workedOn();
        }

        else if(command == 'q' || command == 'Q')
        {
            quitSystem();
        }
        else if(command == 'b' || command == 'B')
        {
            mainMenu();
        }
        else
        {
            cout << "  Invalid input!" << endl;
            computerMenu();
        }
    }

}
void ConsoleUI::computerListMenu()
{
    char list = ' ';
    computerListMenuPrint();
    cin >> list;

    if(list == '1')     //All
    {
        computerListAllMenu();
    }
    else if(list == '2')        //Specific computer name.
    {

        //senda int list og streng með nafninu. Fá allt stakið úr vektornum ef match finnst.
        //string searchString;

        cout << "  (Electornic, mechanical, micro-computer, tenary or transistor). ";
        cout << "  Her geturu leitad af T0LVU!" << endl;
        do
        {
            cout << "  Please enter a name of a scientist: ";
            cin >> searchString;
            if(searchString == "q" || searchString == "Q")
            {
                quitSystem();
            }


        }
        while(!_service.inputNameValid(searchString));

        vector<Scientist> scientists = _service.searchForScientistsByName(searchString);
        //printScientists(scientists);

        for(unsigned int i = 0; i < scientists.size(); i++)
        {
            cout << scientists[i];
        }

        cout << "  ======================================================================================= " << endl << endl;

        computerListMenu();

    }
    else if(list == '3')      //specific specific built year.
    {

        string year;

        cout << "  Please enter the year in question: ";

        cin >> year;
        vector<Scientist> result;



        result = _service.searchOfSciencetistsByYearOfBirth(year);

        if(result.size() == 0)
        {
            cout << "  Year not found!" << endl;
        }
        else
        {
            scientistNameColumn();

            void printScientists(vector<Scientist> scientists);

            scientistListMenu();
        }

        cout << "  Her geturu leitad af hvenær TÖLVAN VAR BYGGÐ!" << endl;
        computerListMenu();
    }
    else if(list == '4')      //specific computer type
    {

        string year;
        cout << "  Please enter year to look for: ";
        cin >> year;
        vector<Scientist> result;

        result = _service.searchOfSciencetistsByYearOfDeath(year);

        if(result.size() == 0)
        {
            cout << "  Year not found!" << endl;
        }
        else
        {
            scientistNameColumn();

            void printScientists(vector<Scientist> scientists);
        }


        cout << "Her geturu leitad af TYPU AF TOLVU!" << endl;
        computerListMenu();
    }
    else if(list == 'b' || list == 'B')   //Go back to main menu.
    {
        computerMenu();
    }

    else if(list == 'q' || list == 'Q')
    {
        quitSystem();
    }

    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        computerListMenu();
    }
}
void ConsoleUI::computerListAllMenu()
{
    char input = ' ';
    computerListAllMenuPrint();
    cin >> input;


    if(input == '1') //A-Z
    {

        vector<Computer> computers = _service.getAllComputersAtoZ();
        computerNameColumn();
        printComputer(computers);

        cout << "  ======================================================================================= " << endl << endl;

        computerListAllMenu();


    }
    if(input == '2')    //Z-A
    {

        vector<Computer> computers = _service.getAllComputersZtoA();
        computerNameColumn();
        printComputer(computers);

        cout << "  ======================================================================================= " << endl << endl;

        computerListAllMenu();


    }
    else if(input == '3')    //Type
    {
        computerListAllTypeMenu();
    }
    else if(input == '4')    //Built year
    {
        computerListAllBuildYearMenu();
    }
    else if(input == '5')    //Original Or Developed
    {
        computerListAllDevelopmentMenu();
    }
    else if(input == 'b' || input == 'B')    //Go back
    {
        computerListMenu();
    }

    else if (input == 'q' || input == 'Q')
    {
        quitSystem();
    }

    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        computerListAllMenu();
    }
}
void ConsoleUI::computerListAllTypeMenu()
{
    string type = " ";
    computerListAllTypeMenuPrint();
    cin >> type;


    if(type == "b" || type == "B")
    {
        computerListAllMenu();
    }

    else if (type == "q" || type == "Q")
    {
        quitSystem();
    }

    else if (type == "b" || type == "B" || type == "q" || type == "Q")
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
    }
    else
    {
        vector<Computer> computerType = _service.getAllTypesComputersAtoZ(type);
        computerNameColumn();
        for(unsigned int i = 0; i < computerType.size(); i++)
        {
            cout << computerType[i];
        }
        cout << "  ======================================================================================= " << endl;

        computerListAllTypeMenu();
    }
        computerListAllTypeMenu();
}
void ConsoleUI::computerListAllBuildYearMenu()
{
    string yearBuilt = " ";
    computerListAllYearBuiltMenuPrint();
    cin >> yearBuilt;

    if(yearBuilt == "b" || yearBuilt == "B")
    {
        computerListAllMenu();
    }

    else if (yearBuilt == "q" || yearBuilt == "Q")
    {
        quitSystem();
    }

    else if(yearBuilt == "q" || yearBuilt == "Q" || yearBuilt == "b" || yearBuilt == "B" )
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
        computerListAllBuildYearMenu();
    }
    else
    {
        vector<Computer> computerBuilt = _service.getAllBuildYearComputers(yearBuilt);
        computerNameColumn();
        for(unsigned int i = 0; i < computerBuilt.size(); i++)
        {
            cout << computerBuilt[i];
        }
    }
     computerListAllBuildYearMenu();
}
void ConsoleUI::computerListAllDevelopmentMenu()
{
    string development = " ";

    computerListAllDevelopmentMenuPrint();
    cin >> development;

    if(development == "b" || development == "B")
    {
        computerListAllMenu();
    }

    else if (development == "q" || development == "Q")
    {
        quitSystem();
    }

    else if (development == "b" || development == "B" || development == "q" || development == "Q")
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
        computerListAllDevelopmentMenu();
    }
    else
    {
        vector<Computer> computerDevelopment = _service.getAllDevelopmentAndOriginalComputers(development);
        computerNameColumn();
        for(unsigned int i = 0; i < computerDevelopment.size(); i++)
        {
            cout << computerDevelopment[i];
        }
    }

    computerListAllDevelopmentMenu();
}
    //Computers - Print functions.
void ConsoleUI::printComputer(vector<Computer> temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }
    int print = temp.size();
    cout << "  =======================================================================================" << endl;
    cout << " | ";
    cout << setfill(' ') << setw(50);
    cout << right << "Number of results return: ";
    cout << setw(36);
    cout << left << print;
    cout << setw(1) << "|" << endl;
}
void ConsoleUI::computerMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |     1. List - List of computers.                            2. Add - Add computer.    | " << endl;
    cout << " |     3. Developer - Enter the ID of a Computer for a list of developers                | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::computerListMenuPrint()
{
    cout << "  =======================================================================================  " << endl;
    cout << " |     1. All.                     2. Specific computer.       3. Specific build year.   | " << endl;
    cout << " |     4. Specific type                                                                  | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << "  > Please enter a number: ";

}
void ConsoleUI::computerListAllMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |     1. A-Z.                    2. Z-A.                       3. Type.                 | " << endl;
    cout << " |     4. Built Year.             5. Original/Developed.                                 | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " > Please enter a number: ";
}
void ConsoleUI::computerListAllTypeMenuPrint()
{
    cout << "  =======================================================================================  " << endl;
    cout << " |     1. Type(A-Z)                  2. Electronic              3. Mechanical            | " << endl;
    cout << " |     4. Electronic/Mechanical      5. Transistor              6. Microcomputer         | " << endl;
    cout << " |     7. Ternary                                                                        | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " > Please enter a number: ";
}
void ConsoleUI::computerListAllYearBuiltMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |     1. Built year(oldest to newest).             2. Built year(newest to oldest).     |" << endl;
    cout << " |                                                                                       |" << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      |" << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " > Please enter a number: ";
}
void ConsoleUI::computerListAllDevelopmentMenuPrint()
{
    cout << "  ===================================================================================== " << endl;
    cout << " |     1. Only Original.          2. Only Developed.            3. All.                  | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " > Please enter a number: ";
}
    //Computers - Other functions.
void ConsoleUI::addComputer()
{

}
void ConsoleUI::workedOn()
{
    int idNumber;
    cout << "  > Please enter the ID of the Computer: ";
    cin >> idNumber;
    //vector<Scientist> scientists = _service.connectComputerToScientist(idNumber);
    scientistNameColumn();
    //printScientist(scientists);
}
void ConsoleUI::computerNameColumn()
{
    cout << "  ======================================================================================= " << endl;
    cout.width(8);
    cout << left << " | ID:";
    cout.width(26);
    cout << "Name:";
    cout.width(23);
    cout << left << "Type:";
    cout.width(15);
    cout << left << "Built year:";
    cout.width(17);
    cout << left << "Development:";
    cout << "|" << endl;
    cout << "  ======================================================================================= " << endl;
}

*/

