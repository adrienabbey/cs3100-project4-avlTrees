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
    // REMINDER: This should FAIL if the key exists!

    // If there is no root, the new node becomes root:
    if (root == nullptr)
    {
        // The new node is now the root node:
        root = new AVLNode(newKey, newValue);

        // Increment the tree size, new node.
        size++;

        // A node was successfully inserted.  Do not continue.
        return true;
    }

    // Otherwise, start walking down the tree.
    // Create a pointer to track where we are in the tree:
    AVLNode *currentNode = root;

    // Create a pointer to track the new node, if any:
    AVLNode *newNode = nullptr;

    // While there is a node to track:
    while (currentNode != nullptr)
    {
        // If the key already exists:
        if (newKey == currentNode->getKey())
        {
            // Then do NOT insert the node, return false:
            return false;
        }
        // If the new key is less than the current key:
        else if (newKey < currentNode->getKey())
        {
            // And if the current key has no left child:
            if (currentNode->getLeftChild() == nullptr)
            {
                // Create a new node:
                newNode = new AVLNode(newKey, newValue);

                // Then set the current node's left child to the new node:
                currentNode->setLeftChild(newNode);

                // New node, increment tree size:
                size++;

                // The new node's parent is the new node:
                newNode->setParentNode(currentNode);

                // Null current node, exit while loop:
                currentNode = nullptr;
            }
            else
            {
                // There is a left child, move to that:
                currentNode = currentNode->getLeftChild();
            }
        }
        // If the newKey is greater than the current key:
        else if (newKey > currentNode->getKey())
        {
            // And if the currrent key has no right child:
            if (currentNode->getRightChild() == nullptr)
            {
                // Create a new node:
                newNode = new AVLNode(newKey, newValue);

                // Then set the current node's right child to the new node:
                currentNode->setRightChild(newNode);

                // New node, increment tree size:
                size++;

                // The new node's parent is the current node:
                newNode->setParentNode(currentNode);

                // Null current node, exit while loop:
                currentNode = nullptr;
            }
            else
            {
                // There is a right child, move to that:
                currentNode = currentNode->getRightChild();
            }
        }
    }

    // Rebalance the tree starting with the new node:
    // FIXME: This needs fixing.

    // If we got to this point, then a new node was created, return true:
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