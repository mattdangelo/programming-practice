class Solution {
    unordered_map<int, int> memo;
public:
    int recRob(vector<int>& nums, int index) {
        if(index >= nums.size()) {
            return 0;
        }
        
        if(memo.count(index + 1) == 0) {
            memo[index + 1] = recRob(nums, index + 1);
        }
        
        if(memo.count(index + 2) == 0) {
            memo[index + 2] = recRob(nums, index + 2);
        }
        
        return max(memo[index + 1], memo[index + 2] + nums[index]);
    }
    
    int rob(vector<int>& nums) {
        return recRob(nums, 0);
    }
};
