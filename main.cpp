#include <iostream>
#include "Stack.h"

int main() {
    const int kobe = 24;
    int nonconstvar = 23;

    Stack<int> t;
    t.push(kobe);
    t.push(23);
    t.push(nonconstvar);
    t.print();
    t.pop();
    t.print();
    t.pop();
    t.print();
    return 0;
}
