#include "consoleui.h"
#include "scientist.h"
#include "service.h"
#include <iomanip>

using namespace std;
const int MAXSIZEOFNAME = 80;


//--Constructor--//
ConsoleUI::ConsoleUI()
{

}
/*
 * This function is used to go back or quit the program,
 * we take in a command and navigate based on what the input was.
 * */
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
//-- Booting functions --//
//Booting - Print functions.
/*
 * This function is used to print out just in the begining of the program.
 * */
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
/*
 * This function is used to print out the main menu.
 * */
void ConsoleUI::mainMenuPrint()
{
    cout << "  =======================================================================================  " << endl;
    cout << " |                                     MAIN MENU                                         | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |     1. Computers.                                       2. Computer scientists.       | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program.                                                        | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << "  > Please enter a number: ";
}
//Booting - Other functions.
/*
 * This function is used to show the menu, we take in a command and navigate based on what the input was.
 * */
void ConsoleUI::mainMenu()
{
    char mainCommand = ' ';
    mainMenuPrint();
    cin >> mainCommand;

    if(mainCommand == '1')
    {
        computerMenu();
    }
    else if(mainCommand == '2')
    {
        scientistMenu();
    }
    else if(goBackOrQuit(mainCommand))
    {
        mainMenu();
    }
    else
    {
        cout << "  Invalid input!" << endl;
        mainMenu();

    }
}
/*
 * This function run the program.
 * */
void ConsoleUI::run()
{
    beginingOfProgramPrint();
    mainMenu();
}
//-- Computer scientists --//
/*
 * This function is used to show the menu, we take in a command and navigate based on what the input was.
 * */
