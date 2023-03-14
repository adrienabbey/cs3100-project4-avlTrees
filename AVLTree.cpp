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
    rebalance(newNode);

    // If we got to this point, then a new node was created, return true:
    return true;
}

bool AVLTree::find(int key, string value)
{
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
{
}

void AVLTree::updateHeight(AVLNode *node)
{
    // Updates the heights of the given node, and its parents.

    // Track the heights of each child node:
    int leftHeight = 0;
    int rightHeight = 0;

    // Get the hights of each child.
    // If the left node is null:
    if (node->getLeftChild() == nullptr)
    {
        // Then the left height is -1:
        leftHeight = -1;
    }
    else
    {
        // Otherwise, it's the left child's height:
        leftHeight = node->getLeftChild()->getHeight();
    }

    // If the right node is null:
    if (node->getRightChild() == nullptr)
    {
        // Then the right height is -1:
        rightHeight = -1;
    }
    else
    {
        // Otherwise, it's the right child's height:
        rightHeight = node->getRightChild()->getHeight();
    }

    // Determine which child node's height is greater:
    // If left child is higher than the right child:
    if (leftHeight > rightHeight)
    {
        // Then this node's height is that + 1:
        node->setHeight(leftHeight + 1);
    }
    // If the right child is higher than the left:
    else if (rightHeight > leftHeight)
    {
        // Then this node is that height +1:
        node->setHeight(rightHeight + 1);
    }
    else
    {
        // Otherwise, the heights are equal, so set the height to that +1:
        node->setHeight(leftHeight + 1);
    }

    // If this node has a parent:
    if (node->getParentNode() != nullptr)
    {
        // Then update the height of the parent as well:
        updateHeight(node->getParentNode());
    }
}

void AVLTree::rebalance(AVLNode *node)
{
    // Rebalances the tree, starting with the given node.
    // It's assumed that this method is called after adding a new node.

    // First, update the heights starting with the current node:
    updateHeight(node);

    // Get the balance of the current node:
    int balance = node->getBalance();

    // FIXME: The following if statements calculate each node's balance repeatedly.
    // There may be a more efficient way to do this.

    // If the balance is -2:
    if (node->getBalance() == -2)
    {
        // And a right child exists:
        if (node->getRightChild() != nullptr)
        {
            // and the right child's balance is 1:
            if (node->getRightChild()->getBalance() == 1)
            {
                // Then we need a double rotation, starting with a right rotation of the right child:
                rotateRight(node->getRightChild());
            }
        }
        // Regardless of what happened to the right child...
        // Do a left rotation of the node:
        rotateLeft(node);
    }
    // If the balance is +2:
    else if (node->getBalance() == 2)
    {
        // And the left child exists:
        if (node->getLeftChild() != nullptr)
        {
            // and the left child's balance is -1:
            if (node->getLeftChild()->getBalance() == -1)
            {
                // Then we need a doubel rotation, starting with a left rotation of the left child:
                rotateLeft(node->getLeftChild());
            }
        }
        // Regardless of what happened to the left child...
        // Do a right rotation of the node:
        rotateRight(node);
    }
}

void rotateRight(AVLNode *node)
{
}

void rotateLeft(AVLNode *node)
{
}

int AVLTree::getHeight()
{
    // The height of this tree is the height of the root node:
    return root->getHeight();
    // This is O(1) time complexity!
    // It works because each node remembers its height.
    // The height of each new node (and its ancestors) gets updated when appropriate.
}

int AVLTree::getSize()
{
    return size;
    // Note: this is O(1) time, as this variable is incremented whenever a new node is added.
}

ostream &operator<<(ostream &os, const AVLTree &me)
{
}