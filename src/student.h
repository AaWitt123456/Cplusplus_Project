#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
	public:
		const static int dayArray = 3;


		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int days[dayArray];
		DegreeProgram degreeProgram;

		Student();
		Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
		~Student();

		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int* getDays();
		DegreeProgram getDegreeProgram();

		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string email);
		void setAge(int age);
		void setDays(int days[]);
		void setDegreeProgram(DegreeProgram degPro);

		static void printHeader();

		void print();
};

