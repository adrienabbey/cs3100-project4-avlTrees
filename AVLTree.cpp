// Adrien Abbey, CS-3100-02, Mar. 10, 2023
// Project #4: Indexing with AVL Trees
// Visual Studio Code Server, Ubuntu 22.04, g++/gdb

#include <iostream>
#include "AVLTree.h"

using namespace std;

/* Constructors */

AVLTree::AVLTree()
{
    // Empty AVLTree constructor.
    root = nullptr;
    size = 0;
}

AVLTree::AVLTree(const AVLTree &originalTree)
{
    // Create a deep copy of the given tree.

    // Initialize this tree:
    root = nullptr;
    size = 0;

    // Start copying nodes from the original tree:
    root = copyHelper(originalTree.root);
}

AVLTree::~AVLTree()
{
    // Deconstructor override.  This IS needed, as I regularly create 'new' AVLNodes,
    // which need to be deleted.

    // Just call this tree's clear function:
    clear();
}

/* Methods */
bool AVLTree::insert(int newKey, string newValue)
{
    // Inserts the given key and value into this tree.

    // REMINDER: Increase tree size when insert is successful!
    // REMINDER: This should FAIL if the key exists!

    // If there is no root, the new node becomes root:
    if (root == nullptr)
    {
        // The new node is now the root node:
        root = new AVLNode(newKey, newValue);

        // Increment the tree size, new node.
        size++;

        // A node was successfully inserted.  Do not continue.
        return true;
    }

    // Otherwise, start walking down the tree.
    // Create a pointer to track where we are in the tree:
    AVLNode *currentNode = root;

    // Create a pointer to track the new node, if any:
    AVLNode *newNode = nullptr;

    // While there is a node to track:
    while (currentNode != nullptr)
    {
        // If the key already exists:
        if (newKey == currentNode->getKey())
        {
            // Then do NOT insert the node, return false:
            return false;
        }
        // If the new key is less than the current key:
        else if (newKey < currentNode->getKey())
        {
            // And if the current key has no left child:
            if (currentNode->getLeftChild() == nullptr)
            {
                // Create a new node:
                newNode = new AVLNode(newKey, newValue);

                // Then set the current node's left child to the new node:
                currentNode->setLeftChild(newNode);

                // New node, increment tree size:
                size++;

                // The new node's parent is the new node:
                newNode->setParentNode(currentNode);

                // Null current node, exit while loop:
                currentNode = nullptr;
            }
            else
            {
                // There is a left child, move to that:
                currentNode = currentNode->getLeftChild();
            }
        }
        // If the newKey is greater than the current key:
        else if (newKey > currentNode->getKey())
        {
            // And if the currrent key has no right child:
            if (currentNode->getRightChild() == nullptr)
            {
                // Create a new node:
                newNode = new AVLNode(newKey, newValue);

                // Then set the current node's right child to the new node:
                currentNode->setRightChild(newNode);

                // New node, increment tree size:
                size++;

                // The new node's parent is the current node:
                newNode->setParentNode(currentNode);

                // Null current node, exit while loop:
                currentNode = nullptr;
            }
            else
            {
                // There is a right child, move to that:
                currentNode = currentNode->getRightChild();
            }
        }
    }

    // After inserting a new node, we need to rebalance the tree, starting with the parent node:
    currentNode = newNode->getParentNode();

    // While there are ancestor nodes to rebalance:
    while (currentNode != nullptr)
    {
        // Rebalance the current node:
        rebalance(currentNode);

        // Continue working up the tree:
        currentNode = currentNode->getParentNode();
    }

    // If we got to this point, then a new node was created, return true:
    return true;
}

