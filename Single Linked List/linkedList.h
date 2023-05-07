#ifndef SINGLE_LINKED_LIST_LINKEDLIST_H
#define SINGLE_LINKED_LIST_LINKEDLIST_H
#include "node.h"

template <class T>
class linkedList {
private:
    node<T> *head, *tail;
    int length;
public:
    linkedList();
    ~linkedList();
    bool isEmpty();
    bool isInList(T val);
    void addToHead(T val);
    void addToTail(T val);
    void addToPos(int idx, T val);
    void deleteFromHead();
    void deleteFromTail();
    void deleteByValue(T val);
    void reverse();
    void print();
};
#endif //SINGLE_LINKED_LIST_LINKEDLIST_H
