#include "TST.h"

// Function to insert a word in the tree:
void TST::insert(string myWord, Node* node)
{
	// Checking if the node pointer points to nothing:
	if (node == nullptr)
	{
		// This creates a new node on the heap (dynamic allocation):
		Node* myNode = new Node();

		// This sets the root of the tree equal to the current node (if current node is the very first node in the tree):
		if (root == nullptr)
		{
			root = myNode;
		}

		// This inserts a word in the left word (key) of the node:
		node = myNode;
		node->leftWord = myWord;
		node->leftCount++;
		cout << myWord << " inserted, new count = " << node->leftCount << endl;
		return;
	}
	// Checking if the word to be insert is the same as the node's left word (key):
	else if (myWord.compare(node->leftWord) == 0) // This returns a value < 0 if "myWord" is less then "root->leftWord"
												  // This "compare()" function compares the ASCII characters of the strings
	{
		node->leftCount++;
		cout << myWord << " inserted, new count = " << node->leftCount << endl;
		return;
	}
	// Checking if the word to be insert is the same as the node's right word (key):
	else if (myWord.compare(node->rightWord) == 0)
	{
		node->rightCount++;
		cout << myWord << " inserted, new count = " << node->rightCount << endl;
		return;
	}
	// Checking if the node's left word (key) and right word (key) are both empty:
	else if ((node->leftWord.empty()) && (node->rightWord.empty()))
	{
		node->leftWord = myWord;
		node->leftCount++;
		cout << myWord << " inserted, new count = " << node->leftCount << endl;
		return;
	}
	// Checking if the word to be insert is less than node's left word (key) and node's right word (key) is empty:
	else if ((myWord.compare(node->leftWord) < 0) && (node->rightWord.empty()))
	{
		node->rightWord = node->leftWord;
		node->rightCount = node->leftCount;
		node->leftWord = myWord;
		node->leftCount = 1;
		cout << myWord << " inserted, new count = " << node->leftCount << endl;
		return;
	}
	// Checking if the word to be insert is greater than node's left word (key) and node's right word (key) is empty:
	else if ((myWord.compare(node->leftWord) > 0) && (node->rightWord.empty()))
	{
		node->rightWord = myWord;
		node->rightCount++;
		cout << myWord << " inserted, new count = " << node->rightCount << endl;
		return;
	}
	// Checking if the word to be insert is less than node's left word (key):
	else if ((myWord.compare(node->leftWord) < 0))
	{
		// There is nothing to the left of the current node:
		if (node->left == nullptr)
		{
			node->left = new Node();
			insert(myWord, node->left);
		}
		// There is already a node to the left of the current node:
		else
		{
			insert(myWord, node->left);
		}
	}
	// Checking if the word to be insert is greater than node's right word (key):
	else if ((myWord.compare(node->rightWord) > 0))
	{
		// There is nothing to the right of the current node:
		if (node->right == nullptr)
		{
			node->right = new Node();
			insert(myWord, node->right);
		}
		// There is already a node to the right of the current node:
		else
		{
			insert(myWord, node->right);
		}
	}
	// Checking if the word to be insert is in between node's left word (key) and right word (key):
	else if ((myWord.compare(node->leftWord) > 0) && (myWord.compare(node->rightWord) < 0))
	{
		// There is nothing in the middle:
		if (node->middle == nullptr)
		{
			node->middle = new Node();
			insert(myWord, node->middle);
		}
		// There is already a node in the middle:
		else
		{
			insert(myWord, node->middle);
		}
	}
	// Do nothing if you get here:
	else
	{
		return;
	}
}

// Function to lookup a word in the tree:
TST::Node* TST::lookup(string myWord, Node* node)
{
	// Everytime the lookup function is called, "nodeGetter" is reset to nullptr:
	nodeGetter = nullptr;

	// Calling the function that returns a pointer to the node containing the word you are looking for:
	return get_node(myWord, node);
}

// Function to return a pointer to the node containing the word you are looking for:
TST::Node* TST::get_node(string myWord, Node* node)
{
	// Checking if the root of the tree points to nothing (tree is empty):
	if (root == nullptr)
	{
		return nullptr;
	}
	else
	{
		// Checking if the word is in the left word (key) of the current node:
		if (myWord == node->leftWord)
		{
			nodeGetter = node;
		}
		// Checking if the word is in the right word (key) of the current node:
		else if (myWord == node->rightWord)
		{
			nodeGetter = node;
		}
		else
		{
			// Checking the left subtree of the current node:
			if (node->left != nullptr)
				get_node(myWord, node->left);
			// Checking the middle subtree of the current node:
			if (node->middle != nullptr)
				get_node(myWord, node->middle);
			// Checking the right subtree of the current node:
			if (node->right != nullptr)
				get_node(myWord, node->right);
		}
	}
	// Checking if the node containing the word you are looking for has been found:
	if (nodeGetter != nullptr)
	{
		return nodeGetter;
	}
	// This returns a nullptr if the word you are looking for has not been found:
	else
		return nodeGetter;
}