//Computer scientists - Menu functions.
/*
 * This function is used to show the Scientist menu, we take in a command and navigate based on what the
 * input was.
 * */
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
    else
    {
        cout << "  > Invalid input!" << endl;
        scientistMenu();

    }
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

        scientistWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addScientist();
        }
        else if(wantToModify == '2')
        {
            removeScientistFromDataBase();
        }
        else if(wantToModify == '3')
        {
            scientistWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
        }
        else if(wantToModify == '5')
        {
            scientistSearchMenu();
        }
        //Returns true if user wants to go back!
        else if(goBackOrQuit(wantToModify))
        {
            scientistSearchMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            scientistSearchMenu();
        }


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
            scientistSearchMenu();
        }
        else
        {
            scientistNameColumn();
            printScientist(scientists);
        }

        scientistWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addScientist();
        }
        else if(wantToModify == '2')
        {
            removeScientistFromDataBase();
        }
        else if(wantToModify == '3')
        {
            scientistWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
        }
        else if(wantToModify == '5')
        {
            scientistSearchMenu();
        }
        //Returns true if user wants to go back!
        else if(goBackOrQuit(wantToModify))
        {
            scientistSearchMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            scientistSearchMenu();
        }

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
            scientistSearchMenu();
        }
        else
        {
            scientistNameColumn();
            printScientist(scientists);

        }

        scientistWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addScientist();
        }
        else if(wantToModify == '2')
        {
            removeScientistFromDataBase();
        }
        else if(wantToModify == '3')
        {
            scientistWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
        }
        else if(wantToModify == '5')
        {
            scientistSearchMenu();
        }
        //Returns true if user wants to go back!
        else if(goBackOrQuit(wantToModify))
        {
            scientistSearchMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            scientistSearchMenu();
        }
    }
    else if(goBackOrQuit(commandSearch))
    {
        scientistMenu();
    }
    else
    {

        cout << "  > Invalid input!" << endl;
        cout << endl;
        scientistSearchMenu();
    }
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

        scientistWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addScientist();
        }
        else if(wantToModify == '2')
        {
            removeScientistFromDataBase();
        }
        else if(wantToModify == '3')
        {
            scientistWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
        }
        else if(wantToModify == '5')
        {
            scientistListMenu();
        }
        //Returns true if user wants to go back!
        else if(goBackOrQuit(wantToModify))
        {
            scientistListMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            scientistListMenu();
        }
    }

    else if(listCommand == '2')    //Z-A
    {
        vector<Scientist> scientists = _service.getAllScientistsZtoA();
        scientistNameColumn();

        printScientist(scientists);

        scientistWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addScientist();
        }
        else if(wantToModify == '2')
        {
            removeScientistFromDataBase();
        }
        else if(wantToModify == '3')
        {
            scientistWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
        }
        else if(wantToModify == '5')
        {
            scientistListMenu();
        }
        //Returns true if user wants to go back!
        else if(goBackOrQuit(wantToModify))
        {
            scientistListMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            scientistListMenu();
        }
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
    else
    {
        cout << "  > Invalid input!" << endl;
        scientistListMenu();
    }
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

    scientistWhatToDoPrint();
    cin >> wantToModify;

    if(wantToModify == '1')
    {
        addScientist();
    }
    else if(wantToModify == '2')
    {
        removeScientistFromDataBase();
    }
    else if(wantToModify == '3')
    {
        scientistWorkedOn();
    }
    else if(wantToModify == '4')
    {
        cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
    }
    else if(wantToModify == '5')
    {
        scientistListAllGenderMenu();
    }
    //Returns true if user wants to go back!
    else if(goBackOrQuit(wantToModify))
    {
        scientistListAllGenderMenu();
    }
    else
    {
        cout << "  > Invalid input!" << endl;
        scientistListAllGenderMenu();
    }
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

    scientistWhatToDoPrint();
    cin >> wantToModify;

    if(wantToModify == '1')
    {
        addScientist();
    }
    else if(wantToModify == '2')
    {
        removeScientistFromDataBase();
    }
    else if(wantToModify == '3')
    {
        scientistWorkedOn();
    }
    else if(wantToModify == '4')
    {
        cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
    }
    else if(wantToModify == '5')
    {
        scientistListAllDeadOrAliveMenu();
    }
    //Returns true if user wants to go back!
    else if(goBackOrQuit(wantToModify))
    {
        scientistListAllDeadOrAliveMenu();
    }
    else
    {
        cout << "  > Invalid input!" << endl;
        scientistListAllDeadOrAliveMenu();
    }

}
/*
 * This function is used to prin
 * */
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

        scientistWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addScientist();
        }
        else if(wantToModify == '2')
        {
            removeScientistFromDataBase();
        }
        else if(wantToModify == '3')
        {
            scientistWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
        }
        else if(wantToModify == '5')
        {
            scientistListAllYearOfBirthMenu();
        }
        //Returns true if user wants to go back!
        else if(goBackOrQuit(wantToModify))
        {
            scientistListAllYearOfBirthMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            scientistListAllYearOfBirthMenu();
        }


    }
    else if(yearOfBirth == '2')    //Year of birth descending
    {

        vector<Scientist> scientists = _service.getAllScientistsByYearOfBirthDes();
        scientistNameColumn();
        printScientist(scientists);

        scientistWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addScientist();
        }
        else if(wantToModify == '2')
        {
            removeScientistFromDataBase();
        }
        else if(wantToModify == '3')
        {
            scientistWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGITENGI EFTIR AD UTFAERA!!" << endl;
        }
        else if(wantToModify == '5')
        {
            scientistListAllYearOfBirthMenu();
        }
        //Returns true if user wants to go back!
        else if(goBackOrQuit(wantToModify))
        {
            scientistListAllYearOfBirthMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            scientistListAllYearOfBirthMenu();
        }
    }
    else if (goBackOrQuit(yearOfBirth))
    {
        scientistListMenu();
    }
    else
    {
        cout << "  > Invalid input!" << endl;
        scientistListAllYearOfBirthMenu();
    }

}
//Computer scientists - Print functions.
/*
 * This function is used to print out modify menu, the user can add, edit and delete scientis from the database
 * after he/her see the list they asked for.
 * */
void ConsoleUI::scientistWhatToDoPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |                                      OPTIONS                                          | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " | 1 - Add scientist.                                         2 - Delete scientist.      | " << endl;
    cout << " | 3 - More info about the scientist.                         4 - Add relation.          | " << endl;
    cout << " | 5 - Continue.                                                                         | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
