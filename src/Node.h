#pragma once

template<class ItemType>
class Node {
private:
    ItemType data;
    Node<ItemType> *prev;
    Node<ItemType> *next;
public:
    Node();

    Node(const ItemType &anItem);

    Node(const ItemType &anItem, Node<ItemType> *prevNodePtr, Node<ItemType> *nextNodePtr);

    void setItem(const ItemType &anItem);

    void setPrev(Node<ItemType> *prevNodePtr);

    void setNext(Node<ItemType> *nextNodePtr);

    ItemType getItem() const;

    Node<ItemType> *getPrev() const;

    Node<ItemType> *getNext() const;
};

template<class ItemType>
Node<ItemType>::Node() : data(0), prev(nullptr), next(nullptr) { }

template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem) : data(anItem), prev(nullptr), next(nullptr) { }

template<class ItemType>
Node<ItemType>::Node(const ItemType &anItem, Node<ItemType> *prevNodePtr, Node<ItemType> *nextNodePtr) : data(anItem),
                                                                                                         prev(prevNodePtr),
                                                                                                         next(nextNodePtr) { }

template<class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem) { data = anItem; }

template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType> *prevNodePtr) { prev = prevNodePtr; }

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr) { next = nextNodePtr; }

template<class ItemType>
ItemType Node<ItemType>::getItem() const { return data; }

template<class ItemType>
Node<ItemType> *Node<ItemType>::getPrev() const { return prev; }

template<class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const { return next; }