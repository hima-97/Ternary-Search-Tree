#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm> // Needed to remove characters in strings
#include <sstream> // Needed for the parsing function
using namespace std;

// Ternary Search Tree (TST) class:
class TST
{
public:
	// TST Node class:
	class Node
	{
	public:
		string leftWord;
		string rightWord;
		int leftCount = 0, rightCount = 0;
		Node* left, * middle, * right;
		// Node constructor:
		Node() { right = left = middle = nullptr; }
		// Node destructor:
		~Node() { right = left = middle = nullptr; delete left, middle, right; }
	};

	// Pointer to the root of the tree:
	Node* root;

	// Tree constructors:
	TST() { root = nullptr; }
	TST(Node* myRoot) { root = myRoot; }

	// Tree destructor:
	~TST() { root = nullptr; delete root; };

	// Function to insert a word in the tree:
	void insert(string myWord, Node* node);

	// Function to lookup a word in the tree:
	Node* lookup(string myWord, Node* node);
	Node* get_node(string myWord, Node* node); // Function to return a pointer to the node containing the word you are looking for
	Node* nodeGetter = nullptr; // Pointer to the node containing the word you are looking for

	// Function to perform a words range search in the tree:
	void range_search(string myWord1, string myWord2, Node* node);

	// Function to arrange the words in the tree in alphabetical order:
	vector<string> alphabeticalOrder(Node* node);

	// Vector to store the words in the tree arranged in alphabetical order: 
	vector<string> myWordsInOrder;

	// Function to delete a word in the tree:
	void delete_node(string myWord, Node* node);

	// Function to traverse the tree from the root and delete the node containing the word you want to delete: 
	void traverse_and_delete(Node* node, Node* targetNode);

	// Function to traverse and print the tree in LNR (in-order traversal):
	void printLNR(Node* node);

	// Function to traverse and print the tree in NLR (pre-order traversal):
	void printNLR(Node* node);

	// Function to traverse and print the tree in LRN (post-order traversal):
	void printLRN(Node* node);
};