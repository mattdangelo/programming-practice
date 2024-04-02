class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Early exist - strings not the same size
        if(s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, char> s_mapping;
        std::unordered_map<char, char> t_mapping;

        for(int i=0;i<s.length();i++) {
            if(s_mapping.count(s[i])) {
                if(s_mapping[s[i]] != t[i]) {
                    return false;
                }
            }
            else if(t_mapping.count(t[i])) {
                if(t_mapping[t[i]] != s[i]) {
                    return false;
                }
            }
            else {
                s_mapping[s[i]] = t[i];
                t_mapping[t[i]] = s[i];
            }
        }

        return true;
    }
};
