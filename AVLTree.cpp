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
    size = 0;
}

/* Methods */
bool AVLTree::insert(int newKey, string newValue)
{
    // Inserts the given key and value into this tree.

    // REMINDER: Increase tree size when insert is successful!

    // If there is no root, the new node becomes root:
    if (root == nullptr)
    {
        root = new AVLNode(newKey, newValue);
        // A node was successfully inserted.  Do not continue.
        return true;
    }

    // Otherwise, start walking down the tree.
    // Create a pointer to track where we are in the tree:
    AVLNode *currentNode = root;

    // While there is a node to track:
    while (currentNode != nullptr)
    {
        // If the new key is less than the current key:
        if (newKey < currentNode->getKey())
        {
            // And if the current key has no left child:
            if (currentNode->getLeftChild() == nullptr)
            {
                // Then set the current node's left child to the new node:
                currentNode->setLeftChild(new AVLNode(newKey, newValue));
            }
        }
    }

    // FIXME: return 'false' if the key already exists:
    return true;
}

bool AVLTree::find(int key, string value)
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