#include "consoleui.h"
#include "scientist.h"
#include "service.h"
#include <iomanip>

using namespace std;

//Sjálfgefinn Smiður.
ConsoleUI::ConsoleUI()
{

}

//-- Booting functions --//
//Booting - Print functions.
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
    else if(areYouSure == 'q' || areYouSure == 'Q')
    {
        quitSystem();
    }

}

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
    cout << " |     1. Computers.                                          2. Computer scientists.    | " << endl;
    cout << " |     3. Other functions                                                                | " << endl;
    cout << " | Press 'q' to quit the program.                                                        | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " > Please enter a number: ";
}
//Booting - Other functions.
void ConsoleUI::mainMenu()
{
    string command = " ";
    mainMenuPrint();
    getline(cin,command);

    if(command == "1")
    {
        computerMenu();
    }
    else if(command == "2")
    {
        scientistMenu();
    }
    else if(command == "3")
    {
        otherMenu();
    }
    else if(command == "q" || command == "Q")
    {
        quitSystem();
    }
    else if(command == "group 34")
    {
        cout << "  > Secret phase!!" << endl;
        cout << "  > I am Donald Trump" << endl << endl;
    }
    else if (command != "1" || command != "2")
    {
        cout << "  Invalid input!" << endl;
        mainMenu();
    }

}
void ConsoleUI::run()                           //----MAINFALL----
{
    beginingOfProgramPrint();
    mainMenu();
}

//-- Computer scientists --//
//Computer scientist - Menu functions.
void ConsoleUI::scientistWhatToDo()
{
    scientistWhatToDoPrint();

    char whatToDo;
    cin >> whatToDo;

    if(whatToDo == '1')
    {
        removeScientist();
    }
    else if(whatToDo == '2')
    {
        cout << "Eftir ad gera " << endl;
    }
    else if(whatToDo == 'b' || whatToDo == 'B')
    {
        mainMenu();
        //utfaera location breytu til ad vita hvert a ad fara.
    }
    else if(whatToDo == 'q' || whatToDo == 'Q')
    {
        quitSystem();
    }

    cout << "Invalid input! " << endl;
    scientistWhatToDo();
}
void ConsoleUI::scientistMenu()
{
    char command = ' ';

    scientistMenuPrint();

    while(command != 'q')
    {
        cin >> command;

        if(command == '1')
        {
            scientistListMenu();
        }
        else if(command == '2')
        {
            addScientist();

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
            scientistMenu();
        }
    }
}
void ConsoleUI::scientistListMenu()
{
    char list = ' ';
    scientistListMenuPrint();
    cin >> list;

    if(list == '1')     //All
    {
        scientistListAllMenu();
    }
    else if(list == '2')        //Specific name.
    {

        string searchString;

        do
        {
            cin.ignore();
            cout << "  > Please enter a name of a scientist: ";
            getline(cin, searchString);

            if(searchString == "q" || searchString == "Q")
            {
                quitSystem();
            }

        }
        while(!_service.inputNameValid(searchString));

        vector<Scientist> scientists = _service.searchForScientistsByName(searchString);

        scientistNameColumn();
        printScientist(scientists);
        cout << "  ======================================================================================= " << endl << endl;

        scientistListMenu();

    }
    else if(list == '3')      //specific year of birth.
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
            scientistListMenu();
        }

        scientistListMenu();
    }
    else if(list == '4')      //specific year of Death.
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
            scientistListMenu();
        }

        scientistListMenu();
    }
    else if(list == 'b' || list == 'B')   //Go back to main menu.
    {
        scientistMenu();
    }
    else if(list == 'q' || list == 'Q')
    {
        quitSystem();
    }

    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        scientistListMenu();
    }
}
void ConsoleUI::scientistListAllMenu()
{
    string input = " " ;
    scientistListAllMenuPrint();
    cin >> input;

    if(input == "1")           //A-Z
    {
        vector<Scientist> scientists = _service.getAllScientistsAtoZ();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl << endl;

        //scientistListAllMenu();
        scientistWhatToDo();
    }
    else if(input == "2")    //Z-A
    {
        vector<Scientist> scientists = _service.getAllScientistsZtoA();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl << endl;

        scientistListAllMenu();
    }
    else if(input == "3")
    {
        scientistListAllYearOfBirthMenu();
    }
    else if(input == "4")    //Gender
    {
        scientistListAllGenderMenu();
    }
    else if(input == "5")    //Dead or Alive.
    {
        scientistListAllDeadOrAliveMenu();
    }
    else if(input == "b" || input == "B")    //Go back
    {
        scientistListMenu();
    }
    else if(input == "q" || input == "Q")
    {
        quitSystem();
    }
    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        scientistListAllMenu();
    }
}
void ConsoleUI::scientistListAllGenderMenu()
{
    string gender;
    scientistListAllGenderMenuPrint();
    cin >> gender;

    if(gender == "b" || gender == "B")
    {
        scientistListAllMenu();
    }

    if (gender != "1" && gender != "2" && gender != "3")
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
        scientistListAllGenderMenu();
    }
    else
    {
        vector<Scientist> scientists = _service.getScientistsByGenderAtoZ(gender);
        scientistNameColumn();
        printScientist(scientists);

        for(unsigned int i = 0; i < scientists.size(); i++)
        {
            cout << scientists[i];
        }

        cout << "  ======================================================================================= " << endl;


        scientistListAllGenderMenu();
    }
}
void ConsoleUI::scientistListAllDeadOrAliveMenu()
{
    string aliveOrDeseaced;

    scientistListAllDeadOrAliveMenuPrint();
    cin >> aliveOrDeseaced;

    if(aliveOrDeseaced == "b" || aliveOrDeseaced == "B")
    {
        scientistListAllMenu();
    }
    else if(aliveOrDeseaced == "q" || aliveOrDeseaced == "Q")
    {
        quitSystem();
    }
    else if (aliveOrDeseaced != "1" && aliveOrDeseaced != "2" && aliveOrDeseaced != "3")
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

    scientistListAllDeadOrAliveMenu();
}
void ConsoleUI::scientistListAllYearOfBirthMenu()
{
    scientistListAllYearOfBirthMenuPrint();
    char yearOfBirth = ' ';
    cin >> yearOfBirth;

    if(yearOfBirth == '1')    //Year of birth
    {
        vector<Scientist> scientists = _service.getAllScientistsByYearOfBirthAsc();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl << endl;

        scientistListAllMenu();
    }
    else if(yearOfBirth == '2')    //Year of birth descending
    {

        vector<Scientist> scientists = _service.getAllScientistsByYearOfBirthDes();
        scientistNameColumn();
        printScientist(scientists);


        cout << "  ======================================================================================= " << endl << endl;


    }
    else if(yearOfBirth == 'b' || yearOfBirth == 'B')
    {
        scientistListAllMenu();
    }
    else if (yearOfBirth == 'q' || yearOfBirth == 'Q')
    {
        quitSystem();
    }
    else
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
        scientistListAllYearOfBirthMenu();
    }
    scientistListAllYearOfBirthMenu();
}

