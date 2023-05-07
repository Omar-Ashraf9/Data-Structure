#include <iostream>
#include "dLinkedList.h"
using namespace std;
int main() {

    dLinkedList<int> dl;
    dl.addToHead(5);
    dl.addToTail(10);
    dl.addToPos(1, 6);
    dl.addToTail(8);
    dl.print();

    dl.reversePrint();


    dl.deleteByValue(6);
    dl.deleteFromTail();
    dl.deleteFromHead();
    dl.print();

    bool res = dl.isInList(10);
    if(res)
        cout << "The element exists in the linked list\n";
    else
        cout << "The element doesn't exist in the linked list\n";

    return 0;
}
