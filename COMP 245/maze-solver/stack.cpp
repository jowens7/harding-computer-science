#include "stack.h"
#include <iostream>

Stack::Stack() {
    Head = NULL;
}

Stack::~Stack() {
    while (Head != NULL) {
        Node* temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

bool Stack::Push(Coordinate coordinate) {
    Node *newNode = new Node;

    if (newNode == NULL)
        return true;

    newNode->Element = coordinate;
    newNode->Next = Head;
    Head = newNode;
    return true;
}

Stacktype Stack::Pop() {
    Node* firstNode = Head;
    Stacktype value = Head->Element;
    Head = Head->Next;
    delete firstNode;
    return value;
}

bool Stack::IsEmpty() {
    return Head == NULL;
}
