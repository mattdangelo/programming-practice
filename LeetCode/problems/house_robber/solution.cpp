class Solution {
    std::unordered_map<int, int> memo;
public:
    int rob(vector<int>& nums, int index) {
        if(index < 0) {
            return 0;
        }
        
        if(memo.find(index-1) == memo.end()) {
            memo[index-1] = rob(nums, index - 1);
        }
                                
        if(memo.find(index-2) == memo.end()) {
            memo[index-2] = rob(nums, index - 2);
        }
        
        return max(memo[index-1], memo[index-2] + nums[index]);
    }
    
    int rob(vector<int>& nums) {
        return rob(nums, nums.size() - 1);
    }
};