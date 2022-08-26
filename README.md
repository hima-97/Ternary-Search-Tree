# Project Description

This project consists of implementing a Ternary Search Tree (TST), a variant of binary search tree. 
Binary search tree and its variants are members of a class of search tree called multi-way search trees. 
A node in a multi-way search tree stores k keys and therefore has k + 1 children. 
Therefore a ternary tree node will store two keys (i.e. K-left and K-right) and three children (i.e. left child, middle child, and right child).
Each node in the TST is a pair of (word, count) where word serves as the key and count is the value associated with the key
and shows the number of occurrences of the word in the underlying dataset represented by the current instance of the TST.

The search property holds as before:
- The left sub-tree has keys smaller than K-left
- The right sub-tree has keys larger than K-right
- The middle sub-tree has keys larger than K-left and smnaller than K-right

The TST class has the following functions:
-  A constructor and a destructor
-  A method for searching a word in the TST (the word may not exist in the dataset)
-  A function for inserting a new word into the TST if the word does not exist or increment the count by 1 if the word already exists
-  A function for deleting a word from the TST if the count is 1 or decrement the count by 1 if the count is greater than 1
-  A function for doing a range search
-  A function to traverse and print the tree in LNR (in-order traversal)

# Insert function

Function for inserting a new word into the TST if the word does not exist or increment the count by 1 if the word already exists.

Upon passing the string command `"insert [word]"` via argv[1], the program should print out:
- `[word] inserted, new count = [count]`

Example:
Passing the command `"insert goodbye"` will output:
- `goodbye inserted, new count = 1`, if there was no "goodbye" in the TST upon inserting
- `goodbye inserted, new count = 3`, if there were two "goodbye" in the TST upon inserting

# Lookup function

Function for searching a word in the TST (the word may not exist in the dataset).

Upon passing the string command `"lookup [word]"` via argv[1], the program should print out:
- `[word] found, count = [count of the word]`, if the word is found
- `[word] not found`, if the word is not found in the TST

Example:
Passing the command `"lookup hello"` will output:
- `hello found, count = 2`, if the TST contains two "hello"
- `hello not found`, if "hello" is not in the data structure

# Delete function

Function for deleting a word from the TST if the count is 1 or decrement the count by 1 if the count is greater than 1.

Upon passing the string command `"delete [word]"` via argv[1], the program should print out:
- `[word] deleted, new count = [count]`, if the word has count > 1
- `[word] deleted`, if the word has count = 1
- Print nothing if the word is not present in the TST

Example:
Passing the command `"delete yesterday"` will output:
- `yesterday deleted, new count = 2`, if there are three "yesterday" before deletion
- `yesterday deleted`, if "yesterday" had a count of 1 before deletion

# Range function

Function for doing a range search in the TST.
The program should print out all words alphabetically in between (and including if present) the two words provided in the range search that are in the TST.
You may assume that the first word will not be greater than the second word for the range search parameters.

Upon passing the string command `"range_search [word1] to [word2]"` via argv[1], the program should print out:
- All words in the TST in between (and including if present) word1 and word2, alphabetically and separated by a new line
- If one or both words passed as parameters are not present in the TST, then the program will print the words present in the TST that fall in this range
- Print nothing if there is no result for the range search

Example:
Passing the command `"range_search band to cat"` will output:

`band
bankers
bat
cab
calling
band
bankers
bat
cab
calling`, if these words are stored in the TST when doing the range search

# Running and testing the project

You can run and test the full project by running the following command:

- `if ($?) { g++ TST.cpp main.cpp -o TST } ; if ($?) { .\TST "insert argv[1] string argument here" }`

- Note: replace `"insert argv[1] string argument here"` with an input string from the "Test cases.txt" file
        or you can also test your own input string following the same format

- Note: the `{ g++ TST.cpp main.cpp -o TST }` command compiles the TST.cpp and main.cpp files,
        producing a TST executable file
