#pragma once
#ifndef DATASET_H
#define DATASET_H
#include <fstream>

/***************************************************************
* class DataSet performs basic statistics on a data set of     *
* integers. The data set size must be at least 1 but not more  *
* than 100,000,000. The only screen output is done in          *
* LoadData(std::ifstream &in); (if an error occurs loading     *
* PrintAll(bool table).                                        *
***************************************************************/
class DataSet {
	int		*dataset;	//holds the data
	int		size;		//size of data in the set
	int		limit;		//size of the array

public:
	double mean();		//returns the mean of dataset
	int min();			//returns the minimum value of dataset
	int max();			//returns the maximum value of dataset
	double standev();	//returns the standard deviation of dataset
	double median();	//returns the median value of dataset
	double variance();	//returns the variance of dataset 
	int getSize();		//returns the size of dataset
	DataSet(int s);		//constructs the dataset array
						
	//PrintAll prints the dataset in either a table=true 
	//or one column if table =false
	void PrintAll(bool table);

	/* LoadData checks if the file "in" is open and attempts to
	load the dataset from the input file. If the file is not
	open print "file not open". If the file contains more data the
	limit entered, stop attempting to read and return.
	*/
	void LoadData(std::ifstream &in);
	void sort();
};
#endif // !DATASET_H

