class Solution {
    std::unordered_set<char> unused;
public:
    bool checkIfPangram(string sentence) {    
        for (char c = 'a'; c <= 'z'; c++) {
            unused.insert(c);
        }
        
        for(char c : sentence) {
            if(unused.count(c)) {
                unused.erase(c);
            }
            
            if(unused.empty()) {
                return true;
            }
        }
        
        return false;
    }
};