/*
 * This function is used to print out the scientist menu.
 * */
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
/*
 * This function is used to print out the scientist list menu.
 * */
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
/*
 * This function is used to print out the scientist serch menu.
 * */
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
/*
 * This function is used to print out the scientist gender list menu.
 * */
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
/*
 * This function is used to print out the menu for scientist to check if she/he is alive, deceased or both.
 * */
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
/*
 * This function is used to print out the menu for scientist to check his/her birth year, asc or desc.
 * */
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
/*
 * This function is used to print out a vector of class computers and then it prints out
 * how many are in the list.
 * */
void ConsoleUI::printScientist(vector<Scientist> temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }

    cout << " |                                       - - -                                           | " << endl;
    size_t print = temp.size();

    cout << " | ";
    cout << setfill(' ') << setw(50);
    cout << right << "Number of results returned: ";
    cout << setw(36);
    cout << left << print;
    cout << setw(1) << "|" << endl;
    cout << " |                                                                                       | " << endl;
}
//Computer scientists - Other functions.
/*
 * This function is used to remove Sceintist from database, we take in a command and call remove function from
 * service layer and remove the scientist from the database.
 * */
void ConsoleUI::removeScientistFromDataBase()
{

    int idOfScientist;
    char areYouSure;


    cout << "  > Enter id of scientist to remove from the list: ";
    cin >> idOfScientist;

    cout << "  > Are you sure you want to remove scientist with id " << "\"" << getScientistName(idOfScientist) << "\""<< " (Y/N)? " ;
    cin >> areYouSure;

    if(areYouSure == 'y' || areYouSure == 'Y')
    {
        _service.removeScientistFromDataBase(idOfScientist);
        cout << endl;
        cout << "  > Scientist has been deleted!" << endl;
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
/*
 * This function is used to add Scientist to the database, we take in a command and call add function from
 * service layer and add the scientist from to the database.
 * */





void ConsoleUI::addScientist()
{
    string name, gender, yearOfBirth, yearOfDeath;

    cin.ignore();                                                                                    //NAME

    cout << "  > Input name of scientist: ";
    getline(cin, name);

    cout << "  > Input gender (male/female): ";
    getline(cin, gender);

    //Make sure input has upper case as first letter and lower case after that.
    _service.fixInputNameScientist(name);
    _service.fixInputGenderScientist(gender);

    cout << "  > Input year of birth: ";
    getline(cin, yearOfBirth);

    cout << "  > Input year of death if applicable, if not please enter N/A): ";
    getline(cin, yearOfDeath);
    cout << endl;

    //char yesOrNo = ' ';


    if(_service.isAddScientistValid(name, gender, yearOfBirth, yearOfDeath))
    {
        _service.addScientistToData(name, gender, yearOfBirth, yearOfDeath);

        /*
        cout << "Is this scientist connected to any famous computers ?" << endl;

        cin >> yesOrNo;
        if(yesOrNo == 'Y' || yesOrNo == 'y')
        {
            int howMany = 0;
            int idNumber = 0;
            cout << "How many computers is he/she connected with?" << endl;
            cin >> howMany;
            for(int i = 0; i < howMany; i++)
            {
                //_service.addComputerToData();
                _service.connectComputerToScientist(idNumber);

            }
        }
        else if(yesOrNo == 'n' || yesOrNo == 'N')
        {
            scientistMenu();
        }
        else
        {
            cout << "Invalid input! " << endl;
        }
        */
        cout << "  > Scientest has been added to database! " << endl;

    }

    scientistMenu();

}
/*
 * This function is used to make the console look nice, the output is in consistant table.
 * */
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
void ConsoleUI::scientistWorkedOn()
{
    int idNumber;
    cout << "  > Please enter the ID of the scientist: ";
    cin >> idNumber;
    vector<Computer> computers = _service.connectScientistToComputer(idNumber);

    connectScientistColumn(idNumber);
    scientistNameColumn();
    printComputer(computers);
}

//-- Computers--//
//Computers - Menu function
/*
 * This function is used to show the Computer menu, we take in a command and navigate based on
 * what the input input is.
 * */
void ConsoleUI::computerMenu()
{
    char list = ' ';

    computerListMenuPrint();
    cin >> list;

    if(list == '1')     //All
    {
        computerListAllMenu();
    }
    else if(list == '2')
    {
        computerSearchMenu();
    }
    else if(list == 'b' || list == 'B')   //Go back to main menu.
    {
        mainMenu();
    }

    else if(list == 'q' || list == 'Q')
    {
        quitSystem();
    }

    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        computerMenu();
    }

}
/*
 * This function is used to search for a specific computer name, specific computer built year
 * and specific year.
 * */
void ConsoleUI::computerSearchMenu()
{
    char list = ' ';
    char wantToModify = ' ';
    string searchString = " ";
    computerSearchMenuPrint();
    cin >> list;

    if(list == '1')        //Specific computer name.
    {
        do
        {
            cout << "  Please enter a name of a computer: ";
            cin >> searchString;
            if(searchString == "q" || searchString == "Q")
            {
                quitSystem();
            }
        }
        while(!_service.inputNameValid(searchString));

        vector<Computer> computers = _service.searchForComputersByName(searchString);

        if(computers.size() == 0)
        {
            cout << "  > Computer not found!" << endl;
        }
        else
        {
            computerNameColumn();
            printComputer(computers);
            computerWhatToDoPrint();
            cin >> wantToModify;

            if(wantToModify == '1')
            {
                addComputer();
            }
            else if(wantToModify == '2')
            {
                computerSearchMenu();
            }
            else if(wantToModify == '3')
            {
                computerWorkedOn();
            }
            else if(wantToModify == '4')
            {
                cout << "TENGITENGI TENGITAFLA-- EFTIR AD GERA!!!" << endl;
            }
            else if(wantToModify == '5')
            {
                computerSearchMenu();
            }
            else if(goBackOrQuit(wantToModify))
            {
                computerSearchMenu();
            }
            else
            {
                cout << ">  Invalid Input!" << endl;
                computerSearchMenu();
            }
        }
     }
    else if(list == '2')      //specific specific built year.
    {
        string year;

        cout << "  > Please enter the year in question: ";

        cin >> year;

        vector<Computer> computers = _service.searchForComputersByYearBuilt(year);

        if(computers.size() == 0)
        {
            cout << "  > Year not found!" << endl;
        }
        else
        {
            printComputer(computers);
            computerWhatToDoPrint();
            cin >> wantToModify;

            if(wantToModify == '1')
            {
                addComputer();
            }
            else if(wantToModify == '2')
            {
                removeComputerFromDataBase();
            }
            else if(wantToModify == '3')
            {
                computerWorkedOn();
            }
            else if(wantToModify == '4')
            {
                cout << "TENGITENGI TENGITAFLA-- EFTIR AD GERA!!!" << endl;
            }
            else if(wantToModify == '5')
            {
                computerSearchMenu();
            }
            else if(goBackOrQuit(wantToModify))
            {
                computerSearchMenu();
            }
            else
            {
                cout << "  > Invalid input!" << endl;
                computerSearchMenu();
            }
        }
    }

    else if(list == '3')      //specific computer type
    {


        string year;
        cout << "  > Please enter year to look for: ";
        cin >> year;
        vector<Computer> computers  = _service.searchForComputersByType(year);

        if(computers.size() == 0)
        {
            cout << "  > Year not found!" << endl;
        }
        else
        {
            printComputer(computers);
            computerWhatToDoPrint();
            cin >> wantToModify;

            if(wantToModify == '1')
            {
                addComputer();
            }
            else if(wantToModify == '2')
            {
                removeComputerFromDataBase();
            }
            else if(wantToModify == '3')
            {
                computerWorkedOn();
            }
            else if(wantToModify == '4')
            {
                cout << "TENGITENGI TENGITAFLA-- EFTIR AD GERA!!!" << endl;
            }
            else if(wantToModify == '5')
            {
                computerSearchMenu();
            }
            else if(goBackOrQuit(wantToModify))
            {
                computerSearchMenu();
            }
            else
            {
                cout << "  > Invalid input!" << endl;
                computerSearchMenu();
            }

        }

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
        computerSearchMenu();
    }
}
/*
 * This function is used to print out the computer list menu.
 * */
void ConsoleUI::computerListMenu()
{
    char list = ' ';

    computerListMenuPrint();
    cin >> list;

    if(list == '1')     //All
    {
        computerListAllMenu();
    }
    else if(list == '2')
    {
        computerSearchMenu();
    }
    else if(list == 'b' || list == 'B')   //Go back to main menu.
    {
        computerMenu();
    }

}
void ConsoleUI::computerListAllMenu()
{
    char input = ' ';
    char wantToModify = ' ';
    computerListAllMenuPrint();
    cin >> input;


    if(input == '1') //A-Z
    {

        vector<Computer> computers = _service.getAllComputersAtoZ();
        computerNameColumn();
        printComputer(computers);
        computerWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addComputer();
        }
        else if(wantToModify == '2')
        {
            removeComputerFromDataBase();
        }
        else if(wantToModify == '3')
        {
            computerWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGI TENGITAFLA-- EFTIR AD GERA!!!" << endl;
        }
        else if(wantToModify == '5')
        {
            computerListAllMenu();
        }
        else if(goBackOrQuit(wantToModify))
        {
            computerListAllMenu();
        }
        else
        {
            cout << "  > Invalid inputhun!" << endl;
            computerListAllMenu();
        }

    }
    if(input == '2')    //Z-A
    {

        vector<Computer> computers = _service.getAllComputersZtoA();
        computerNameColumn();
        printComputer(computers);
        computerWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addComputer();
        }
        else if(wantToModify == '2')
        {
            removeComputerFromDataBase();
        }
        else if(wantToModify == '3')
        {
            computerWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGI TENGITAFLA-- EFTIR AD GERA!!!" << endl;
        }
        else if(wantToModify == '5')
        {
            computerListAllMenu();
        }
        else if(goBackOrQuit(wantToModify))
        {
            computerListAllMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            computerListAllMenu();
        }

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
        computerMenu();
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
    char wantToModify = ' ';
    computerListAllTypeMenuPrint();
    cin >> type;

    if(goBackOrQuit(type))
    {
        computerListAllMenu();
    }

    else
    {

            vector<Computer> computerType = _service.getAllTypesComputersAtoZ(type);
            computerNameColumn();
            printComputer(computerType);

            computerWhatToDoPrint();
            cin >> wantToModify;

            if(wantToModify == '1')
            {
                addComputer();
            }
            else if(wantToModify == '2')
            {
                removeComputerFromDataBase();
            }
            else if(wantToModify == '3')
            {
                computerWorkedOn();
            }
            else if(wantToModify == '4')
            {
                cout << "TENGITENGI TENGITAFLA-- EFTIR AD GERA!!!" << endl;
            }
            else if(wantToModify == '5')
            {
                computerListAllTypeMenu();
            }
            else if(goBackOrQuit(wantToModify))
            {
                computerListAllTypeMenu();
            }
            else
            {
                cout << "  > Invalid input!" << endl;
                computerListAllTypeMenu();
            }
        }
}
void ConsoleUI::computerListAllBuildYearMenu()
{
    string yearBuilt = " ";
    char wantToModify = ' ';
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
        vector<Computer> computers = _service.getAllBuildYearComputers(yearBuilt);
        computerNameColumn();
        printComputer(computers);

        computerWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addComputer();
        }
        else if(wantToModify == '2')
        {
            removeComputerFromDataBase();
        }
        else if(wantToModify == '3')
        {
            computerWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGI TENGITAFLA-- EFTIR AD GERA!!!" << endl;
        }
        else if(wantToModify == '5')
        {
            computerListAllBuildYearMenu();
        }
        else if(goBackOrQuit(wantToModify))
        {
            computerListAllBuildYearMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            computerListAllBuildYearMenu();
        }

    }
}

