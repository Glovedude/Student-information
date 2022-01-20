#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student {

public:
	const static int courseTimeArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string studentEmail;
	int studentAge;
	double courseTime[courseTimeArraySize];
	DegreeType degreeType;
public:
	Student(); // default constructor
	Student(string studentID, string firstName, string lastName, string studentEmail, 
		int studentAge, double courseTime[], DegreeType degreeType); // full constructor
	~Student(); //destructor
	 
	//Getters/accessors
	string getStudentID();
	string getFirstName();
	string getLastname();
	string getStudentEmail();
	int getStudentAge();
	double* getCourseTime();
	DegreeType getDegreeType();

	//setters/mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setStudentEmail(string studentEmail);
	void setStudentAge(int studentAge);
	void setCourseTime(double courseTime[]);
	void setDegreeType(DegreeType degreeType);

	static void printHeader();

	void print();


};
