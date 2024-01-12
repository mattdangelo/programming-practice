class Solution {
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    bool halvesAreAlike(string s) {
        int count_1 = 0;
        int count_2 = 0;
        int ptr_1 = 0;
        int ptr_2 = s.length() / 2;

        while(ptr_2 < s.length()) {
            if(vowels.count(s[ptr_1])) {
                count_1++;
            }

            if(vowels.count(s[ptr_2])) {
                count_2++;
            }

            ptr_1++;
            ptr_2++;
        }

        return count_1 == count_2;
    }
};