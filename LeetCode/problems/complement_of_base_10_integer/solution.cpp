class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }
        int ret = 0;
        int shift = 0;
        while(n) {
            ret |= ((!(n & 1)) << shift);
            n = n >> 1;
            shift++;
        }
        
        return ret;
    }
};