#include "Student.h"

Student::Student()
{
	studentID = 0;
	grade = 0;
}

int Student::testGrades(int answerKey[], int answer[], int size)
{
	int count = 0;
	int maxGrade = 100;

	for (int i = 0; i < size; i++)
	{
		if (answerKey[i] != answer[i])
		{
			count++;
		}
	}

	return maxGrade - (maxGrade / size) * count;
}

void Student::setGrade()
{
	grade = 0;
}

void Student::setStudentID()
{
	studentID = 0;
}

//getter functions
int Student::getGrade() const
{
	return grade;
}

int Student::getStudentID() const
{
	return studentID;
}