bool AVLTree::find(int key, string &value)
{
    // Search the tree for the given key.
    // If the key is found, update the given value string, then return true.
    // If the key is not found, return false.

    // Search the tree, starting at the root node:
    AVLNode *currentNode = root;

    // While the current node is not null:
    while (currentNode != nullptr)
    {
        // If the current node is the desired key:
        if (currentNode->getKey() == key)
        {
            // Then we found our key!

            // Update the given value string pointer to the node's value:
            value = currentNode->getValue();

            // Return true:
            return true;
        }
        // If the key is less than the current node:
        else if (key < currentNode->getKey())
        {
            // Then we need to move to the left child:
            currentNode = currentNode->getLeftChild();
        }
        // If the key is greater than the current node:
        else if (key > currentNode->getKey())
        {
            // Then move onto the right child:
            currentNode = currentNode->getRightChild();
        }
    }

    // The key was not found.  Return false:
    return false;
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
{
    // Return a vector containing all the VALUES between the two keys (inclusive).
    // NOTE: I saw no mention of O time complexity, so I'm assuming I don't need to be overly efficient here.

    // Create a vector to return:
    vector<string> returnVector;

    // Find the given range of keys in the tree, starting with the root node.
    root->findRange(root, returnVector, lowkey, highkey);

    return returnVector;
}

void AVLTree::rebalance(AVLNode *node)
{
    // Rebalances the tree, starting with the given node.
    // It's assumed that this method is called after adding a new node.

    // First, update the heights starting with the current node:
    node->updateHeight();

    // FIXME: The following if statements calculate each node's balance repeatedly.
    // There may be a more efficient way to do this.

    // If the balance is -2:
    if (node->getBalance() == -2)
    {
        // And a right child exists:
        if (node->getRightChild() != nullptr)
        {
            // and the right child's balance is 1:
            if (node->getRightChild()->getBalance() == 1)
            {
                // Then we need a double rotation, starting with a right rotation of the right child:
                rotateRight(node->getRightChild());
            }
        }
        // Regardless of what happened to the right child...
        // Do a left rotation of the node:
        rotateLeft(node);
    }
    // If the balance is +2:
    else if (node->getBalance() == 2)
    {
        // And the left child exists:
        if (node->getLeftChild() != nullptr)
        {
            // and the left child's balance is -1:
            if (node->getLeftChild()->getBalance() == -1)
            {
                // Then we need a doubel rotation, starting with a left rotation of the left child:
                rotateLeft(node->getLeftChild());
            }
        }
        // Regardless of what happened to the left child...
        // Do a right rotation of the node:
        rotateRight(node);
    }
}

void AVLTree::rotateRight(AVLNode *node)
{
    // Perform a right rotation, where the given node is the 'hook' node,
    // and it's parent is the 'problem' node.

    // Save the left child's right child:
    AVLNode *savedChild = node->getLeftChild()->getRightChild();

    // If the node's parent exists:
    if (node->getParentNode() != nullptr)
    {
        // Then replace that node with the current node:
        replaceChild(node, node->getLeftChild());
    }
    else
    {
        // Otherwise, this is the root node.

        // Replace the root node with this node's left child:
        root = node->getLeftChild();

        // The new root node has no parent:
        root->setParentNode(nullptr);
    }

    // Set the right child of this node's left child to be this node:
    setChild(node->getLeftChild(), "right", node);

    // Set this node's left child to be the saved node from earlier:
    setChild(node, "left", savedChild);
}

void AVLTree::rotateLeft(AVLNode *node)
{
    // Save the right child's left child:
    AVLNode *savedChild = node->getRightChild()->getLeftChild();

    // If the node's parent exists:
    if (node->getParentNode() != nullptr)
    {
        // Then replace that node with the current node:
        replaceChild(node, node->getRightChild());
    }
    else
    {
        // Otherwise, this is the root node.

        // Replace the root node with this node's right child:
        root = node->getRightChild();

        // The root node has no parent:
        root->setParentNode(nullptr);
    }

    // Set the left child of this node's right child to be this node:
    setChild(node->getRightChild(), "left", node);

    // Set this node's right child to be the saved node from earlier:
    setChild(node, "right", savedChild);
}

void AVLTree::replaceChild(AVLNode *currentChild, AVLNode *newChild)
{
    // Replaces the current child node with a new child, using the setChild node to do this.

    // Find the parent of the current child (excluding root):
    AVLNode *parentNode = currentChild->getParentNode();
    string leftOrRight = "";

    // Determine if the current child is "left" or "right".
    // If the current child is the left child of the parent:
    if (parentNode->getLeftChild() == currentChild)
    {
        // Then specify "left":
        leftOrRight = "left";
    }
    // If the current child is the right child of the parent:
    else if (parentNode->getRightChild() == currentChild)
    {
        // Then specify "right":
        leftOrRight = "right";
    }
    else
    {
        // Something went horribly wrong.  Throw an error:
        cout << "Something went horribly wrong.  Child's direction could not be determined." << endl;
    }

    // Replace the child of the current child with a new child:
    setChild(parentNode, leftOrRight, newChild);

    // The old child's parent should be set to null:
    currentChild->setParentNode(nullptr);
}

void AVLTree::setChild(AVLNode *parentNode, string leftOrRight, AVLNode *childNode)
{
    // Set the given child node as the left or right child of the given parent node:
    // Note: this does not check if it's replacing an existing child node.

    // If "left" child specified:
    if (leftOrRight.compare("left") == 0)
    {
        // Then set the given child node to the left child of the parent node:
        parentNode->setLeftChild(childNode);

        // If the child node is not null:
        if (childNode != nullptr)
        {
            // Update the child's parent pointer:
            childNode->setParentNode(parentNode);
        }

        // Update the parent node's height:
        parentNode->updateHeight();
    }
    // If "right" child is specified:
    else if (leftOrRight.compare("right") == 0)
    {
        // Then set the given child node to be the right child of the parent node:
        parentNode->setRightChild(childNode);

        // If the child node is not null:
        if (childNode != nullptr)
        {
            // Update the child's parent pointer:
            childNode->setParentNode(parentNode);
        }

        // Update the parent node's height:
        parentNode->updateHeight();
    }
    else
    {
        // Otherwise, invalid input, throw an error:
        cout << "Invalid child direction specified!" << endl;
    }
}

int AVLTree::getHeight()
{
    // The height of this tree is the height of the root node:
    return root->getHeight();
    // This is O(1) time complexity!
    // It works because each node remembers its height.
    // The height of each new node (and its ancestors) gets updated when appropriate.
}

int AVLTree::getSize()
{
    return size;
    // Note: this is O(1) time, as this variable is incremented whenever a new node is added.
}

ostream &operator<<(ostream &os, const AVLTree &me)
{
    // This prints out the tree SIDEWAYS, in order, biggest number at top.
    // Each node is indented by its layer (root node leftmost).

    // Start recursively printing nodes starting with the root node at depth 0:
    printMe(os, me.root, 0);

    // Return the ostream:
    return os;
}

void AVLTree::clear()
{
    // Deletes all the nodes of this tree, freeing their memory.  Then resets this tree's fields.

    // Use the root node's clearHelper to delete all its children:
    root->clearHelper();

    // Then delete the root node:
    delete root;

    // Finally, reset this tree's fields:
    root = nullptr;
    size = 0;
}

AVLTree &AVLTree::operator=(const AVLTree &s)
{
    // Clear this sequence, then make a deep copy of every node on the given tree.
    // Note: this should preserve the tree's structure!  Lazy inserts could mnagle the layout.

    // Clear this tree, making it ready for new nodes:
    clear();

    // To create deep copies of nodes, I should probably use a recursive
    // copyHelper method.  Since this copy helper is part of the AVLNode
    // class, I'm calling it on root (which is nullptr).  Hopefully this works
    // fine...
    root = copyHelper(s.root);

    // Return this object:
    return *this;
}

AVLNode *AVLTree::copyHelper(AVLNode *originalNode)
{
    // Creates a new deeop copy of the given node, then create new deep copies
    // of its children nodes (recursively).  Return a pointer to the new node.

    // Create a new deep copy of the original node:
    AVLNode *newNode = new AVLNode(originalNode->getKey(), originalNode->getValue());

    // Create pointers to potential future children:
    AVLNode *newLeftChildNode = nullptr;
    AVLNode *newRightChildNode = nullptr;

    // Since I'm NOT using the insert method (as that could mangle the new
    // tree's layout), I need to be careful about updating parent/children
    // pointers, heights, etc.

    // Recursively create deep copies of the original node's children:
    // If there's an original left child:
    if (originalNode->getLeftChild() != nullptr)
    {
        // Create a deep copy of that child:
        newLeftChildNode = copyHelper(originalNode->getLeftChild());

        // Set the parent/child pointers:
        newNode->setLeftChild(newLeftChildNode);
        newLeftChildNode->setParentNode(newNode);

        // Update the heights of the new node and its ancestors:
        newLeftChildNode->updateHeight();
    }

    // Repeat if there's an original right child:
    if (originalNode->getRightChild() != nullptr)
    {
        newRightChildNode = copyHelper(originalNode->getRightChild());
        newNode->setRightChild(newRightChildNode);
        newRightChildNode->setParentNode(newNode);
        newRightChildNode->updateHeight();
    }

    return newNode;
}