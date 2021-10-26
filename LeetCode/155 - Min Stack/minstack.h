#ifndef README_MD_MINSTACK_H
#define README_MD_MINSTACK_H

#include <stack>

class MinStack {
public:
    MinStack();
    void push(int val);
    void pop();
    int top();
    int getMin();

private:
    std::stack<int> values;
    std::stack<int> mins;
};

#endif //README_MD_MINSTACK_H
