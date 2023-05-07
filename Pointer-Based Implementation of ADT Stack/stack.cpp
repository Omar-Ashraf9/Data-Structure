//
// Created by Omar Ashraf on 5/2/2023.
//

#include "stack.h"
#include "node.h"
#include <iostream>
using namespace std;

template <class T>
stack<T> ::stack() { top = NULL; }

template <class T>
void stack<T>::push(T val)
{
    node<T>* newNode = new node<T>;
    newNode->setData(val);
    newNode->setNext(top);
    top = newNode;
}
template <class T>
bool stack<T>::isEmpty()
{
    return top == NULL;
}
template <class T>
void stack<T>::pop()
{
    if(isEmpty())
        cout << "Stack is empty!!!\n";
    else
    {
        node<T> *temp = top;
        top = top->getNext();
        //temp = temp->setNext(NULL);
        delete temp;
    }
}
template <class T>
T stack<T>::getTop()
{
    if(isEmpty())
        cout << "Stack is empty!!!\n";
    else
    {
        T ret = top->getData();
        node<T> *temp = top;
        top = top->getNext();
        //temp = temp->next = NULL;
        delete temp;
        return ret;
    }
}
template <class T>
void stack<T>::print()
{
    node<T>* cur = top;
    while(cur != NULL)
    {
        cout << cur->getData() << ' ';
        cur = cur->getNext();
    }
    cout << "\n";
}
template class stack<int>;
template class stack<float>;