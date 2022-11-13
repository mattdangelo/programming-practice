class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> stack;
        for(char c : s) {
            if(!stack.empty() && stack.top() == c) {
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }

        std::string no_duplicates = "";
        no_duplicates.reserve(stack.size());

        while(!stack.empty()) {
            no_duplicates.push_back(stack.top());
            stack.pop();
        }
        
        std::reverse(no_duplicates.begin(), no_duplicates.end());

        return no_duplicates;
    }
};