#pragma once
#ifndef WORDTREE_H
#define WORDTREE_H
#include <string>
using namespace std;

class WordTree {

	// Binary Tree is a non-linear linked structure
	// because each node can point to two other nodes

private:
	struct TreeNode
	{
		string word;
		int value;
		TreeNode *left;		// Pointer to the left child node
		TreeNode *right;	// Pointer to the right child node
	};

	TreeNode *root;			// Pointer to the root node

	// private memeber functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);		// recursively destroy all nodes
	void deleteNode(string, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

	int size(TreeNode *nodePtr);
	int maxDepth(TreeNode *nodePtr);

	void printSorted(TreeNode *nodePtr);

public:

	// Constructor
	WordTree() {
		root = nullptr;
	}

	// Destructor
	~WordTree() {
		destroySubTree(root);
	}

	// Binary Tree Operations
	void insertNode(string);
	bool searchNode(string);
	void remove(string);

	void printSorted() {
		printSorted(root);
	}

	void displayInOrder() const
	{
		displayInOrder(root);
	}

	void displayPreOrder() const
	{
		displayPreOrder(root);
	}

	void displayPostOrder() const
	{
		displayPostOrder(root);
	}

	int size() {
		return size(root);
	}

	int maxDepth() {
		return maxDepth(root);
	}
};
#endif // !WORDTREE_H