void ConsoleUI::computerListAllDevelopmentMenu()
{
    string development = " ";
    char wantToModify = ' ';
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
        vector<Computer> computers = _service.getAllDevelopmentAndOriginalComputers(development);
        computerNameColumn();
        printComputer(computers);

        computerWhatToDoPrint();
        cin >> wantToModify;

        if(wantToModify == '1')
        {
            addComputer();
        }
        else if(wantToModify == '2')
        {
            removeComputerFromDataBase();
        }
        else if(wantToModify == '3')
        {
            computerWorkedOn();
        }
        else if(wantToModify == '4')
        {
            cout << "TENGITENGI TENGITAFLA-- EFTIR AD GERA!!!" << endl;
        }
        else if(wantToModify == '5')
        {
            computerListAllDevelopmentMenu();
        }
        else if(goBackOrQuit(wantToModify))
        {
            computerListAllDevelopmentMenu();
        }
        else
        {
            cout << "  > Invalid input!" << endl;
            computerListAllDevelopmentMenu();
        }
    }
}
//Computers - Print functions.
/*
 * This function is used to print out modify menu, the user can add, edit and delete computer from the database
 * after he/her see the list they asked for.
 * */
void ConsoleUI::computerWhatToDoPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |                                      OPTIONS                                          | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " | 1 - Add computer.                                         2 - Delete computer.        | " << endl;
    cout << " | 3 - More info about computer                              4 - Add relation.           | " << endl;
    cout << " | 5 - Continue.                                                                         | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
