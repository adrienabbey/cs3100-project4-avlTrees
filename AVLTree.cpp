// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <iostream>
#include "AVLTree.h"

using namespace std;

/* Constructors */

AVLTree::AVLTree()
{
    // Empty AVLTree constructor.
    AVLNode *root = nullptr;
}

/* Methods */
bool AVLTree::insert(int key, string value)
{
    // Inserts the given key and value into this tree.

    // FIXME: test code, inserts just a root node:
    root = new AVLNode(key, value);

    // FIXME: return 'false' if the key already exists:
    return true;
}

bool AVLTree::find(int key, string &value)
{
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
{
}

int AVLTree::getHeight()
{
}

int AVLTree::getSize()
{
}

ostream &operator<<(ostream &os, const AVLTree &me)
{
}