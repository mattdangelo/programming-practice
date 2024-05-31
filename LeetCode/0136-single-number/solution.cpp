class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int test = 0;
        for(int i : nums) {
            test ^= i;
        }

        return test;
    }
};
