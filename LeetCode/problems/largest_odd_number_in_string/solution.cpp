class Solution {
public:
    string largestOddNumber(string num) {
        int ptr = num.length() - 1;
        // ASCII codes for odd numbers are also odd
        while(ptr >= 0 && int(num[ptr]) % 2 == 0) {
            ptr--;
        }

        if(ptr == -1) {
            return "";
        }

        return num.substr(0, ptr + 1);
    }
};