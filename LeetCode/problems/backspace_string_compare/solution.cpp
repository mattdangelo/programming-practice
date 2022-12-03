class Solution {
public:
    bool backspaceCompare(string s, string t) {
        std::string s_fixed;
        std::string t_fixed;
        
        for(char c : s) {
            if(c == '#') {
                s_fixed = s_fixed.substr(0, s_fixed.length() - 1);
            }
            else {
                s_fixed += c;
            }
        }
        
        for(char c : t) {
            if(c == '#') {
                t_fixed = t_fixed.substr(0, t_fixed.length() - 1);
            }
            else {
                t_fixed += c;
            }
        }
        
        return s_fixed == t_fixed;
    }
};