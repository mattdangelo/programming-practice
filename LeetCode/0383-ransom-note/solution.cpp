class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> counts;
        for(char c : magazine) {
            if(counts.count(c)) {
                counts[c]++;
            }
            else {
                counts[c] = 1;
            }
        }
        
        for(char c : ransomNote) {
            if(!counts.count(c)) {
                return false;
            }
            else {
                counts[c]--;
                if(counts[c] == 0) {
                    counts.erase(c);
                }
            }
        }
        
        return true;
    }
};
