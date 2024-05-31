class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int total_xor = 0;
        for(int i : nums) {
            total_xor ^= i;
        }

        // Find a bit that's a 1 in the total xor
        // that's a difference between the two numbers we're looking for
        int first_diff = 0;
        for(;first_diff<32;first_diff++) {
            if((total_xor >> first_diff) & 1) {
                break;
            }
        }

        // Create 2 groups and xor them together. One group will have a 1 in position first_diff, the other
        // will have a 0
        int group_one_xor = 0;
        int group_zero_xor = 0;
        for(int i : nums) {
            if((i >> first_diff) & 1) {
                group_one_xor ^= i;
            }
            else {
                group_zero_xor ^= i;
            }
        }

        return { group_one_xor, group_zero_xor };
    }
};
