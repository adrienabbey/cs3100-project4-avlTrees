// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <string>
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