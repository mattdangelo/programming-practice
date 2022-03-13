class Solution {
public:
    bool isValid(string s) {
        std::stack<int> p_stack;
        std::unordered_map<char, char> p_pairs = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        
        for(char c : s) {
            if(p_pairs.count(c)) {
                // It's an opening parenthesis
                p_stack.push(c);
            }
            else {
                if(p_stack.size() == 0) {
                    return false;
                }
                
                if(p_pairs.count(p_stack.top()) && p_pairs[p_stack.top()] == c) {
                    p_stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        return p_stack.size() == 0;
    }
};
