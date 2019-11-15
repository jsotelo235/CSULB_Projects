#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Class.h"
#include "Student.h"
using namespace std;

const string NEWLINE = "\n";

int main()
{
	fstream infile;
	Student student;
	Class _Class;

	string fileName = "";
	int numQuestions = 0, numOfTest = 0;
	int grade = 0;

	int answerKeys[50] = { 0 };		//array holds the answer keys
	int answers[50] = { 0 };		//array holds the answer of the students
	int frequency[101] = { 0 };		//frequency array keeps track of reoccuring grades

	double average = 0;

	cout << "Enter file name: ";				//prompting user to enter file name
	cin >> fileName;

	infile.open(fileName, ios::in);	//opening txt file 

	while (infile.fail())						//checks to see if the fail enter fails
	{
		infile.clear();
		cout << "File not found, please enter correct file name" << endl;
		cout << NEWLINE;

		cout << "Enter file name: ";			//prompt the user to renter name of the test
		cin >> fileName;
		infile.open(fileName + ".txt", ios::in);
	}

	infile >> numQuestions;								//reading the first line of the file

	_Class.readFile(infile, answerKeys, numQuestions);	//function reads the file	

	cout << "Student ID " <<setw(8) << "Score" << endl;
	cout << "====================" << endl;

	int i = 0, j = 0;							//variables used to keep track of the indices in an array

	while (!infile.eof())
	{
		infile >> _Class.setStudents[i].studentID;
		_Class.readFile(infile, answers, numQuestions);
		student.setGrade = student.testGrades(answerKeys, answers, numQuestions);
		frequency[student.getGrade()]++;
		average += student.getGrade();

		//total number of students
		_Class.setTotalStudents();

		_Class.sortDecendingOrder(_Class, numQuestions);		//decending sorting function
		_Class.showDecendingOrder(_Class, numQuestions);		//function display elements in decending order

		numOfTest++;
	}

	cout << "====================" << endl;
	cout << "Test graded = " << numOfTest << endl;
	cout << "====================" << endl;
	cout << "Score" << setw(14) << "Frequency" << endl;
	cout << "====================" << endl;

	for (int i = 100; i > 0; i--)
	{
		if (frequency[i] != 0)
		{
			cout << setw(3) << i << setw(12) << frequency[i] << endl;
			cout << "===================" << endl;
		}
	}

	cout << "Class Average = " << average / numOfTest << endl;

	system("pause");
	return 0;
}
