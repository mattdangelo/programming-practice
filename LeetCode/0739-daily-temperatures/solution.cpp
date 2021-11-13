class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
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
};
