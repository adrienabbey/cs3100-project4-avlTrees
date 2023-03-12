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

    return 0;
}