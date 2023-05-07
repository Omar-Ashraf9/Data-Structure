//
// Created by Omar Ashraf on 5/5/2023.
//
#include "arrayList.h"
#include <cmath>
#include <iostream>
using namespace std;

template <class T>
arrayList<T>::arrayList(int size)
{
    maxSize = abs(size);
    arr = new T[maxSize];
    length = 0;
}

template <class T>
bool arrayList<T>::isEmpty()
{
    return length == 0;
}

template <class T>
bool arrayList<T>::isFull()
{
    return length == maxSize;
}

template <class T>
int arrayList<T>::getSize()
{
    return length;
}

template <class T>
void arrayList<T>::print()
{
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}

template <class T>
void arrayList<T>::insertAt(int pos, T val)
{
    if(isFull())
    {
        cout << "List is full!!, free some space..\n";
    }else if(pos < 0 || pos > length)
    {
        cout << "index out of bound..\n";
    }else
    {
        /* shift elements to the right */
        for (int i = length; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = val;
        length++;
    }
}

template <class T>
void arrayList<T>::removeAt(int pos)
{
    if(isEmpty())
    {
        cout << "List is empty!!, nothing to remove..\n";
    }else if(pos < 0 || pos > length)
    {
        cout << "index out of bound..\n";
    }else
    {
        /* shift elements to the left */
        for (int i = pos; i < length; i++)
            arr[i] = arr[i + 1];

        length--;
    }
}

template <class T>
void arrayList<T>::insert(T val)
{
    if (isFull())
        cout << "List is full!!, free some space..\n";
    else
        arr[length++] = val;
}

template <class T>
void arrayList<T>::updateAt(int pos, T val)
{
    if(pos < 0 || pos > length)
        cout << "index out of bound..\n";
    else
        arr[pos] = val;
}

template <class T>
T arrayList<T>::getElement(int pos)
{
    if(pos < 0 || pos > length)
        cout << "index out of bound..\n";
    else
        return arr[pos];
}

template <class T>
arrayList<T>::~arrayList()
{
    delete[] arr;
}

template class arrayList<int>;
template class arrayList<float>;