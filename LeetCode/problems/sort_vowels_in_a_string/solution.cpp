class Solution {
    const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    string sortVowels(string s) {
        // Pass 1: Pull out all the vowels and sort them
        std::vector<char> s_vowels;
        s_vowels.reserve(s.length());
        for(int i=0;i<s.length();i++) {
            if(vowels.count(s[i])) {
                s_vowels.push_back(s[i]);
                s[i] = '_';
            }
        }

        std::sort(s_vowels.begin(), s_vowels.end());

        // Pass 2: Walk the string again and replace each vowel with vowels[ptr], incramenting ptr for each vowel replaced
        int ptr = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '_') {
                s[i] = s_vowels[ptr];
                ptr++;
            }
        }

        return s;
    }
};