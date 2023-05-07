//
// Created by Omar Ashraf on 5/2/2023.
//
#ifndef POINTER_BASED_IMPLEMENTATION_OF_ADT_STACK_STACK_H
#define POINTER_BASED_IMPLEMENTATION_OF_ADT_STACK_STACK_H
#include "node.h"
template <class T>
class stack {
private:
    node<T>* top;
public:
    stack();
    void push(T val);
    void print();
    bool isEmpty();
    void pop();
    T getTop();
};


#endif //POINTER_BASED_IMPLEMENTATION_OF_ADT_STACK_STACK_H
