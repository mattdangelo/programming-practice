class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int best = 0;
        for(char c : s) {
            if(c == '(') {
                count++;
                best = std::max(best, count);
            }
            else if(c == ')') {
                count--;
            }
        }

        return best;
    }
};
