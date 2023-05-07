
#include "node.h"
template <class T>
node<T>::node()
{
    next = prev = 0;
}

template <class T>
node<T>::node(T val, node* nxt, node* prv)
{
    data = val;
    next = nxt;
    prev = prv;
}
template class node<int>;