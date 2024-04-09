class Solution {
private:
    std::stack<int> memory;

    std::pair<int, int> popOperands() {
        std::pair<int, int> values;
        values.first = memory.top();
        memory.pop();
        values.second = memory.top();
        memory.pop();
        return values;
    }

public:
    int evalRPN(vector<string>& tokens) {
        for(std::string s : tokens) {
            if(s == "+") {
                auto operands = popOperands();
                memory.push(operands.second + operands.first);
            }
            else if(s == "-") {
                auto operands = popOperands();
                memory.push(operands.second - operands.first);
            }
            else if(s == "*") {
                auto operands = popOperands();
                memory.push(operands.second * operands.first);
            }
            else if(s == "/") {
                auto operands = popOperands();
                memory.push(operands.second / operands.first);
            }
            else {
                // Just a number, push it onto the stack
                memory.push(stoi(s));
            }
        }

        return memory.top();
    }
};