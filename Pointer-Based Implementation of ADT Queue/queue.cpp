//
// Created by Omar Ashraf on 5/2/2023.
//

#include "queue.h"
#include <iostream>
using namespace std;
template <class T>
queue<T>::queue()
{
    front = NULL;
    rear = NULL;
    capacity = 0;
}

template <class T>
bool queue<T>::isEmpty()
{
    return capacity == 0;
}

template <class T>
void queue<T>::enqueue(T val)
{
    node<T>* newNode = new node<T>;
    newNode->setData(val);
    newNode->setNext(NULL);
    if(isEmpty())                   /// first element to be added.
    {
        front = rear = newNode;
        capacity++;
    }else                           /// first element to be added.
    {
        rear->setNext(newNode);
        rear = newNode;
        capacity++;
    }
}

template <class T>
void queue<T>::dequeue()
{
    if(isEmpty())
    {
        cout << "Empty queue, nothing to delete!!\n";
    }else if(front == rear)
    {
        front = rear = NULL;
        capacity--;
    }else
    {
        node<T>* temp = new node<T>;
        temp = front;
        front = front->getNext();
        temp->setNext(NULL);
        delete temp;
        capacity--;
    }


}

template <class T>
T queue<T>::getFront()
{
    if(isEmpty())
        cout << "cannot get Front\n";
    else
        return front->getData();
}

template <class T>
T queue<T>::getRear()
{
    if(isEmpty())
        cout << "cannot get Rear\n";
    else
        return rear->getData();
}

template <class T>
void queue<T>::print()
{
    node<T>* cur = new node<T>;
    cur = front;
    while(cur != NULL)
    {
        cout << cur->getData() << ' ';
        cur = cur->getNext();
    }
    cout << "\n";
}

template <class T>
void queue<T>::clear()
{
    node<T>* cur = new node<T>;
    while(front != NULL)
    {
        cur = front;
        front = front->getNext();
        delete cur;
    }
    rear->setNext(NULL);
    capacity = 0;
}
template class queue<int>;
template class queue<float>;