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
    // int setKey(int value);

    string getValue();
    // string setValue(int value);

    AVLNode *getLeftChild();
    AVLNode setLeftChild(AVLNode *node);

    AVLNode *getRightChild();
    AVLNode setRightChild(AVLNode *node);

    // int getHeight();
    // int getBalance();
};