/*
 * This function is used to print out a vector of class scientists and then it prints out
 * how many are in the list.
 * */
void ConsoleUI::printComputer(vector<Computer> temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }

    cout << " |                                       - - -                                           | " << endl;
    size_t print = temp.size();

    cout << " | ";
    cout << setfill(' ') << setw(50);
    cout << right << "Number of results returned: ";
    cout << setw(36);
    cout << left << print;
    cout << setw(1) << "|" << endl;

}
/*
 * This function is used to print out the computer menu.
 * */
void ConsoleUI::computerMenuPrint()
{
    cout << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |                                   COMPUTER MENU                                       | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |     1. List - List of computers.                                                      | " << endl;
    cout << " |     2. Developer - Enter the ID of a Computer for a list of developers                | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << "  > Please enter a number: ";
}
/*
 * This function is used to print out the computer list menu.
 * */
void ConsoleUI::computerListMenuPrint()
{
    cout << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |                                   COMPUTER MENU                                       | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |     1 - List all computers.                               2 - Search for computers.   | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << "  > Please enter a number: ";

}
/*
 * This function is used to print out the computer search all menu.
 * */
void ConsoleUI::computerSearchMenuPrint()
{
    cout << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |                                 COMPUTER SEARCH MENU                                  | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |  1 - Specific computer.       2 - Specific build year.          3 - Specific type.    | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << "  > Please enter a number: ";

}
/*
 * This function is used to print out the computer list all menu.
 * */
