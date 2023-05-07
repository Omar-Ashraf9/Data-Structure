#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H

const int MAX_SZ = 1000;

template <class T>
class stack{
private:
    int top;
    T arr[MAX_SZ];

public:
    stack();

    void push(T val);

    void print();

    bool isEmpty();

    void pop();

    T get_Top();
};


#endif //MAIN_CPP_STACK_H
