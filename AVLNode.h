// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

// NOTE: I'm assuming that this class does not need a deconstructor method to
// be defined.  The class fields are all from the standard library, which
// already have well defined deconstructors.

#include <string>
#include <vector>

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

    int getHeight();
    void setHeight(int newHeight);

    int getBalance();

    friend ostream &printMe(ostream &os, AVLNode *node, int depth);

    void findRange(AVLNode *node, vector<string> &valueVector, int lowKey, int highKey);
};