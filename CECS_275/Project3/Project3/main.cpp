#include <iostream>		/*Header that defines the standard input/output stream objects*/
#include <fstream>		/*IO stream class to operate on files*/
#include<string>		/*Strings are objects that represent sequences of characters*/
#include "DataSet.h"	/*Class define DataSet*/

using namespace std;

const string NEWLINE = "\n";

void userInputValidation(int);

int main()
{
	ifstream inFile;
	string fileName;
	int userInputData;
	char input;
	bool printTable = true;

	cout << "This program calculates several basic statistics for a data set"<<
		    "of integers of any size > 0 && 100, 000, 000" << endl;

	cout << NEWLINE;

	//prompt the user to enter the size of the data
	cout << "Enter the size of the data between 1 and 100,000,000: ";
	cin >> userInputData;

	userInputValidation(userInputData);

	DataSet data(userInputData);		//Define an object of the DataSet class

	//prompt the user to enter the name of the file
	cout << "Enter the name of the file: ";
	cin >> fileName;

	inFile.open(fileName + ".txt", ifstream::in);	//Input stream class to operate on files

	data.LoadData(inFile);	//passing the files contents to the LoadData function

	//prompt the user to enter the character value Y or N
	cout << "Do you want to print the data set in a table(Y/N): ";
	cin >> input;
	
	/*If the user enter Y or y the 
	data get print in a table
	*/
	if (input == 'Y' || input == 'y')
	{
		data.PrintAll(printTable);
	}
	else if (input == 'N' || input == 'n')
	{
		data.PrintAll(!printTable);
	}

	cout << NEWLINE;
	//Print data 
	cout << "Data set size: " << data.getSize() << endl;			//size
	cout << "Mean: " << data.mean() << endl;						//mean
	cout << "Min: " << data.min() << endl;							//min
	cout << "Max: " << data.max() << endl;							//max
	cout << "Sample variance: " << data.variance() << endl;			//variance
	cout << "Sample standar deviation: " << data.standev() << endl;	//standard deviation
	cout << "Median: " << data.median() << endl;					//median

	system("pause");
	return 0;
}

/*
The purpose of this function is to check
that the user enter a value between
1 and 100,000,000
@param int input	Variable contains the value enter by the user
*/
void userInputValidation(int input)
{
	while (input <= 0 || input > 100000000)
	{
		cout << NEWLINE;
		cout << "Invalid input! Please enter a number between 1 and 100,000,000: ";
		cin >> input;
	}
}