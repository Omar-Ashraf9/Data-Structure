#ifndef ADT_BINARY_SEARCH_TREE_BSTNODE_H
#define ADT_BINARY_SEARCH_TREE_BSTNODE_H

template <class T>
class BSTNode {
private:
    T val;
    BSTNode<T> *left, *right;
public:
    BSTNode();
    BSTNode(T v);
    BSTNode(T val, BSTNode<T> *left, BSTNode<T> *right);

    T getVal() const {return val;}
    BSTNode<T> *getLeft() const {return left;}
    BSTNode<T> *getRight() const {return right;}

    void setVal(T val) {BSTNode::val = val;}
    void setLeft(BSTNode<T> *left) {BSTNode::left = left;}
    void setRight(BSTNode<T> *right) {BSTNode::right = right;}
};




#endif //ADT_BINARY_SEARCH_TREE_BSTNODE_H
