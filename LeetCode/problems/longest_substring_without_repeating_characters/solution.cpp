class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        
        unordered_set<char> found;

        int best = 0;
        while(right < s.length()) {
            if(found.count(s[right]) > 0) {
                while(s[left] != s[right]) {
                    found.erase(s[left]);
                    left++;
                }
                
                found.erase(s[left]);
                left++;
            }
            else {
                found.insert(s[right]);
                right++;
                best = max(best, right - left);
            }
        }
        
        return best;
    }
};