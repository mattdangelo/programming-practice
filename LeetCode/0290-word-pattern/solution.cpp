class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_set<char> used; 
        std::unordered_map<std::string, char> map;
        int ptr = 0;
        std::string buffer;
        for(int i=0;i<pattern.length();i++) {
            buffer.clear();
            for(;ptr<s.length();ptr++) {
                if(s[ptr] == ' ') {
                    ptr++;
                    break;
                }
                else {
                    buffer += s[ptr];
                }
            }
            
            if(buffer == "") {
                return false;
            }
            
            if(map.count(buffer)) {
                if(pattern[i] != map[buffer]) {
                    return false;
                }
            }
            else {
                if(used.count(pattern[i])) {
                    return false;
                }
                else {
                    used.insert(pattern[i]);
                    map[buffer] = pattern[i];
                }
            }
        }
        
        return ptr >= s.length();
    }
};
