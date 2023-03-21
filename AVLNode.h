// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

// NOTE: I'm assuming that this class does not need a deconstructor method to
// be defined.  This class does not create 'new' objects, except perhaps by
// standard class objects, which should handle themselves.

#include <string>
#include <vector>

using namespace std;

class AVLNode
{
private:
    /* Fields */
    int key;
    string value;
    int height;

    AVLNode *parentNode;
    AVLNode *leftChild;
    AVLNode *rightChild;

public:
    /* Constructors, Deconstructors */
    AVLNode(int key, string value);

    /* Methods */
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

    void findRange(AVLNode *node, vector<string> &valueVector, int lowKey, int highKey);

    void clearHelper();

    /* Overrides */
    friend ostream &printMe(ostream &os, AVLNode *node, int depth);
};