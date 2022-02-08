class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char, int> s_m;
        
        for(int i=0;i<s.length();i++) {
            if(s_m.count(s[i])) {
                if(s_m[s[i]] == -1) {
                    s_m.erase(s[i]);
                }
                else {
                   s_m[s[i]]++; 
                }
            }
            else {
                s_m[s[i]] = 1;
            }
            
            if(s_m.count(t[i])) {
                if(s_m[t[i]] == 1) {
                    s_m.erase(t[i]);
                }
                else {
                    s_m[t[i]]--;
                }
            }
            else {
                s_m[t[i]] = -1;
            }
        }
        
        if(s_m.count(t[t.length() - 1])) {
            if(s_m[t[t.length() - 1]] == 1) {
                s_m.erase(t[t.length() - 1]);
            }
            else {
                s_m[t[t.length() - 1]]--;
            }
        }
        else {
            s_m[t[t.length() - 1]] = -1;
        }
        
        return s_m.begin()->first;
    }
};