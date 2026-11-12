#include "roster.h"

void Roster::parse(string studentdata)
{

    int rhs = studentdata.find(',');
    string studentID = studentdata.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentdata.find(',', lhs);
    string studentFirstName = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(',', lhs);
    string studentLastName = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string studentEmailAddress = studentdata.substr(lhs, rhs -lhs);

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int studentAge = stoi(studentdata.substr(lhs, rhs -lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse1 = stod(studentdata.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse2 = stod(studentdata.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int daysInCourse3 = stod(studentdata.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);

    DegreeProgram degPro  = SECURITY;

    if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') degPro = SECURITY;
    else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') degPro = SOFTWARE;
    else if (studentdata.at(lhs) == 'N') degPro = NETWORK;

    add(studentID, studentFirstName, studentLastName, studentEmailAddress, studentAge, daysInCourse1, daysInCourse2, daysInCourse3, degPro);

}


void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degPro)
{

    int darr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, darr, degPro);
}


void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printInvalidEmail()
{
    bool any = false;

    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmail());

        if ((email.find(".") == string::npos) || (email.find(" ") != string::npos) || (email.find("@") == string::npos))
        {
            any = true;

            cout << email << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;

}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID()==studentID)
        {
            cout << studentID << ":  ";
            cout << ( classRosterArray[i]->getDays()[0] +
                     classRosterArray[i]->getDays()[1] +
                     classRosterArray[i]->getDays()[2] ) /3; cout << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degPro)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degPro) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::remove(string studentID)
{
    bool success = false;
    for (int i=0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            success = true;
            if (i < studentDataTable - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentDataTable - 1];
                classRosterArray[studentDataTable - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " not found." << std::endl << std::endl;;
}

Roster::~Roster()
{
    cout << "destructor call" << std::endl << std::endl;
    for (int i=0; i < studentDataTable; i++)
    {
        cout << "Removing student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

