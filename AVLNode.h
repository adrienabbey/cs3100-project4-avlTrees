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
    int height;

    AVLNode *parentNode;
    AVLNode *leftChild;
    AVLNode *rightChild;

    // int balance;

public:
    AVLNode(int key, string value); // Constructor

    int getKey();

    string getValue();

    AVLNode *getLeftChild();
    void setLeftChild(AVLNode *node);

    AVLNode *getRightChild();
    void setRightChild(AVLNode *node);

    AVLNode *getParentNode();
    void setParentNode(AVLNode *node);

    // int getHeight();
    // int getBalance();
};