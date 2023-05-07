#ifndef SINGLE_LINKED_LIST_NODE_H
#define SINGLE_LINKED_LIST_NODE_H


template <class T>
class node {
private:
    T data;
    node* next;
public:
    node();
    node(T val, node* ptr = 0);

    T getData() const {return data;}
    node *getNext() const {return next;}

    void setData(T data) {node::data = data;}
    void setNext(node *next) {node::next = next;}

};


#endif //SINGLE_LINKED_LIST_NODE_H
