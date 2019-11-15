#include <iostream>
#include <string>
#include "WordTree.h"
using namespace std;

void WordTree::insertNode(string vals) {

	TreeNode *newNode = nullptr;		// Pointer to a new node

	// A new node is created and stored
	newNode = new TreeNode;
	newNode->word = vals;

	// left and right pointers are set to nullptr
	// because all nodes must be insert as leaft nodes
	newNode->left = nullptr;
	newNode->right = nullptr;

	// private insert function
	insert(root, newNode);
}

void WordTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {

	if (nodePtr == nullptr)
	{
		nodePtr = newNode;
	}
	else if (newNode->word < newNode->word)
	{
		insert(nodePtr->left, newNode);		// recursively inserting value to the left branch
	}
	else
	{
		insert(nodePtr->right, newNode);	// recursively insert value to the right branch
	}
}

void WordTree::destroySubTree(TreeNode *nodePtr) {

	if (nodePtr)
	{
		if (nodePtr->left)
		{
			destroySubTree(nodePtr->left);
		}

		if (nodePtr->right)
		{
			destroySubTree(nodePtr->right);
		}

		delete nodePtr;
	}

}

void WordTree::deleteNode(string vals, TreeNode *&nodePtr) {

	if (vals < nodePtr->word)
	{
		deleteNode(vals, nodePtr->left);
	}
	else if (vals > nodePtr->word)
	{
		deleteNode(vals, nodePtr->right);
	}
	else
	{
		makeDeletion(nodePtr);
	}
}

void WordTree::makeDeletion(TreeNode *&nodePtr)
{
	// Define a temporary pointer to use in reattaching
	// the left subtree.

	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr) {
		cout << "Cannot delete empty node.\n";
	}
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; // Reattach the left child.
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; // Reattach the right child.
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
		// Move one node to the right.
		tempNodePtr = nodePtr->right;

		// Go to the end left node.
		while (tempNodePtr->left) {
			tempNodePtr = tempNodePtr->left;
		}

		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;

		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

bool WordTree::searchNode(string vals) {

	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->word == vals)
		{
			return true;
		}
		else if (vals < nodePtr->word)
		{
			nodePtr = nodePtr->left;		// search the left side of the tree branch
		}
		else {
			nodePtr = nodePtr->right;		// search the right side of the tree branch
		}
	}

	return false;
}

void WordTree::remove(string vals) {
	// private deleteNode function
	deleteNode(vals, root);
}


void WordTree::displayInOrder(TreeNode *nodePtr) const
{
	 if (nodePtr){
		 displayInOrder(nodePtr->left);
		 cout << nodePtr->word << endl;
		 displayInOrder(nodePtr->right);
		}
}

void WordTree::displayPostOrder(TreeNode *nodePtr) const
{
	 if (nodePtr){
		 displayPostOrder(nodePtr->left);
		 displayPostOrder(nodePtr->right);
		 cout << nodePtr->word << endl;
	 }
}

void WordTree::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr){
		 cout << nodePtr->word << endl;
		 displayPreOrder(nodePtr->left);
		 displayPreOrder(nodePtr->right);
	 }
}

int WordTree::size(TreeNode *nodePtr) {
	if (nodePtr == 0)
		return 0;
	else
		return (size(nodePtr->left) + 1 + size(nodePtr->right));
}

int WordTree::maxDepth(TreeNode *nodePtr) {
	if (nodePtr == 0)
		return 0;
	else
	{
		int leftDepth = maxDepth(nodePtr->left);
		int rightDepth = maxDepth(nodePtr->right);

		if (leftDepth > rightDepth)
		{
			return leftDepth + 1;
		}
		else
		{
			return rightDepth + 1;
		}
	}
}

void WordTree::printSorted(TreeNode *nodePtr) {
	if (nodePtr == 0)
		return;
	printSorted(nodePtr->left);
	cout << nodePtr->word << endl;
	printSorted(nodePtr->right);
}