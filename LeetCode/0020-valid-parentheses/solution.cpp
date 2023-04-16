class Solution {
    const std::unordered_map<char, char> opp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    std::stack<char> stack;
public:
    bool isValid(string s) {
        for(char c : s) {
            if(opp.count(c)) {
                // Opening Brace
                stack.push(c);
            }
            else {
                // Closing Brace
                if(stack.empty() || c != opp.at(stack.top())) {
                    return false;
                }
                else {
                    stack.pop();
                }
            }
        }

        return stack.empty();
    }
};
