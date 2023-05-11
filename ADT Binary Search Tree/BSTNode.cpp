#include "BSTNode.h"

template <class T>
BSTNode<T>::BSTNode(T v, BSTNode<T> *l, BSTNode<T> *r)
{
    val = v; left = l; right = r;
}

template <class T>
BSTNode<T>::BSTNode()
{
    left = right = 0;
}

template<class T>
BSTNode<T>::BSTNode(T v)
{
    val = v; left = right = 0;
}
template class BSTNode<int>;