//
// Created by Omar Ashraf on 5/2/2023.
//
#include <iostream>
#include <cassert>
#include "queue.h"
using namespace std;
template <class T>
queue<T>::queue()
{
    size = MAX_LEN;
    front = 0;
    capacity = 0;
    rear = MAX_LEN - 1;
    arr = new int [MAX_LEN];
}
template <class T>
queue<T>::queue(int sz)
{
    size = sz;
    front = 0;
    capacity = 0;
    rear = sz - 1;
    arr = new int [sz];
}
template <class T>
bool queue<T>::isEmpty()
{
    return capacity == 0;
}
template <class T>
bool queue<T>::isFull()
{
    return capacity == size;
}
template <class T>
void queue<T>::enqueue(T element)
{
    if(isFull())
    {
        cout << "queue is full!! free some space\n";
    }else
    {
        rear = (rear + 1) % size;
        arr[rear] = element;
        capacity++;
    }
}
template <class T>
void queue<T>::dequeue()
{
    if(isEmpty())
    {
        cout << "queue is empty!! add some elements\n";
    }else
    {
        front = (front + 1) % size;
        capacity--;
    }
}
template <class T>
T queue<T>::getFront()
{
    assert(!isEmpty());
    return arr[front];
}
template <class T>
T queue<T>::getRear()
{
    assert(!isEmpty());
    return arr[rear];
}
template <class T>
void queue<T>::print()
{
    for(int i = front; i != rear; i = (i+1) % size)
    {
        cout << arr[i] << ' ';
    }
    cout << arr[rear];
    cout << "\n";
}
template class queue<int>;