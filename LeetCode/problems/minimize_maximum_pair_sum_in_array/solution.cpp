class Solution {
public:
    int minPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int max_val = 0;
        for(int i=0;i<nums.size() / 2;i++) {
            max_val = std::max(max_val, nums[i] + nums[nums.size() - 1 - i]);
        }

        return max_val;
    }
};