void ConsoleUI::computerListAllMenuPrint()
{
    cout << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |                                 COMPUTER LIST MENU                                    | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |     1. A-Z.                    2. Z-A.                       3. Type.                 | " << endl;
    cout << " |     4. Built Year.             5. Original/Developed.                                 | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " > Please enter a number: ";
}
/*
 * This function is used to print out the computer list type menu.
 * */
void ConsoleUI::computerListAllTypeMenuPrint()
{
    cout << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |                               COMPUTER LIST TYPE MENU                                 | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " |     1. Type(A-Z)                  2. Electronic              3. Mechanical            | " << endl;
    cout << " |     4. Electronic/Mechanical      5. Transistor              6. Microcomputer         | " << endl;
    cout << " |     7. Ternary                                                                        | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " > Please enter a number: ";
}
/*
 * This function is used to print out the computer list built menu.
 * */
void ConsoleUI::computerListAllYearBuiltMenuPrint()
{
    cout << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |                               COMPUTER LIST BUILT YEAR MENU                           | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |     1. Built year(oldest to newest).             2. Built year(newest to oldest).     |" << endl;
    cout << " |                                                                                       |" << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      |" << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " > Please enter a number: ";
}
/*
 * This function is used to print out the computer list development menu.
 * */
void ConsoleUI::computerListAllDevelopmentMenuPrint()
{
    cout << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |                           COMPUTER LIST DEVELOPMENT MENU                              | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " |     1. Only Original.          2. Only Developed.            3. All.                  | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << " > Please enter a number: ";
}
//Computers - Other functions.
/*
 * This function is used to add computer to the database, we take in a command and call add function from
 * service layer and add the computer from to the database.
 * */
