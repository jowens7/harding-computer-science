#include <fstream>
#include <iostream>
#include <iomanip>
#include "tree.h"

/**
 * Create a new tree
 */
Tree::Tree() {
    root = NULL;
    nodeCount = 1;
    treeHeight = 0;
}

/**
 * Destroy a tree
 */
Tree::~Tree() {
    deleteTree(root);
}

/**
 * Insert a node into the tree
 * @param value The value to insert
 * @return Whether or not the operation succeeded
 */
bool Tree::insertNode(TreeType value) {
    int nodeHeight = 0;
    Node *newNode = new Node;
    if (newNode == NULL) {
        return false;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value;
    newNode->count = 1;
    newNode->parent = NULL;
    if (root == NULL) {
        root = newNode;
    } else {
        Node *currentNode = root;
        Node *parentNode = NULL;
        while (currentNode != NULL) {
            nodeHeight += 1;
            parentNode = currentNode;
            if (newNode->value < currentNode->value) {
                currentNode = currentNode->left;
            } else if (newNode->value > currentNode->value) {
                currentNode = currentNode->right;
            } else {
                currentNode->count += 1;
                return true;
            }
        }
        nodeCount += 1;
        newNode->parent = parentNode;
        if (newNode->value <= parentNode->value) {
            parentNode->left = newNode;
        } else {
            parentNode->right = newNode;
        }
    }
    if (nodeHeight > treeHeight) {
        treeHeight = nodeHeight;
    }
    return true;
}

/**
 * Recursively print a tree to an output file
 * @param outputFile The file to print to
 * @param node The node to start at
 */
void Tree::printTree(std::ofstream &outputFile, Node *node) {

    if (node == NULL) {
        node = root;
    }

    // LVR
    if (node->left != NULL) {
        printTree(outputFile, node->left);
    }
    outputFile << std::left << std::setw(25) << node->value << std::setw(3) << node->count << std::endl;
    if (node->right != NULL) {
        printTree(outputFile, node->right);
    }

}

/**
 * Pretty print a tree
 * Taken from http://stackoverflow.com/a/26699993/3496078
 * @param outputFile The file to print to
 * @param node The node to start at
 * @param level The indentation level
 */
void Tree::printTreeInOrder(std::ofstream &outputFile, Node *node, int level) {
    if (node == NULL) {
        node = root;
    }
    if (node != NULL) {
        if (node->right) {
            printTreeInOrder(outputFile, node->right, level + 4);
        }
        if (level) {
            outputFile << std::setw(level) << ' ';
        }
        if (node->right) outputFile << " /\n" << std::setw(level) << ' ';
        outputFile << level / 4 << " " << node->value << "\n ";
        if (node->left) {
            outputFile << std::setw(level) << ' ' << " \\\n";
            printTreeInOrder(outputFile, node->left, level + 4);
        }
    }
}

/**
 * Recursively delete a node and its children
 * @param node The node to delete
 */
void Tree::deleteTree(Node *node) {
    // LRV
    if (node->left != NULL) {
        deleteTree(node->left);
    }
    if (node->right != NULL) {
        deleteTree(node->right);
    }
    delete node;
}

/**
 * Find a node by value
 * @param value The value to search for
 * @return The node containing the value
 */
Node *Tree::findNode(TreeType value) {

    Node *currentNode = root;

    while (currentNode != NULL) {
        if (currentNode->value == value) {
            return currentNode;
        }
        if (value < currentNode->value) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    return NULL;
}

/**
 * Delete a node from the tree
 * @param node The node to delete
 */
void Tree::deleteNode(Node *node) {

    // No children
    if (node->left == NULL && node->right == NULL) {
        // Figure out if we're to the left or right of the parent
        if (node->parent->left == node) {
            node->parent->left = NULL;
        } else {
            node->parent->right = NULL;
        }
        delete node;
        return;
    }

    // One child
    if (node->left != NULL && node->right == NULL ||
        node->left == NULL && node->right != NULL) {

        Node *nodeChild;

        // Figure out if the child is on the left or the right
        if (node->left != NULL) {
            nodeChild = node->left;
        } else {
            nodeChild = node->right;
        }

        // Figure out if we're to the left or right of the parent
        if (node->parent->left == node) {
            node->parent->left = nodeChild;
            nodeChild->parent = node->parent;
        } else {
            node->parent->right = nodeChild;
            nodeChild->parent = node->parent;
        }

        delete node;
        return;
    }

    // Two children
    Node *smallestNode = findSmallestNode(node->right);

    // Remove the smallestNode from its parent
    if (smallestNode->parent->left == smallestNode) {
        smallestNode->parent->left = NULL;
    } else {
        smallestNode->parent->right = NULL;
    }

    // Set the smallestNode's parent as the node's parent
    smallestNode->parent = node->parent;

    // Move the nodes children to smallestNode
    smallestNode->left = node->left;
    if (smallestNode->right != smallestNode) {
        smallestNode->right = node->right;
    } else {
        smallestNode->right = NULL;
    }

    smallestNode->left->parent = smallestNode;
    if (smallestNode->right != NULL) {
        smallestNode->right->parent = smallestNode;
    }

    // Set the node's parent to point to smallestNode
    if (node == root) {
        root = smallestNode;
    } else if (node->parent->left == node) {
        node->parent->left = smallestNode;
    } else {
        node->parent->right = smallestNode;
    }

    delete node;

}

/**
 * Find the left-most node from a given node
 * @param node The node to start at
 * @return The left-most node
 */
Node *Tree::findSmallestNode(Node *node) {
    if (node->left != NULL) {
        return findSmallestNode(node->left);
    } else {
        if (node->right != NULL) {
            return findSmallestNode(node->right);
        } else {
            return node;
        }
    }
}

/**
 * Get the number of nodes in the tree
 * @return The number of nodes in the tree
 */
int Tree::getNodeCount() {
    return nodeCount;
}

/**
 * Get the height of the tree
 * @return The height of the tree
 */
int Tree::getHeight() {
    return treeHeight;
}