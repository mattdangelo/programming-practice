class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ptr = 0;
        int t_ptr = 0;
        
        while(t_ptr < t.length()) {
            if(s[s_ptr] == t[t_ptr]) {
                s_ptr++;
                t_ptr++;
            }
            else {
                t_ptr++;
            }
            
            if(s_ptr == s.length()) {
                return true;
            }
        }
        
        return s == "";
    }
};
