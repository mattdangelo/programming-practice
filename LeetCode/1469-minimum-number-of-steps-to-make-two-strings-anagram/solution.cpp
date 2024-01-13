#define ASCII_OFFSET 97
#define ALPHABET_COUNT 26

class Solution {
public:
    int minSteps(string s, string t) {
        int counts[ALPHABET_COUNT] = {};

        for(int i=0;i<s.length();i++) {
            counts[s[i] - ASCII_OFFSET]++;
            counts[t[i] - ASCII_OFFSET]--;
        }

        int difference_sum = 0;
        for(int i=0;i<ALPHABET_COUNT;i++) {
            difference_sum += abs(counts[i]);
        }

        return difference_sum / 2;
    }
};

