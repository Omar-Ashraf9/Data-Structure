#include <iostream>
#include "dLinkedList.h"
using namespace std;
template<class T>
dLinkedList<T>::dLinkedList()
{
    head = tail = 0;
    length = 0;
}

template<class T>
dLinkedList<T>::~dLinkedList()
{
    node<T> *p;
    while(head != 0)
    {
        p = head;
        head = head->getNext();
        delete p;
    }
    tail = 0;
    length = 0;
    /*for(node<T> *p; !isEmpty(); p = head->getNext())
    {
        delete head;
        head = p;
        length--;
    }*/
}

template<class T>
void dLinkedList<T>::deleteByValue(T val)
{
    if(isEmpty())
        cout << "Empty list!... nothing to remove\n";
    else if(head->getData() == val && head == tail) /* Only one node in the list */
    {
        delete head;
        head = tail = 0;
        length--;
    }else if(head->getData() == val)          /* more than one node and the old head is deleted */
    {
        node<T> *tmp = head;
        head = head->getNext();
        head->setPrev(0);
        delete tmp;
        length--;
    }else                               /* more than one node and a non-head node is deleted */
    {
        node<T> *cur = head->getNext();

        while(cur != 0 && cur->getData() != val)
            cur = cur->getNext();

        if(cur == 0)
            cout << "Element not found..\n";
        else
        {
            cur->getPrev()->setNext(cur->getNext());
            cur->getNext()->setPrev(cur->getPrev());
            if(cur == tail)
            {
                tail = tail->getPrev();
                tail->setNext(0);
            }
            delete cur;
            length--;
        }
    }
}

template<class T>
void dLinkedList<T>::deleteFromTail()
{
    if(isEmpty())
        cout << "Empty list!... nothing to remove\n";
    else if(length == 1)
    {
        delete head;
        head = tail = 0;
        length--;
    }else
    {
        node<T> *tmp = tail;
        tail = tail->getPrev();
        tail->setNext(0);
        delete tmp;
        length--;
    }
}

template<class T>
void dLinkedList<T>::deleteFromHead()
{
    if(isEmpty())
        cout << "Empty list!... nothing to remove\n";
    else if(length == 1)
    {
        delete head;
        head = tail = 0;
        length--;
    }else
    {
        node<T> *tmp = head;
        head = head->getNext();
        head->setPrev(0);
        delete tmp;
        length--;
    }
}

template<class T>
void dLinkedList<T>::addToPos(int idx, T val)
{
    if(idx == 0)
        addToHead(val);
    else if(idx == length)
        addToTail(val);
    else
    {
        node<T> *curr = head;

        for(int i = 1; i < idx; i++)
            curr = curr->getNext();

        node<T> *newNode = new node(val, curr->getNext(), curr);
        curr->setNext(newNode);
        newNode->getNext()->setPrev(newNode);
        length++;
    }
}

template<class T>
void dLinkedList<T>::addToTail(T val)
{
    if(tail != 0)
    {
        tail = new node<T>(val, 0, tail);
        tail->getPrev()->setNext(tail);
    }else
    {
        head = tail = new node<T>(val);
    }
    length++;
}

template<class T>
void dLinkedList<T>::addToHead(T val)
{
    /*head = new node<T>(val, head);
    if(length)
        head->getNext()->setPrev(head);
    if(tail == 0)
        tail = head;
    length++;*/
    if(head != 0)
    {
        head = new node<T>(val, head);
        head->getNext()->setPrev(head);
    }else
    {
        head = tail = new node<T>(val);
    }
    length++;
}

template<class T>
bool dLinkedList<T>::isEmpty()
{
    return length == 0;
}

template<class T>
bool dLinkedList<T>::isInList(T val)
{
    bool found = false;
    node<T> *tmp = head;
    while (tmp != 0 && tmp->getData() != val)
        tmp = tmp->getNext();
    if (tmp != 0)
        found = true;
    else
        found = false;
    return found;
}

template<class T>
void dLinkedList<T>::print()
{
    cout << "[ ";
    if(!length)
        cout << "Empty List... ";
    else
    {
        node<T> *cur = head;
        while (cur != NULL) {
            cout << cur->getData() << ' ';
            cur = cur->getNext();
        }
        delete cur;
    }
    cout << "]\n";
}

template<class T>
void dLinkedList<T>::reversePrint()
{
    cout << "[ ";
    if(!length)
        cout << "Empty List... ";
    else
    {
        node<T> *cur = tail;
        while (cur != NULL) {
            cout << cur->getData() << ' ';
            cur = cur->getPrev();
        }
        delete cur;
    }
    cout << "]\n";
}
template class dLinkedList<int>;