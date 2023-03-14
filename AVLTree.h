// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <string>
#include <vector>
#include "AVLNode.h"

using namespace std;

class AVLTree
{
private:
    AVLNode *root;
    int size;
    // int height;

public:
    AVLTree(); // Constructor
    bool insert(int key, string value);
    bool find(int key, string value);
    vector<string> findRange(int lowkey, int highkey);
    int getHeight();
    int getSize();
    friend ostream &operator<<(ostream &os, const AVLTree &me);
};