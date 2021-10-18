class Solution {
public:
    bool isPalindrome(int x) {
        // Early exit - can't be a palindrome if it has a negative sign
        if (x < 0)
            return false;

        string s = to_string(x);
        int ptr_1 = 0;
        int ptr_2 = s.length() - 1;
        while (ptr_1 <= ptr_2) {
            if (s[ptr_1] != s[ptr_2]) {
                return false;
            }
            ptr_1++;
            ptr_2--;
        }

        return true;
    }
};