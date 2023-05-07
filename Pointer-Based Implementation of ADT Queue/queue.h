//
// Created by Omar Ashraf on 5/2/2023.
//

#ifndef QUEUE_WITH_LINKED_LIST_QUEUE_H
#define QUEUE_WITH_LINKED_LIST_QUEUE_H
#include "node.h"

template <class T>
class queue {
private:
    node<T>* front;
    node<T>* rear;
    int capacity;
public:
    queue();
    bool isEmpty();
    void enqueue(T val);
    void dequeue();
    T getFront();
    T getRear();
    void print();
    void clear();
};

#endif //QUEUE_WITH_LINKED_LIST_QUEUE_H
