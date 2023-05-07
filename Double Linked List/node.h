#ifndef DOUBLE_LINKED_LIST_NODE_H
#define DOUBLE_LINKED_LIST_NODE_H

template <class T>
class node {
private:
    T data;
    node* next;
    node* prev;
public:
    node();
    node(T val, node* nxt = 0, node* prv = 0);

    T getData() const {return data;}
    node *getNext() const {return next;}
    node *getPrev() const {return prev;}

    void setData(T data) {node::data = data;}
    void setNext(node *next) {node::next = next;}
    void setPrev(node *prev) {node::prev = prev;}

};



#endif //DOUBLE_LINKED_LIST_NODE_H
