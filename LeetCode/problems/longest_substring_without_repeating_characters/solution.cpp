class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> found;
        int best = 0;
        
        int l = 0;
        int r = 0;
        
        while(r < s.length()) {
            if(found.count(s[r])) {
                // Have seen this value
                while(s[l] != s[r]) {
                    found.erase(s[l]);
                    l++;
                }
                found.erase(s[l]);
                l++;
            }
            else {
                found.insert(s[r]);
                r++;
                if((r - l + 1) > best) {
                    best = (r - l);
                }
            }
        }
        
        return best;
    }
};