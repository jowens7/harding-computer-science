// Jerred Shepherd
// 10-19-2016

#include "List.h"
#include <iostream>

/*
 * Constructor
 * Create a new list with the head as null
 */
List::List() {
    Head = NULL;
}

/*
 * Destructor
 * Go through the list, delete all nodes
 */
List::~List() {
    while (Head != NULL) {
        Node *Temp = Head->nextNode;
        delete Head;
        Head = Temp;
    }
}

/*
 * Insert a node into the list, sorted by std::string#compare
 * @param value The value to be inserted into the list
 * @return Whether or not memory allocation/insertion was successful
 */
bool List::Insert(Type value) {
    Node *newNode = new Node;

    if (newNode == NULL)
        return false;

    newNode->value = value;

    // Check if the list is empty
    if (Head == NULL) {
        Head = newNode;
        newNode->lastNode = NULL;
        newNode->nextNode = NULL;
        return true;
    }

    Node* InsertionPoint = Head;

    while (InsertionPoint != NULL) {
        if (value.compare(InsertionPoint->value) < 0 || value.compare(InsertionPoint->value) == 0) {
            // Value to insert is lesser or equal, put it in front of the current point
            newNode->lastNode = InsertionPoint->lastNode;
            InsertionPoint->lastNode->nextNode = newNode;
            InsertionPoint->lastNode = newNode;
            newNode->nextNode = InsertionPoint;
            return true;
        } else if (InsertionPoint->nextNode == NULL) {
            // We're at the end of the list, let's put it there
            InsertionPoint->nextNode = newNode;
            newNode->lastNode = InsertionPoint;
            newNode->nextNode = NULL;
            return true;
        }
        InsertionPoint = InsertionPoint->nextNode;
    }
    return false;
}

/*
 * Print the value of all nodes in the list
 */
void List::Print() {
    Node *currentNode = Head;
    while (currentNode != NULL) {
        std::cout << currentNode->value << std::endl;
        currentNode = currentNode->nextNode;
    }
}

/*
 * Delete a node in the list
 * @param value The value to delete
 * @return Whether or not the value was found
 */
bool List::Delete(Type value) {
    Node *currentNode = Head;
    while (currentNode != NULL) {
        if (currentNode->value == value) {
            if (Head == currentNode) {
                Head->nextNode->lastNode = NULL;
                Head = Head->nextNode;
                delete currentNode;
                return true;
            }

            if (currentNode->nextNode == NULL) {
                currentNode->lastNode->nextNode = NULL;
                delete currentNode;
                return true;
            }

            currentNode->nextNode->lastNode = currentNode->lastNode;
            currentNode->lastNode->nextNode = currentNode->nextNode;
            delete currentNode;
            return true;
        }
        currentNode = currentNode->nextNode;
    }
    return false;
}

/*
 * Edit an item in the list. This is done by deleting an inserting a node.
 * @param oldValue The value to edit
 * @param newValue The new value to insert
 * @return Whether or not the value was found
 */
bool List::Edit(Type oldValue, Type newValue) {
    Node *currentNode = Head;
    while (currentNode != NULL) {
        if (currentNode->value == oldValue) {
            Delete(oldValue);
            Insert(newValue);
            return true;
        }
        currentNode = currentNode->nextNode;
    }
    return false;
}
