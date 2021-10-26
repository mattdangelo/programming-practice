#include "minstack.h"

MinStack::MinStack() {

}

void MinStack::push(int val) {
    values.push(val);
    if(mins.empty()) {
        mins.push(val);
    }
    else {
        mins.push(mins.top() > val ? val : mins.top());
    }
}

void MinStack::pop() {
    values.pop();
    mins.pop();
}

int MinStack::top() {
    return values.top();
}

int MinStack::getMin() {
    return mins.top();
}