class Solution {
    int stream = 1;
    std::vector<int> stack;
    std::vector<string> res;

    int getFromStream() {
        stream++;
        return stream - 1;
    }

    void push_stack() {
        stack.push_back(getFromStream());
        res.push_back("Push");
    }

    void pop_stack() {
        stack.pop_back();
        res.push_back("Pop");
    }

public:

    vector<string> buildArray(vector<int>& target, int n) {
        stack.reserve(target.size()); 
        int ptr = 0;
        while(target.size() != stack.size()) {
            int goal = target[ptr];
            push_stack();
            while(stack[ptr] != target[ptr]) {
                pop_stack();
                push_stack();
            }
            ptr++;
        }

        return res;
    }
};