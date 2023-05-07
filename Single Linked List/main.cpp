#include <iostream>
#include "linkedList.h"
using namespace std;

int main() {

    linkedList<int> li;
    li.addToHead(5);
    li.addToTail(10);
    li.addToPos(1, 6);
    li.addToTail(8);
    li.print();

    /*li.reverse();
    li.print();*/

    li.deleteByValue(6);
    li.deleteFromTail();
    li.deleteFromHead();
    li.print();

    li.isInList(10);
    return 0;
}
