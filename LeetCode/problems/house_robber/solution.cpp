class Solution {
    std::unordered_map<int, int> memo;
public:
    int rob(vector<int> nums, int i) {
        if(i < 0) {
            return 0;
        }
        
        if(memo.find(i - 2) == memo.end()) {
            memo[i - 2] = rob(nums, i - 2);
        }
        
        if(memo.find(i - 1) == memo.end()) {
            memo[i - 1] = rob(nums, i -1);
        }

        return max(memo[i - 2] + nums[i], memo[i - 1]);
    }
    
    int rob(vector<int>& nums) {
        return rob(nums, nums.size() - 1);
    }
};