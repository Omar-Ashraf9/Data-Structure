//
// Created by Omar Ashraf on 5/2/2023.
//
#ifndef QUEUE_WITH_CIRCULAR_ARRAY_QUEUE_H
#define QUEUE_WITH_CIRCULAR_ARRAY_QUEUE_H
const int MAX_LEN = 105;
template <class T>
class queue {
private:
    int front;
    int rear;
    int capacity;
    int size;
    T *arr;
public:
    queue();
    explicit queue(int sz);
    bool isEmpty();
    bool isFull();
    void enqueue(T element);
    void dequeue();
    T getFront();
    T getRear();
    void print();
};


#endif //QUEUE_WITH_CIRCULAR_ARRAY_QUEUE_H
