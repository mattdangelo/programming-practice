class Solution {
    std::vector<int> bitset;
public:
    int singleNumber(vector<int>& nums) {
        bitset.resize(32);

        // For every number in nums - O(n)
        for(int i : nums) {
            // For every bit in that number - O(1) constant time since there's always 32 bits
            for(int j=0;j<32;j++) {
                // Add it to the bit count mod 3
                if(((i>>j)&1)) {
                    bitset[j] = (bitset[j] + 1) % 3;
                }
            }
        }

        // Bitset now has the value of interest - convert it back into an int - O(1) since there's always 32 bits
        int res = 0;
        for(int i=0;i<32;i++) {
            res = res | (bitset[i] << i);
        }
        return res;
    }
};
