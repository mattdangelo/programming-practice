class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length()) {
            return false;
        }
        
        if(s.length() == 0) {
            return true;
        }
        
        int s_ptr = 0;
        int t_ptr = 0;
        
        while(t_ptr < t.length()) {
            if(t[t_ptr] != s[s_ptr]) {
                t_ptr++;
            }
            else {
                t_ptr++;
                s_ptr++;
            }
            
            if(s_ptr == s.length()) {
                return true;
            }
        }
        
        return false;
    }
};