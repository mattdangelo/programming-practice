class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0 || n < 0) {
            return false;
        }

        bool found_one = false;
        while(n != 0) {
            if(n & 1 == 1) {
                if(found_one) {
                    return false;
                }
                else {
                    found_one = true;
                }
            }
            n = n >> 1;
        }

        return true;
    }
};