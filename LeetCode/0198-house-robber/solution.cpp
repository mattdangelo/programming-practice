class Solution {
    std::unordered_map<int, int> memo;
public:
    int rob(vector<int>& nums, int index) {
        if(index >= nums.size()) {
            return 0;
        }
        
        if(memo.count(index + 1) == 0) {
            memo[index + 1] = rob(nums, index + 1);
        }
        
        if(memo.count(index + 2) == 0) {
            memo[index + 2] = rob(nums, index + 2);
        }
        
        return max(memo[index + 1], memo[index + 2] + nums[index]);
    }
    
    int rob(vector<int>& nums) {
        return rob(nums, 0);
    }
};
