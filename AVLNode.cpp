// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <string>
#include <iostream>
#include "AVLNode.h"

using namespace std;

/* Constructors, Deconstructors */
AVLNode::AVLNode(int newKey, string newValue)
{
    key = newKey;
    value = newValue;
    height = 0;

    leftChild = nullptr;
    rightChild = nullptr;
    parentNode = nullptr;
}

/* Methods */
int AVLNode::getKey()
{
    return key;
}

string AVLNode::getValue()
{
    return value;
}

AVLNode *AVLNode::getLeftChild()
{
    return leftChild;
}

void AVLNode::setLeftChild(AVLNode *node)
{
    leftChild = node;
}

AVLNode *AVLNode::getRightChild()
{
    return rightChild;
}

void AVLNode::setRightChild(AVLNode *node)
{
    rightChild = node;
}

AVLNode *AVLNode::getParentNode()
{
    return parentNode;
}

void AVLNode::setParentNode(AVLNode *node)
{
    parentNode = node;
}

int AVLNode::getHeight()
{
    return height;
}

void AVLNode::setHeight(int newHeight)
{
    height = newHeight;
}

int AVLNode::getBalance()
{
    // Calculates and returns the balance of this node.
    // This is the height of the left child minus the height of the right child.

    // Track height of children:
    int leftHeight = 0;
    int rightHeight = 0;

    // If there's no left child:
    if (leftChild == nullptr)
    {
        // Then the left height is -1:
        leftHeight = -1;
    }
    else
    {
        // Otherwise, it's the left child's height:
        leftHeight = leftChild->getHeight();
    }

    // If there's no right child:
    if (rightChild == nullptr)
    {
        // Then the right height is -1:
        rightHeight = -1;
    }
    else
    {
        // Otherwise, it's the right child's height:
        rightHeight = rightChild->getHeight();
    }

    // Test code, please ignore:
    // cout << value << "'s balance is " << leftHeight - rightHeight << endl;

    // Calculate and return this node's balance
    return (leftHeight - rightHeight);
}

ostream &printMe(ostream &os, AVLNode *node, int depth)
{
    // This is a recursive function to print the AVLTree according to the project instructions.
    // Order is: right child, self, then left child:

    // If the node is not null:
    if (node != nullptr)
    {
        // Then print this node's right child:
        printMe(os, node->getRightChild(), depth + 1);

        // Print this node with the appropriate number of spaces:
        // indentation example code from: https://stackoverflow.com/a/1550334
        os << string(depth * 4, ' ');
        os << node->getKey() << ", " << node->getValue() << endl;

        // Finally, print this node's left child:
        printMe(os, node->getLeftChild(), depth + 1);
    }

    // Return the ostream:
    return os;
}

void AVLNode::findRange(AVLNode *node, vector<string> &valueVector, int lowKey, int highKey)
{
    // Look for nodes with keys between the two given values (inclusive), adding them to the given vector if found.
    // Recursive function: calls itself again for each child.

    // So long as the given node is not null:
    if (node != nullptr)
    {
        // In-order search: start with the left child:
        findRange(node->getLeftChild(), valueVector, lowKey, highKey);

        // In-order search: next, this node:
        // If this node's key is within the given range (inclusive):
        if (node->getKey() >= lowKey && node->getKey() <= highKey)
        {
            // Then add this node's value to the string vector:
            valueVector.push_back(node->getValue());
        }

        // In-orer search: finally, the right child node:
        findRange(node->getRightChild(), valueVector, lowKey, highKey);
    }
}

void AVLNode::clearHelper()
{
    // This helper method is used to ensure children of the given node get
    // deleted properly.  It calls itself recursively, deleting each child
    // node before deleting itself.  Note: nodes cannot delete themselves, so
    // the first time this method is called needs to remember to delete that
    // node after.

    // If the left child exists:
    if (leftChild != nullptr)
    {
        // Call this method recursively on that child:
        leftChild->clearHelper();
        // Then delete the child:
        delete leftChild;
    }

    // Same with the right child:
    if (rightChild != nullptr)
    {
        rightChild->clearHelper();
        delete rightChild;
    }
}

void AVLNode::updateHeight()
{
    // Updates the heights of the given node, and its parents.

    // Track the heights of each child node:
    int leftHeight = 0;
    int rightHeight = 0;

    // Get the hights of each child.
    // If the left node is null:
    if (leftChild == nullptr)
    {
        // Then the left height is -1:
        leftHeight = -1;
    }
    else
    {
        // Otherwise, it's the left child's height:
        leftHeight = leftChild->height;
    }

    // If the right node is null:
    if (rightChild == nullptr)
    {
        // Then the right height is -1:
        rightHeight = -1;
    }
    else
    {
        // Otherwise, it's the right child's height:
        rightHeight = rightChild->height;
    }

    // Determine which child node's height is greater:
    // If left child is higher than the right child:
    if (leftHeight > rightHeight)
    {
        // Then this node's height is that + 1:
        height = (leftHeight + 1);
    }
    // If the right child is higher than the left:
    else if (rightHeight > leftHeight)
    {
        // Then this node is that height +1:
        height = (rightHeight + 1);
    }
    else
    {
        // Otherwise, the heights are equal, so set the height to that +1:
        height = (leftHeight + 1);
    }
}