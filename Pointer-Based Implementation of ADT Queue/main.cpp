#include <iostream>
#include "queue.h"
using namespace std;

int main() {

    queue <int> q;
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.print();

    q.dequeue();
    q.dequeue();

    q.print();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear:  " << q.getRear() << endl;

    q.enqueue(0);
    q.enqueue(1);

    q.print();
    return 0;
}
