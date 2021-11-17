class Solution {
    unordered_map<int, int> memo;
public:
    int rob(vector<int>& nums, int left, int index) {
        if(index < left) {
            return 0;
        }
        
        if(memo.find(index - 2) == memo.end()) {
            memo[index - 2] = rob(nums, left, index - 2);
        }
        
        if(memo.find(index - 1) == memo.end()) {
            memo[index - 1] = rob(nums, left, index - 1);
        }
        
        return max(memo[index - 1], nums[index] + memo[index - 2]);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int c1 = rob(nums, 0, nums.size() - 2);
        memo.clear();
        int c2 = rob(nums, 1, nums.size() - 1);
        return max(c1, c2);
    }
};
