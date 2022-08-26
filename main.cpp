#include "TST.h"

// Function to parse the input string:
vector<string> inputParsing(string myInput)
{
    // Commands vector to store the parsed input string: 
    vector<string> myCommands;

    stringstream ss(myInput);

    // Variable to hold a word of the input string:
    string singleWord;

    // Loop to parse the input string:
    while (getline(ss, singleWord, ' '))
    {
        // This erases the "," in each word:
        singleWord.erase(remove(singleWord.begin(), singleWord.end(), ','), singleWord.end());

        // This puts each word in the commands vector:
        myCommands.push_back(singleWord);
    }
    return myCommands;
}

int main(int argc, char* argv[])
{
    // Input string from the command line prompt:
    string input = argv[1];
    //string input = "insert honour, insert honour, insert honour, insert brochure, insert brochure, insert fume, lookup water, insert clear, insert zulu, delete brochure, delete honour, insert yankee, delete brochure, lookup brochure, insert triangle, insert stadium, delete triangle, lookup triangle, insert microphone, insert zulu, delete honour, delete honour, delete honour, lookup zulu, delete zulu, delete clear, insert karaoke, delete fume, delete yankee, delete stadium, delete zulu, delete karaoke, delete microphone, lookup honour, lookup microphone, insert last, lookup stadium, lookup last";
	
	// Vector to store the parsed input string:
    vector<string> commands = inputParsing(input);

    // Creating an object of the TST class:
    TST myTree;

    // Checking and performing each command from the input:
    for (int i = 0; i < commands.size(); i++)
    {
        // Checking for the command to insert a word:
        if ((commands[i] == "insert") || (commands[i] == "Insert"))
        {
            // This stores the word that follows "insert" from the input:
            string word = commands[i + 1];

            // This inserts the word in the tree:
            myTree.insert(word, myTree.root);
        }
        // Checking for the command to lookup a word:
        else if ((commands[i] == "lookup") || (commands[i] == "Lookup"))
        {
            // This stores the word that follows "lookup" from the input:
            string word = commands[i + 1];

            // Node pointer to the node that is returned by the lookup function:
            TST::Node* myNode = myTree.lookup(word, myTree.root);

            // Checking if the node pointer is a nullptr:
            if (myNode == nullptr)
            {
                cout << word << " not found" << endl;
            }
            // Checking if the word is in the left word (key) of the node:
            else if (myNode->leftWord == word)
            {
                cout << myNode->leftWord << " found, count = " << myNode->leftCount << endl;
            }
            // Checking if the word is in the right word (key) of the node:
            else if (myNode->rightWord == word)
            {
                cout << myNode->rightWord << " found, count = " << myNode->rightCount << endl;
            }
        }
        // Checking for the command to perform a words range search:
        else if ((commands[i] == "range_search") || (commands[i] == "Range_search"))
        {
            // This stores the word that follows "range_search" from the input:
            // Note: this is the word that marks the start of the words range
            string word1 = commands[i + 1];

            // This stores the third word that follows "range_search" from the input:
            // Note: this is the word that marks the end of the words range
            string word2 = commands[i + 3];

            // This performs a words range search:
            myTree.range_search(word1, word2, myTree.root);
        }
        // Checking for the command to delete a word:
        else if ((commands[i] == "delete") || (commands[i] == "Delete"))
        {
            // This stores the word that follows "delete" from the input:
            string word = commands[i + 1];

            // This deletes the word from the tree:
            myTree.delete_node(word, myTree.root);
        }
    }

    // Calling the function to print the tree:
    // myTree.printLNR(myTree.root);

    return 0;
}