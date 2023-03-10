// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <string>

using namespace std;

class AVLNode
{
private:
    int key;
    string value;
    AVLNode *leftChild;
    AVLNode *rightChild;
    // AVLNode *parent;
    // int height;
    // int balance;

public:
    int AVLNode::getKey();
    int AVLNode::setKey(int value);

    string AVLNode::getValue();
    string AVLNode::setValue(int value);

    AVLNode AVLNode::getLeftChild();
    AVLNode AVLNode::setLeftChild(AVLNode node);

    AVLNode AVLNode::getRightChild();
    AVLNode AVLNode::setRightChild(AVLNode node);

    // int AVLNode::getHeight();
    // int AVLNode::getBalance();
};