#include <iostream>
#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::stack<int> stack;
    std::vector<int> ret(temperatures.size());
    for(int i = 0; i < temperatures.size(); i++) {
        while(!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
            int idx = stack.top();
            stack.pop();
            ret[idx] = i - idx;
        }
        stack.push(i);
    }
    return ret;
}

int main() {
    std::vector<int> input = { 73, 74, 75, 71, 69, 72, 76, 73 };
    auto res = dailyTemperatures(input);

    for (int i : res) {
        std::cout << i << " ";
    }

    return 0;
}