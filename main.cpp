#include "roster.h"

int main()
{
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Chase,Christensen,cchr288@wgu.edu,28,3,2,3,SOFTWARE"
	};
	
	const int numStudents = 5;
	Roster roster;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Displaying all students; " << std::endl;
	roster.printAll();
	cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying roster by degree program: " << degreeTypeStrings[i] << std::endl;
		roster.printByDegreeType((DegreeType)i);
	}

	cout << "Displaying students with invalid emails" << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;

	cout << "Average time in courses:" << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		roster.printAverageCourseTime(roster.studentRosterArray[i]->getStudentID());
	}
	cout << std::endl;
	

	cout << "Removing student with ID A3:" << std::endl;
	roster.removeStudentByID("A3");
	cout << std::endl;

	cout << "Removing student with ID A3:" << std::endl;
	roster.removeStudentByID("A3");
	cout << std::endl;

	system("pause");
	return 0;

}