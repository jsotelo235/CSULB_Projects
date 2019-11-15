#include "Class.h"
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_STUDENTS = 30;
Class::Class()
{
	totalStudents = 0;
	students = nullptr;
}

//mutator functions 
void Class::setStudents(int totalStudents)
{
	students = new Student[totalStudents];

	delete[] students;
}

//need to set total students
void Class::setTotalStudents()
{
	totalStudents++;
}

//accessor functions
int Class::getStudents() const
{
	return;
}

int Class::getTotalStudents() const
{
	for (int i = 0;  i < MAX_STUDENTS;  i++)
	{
		return totalStudents;
	}
}

bool Class::readFile(fstream &file, int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		file >> array[i];
	}

	return file.eof();
}

void Class::sortDecendingOrder(class Class& _Class, int size)
{
	int temp1 = 0, temp2 = 0;
	bool swap = true;
	int arrayIndices = size - 1;

	do
	{
		swap = !swap;

		for (int i = 0; i < arrayIndices; i++)
		{
			//compares elements 
			if (_Class.students[i].getGrade() < _Class.students[i + 1].getGrade())
			{
				//swap elements
				temp1 = _Class.students[i].getGrade();
				temp2 = _Class.students[i].getStudentID();

				_Class.students[i].setGrade = _Class.students[i + 1].getGrade();
				_Class.students[i].setGrade = _Class.students[i + 1].getStudentID();

				_Class.students[i + 1].setGrade = temp1;
				_Class.students[i + 1].setStudentID = temp2;
				swap = swap;
			}
		}
	} while (swap);
}

void Class::showDecendingOrder(class Class &_Class, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << _Class.students[i].getStudentID() << endl;
	}
}