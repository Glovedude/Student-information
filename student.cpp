#include "student.h"

Student::Student() // parameterless constructor
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->studentEmail = "";
	this->studentAge = 0;
	for (int i = 0; i < courseTimeArraySize; ++i)
		this->courseTime[i] = 0;
	this->degreeType = DegreeType::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string studentEmail,
	int studentAge, double courseTime[], DegreeType degreeType)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	for (int i = 0; i < courseTimeArraySize; ++i)
		this->courseTime[i] = courseTime[i];
	this->degreeType = degreeType;
}

Student::~Student() {} //destructor

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastname() { return this->lastName; }
string Student::getStudentEmail() { return this->studentEmail; }
int Student::getStudentAge() { return this->studentAge; }
double* Student::getCourseTime() { return this->courseTime; }
DegreeType Student::getDegreeType() { return this->degreeType; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setStudentEmail(string studentEmail) { this->studentEmail = studentEmail; }
void Student::setStudentAge(int studentAge) { this->studentAge = studentAge; }
void Student::setCourseTime(double courseTime[]) //set time individually via loop
{
	for (int i = 0; i < courseTimeArraySize; ++i) this->courseTime[i] = courseTime[i];
}
void Student::setDegreeType(DegreeType dt) { this->degreeType = dt; }

void Student::printHeader() //print header
{
	cout << "Output format: StudentID|First Name|Last Name|Email Address|Age|Time to complete 3 courses|Degree Program\n";
}

void Student::print()
{
	cout << this->getStudentID() << '\t'; // tab to seperate output and getters until coursetime, which is seperated via comma
	cout << this->getFirstName() << '\t';
	cout << this->getLastname() << '\t';
	cout << this->getStudentEmail() << '\t';
	cout << this->getStudentAge() << '\t';
	cout << this->getCourseTime()[0] << ',';
	cout << this->getCourseTime()[1] << ',';
	cout << this->getCourseTime()[2] << '\t';
	cout << degreeTypeStrings[this->getDegreeType()] << '\n';
}


