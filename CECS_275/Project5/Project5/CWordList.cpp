#include "CWordList.h"
#include <iostream>
#include <string>
using namespace std;


CWordsList::~CWordsList()
{
	wordstruct *nodePtr;
	wordstruct *nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}

}


void CWordsList::appendNode(string words)
{
	wordstruct *newNode;	// to point to a new node
	wordstruct *nodePtr;	// to move through the list

	// Allocate new node and store the number there
	newNode = new wordstruct();
	newNode->word = words;
	newNode->next = nullptr;

	// Empty nodes in the list, make a new node to the first
	if (head == nullptr)
	{
		head = newNode;
	}
	else {
		// initialize nodePtr to the head of the list
		nodePtr = head;

		//	search for the last node in the list
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		// insert the new node into the list
		nodePtr->next = newNode;
	}
}

/*
Insert node into the list
*/
void CWordsList::insertNode(string words) {

	wordstruct *newNode = nullptr;					// A new node
	wordstruct *nodePtr = nullptr;					// Traverse the list
	wordstruct *previousNode = nullptr;				// Previous node

	// Allocate a new node and store the num
	newNode = new wordstruct;
	newNode->word = words;

	// if there are no nodes in the list, make a new node in the first node
	if (head == nullptr)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // insert a node
	{
		// Position nodePtr to the head of the list
		nodePtr = head;

		// Initialize the previous nodePtr to nullptr
		previousNode = nullptr;

		// Skip all nodes whose value is less than num.
		while ((nodePtr != nullptr) && (nodePtr->word < words))
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// if the new node is the first in the list, insert new node there
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // else, insert node after the previous node
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

/*
Delete a node in the list
*/
void CWordsList::deleteNode(string words)
{
	wordstruct *nodePtr = nullptr;				// Use to traverse the list
	wordstruct *previousNode = nullptr;			// Use to point to the next node

	// If the list is empty, don't do anything
	if (!head)
	{
		return;
	}

	// Determine if the first node is the one to delete
	if (head->word == words)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// initialize nodePtr to the head of the list
		nodePtr = head;

		//Skip all the nodes whos number is not equal to num
		while (nodePtr != nullptr && nodePtr->word != words)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// NodePtr is not at the end of the list, link the previous
		// node to the node after nodePtr, then delte nodePtr
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

short CWordsList::countRepeatingNode(string str)
{
	wordstruct *current = head;
	wordstruct value;
	value.count = 0;

	while (current != nullptr)
	{
		if (current->word == str)
		{
			value.count++;
		}

		current = current->next;
	}
	return value.count;
}

/*
Traverse the link list and display the value in the node
*/
void CWordsList::displayList() const
{
	wordstruct *nodePtr;	// traverse through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		// Display the value in the node
		cout << nodePtr->word << endl;

		// Move to the next node
		nodePtr = nodePtr->next;
	}
}

/*
Link list size
*/
int CWordsList::linkListSize()
{
	int size = 0;

	wordstruct *nodePtr = head;

	while (nodePtr != nullptr)
	{
		size++;
		nodePtr = nodePtr->next;
	}

	return size;
}
