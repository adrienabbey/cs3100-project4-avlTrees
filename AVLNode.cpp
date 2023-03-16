// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <string>
#include <iostream>
#include "AVLNode.h"

using namespace std;

/* Constructors */
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
    cout << value << "'s balance is " << leftHeight - rightHeight << endl;

    // Calculate and return this node's balance
    return (leftHeight - rightHeight);
}