// Function to arrange the words in the tree in alphabetical order:
vector<string> TST::alphabeticalOrder(Node* node)
{
	// Checking the left subtree of the current node:
	if (node->left != nullptr)
		alphabeticalOrder(node->left);

	// This adds the current node's left word (key) to the "myWordsInOrder" vector, if there is one:
	if (!(node->leftWord.empty()))
		myWordsInOrder.push_back(node->leftWord);

	// Checking the middle subtree of the current node:
	if (node->middle != nullptr)
		alphabeticalOrder(node->middle);

	// This adds the current node's right word (key) to the "myWordsInOrder" vector, if there is one:
	if (!(node->rightWord.empty()))
		myWordsInOrder.push_back(node->rightWord);

	// Checking the right subtree of the current node:
	if (node->right != nullptr)
		alphabeticalOrder(node->right);

	// This returns the vector containing the words in the tree arranged in alphabetical order:
	return myWordsInOrder;
}

// Function to perform a words range search in the tree:
void TST::range_search(string myWord1, string myWord2, Node* node)
{
	// Variables to keep track of the start and the end of the words range:
	int start = -1;
	int end = -1;

	// This clears (resets) the "myWordsInOrder" vector before "alphabeticalOrder()" is called:
	myWordsInOrder.clear();

	// Vector to store the words arranged in alphabetical order:
	vector<string> wordsInOrder = alphabeticalOrder(node);

	// This sets the start of the words range:
	for (int i = 0; i < wordsInOrder.size(); i++)
	{
		if (wordsInOrder[i] == myWord1)
		{
			start = i;
		}
	}
	// This sets the end of the words range:
	for (int i = 0; i < wordsInOrder.size(); i++)
	{
		if (wordsInOrder[i] == myWord2)
		{
			end = i;
		}
	}
	// If the word specified is not found, then this sets the start of the word range at the word that follows it in the alphabetical order:
	if (start == -1)
	{
		for (int i = 0; i < wordsInOrder.size(); i++)
		{
			if (wordsInOrder[i].compare(myWord1) > 0)
			{
				start = i;
				break;
			}
		}
	}
	// If the word specified is not found, then this sets the end of the word range at the word that precedes it in the alphabetical order:
	if (end == -1)
	{
		for (int i = 0; i < wordsInOrder.size(); i++)
		{
			if (wordsInOrder[i].compare(myWord2) > 0)
			{
				end = i - 1;
				break;
			}
		}
	}
	// This prints nothing if the words range results in an empty range:
	if (start == -1 && end == -1)
	{
		return;
	}
	// This prints the words range from the start to the end of the entire vector ("end" has NOT been set to a specific word):
	else if (end == -1)
	{
		for (int i = start; i < wordsInOrder.size(); i++)
		{
			cout << wordsInOrder[i] << endl;
		}
		return;
	}
	// This prints the words range from the start to the end of the range ("end" has been set to a specific word):
	else // if ((start != -1) && (end != -1))
	{
		for (int i = start; i <= end; i++)
		{
			cout << wordsInOrder[i] << endl;
		}
		return;
	}
}

