// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <string>
#include <vector>
#include <ostream>
#include "AVLNode.h"

using namespace std;

// In order to make this function usable, I needed to declare it before the class:
// https://stackoverflow.com/a/9608888
// ostream &printMe(ostream &os, AVLNode *node, int depth);
// Note: I'm moving this to the AVLNode class, as that makes FAR more sense.

class AVLTree
{
private:
    AVLNode *root;
    int size;
    void rebalance(AVLNode *node);
    void rotateRight(AVLNode *node);
    void rotateLeft(AVLNode *node);
    void replaceChild(AVLNode *currentChild, AVLNode *newChild);
    void setChild(AVLNode *parentNode, string leftOrRight, AVLNode *childNode);
    void updateHeight(AVLNode *node);

public:
    AVLTree(); // Constructor
    bool insert(int key, string value);
    bool find(int key, string &value);
    vector<string> findRange(int lowkey, int highkey);
    int getHeight();
    int getSize();
    // friend ostream &printMe(ostream &os, AVLNode *node, int depth);
    friend ostream &operator<<(ostream &os, const AVLTree &me);
};