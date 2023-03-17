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
    AVLNode *root = nullptr;
    size = 0;
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

bool AVLTree::find(int key, string value)
{
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
{
}

void AVLTree::updateHeight(AVLNode *node)
{
    // Updates the heights of the given node, and its parents.

    // Track the heights of each child node:
    int leftHeight = 0;
    int rightHeight = 0;

    // Get the hights of each child.
    // If the left node is null:
    if (node->getLeftChild() == nullptr)
    {
        // Then the left height is -1:
        leftHeight = -1;
    }
    else
    {
        // Otherwise, it's the left child's height:
        leftHeight = node->getLeftChild()->getHeight();
    }

    // If the right node is null:
    if (node->getRightChild() == nullptr)
    {
        // Then the right height is -1:
        rightHeight = -1;
    }
    else
    {
        // Otherwise, it's the right child's height:
        rightHeight = node->getRightChild()->getHeight();
    }

    // Determine which child node's height is greater:
    // If left child is higher than the right child:
    if (leftHeight > rightHeight)
    {
        // Then this node's height is that + 1:
        node->setHeight(leftHeight + 1);
    }
    // If the right child is higher than the left:
    else if (rightHeight > leftHeight)
    {
        // Then this node is that height +1:
        node->setHeight(rightHeight + 1);
    }
    else
    {
        // Otherwise, the heights are equal, so set the height to that +1:
        node->setHeight(leftHeight + 1);
    }

    // If this node has a parent:
    if (node->getParentNode() != nullptr)
    {
        // Then update the height of the parent as well:
        updateHeight(node->getParentNode());
    }
}

void AVLTree::rebalance(AVLNode *node)
{
    // Rebalances the tree, starting with the given node.
    // It's assumed that this method is called after adding a new node.

    // First, update the heights starting with the current node:
    updateHeight(node);

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
        updateHeight(parentNode);
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
        updateHeight(parentNode);
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

ostream &printMe(ostream &os, AVLNode *node, int depth)
{
    // This is a recursive function to print the AVLTree according to the project instructions.
    // Order is: right child, self, then left child:

    // If the node is not null:
    if (node != nullptr)
    {
        // Then print this node's right child:
        printMe(os, node->getRightChild(), depth + 1);

        // Print this node with the appropriate number of spaces:
        // indentation example code from: https://stackoverflow.com/a/1550334
        os << string(depth * 4, ' ');
        os << node->getKey() << ", " << node->getValue() << endl;

        // Finally, print this node's left child:
        printMe(os, node->getLeftChild(), depth + 1);
    }

    // Return the ostream:
    return os;
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