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
    cout << newTree.insert(40, "Forty") << endl;
    cout << newTree.insert(50, "Fifty") << endl;
    cout << newTree.insert(30, "Thirty") << endl;
    cout << newTree.insert(40, "Forty") << endl; // should fail
    cout << newTree.insert(20, "Twenty") << endl;
    cout << newTree.insert(10, "Ten") << endl;
    cout << newTree.insert(5, "Five") << endl;
    cout << newTree.insert(60, "Sixty") << endl;
    cout << newTree.insert(70, "Seventy") << endl;
    cout << newTree.insert(80, "Eighty") << endl;

    return 0;
}