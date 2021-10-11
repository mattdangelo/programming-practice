class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for(char c : s) {
            // Push any opening parenthesis onto the stack
            if(c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else {
                // Check if we can pop - if not, we have too many closing parenthesis and thus s is invalid
                if(!stack.empty()) {
                    char prev = stack.top();
                    stack.pop();
                    // Check if the parenthesis match - if not, s is invalid
                    if((c == ')' && prev != '(') || (c == '}' && prev != '{') || (c == ']' && prev != '[')) {
                        return false;
                    }
                }
                else {
                  return false;  
                }
            }
        }
        return stack.empty();
    }
};
