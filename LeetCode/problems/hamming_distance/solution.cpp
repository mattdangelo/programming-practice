class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int diff = x ^ y;
        
        int count = 0;
        while(diff) {
            if(diff & 1) {
                count++;
            }
            diff = diff >> 1;
        }
        
        return count;
    }
};