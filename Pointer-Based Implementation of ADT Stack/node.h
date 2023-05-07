//
// Created by Omar Ashraf on 5/2/2023.
//
#ifndef POINTER_BASED_IMPLEMENTATION_OF_ADT_STACK_NODE_H
#define POINTER_BASED_IMPLEMENTATION_OF_ADT_STACK_NODE_H

template <class T>
class node {
private:
    T data;
    node* next;
public:
    node();
    node(T data);

    T getData() const {return data;}
    node *getNext() const {return next;}

    void setData(T data) {node::data = data;}
    void setNext(node *next) {node::next = next;}
};


#endif //POINTER_BASED_IMPLEMENTATION_OF_ADT_STACK_NODE_H
