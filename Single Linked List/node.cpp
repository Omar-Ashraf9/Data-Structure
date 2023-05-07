#include "node.h"
#include <iostream>
using namespace std;

template <class T>
node<T>::node()
{
    next = 0;
}

template <class T>
node<T>::node(T val, node* ptr)
{
    data = val;
    next = ptr;
}
template class node<int>;