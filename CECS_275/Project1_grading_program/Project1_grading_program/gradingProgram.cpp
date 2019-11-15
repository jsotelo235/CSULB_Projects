#include <iostream>
#include <fstream>		//Stream class to read/write files
#include <string>
#include <iomanip>
using namespace std;

const string NEWLINE = "\n";
const int MAX_SCORE = 100;

/*
Function prototypes
*/
bool readExam(fstream &file, int array[], int size);
int gradeTest(int key[], int answers[], int size);
void frequency(int *);

int main()
{
	string fileName = "";			 //variable used for user to enter name
	fstream infile;					//to read/write to file

	int studentID = 0, studentScore = 0, numTests = 0, numQuestions = 0;
	int answerKey[50], answers[50];
	int scoreFrequency[101] = { 0 };

	double average = 0;

	cout << "Enter file name: ";	//prompting user to enter file name
	cin >> fileName;

	infile.open(fileName + ".txt", ios::in);	//opening txt file 

	infile >> numQuestions;
	readExam(infile, answerKey, numQuestions);

	cout << NEWLINE;

	cout << "Student ID" << setw(12) << "Score" << endl;
	cout << "=======================" << endl;

	while (!infile.eof()) {
		infile >> studentID;
		readExam(infile, answers, numQuestions);
		studentScore = gradeTest(answerKey, answers, numQuestions);
		scoreFrequency[studentScore]++;
		average += studentScore;
		cout << studentID << setw(12) << studentScore << endl;
		numTests++;
	}

	cout << "===================" << endl;
	cout << "Tests graded = " << numTests << endl;
	cout << "===================" << endl;
	cout << "Score" << setw(14) << "Frequency" << endl;
	cout << "===================" << endl;

	frequency(scoreFrequency);

	cout << "===================" << endl;

	cout << "Class Average = " << average / numTests << endl;

	system("pause");
	return 0;
}

bool readExam(fstream &file, int array[], int size)
{
	for (int i = 0; i< size; i++)
		file >> array[i];
	return file.eof();
}

int gradeTest(int key[], int answers[], int size) {
	int misses = 0;

	for (int i = 0; i< size; i++)
		if (key[i] != answers[i])
			misses++;
	return MAX_SCORE - (MAX_SCORE / size) * misses;
}

void frequency(int *frequency)
{
	for (int i = 100; i < 0; i--)
	{
		if (frequency[i] != 0)
		{
			cout << setw(3) << i << setw(12) << frequency[i] << endl;
		}
	}
}