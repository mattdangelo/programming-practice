class Solution {
public:
    bool recValidPalindrome(string& s, int l, int r, bool skipped) {
        if(l >= r) {
            return true;
        }
        
        if(s[l] == s[r]) {
            return recValidPalindrome(s, l+1, r-1, skipped);
        }
        else {
            if(skipped) {
                return false;
            }   
            
            return recValidPalindrome(s, l+1, r, true) || recValidPalindrome(s, l, r - 1, true);
        }
    }
    
    bool validPalindrome(string s) {
        return recValidPalindrome(s, 0, s.length() - 1, false);
    }
};