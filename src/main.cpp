//============================================================================
// Author      : Aaron Wittmus
//============================================================================
#include "roster.h"
#include <iostream>
using namespace std;

int main()
{

	cout << setw(25) << left << "Class:" << "Scripting and Programming - Applications - C867" << endl;
	cout << setw(25) << left << "Programming Language:" << "C++" << endl;
	cout << setw(25) << left << "Student ID:" << "#001384854" << endl;
	cout << setw(25) << left << "Name:" << "Aaron Wittmus" << endl << endl;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Aaron,Wittmus,awittm2@wgu.edu,20,10,20,400,SOFTWARE",
	};

	const int studentDataTable = 5;
	Roster classRoster;

	for (int i = 0; i < studentDataTable; i++) classRoster.parse(studentData[i]);

		cout << "Displaying All Students: " << std::endl;
		classRoster.printAll();
		cout << std::endl;

		cout << "Displaying invalid email addresses: " << std::endl;
		classRoster.printInvalidEmail();
		cout << std::endl;

		cout << "Displaying all software students:" << std::endl;
	    classRoster.printByDegreeProgram(SOFTWARE);
	    cout << std::endl;

	    cout << "Displaying average days per class by student ID:" << std::endl;
	    for (int i = 0; i < studentDataTable; i++)
	    {
	    classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	    }
	    cout << std::endl;

	    cout << "Remove student A3." << std::endl;
	    classRoster.remove("A3");
	    cout << std::endl;

	    cout << "Remove student A3." << std::endl;
	    classRoster.remove("A3");
	    cout << std::endl << std::endl;

	return 0;
}
