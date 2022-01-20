#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* studentRosterArray[numStudents];

public:
	void parse(string row);
	void add(string studentID,
		string firstName,
		string lastName,
		string studentEmail,
		int studentAge,
		double courseTime1,
		double courseTime2,
		double courseTime3,
		DegreeType degreeType);

	void removeStudentByID(string studentID); //remove student from list by ID tag
	void printAll();
	void printAverageCourseTime(string studentID); // print everage days in course, identified by studentID
	void printInvalidEmails(); //email must include '@', '.', and no ' '
	void printByDegreeType(DegreeType degreeType);
	~Roster();

};