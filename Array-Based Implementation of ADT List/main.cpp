#include <iostream>
#include "arrayList.h"
using namespace std;

int main() {

    arrayList<int> ar;
    ar.insert(5);
    ar.insert(10);
    ar.insert(15);
    ar.insert(20);
    ar.insert(21);
    ar.insert(22);
    ar.insert(23);

    ar.print();
    ar.insertAt(2, 19);
    ar.print();

    ar.removeAt(2);
    ar.print();

    cout << "Size of the list is: " << ar.getSize() << "\n";

    ar.updateAt(0, 8);
    ar.print();
    return 0;
}
