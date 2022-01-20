#include "roster.h"

void Roster::parse(string studentData)
{

	int rhs = studentData.find(","); //find first comma and the below line pull all data from 0 up to that first comma
	string studentID = studentData.substr(0, rhs); //extract student ID

	int lhs = rhs + 1; // the start now is from that comma PLUS one, meaning it starts just after the comma
	rhs = studentData.find(",", lhs); // rhs include all from the lhs up to the next comma and pulls the data therin using the next line of code
	string firstName = studentData.substr(lhs, rhs - lhs); // student firstname

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs); //lastname

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentEmail = studentData.substr(lhs, rhs - lhs); //email

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int studentAge = std::stod(studentData.substr(lhs, rhs - lhs)); //age converted into integer via stod

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double courseTime1 = std::stod(studentData.substr(lhs, rhs - lhs)); // convert courseTime to double, first time
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double courseTime2 = std::stod(studentData.substr(lhs, rhs - lhs)); //second time
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double courseTime3 = std::stod(studentData.substr(lhs, rhs - lhs)); //third time

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	DegreeType degreeType = SECURITY;  //set standard degree
	if (studentData.substr(lhs, rhs = lhs) == "SOFTWARE") degreeType = SOFTWARE; //software if third character is F
	else if (studentData.substr(lhs, rhs = lhs) == "NETWORK") degreeType = NETWORK; //Network if third character is T

	add(studentID, firstName, lastName, studentEmail, studentAge, courseTime1, courseTime2, courseTime3, degreeType);
}

void Roster::add(string studentID, string firstName, string lastName, string studentEmail, int studentAge, double courseTime1, double courseTime2, double courseTime3, DegreeType degreeType)
{
	double time[3] = { courseTime1,courseTime2,courseTime3 }; //set time into array
	// lastIndex was secified in roster.h specifically for this purpose
	studentRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, studentEmail, studentAge, time, degreeType);
}

void Roster::printAll() //display student info
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << studentRosterArray[i]->getStudentID(); cout << '\t';
		cout << studentRosterArray[i]->getFirstName(); cout << '\t';
		cout << studentRosterArray[i]->getLastname(); cout << '\t';
		cout << studentRosterArray[i]->getStudentEmail(); cout << '\t';
		cout << studentRosterArray[i]->getStudentAge(); cout << '\t';
		cout << studentRosterArray[i]->getCourseTime()[0]; cout << '\t';
		cout << studentRosterArray[i]->getCourseTime()[1]; cout << '\t';
		cout << studentRosterArray[i]->getCourseTime()[2]; cout << '\t';
		// degree type is actually an integer 0,1,2 and must be converted into the degree via degreeTypeStrings
		cout << degreeTypeStrings[studentRosterArray[i]->getDegreeType()] << std::endl;
	}
}

void Roster::removeStudentByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = temp; 
			}
			Roster::lastIndex--; // ID not deleted, but rather hidden
		}
	}
	if (success)
	{
		cout << studentID << " removed from roster." << std::endl << std::endl;
		this->printAll(); //the removed student should no longer display
	}
	else cout << studentID << " not found." << std::endl << std::endl; 
}

//display only students that match the degree type
void Roster::printByDegreeType(DegreeType degreeType)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::studentRosterArray[i]->getDegreeType() == degreeType) studentRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printAverageCourseTime(string studentID)
{
		for (int i = 0; i <= Roster::lastIndex; i++) 
		{
			if (studentRosterArray[i]->getStudentID() == studentID)
			{
				cout << studentID << ": ";
				cout << (studentRosterArray[i]->getCourseTime()[0] //you can include an index address when getting arrays as shown
					+ studentRosterArray[i]->getCourseTime()[1]
					+ studentRosterArray[i]->getCourseTime()[2]) / 3.0 << std::endl;
			}
		}
}

/*Each email must include '@' and a '.' and not have any spaces ' '*/
void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string studentEmail = (studentRosterArray[i]->getStudentEmail());
		if (studentEmail.find('@') == string::npos || studentEmail.find('.') == string::npos || studentEmail.find(' ') != string::npos)
		{
			any = true;
			cout << studentEmail << ": " << studentRosterArray[i]->getStudentID() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student ID" << i + 1 << std::endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}

