class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag_count;
        for(char c : magazine) {
            if(mag_count.find(c) == mag_count.end()) {
                mag_count[c] = 1;
            }
            else {
                mag_count[c] = mag_count[c] + 1;
            }
        }
        
        for(char c : ransomNote) {
            if(mag_count.find(c) == mag_count.end()) {
                return false;
            }
            else {
                mag_count[c] = mag_count[c] - 1;
                if(mag_count[c] == 0) {
                    mag_count.erase(c);
                }
            }
        }
        
        return true;
    }
};