// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
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
    cout << newTree.insert(40, "Forty") << endl;

    cout << "Tree height: " << newTree.getHeight() << endl;
    cout << "Tree size: " << newTree.getSize() << endl;

    AVLTree tinyTree;
    tinyTree.insert(1, "one");

    cout << "Tree height: " << tinyTree.getHeight() << endl;
    cout << "Tree size: " << tinyTree.getSize() << endl;

    return 0;
}