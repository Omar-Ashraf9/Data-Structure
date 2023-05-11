#ifndef ADT_BINARY_SEARCH_TREE_BST_H
#define ADT_BINARY_SEARCH_TREE_BST_H
#include "BSTNode.h"
#include "graphicalTool.h"
template <class T>
class BST {

private:
    BSTNode<T> *root;
    graphicalTool gTool;

protected:
    void preOrder(BSTNode<T> *r);
    void inOrder(BSTNode<T> *r);
    void postOrder(BSTNode<T> *r);
    bool search(BSTNode<T> *p, T v);
    void deleteTree(BSTNode<T> *p);
    std::pair<BSTNode<T> *, BSTNode<T> *> getNode(T val);
    int getHeight(BSTNode<T> *root);
    int getNumberOfNodes(BSTNode<T> *root);
    BSTNode<T> *copyHelper(const BSTNode<T> *source);
    T getSuccessor(BSTNode<T>* pNode);
    void plotTree(BSTNode<T> *root, int h, int H, int mid, int Y);

public:
    BST();
    ~BST();
    bool isEmpty();
    int getHeight()          { getHeight(root);              }
    int getNumberOfNodes()   { getNumberOfNodes(root);       }
    void preOrder()          { preOrder(root);               }
    void inOrder()           { inOrder(root);                }
    void postOrder()         { postOrder(root);              }
    bool search(T v)         { return search(root, v);       }
    void deleteNode(T del);
    void insert(T v);
    void plot();
};




#endif //ADT_BINARY_SEARCH_TREE_BST_H
