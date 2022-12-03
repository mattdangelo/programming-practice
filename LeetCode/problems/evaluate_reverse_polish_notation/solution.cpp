class Solution {
private:
    std::pair<int, int> getOperands(std::stack<int>& memory) {
        std::pair<int, int> values;
        values.first = memory.top();
        memory.pop();
        values.second = memory.top();
        memory.pop();
        return values;
    }
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> memory;
        
        for(std::string s : tokens) {
            if(s == "+") {
                auto operands = getOperands(memory);
                memory.push(operands.second + operands.first);
            }
            else if(s == "-") {
                auto operands = getOperands(memory);
                memory.push(operands.second - operands.first);
            }
            else if(s == "*") {
                auto operands = getOperands(memory);
                memory.push(operands.second * operands.first);
            }
            else if(s == "/") {
                auto operands = getOperands(memory);
                memory.push(operands.second / operands.first);
            }
            else {
                memory.push(stoi(s));
            }
        }
        
        return memory.top();
    }
};