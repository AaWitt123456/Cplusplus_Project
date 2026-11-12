#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int studentDataTable = 5;
	Student* classRosterArray[studentDataTable];

	void parse(string row);
	void add(string studentID,
			string studentFirstName,
			string studentLastName,
			string studentEmailAddress,
			int studentAge,
			int daysInCourse1,
			int daysInCourse2,
			int daysInCourse3,
			DegreeProgram degPro);

	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmail();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	~Roster();
};
