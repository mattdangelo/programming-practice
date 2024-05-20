class Solution {
    int recSubsetXORSum(vector<int>& nums, int index, int count) {
        if(index == nums.size()) {
            return count;
        }

        return recSubsetXORSum(nums, index + 1, count) + recSubsetXORSum(nums, index + 1, count ^ nums[index]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return recSubsetXORSum(nums, 0, 0);
    }
};
