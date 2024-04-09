class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_set<char> used;
        std::unordered_map<char, char> charmap;
        
        for(int i=0;i<s.length();i++) {
            if(charmap.count(s[i]) == 0) {
                if(used.count(t[i]) == 0) {
                    charmap[s[i]] = t[i];
                    used.insert(t[i]);
                }
                else {
                    return false;
                }
            }
            else {
                if(charmap[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};