#pragma once
#ifndef CWORDSLIST_H
#define	CWORDSLIST_H
#include <string>
using namespace std;

class CWordsList
{
private:
	// Declare a structure for the list
	struct wordstruct
	{
		string word;
		short count;				

		struct wordstruct *next;	// To point to the next node
	};

	wordstruct *head;				// List head pointer

public:
	// Constructor
	CWordsList()
	{
		head = nullptr; 
	}

	~CWordsList();

	// Linked list operations
	void appendNode(string);
	void insertNode(string);
	void deleteNode(string);
	short countRepeatingNode(string);
	void displayList() const;

	int linkListSize();
};
#endif // !CWORDSLIST_H

