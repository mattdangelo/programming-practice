class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == -2147483648) {
            return false;
        }
        
        while(n) {
            if((n & 1) == 1) {
                n = (unsigned)n >> 1;
                if(n != 0) {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                n = (unsigned)n >> 1;
            }
        }
        
        return false;
    }
};