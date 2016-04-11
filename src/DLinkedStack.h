#pragma once

#include "StackInterface.h"
#include "Node.h"
#include <vector>
#include <cassert>

using namespace std;

template<class ItemType>
class DLinkedStack : public StackInterface<ItemType> {
private:
    Node<ItemType> *headPtr;    // Pointer to first node in the chain;
    Node<ItemType> *topPtr;    // Pointer to (last) node in the chain that contains the stack's top
public:

    DLinkedStack();

    DLinkedStack(const DLinkedStack<ItemType> &aStack);    // Copy constructor

    virtual ~ DLinkedStack();    // Destructor

    Node<ItemType> *getPointerTo(const ItemType &target) const;

    bool isEmpty() const;

    bool push(const ItemType &newItem);

    bool pop();

    ItemType peek() const;

    vector<ItemType> toVector() const;

    Node<ItemType> *getHeadPTR() const;

    Node<ItemType> *getTopPTR() const;
};

template<class ItemType>
DLinkedStack<ItemType>::DLinkedStack() : headPtr(nullptr), topPtr(nullptr) {
}

template<class ItemType>
DLinkedStack<ItemType>::DLinkedStack(const DLinkedStack<ItemType> &aStack) {
    //TODO - Implement the copy constructor
    Node<ItemType> *defaultPtr = headPtr;
    if (defaultPtr == nullptr)
        headPtr = nullptr;
    else {
        headPtr = new Node<ItemType>();
        headPtr->setItem(defaultPtr->getItem());
        Node<ItemType> *newPtr = headPtr;
        defaultPtr = defaultPtr->getNext();

        while (defaultPtr != nullptr) {
            ItemType nextItem = defaultPtr->getItem();
            Node<ItemType> *nodePtr = new Node<ItemType>(nextItem);
            newPtr->setNext(nodePtr);
            newPtr = newPtr->getNext();
            defaultPtr = defaultPtr->getNext();
        }
        newPtr->setNext(nullptr);
    }
}

template<class ItemType>
DLinkedStack<ItemType>::~DLinkedStack() {
    //TODO - Implement the destructor
    Node<ItemType> *deletePtr = headPtr;
    while (headPtr != nullptr) {
        headPtr = headPtr->getNext();
        deletePtr->setNext(nullptr);
        delete deletePtr;
        deletePtr = headPtr;
    }
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getPointerTo(const ItemType &target) const {
    //TODO - Return the Node pointer that contains the target(return nullptr if not found)
    Node<ItemType> *newPtr = headPtr;
    while ((newPtr != nullptr)) {
        if (target == newPtr->getItem()) {
            return newPtr;
        }
        newPtr = newPtr->getNext();
    }
    return nullptr;
}

template<class ItemType>
bool DLinkedStack<ItemType>::isEmpty() const {
    //TODO - Return True if the list is empty
    return headPtr == nullptr;
}

template<class ItemType>
bool DLinkedStack<ItemType>::push(const ItemType &newItem) {
    //TODO - Push an item on the Doubly Linked Stack
    if (isEmpty()) {
        Node<ItemType> *nodePtr = new Node<ItemType>();
        nodePtr->setItem(newItem);
        headPtr = nodePtr;
        topPtr = nodePtr;
        return true;
    }
    else {
        Node<ItemType> *nodePtr = new Node<ItemType>();
        nodePtr->setItem(newItem);
        topPtr->setNext(nodePtr);
        nodePtr->setPrev(topPtr);
        nodePtr->setNext(nullptr);
        topPtr=nodePtr;
        return true;
    }
    return false;
}

template<class ItemType>
bool DLinkedStack<ItemType>::pop() {
    //TODO - Pop an item from the stack - Return true if successful
    Node<ItemType> *newPtr = headPtr;
    if (isEmpty()) {
        return false;

    } else{
        topPtr=topPtr->getPrev();
        newPtr->setNext(NULL);
        return true;
    }
}

template<class ItemType>
ItemType DLinkedStack<ItemType>::peek() const {//Assume this never fails.
    //TODO - return the element stored at the top of the stack (topPtr)
    //return 0;//garbage
    return topPtr->getItem();
}

template<class ItemType>
vector<ItemType> DLinkedStack<ItemType>::toVector() const {
    // DO NOT MODIFY THIS FUNCTION
    vector<ItemType> returnVector;
    // Put stack items into a vector in top to bottom order
    Node<ItemType> *curPtr = topPtr;
    while (curPtr != nullptr) {
        returnVector.push_back(curPtr->getItem());
        curPtr = curPtr->getPrev();
    }
    return returnVector;
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getHeadPTR() const {
    // DO NOT MODIFY THIS FUNCTION
    return headPtr;
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getTopPTR() const {
    // DO NOT MODIFY THIS FUNCTION
    return topPtr;
}
