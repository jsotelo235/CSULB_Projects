#pragma once
#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
	int studentID;		//hold student id
	int grade;			//hold student's grade

public:

	Student();

	int testGrades(int[], int[], int);
	
	//mutators
	void setGrade();
	void setStudentID();

	//accessors
	int getGrade() const;
	int getStudentID() const;
};
#endif // !STUDENT_H

