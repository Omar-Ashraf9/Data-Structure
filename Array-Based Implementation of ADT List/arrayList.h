//
// Created by Omar Ashraf on 5/5/2023.
//
#ifndef ARRAY_BASED_LIST_IMPLEMENTATION_ARRAYLIST_H
#define ARRAY_BASED_LIST_IMPLEMENTATION_ARRAYLIST_H

template <class T>
class arrayList {
private:
    T *arr;
    int maxSize;
    int length;
public:
    arrayList(int size = 100);
    ~arrayList();
    bool isEmpty();
    bool isFull();
    int getSize();
    void print();
    void insertAt(int pos, T val);
    void removeAt(int pos);
    void updateAt(int pos, T val);
    void insert(T val);
    T getElement(int pos);

};
#endif //ARRAY_BASED_LIST_IMPLEMENTATION_ARRAYLIST_H
