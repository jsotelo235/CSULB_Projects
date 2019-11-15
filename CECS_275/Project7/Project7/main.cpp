#include <iostream>
#include <string>
#include "WordTree.h"
#include <fstream>
using namespace std;

const string NEWLINE = "\n";
string ConvertToUpperCase(string);

int main() {

	WordTree tree;
	fstream infile;
	string words;
	int count = 0;

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

		tree.insertNode(words);

		if (tree.searchNode(temp)) {
			count++;
		}

	}

	cout << "Tree size is: " << tree.size() << endl;
	cout << "Tree depth is: " << tree.maxDepth() << endl;
	cout << NEWLINE;

	tree.displayInOrder();

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