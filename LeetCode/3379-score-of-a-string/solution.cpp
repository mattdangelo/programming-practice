class Solution {
public:
    int scoreOfString(string s) {
        int total = 0;
        for(int i=1;i<s.length();i++) {
            total += abs(s[i - 1] - s[i]);
        }
        return total;
    }
};
