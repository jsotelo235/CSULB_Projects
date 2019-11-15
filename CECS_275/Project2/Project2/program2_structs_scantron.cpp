#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SCORE = 100;
const string NEWLINE = "\n";

struct Student
{
	int studentID;		//hold student id
	int grade;			//hold student's grade
};

struct Class
{
	Student students[100] = { 0 };	//student struct array
	int totalStudents;				//hold the total number of students objects
};

//function prototypes
bool readFile(fstream &, int [], int);

int testGrades(int [], int [], int);

void sortDecendingOrder(struct Class&, int);

void showDecendingOrder(const struct Class&, int);

int main()
{
	fstream infile;
	Student student;
	Class _Class;

	string fileName = "";
	int numQuestions = 0, numOfTest = 0;

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

	infile >> numQuestions;						//reading the first line of the file

	readFile(infile, answerKeys, numQuestions);	//function reads the file	

	cout << "Student ID " <<setw(8) << "Score" << endl;
	cout << "====================" << endl;

	int i = 0, j = 0;							//variables used to keep track of the indices in an array

	while (!infile.eof())
	{
		infile >> _Class.students[i].studentID;
		readFile(infile, answers, numQuestions);
		student.grade = testGrades(answerKeys, answers, numQuestions);
		frequency[student.grade]++;
		average += student.grade;

		//total number of students
		_Class.totalStudents++;

		sortDecendingOrder(_Class, numQuestions);		//decending sorting function
		showDecendingOrder(_Class, numQuestions);		//function display elements in decending order

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

//Function definitions
bool readFile(fstream &file, int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		file >> array[i];
	}
	
	return file.eof();	
}

int testGrades(int answerKey[], int answers[], int size)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (answerKey[i] != answers[i])
		{
			count++;
		}

		return MAX_SCORE - (MAX_SCORE / size) * count;
	}
}

void sortDecendingOrder(struct Class &_Class, int size)
{
	int temp1= 0, temp2 = 0;
	bool swap = true;
	int arrayIndices = size - 1;

	do
	{
		swap = !swap;

		for (int i = 0; i < arrayIndices; i++)
		{
			//compares elements 
			if (_Class.students[i].grade < _Class.students[i + 1].grade)
			{
				//swap elements
				temp1 = _Class.students[i].grade;
				temp2 = _Class.students[i].studentID;

				_Class.students[i].grade = _Class.students[i + 1].grade;
				_Class.students[i].grade = _Class.students[i + 1].studentID;

				_Class.students[i + 1].grade = temp1;
				_Class.students[i + 1].studentID = temp2;
				swap = swap;
			}
		}
	} while (swap);
}

void showDecendingOrder(const struct Class &_Class, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << _Class.students[i].studentID << endl;
	}
}
