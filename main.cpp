#include <iostream>
#include "Stack.h"

int main() {
    const int kobe = 24;

    Stack<int> t;
    t.push(kobe);
    t.push(23);
    std::cout << t.top() << "\n";
    t.pop();
    std::cout << t.top();
    return 0;
}