// Function to delete a word in the tree:
void TST::delete_node(string myWord, Node* node)
{
	// Checking if the root of the tree points to nothing (tree is empty):
	if (root == nullptr)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	else
	{
		// Pointer to the node pointer returned by the "lookup" function:
		Node* myNode = lookup(myWord, node);

		// Checking if no node containing the word was found:
		if (myNode == nullptr)
		{
			return;
		}
		else
		{
			// Checking if the word to delete is in node's left word (key) and left count is greater than one:
			if ((myWord == myNode->leftWord) && (myNode->leftCount > 1))
			{
				myNode->leftCount--;
				cout << myWord << " deleted, new count = " << myNode->leftCount << endl;
				return;
			}
			// Checking if the word to delete is in node's right word (key) and right count is greater than one:
			else if ((myWord == myNode->rightWord) && (myNode->rightCount > 1))
			{
				myNode->rightCount--;
				cout << myWord << " deleted, new count = " << myNode->rightCount << endl;
				return;
			}
			// Checking if the word to delete is in node's left word (key) and left count is one:
			else if ((myWord == myNode->leftWord) && (myNode->leftCount == 1))
			{
				// Checking if the current node is a leaf node:
				if ((myNode->left == nullptr) && (myNode->middle == nullptr) && (myNode->right == nullptr))
				{
					// Checking if the current node does not have a right word (key):
					if (myNode->rightWord.empty())
					{
						// This traverses the entire tree and deletes the node with word you want to delete:
						traverse_and_delete(root, myNode);
						cout << myWord << " deleted" << endl;
						return;
					}
					// Checking if the current node has a right word (key):
					else
					{
						// This swaps the node's left word (key) with the node's right word (key):
						myNode->leftWord = myNode->rightWord;
						myNode->leftCount = myNode->rightCount;
						myNode->rightWord.clear();
						myNode->rightCount = 0;
						cout << myWord << " deleted" << endl;
						return;
					}
				}
				// Checking if the current node is not a leaf node:
				else
				{
					// Checking the left subtree of the current node:
					if (myNode->left != nullptr)
					{
						string tempWord = myNode->leftWord;
						int tempInt = myNode->leftCount;

						// Checking if the current node's left child has a right word (key):
						if (!(myNode->left->rightWord.empty()))
						{
							// This swaps the current node's left word (key) with the left child's right word (key):
							myNode->leftWord = myNode->left->rightWord;
							myNode->leftCount = myNode->left->rightCount;
							myNode->left->rightWord = tempWord;
							myNode->left->rightCount = tempInt;
						}
						// Checking if the current node's left child does not have a right word (key):
						else
						{
							// This swaps the current node's left word (key) with the left child's left word (key):
							myNode->leftWord = myNode->left->leftWord;
							myNode->leftCount = myNode->left->leftCount;
							myNode->left->leftWord = tempWord;
							myNode->left->leftCount = tempInt;
						}
						delete_node(tempWord, root);
					}
					// Checking the middle subtree of the current node:
					else if (myNode->middle != nullptr)
					{
						// This swaps the current node's left word (key) with the middle child's left word (key):
						string tempWord = myNode->leftWord;
						int tempInt = myNode->leftCount;
						myNode->leftWord = myNode->middle->leftWord;
						myNode->leftCount = myNode->middle->leftCount;
						myNode->middle->leftWord = tempWord;
						myNode->middle->leftCount = tempInt;

						delete_node(tempWord, root);
					}
					// Checking the right subtree of the current node:
					else if (myNode->right != nullptr)
					{
						// This swaps the current node's left word (key) with the current node's right word (key):
						string tempWord = myNode->leftWord;
						int tempInt = myNode->leftCount;
						myNode->leftWord = myNode->rightWord;
						myNode->leftCount = myNode->rightCount;
						myNode->rightWord = tempWord;
						myNode->rightCount = tempInt;

						delete_node(tempWord, root);
					}
				}
			}
			// Checking if the word to delete is in node's right word (key) and right count is one:
			else if ((myWord == myNode->rightWord) && (myNode->rightCount == 1))
			{
				// Checking if the current node is a leaf node:
				if ((myNode->left == nullptr) && (myNode->middle == nullptr) && (myNode->right == nullptr))
				{
					// This deletes the node's right word:
					myNode->rightWord.clear();
					myNode->rightCount = 0;
					cout << myWord << " deleted" << endl;
					return;
				}
				// Checking if the current node is not a leaf node:
				else
				{
					// Checking the left subtree of the current node:
					if (myNode->left != nullptr)
					{
						// This swaps the current node's right word (key) with the current node's left word (key):
						string tempWord = myNode->rightWord;
						int tempInt = myNode->rightCount;
						myNode->rightWord = myNode->leftWord;
						myNode->rightCount = myNode->leftCount;

						// Checking if the current node's left child has a right word (key):
						if (!(myNode->left->rightWord.empty()))
						{
							// This swaps the current node's left word (key) with the left child's right word (key):
							myNode->leftWord = myNode->left->rightWord;
							myNode->leftCount = myNode->left->rightCount;
							myNode->left->rightWord = tempWord;
							myNode->left->rightCount = tempInt;
						}
						// Checking if the current node's left child does not have a right word (key):
						else
						{
							// This swaps the current node's left word (key) with the left child's left word (key):
							myNode->leftWord = myNode->left->leftWord;
							myNode->leftCount = myNode->left->leftCount;
							myNode->left->leftWord = tempWord;
							myNode->left->leftCount = tempInt;
						}
						delete_node(tempWord, root);
					}
					// Checking the middle subtree of the current node:
					else if (myNode->middle != nullptr)
					{
						string tempWord = myNode->rightWord;
						int tempInt = myNode->rightCount;

						// Checking if the current node's middle child has a right word (key):
						if (!(myNode->middle->rightWord.empty()))
						{
							// This swaps the current node's right word (key) with the middle child's right word (key):
							myNode->rightWord = myNode->middle->rightWord;
							myNode->rightCount = myNode->middle->rightCount;
							myNode->middle->rightWord = tempWord;
							myNode->middle->rightCount = tempInt;
						}
						// Checking if the current node's middle child does not have a right word (key):
						else
						{
							// This swaps the current node's right word (key) with the middle child's left word (key):
							myNode->rightWord = myNode->middle->leftWord;
							myNode->rightCount = myNode->middle->leftCount;
							myNode->middle->leftWord = tempWord;
							myNode->middle->leftCount = tempInt;
						}
						delete_node(tempWord, root);
					}
					// Checking the right subtree of the current node:
					else if (myNode->right != nullptr)
					{
						string tempWord = myNode->rightWord;
						int tempInt = myNode->rightCount;

						// The first thing to do is to find the in-order successor of the word to delete.
						// Note: the in-order successor in this case is the smallest word (key) in the right subtree of the current node.

						// Checking the left subtree of the current node's right child:
						if ((myNode->right->left != nullptr))
						{
							Node* tempNode = myNode->right;
							// This traverses the entire left subtree until you get to the node containing the in-order successor of the word to delete:
							while (tempNode->left != nullptr)
							{
								tempNode = tempNode->left;
							}

							// This swaps the current node's right word (key) with the in-order successor:
							myNode->rightWord = tempNode->leftWord;
							myNode->rightCount = tempNode->leftCount;
							tempNode->leftWord = tempWord;
							tempNode->leftCount = tempInt;
						}
						// Checking if the current node's right child does not have a left subtree:
						// Note: if there is no left subtree, then the in-order successor is the left word (key) of the current node's right child
						else
						{
							// This swaps the current node's right word (key) with the in-order successor:
							myNode->rightWord = myNode->right->leftWord;
							myNode->rightCount = myNode->right->leftCount;
							myNode->right->leftWord = tempWord;
							myNode->right->leftCount = tempInt;
						}
						delete_node(tempWord, root);
					}
				}
			}
		}
	}
}

