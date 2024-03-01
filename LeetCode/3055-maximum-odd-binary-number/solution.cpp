class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        uint len = s.length() - 1;
        uint ptr = len;
        std::string ret = std::string(len + 1, '0');

        for(char c : s) {
            if(c == '1') {
                ret[ptr] = '1';

                if(ptr == len) {       
                    // First 1 we've seen             
                    ptr = 0;
                }
                else {
                    // Just incrament to the right
                    ptr++;
                }
            }
        }

        return ret;
    }
};
