#include <iostream>

#include "minstack.h"

int main() {
    auto* m = new MinStack();

    m->push(1);
    m->push(2);
    m->push(0);
    m->pop();
    std::cout << m->top() << std::endl;
    std::cout << m->getMin() << std::endl;
}