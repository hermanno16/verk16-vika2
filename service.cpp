#include "service.h"
#include <cctype>


Service::Service()
{

}
//--Scientists functions--//
vector<Scientist> Service::getAllScientistsAtoZ()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsAtoZ();

    return allScientists;
}
vector<Scientist> Service::getAllScientistsZtoA()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsZtoA();

    return allScientists;
}
vector<Scientist> Service::getAllScientistsByYearOfBirthAsc()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsByYearOfBirthAsc();

    return allScientists;
}
vector<Scientist> Service::getAllScientistsByYearOfBirthDes()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsByYearOfBirthDes();

    return allScientists;
}
vector<Scientist> Service::getAllDeadOrAliveScientistsAtoZ(char input)
{
    vector<Scientist> deadOrAliveScientists;

    if(input == '1')
    {
        deadOrAliveScientists = _dAccess.getAllAliveScientistsAtoZ();
    }
    else if(input == '2')
    {
        deadOrAliveScientists = _dAccess.getAllDeceasedScientistsAtoZ();
    }
    else
    {
        deadOrAliveScientists = _dAccess.getAllAliveScientistsAtoZ();

        for(unsigned int i = 0; i < _dAccess.getAllDeceasedScientistsAtoZ().size(); i++)
        {
            deadOrAliveScientists.push_back(_dAccess.getAllDeceasedScientistsAtoZ()[i]);
        }
    }

    return deadOrAliveScientists;
}
vector<Scientist> Service::getAllDeceasedScientistsAtoZ()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllDeceasedScientistsAtoZ();

    return allScientists;
}
//Scientist - search functions.
vector<Scientist> Service::searchForScientistsByName(string searchString)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.searchForScientistsByName(searchString);

    return allScientists;
}
vector<Scientist> Service::searchForScientistsByYearOfBirthAtoZ(string yearToFind)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.searchForScientistsByYearOfBirthAtoZ(yearToFind);

    return allScientists;
}
vector<Scientist> Service::searchForScientistsByYearOfDeathAtoZ(string yearToFind)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.searchForScientistsByYearOfDeathAtoZ(yearToFind);

    return allScientists;
}
vector<Scientist> Service::getScientistsByGenderAtoZ(char gender)
{
    vector<Scientist> genderScientists;

    if(gender == '1')
    {
        genderScientists = _dAccess.getAllFemaleScientistsAtoZ();
    }
    else if(gender == '2')
    {
        genderScientists = _dAccess.getAllMaleScientistsAtoZ();
    }
    else
    {
        genderScientists = _dAccess.getAllFemaleScientistsAtoZ();

        for(unsigned int i = 0; i < _dAccess.getAllMaleScientistsAtoZ().size(); i++)
        {
            genderScientists.push_back(_dAccess.getAllMaleScientistsAtoZ()[i]);
        }
    }

    return genderScientists;
}
void Service::removeScientistFromDataBase(int idOfScientist)
{
    _dAccess.removeScientistFromDatabase(idOfScientist);
}
//--Computer and Scientist functions--//
vector<Scientist> Service::connectComputerToScientist(int idNumber)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.connectComputerToScientist(idNumber);

    return allScientists;
}
//--Computer functions--//
vector<Computer> Service::getAllComputersAtoZ()
{
    vector<Computer> allComputers;

    allComputers = _dAccess.getAllComputersAtoZ();

    return allComputers;
}
vector<Computer> Service::getAllComputersZtoA()
{
    vector<Computer> allComputers;

    allComputers = _dAccess.getAllComputersZtoA();

    return allComputers;
}
vector<Computer> Service::getAllTypesComputersAtoZ(string type)
{
    vector<Computer> typeComputer;

    if(type == "1")
    {
        typeComputer = _dAccess.getAllComputersTypeAtoZ();
    }
    else if(type == "2")
    {
        typeComputer = _dAccess.getAllComputersTypeElectronic();
    }
    else if(type == "3")
    {
        typeComputer = _dAccess.getAllComputersTypeMechanical();
    }
    else if(type == "4")
    {
        typeComputer = _dAccess.getAllComputersTypeElectronicMechanical();
    }
    else if(type == "5")
    {
        typeComputer = _dAccess.getAllComputersTransistor();
    }
    else if(type == "6")
    {
        typeComputer = _dAccess.getAllComputersTypeMicrocomputer();
    }
    else if (type == "7")
    {
        typeComputer = _dAccess.getAllComputersTypeTernary();
    }

    return typeComputer;
}
vector<Computer> Service::getAllBuildYearComputers(string yearBuilt)
{
    vector<Computer> yearBuiltComputer;

    if(yearBuilt == "1")
    {
        yearBuiltComputer = _dAccess.getAllComputersYearBuiltAtoZ();
    }
    else if(yearBuilt == "2")
    {
        yearBuiltComputer = _dAccess.getAllComputersYearBuiltZtoA();
    }

    return yearBuiltComputer;
}
vector<Computer> Service::getAllDevelopmentAndOriginalComputers(string development)
{
    vector<Computer> developmentComputer;

    if (development == "1")
    {
        developmentComputer = _dAccess.getAllComputersOriginal();
    }
    else if (development == "2")
    {
        developmentComputer = _dAccess.getAllComputersDeveloped();

    }
    else if (development == "3")
    {
        developmentComputer =_dAccess.getAllComputersDevelopedAndOriginal();
    }

    return developmentComputer;
}
//--Computer Search Functions
vector<Computer> Service::searchForComputersByName(string inputName)
{
    vector<Computer> allComputers;

    allComputers = _dAccess.searchForComputersByName(inputName);

    return allComputers;
}
vector<Computer> Service::searchForComputersByYearBuilt(string yearBuiltToFind)
{
    vector<Computer> allComputers;

    allComputers = _dAccess.searchForComputersByYearBuilt(yearBuiltToFind);

    return allComputers;
}
vector<Computer> Service::searchForComputersByType(string typeToFind)
{
    vector<Computer> allComputers;

    allComputers = _dAccess.searchForComputersByType(typeToFind);

    return allComputers;
}
//-- Valid functions --//
void Service::addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath)
{
    _dAccess.addScientistToDataBase(inputName, inputGender, inputYearOfBirth, inputYearOfDeath);
}
void Service::addComputerToData(string inputName, string inputYearBuilt, string inputType, string inputDevelopment)
{
    _dAccess.addComputerToDataBase(inputName, inputYearBuilt, inputType, inputDevelopment);
}
void Service::removeComputerFromDataBase(int idOfComputer)
{
    _dAccess.removeComputerFromDatabase(idOfComputer);
}