void ConsoleUI::addComputer()
{
    string name, yearBuilt, type, development;

    cin.ignore();                                                                                    //NAME

    cout << "  > Input name of computer: ";
    getline(cin, name);


    cout << "  > Input built year (if the computer was build): ";
    getline(cin, yearBuilt);

    cout << "  > Input type of computer(Electronic, mechanic, electronic/mechanic, transistor, microcomputer or ternary.): ";
    getline(cin, type);

    cout << "  > Input computer Development(Original or developed): ";
    getline(cin, development);

    //Make sure input will be fixed so that string has uppercase first letter and the rest lower case.
    _service.fixInputNameComputer(name);
    _service.fixInputTypeComputer(type);
    _service.fixInputDevelopmentComputer(development);



    if(_service.isAddComputerValid(name, yearBuilt, type, development))
    {
        _service.addComputerToData(name, yearBuilt, type, development);

        computerMenu();
    }
    else
    {
        cout << "  > Invalid input!" << endl;

        computerMenu();
    }
}

/*
 * This function is used to add Sceintist to the database, we take in a command and call add function from
 * service layer and add the scientist from to the database.
 * */
void ConsoleUI::removeComputerFromDataBase()
{
    int idOfComputer;
    char areYouSure;


    cout << "  > Enter id of computer to remove from the list: ";
    cin >> idOfComputer;

    cout << "  > Are you sure you want to remove computer " << "\"" << getComputerName(idOfComputer) << "\"" << " (Y/N)? " ;
    cin >> areYouSure;

    if(areYouSure == 'y' || areYouSure == 'Y')
    {
        _service.removeComputerFromDataBase(idOfComputer);
        cout << endl;
        cout << "  > Computer has been deleted!" << endl;
        mainMenu();
    }

    else if(areYouSure == 'b' || areYouSure == 'B')
    {
        mainMenu();
        //utfaera location breytu til ad vita hvert a ad fara.
    }

    else if(goBackOrQuit(areYouSure))
    {
        computerListMenu();
    }
}



void ConsoleUI::computerWorkedOn()
{
    int idNumber;
    cout << "  > Please enter the ID of the computer: ";
    cin >> idNumber;
    vector<Scientist> scientists = _service.connectComputerToScientist(idNumber);
    connectComputerColumn(idNumber);
    computerNameColumn();
    printScientist(scientists);
}
/*
 * This function is used to make the console look nice, the output is in consistant table.
 * */
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
/*
 * This function is used so the user can quit the program.
 * */
void ConsoleUI::quitSystem()
{
    cout << "  > Quitting program..." << endl;
    exit(1);
}
void ConsoleUI::connectComputerColumn(int idNumber)
{
    string computerName = getComputerName(idNumber);
    cout << "  ======================================================================================= " << endl;
    cout << " |";
    cout.width(15);
    cout << right << "Developers of ";
    cout.width(72);
    cout << left << computerName;
    cout << "|" << endl;

}
void ConsoleUI::connectScientistColumn(int idNumber)
{
    string scientistName = getScientistName(idNumber);
    cout << "  ======================================================================================= " << endl;
    cout << " |";
    cout.width(26);
    cout << right << "Computers develeped by ";
    cout.width(60);
    cout << left << scientistName;
    cout << "|" << endl;
}
string ConsoleUI::getComputerName(int idNumber)
{
    return _service.getComputerName(idNumber);
}
string ConsoleUI::getScientistName(int idNumber)
{
    return _service.getScientistName(idNumber);
}
