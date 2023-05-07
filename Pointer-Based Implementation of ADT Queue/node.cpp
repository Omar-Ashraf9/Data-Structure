//
// Created by Omar Ashraf on 5/2/2023.
//

#include "node.h"
#include <iostream>
using namespace std;

template<class T>
node<T> :: node()
{
    data = 0;
    next = NULL;
}
template<class T>
node<T> :: node(T data)
{
    this->data = data;
    this->next = NULL;
}
template class node<int>;
template class node<float>;