#include "stack.h"
#include <iostream>
using namespace std;

template <class T>
stack<T>::stack()
{
    top = -1;
}

template <class T>
void stack<T>::push(T val)
{
    if(top >= MAX_SZ - 1)
        cout << "Sorry, Stack is Full!!\n";
    else
        arr[++top] = val;
}

template <class T>
void stack<T>::print()
{
    for(int i = top; i >= 0; i--)
    {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}

template <class T>
bool stack<T>::isEmpty()
{
    return (top == -1);
}

template <class T>
void stack<T>::pop()
{
    if(isEmpty())
        cout << "Stack is empty!!\n";
    else
        top--;
}

template <class T>
T stack<T>::get_Top()
{
    if(isEmpty())
        cout << "Stack is empty!!\n";
    else
        return arr[top--];
}
template class stack<int>;
template class stack<float>;