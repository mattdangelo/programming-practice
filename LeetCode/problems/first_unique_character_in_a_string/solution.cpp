#define ASCII_OFFSET 97

class Solution {
    int counts[26];
public:
    int firstUniqChar(string s) {
        // First pass, get the counts of all characters in the string s
        for(char c : s) {
            counts[c - ASCII_OFFSET]++;
        }

        // Second pass, find the first char with a count of 1 and return the index
        for(int i=0;i<s.length();i++) {
            if(counts[s[i] - ASCII_OFFSET] == 1) {
                return i;
            }
        }

        return -1;
    }
};