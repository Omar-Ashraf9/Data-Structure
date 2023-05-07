#include <iostream>
#include "stack.h"
using namespace std;

int main() {

    stack <int> s;
    s.push(100);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.print();

    s.pop();
    s.print();

    cout << s.get_Top();
    return 0;
}
