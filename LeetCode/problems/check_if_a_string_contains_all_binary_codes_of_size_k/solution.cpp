class Solution {
public:
    bool hasAllCodes(string s, int k) {
        std::unordered_set<std::string> found;
        
        int left = 0;
        while(left + k <= s.length()) {
            found.insert(s.substr(left, k));
            left++;
        }
        
        return found.size() == pow(2, k);
    }
};