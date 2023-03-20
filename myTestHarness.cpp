// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <iostream>
#include "AVLTree.h"

using namespace std;

void generateRandNodes(AVLTree &tree)
{
     // Generates random node values and insert them into the given AVL tree.

     // The tree's size should be between 7+8 and 15+8 nodes (inclusive):
     int nodeCount = (rand() % 15) + 23;

     // Start seeding the tree with random nodes:
     for (int i = 0; i < nodeCount; i++)
     {
          // Generate a random key value between 1 and 100:
          int randKey = (rand() % 100) + 1;

          // Add that new value to the tree:
          cout << "Inserting " << randKey << ": " << tree.insert(randKey, " ") << endl;
     }

     cout << endl
          << tree;
}

int main()
{
     // Seed the RNG:
     srand(time(nullptr));

     // Create an empty AVLTree:
     AVLTree newTree;
     cout << newTree.insert(40, "Forty");
     cout << newTree.insert(50, "Fifty");
     cout << newTree.insert(30, "Thirty");
     cout << newTree.insert(20, "Twenty");
     cout << newTree.insert(10, "Ten");
     cout << newTree.insert(5, "Five");
     cout << newTree.insert(60, "Sixty");
     cout << newTree.insert(70, "Seventy");
     cout << newTree.insert(80, "Eighty");
     cout << newTree.insert(25, "Twenty Five");
     cout << newTree.insert(40, "Forty") << endl
          << endl;

     // Print the tree:
     cout << newTree << endl;

     // Print tree statistics:
     cout << "Tree height: " << newTree.getHeight() << endl;
     cout << "Tree size: " << newTree.getSize() << endl
          << endl;

     string findString = "Nothing found.";
     // Test the find function:
     cout << "Find 5 gives: " << newTree.find(5, findString) << " " << findString << endl;
     findString = "Nothing found.";
     cout << "Find 100 gives: " << newTree.find(100, findString) << " " << findString << endl;

     // AVLTree tinyTree;
     // tinyTree.insert(1, "one");

     // cout << "Tree height: " << tinyTree.getHeight() << endl;
     // cout << "Tree size: " << tinyTree.getSize() << endl;

     AVLTree randTree;
     generateRandNodes(randTree);
     int randLow = (rand() % 50) + 1;
     int randHigh = (rand() % 50) + 51;
     vector<string> findRangeResultVector = randTree.findRange(randLow, randHigh);
     cout << "Find values between " << randLow << " and " << randHigh << " results in:" << endl;
     for (string i : findRangeResultVector)
     {
          cout << "    " << i << ", ";
     }

     return 0;
}