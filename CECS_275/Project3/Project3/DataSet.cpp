#include "DataSet.h"	/*Class define DataSet*/
#include <iostream>		/*Header that defines the standard input/output stream objects*/
#include <fstream>		/*IO stream class to operate on files*/
#include <iomanip>		/*IO manipulators*/
#include <string>		/*Strings are objects that represent sequences of characters*/
#include <math.h>		/*sqrt*/

using namespace std;

const string NEWLINE = "\n";

/*Class constructor constructs the dataset array*/
DataSet::DataSet(int S)
{
	size = 0;
	limit = S;

	dataset = new int[limit]; //dynamically allocating memory
}

/*Function returns the mean of dataset*/
double DataSet::mean()
{
	double sum = 0;							//variable to stored the sum of the data

	for (int i = 0; i < size; i++)
	{
		sum += dataset[i];					//adding up all the data in the dynamic array
	}
	return static_cast<double>(sum / size);	//returns the mean
}

/*Function returns the minimum value of dataset*/
int DataSet::min()
{
	sort();		//sorting the data

	return dataset[0];
}

/*Function returns the max value of dataset*/
int DataSet::max()
{
	sort();

	return dataset[size - 1];
}

/*Function returns the standard deviation of dataset*/
double DataSet::standev()
{
	double _Variance = variance();			//variance function returns value to variable
	double standDev = sqrt(_Variance);		//standard deviation calculation
	return standDev;
}

/*Function returns the median value of dataset*/
double DataSet::median()
{
	int middle;
	double average = mean();
	double median;

	middle = static_cast<double>(size / 2);	//holds the middle size value

	if (size % 2 == 0)
	{
		median = (dataset[middle] + dataset[size + 1]) / 2.0;
	}
	else
	{
		median = dataset[size] / 1.0;
	}
	return median;
}

/*Function returns the variance of dataset */
double DataSet::variance()
{
	double average = mean();		
	double temp = 0;
	int count = size;

	for (int i = 0; i < size; i++)
	{
		temp += pow((dataset[i] - average), 2);
	}
	count--;

	temp = temp / count;

	return temp;
}

/*Function accessor returns the size of dataset*/
int DataSet::getSize()
{
	return size;
}

/*
Function
PrintAll prints the dataset in either a table=true
or one column if table =false
*/
void DataSet::PrintAll(bool table)
{
	cout << "Data size: " << size << endl;

	if (table)
	{
		for (int i = 0; i < 80; i++)
		{
			cout << "=";
		}

		for (int i = 0; i < size; i++)
		{
			if (i % 10 == 0)
			{
				cout << NEWLINE;
			}

			cout << setw(10) << dataset[i];
		}

		cout << NEWLINE;

		for (int i = 0; i < 80; i++)
		{
			cout << "=";
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << setw(10) << dataset[i] << endl;
		}
	}
}

/* LoadData checks if the file "in" is open and attempts to
load the dataset from the input file. If the file is not
open print "file not open". If the file contains more data then the
limit entered, stop attempting to read and return.
*/
void DataSet::LoadData(std::ifstream &in)
{
	if (in.fail())
	{
		cout << "Error! File not open" << endl;
	}

	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> dataset[size];
			size++;
		}
	}
}

/*Function sorts the data*/
void DataSet::sort()
{
	bool swap;
	int temp;

	//bubble sort algorithm 
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (dataset[count] > dataset[count + 1])
			{
				temp = dataset[count];
				dataset[count] = dataset[count + 1];
				dataset[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}