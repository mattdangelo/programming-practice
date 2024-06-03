class Solution {
public:
    int appendCharacters(string s, string t) {
        int index = 0;

        for(char c : s) {
            if(t[index] == c) {
                index++;

                if(index == t.length()) {
                    // We don't need to add any characters, 
                    // since t is already a subsequence of s
                    return 0;
                }
            }
        }

        return t.length() - index;
    }
};
