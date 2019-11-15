#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "CWordList.h"
using namespace std;

const string NEWLINE = "\n";

string ConvertToUpperCase(string);
void SearchList(string);

int main()
{
	fstream infile;
	string words = "";
	CWordsList wordsList;

	infile.open("words.txt", ios::in);

	// Checks to see if the the file exits
	if (infile.fail())
	{
		cout << "ERROR: Cannot open the file.\n";
		return 0;
	}

	string temp = " ";

	while (!infile.eof())
	{
		infile >> words;
		temp = ConvertToUpperCase(words);
		wordsList.insertNode(temp);
		cout << wordsList.countRepeatingNode(temp) << endl;
	}

	wordsList.displayList();
	system("pause");
	return 0;
}

string ConvertToUpperCase(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		// if the character is not a space
		if (str[i] != ' ')
		{
			// set the character to lower case
			str[i] = toupper(str[i]);
		}
	}

	return str;
}