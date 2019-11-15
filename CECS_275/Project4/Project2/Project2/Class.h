#pragma once
#ifndef CLASS_H
#define CLASS_H
#include "Student.h"
#include <fstream>

using namespace std;

class Class
{
private:

	Student *students;
	int totalStudents;				//hold the total number of students objects

public:

	Class();	//constructor

	bool readFile(fstream &, int[], int);

	void sortDecendingOrder(class Class&, int);

	void showDecendingOrder(class Class&, int);

	//mutator functions
	void setStudents(int);
	void setTotalStudents();

	//accessor function
	int getStudents() const;
	int getTotalStudents() const;
};
#endif // !CLASS_H

