class Solution {
    int getNumOfAction(vector<int>& nums, int target) {
        int diff = 0;
        for(int i=0;i<nums.size();i++) {
            diff += abs(target - nums[i]);
        }
        return diff;
    }
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return getNumOfAction(nums, nums[nums.size() / 2]);
    }
};
