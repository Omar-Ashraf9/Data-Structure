
#ifndef DOUBLE_LINKED_LIST_DLINKEDLIST_H
#define DOUBLE_LINKED_LIST_DLINKEDLIST_H

#include "node.h"
template <class T>
class dLinkedList {
private:
    node<T> *head, *tail;
    int length;
public:
    dLinkedList();
    ~dLinkedList();
    bool isEmpty();
    bool isInList(T val);
    void addToHead(T val);
    void addToTail(T val);
    void addToPos(int idx, T val);
    void deleteFromHead();
    void deleteFromTail();
    void deleteByValue(T val);
    void reversePrint();
    void print();
};


#endif //DOUBLE_LINKED_LIST_DLINKEDLIST_H
