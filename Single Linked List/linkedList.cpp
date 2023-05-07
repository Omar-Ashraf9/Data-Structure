#include "linkedList.h"
#include <iostream>
using namespace std;

template<class T>
linkedList<T>::linkedList()
{
    head = tail = 0;
    length = 0;
}

template<class T>
linkedList<T>::~linkedList()
{
    for(node<T> *p; !isEmpty();)
    {
        p = head->getNext();
        delete head;
        head = p;
        length--;
    }
}

template<class T>
void linkedList<T>::deleteByValue(T val)
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
        delete tmp;
        length--;
    }else                               /* more than one node and a non-head node is deleted */
    {
        node<T> *cur, *pre;
        pre = head, cur = head->getNext();

        while(cur != 0 && cur->getData() != val)
            pre = cur, cur = cur->getNext();

        if(cur == 0)
            cout << "Element not found..\n";
        else
        {
            pre->setNext(cur->getNext());
            if(cur == tail)
                tail = pre;
            delete cur;
            length--;
        }
    }
}

template<class T>
void linkedList<T>::deleteFromTail()
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
        node<T> *tmp;
        /// Find the predecessor of the tail.
        for(tmp = head; tmp->getNext() != tail; tmp = tmp->getNext());
        delete tail;
        tail = tmp;
        tmp->setNext(0);
        length--;
    }
}

template<class T>
void linkedList<T>::deleteFromHead()
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
        delete tmp;
        length--;
    }
}

template<class T>
void linkedList<T>::addToPos(int idx, T val)
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

        node<T> *newNode = new node(val, curr->getNext());
        curr->setNext(newNode);
        length++;
    }
}

template<class T>
void linkedList<T>::addToTail(T val)
{
    if(tail != 0)
    {
        tail->setNext(new node(val));
        tail = tail->getNext();
    }else
    {
        head = tail = new node(val);
    }
    length++;
}

template<class T>
void linkedList<T>::addToHead(T val)
{
    head = new node(val, head);
    if(tail == 0)
        tail = head;
    length++;
}

template<class T>
bool linkedList<T>::isEmpty()
{
    return length == 0;
}

template<class T>
bool linkedList<T>::isInList(T val)
{
    node<T> *tmp = head;
    while(tmp != 0 && tmp->getData() != val)
        tmp = tmp->getNext();
    if(tmp != 0)
    {
        cout << "The element " << val << " exists in the linked list\n";
        return true;
    }else
    {
        cout << "The element " << val << " doesn't exist in the linked list\n";
        return false;
    }
}

template<class T>
void linkedList<T>::print()
{
    cout << "[ ";
    if(!length)
        cout << "Empty List... ";
    else
    {
        node<T> *cur = head;
        while (cur != NULL) {
            std::cout << cur->getData() << ' ';
            cur = cur->getNext();
        }
        delete cur;
    }
    cout << "]\n";
}

template<class T>
void linkedList<T>::reverse()
{
    node<T> *prev, *curt, *next;
    prev = NULL;
    curt = head;
    next = curt->getNext();
    while(next != NULL)
    {
        next = curt->getNext();
        curt->setNext(prev);
        prev = curt;
        curt = next;
    }
    head = prev;
}
template class linkedList<int>;