bool Service::inputNameValid(string input)
{
    if(atoi(input.c_str()) && input.length() < 40)
    {
        return false;
    }

    return true;
}
bool Service::isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath)
{
    bool checkName = false;             // Beisik bool-föll til að athuga hvort input
    bool checkGender = false;           // uppfylli okkar skilyrði
    bool checkYearOfBirth = false;
    bool checkYearOfDeath = false;

    transform(gender.begin(), gender.end(), gender.begin(), ::tolower);

    if(name.length() > 0)
    {
        checkName = true;
    }

    if(gender == "male" || gender == "female")
    {
        checkGender = true;
    }

    if(atoi(yearOfBirth.c_str()) <= YEARTODAY && atoi(yearOfBirth.c_str()) > 0)
    {
        checkYearOfBirth = true;
    }

    if(yearOfDeath == "N/A" || (atoi(yearOfDeath.c_str()) > atoi(yearOfBirth.c_str())) || (atoi(yearOfDeath.c_str())) <= YEARTODAY)
    {
        checkYearOfDeath = true;
    }


    return (checkName && checkGender && checkYearOfBirth && checkYearOfDeath);

}

void Service::fixInputNameScientist(string& inputName)
{
        inputName = inputName.substr(0,40);

        inputName.at(0) = toupper(inputName.at(0));

        for(unsigned int i = 1; i < inputName.size(); i++)
        {
            if (inputName.at(i - 1) == ' ')
            {
                inputName.at(i) = toupper(inputName.at(i));
            }
            else
            {
                inputName.at(i) = tolower(inputName.at(i));
            }
        }
}
void Service::fixInputGenderScientist(string& inputGender)
{
        //Max size of input is 6, if string is longer,the rest will be cut off.
        inputGender = inputGender.substr(0,6);
        //First letter to upper case.
        inputGender.at(0) = toupper(inputGender.at(0));
        //Rest of the letters to lower case.
        for(unsigned int i = 1; i < inputGender.size(); i++)
        {
            inputGender.at(i) = tolower(inputGender.at(i));

        }
}
void Service::fixInputNameComputer(string& inputName)
{
        inputName = inputName.substr(0, 23);

        inputName.at(0) = toupper(inputName.at(0));

        for(unsigned int i = 1; i < inputName.size(); i++)
        {
            if (inputName.at(i - 1) == ' ')
            {
                inputName.at(i) = toupper(inputName.at(i));
            }
            else
            {
                inputName.at(i) = tolower(inputName.at(i));
            }
        }
}
void Service::fixInputTypeComputer(string& inputType)
{
        inputType = inputType.substr(0,21);

        inputType.at(0) = toupper(inputType.at(0));

        for(unsigned int i = 1; i < inputType.size(); i++)
        {
            inputType.at(i) = tolower(inputType.at(i));

        }

}
void Service::fixInputDevelopmentComputer(string& inputDevelopment)
{

        inputDevelopment = inputDevelopment.substr(0,9);

        inputDevelopment.at(0) = toupper(inputDevelopment.at(0));

        for(unsigned int i = 1; i < inputDevelopment.size(); i++)
        {
            inputDevelopment.at(i) = tolower(inputDevelopment.at(i));

        }
}


