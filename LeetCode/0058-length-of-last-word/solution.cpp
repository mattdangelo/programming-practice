class Solution {
public:
    int lengthOfLastWord(string s) {
        int ptr_1 = s.length() - 1;
        while(s[ptr_1] == ' ') {
            ptr_1--;
        }

        // ptr_1 points to the end of the last word
        int ptr_2 = ptr_1;
        while(ptr_2 >= 0) {
            if(s[ptr_2] == ' ') {
                break;
            }
            ptr_2--;
        }

        // ptr_2 points to the start of the last word
        return ptr_1 - ptr_2;
    }
};
