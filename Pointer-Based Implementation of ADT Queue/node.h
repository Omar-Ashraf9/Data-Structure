//
// Created by Omar Ashraf on 5/2/2023.
//

#ifndef QUEUE_WITH_LINKED_LIST_NODE_H
#define QUEUE_WITH_LINKED_LIST_NODE_H

template <class T>
class node {
private:
    T data;
    node* next;
public:
    node();
    node(T data);

    void setData(T data) {node::data = data;}
    void setNext(node *next) {node::next = next;}

    T getData() const {return data;}
    node *getNext() const {return next;}
};


#endif //QUEUE_WITH_LINKED_LIST_NODE_H