bool Service::isAddComputerValid(string name, string yearBuilt, string type, string development)

{
    bool checkName = false;             // Beisik bool-föll til að athuga hvort input
    bool checkYearBuilt = false;           // uppfylli okkar skilyrði
    bool checkType = false;
    bool checkDevelopment = false;

    transform(type.begin(), type.end(), type.begin(), ::tolower);
    transform(development.begin(), development.end(), development.begin(), ::tolower);

    if(name.length() > 0)
    {
       checkName = true;
    }

    if(atoi(yearBuilt.c_str()) <= YEARTODAY && atoi(yearBuilt.c_str()) > 0)
    {
        checkYearBuilt = true;
    }

    if(type == "electronic" || type == "mechanical" || type == "electronic/mechanical" || type == "transistor" || type == "microcomputer" || type == "ternary")
    {
        checkType = true;
    }

    if(development == "developed" || development == "original")
    {

        checkDevelopment = true;
    }

    return (checkName && checkYearBuilt && checkType && checkDevelopment);

}

//--Operators overload--//
ostream& operator <<(ostream& os , Scientist& TempClass)    // Operator Overloader fyrir cout << Scientist.
{
    if(TempClass.getYearOfDeath()==0)
    {
        os << " | ";os.width(5); os << left << TempClass.getID();
        os.width(30); os << left << TempClass.getName();
        os << "  " ;os.width(13); os << left << TempClass.getGender();
        os << "  " ;os.width(15); os << left << TempClass.getYearOfBirth();
        os << "  " ;os.width(17); os << left << "N/A" << "|";
        os << endl;
    }
    else
    {
        os << " | ";os.width(5); os << left << TempClass.getID();
        os.width(30); os << left << TempClass.getName();
        os << "  " ;os.width(13); os << left << TempClass.getGender();
        os << "  " ;os.width(15); os << left << TempClass.getYearOfBirth();
        os << "  " ;os.width(17); os << left << TempClass.getYearOfDeath() << "|";
        os << endl;
    }

    return os;
}
ostream& operator <<(ostream& os, Computer& TempClass)    // Operator Overloader fyrir cout << Computer.
{
    os << " | ";os.width(5); os << left << TempClass.getId();
    os.width(24); os << left << TempClass.getName();
    os << "  " ;os.width(21); os << left << TempClass.getType();
    os << "  " ;os.width(13); os << left << TempClass.getYearBuilt();
    os << "  " ;os.width(17); os << left << TempClass.getDevelopment() << "|";
    os << endl;

    return os;
}