//Computer scientist - Print functions.
void ConsoleUI::scientistWhatToDoPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. Delete - Delete scientist.             2. Edit - Edit scientist.                   | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}

void ConsoleUI::scientistMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. List - List of scientists.             2. Add - Add scientist to list.             | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. All.                     2. Specific name.           3. Specific year of birth.    | " << endl;
    cout << " | 4. Specific year of death.                                                            | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllGenderMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. Only females.                     2. Only males.                3. All.            | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllDeadOrAliveMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. Only Alive.                      2. Only Deceased.             3. All.             | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. A-Z                 2. Z-A                          3. Year of birth               | " << endl;
    cout << " | 4. Gender              5. Alive/deceased                                              | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllYearOfBirthMenuPrint()
{
    cout << "  ======================================================================================== " << endl;
    cout << " |     1. Year of birth(A-Z).                                  2. Year of birth(Z-A).     |" << endl;
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
//Computer scientist - Other functions.
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

//Computer - Menu function
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
        /*
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
        */
        computerListMenu();

    }
    else if(list == '3')      //specific specific built year.
    {
        /*
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
        */
        cout << "  Her geturu leitad af hvenær TÖLVAN VAR BYGGÐ!" << endl;
        computerListMenu();
    }
    else if(list == '4')      //specific computer type
    {
        /*
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
        */

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
    char type = ' ';
    computerListAllTypeMenuPrint();
    cin >> type;


    if (type == '1') //All type A-Z
    {
        cout << "A-Z";
        /*
        vector<Computer> computers = _service.getAllTypeComputersAtoZ();
        computerNameColumn();
        printComputer(computers);

        cout << "  ======================================================================================= " << endl << endl;

        computerListAllTypeMenu();
        */
    }
    else if (type == '2') //2. Electronic
    {
        cout << "2. Electronic";
    }
    else if (type == '3')
    {
        cout << "3. Mechanical";
    }
    else if (type == '4')
    {
    cout << "4. Electronic/Mechanical";
    }
    else if (type == '5')
    {
    cout << "5. Transistor";
    }
    else if (type == '6')
    {
        cout << "6. Microcomputer";
    }
    else if (type == '7')
    {
    cout << "7. Ternary";
    }
    else if(type == 'b' || type == 'B')
    {
        computerListAllMenu();
    }
    else if (type == 'q' || type == 'Q')
    {
        quitSystem();
    }
        cout << "  Wrong input!" << endl;
        cout << endl;
        computerListAllTypeMenu();

}
void ConsoleUI::computerListAllBuildYearMenu()
{
    char yearBuilt = ' ';
    computerListAllYearBuiltMenuPrint();
    cin >> yearBuilt;

    if (yearBuilt == '1')
    {
        /*
        vector<Computer> computers = _service.getAllBuildYearComputersAtoZ();
        computerNameColumn();
        printScientist(computers);

        cout << "  ======================================================================================= " << endl << endl;

        computerListAllYearBuiltMenu();
        */
    }
    else if (yearBuilt == '2')
    {
        /*
        vector<Computer> computers = _service.getAllBuildYearComputersZtoA();
        computerNameColumn();
        printScientist(computers);

        cout << "  ======================================================================================= " << endl << endl;

        computerListAllYearBuiltMenu();
        */

    }
    if(yearBuilt == 'b' || yearBuilt == 'B')
    {
        computerListAllMenu();
    }
    else if (yearBuilt == 'q' || yearBuilt == 'Q')
    {
        quitSystem();
    }

        cout << "  Wrong input!" << endl;
        cout << endl;
        computerListAllBuildYearMenu();

}
void ConsoleUI::computerListAllDevelopmentMenu()
{
    char development = ' ';

    computerListAllDevelopmentMenuPrint();
    cin >> development;

    if (development == '1')
    {
        cout << "  Her kemur ORIGINAL listi!" << endl;
        // TODO!
    }
    else if (development == '2')
    {
        /*
        vector<Computer> computers = _service.getAllDevelopmentComputers();
        computerNameColumn();
        printScientist(computers);

        cout << "  ======================================================================================= " << endl << endl;

        computerListAllDevelopmentMenu();
        */
    }
    else if (development == '3')
    {
        cout << "  Her kemur listi af ORIGINAL og DEVELOPED." << endl;
    }
    else if(development == 'b' || development == 'B')
    {
        computerListAllMenu();
    }
    else if (development == 'q' || development == 'Q')
    {
        quitSystem();
    }
    else if (development != '1' && development != '2' && development!= '3')
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
        computerListAllDevelopmentMenu();
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
    cout << " |     1. Built year(A-Z).                                      2. Built year(Z-A).      |" << endl;
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


//Computer scientist - Other functions.
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
void ConsoleUI::quitSystem()
{
    cout << "Quitting program..." << endl;
    exit(1);
}

void ConsoleUI::otherMenu()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |     1. Edit relations of computer and scientist                                       | " << endl;
    cout << " |     2. Add a relation of a scientist to a computer                                    | " << endl;
    cout << " |     3. Add a relation of a computer to a scientist                                    | " << endl;
    cout << " |     4. Remove a relation between a computer and a scientist                           | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << "  > Please enter a number: ";
/*
    if(list == '1')
    {
        //TODO - - -1. Edit relations of computer and scientist
    }
    else if(list == '1')
    {
        //TODO - - -1. Edit relations of computer and scientist
    }
    else if(list == '1')
    {
        //TODO - - -1. Edit relations of computer and scientist
    }
    else if(list == '1')
    {
        //TODO - - -1. Edit relations of computer and scientist
    }


    else if(list == 'b' || list == 'B')
    {
        mainMenuPrint();
    }
    else if(list == 'q' || list == 'Q')
    {
        quitSystem();
    }
    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        otherMenu();
    }
    */
}
