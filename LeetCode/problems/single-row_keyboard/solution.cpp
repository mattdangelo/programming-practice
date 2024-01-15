#define ASCII_OFFSET 97

class Solution {
    int mapping[26] = {};
public:
    int calculateTime(string keyboard, string word) {
        for(int i=0;i<keyboard.length();i++) {
            mapping[keyboard[i] - ASCII_OFFSET] = i;
        }

        int total = 0;
        int last = 0;
        for(char c : word) {
            total += abs(last - mapping[c - ASCII_OFFSET]);
            last = mapping[c - ASCII_OFFSET];
        }

        return total;
    }
};