// Function to traverse the tree from the root and delete the node containing the word you want to delete:
void TST::traverse_and_delete(Node* node, Node* targetNode)
{
	// Checking if the node to delete is the root of the tree:
	if (root == targetNode)
	{
		root = nullptr;
		return;
	}
	// Checking the left subtree of the current node:
	if (node->left != nullptr)
	{
		if (node->left == targetNode)
		{
			node->left = nullptr;
			return;
		}
		else
		{
			traverse_and_delete(node->left, targetNode);
		}
	}
	// Checking the middle subtree of the current node:
	if (node->middle != nullptr)
	{
		if (node->middle == targetNode)
		{
			node->middle = nullptr;
			return;
		}
		else
		{
			traverse_and_delete(node->middle, targetNode);
		}
	}
	// Checking the right subtree of the current node:
	if (node->right != nullptr)
	{
		if (node->right == targetNode)
		{
			node->right = nullptr;
			return;
		}
		else
		{
			traverse_and_delete(node->right, targetNode);
		}
	}
}

// Function to traverse and print the tree in LNR (in-order traversal):
void TST::printLNR(Node* node)
{
	// Checking the left subtree of the current node:
	if (node->left != nullptr)
		printLNR(node->left);

	// This prints the current node's left word (key), if there is one:
	if (!(node->leftWord.empty()))
		cout << "Left word (key) = " << node->leftWord << ", " << node->leftCount << endl;

	// Checking the middle subtree of the current node:
	if (node->middle != nullptr)
		printLNR(node->middle);

	// This prints the current node's right word (key), if there is one:
	if (!(node->rightWord.empty()))
		cout << "Right word (key) = " << node->rightWord << ", " << node->rightCount << endl;

	// Checking the right subtree of the current node:
	if (node->right != nullptr)
		printLNR(node->right);
}