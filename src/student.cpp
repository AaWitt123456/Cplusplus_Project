#include "student.h"
#include "degree.h"
using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age=0;
	for (int i = 0; i < dayArray; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this-> email = email;
    this->age = age;
    for (int i = 0; i < dayArray; i++) this ->days[i] = days[i];
    this ->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() {return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmail() {return this->email;}
int Student::getAge() {return this->age;}
int* Student::getDays() {return this->days;}
DegreeProgram Student::getDegreeProgram(){return this->degreeProgram;}

void Student::setStudentID(string studentID){this->studentID = studentID;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName){this->lastName = lastName;}
void Student::setEmail(string email){this->email = email;}
void Student::setAge(int age){ this->age = age;}
void Student::setDays(int days[])
{
	for (int i = 0; i < dayArray; i++) this ->days[i] = days[i];
}

void Student::setDegreeProgram(DegreeProgram degPro) {this ->degreeProgram = degPro;}

void Student::printHeader()
{
    cout << setw(14) << left << "Student ID:" << setw(14) << left << "First Name:"
    << setw(14) << left << "Last Name:" << setw(30) << left << "Email Address:" <<
	setw(14) << left << "Age:" << setw(25) << left << "Days to Complete:" << "Degree:" << std::endl;
}

void Student::print()
{
    cout << setw(14) << left << this->getStudentID();
    cout << setw(14) << left << this->getFirstName();
    cout << setw(14) << left << this->getLastName();
    cout << setw(30) << left << this->getEmail();
    cout << setw(14) << left << this->getAge();
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << setw(19) << left << this->getDays()[2];
    cout << setw(15) << left << degreeProgramString[this->getDegreeProgram()] << '\n';
}
